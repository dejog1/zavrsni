#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <ctype.h> 

static int isValidName(const char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return 0;
        }
    }
    return 1;
}

void getPlayerNames(Game* game) {
    if (game == NULL) return;

    char* inputBuffer = (char*)malloc(50 * sizeof(char));
    if (inputBuffer == NULL) {
        fprintf(stderr, "Nedovoljno memorije za unos imena.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Unesite ime prvog igraca (samo slova): ");
        fgets(inputBuffer, 50, stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        if (isValidName(inputBuffer)) {
            strncpy(game->player1.name, inputBuffer, sizeof(game->player1.name) - 1);
            game->player1.name[sizeof(game->player1.name) - 1] = '\0';
            break;
        }
        else {
            printf("Ime moze sadrzavati samo slova. Pokusajte ponovo.\n");
        }
    }

    while (1) {
        printf("Unesite ime drugog igraca (samo slova): ");
        fgets(inputBuffer, 50, stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        if (isValidName(inputBuffer)) {
            strncpy(game->player2.name, inputBuffer, sizeof(game->player2.name) - 1);
            game->player2.name[sizeof(game->player2.name) - 1] = '\0';
            break;
        }
        else {
            printf("Ime moze sadrzavati samo slova. Pokusajte ponovo.\n");
        }
    }

    free(inputBuffer);
}


void changePlayerNames(Game* game) {
    if (game == NULL) return;

    char* inputBuffer = (char*)malloc(50 * sizeof(char));
    if (inputBuffer == NULL) {
        fprintf(stderr, "Nedovoljno memorije za unos imena.\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(game->player1.name) == 0 && strlen(game->player2.name) == 0) {
        printf("Imena igraca jos nisu unesena. Molimo unesite imena prvo.\n");
        free(inputBuffer);
        return;
    }

    while (1) {
        printf("Unesite novo ime prvog igraca (samo slova): ");
        fgets(inputBuffer, 50, stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        if (isValidName(inputBuffer)) {
            strncpy(game->player1.name, inputBuffer, sizeof(game->player1.name) - 1);
            game->player1.name[sizeof(game->player1.name) - 1] = '\0';
            break;
        }
        else {
            printf("Ime moze sadrzavati samo slova. Pokusajte ponovo.\n");
        }
    }

    while (1) {
        printf("Unesite novo ime drugog igraca (samo slova): ");
        fgets(inputBuffer, 50, stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        if (isValidName(inputBuffer)) {
            strncpy(game->player2.name, inputBuffer, sizeof(game->player2.name) - 1);
            game->player2.name[sizeof(game->player2.name) - 1] = '\0';
            break;
        }
        else {
            printf("Ime moze sadrzavati samo slova. Pokusajte ponovo.\n");
        }
    }

    free(inputBuffer);
}
