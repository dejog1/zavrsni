#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void saveGameData(const Game* game) {
    if (game == NULL) return;

    rename("rezultati.txt", "rezultati2.txt");

    FILE* file = fopen("rezultati.txt", "w");
    if (file == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    
    long currentPos = ftell(file);
    if (currentPos == -1L) {
        perror("Greska pri dobijanju pozicije u datoteci");
        fclose(file);
        return;
    }

    fprintf(file, "%s %u\n", game->player1.name, game->player1.wins);
    fprintf(file, "%s %u\n", game->player2.name, game->player2.wins);

    
    rewind(file);

    fclose(file);
    remove("rezultati2.txt");
}

void loadGameData(Game* game) {
    if (game == NULL) return;
    FILE* file = fopen("rezultati.txt", "r");
    if (file == NULL) {
        return;
    }

    rewind(file);

    if (fscanf(file, "%s %u", game->player1.name, &game->player1.wins) != 2 ||
        fscanf(file, "%s %u", game->player2.name, &game->player2.wins) != 2) {
        game->player1.name[0] = '\0';
        game->player2.name[0] = '\0';
        game->player1.wins = 0;
        game->player2.wins = 0;
    }

    fclose(file);
}

void resetGameData(Game* game) {
    if (game == NULL) return;
    game->player1.wins = 0;
    game->player2.wins = 0;
    game->player1.name[0] = '\0';
    game->player2.name[0] = '\0';
    saveGameData(game);
}
