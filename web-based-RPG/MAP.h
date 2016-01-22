#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ME4.h"

void map_screen(char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI, int experience, int motion){
  if ((hp + 5) >= (VIT * 3) + 11) {
    hp = (VIT * 3) + 11;
  } else {
    hp += 5;
  }

  if ((mp + 3) >= (MAG * 3) + 5) {
    mp = (MAG * 3) + 5;
  } else {
    mp += 3;
  }



  printf("<!-- Map Screen html -->\n\
<!DOCTYPE html>\n\
<html>\n\
<head>\n\
  <meta charset='utf-8'>\n\
  <meta name='viewport' content='width=device-width, initial-scale=1'>\n\
  <meta name='description' content='MP1'>\n\
  <meta name='author' content='Baquiran & Marcelo'>\n\
  <title>MAP SCREEN</title>\n\
  \n\
  <link href='/icon.ico' rel='shortcut icon'>\n\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap.min.css'>\n\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css'>\n\
  <link rel='stylesheet' type='text/css' href='/style.css'>\n\
  <link rel='stylesheet' type='text/css' href='/MP1_map_screen_style.css'>\n\
</head>\n\n");

  printf("<body id='map-body' style='background-color:transparent'>\n\
  <div class='container' style='margin:30px 20px 30px 20px;'>\n\
    <!-- Arrows -->\n\
    <div class='col-md-2' id='ms_arrow'>\n\
      <!-- Up -->\n\
      <div class='row' >\n\
          <div class='col-md-3'></div>\n\
          <div class='col-md-6'>\n\
           <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='up' src='/mp1_images/ar_up.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-3'></div>\n\
      </div>\n\
      <!-- Left and Right -->\n\
      <div class='row'>\n\
          <div class='col-md-6'>\n\
           <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='left' src='/mp1_images/ar_left.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-6'>\n\
             <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='right' src='/mp1_images/ar_right.png'>\n\
            </form>\n\
          </div>\n\
      </div>\n\
      <!-- Down -->\n\
      <div class='row'>\n\
          <div class='col-md-3'></div>\n\
          <div class='col-md-6'>\n\
           <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='down' src='/mp1_images/ar_down.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-3'></div>\n\
      </div>\n\
    </div>\n\n", STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience);
    
    printf("  <!-- MAP -->\n\
    <div class='col-md-8' id='ms_map' style='padding-right: 100px; padding-left: 100px;'>\n\
      <div class='embed-responsive embed-responsive-16by16'> \n\
        <iframe name='map' class='embed-responsive-item' scrolling='no' allowtransparency='true' srcdoc='\n\
  <link rel=\"stylesheet\" href=\"/bootstrap-3.3.5-dist/css/bootstrap.min.css\">\n\
  <link rel=\"stylesheet\" href=\"/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css\">\n\
  <link rel=\"stylesheet\" type=\"text/css\" href=\"/MP1_map_screen_style.css\">\n\
\n");
  
  printf("<table class=\"table_map\">\n");
  
  int a, b;
  for (a = 1; a <= 9; ++a) {
    printf("<tr class=\"row_map\" id=\"row%d\">", a);
    for (b = 1; b <= 9; ++b) {

      if ( (a==y) && (b==x) ) {
          printf("    <td class=\"cell_map\">\n");
          printf("        <div style=\"position:relative; dispay:inline;\" >\n");
          printf("        <img class=\"img_map\" src=\"/mp1_images/kh_tiled%d.png\" id=\"cell%d\">\n", ((a%2)*2)+1+(b%2),b); 

        // sprite
        if ( !(strcmp(character, "sora"))) {
          //sora
          if (motion) {
            switch(motion){
              case 1:
                printf("    <img class=\"img2_map\" src=\"/mp1_images/idle.gif\" id=\"sprite\">\n");
                break;
              case 2:
                printf("    <img class=\"img2_map\" src=\"/mp1_images/s_left.gif\" id=\"sprite\">\n");
                break;
              case 3:
                printf("    <img class=\"img2_map\" src=\"/mp1_images/s_down.gif\" id=\"sprite\">\n");
                break;
              case 4:
                printf("    <img class=\"img2_map\" src=\"/mp1_images/s_right.gif\" id=\"sprite\">\n");
                break;    
            }
          } else {
            printf("    <img class=\"img2_map\" src=\"/mp1_images/idle.gif\" id=\"sprite\">\n");
          }
        } else {
          //riku
          if (motion) {
            switch(motion){
              case 1:
                printf("    <img class=\"img3_map\" src=\"/mp1_images/idle2.gif\" id=\"sprite\">\n");
                break;
              case 2:
                printf("    <img class=\"img3_map\" src=\"/mp1_images/idle2.gif\" id=\"sprite\">\n");
                break;
              case 3:
                printf("    <img class=\"img3_map\" src=\"/mp1_images/r_down.gif\" id=\"sprite\">\n");
                break;
              case 4:
                printf("    <img class=\"img3_map\" src=\"/mp1_images/idle2.gif\" id=\"sprite\">\n");
                break;    
            } 
          } else {
                printf("    <img class=\"img2_map\" src=\"/mp1_images/idle2.gif\" id=\"sprite\">\n");
            }
          } 
        printf("</div></td>\n");  
        // printf("</div>\n");
      } else {
        printf("    <td class=\"cell_map\"><img class=\"img_map\" src=\"/mp1_images/kh_tiled%d.png\" id=\"cell%d\">", ((a%2)*2)+1+(b%2),b);
        printf("</td>\n");  
      }
    }
    printf("</tr>\n");
  }
    
  printf("</table>\n\
    <script>\n\
    function enable() {\n\
      window.parent.document.getElementsByName(\"save\")[0].disabled = false; \n\
      window.parent.document.getElementsByName(\"up\")[0].disabled = false; \n\
      window.parent.document.getElementsByName(\"right\")[0].disabled = false; \n\
      window.parent.document.getElementsByName(\"left\")[0].disabled = false; \n\
      window.parent.document.getElementsByName(\"down\")[0].disabled = false; \n\
    } \n\
    window.onload = enable;\n\
  </script>'></iframe> \n\
      </div>\n\
    </div>\n\n");

  // HUD and Save
  printf(" <!-- HUD and Save --> \n\
    <div class='col-md-2' id='ms_hud' style='padding-left: 10px;'>\n\
      <div class='row'>\n\
        <!-- HUD -->\n\
        <table class='table table-bordered' id='player_info' style='font-family:zig; color:#00a133; background: rgba(0, 0, 0, 0.9);'>\n\
          <tr>\n\
            <td>Name</td>\n\
            <td>%s</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Level</td>\n\
            <td>%d</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Health</td>\n\
            <td>%d</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Mana</td>\n\
            <td>%d</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Exp</td>\n\
            <td>%d / %d</td>\n\
          </tr>\n\
        </table>\n\
      </div>\n\
      <div class='row'>\n\
        <table class='table table-bordered' id='player_stats' style='font-family:zig; color:#00a133; background: rgba(0, 0, 0, 0.9);'> \n\
          <thead class='hud_info'>\n\
            <tr>\n\
              <th>STR</th>\n\
              <th>MAG</th>\n\
              <th>VIT</th>\n\
              <th>DEX</th>\n\
              <th>AGI</th>\n\
            </tr>\n\
          </thead>\n\
          <tbody>\n\
            <tr>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
            </tr>\n\
          </tbody>\n\
        </table>\n\
         <table class='table table-bordered' id='player_stats' style='font-family:zig; color:#00a133; background: rgba(0, 0, 0, 0.9);'> \n\
          <thead class='hud_info'>\n\
            <tr>\n\
              <th>x</th>\n\
              <th>y</th>\n\
            </tr>\n\
          </thead>\n\
          <tbody>\n\
            <tr>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
            </tr>\n\
          </tbody>\n\
        </table>\n\
      </div>\n\
      \n\
      <!-- Save and Exit -->\n\
      <div class='row' style='padding-top:20px'>\n\
        <div class='form-group' style='font-size:20px'>\n\
          <form>\n\
          <a href=\"#\"data-toggle=\"popover\" data-html=\"True\" data-placement=\"left\"\n\
            data-content=\"\n\
               <form class='form form-inline' action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form'>\n\
                  <div class='form-group'>\n\
                        <input type='submit' class='btn btn-primary save logo' value='Slot 1' name='slot'>\n\
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
                  <div class='form-group'>\n\
                        <input type='submit' class='btn btn-primary save logo' value='Slot 2' name='slot'>\n\
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
                  <div class='form-group'>\n\
                     <input type='submit' class='btn btn-primary save logo' value='Slot 3' name='slot'>\n\
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
               </form>\">\n\
            <input type='button' class='btn btn-primary save logo' style='font-size:30px' name='save' value='Save'></a>\n\
            \n\
            <a href='http://kh.celinemarcelo.com/index.html'><input type='button' class='btn btn-primary save logo' style='font-size:30px' value='Exit'></a>\n\
          </form>\n\
        </div>\n\
      </div>\n\
    </div>\n\
  </div>\n\
  <script src='/bootstrap-3.3.5-dist/jquery-1.11.3.min.js'></script>\n\
  <!-- <script src='https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script> -->\n\
  <script src='/bootstrap-3.3.5-dist/jquery-2.1.4.min.js'></script> -->\n\
  <!-- <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js'></script> -->\n\
  <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.min.js'></script>\n\
  <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.js'></script> -->\n\
\n\
   <script>\n\
      $(document).ready(function(){\n\
         $('[data-toggle=\"popover\"]').popover();\n\
      });\n\
   </script>\n\
   <script>\n\
    function enable() {\n\
      document.getElementsByName('save')[0].disabled = false; \n\
      document.getElementsByName('up')[0].disabled = false; \n\
      document.getElementsByName('right')[0].disabled = false; \n\
      document.getElementsByName('left')[0].disabled = false; \n\
      document.getElementsByName('down')[0].disabled = false; \n\
    } \n\
    window.onload = enable;\n\
  </script>\n\
   <style type='text/css'>\n\
      body, a:hover {\n\
         /*cursor: url(http://cur.cursors-4u.net/games/gam-2/gam134.cur), progress !important;}*/\n\
         cursor: url(/gam134.cur), progress !important;\n\
      }\n\
   </style>\n\
  <audio autoplay='' loop=''><source src='/A-Walk-in-Andante.mp3' type='audio/mpeg'></audio>\n\
</body>\n\
</html>\n\n", name, level, hp, mp, experience, ((level * level) +3), STR, MAG, VIT, DEX, AGI, x, y, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience);
}


void fight_flee(char *character, char *name, int level, int hp, int mp, int x, int y, int STR, int MAG, int VIT, int DEX, int AGI, int experience) {
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
  <link href='/icon.ico' rel='shortcut icon'>\n\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap.min.css'>\n\
  <link rel='stylesheet' href='/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css'>\n\
  <link rel='stylesheet' type='text/css' href='/MP1_map_screen_style.css'>\n\
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
           <form action='' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='up' src='/mp1_images/ar_up.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-3'></div>\n\
      </div>\n\
      <!-- Left and Right -->\n\
      <div class='row'>\n\
          <div class='col-md-6'>\n\
           <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='left' src='/mp1_images/ar_left.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-6'>\n\
             <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='right' src='/mp1_images/ar_right.png'>\n\
            </form>\n\
          </div>\n\
      </div>\n\
      <!-- Down -->\n\
      <div class='row'>\n\
          <div class='col-md-3'></div>\n\
          <div class='col-md-6'>\n\
           <form action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form' target='_parent'>\n\
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
              <input type='hidden' name='experience' value='%d'>\n\
              <input class='dir_im' type='image' name='down' src='/mp1_images/ar_down.png'>\n\
            </form>\n\
          </div>\n\
          <div class='col-md-3'></div>\n\
      </div>\n\
    </div>\n\n", STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience);

  // MAP
  printf("  <!-- MAP -->\n\
    <div class='col-md-8' id='ms_map' style='padding-right: 100px; padding-left: 100px;'>\n\
      <div class='embed-responsive embed-responsive-16by16'> \n\
        <iframe name='map' class='embed-responsive-item' scrolling='no' allowtransparency='true' id='map' srcdoc='\n\
        <body style=\"background-color:transparent\">\
  <link rel=\"stylesheet\" href=\"/bootstrap-3.3.5-dist/css/bootstrap.min.css\">\n\
  <link rel=\"stylesheet\" href=\"/bootstrap-3.3.5-dist/css/bootstrap-theme.min.css\">\n\
  <link rel=\"stylesheet\" href=\"/style.css\">\n\
\n\
  ");
  printf("<div style=\"background: rgba(0, 0, 0, 0.9); border:solid; border-radius: 15px; color:#00a133; font-size:50px; font-family:zig; text-align:center\" class=\"well\">\
            <h1>You encountered a monster! What will you do?<h1><br>\
            <form action=\"http://kh.celinemarcelo.com/cgi-bin/battle.cgi\" method=\"post\" enctype=\"multipart/form-data\" role=\"form\" target=\"map\">\
              <input type=\"submit\" name=\"fight\" value=\">FIGHT!\" style=\"border:none; background:none; padding:10px;\"><br><br>\
              <input type=\"submit\" name=\"flee\" value=\">FLEE...\" style=\"border:none; background:none; padding:10px;\">\
              <input type=\"hidden\" name=\"STR\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"MAG\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"VIT\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"DEX\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"AGI\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"name\" value=\"%s\">\n\
              <input type=\"hidden\" name=\"level\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"hp\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"mp\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"x\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"y\" value=\"%d\">\n\
              <input type=\"hidden\" name=\"character\" value=\"%s\">\n\
              <input type=\"hidden\" name=\"experience\" value=\"%d\">\n\
            </form>\
          </div>\
   ", STR, MAG, VIT, DEX, AGI, name, level, hp, mp, x, y, character, experience);

  printf("<script>\
    function disable() {\
      window.parent.document.getElementsByName(\"save\")[0].disabled = true; \
      window.parent.document.getElementsByName(\"up\")[0].disabled = true; \
      window.parent.document.getElementsByName(\"right\")[0].disabled = true; \
      window.parent.document.getElementsByName(\"left\")[0].disabled = true; \
      window.parent.document.getElementsByName(\"down\")[0].disabled = true; \
    } \
    window.onload = disable;\
  </script></body>\
  '></iframe> \n\
      </div>\n\
    </div>\n\n");

 // HUD and Save
  printf(" <!-- HUD and Save --> \n\
    <div class='col-md-2' id='ms_hud' style='padding-left: 10px;'>\n\
      <div class='row'>\n\
        <!-- HUD -->\n\
        <table class='table table-bordered' id='player_info' style='font-family:zig; color:#00a133; background: rgba(0, 0, 0, 0.9);'>\n\
          <tr>\n\
            <td>Name</td>\n\
            <td>%s</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Level</td>\n\
            <td>%d</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Health</td>\n\
            <td>%d</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Mana</td>\n\
            <td>%d</td>\n\
          </tr>\n\
          <tr>\n\
            <td>Exp</td>\n\
            <td>%d / %d</td>\n\
          </tr>\n\
        </table>\n\
      </div>\n\
      <div class='row'>\n\
        <table class='table table-bordered' id='player_stats' style='font-family:zig; color:#00a133; background: rgba(0, 0, 0, 0.9);'> \n\
          <thead class='hud_info'>\n\
            <tr>\n\
              <th>STR</th>\n\
              <th>MAG</th>\n\
              <th>VIT</th>\n\
              <th>DEX</th>\n\
              <th>AGI</th>\n\
            </tr>\n\
          </thead>\n\
          <tbody>\n\
            <tr>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
            </tr>\n\
          </tbody>\n\
        </table>\n\
         <table class='table table-bordered' id='player_stats' style='font-family:zig; color:#00a133; background: rgba(0, 0, 0, 0.9);'> \n\
          <thead class='hud_info'>\n\
            <tr>\n\
              <th>x</th>\n\
              <th>y</th>\n\
            </tr>\n\
          </thead>\n\
          <tbody>\n\
            <tr>\n\
              <td>%d</td>\n\
              <td>%d</td>\n\
            </tr>\n\
          </tbody>\n\
        </table>\n\
      </div>\n\
      <!-- Save and Exit -->\n\
      <div class='row' style='padding-top:20px'>\n\
        <div class='form-group' style='font-size:20px'>\n\
          <form>\n\
          <a href=\"#\"data-toggle=\"popover\" data-html=\"True\" data-placement=\"left\"\n\
            data-content=\"\n\
               <form class='form form-inline' action='http://kh.celinemarcelo.com/cgi-bin/MAP2.cgi' method='post' enctype='multipart/form-data' role='form'>\n\
                  <div class='form-group' style='padding: 10px;'>\n\
                        <input type='submit' class='btn btn-primary save logo' value='Slot 1' name='slot'>\n\
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
                  <div class='form-group' style='padding: 10px;'>\n\
                        <input type='submit' class='btn btn-primary save logo' value='Slot 2' name='slot'>\n\
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
                  <div class='form-group' style='padding: 10px;'>\n\
                     <input type='submit' class='btn btn-primary save logo' value='Slot 3' name='slot'>\n\
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
               </form>\">\n\
            <input type='button' class='btn btn-primary save logo' style='font-size:30px' name='save' value='Save'></a>\n\
            \n\
            <a href='http://kh.celinemarcelo.com/index.html'><input type='button' class='btn btn-primary save logo' style='font-size:30px' value='Exit'></a>\n\
          </form>\n\
        </div>\n\
      </div>\n\
    </div>\n\
  </div>\n\
  <script src='/bootstrap-3.3.5-dist/jquery-1.11.3.min.js'></script>\n\
  <!-- <script src='https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script> -->\n\
  <script src='/bootstrap-3.3.5-dist/jquery-2.1.4.min.js'></script> -->\n\
  <!-- <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js'></script> -->\n\
  <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.min.js'></script>\n\
  <script src='/bootstrap-3.3.5-dist/fonts/js/bootstrap.js'></script> -->\n\
  \n\
   <script>\n\
    function disable() {\n\
      document.getElementsByName('save')[0].disabled = true; \n\
      document.getElementsByName('up')[0].disabled = true; \n\
      document.getElementsByName('right')[0].disabled = true; \n\
      document.getElementsByName('left')[0].disabled = true; \n\
      document.getElementsByName('down')[0].disabled = true; \n\
    } \n\
    window.onload = disable;\n\
  </script>\n\
   <style type='text/css'>\n\
      body, a:hover {\n\
         cursor: url(/gam134.cur), progress !important;\n\
      }\n\
   </style>\n\
  <audio autoplay='' loop=''><source src='/Fight.mp3' type='audio/mpeg'></audio>\n\
</map-body>\n\
</html>\n\n", name, level, hp, mp, experience, ((level * level) +3), STR, MAG, VIT, DEX, AGI, x, y, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience, STR, MAG, VIT, DEX, AGI, name, level, hp,  mp, x, y, character, experience);
}

#endif /* MAP_H_ */
