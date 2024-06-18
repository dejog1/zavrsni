#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Game game;

void initializeGame(Game* game) {
    if (game == NULL) return;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game->board[i][j] = ' ';
        }
    }
    game->player1.name[0] = '\0';
    game->player2.name[0] = '\0';
    game->player1.wins = 0;
    game->player2.wins = 0;
    loadGameData(game);
}

Game* createGame() {
    Game* game = (Game*)malloc(sizeof(Game));
    if (game == NULL) {
        fprintf(stderr, "Nedovoljno memorije za kreiranje igre.\n");
        exit(EXIT_FAILURE);
    }
    initializeGame(game);
    return game;
}

void destroyGame(Game* game) {
    if (game != NULL) {
        free(game);
        game = NULL;
    }
}

void printBoard(const char board[3][3]) {
    if (board == NULL) return;
    system("cls");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(const char board[3][3]) {
    if (board == NULL) return 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == 'X' ? 1 : 2;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i] == 'X' ? 1 : 2;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == 'X' ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == 'X' ? 1 : 2;
    }
    return 0;
}

void playGame(Game* game) {
    if (game == NULL) return;
    if (strlen(game->player1.name) == 0 || strlen(game->player2.name) == 0) {
        printf("Imena igraca jos nisu unesena. Molimo unesite imena prvo.\n");
        return;
    }
    int currentPlayer = 1;
    int moves = 0;
    int winner = 0;

    for (int i = 0; i < 3; i++) {
        memset(game->board[i], ' ', 3 * sizeof(char));
    }

    while (moves < 9 && winner == 0) {
        printBoard(game->board);
        int row, col;

        printf("Na redu je %s ( %c )\n", currentPlayer == 1 ? game->player1.name : game->player2.name, currentPlayer == 1 ? 'X' : 'O');
        printf("Unesite broj reda (1-3): ");
        row = getValidatedNumber(1, 3) - 1;
        printf("Unesite broj stupca (1-3): ");
        col = getValidatedNumber(1, 3) - 1;

        if (game->board[row][col] == ' ') {
            game->board[row][col] = currentPlayer == 1 ? 'X' : 'O';
            currentPlayer = currentPlayer == 1 ? 2 : 1;
            moves++;
            winner = checkWin(game->board);
        }
        else {
            printf("Polje je vec zauzeto. Pokusajte ponovo.\n");
        }
    }

    printBoard(game->board);
    if (winner == 1) {
        printf("Pobjednik je %s!\n", game->player1.name);
        recordWin(&game->player1);
    }
    else if (winner == 2) {
        printf("Pobjednik je %s!\n", game->player2.name);
        recordWin(&game->player2);
    }
    else {
        printf("Nerijeseno!\n");
    }

    saveGameData(game);
}

void recordWin(Player* player) {
    if (player == NULL) return;
    player->wins++;
}

void displayResults(const Game* game) {
    if (game == NULL) return;
    printf("Rezultati:\n");
    printf("%s: %u pobjeda\n", game->player1.name, game->player1.wins);
    printf("%s: %u pobjeda\n", game->player2.name, game->player2.wins);
}

Player* findPlayerByName(const char* name, Player players[], int numPlayers) {
    Player key;
    strcpy(key.name, name);

  
    qsort(players, numPlayers, sizeof(Player), comparePlayers);

    
    Player* foundPlayer = (Player*)bsearch(&key, players, numPlayers, sizeof(Player), comparePlayers);

    return foundPlayer;
}

void isPlayerFound() {
    char searchName[50];
    printf("Unesite ime igraca za pretragu: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    Player* foundPlayer = findPlayerByName(searchName, (Player[]) { game.player1, game.player2 }, 2);
    if (foundPlayer != NULL) {
        printf("Pronadjen igrac: %s, broj pobjeda: %u\n", foundPlayer->name, foundPlayer->wins);
    }
    else {
        printf("Nije pronadjen igrac sa imenom: %s\n", searchName);
    }
}