#include <stdio.h>
#include "functions.h"

int main() {
    Game* game = createGame();

    int choice = 0;
    while (choice != IZLAZ) {
        displayMenu();
        printf("Odaberite opciju: ");
        getInput(&choice);
        system("cls");
        if (choice == -1) {
            printf("Neispravan unos. Pokusajte ponovo.\n");
            continue;
        }
        if ((choice != UNOS_IMENA_IGRACA && choice != IZLAZ) && (strlen(game->player1.name) == 0 || strlen(game->player2.name) == 0)) {
            printf("Morate unijeti imena igraca prvo.\n");
            continue;
        }
        switch (choice) {
        case UNOS_IMENA_IGRACA:
            if (strlen(game->player1.name) == 0 && strlen(game->player2.name) == 0) {
                getPlayerNames(game);
                saveGameData(game);
                clearInputBuffer();
                system("cls");
            }
            else {
                printf("Imena igraca su vec unesena. Promijenite ih u opciji 2.\n");
                clearInputBuffer();
                system("cls");
            }
            break;
        case PROMJENA_IMENA_IGRACA:
            changePlayerNames(game);
            saveGameData(game);
            clearInputBuffer();
            system("cls");
            break;
        case IGRA:
            playGame(game);
            clearInputBuffer();
            system("cls");
            break;
        case PRIKAZ_REZULTATA:
            displayResults(game);
            clearInputBuffer();
            system("cls");
            break;
        case RESET_PODATAKA:
            resetGameData(game);
            clearInputBuffer();
            system("cls");
            break;
        case SORTIRANJE_IGRACA_PO_BROJU_POBJEDA:
            sortPlayersByWins(game);
            clearInputBuffer();
            system("cls");
            break;
        case PRETRAGA_IGRACA_PO_IMENU:
            isPlayerFound();
            clearInputBuffer();
            system("cls");
            break;
        case IZLAZ:
            printf("Izlaz iz programa.\n");
            break;
        default:
            printf("Neispravan unos. Pokusajte ponovo.\n");
        }
    }

    destroyGame(game);
    return 0;
}
