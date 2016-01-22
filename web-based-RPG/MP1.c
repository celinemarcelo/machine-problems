#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <mysql.h>
#include "ME4.h"
#include "MAP.h"
#include <time.h>


#define MAXLEN 1000000
#define DATALEN 1000

void new_game(char *character, char *name, int STR, int MAG, int VIT, int DEX, int AGI){
	int x = 0;
	int y = 0;
	float hp = 0;
	float mp = 0;

	srand(time(NULL));

	hp =  (VIT * 3) + 11;
	mp =  (MAG * 3) + 5;

	x = (rand() % 9) +1;
	y = (rand() % 9) +1;

	map_screen(character, name, 1, (int) hp, (int) mp, x, y, STR, MAG, VIT, DEX, AGI, 0, 0);
}

void load_game(char *slot){
	int connect = 0, slotnum = 0, i = 0, j = 0;
	char *query;
	char *character, *name;
	int STR = 0, MAG = 0, VIT = 0, DEX = 0, AGI = 0;
	int level = 0, hp = 0, mp = 0, x = 0, y = 0, experience = 0;

	query = malloc(30);
	character = malloc(5);
	name = malloc(30);

	// unsigned int num_rows = 0;
	unsigned int num_fields = 0;

	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	// MYSQL_FIELD *field;


	if(mysql_init(&mysql)){
		if(!mysql_real_connect(&mysql, "127.0.0.1", "root", "", "MP1", 0, NULL, 0)){
		//	puts("<h1>Error in connecting database.</h1>");
		} else {
		//	puts("<h1>Connected!</h1>");
			connect++;
		}
	}

	if(connect){
		slotnum = slot[5] - '0';
		sprintf(query, "SELECT * FROM Saves WHERE slot=%d", slotnum);
		//printf("%s\n", query);
		mysql_query(&mysql, query);
		res = mysql_store_result(&mysql);
		
		if(res){
			num_fields = mysql_num_fields(res);

			if(num_fields){
				row = mysql_fetch_row(res);

				//puts("<table class=\"table-striped table table-responsive\" style=\"font-size:20px;\">");

				for(j = 0; j < num_fields; j++){
       				// field = mysql_fetch_field_direct(res, j);
    				//printf("<th>%s</th>", field->name);	
				}

				for(j = 0; j < mysql_num_rows(res); j++){
   					// unsigned long *lengths;
   					// lengths = mysql_fetch_lengths(res);
   				
   					//puts("<tr>");
   					for(i = 0; i < num_fields; i++){
       					// printf("<td>%.*s</td>", (int) lengths[i], row[i]);
       					switch(i){
       						
       						// slot number then other fields;

       						case 1:
      							strcpy(character, row[i]);
      							break;

      						case 2:
      							strcpy(name, row[i]);
      							break;

      						case 3:
      							level = atoi(row[i]);
      							break;

      						case 4:
      							hp = atoi(row[i]);
      							break;

      						case 5:
      							mp = atoi(row[i]);
      							break;

      						case 6:
      							x = atoi(row[i]);
      							break;

      						case 7:
      							y = atoi(row[i]);
      							break;

      						case 8:
      							STR = atoi(row[i]);
      							break;

      						case 9:
      							MAG = atoi(row[i]);
      							break;

      						case 10:
      							VIT = atoi(row[i]);
      							break;

      						case 11:
      							DEX = atoi(row[i]);
      							break;

      						case 12:
      							AGI = atoi(row[i]);
      							break;

      						case 13:
      							experience = atoi(row[i]);

     					}
      					
   					}
   					//puts("</tr>");

   					row = mysql_fetch_row(res);
   				}

   				//puts("</table>");
			}

			//printf("CHARACTER = %s<br>NAME = %s<br>LEVEL = %d<br>", character, name, level);
			//printf("HP = %d<br>MP = %d<br>X = %d<br>Y = %d<br>STR = %d<br>
			//	MAG = %d<br>VIT = %d<br>DEX = %d<br>AGI = %d", hp, mp, x, y, STR, MAG, VIT, DEX, AGI);
   		}
	}

	map_screen(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, experience, 0);
	mysql_close(&mysql);
}


int main(void) {
	char data[MAXLEN] = {};
	char slot[7] = {};
	char character[5] = {};
	char name[DATALEN] = {};

	char STR[3] = {};
	int STR_int = 0;
	char MAG[3] = {};
    int MAG_int = 0;
    char VIT[3] = {};
    int VIT_int = 0;
    char AGI[3] = {};
    int AGI_int = 0;
    char DEX[3] = {};
    int DEX_int = 0;

	cgi_init();
	//start_html("Kingdom Hearts: Zeroth Dimension");

	get_data(get_length(), &data[0]);

	get_element(&data[0],"slot", &slot[0]);
	slot[strlen(slot) - 2] = 0;
	//printf("    <p><br>slot=\"%s\"</p>", slot);

	get_element(&data[0],"character", &character[0]);
	character[strlen(character) - 2] = 0;
	//printf("    <p><br>character=\"%s\"</p>", character);

	get_element(&data[0],"name", &name[0]);
	name[strlen(name) - 2] = 0;
	//printf("    <p><br>name=\"%s\"</p>", name);

	get_element(&data[0],"STR", &STR[0]);
	STR[strlen(STR) - 2] = 0;
	STR_int = atoi(STR);
	//printf("    <p><br>STR=\"%d\"</p>", STR_int);

	get_element(&data[0],"MAG", &MAG[0]);
	MAG[strlen(MAG) - 2] = 0;
	MAG_int = atoi(MAG);
	//printf("    <p><br>MAG=\"%d\"</p>", MAG_int);

	get_element(&data[0],"VIT", &VIT[0]);
	VIT[strlen(VIT) - 2] = 0;
	VIT_int = atoi(VIT);
	//printf("    <p><br>VIT=\"%d\"</p>", VIT_int);

	get_element(&data[0],"DEX", &DEX[0]);
	DEX[strlen(DEX) - 2] = 0;
	DEX_int = atoi(DEX);
	//printf("    <p><br>DEX=\"%d\"</p>", DEX_int);
	
	get_element(&data[0],"AGI", &AGI[0]);
	AGI[strlen(AGI) - 2] = 0;
	AGI_int = atoi(AGI);
	//printf("    <p><br>AGI=\"%d\"</p>", AGI_int);

	
	if(!strcmp(slot,"")) {
		//puts("<h1>NEW GAME?</h1>");
		new_game(character, name, STR_int, MAG_int, VIT_int, DEX_int, AGI_int);
	} else {
		//puts("<h1>LOAD GAME?</h1>");
		load_game(slot);
	}

	//end_html();
	return 0;

}
