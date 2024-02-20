#include "include.h"

// Fonctions pour l'ennemi
void initialize_enemy(Enemy *enemy, int x, int y) {
    enemy->x = x;
    enemy->y = y;
    enemy->health = 100;
}

void move_enemy(Enemy *enemy, int dx, int dy) {
    enemy->x += dx;
    enemy->y += dy;
}

void damage_enemy(Enemy *enemy, int damage) {
    enemy->health -= damage;
}

// Fonctions pour le joueur
void initialize_player(Player *player, int x, int y) {
    player->x = x;
    player->y = y;
    player->health = 100;
}

void move_player(Player *player, int dx, int dy) {
    player->x += dx;
    player->y += dy;
}

void damage_player(Player *player, int damage) {
    player->health -= damage;
}
