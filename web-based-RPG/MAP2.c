#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ME4.h"
#include "MAP.h"
#include "rand.h"

#define MAXLEN 1000000

void iframe(char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI, char *dir){
	//printf("Before: %d, %d\n", x,y);
	/*movement function*/
	//printf("dir:%s\n", dir);
	if (!(strcmp(dir, "up"))) {
	 	if ( (y+1) < 9) {
	 		y++;
	 	}
	 } else if(!(strcmp(dir, "down"))) {
	 	if ( (y-1) > 0) {
	 	 	y--;
	 	 } 
	 } else if(!(strcmp(dir, "left"))) {
	 	if ( (x-1) > 0) {
	 		x--;
	 	}
	 } else if(!(strcmp(dir, "right"))) {
	 	if ( (x+1) < 9) {
	 		x++;
	 	}
	 } else {
	 	printf("ERROR\n");
	 }

	//printf("After: %d, %d\n", x,y);
	// randomize chance of spawn
	if(1 /*enemy spawned*/){
		// randomize enemy 
		printf("\
            <form action='http://localhost/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data' role='form' target='map'>\
			<input type='submit' name='fight' value='FIGHT'>\
			<input type='submit' name='flee' value='FLEE'>\
			<input type='hidden' name='STR' value='%d'>\n\
            <input type='hidden' name='MAG' value='%d'>\n\
            <input type='hidden' name='VIT' value='%d'>\n\
            <input type='hidden' name='DEX' value='%d'>\n\
            <input type='hidden' name='AGI' value='%d'>\n\
            <input type='hidden' name='name' value='%s'>\n\
            <input type='hidden' name='level' value='%d'>\n\
            <input type='hidden' name='hp' value='%d'>\n\
            <input type='hidden' name='mp' value='%d'>\n\
            <input type='hidden' name='x' value='%d'>\n\
            <input type='hidden' name='y' value='%d'>\n\
			</form>\
   ", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y);

		//battle_screen(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI);
	 } 
}

int main(void){
	char data[MAXLEN] = {};
	char character[5] = {}, name[30] = {}, holder[3], dir[7] = {};
	int STR = 0, MAG = 0, VIT = 0, DEX = 0, AGI= 0, level = 0, hp = 0, mp = 0, x = 0, y = 0;

	cgi_init();
	start_html("MAP MOVEMENT");
	get_data(get_length(), &data[0]);

	get_element(&data[0],"character", &character[0]);
	character[strlen(character) - 2] = 0;

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
	
	//puts("HERE AT MAP2");
	iframe(character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, dir);
	return 0;
}
