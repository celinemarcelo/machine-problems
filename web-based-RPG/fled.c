#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ME4.h"
#include "MAP.h"
#include "rand.h"

#define MAXLEN 1000000
#define DATALEN 300

int main(){
	char data[MAXLEN] = {};
  char slot[7] = {};
  char character[5] = {};
  char name[DATALEN] = {};
  char choice[10] = {};
  int first = 0;

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
  char level[3] = {};
  int level_int = 0;
  char hp[3] = {};
  int hp_int = 0;
  char mp[3] = {};
  int mp_int = 0;
  char x[3] = {};
  int x_int = 0;
  char y[3] = {};
  int y_int = 0;

  int mon_AGI = 0;
  int mon_level = 0;

  cgi_init();

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

  get_element(&data[0],"AGI", &AGI[0]);
  AGI[strlen(AGI) - 2] = 0;
  AGI_int = atoi(AGI);
  //printf("    <p><br>AGI=\"%d\"</p>", AGI_int);

  get_element(&data[0],"DEX", &DEX[0]);
  DEX[strlen(DEX) - 2] = 0;
  DEX_int = atoi(DEX);
  //printf("    <p><br>DEX=\"%d\"</p>", DEX_int);

  get_element(&data[0],"level", &level[0]);
  level[strlen(level) - 2] = 0;
  level_int = atoi(level);
  
  get_element(&data[0],"hp", &hp[0]);
  hp[strlen(hp) - 2] = 0;
  hp_int = atoi(hp);

  get_element(&data[0],"mp", &mp[0]);
  mp[strlen(mp) - 2] = 0;
  mp_int = atoi(mp);

  get_element(&data[0],"x", &x[0]);
  x[strlen(x) - 2] = 0;
  x_int = atoi(x);

  get_element(&data[0],"y", &y[0]);
  y[strlen(y) - 2] = 0;
  y_int = atoi(y);
	
map_screen(character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int);

	return 0;
}