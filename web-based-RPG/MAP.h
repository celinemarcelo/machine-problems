#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ME4.h"

void map_screen(char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI){
	printf("<!-- Map Screen html -->\n\
<!DOCTYPE html>\n\
<html>\n\
<head>\n\
  <meta charset='utf-8'>\n\
  <meta name='viewport' content='width=device-width, initial-scale=1'>\n\
  <meta name='description' content='MP1 sample'>\n\
  <meta name='author' content='Baquiran & Marcelo'>\n\
  <title>MAP SCREEN</title>\n\
  \n\
  <link href='icon.ico' rel='shortcut icon'>\n\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap.min.css'>\n\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css'>\n\
  <link rel='stylesheet' type='text/css' href='/MP1map_screen_style.css'>\n\
  <link rel='stylesheet' type='text/css' href='/style.css'>\n\
</head>\n\n");

  printf("<body id='map-body' style='background-color:transparent'>\n\
  <div class='container' style='margin:30px 20px 30px 20px;'>\n\
    <!-- Arrows -->\n\
    <div class='col-md-2' id='ms_arrow'>\n\
      <!-- Up -->\n\
      <div class='row' >\n\
          <div class='col-md-3'></div>\n\
          <div class='col-md-6'>\n\
           <form action='http://localhost/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='map'>\n\
              <input type='hidden' name='direction' value='up'>\n\
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
              <input class='dir_im' type='image' name='up' src='/mp1_images/ar_up.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-3'></div>\n\
      </div>\n\
      <!-- Left and Right -->\n\
      <div class='row'>\n\
          <div class='col-md-6'>\n\
           <form action='http://localhost/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='map'>\n\
              <input type='hidden' name='direction' value='left'>\n\
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
              <input class='dir_im' type='image' name='left' src='/mp1_images/ar_left.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-6'>\n\
             <form action='http://localhost/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='map'>\n\
              <input type='hidden' name='direction' value='right'>\n\
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
              <input class='dir_im' type='image' name='right' src='/mp1_images/ar_right.png'>\n\
            </form>\n\
          </div>\n\
      </div>\n\
      <!-- Down -->\n\
      <div class='row'>\n\
          <div class='col-md-3'></div>\n\
          <div class='col-md-6'>\n\
           <form action='http://localhost/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='map'>\n\
              <input type='hidden' name='direction' value='down'>\n\
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
              <input class='dir_im' type='image' name='down' src='/mp1_images/ar_down.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-3'></div>\n\
      </div>\n\
    </div>\n\n", STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character);

  // MAP
  printf("  <!-- MAP -->\n\
    <div class='col-md-8' id='ms_map' style='padding-right: 100px; padding-left: 100px;'>\n\
      <div class='embed-responsive embed-responsive-16by16'> \n\
        <iframe name='map' class='embed-responsive-item' scrolling='no' allowtransparency='true' id='map' srcdoc='\n\
  <link rel=\"stylesheet\" href=\"/bootstrap-3.3.5-dist/css/bootstrap.min.css\">\n\
  <link rel=\"stylesheet\" href=\"/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css\">\n\
  <link rel=\"stylesheet\" type=\"text/css\" href=\"/MP1map_screen_style.css\">\n\
\n\
  <table class=\"table_map\">\n");
  
  int a, b;
  for (a = 0; a <= 8; ++a) {
    printf("<tr class=\"row_map\" id=\"row%d\"\n>", a);
    for (b = 1; b <= 9; ++b) {
      printf("    <td class=\"cell_map\"><img class=\"img_map\" src=\"/mp1_images/kh_tiled%d.png\" id=\"cell%d\">", ((a%2)*2)+1+(b%2),b);
      if ( (a==y) && (b==x) ) {
        if ( !(strcmp(character, "sora"))) {
          printf("    <img class=\"img2_map\" src=\"/mp1_images/idle.gif\" id=\"sprite\">\n");
        } else {
          printf("    <img class=\"img2_map\" src=\"/mp1_images/idle2.gif\" id=\"sprite\">\n");
        }
      }
      printf("</td>\n");  
    }
    printf("</tr>\n");
  }
    
  printf("</table><script>\
    function enable() {\
      window.parent.document.getElementsByName(\"save\")[0].disabled = false; \
      window.parent.document.getElementsByName(\"up\")[0].disabled = false; \
      window.parent.document.getElementsByName(\"right\")[0].disabled = false; \
      window.parent.document.getElementsByName(\"left\")[0].disabled = false; \
      window.parent.document.getElementsByName(\"down\")[0].disabled = false; \
    } \
    window.onload = enable;\
  </script>\
  '></iframe> \n\
      </div>\n\
    </div>\n\n");
  
  // HUD and Save
  printf(" <!-- HUD and Save --> \
    <div class='col-md-2' id='ms_hud' style='padding-left: 15px;'>\
      <div class='row'>\
        <!-- HUD -->\
        <table class='table table-bordered' id='player_info'>\
          <tr>\
            <td>Level</td>\
            <td>%d</td>\
          </tr>\
          <tr>\
            <td>Health</td>\
            <td>%d</td>\
          </tr>\
          <tr>\
            <td>Mana</td>\
            <td>%d</td>\
          </tr>\
        </table>\
      </div>\
      <div class='row'>\
        <table class='table table-bordered' id='player_stats'> \
          <thead class='hud_info'>\
            <tr>\
              <th>STR</th>\
              <th>MAG</th>\
              <th>VIT</th>\
              <th>DEX</th>\
              <th>AGI</th>\
              <th>x</th>\
              <th>y</th>\
            </tr>\
          </thead>\
          <tbody>\
            <tr>\
              <td>%d</td>\
              <td>%d</td>\
              <td>%d</td>\
              <td>%d</td>\
              <td>%d</td>\
              <td>%d</td>\
              <td>%d</td>\
            </tr>\
          </tbody>\
        </table>\
      </div>\
      <!-- Save and Exit -->\
      <div class='row' style='padding-top:20px'>\
        <div class='form-group' style='font-size:20px'>\
          <form>\
            <input type='button' class='btn btn-primary save logo' style='font-size:30px' name='save' value='Save'>\
            <a href='http://localhost/index.html'><input type='button' class='btn btn-primary save logo' style='font-size:30px' value='Exit'></a>\
          </form>\
        </div>\
      </div>\
    </div>\
  </div>\
   <script src='/bootstrap-3.3.5-dist/jquery-1.11.3.min.js'></script>\
   <script src='https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>\
   <!-- <script src='/bootstrap-3.3.5-dist/jquery-2.1.4.min.js'></script> -->\
   <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js'></script>\
   <!-- <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.min.js'></script>\
   <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.js'></script> -->\
   <script>\
    function enable() {\
      document.getElementsByName('save')[0].disabled = false; \
      document.getElementsByName('up')[0].disabled = false; \
      document.getElementsByName('right')[0].disabled = false; \
      document.getElementsByName('left')[0].disabled = false; \
      document.getElementsByName('down')[0].disabled = false; \
    } \
    window.onload = enable;\
  </script>\
   <style type='text/css'>\
      body, a:hover {\
         /*cursor: url(http://cur.cursors-4u.net/games/gam-2/gam134.cur), progress !important;}*/\
         cursor: url(gam134.cur), progress !important;\
      }\
   </style>\
   <a href='http://www.cursors-4u.com/cursor/2006/04/02/gam134.html' target='_blank' title='Keyblade'>\
      <img src='http://cur.cursors-4u.net/cursor.png' border='0' alt='Keyblade' style='position:absolute; top: 0px; right: 0px;' />\
   </a>\
  <!-- <audio autoplay='' loop=''><source src='/A Walk in Andante.mp3' type='audio/mpeg'></audio>  -->\
</body>\
</html>\n\n", level, hp, mp, STR, MAG, VIT, DEX, AGI, x, y);

}


#endif /* MAP_H_ */
