#ifndef PLAYER_SETUP_
#define PLAYER_SETUP_

typedef struct{
  int px_position;
  int py_position;
  int speed;
}PRO;
 
typedef struct{
  int x_position;
  int y_position;
  int mov_speed;
  int health;
  PRO projectile;

}Player;


Player * player_setup();
int player_damage(Player * player, Player * enemy);
void player_move(Player * player,int x, int y);
void player_border(Player * player, int x, int y);
void player_pro_shoot(Player * player);


void controls(Player * player,char input);
#endif



