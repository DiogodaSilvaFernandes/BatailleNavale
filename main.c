#include <stdio.h>
#include <windows.h>

//===============================================================//
//========================= GLOBAL VAR ==========================//
//===============================================================//

//<editor-fold desc="Global var - BLOCK">
// Declaration bateaux
int nbrPorteAvion = 1, nbrCroiseur = 1, nbrContreTorpilleur = 2, nbrTorpilleur = 1;

// Declaration du tableau de jeu
char gameBoard[11][11] = {
        {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
        {'A', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'B', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'D', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'F', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'G', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'H', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'J', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};
//</editor-fold>

//==============================================================//
//========================= FUNCTIONS ==========================//
//==============================================================//

//<editor-fold desc="Functions - BLOCK">
void gameBoard_Show(){
    // Afficher le tableau
    printf("\n        ╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╗\n");
    printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

    for (int col = 0; col < 11; ++col) {
        printf("        ║");

        for (int line = 0; line < 11; ++line) {
            if (col == 10 && line == 0) {
                printf("  10   ║");
            } else {
                printf("   %c   ║", gameBoard[line][col]);
            }
        }

        printf("\n        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

        if (col != 10) {
            printf("        ╠═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╣\n");
            printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

        } else {
            printf("        ╚═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╝\n");
        }
    }
}

void gameVerifications(int col, int line){
    // Verif si deja joué sinon, il fais les vérification
    if (gameBoard[col][line] == 'X' || gameBoard[col][line] == 'O' || gameBoard[col][line] == 'C'){
        printf("\nVous avez déjà tenté cette case !\n\n");
    }else {
        // Verif coordonnées entrée par rapport au données des bateaux

        // PORTE AVION
        if ((col == 10 && line == 6) || (col == 10 && line == 7) || (col == 10 && line == 8) ||
            (col == 10 && line == 9) || (col == 10 && line == 10)) {
            printf("\nVous avez touché le porte-avions ! Vous êtes sur la bonne voie !\n\n");
            gameBoard[col][line] = 'O';
        }

            // CROISEUR
        else if ((col == 1 && line == 1) || (col == 2 && line == 1) || (col == 3 && line == 1) ||
                 (col == 4 && line == 1)) {
            printf("\nVous avez touché le croiseur ! Vous êtes sur la bonne voie !\n\n");
            gameBoard[col][line] = 'O';
        }

            // CONTRE-TORPILLEURS
        else if (((col == 1 && line == 3) || (col == 1 && line == 4) || (col == 1 && line == 5)) ||
                 ((col == 7 && line == 7) || (col == 7 && line == 8) || (col == 7 && line == 9))) {
            printf("\nVous avez touché un des 2 contre-torpilleurs ! Vous êtes sur la bonne voie !\n\n");
            gameBoard[col][line] = 'O';
        }

            // TORPILLEUR
        else if ((col == 1 && line == 10) || (col == 2 && line == 10)) {
            printf("\nVous avez touché le torpilleur ! Vous êtes sur la bonne voie !\n\n");
            gameBoard[col][line] = 'O';
        }

            // SI RIEN TOUCHÉ
        else {
            printf("\nC'est dommage... Vous avez rien touché, mais ne vous découragez pas !\n\n");
            gameBoard[col][line] = 'X';
        }

        // Verif coordonnées entrée par rapport au données des bateaux (si toutes les coordonnées sont touchées !)

        // PORTE AVION
        if (gameBoard[10][6] == 'O' && gameBoard[10][7] == 'O' && gameBoard[10][8] == 'O' && gameBoard[10][9] == 'O' &&
            gameBoard[10][10] == 'O') {
            printf("VOUS AVEZ FAIT COULÉ LE PORTE-AVIONS ! BIEN JOUÉ !\n\n");
            gameBoard[10][6] = 'C';
            gameBoard[10][7] = 'C';
            gameBoard[10][8] = 'C';
            gameBoard[10][9] = 'C';
            gameBoard[10][10] = 'C';
            nbrPorteAvion -= 1;
        }

            // CROISEUR
        else if (gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O' && gameBoard[3][1] == 'O' && gameBoard[4][1] == 'O') {
            printf("VOUS AVEZ FAIT COULÉ LE CROISEUR ! BIEN JOUÉ !\n\n");
            gameBoard[1][1] = 'C';
            gameBoard[2][1] = 'C';
            gameBoard[3][1] = 'C';
            gameBoard[4][1] = 'C';
            nbrCroiseur -= 1;
        }

            // CONTRE-TORPILLEURS
        else if ((gameBoard[1][3] == 'O' && gameBoard[1][4] == 'O' && gameBoard[1][5] == 'O') ||
                 (gameBoard[7][7] == 'O' && gameBoard[7][8] == 'O' && gameBoard[7][9] == 'O')) {
            printf("VOUS AVEZ FAIT COULÉ UN DES CONTRE-TORPILLEURS ! BIEN JOUÉ !\n\n");

            if (gameBoard[1][3] == 'O' && gameBoard[1][4] == 'O' && gameBoard[1][5] == 'O') {
                gameBoard[1][3] = 'C';
                gameBoard[1][4] = 'C';
                gameBoard[1][5] = 'C';
            } else {
                gameBoard[7][7] = 'C';
                gameBoard[7][8] = 'C';
                gameBoard[7][9] = 'C';
            }
            nbrContreTorpilleur -= 1;
        }

            // TORPILLEUR
        else if (gameBoard[1][10] == 'O' && gameBoard[2][10] == 'O') {
            printf("VOUS AVEZ FAIT COULÉ LE TORPILLEUR ! BIEN JOUÉ !\n\n");
            gameBoard[1][10] = 'C';
            gameBoard[2][10] = 'C';
            nbrTorpilleur -= 1;
        }
    }
}
//</editor-fold>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale - V0.1");

    // Declaration de variables
    char colChoice;
    int lineChoice = 0, gameOn = 1, menuChoice = 0;

    printf("Bienvenue !\n");

    while (gameOn != 0) {


        while (menuChoice < 1 || menuChoice > 3){

            printf("\nMENU DU JEU\n"
                   "    1 - Jouer\n"
                   "    2 - Aide de Jeu\n"
                   "    3 - Quitter\n\n"
                   "Que voulez-vous faire :"
            );

            scanf("%d",&menuChoice);
        }

        switch (menuChoice) {
            case 1:
                system("cls");
                printf("Lancement de la partie ! Bonne chance !\n\n");

                // Continue la partie tant que tout les bateaux ne sont pas coulés
                do {
                    // Fonction pour afficher le tableau
                    gameBoard_Show();

                    //Vérification que la colone choisie est entre A et J
                    do {
                        printf("\n\n-> Colonne (A à J -> En majuscule):");
                        scanf("%s", &colChoice);

                        if (colChoice < 65 || colChoice > 74) {
                            printf("Vous n'avez pas choisi une lettre en A et J !\n");
                        }
                    } while (colChoice < 65 || colChoice > 74);

                    //Vérification que la ligne choisie est entre 1 et 10
                    do {
                        printf("-> Ligne (1 à 10):");
                        scanf("%d", &lineChoice);

                        if (lineChoice < 1 || lineChoice > 10) {
                            printf("Vous devez choisir que des chiffres entre 1 et 10 !\n");
                        }
                    } while (lineChoice < 1 || lineChoice > 10);

                    gameVerifications(colChoice-64,lineChoice);

                    system("PAUSE");

                    system("cls");

                } while (nbrPorteAvion > 0 || nbrCroiseur > 0 || nbrContreTorpilleur > 0 || nbrTorpilleur > 0);

                printf("BRAVO ! VOUS AVEZ GAGNÉ LA PARTIE !\n\nRetour au menu -> ");
                system("PAUSE");

                system("cls");

                menuChoice = 0;

                break;

            case 2:
                menuChoice = 0;
                system("cls");
                break;

            case 3:
                menuChoice = 0;
                gameOn = 0;
                break;

            default:
                menuChoice = 0;
                break;
        }
    }
        return 0;
}
