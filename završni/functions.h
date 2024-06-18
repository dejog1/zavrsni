#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    unsigned int wins;
} Player;

typedef struct {
    char board[3][3];
    Player player1;
    Player player2;
} Game;

typedef enum {
    UNOS_IMENA_IGRACA = 1,
    PROMJENA_IMENA_IGRACA,
    IGRA,
    PRIKAZ_REZULTATA,
    RESET_PODATAKA,
    SORTIRANJE_IGRACA_PO_BROJU_POBJEDA,
    PRETRAGA_IGRACA_PO_IMENU,
    IZLAZ
} MenuOption;

extern Game game;

int getValidatedNumber(int min, int max);
void initializeGame(Game* game);
Game* createGame();
void destroyGame(Game* game);
void getInput(int* choice);
void displayMenu();
void saveGameData(const Game* game);
void loadGameData(Game* game);
void getPlayerNames(Game* game);
void changePlayerNames(Game* game);
void printBoard(const char board[3][3]);
int checkWin(const char board[3][3]);
void playGame(Game* game);
void recordWin(Player* player);
void resetGameData(Game* game);
void displayResults(const Game* game);
int comparePlayers(const void* a, const void* b);
void sortPlayersByWins(Game* game);
void clearInputBuffer();
Player* findPlayerByName(const char* name, Player players[], int numPlayers);
void isPlayerFound();