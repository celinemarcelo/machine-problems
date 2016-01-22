#ifndef RAND_H_
#define RAND_H_

typedef struct {
  unsigned short int x;
  unsigned short int y;
} coordinate_t;

coordinate_t rand_location(int row, int col);
unsigned short int rand_spawn(unsigned short int rate);
unsigned int rand_monster_lvl(unsigned int plevel);

#endif /* RAND_H_ */
