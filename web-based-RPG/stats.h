#ifndef STATS_H_
#define STATS_H_


typedef struct {
  unsigned int strength;
  unsigned int intelligence;
  unsigned int vitality;
  unsigned int agility;
  unsigned int dexterity;
  unsigned int health;
  unsigned int maxhealth;
  unsigned int mana;
  unsigned int maxmana;
  unsigned int level;
} stats_t;

int cur_health(unsigned int s_health, unsigned int dmg, unsigned int def);
unsigned int dmg_attack(unsigned int s_strength, unsigned int t_level);
unsigned int dmg_skill(unsigned int s_intelligence, unsigned int t_level);
unsigned int dmg_reduction(unsigned int s_vitality, unsigned int s_level);
unsigned short int flee_success(unsigned int s_agility, unsigned int s_level, unsigned int t_level);
unsigned short int hit_success(unsigned int s_dexterity, unsigned int t_agility);


#endif	/* STATS_H_ */
