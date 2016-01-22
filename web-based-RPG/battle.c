#include <stdio.h>
#include <string.h>
#include "ME4.h"
#include <time.h>
#include "stats.h"
#include "rand.h"
#include "MAP.h"
#include <mysql/mysql.h>

#define MAXLEN 1000000
#define DATALEN 300

typedef struct {
  int mSTR;
  int mVIT;
  int mDEX;
  int mAGI;
  int mlevel;
  char *mname;
  int mhp;
} monster_info;


void battle_screen(monster_info cur_monster, int pturn, char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI, char *command, int defend, int fled, int experience) {
  int hit = 0;
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
  <link rel='stylesheet' type='text/css' href='/style.css'>\
</head>\
<body style='background-color:transparent'>\
");


  if (pturn && hp != 0 && cur_monster.mhp != 0 && !strcmp(command, "")) {
    printf("\
<!-- HUD -->\
\
  <div id='menu'>\
    <div style='width:100%%; height:100px; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='text-align:center; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='mhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
  </div>\
  <div>\
  <img src='/mp1_images/%s.gif' style='height:150px;' class='img-responsive center-block'><br>\
  </div>\
  ", cur_monster.mlevel, cur_monster.mname, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, (float) (cur_monster.mhp / ((cur_monster.mVIT * 3.0) + 11.0)) * 100.0, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, cur_monster.mname);

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
    ", level, name, hp, (VIT * 3) + 11, (float) (hp / ((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 5, (float) (mp / ((MAG * 3.0) + 5.0)) * 100.0, mp, (MAG * 3) + 5);
    printf("\
    <div style='text-align:center'>\
      <form action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
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
        <input type='hidden' name='mSTR' value='%d'>\n\
        <input type='hidden' name='mVIT' value='%d'>\n\
        <input type='hidden' name='mDEX' value='%d'>\n\
        <input type='hidden' name='mAGI' value='%d'>\n\
        <input type='hidden' name='mname' value='%s'>\n\
        <input type='hidden' name='mlevel' value='%d'>\n\
        <input type='hidden' name='mhp' value='%d'>\n\
        <input type='hidden' name='character' value='%s'>\n\
        <input type='hidden' name='experience' value='%d'>\n\
        <input type='submit' name='attack' value='ATTACK' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <input type='submit' name='skill' value='SKILL' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <input type='submit' name='defend' value='DEFEND' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
        <br><input type='submit' name='run' value='RUN' style='color:#00a133; font-family:zig; font-size:25px; border:none; background:none; padding:10px;'>\
      </form>\
      </div>\
  </div>\
  </div>\
  <style type='text/css'>\
    body, a:hover {\
      cursor: url(/gam134.cur), progress !important;}\
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
  ", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, pturn, cur_monster.mSTR, cur_monster.mVIT, cur_monster.mDEX, cur_monster.mAGI, cur_monster.mname, cur_monster.mlevel, cur_monster.mhp, character, experience);

  } else if (!pturn && hp != 0 && cur_monster.mhp != 0) {
    int cur_hp = hp;
    hit = hit_success(cur_monster.mDEX, AGI);

    if (hit) {
      if (defend) {
        hp = cur_health(hp, dmg_attack(cur_monster.mSTR, cur_monster.mlevel), dmg_reduction(VIT, level) + VIT);

      } else {
        hp = cur_health(hp, dmg_attack(cur_monster.mSTR, cur_monster.mlevel), dmg_reduction(VIT, level));
      }
    }
    pturn = 1;
    printf("\
<!-- HUD -->\
\
  <div id='menu'>\
    <div style='width:100%%; height:100px; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='text-align:center; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='mhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
  </div>\
  <div>\
  <img src='/mp1_images/%s.gif' style='height:150px;' class='img-responsive center-block'><br>\
  </div>\
  ", cur_monster.mlevel, cur_monster.mname, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, (float) (cur_monster.mhp / ((cur_monster.mVIT * 3.0) + 11.0)) * 100.0, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, cur_monster.mname);

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
  ", level, name, hp, (VIT * 3) + 11, (float) (hp / ((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 5, (float) (mp / ((MAG * 3.0) + 5.0)) * 100.0, mp, (MAG * 3) + 5);

    if (!fled) {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>Can't escape!</p>\
      </div>");
    }

    if (hit) {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s ATTACKS!<br><br>>%s takes %d damage!</p>\
      </div>\
    ", cur_monster.mname, name, cur_hp - hp);
    } else {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s ATTACKS!<br><br>>But it missed!</p>\
      </div>\
    ", cur_monster.mname);
    }

    printf("\
\
      <form action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
        <input type='submit' name='continue' value='>Continue...' style='color:#00a133; font-family:zig; font-size:20px; border:none; background:none;'>\
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
        <input type='hidden' name='mSTR' value='%d'>\n\
        <input type='hidden' name='mVIT' value='%d'>\n\
        <input type='hidden' name='mDEX' value='%d'>\n\
        <input type='hidden' name='mAGI' value='%d'>\n\
        <input type='hidden' name='mname' value='%s'>\n\
        <input type='hidden' name='mlevel' value='%d'>\n\
        <input type='hidden' name='mhp' value='%d'>\n\
        <input type='hidden' name='character' value='%s'>\n\
        <input type='hidden' name='experience' value='%d'>\n\
        \
      </form>\
      </div>\
      </div>\
\
\
  <style type='text/css'>\
    body, a:hover {\
      cursor: url(/gam134.cur), progress !important;}\
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
", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, pturn, cur_monster.mSTR, cur_monster.mVIT, cur_monster.mDEX, cur_monster.mAGI, cur_monster.mname, cur_monster.mlevel, cur_monster.mhp, character, experience);

  } else if (pturn && hp != 0 && cur_monster.mhp != 0 && !strcmp(command, "ATTACK")) {
    int cur_hp = cur_monster.mhp;

    hit = hit_success(DEX, cur_monster.mAGI);

    if (hit) {
      cur_monster.mhp = cur_health(cur_monster.mhp, dmg_attack(STR, level), dmg_reduction(cur_monster.mVIT, cur_monster.mlevel));
    }

    pturn = 0;
    printf("\
<!-- HUD -->\
\
  <div id='menu'>\
    <div style='width:100%%; height:100px; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='text-align:center; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='mhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
  </div>\
  <div>\
  <img src='/mp1_images/%s.gif' style='height:150px;' class='img-responsive center-block'><br>\
  </div>\
  ", cur_monster.mlevel, cur_monster.mname, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, (float) (cur_monster.mhp / ((cur_monster.mVIT * 3.0) + 11.0)) * 100.0, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, cur_monster.mname);
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
  ", level, name, hp, (VIT * 3) + 11, (float) (hp / ((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 5, (float) (mp / ((MAG * 3.0) + 5.0)) * 100.0, mp, (MAG * 3) + 5);


    if (hit) {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s ATTACKS!<br><br>>%s takes %d damage!</p>\
      </div>\
    ", name, cur_monster.mname, cur_hp - cur_monster.mhp);
    } else {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s ATTACKS!<br><br>>But it missed!</p>\
      </div>\
    ", name);
    }

    printf("\
\
      <form action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
        <input type='submit' name='continue' value='>Continue...' style='color:#00a133; font-family:zig; font-size:20px; border:none; background:none;'>\
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
        <input type='hidden' name='mSTR' value='%d'>\n\
        <input type='hidden' name='mVIT' value='%d'>\n\
        <input type='hidden' name='mDEX' value='%d'>\n\
        <input type='hidden' name='mAGI' value='%d'>\n\
        <input type='hidden' name='mname' value='%s'>\n\
        <input type='hidden' name='mlevel' value='%d'>\n\
        <input type='hidden' name='mhp' value='%d'>\n\
        <input type='hidden' name='character' value='%s'>\n\
        <input type='hidden' name='experience' value='%d'>\n\
        \
      </form>\
      </div>\
      </div>\
\
\
  <style type='text/css'>\
    body, a:hover {\
      cursor: url(/gam134.cur), progress !important;}\
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
", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, pturn, cur_monster.mSTR, cur_monster.mVIT, cur_monster.mDEX, cur_monster.mAGI, cur_monster.mname, cur_monster.mlevel, cur_monster.mhp, character, experience);

  } else if (pturn && hp != 0 && cur_monster.mhp != 0 && !strcmp(command, "SKILL")) {
    int cur_hp = cur_monster.mhp;
    int insufficient_mp = 0;
    if (mp >= 2) {
      pturn = 0;
      mp -= 2;
      hit = hit_success(DEX, cur_monster.mAGI);
      if (hit) {
        cur_monster.mhp = cur_health(cur_monster.mhp, dmg_skill(MAG, level), dmg_reduction(cur_monster.mVIT, cur_monster.mlevel));
      }
    } else {
      insufficient_mp++;
    }


    printf("\
<!-- HUD -->\
\
  <div id='menu'>\
    <div style='width:100%%; height:100px; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='text-align:center; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='mhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
  </div>\
  <div>\
  <img src='/mp1_images/%s.gif' style='height:150px;' class='img-responsive center-block'><br>\
  </div>\
  ", cur_monster.mlevel, cur_monster.mname, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, (float) (cur_monster.mhp / ((cur_monster.mVIT * 3.0) + 11.0)) * 100.0, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, cur_monster.mname);
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
  ", level, name, hp, (VIT * 3) + 11, (float) (hp / ((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 5, (float) (mp / ((MAG * 3.0) + 5.0)) * 100.0, mp, (MAG * 3) + 5);

    if (insufficient_mp) {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>Insufficient MP!</p>\
      </div>\
      ");
    } else if (hit) {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s USES FIRA!<br><br>>%s takes %d damage!</p>\
      </div>\
    ", name, cur_monster.mname, cur_hp - cur_monster.mhp);
    } else {
      printf("\
      <div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s USES FIRA!<br><br>>But it missed!</p>\
      </div>\
    ", name);
    }

    printf("\
\
      <form action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
        <input type='submit' name='continue' value='>Continue...' style='color:#00a133; font-family:zig; font-size:20px; border:none; background:none;'>\
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
        <input type='hidden' name='mSTR' value='%d'>\n\
        <input type='hidden' name='mVIT' value='%d'>\n\
        <input type='hidden' name='mDEX' value='%d'>\n\
        <input type='hidden' name='mAGI' value='%d'>\n\
        <input type='hidden' name='mname' value='%s'>\n\
        <input type='hidden' name='mlevel' value='%d'>\n\
        <input type='hidden' name='mhp' value='%d'>\n\
        <input type='hidden' name='character' value='%s'>\n\
        <input type='hidden' name='experience' value='%d'>\n\
        \
      </form>\
      </div>\
      </div>\
\
\
  <style type='text/css'>\
    body, a:hover {\
      cursor: url(/gam134.cur), progress !important;}\
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
", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, pturn, cur_monster.mSTR, cur_monster.mVIT, cur_monster.mDEX, cur_monster.mAGI, cur_monster.mname, cur_monster.mlevel, cur_monster.mhp, character, experience);

  } else if (pturn && hp != 0 && cur_monster.mhp != 0 && !strcmp(command, "DEFEND")) {
    pturn = 0;
    printf("\
<!-- HUD -->\
\
  <div id='menu'>\
    <div style='width:100%%; height:100px; float:left; background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px;' class='well'>\
      <div style='text-align:center; color:#00a133;'>\
        <h4 style='white-space:pre; display:inline; font-family:zig'>> Lv%d  </h4>\
        <h2 style='white-space:pre; display:inline; font-family:mana'>%s</h2>\
      </div>\
\
      <div class='progress' name='mhp' style='height:25px; margin-top:10px;'>\
        <div class='progress-bar progress-bar-success mana active' role='progressbar'\
        aria-valuenow='%d' aria-valuemin='0' aria-valuemax='%d' style='width:%f%%; font-family:zig; color:#222222; font-size:20px;'>\
        HP:%d/%d\
        </div>\
    </div>\
  </div>\
  <div>\
  <img src='/mp1_images/%s.gif' style='height:150px;' class='img-responsive center-block'><br>\
  </div>\
  ", cur_monster.mlevel, cur_monster.mname, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, (float) (cur_monster.mhp / ((cur_monster.mVIT * 3.0) + 11.0)) * 100.0, cur_monster.mhp, (cur_monster.mVIT * 3) + 11, cur_monster.mname);
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
  ", level, name, hp, (VIT * 3) + 11, (float) (hp / ((VIT * 3.0) + 11.0)) * 100.0, hp, (VIT * 3) + 11, mp, (MAG * 3) + 5, (float) (mp / ((MAG * 3.0) + 5.0)) * 100.0, mp, (MAG * 3) + 5);

    printf("<div style='font-family:zig; color:#00a133; font-size:20px;'>\
        <p>>%s DEFENDED!</p>\
      </div>\
      ", name);

    printf("\
\
      <form action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data'>\
        <input type='submit' name='continue' value='>Continue...' style='color:#00a133; font-family:zig; font-size:20px; border:none; background:none;'>\
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
        <input type='hidden' name='mSTR' value='%d'>\n\
        <input type='hidden' name='mVIT' value='%d'>\n\
        <input type='hidden' name='mDEX' value='%d'>\n\
        <input type='hidden' name='mAGI' value='%d'>\n\
        <input type='hidden' name='mname' value='%s'>\n\
        <input type='hidden' name='mlevel' value='%d'>\n\
        <input type='hidden' name='mhp' value='%d'>\n\
        <input type='hidden' name='defend' value='1'>\n\
        <input type='hidden' name='character' value='%s'>\n\
        <input type='hidden' name='experience' value='%d'>\n\
        \
      </form>\
      </div>\
      </div>\
\
\
  <style type='text/css'>\
    body, a:hover {\
      cursor: url(/gam134.cur), progress !important;}\
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
", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, pturn, cur_monster.mSTR, cur_monster.mVIT, cur_monster.mDEX, cur_monster.mAGI, cur_monster.mname, cur_monster.mlevel, cur_monster.mhp, character, experience);

  } else if (pturn && hp != 0 && cur_monster.mhp != 0 && !strcmp(command, "RUN")) {
    int fled = 0;
    fled = flee_success(AGI, level, cur_monster.mlevel);

    if (fled) {
      printf("\
          <html><body style='background-color:transparent'>\
          	<div style='background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px; text-align:center' class='well'>\
            <h1 style='color:#00a133; font-family:zig;'>Successfully escaped from monster!</h1><br>\
            <form target='_parent' action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' enctype='multipart/form-data' method='post'>\
              <input type='submit' value='> Back to map screen' style='color:#00a133; font-family:zig; font-size:30px; border:none; background:none;'>\
            	<input type='hidden' value='1' name='redirect'>\
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
        			<input type='hidden' name='character' value='%s'>\n\
        			<input type='hidden' name='experience' value='%d'>\n\
            </form>\
            </div>\
          </body></html>", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, character, experience);
    } else {
      battle_screen(cur_monster, 0, character, name, level, hp, mp, x, y, STR, MAG, VIT, DEX, AGI, "", defend, fled, experience);
    }

  } else if (cur_monster.mhp == 0) {
    //int experience = 0; //temporary

    //printf("EXPERIENCE = %d", experience);

    int temp_exp = experience + (cur_monster.mlevel * 3) + (level) - 1;

    printf("\n\
          <html><body>\n\
            <div style='background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px; text-align:center' class='well'>\n\
            <h1 style='color:#00a133; font-family:zig;'>>YOU WIN!!!</h1><br>\n\
            <h1 style='color:#00a133; font-family:zig;'>>You gained %d EXP!</h1><br>\n\
            ", (cur_monster.mlevel * 3) + (level) - 1);
    
    if (temp_exp >= ((level * level) + 2) ) {

      hp = (VIT * 3) + 11;
      mp =  (MAG * 3) + 5;
      temp_exp = temp_exp - ((level * level) + 2); // sobra if meron;
      level++;
      experience = temp_exp;

      printf("\
            <h1 style='color:#00a133; font-family:zig;'>>You are now level %d!</h1><br>\n\
            <button type='button' style='background-color:transparent; border:none; font-family:zig; font-size:30px; color:#00a133;' id='allocate' data-toggle='modal'\n\
              data-target='#allocate_stats'>\n\
                >Allocate stats...\n\
            </button>\n\
           <div id='allocate_stats' class='modal fade' role='dialog'>\n\
              <div class='modal-dialog'>\n\
                 <div class='modal-content'>\n\
                    <div class='modal-header' style=' background:#33a6cc'>\n\
                       <h3 class='modal-title' style='font-family:mana; color:white;'>Stat Allocation</h3>\n\
                    </div>\n\
                    <form class='form' action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' method='post' enctype='multipart/form-data' role='form'  onsubmit='return validateStats();' target='_parent'>\n\
                       <div class='modal-body'>\n\
                          <div class='mana'>\n\
                             <label for='STR' style='font-size:20px; font-weight:normal;'>\n\
                                STR:\n\
                             </label>\n\
                             <input type='number' name='STR' value='%d' min='%d' max='%d' step='1'><br>\n\
                             \n\
                             <label for='MAG' style='font-size:20px; font-weight:normal;'>\n\
                                MAG:\n\
                             </label>\n\
                             <input type='number' name='MAG' value='%d' min='%d' max='%d' step='1'><br>\n\
                             \n\
                             <label for='VIT' style='font-size:20px; font-weight:normal;'>\n\
                                VIT:\n\
                             </label>\n\
                             <input type='number' name='VIT' value='%d' min='%d' max='%d' step='1'><br>\n\
                             \n\
                             <label for='AGI' style='font-size:20px; font-weight:normal;'>\n\
                                AGI:\n\
                             </label>\n\
                             <input type='number' name='AGI' value='%d' min='%d' max='%d' step='1'><br>\n\
                             \n\
                             <label for='DEX' style='font-size:20px; font-weight:normal;'>\n\
                                DEX:\n\
                             </label>\n\
                             <input type='number' name='DEX' value='%d' min='%d' max='%d' step='1'>\n\
                             <br>\
                            <input type='hidden' value='1' name='redirect'>\
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
                            <input type='hidden' name='character' value='%s'>\n\
                            <input type='hidden' name='experience' value='%d'>\n\
                          </div>\n\
                          \n\
                       </div>\n\
                       <div class='modal-footer' style='background:#ef4a59'>\n\
                          <div id='alert' style='text-align:left;'></div>\n\
                          <button type='submit' class='btn btn-primary' style='font-family:prstart; font-weight: normal;'>\n\
                             Back to Map\n\
                          </button>\n\
                       </div>\n\
                    </form>\n\
                 </div>\n\
              </div>\n\
          </div>\n\
          <script src='/bootstrap-3.3.5-dist/jquery-1.11.3.min.js'></script>\n\
          <script src='/bootstrap-3.3.5-dist/jquery-2.1.4.min.js'></script>\n\
          <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.min.js'></script>\n\
          <script type='text/javascript'>\n\
            function validateStats() {\n\
            var STR = %d;\n\
            var MAG = %d;\n\
            var VIT = %d;\n\
            var DEX = %d;\n\
            var AGI = %d;\n\
            var pts = +document.getElementsByName('STR')[0].value + +document.getElementsByName('MAG')[0].value + +document.getElementsByName('VIT')[0].value + +document.getElementsByName('AGI')[0].value + +document.getElementsByName('DEX')[0].value;\n\
\
            if( pts >  (STR + MAG + VIT + DEX + AGI + 3)){\n\
              alert('HEY');\
             document.getElementById('alert').innerHTML = '<div class='alert alert-danger mana'>You can only allocate 3 stat points.</div>';\n\
             return false;\n\
            } else if (pts < (STR + MAG + VIT + DEX + AGI + 3)){\n\
             document.getElementById('alert').innerHTML = '<div class='alert alert-danger mana'>Please allocate 3 stat points.</div>';\n\
             return false;\n\
            }\n\
\n\
             return true;\n\
            }\n\
             </script>\n\
             ", level, STR, STR, STR + 3, MAG, MAG, MAG + 3, VIT, VIT, VIT + 3, DEX, DEX, DEX + 3, AGI, AGI, AGI + 3, STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI);

    } else {
      experience = temp_exp;


      printf("\
            <form target='_parent' action='http://kh.celinemarcelo.com/cgi-bin/battle.cgi' enctype='multipart/form-data' method='post'>\
              <input type='submit' name='back_to_map' value='>Back to map' style='color:#00a133; font-family:zig; font-size:30px; border:none; background:none;'>\n\
        			<input type='hidden' value='1' name='redirect'>\
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
			        <input type='hidden' name='character' value='%s'>\n\
			        <input type='hidden' name='experience' value='%d'>\n\
            </form>\
            </div>\
          </html></body>", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, character, experience);
    }
  } else if (hp == 0) {

    if (!(strcmp("sora", character))) {
      printf("\
        <html><body>\n\
            <div style='background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px; text-align:center' class='well'>\n\
        <img src='/mp1_images/soragameover.gif'>\
        ");
    } else {
      printf("\
        <html><body>\n\
            <div style='background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px; text-align:center' class='well'>\n\
        <img src='/mp1_images/rikugameover.gif'>\
        ");
    }

    printf("\n\
              <h1 style='color:#00a133; font-family:zig;'>>Game over</h1><br>\n\
              <a href='http://kh.celinemarcelo.com/index.html' style='font-size:30px; color:#00a133; font-family:zig;' target='_parent'>\
                >Go to home screen\n\
              </a>\n\
              <style type='text/css'>\
                body, a:hover {\
                  /*cursor: url(gam134.cur), progress !important;}*/\
                  cursor: url(/gam134.cur), progress !important;\
                }\
              </style>\
              <a href='http://www.cursors-4u.com/cursor/2006/04/02/gam134.html' target='_blank' title='Keyblade'>\
              <img src='http://cur.cursors-4u.net/cursor.png' border='0' alt='Keyblade' style='position:absolute; top: 0px; right: 0px;' />\
           </a>\
           ");
  }
}


monster_info get_monster(int level) {
  monster_info this;
  int m_id = 0;

  this.mlevel = rand_monster_lvl(level);
  this.mname = malloc(10);

  int connect = 0, i = 0, j = 0;
  char query[3] = {};

  MYSQL mysql;
  MYSQL_RES *res;
  MYSQL_ROW row;

  unsigned int num_fields = 0;

  srand(time(NULL));
  m_id = rand() % 6;

  if (mysql_init(&mysql)) {
    if (!mysql_real_connect(&mysql, "mydb.cqueamw43gnb.ap-northeast-1.rds.amazonaws.com", "celinemarcelo", "bookerdewitt", "MP1", 3306, NULL, 0)) {
      //  puts("<h1>Error in connecting database.</h1>");
    } else {
      //  puts("<h1>Connected!</h1>");
      connect++;
    }
  }

  if (connect) {
    sprintf(query, "SELECT * FROM Monsters WHERE id=%d", m_id);
    //printf("%s\n", query);
    mysql_query(&mysql, query);
    res = mysql_store_result(&mysql);

    if (res) {
      num_fields = mysql_num_fields(res);

      if (num_fields) {
        row = mysql_fetch_row(res);

        for (j = 0; j < mysql_num_rows(res); j++) {
          for (i = 0; i < num_fields; i++) {
            // printf("<td>%.*s</td>", (int) lengths[i], row[i]);
            switch (i) {
            case 1:
              strcpy(this.mname, row[i]);
              break;

            case 2:
              this.mSTR = atoi(row[i]);
              break;

            case 3:
              this.mVIT = atoi(row[i]);
              break;

            case 4:
              this.mDEX = atoi(row[i]);
              break;

            case 5:
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

  this.mSTR = (this.mSTR) + (this.mlevel);
  this.mVIT = (this.mVIT) + (this.mlevel);
  this.mDEX = (this.mDEX) + (this.mlevel);
  this.mAGI = (this.mAGI) + (this.mlevel);

  this.mhp = (this.mVIT * 3) + 11;

  return this;
}

int main(void) {
  char data[MAXLEN] = {};
  char character[5] = {};
  char name[DATALEN] = {}, mname[10] = {};
  char choice[10] = {};
  int fled = 2;
  int battle_proper = 0;
  char bproper[2] = {};
  int pturn = 0;
  char pturn_c[2] = {};
  char holder[10] = {};
  char command[10] = {};
  int defend = 0;
  int redirect_int = 0;
  char redirect[2] = {};

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
  char experience[3] = {};
  int experience_int = 0;

  monster_info cur_monster;

  cur_monster.mname = malloc(10);

  cgi_init();
  start_html("Kingdom Hearts: Zeroth Dimension");

  get_data(get_length(), &data[0]);

  get_element(&data[0], "battle_proper", &bproper[0]);
  bproper[strlen(bproper) - 2] = 0;
  battle_proper = atoi(bproper);

  get_element(&data[0], "redirect", &redirect[0]);
  redirect[strlen(redirect) - 2] = 0;
  redirect_int = atoi(redirect);

  get_element(&data[0], "character", &character[0]);
  character[strlen(character) - 2] = 0;

  get_element(&data[0], "name", &name[0]);
  name[strlen(name) - 2] = 0;

  get_element(&data[0], "STR", &STR[0]);
  STR[strlen(STR) - 2] = 0;
  STR_int = atoi(STR);

  get_element(&data[0], "MAG", &MAG[0]);
  MAG[strlen(MAG) - 2] = 0;
  MAG_int = atoi(MAG);

  get_element(&data[0], "VIT", &VIT[0]);
  VIT[strlen(VIT) - 2] = 0;
  VIT_int = atoi(VIT);

  get_element(&data[0], "AGI", &AGI[0]);
  AGI[strlen(AGI) - 2] = 0;
  AGI_int = atoi(AGI);

  get_element(&data[0], "DEX", &DEX[0]);
  DEX[strlen(DEX) - 2] = 0;
  DEX_int = atoi(DEX);

  get_element(&data[0], "level", &level[0]);
  level[strlen(level) - 2] = 0;
  level_int = atoi(level);

  get_element(&data[0], "hp", &hp[0]);
  hp[strlen(hp) - 2] = 0;
  hp_int = atoi(hp);

  get_element(&data[0], "mp", &mp[0]);
  mp[strlen(mp) - 2] = 0;
  mp_int = atoi(mp);

  get_element(&data[0], "x", &x[0]);
  x[strlen(x) - 2] = 0;
  x_int = atoi(x);

  get_element(&data[0], "y", &y[0]);
  y[strlen(y) - 2] = 0;
  y_int = atoi(y);

  get_element(&data[0], "experience", &experience[0]);
  experience[strlen(experience) - 2] = 0;
  experience_int = atoi(experience);


  if (redirect_int) {
    map_screen(character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int, experience_int, 1);
    return 0;
  }

  if (battle_proper) {
    get_element(&data[0], "pturn", &pturn_c[0]);
    pturn_c[strlen(pturn_c) - 2] = 0;
    pturn = atoi(pturn_c);

    get_element(&data[0], "mname", &mname[0]);
    mname[strlen(mname) - 2] = 0;
    strcpy(cur_monster.mname, mname);

    get_element(&data[0], "mSTR", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    cur_monster.mSTR = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "mVIT", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    cur_monster.mVIT = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "mAGI", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    cur_monster.mAGI = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "mDEX", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    cur_monster.mDEX = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "mlevel", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    cur_monster.mlevel = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "mhp", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    cur_monster.mhp = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "defend", &holder[0]);
    holder[strlen(holder) - 2] = 0;
    defend = atoi(holder);
    memset(holder, 0, 10);

    get_element(&data[0], "attack", &holder[0]);
    holder[strlen(holder) - 2] = 0;

    if (!strcmp("ATTACK", holder)) {
      strcpy(command, holder);
    } else {
      get_element(&data[0], "skill", &holder[0]);
      holder[strlen(holder) - 2] = 0;

      if (!strcmp("SKILL", holder)) {
        strcpy(command, "SKILL");
      } else {
        get_element(&data[0], "defend", &holder[0]);
        holder[strlen(holder) - 2] = 0;

        if (!strcmp("DEFEND", holder)) {
          strcpy(command, "DEFEND");
        } else {
          get_element(&data[0], "run", &holder[0]);
          holder[strlen(holder) - 2] = 0;

          if (!strcmp("RUN", holder)) {
            strcpy(command, "RUN");
          }
        }
      }
    }

    battle_screen(cur_monster, pturn, character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int, command, defend, fled, experience_int);

  } else {

    get_element(&data[0], "fight", &choice[0]);

    cur_monster = get_monster(level_int);

    if (strcmp(choice, "")) {
      if (AGI_int > cur_monster.mAGI) {
        pturn = 1;
      } else {
        pturn = 0;
      }

      battle_screen(cur_monster, pturn, character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int, "", defend, fled, experience_int);
    } else {

      fled = flee_success(AGI_int, level_int, cur_monster.mlevel);

      if (fled) {
        printf("\
          <html>\
          <head><link rel='stylesheet' type='text/css' href='/style.css'></head>\
          <body style='background-color:transparent'>\
            <div style='background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px; text-align:center' class='well'>\
            <h1 style='color:#00a133; font-family:zig;'>Successfully escaped from monster!</h1><br>\
            <form target='_parent' enctype='multipart/form-data' method='post'>\
              <input type='submit' value='> Back to map screen' style='color:#00a133; font-family:zig; font-size:30px; border:none; background:none;'>\
            	<input type='hidden' value='1' name='redirect'>\
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
        			<input type='hidden' name='character' value='%s'>\n\
        			<input type='hidden' name='experience' value='%d'>\n\
            </form>\
            </div>\
          </body></html>", STR_int, MAG_int, VIT_int, DEX_int, AGI_int, name, level_int, hp_int, mp_int, x_int, y_int, character, experience_int);
      } else {
        battle_screen(cur_monster, 0, character, name, level_int, hp_int, mp_int, x_int, y_int, STR_int, MAG_int, VIT_int, DEX_int, AGI_int, "", defend, fled, experience_int);
      }
    }
  }



  end_html();
  return 0;

}
