/*Base code taken from http://www.programminglogic.com/example-of-client-server-program-in-c-using-sockets-and-tcp/*/

#include <sys/socket.h>                                                             //necessary header files
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

void extract_info(char *ip_port, char *ip, char *port) {                            //function to extract IP and port from program argument
    int i = 0;

    for (i = 0; ip_port[i] != ':'; i++) {
        *(ip + i) = ip_port[i];
    }

    ip_port += 1 + i;
    strcpy(port, ip_port);

    //printf("ip = %s\n", ip);
    //printf("port = %s\n", port);
}

void send_data(int clientSocket, char *g_l, float threshold, FILE *fp) {            //function that reads data from appropriate .txt file
    char data[10] = {};                                                             //and checks whether data is within threshold
    char c;

    c = fgetc(fp);
    while (c != EOF) {
        fseek(fp, -1, SEEK_CUR);
        fgets(data, 10, fp);
        data[strlen(data) - 1] = 0;

        if (!strcmp(g_l, "-g")) {                                                   //set of if statements that handle data within threshold
            if (atof(data) > threshold) {
                printf("%f > %f\n", atof(data), threshold);

                puts("Disconnecting...");
                break;
            }
        } else {
            if (atof(data) < threshold) {
                printf("%f < %f\n", atof(data), threshold);

                puts("Disconnecting...");
                break;
            }
        }

        sleep(1);                                                                   //required delay

        send(clientSocket, data, strlen(data), 0);                                  //only acceptable data are sent

        c = fgetc(fp);
    }
}



int main(int argc, char **argv) {
    int clientSocket;
    char mesg[20] = {};
    char ip_port[30] = {};
    char ip[20] = {};
    char port[10] = {};
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    int pid = 0;
    int sensornum = 0;
    float threshold = 0;
    char filename[20] = {};
    FILE *fp;

    pid = getpid();
    //printf("pid = %d\n", pid);

    addr_size = sizeof serverAddr;


    if (argc != 6) {                                                                //handling invalid program arguments
        puts("Invalid arguments.");
        puts("Usage: ./client IP:port -s sensornum -l/-g threshold");
        return 0;
    }

    sensornum = atoi(*(argv + 3));
    threshold = atof(*(argv + 5));

    //printf("sensornum = %d\n", sensornum);
    //printf("threshold = %f\n", threshold);

    sprintf(filename, "sensor-0%d.txt", sensornum);
    //puts(filename);

    fp = fopen(filename, "r");                                                      //open .txt file containg data of sensor

    if (!fp) {
        perror(NULL);
        exit(-1);
    }

    strcpy(ip_port, *(argv + 1));

    extract_info(ip_port, ip, port);                                                //call to extract_info function

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);                                 //describe the server to connect to
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(port));


    if (inet_pton(AF_INET, ip, &serverAddr.sin_addr) <= 0) {
        perror(NULL);
        exit(-1);
    }


    if (connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size)) {        //establish connection with server
        perror(NULL);
        exit(-1);
    }

    sprintf(mesg, "%d %d", pid, sensornum);                                         //initial sending of sensor details (number and PID)
    send(clientSocket, mesg, strlen(mesg), 0);

    send_data(clientSocket, *(argv + 4), threshold, fp);                            //normal sending of data

    fclose(fp);
    return 0;
}