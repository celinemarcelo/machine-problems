#include <stdio.h>													//necessary header files
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/tcp.h>

typedef struct {													//all sensors' data are stored in an array of client_t structs
	char data[1024];
	int pid;
	int sensornum;
	int curfd;
	int connected;
	int error;
} clients_t;

clients_t clients[10];												//array of 10 structs declared globally (for easy "passing" to functions)

void kill_all() {													//signal handler for SIGINT which kills all clients before committing
	int l = 0;														//suicide - that is, before the server kills itself :P

	for (l = 0; l <= 9; l++) {
		if (clients[l].curfd) {
			kill(clients[l].pid, SIGKILL);
		}
	}
}

void plot(int index) {												//-BONUS-
	char sys_arg[10] = {};											//function that plots data in a log file

	sprintf(sys_arg, "./plot %d", clients[index].sensornum);
	system(sys_arg);												//execute plot from within the server ;)
	exit(-1);
}

void write_log(int index) {											//function that writes terminated/disconnected client data to log file
	char log_filename[20] = {};

	sprintf(log_filename, "sensor-0%d.log", clients[index].sensornum);

	FILE *fplog = fopen(log_filename, "w");

	if (!fplog) {
		perror(NULL);
		exit(-1);
	}

	//puts(clients[index].data);

	fwrite(clients[index].data, 1, strlen(clients[index].data), fplog);
	printf("Sensor %d data written to %s\n", clients[index].sensornum, log_filename);

	fclose(fplog);
}

void check_data(int index, char *mesg, char *g_l, float threshold) {  //function that checks if received data is within threshold

	if (!strcmp(g_l, "-g")) {										  //set of if statements that kill clients with abnormal data
		if (atof(mesg) > threshold) {
			//printf("%f > %f\n", atof(mesg), threshold);

			//puts("Disconnecting... DATA AFTER");
			//puts(clients[index].data);

			clients[index].error++;
			kill(clients[index].pid, SIGKILL);
			return;
		}
	} else {
		if (atof(mesg) < threshold) {
			//printf("%f < %f\n", atof(mesg), threshold);

			//puts("Disconnecting... DATA AFTER");
			//puts(clients[index].data);

			clients[index].error++;
			kill(clients[index].pid, SIGKILL);
			return;
		}
	}

	printf("Data Received: (%d) %s\n", clients[index].sensornum, mesg); //if data received was not within threshold, print

	strcat(clients[index].data, mesg);									//concatenate new data to existing client[index].data
	strcat(clients[index].data, "\n");

}

int main(int argc, char **argv) {

	int listenfd = 0, connfd = 0;                                              //fds for listener and new connections
	struct sockaddr_in6 servaddr, cliaddr;                                     //structs for server and client information
	socklen_t len = sizeof(cliaddr);                                           //other necessary variables
	char cli_ip[32] = {};
	char mesg[1024] = {};
	char cport[10] = {};
	int pid = 0;
	int i = 0, j = 0, k = 0;
	int fdmax = 0;
	char strport[10] = {};

	fd_set masterfds;                                                          //declaration of fd sets to be monitored by select
	fd_set readfds;

	float threshold = 0;

	signal(SIGINT, kill_all);												  //signal handler declaration

	if (argc != 4) {														  //error handling for invalid arguments
		puts("Invalid arguments.");
		puts("Usage: ./server port -l/-g threshold");
		return 0;
	}


	pid = getpid();                                                            //monitoring of PID
	printf("PID %d\n", pid);
	strcpy(cport, *(argv + 1));

	threshold = atof(*(argv + 3));											   //extracting threshold from char **argv

	listenfd = socket(PF_INET6, SOCK_STREAM, 0);                               //initialization of listener


	bzero(&servaddr, sizeof(servaddr));                                        //clearing of sockaddr_in6 structs
	bzero(&cliaddr, sizeof(cliaddr));

	servaddr.sin6_family = AF_INET6;                                           //necessary IPv6 declarations
	servaddr.sin6_addr = in6addr_any;
	servaddr.sin6_port = htons(atoi(cport));


	if (bind( listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr) ) < 0 ) { //binding of socket to server
		perror(NULL);
		exit(-1);
	}

	//printf("Port %s opened for possible connections.\n", cport);

	if (listen(listenfd, 10) < 0) {                                              //listening
		perror(NULL);
		close(listenfd);
		exit(-1);
	}

	puts("Waiting for connections...");

	FD_ZERO(&readfds);
	fdmax = listenfd;                                                            //listenfd is the highest fd so far (keeping track of max fd is imperative for select)
	FD_SET(listenfd, &masterfds);                                                //insertion of listenfd to master set


	for (i = 0; i <= 9; i++) {													 //initialization of clients
		memset(&clients[i], 0, sizeof(clients[i]));
		//printf("clients[%d] curfd = %d, sensornum = %d, connected = %d.\n", i, clients[i].curfd, clients[i].sensornum, clients[i].connected);
	}

	while (1) {
		for (k = 0; k <= fdmax; k++) {                                            //go through fds to handle either new connections or parse requests from existing clients

			readfds = masterfds;

			if (select(fdmax + 1, &readfds, NULL, NULL, NULL) == -1) {            //select statement which is the heart of this multiple client program
				perror(NULL);
				exit(-1);
			}

			if (FD_ISSET(k, &readfds)) {                                          //check if current fd is in readfds
				if (k == listenfd) {                                              //new connection

					connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len); //establish connection with new client

					if (connfd == -1) {                                           //error checking
						perror(NULL);
						exit(-1);
					}

					FD_SET(connfd, &masterfds);                                   //insert new fd to master set


					sprintf(strport, "%d", ntohs(cliaddr.sin6_port));

					if (connfd > fdmax) {                                        //check if new fd is now max
						fdmax = connfd;
					}

					inet_ntop(AF_INET6, (struct in_addr *) &cliaddr.sin6_addr, cli_ip, sizeof(cli_ip) );  //conversion of numeric address to string

					for (j = 0; clients[j].curfd; j++);							//let j sweep through clients to get available slot

					clients[j].curfd = connfd;


				} else {                                                        //parsing of request from existing client

					memset(mesg, 0, sizeof(mesg));

					if (read(k, mesg, sizeof(mesg)) > 0 ) {   				    //getting the request

						getpeername(k , (struct sockaddr *)&cliaddr , &len);
						inet_ntop(AF_INET6, (struct in_addr *) &cliaddr.sin6_addr, cli_ip, sizeof(cli_ip) );

						for (j = 0; clients[j].curfd != k; j++);				//let j sweep through clients to get struct containing k

						if (!clients[j].connected) {							//let server receive sensornum and PID of client first
							sscanf(mesg, "%d %d", &clients[j].pid, &clients[j].sensornum);

							printf("Sensor %d (%s:%d)\n", clients[j].sensornum, cli_ip, ntohs(cliaddr.sin6_port));
							//printf("clients[%d]\n", j);

							clients[j].connected++;
						} else {
							check_data(j, mesg, *(argv + 2), threshold);		//normal receiving of data
						}



					} else {                                                    //client disconnected/terminated by server
						getpeername(k , (struct sockaddr *)&cliaddr , &len);
						inet_ntop(AF_INET6, (struct in_addr *) &cliaddr.sin6_addr, cli_ip, sizeof(cli_ip) );

						for (j = 0; clients[j].curfd != k; j++);				//let j sweep through clients to get struct containing k

						printf("Sensor %d (%s:%d) %s\n", clients[j].sensornum, cli_ip, ntohs(cliaddr.sin6_port), //conditional operator checks whether client terminated due
						 clients[j].error ? "to be terminated" : "disconnected");  								 //to error, and sets message accordingly

						write_log(j);											//call write_log function to create log file

						pid = fork();											//fork to simultaneously execute ./plot

						if (pid == 0) {

							plot(j);											//call plot function (output will be written on an svg file)

						} else {

							memset(&clients[j], 0, sizeof(clients[j]));

							close(k);                                                 //closing of current fd
							FD_CLR(k, &masterfds);                                    //deleting current fd from master set
						}
					}
				}
			}
		}
	}

	close(listenfd);                                                         //closing of listener
	return 0;
}