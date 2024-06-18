#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>
#include <string.h>


int getValidatedNumber(int min, int max) {
    char buffer[100];
    int number;
    char* endptr;

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            number = strtol(buffer, &endptr, 10);
            if (*endptr == '\0' && endptr != buffer && number >= min && number <= max) {
                break;
            }
            else {
                printf("Neispravan unos. Pokusajte ponovo: ");
            }
        }
    }
    return number;
}


void displayMenu() {
    printf("1. Unos imena igraca\n");
    printf("2. Promjena imena igraca\n");
    printf("3. Igra Tic Tac Toe\n");
    printf("4. Prikaz rezultata\n");
    printf("5. Reset podataka\n");
    printf("6. Sortiranje igraca po broju pobjeda\n");
    printf("7. Pretrazivanje igraca po imenu\n");
    printf("8. Izlaz\n");
}


void getInput(int* choice) {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        char* endptr;
        *choice = strtol(buffer, &endptr, 10);
        if (*endptr != '\0' || *choice < UNOS_IMENA_IGRACA || *choice > IZLAZ) {
            *choice = -1;
        }
    }
}

void clearInputBuffer() {
    printf("Pritisnite ENTER za nastavak: \n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}