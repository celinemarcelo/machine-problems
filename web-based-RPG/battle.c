#include <stdio.h>
#include <string.h>
#include "ME4.h"
#include <time.h>
#include "stats.h"
#include "rand.h"
#include "MAP.h"
#include "/opt/lampp/include/mysql.h"

#define MAXLEN 1000000
#define DATALEN 300

typedef struct {
  int mSTR;
  int mMAG;
  int mVIT;
  int mDEX;
  int mAGI;
  int mlevel;
  char *mname;
  int mhp;
} monster_info;


void battle_screen(monster_info cur_monster, int pturn, char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI){
  printf("<!DOCTYPE html>\
<html lang='en'>\
<head>\
  <meta charset='utf-8'>\
  <meta name='viewport' content='width=device-width, initial-scale=1'>\
  <meta name='description' content='MP1 sample'>\
  <meta name='author' content='Baquiran and Marcelo'>\
  <title>MAP SCREEN</title>\
  \
  <link href='icon.ico' rel='shortcut icon'>\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap.min.css'>\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css'>\
  <link rel='stylesheet' type='text/css' href='/MP1/MP1_map_style.css'>\
  <link rel='stylesheet' type='text/css' href='/MP1/style.css'>\
</head>\
<body style='background-color:transparent'>\
<!-- HUD -->\
\
  <div>\
  <img src='/mp1_images/%s.gif' style='height:190px;' class='img-responsive center-block'>\
  </div>\
  ",cur_monster.mname);

  if(pturn){
  printf("\
    <div id='menu' style='background-repeat:no-repeat; background-size:cover; width:100%%; height:100%%;'>\
    <div style='margin-bottom:0px; width:50%%; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='margin-top:5px; text-align:center; padding:15px; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='charhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
\
    <div class='progress' name='charmp' style='height:25px;'>\
        <div class='progress-bar progress-bar-info mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        MP:%d/%d\
        </div>\
    </div>\
  </div>\
  <div style='margin-bottom:0px; width:50%%; float:right; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='margin-top:5px; padding:15px; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>></h4>\
        <h4 style='white-space:pre; display:inline; font-family:mana'>%s@Oblivion</h4>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>:</h4>\
      </div>\
    <div style='text-align:center'>\
      <form action='http://localhost/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
        <input type='hidden' name='battle_proper' value=1>\
        <input type='submit' name='attack' value='ATTACK' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <input type='submit' name='skill' value='SKILL' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <input type='submit' name='defend' value='DEFEND' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <br><input type='submit' name='run' value='RUN' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
      </form>\
      </div>\
  </div>\
  </div>\
  ", level, name, hp, (VIT * 3) + 11, (float) (hp/((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 11, (float) (mp/((MAG * 3.0) + 11.0)) * 100.0, mp, (MAG * 3) + 11, name, hp, (VIT * 3) + 11, (float) (hp/((VIT * 3) + 11)) * 100, hp, (VIT * 3) + 11);
    pturn = 0;
  } else {
    int cur_hp = hp;
    hp = cur_health(hp, dmg_attack(cur_monster.mSTR, cur_monster.mlevel), VIT);
    pturn = 1;
    printf("\
\
    <div id='menu' style='background-repeat:no-repeat; background-size:cover; width:100%%; height:100%%;'>\
    <div style='margin-bottom:0px; width:50%%; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='margin-top:5px; text-align:center; padding:15px; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='charhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
\
    <div class='progress' name='charmp' style='height:25px;'>\
        <div class='progress-bar progress-bar-info mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        MP:%d/%d\
        </div>\
    </div>\
  </div>\
      \
  <div style='margin-bottom:0px; width:50%%; float:right; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='margin-top:5px; padding:15px; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>></h4>\
        <h4 style='white-space:pre; display:inline; font-family:mana'>%s@Oblivion</h4>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>:</h4>\
      </div>\
    <div style='text-align:center; font-family:zig; color:#00a133;'>\
      <h3>%s ATTACKS! You take %d damage!</h3>\
      </div>\
  </div>\
  </div>\
  ", level, name, hp, (VIT * 3) + 11, (float) (hp/((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 11, (float) (mp/((MAG * 3.0) + 11.0)) * 100.0, mp, (MAG * 3) + 11, name, cur_monster.mname, cur_hp - hp);

  }
  printf("</div>\
\
  <br/>\
  <div style='text-align:center'>\
      <form action='http://localhost/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
        <input type='submit' name='continue' value='Continue...' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <input type='hidden' name='battle_proper' value=1>\
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
        <input type='hidden' name='pturn' value='%d'>\n\
        \
      </form>\
      </div>\
\
\
  <style type='text/css'>\
    body, a:hover {\
      cursor: url(http://cur.cursors-4u.net/games/gam-2/gam134.cur), progress !important;}\
  </style>\
  <a href='http://www.cursors-4u.com/cursor/2006/04/02/gam134.html' target='_blank' title='Keyblade'>\
    <img src='http://cur.cursors-4u.net/cursor.png' border='0' alt='Keyblade' style='position:absolute; top: 0px; right: 0px;' />\
  </a>\
\
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>\
  <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js'></script>\
  <script>\
    function disable() {\
      window.parent.document.getElementsByName('save')[0].disabled = true; \
      window.parent.document.getElementsByName('up')[0].disabled = true; \
      window.parent.document.getElementsByName('right')[0].disabled = true; \
      window.parent.document.getElementsByName('left')[0].disabled = true; \
      window.parent.document.getElementsByName('down')[0].disabled = true; \
    } \
    window.onload = disable;\
  </script>\
\
</body>\
</html>\
", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, pturn);
  //battle_screen(cur_monster, pturn, character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI);
}

monster_info get_monster(int level){
  monster_info this;
  int m_id = 0;

  this.mlevel = rand_monster_lvl(level);
  this.mname = malloc(10);

  int connect = 0, slotnum = 0, i = 0, j = 0;
  char query[3] = {};

  MYSQL mysql;
  MYSQL_RES *res;
  MYSQL_ROW row;

  unsigned int num_fields = 0;

  srand(time(NULL));
  m_id = rand() % 6;

  if(mysql_init(&mysql)){
    if(!mysql_real_connect(&mysql, "127.0.0.1", "root", "", "MP1", 0, NULL, 0)){
    //  puts("<h1>Error in connecting database.</h1>");
    } else {
    //  puts("<h1>Connected!</h1>");
      connect++;
    }
  }

  if(connect){
    sprintf(query, "SELECT * FROM Monsters WHERE id=%d", m_id);
    //printf("%s\n", query);
    mysql_query(&mysql, query);
    res = mysql_store_result(&mysql);
    
    if(res){
      num_fields = mysql_num_fields(res);

      if(num_fields){
        row = mysql_fetch_row(res);

        for(j = 0; j < mysql_num_rows(res); j++){
            for(i = 0; i < num_fields; i++){
                // printf("<td>%.*s</td>", (int) lengths[i], row[i]);
                switch(i){
                  case 1:
                    strcpy(this.mname, row[i]);
                    break;

                  case 2:
                    this.mSTR = atoi(row[i]);
                    break;

                  case 3:
                    this.mMAG = atoi(row[i]);
                    break;

                  case 4:
                    this.mVIT = atoi(row[i]);
                    break;

                  case 5:
                    this.mDEX = atoi(row[i]);
                    break;

                  case 6:
                    this.mAGI = atoi(row[i]);
                    break;
              }

            }
            row = mysql_fetch_row(res);
        
        }
      }
    }
  }
  mysql_close(&mysql);

  this.mhp = (this.mVIT * 3) + 11;

  return this;
}

int main(void){
  char data[MAXLEN] = {};
  char slot[7] = {};
  char character[5] = {};
  char name[DATALEN] = {};
  char choice[10] = {};
  int fled = 0;
  int battle_proper = 0;
  char bproper[2] = {};
  int pturn = 0;
  char pturn_c[2] = {};

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

  monster_info cur_monster;


  cgi_init();
  start_html("Kingdom Hearts: Zeroth Dimension");

  get_data(get_length(), &data[0]);

  get_element(&data[0],"battle_proper", &bproper[0]);
  bproper[strlen(bproper) - 2] = 0;
  battle_proper = atoi(bproper);

  get_element(&data[0],"pturn", &pturn_c[0]);
  pturn_c[strlen(pturn_c) - 2] = 0;
  pturn = atoi(pturn_c);

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

  if(battle_proper){
    printf("%d", battle_proper);
    battle_screen(cur_monster, pturn, character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int);
  } else { 

    get_element(&data[0],"fight", &choice[0]);

    cur_monster = get_monster(level_int);

    if(strcmp(choice, "")){
      if(AGI_int > cur_monster.mAGI){
        pturn = 1;    
      } else {
        pturn = 0;
      }
    
      battle_screen(cur_monster, pturn, character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int);
    } else {
      srand(time(NULL));

      fled = flee_success(AGI_int, level_int, cur_monster.mlevel);

      if(fled){
        printf("\
          <html><body>\
            <p>Successfully escaped from monster!</p>\
            <form target='_parent' action='fled.cgi' enctype='multipart-formdata' method='post'>\
              <input type='button' value='Back to map screen' onclick='history.go(-2)' >\
            </form>\
          </html></body>");
      } else {
        battle_screen(cur_monster, 0, character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int);   
      }
    }
  }

  

  end_html();
  return 0;

}
