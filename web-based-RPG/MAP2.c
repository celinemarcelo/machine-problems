#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ME4.h"
#include "MAP.h"
#include "rand.h"
#include "/opt/lampp/include/mysql.h"
#include <time.h>

#define MAXLEN 1000000

void iframe(char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI, char *dir, int experience){
	/*movement function*/
	int move = 0;
	int tospawn = 0;

	if (!(strcmp(dir, "down"))) {
	 	if ( (y+1) <= 9) {
	 		y++;
	 		move = 3;
	 	}
	 } else if(!(strcmp(dir, "up"))) {
	 	if ( (y-1) >= 1) {
	 	 	y--;
	 		move = 1;
	 	 } 
	 } else if(!(strcmp(dir, "left"))) {
	 	if ( (x-1) > 0) {
	 		x--;
	 		move = 2;
	 	}
	 } else if(!(strcmp(dir, "right"))) {
	 	if ( (x+1) <= 9) {
	 		x++;
	 		move = 4;
	 	}
	 } else {
	 	printf("ERROR DITO\n");
	 }

	// randomize chance of spawn
	if (move){
		int jynx; // lower jynx = less monsters 
		srand(time(NULL));

		if ( level <= 5) {
			jynx = (rand()%(40+(level*level))) +20 ; // 20 to 59+level^2
		} else {
			jynx = (rand()%(level*3)) + 30 ; // 30 to (level*3)-1
		} 

		tospawn = rand_spawn(jynx);
	
		if(tospawn){
			// randomize enemy
		 	fight_flee(character, name, level, hp, mp , x, y, STR, MAG, VIT, DEX, AGI, experience);
			//battle_screen(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI);
		 } else
		 	map_screen(character, name, level, hp, mp , x, y, STR, MAG, VIT, DEX, AGI, experience, move); 
	} else
		map_screen(character, name, level, hp, mp , x, y, STR, MAG, VIT, DEX, AGI, experience, move); // no change in position
}

void save_file(char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI, char *dir, int experience, char *slot) {
	
	// int connect = 0;
	int slotnum = slot[5] - '0';
	// int i = 0, j = 0;
	
	// // unsigned int num_rows = 0;
	// unsigned int num_fields = 0;

	// MYSQL *mysql = mysql_init(NULL);
	// MYSQL_RES *res;
	// MYSQL_ROW row;
	// // MYSQL_FIELD *field;

	MYSQL *mysql = mysql_init(NULL);
	MYSQL_RES *result; 
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	
	char *query;
	query = malloc(30);

	unsigned int num_fields;
	unsigned int num_rows;
	unsigned int i;
	unsigned long *lengths;

	if( mysql ) {
		// Establish connection with mysql database engine running in host
		if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "MP1", 0, NULL, 0) ){
			// connection successful
			// sprintf(query, "select * from Saves WHERE slot=%d", slotnum);
			sprintf(query, "UPDATE Saves SET soriku=\"%s\", name=\"%s\", level=%d,	hp=%d, mp=%d, x=%d, y=%d, STR=%d, MAG=%d, VIT=%d, DEX=%d, AGI=%d, experience=%d WHERE slot=%d", character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, experience,  slotnum);

			//printf("%s\n", query);
		
			if (mysql_query(mysql,query)) {
			    // error
			    printf("<br/>Query failed\n");

			    if(*mysql_error(mysql)) {
			    	// knowing what error occurred
			    	printf("<br/>ERROR, something's wrong!\n");
					printf("<br/>ERROR %d (%s): %s\n", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
			        printf("<br/>Warning/s: %i\n", mysql_warning_count(mysql));
				} else 
				//printf("in in in \n");
				mysql_close(mysql);
			} else {
				printf("inside\n");
				result = mysql_store_result(mysql);
		    
		    if (result) {
		    	// there are rows
		    	num_rows = mysql_affected_rows(mysql);  // rows
		        num_fields = mysql_num_fields(result); // columns
				
				puts("<table class=\"table table-bordered table-striped\">");
				puts("<thead>");
				puts("<tr>");
				// Get header per column 
				for(i = 0; i < num_fields; i++)	{
				    field = mysql_fetch_field_direct(result, i);
				    puts("<th>");
				    // printf("Field %u is %s\n", i, field->name);
				    printf(" %s ", field->name);
				    puts("</th>");
				}
				puts("<tr>");
				puts("</thead>");

				// Gets row content - FETCH ROW
		        while ((row = mysql_fetch_row(result))) {
				   lengths = mysql_fetch_lengths(result);
				   puts("<tr>");
				   for(i = 0; i < num_fields; i++) {
				       	puts("<td>");
				       	// printf("[%.*s] ", (int) lengths[i],
				              // row[i] ? row[i] : "NULL");
				   		printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
				       	puts("</td>");
				   }
				   // printf("\n");
				   puts("</tr>");
				}

				puts("</table>");
				printf("<br/>\n%ld rows affected\n", (long)num_rows);
				printf("with %ld columns\n<br/>\n", (long)num_fields);

				mysql_free_result(result);
		    } else {
		    	// mysql_store_result() returned nothing; should it have?
		        if (mysql_errno(mysql)) {
		           printf("ERROR %i (%s): %s\n", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
		           printf("Warning/s: %i\n", mysql_warning_count(mysql));
		        } else if (mysql_field_count(mysql) == 0) {
		        	// no return set
		            // query does not return data
		            // (it was not a SELECT)
		            num_rows = mysql_affected_rows(mysql);
		            printf("Affected Rows : %i\n", num_rows);
		        }

		        // mysql_close(mysql);
		    }
		    mysql_close(mysql);
			}	
		} else 
			printf("ok\n");
	}  else {
		printf("not connected\n");		
	}

	map_screen(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, experience, 0);
	// mysql_close(&mysql);
}

int main(void){
	char data[MAXLEN] = {};
	char character[5] = {}, name[30] = {}, holder[3], dir[7] = {}, slot[7] = {};;
	int STR = 0, MAG = 0, VIT = 0, DEX = 0, AGI= 0, level = 0, hp = 0, mp = 0, x = 0, y = 0, experience = 0;

	cgi_init();
	start_html("Kingdom Hearts: Zeroth Dimension");
	get_data(get_length(), &data[0]);

	get_element(&data[0],"character", &character[0]);
	character[strlen(character) - 2] = 0;

	get_element(&data[0],"slot", &slot[0]);
	slot[strlen(slot) - 2] = 0;

	get_element(&data[0],"name", &name[0]);
	name[strlen(name) - 2] = 0;

	get_element(&data[0],"level", &holder[0]);
	level = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"hp", &holder[0]);
	hp = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"mp", &holder[0]);
	mp = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"x", &holder[0]);
	x = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"y", &holder[0]);
	y = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"STR", &holder[0]);
	STR = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"VIT", &holder[0]);
	VIT = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"MAG", &holder[0]);
	MAG = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"DEX", &holder[0]);
	DEX = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"AGI", &holder[0]);
	AGI = atoi(holder);
	memset(holder, 0, 3);

	get_element(&data[0],"direction", &dir[0]);
	dir[strlen(dir) - 2] = 0;
	
	get_element(&data[0],"experience", &holder[0]);
	experience = atoi(holder);
	memset(holder, 0, 3);

	if(!strcmp(slot,"")) {
		// Save button
		iframe(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, dir, experience);
	} else {
		// save
		save_file(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, dir, experience, slot);
	}
	return 0;
}
