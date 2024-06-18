#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>



#define MAX_PLAYERS 2


int comparePlayers(const void* a, const void* b) {
  
    const Player* playerA = (const Player*)a;
    const Player* playerB = (const Player*)b;

   
    return strcmp(playerA->name, playerB->name);
}

void sortPlayersByWins(Game* game) {
    if (game == NULL) return;
    Player players[MAX_PLAYERS] = { game->player1, game->player2 };
    qsort(players, MAX_PLAYERS, sizeof(Player), comparePlayers); //21., 23., 24.

    printf("Igraci sortirani po broju pobjeda:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %u pobjeda\n", players[i].name, players[i].wins);
    }
}
