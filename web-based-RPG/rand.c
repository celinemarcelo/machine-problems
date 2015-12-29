#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rand.h"

//Returns random location - for start
coordinate_t rand_location(int row, int col) {
  coordinate_t loc;
  srand(time(NULL));
  printf("Before: %d, %d\n", row, col);
  loc.x = (rand() % col) + 1; // range; 0-col +1 
  loc.y = (rand() % row) + 1; // range: 0-row +1
  printf("After: %d, %d\n", loc.x, loc.y);
  return loc;
}

// To spawn or not to spawn 
unsigned short int rand_spawn(unsigned short int rate) {

  if(rate>100 || rate<0) {
    //invalid rate
    return -1;
  } 
  srand(time(NULL));

  unsigned short int spawn;
  spawn = rand() % 100 + 1; // 0-100
  printf("spawn: %d\n", spawn);

  if(spawn > rate) {
    // no monster
    return 0;
  }
  else if (spawn <= rate) {
    // laban!
    return 1;
  }
  else {
    // error
    return -1;
  }
}

/*
// Monster Type
unsigned int mtype(){
  // refer to db
}*/

// Monster lvl
unsigned int rand_monster_lvl(unsigned int plevel) {
  unsigned int mlevel;
  unsigned short int pivot;

  srand(time(NULL));

  if(plevel > 1) {
    pivot = rand() % 3;
  }
  else if(plevel == 1) {
    // newbie player
    pivot = rand() % 2;
  }
  else {
    // error
    return -1;
  }

  if(pivot == 0) {
    mlevel = plevel;
  }
  else if(pivot == 1) {
    mlevel = plevel + 1;
  }
  else if(pivot == 2) {
    mlevel = plevel - 1;
  }
  else {
    mlevel = -1;
  }

  return mlevel;
}

int main3(int argc, char const *argv[]) {
  // table dimensions
  int row = 9;
  int col = 9;
  
  // db info
  coordinate_t pos_now;
    pos_now.x = 1;
    pos_now.y = 1; 
  int plevel = 10;

  // randomized info
  int mlevel;
  int rate = 50;

  if( (pos_now.x != 0) && (pos_now.y != 0) ){
    // loaded entry then gumalaw  
    if(rand_spawn(rate) ){
      printf("AN ENEMY!\n");
      mlevel = rand_monster_lvl(plevel);
      printf("Encountered a lvl %d monster\n", mlevel);
    } else{
      printf("wala lang\n"); 
    }
  } else {
    //new entry{}
    pos_now = rand_location(row,col);
    printf("Starting pos: %d, %d\n", pos_now.x, pos_now.y);
  }
  return 0;
}