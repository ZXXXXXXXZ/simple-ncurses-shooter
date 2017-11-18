#include "player_setup.h"
#include <ncurses.h>
#include <stdlib.h>

/* Function: player_setup():
 * uses malloc to allocate size for type Enemy
 * because type Player has no set size like int 
 * for example./ prints player at x,y position.
 *
 * RETURN: pointer type Player so player can
 * be created.
 */
Player * player_setup(){
  
  Player * player = malloc(sizeof(Player));

  player->x_position = 60;
  player->y_position = 40;
  player->mov_speed = 1;
  player->health = 100;
  player->projectile.px_position = 0;
  player->projectile.py_position = 0;
  player->projectile.speed = 10;
  
  mvprintw(player->x_position,player->y_position, "P");
  move(player->x_position, player->y_position);
  
  return(player);
}

/*Function: player_move():
 *gets Player x_position,y_position and updates them
 *by x,y variables. then moves cursor to the new pos(x,y);
 */
void player_move(Player * player, int x, int y){
  mvprintw(player->x_position,player->y_position," ");
  player->x_position += x;
  player->y_position += y;
  mvprintw(player->x_position,player->y_position, "P");
  move(player->x_position, player->y_position);
} 

/*Function: player_pro_shoot():
 *tells the bullet how far its allowed to go without 
 *dissapearing.gets Player(x,y) and starts that bullet at
 *that position(x+1,y), then proceeds to update the bullet 
 *position to shoot it.
 */
void  player_pro_shoot(Player * player){
  int pro_range = 10;
  PRO * bullet = &player->projectile;
  bullet->px_position = player->x_position+1;
  bullet->py_position = player->y_position; 

  bullet->py_position += bullet->speed; 
  mvprintw(bullet->px_position,bullet->py_position,"+");
 
  /*sets pos(x,y) back to player so it can be shot again*/
  bullet->px_position = player->x_position+1;
  bullet->py_position = player->y_position;
  move(player->x_position, player->y_position);
    
}

/*Function: player_damage():
 *gets enemy projectile position
 *if enemy projectile pos(x,y) is the same as
 *player pos(x,y) and player health is not 0
 *health -= 20 otherwise it will return 1 which
 *will stop the game.
 */
int player_damage(Player * player, Player * enemy){
  if(enemy->projectile.px_position == player->x_position 
     && enemy->projectile.px_position == player->x_position){
      if(player->health){
        player->health -= 20;
        return(0); 
      }else{
        return(1);
      }
   }
}

void player_border(Player * player, int x, int y){
  if(player->x_position >= x){
    player->x_position -= 1;
    player_move(player, player->x_position, player->y_position);
  }else if(player->x_position <= x-(x-1)){
    player->x_position +=1;
    player_move(player, player->x_position, player->y_position);
  }else if(player->y_position >= y){
    player->y_position -= 1;
    player_move(player, player->x_position, player->y_position);
  }else if(player->y_position <= y-(y-1)){
    player->y_position +=1;
    player_move(player, player->x_position, player->y_position);
  }
}
void controls(Player * player, char input){
    switch(input){
      case'w':
      case'W':
        player_move(player, -(player->mov_speed), 0);
        break;
      case'a':    
      case'A':
       player_move(player, 0, -(player->mov_speed));
       break;
      case's':
      case'S':
       player_move(player, player->mov_speed, 0);
       break;
      case'd':
      case'D':
       player_move(player, 0 ,player->mov_speed);
       break;
      case'p':
       player_pro_shoot(player);
       
      default: break;
    };
  
}




