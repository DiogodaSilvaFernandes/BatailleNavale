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

void game(){
    char colChoice;
    int lineChoice;

    system("cls");
    printf(" ____                                ____  _                                _\n"
           "| __ )   ___   _ __   _ __    ___   / ___|| |__    __ _  _ __    ___  ___  | |\n"
           "|  _ \\  / _ \\ | '_ \\ | '_ \\  / _ \\ | |    | '_ \\  / _` || '_ \\  / __|/ _ \\ | |\n"
           "| |_) || (_) || | | || | | ||  __/ | |___ | | | || (_| || | | || (__|  __/ |_|\n"
           "|____/  \\___/ |_| |_||_| |_| \\___|  \\____||_| |_| \\__,_||_| |_| \\___|\\___| (_)\n\n");

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
}

void gameHelp(){
    int menuChoice = 0;

    while (menuChoice != 3) {
        while (menuChoice < 1 || menuChoice > 3) {
            system("cls");

            printf("    _     ___  ____   _____   ____   _____       _  _____  _   _\n"
                   "   / \\   |_ _||  _ \\ | ____| |  _ \\ | ____|     | || ____|| | | |\n"
                   "  / _ \\   | | | | | ||  _|   | | | ||  _|    _  | ||  _|  | | | |\n"
                   " / ___ \\  | | | |_| || |___  | |_| || |___  | |_| || |___ | |_| |\n"
                   "/_/   \\_\\|___||____/ |_____| |____/ |_____|  \\___/ |_____| \\___/\n\n");

            printf("Que souhaitez-vous connaitre ?\n"
                   "    1 - Règles\n"
                   "    2 - Techniques de jeu\n"
                   "    3 - Revenir au menu principal\n"
                   "->"
            );
            scanf("%d", &menuChoice);
        }

        switch (menuChoice) {
            case 1:
                system("cls");

                printf(" ____   _____  ____  _      _____  ____\n"
                       "|  _ \\ | ____|/ ___|| |    | ____|/ ___|\n"
                       "| |_) ||  _| | |  _ | |    |  _|  \\___ \\\n"
                       "|  _ < | |___| |_| || |___ | |___  ___) |\n"
                       "|_| \\_\\|_____|\\____||_____||_____||____/");

                printf("\n\n    Vous êtes face à une flotte de 5 bateaux. Celle-ci est composée d'un porte-avions (5 cases), d'un croiseur (4 cases), de deux contre-torpilleurs (2x 3 cases) et d'un torpilleur (2 cases).\n"
                       "    Vous pouvez tirer autant de fois que vous le souhaitez tant que tout les bateaux adverses sont en vie.\n"
                       "    A chaque coup, vous devez entrer la case sur laquelle vous souhaitez tier, par exemple B2 ou H6.\n"
                       "    Trois symboles peuvent apparaitre dans une case:\n"
                       "        - X : A l'eau\n"
                       "        - O : Touché\n"
                       "        - C : Coulé\n"
                       "    Vous ne pouvez que tirer qu'une seule fois par case !\n\n"
                       "Retour au menu -> "
                );
                system("PAUSE");
                menuChoice = 0;
                break;

            case 2:
                system("cls");

                printf(" _____  _____  ____  _   _  _   _  ___  ___   _   _  _____  ____\n"
                       "|_   _|| ____|/ ___|| | | || \\ | ||_ _|/ _ \\ | | | || ____|/ ___|\n"
                       "  | |  |  _| | |    | |_| ||  \\| | | || | | || | | ||  _|  \\___ \\\n"
                       "  | |  | |___| |___ |  _  || |\\  | | || |_| || |_| || |___  ___) |\n"
                       "  |_|  |_____|\\____||_| |_||_| \\_||___|\\__\\_\\ \\___/ |_____||____/\n\n");

                printf("    Chasse/Cible:\n"
                       "        Elle consiste à viser aléatoirement une case jusqu'à toucher un bateau.\n"
                       "        Une fois touché, vous devez vous acharner sur les cases aux alentours jusqu'à couler le bateau.\n"
                       "        Dès le bateau coulé, on recommence !\n\n"
                       "    D'autres techniques arriveront...\n\n"
                       "Retour au menu -> "
                );
                system("PAUSE");
                menuChoice = 0;

                break;

            default:
                break;
        }
    }
}
//</editor-fold>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale - V0.1");

    //Commande pour mettre le cmd en plein écran (provient de https://codes-sources.commentcamarche.net/forum/affich-371867-plein-ecran-c-console)
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);

    // Declaration de variables
    int gameOn = 1, menuChoice = 0, test = 0;

    while (gameOn != 0) {

        system("cls");
        printf(" ____          _          _  _  _         _   _                      _                  __     __ ___     _\n"
               "| __ )   __ _ | |_  __ _ (_)| || |  ___  | \\ | |  __ _ __   __ __ _ | |  ___            \\ \\   / // _ \\   / |\n"
               "|  _ \\  / _` || __|/ _` || || || | / _ \\ |  \\| | / _` |\\ \\ / // _` || | / _ \\    _____   \\ \\ / /| | | |  | |\n"
               "| |_) || (_| || |_| (_| || || || ||  __/ | |\\  || (_| | \\ V /| (_| || ||  __/   |_____|   \\ V / | |_| |_ | |\n"
               "|____/  \\__,_| \\__|\\__,_||_||_||_| \\___| |_| \\_| \\__,_|  \\_/  \\__,_||_| \\___|              \\_/   \\___/(_)|_|\n"
        );

        printf("\n============================================================================================================\n"
               " __  __  _____  _   _  _   _   ____   _   _       _  _____  _   _\n"
               "|  \\/  || ____|| \\ | || | | | |  _ \\ | | | |     | || ____|| | | |\n"
               "| |\\/| ||  _|  |  \\| || | | | | | | || | | |  _  | ||  _|  | | | |\n"
               "| |  | || |___ | |\\  || |_| | | |_| || |_| | | |_| || |___ | |_| |\n"
               "|_|  |_||_____||_| \\_| \\___/  |____/  \\___/   \\___/ |_____| \\___/\n\n"
               "    1 - Jouer\n"
               "    2 - Aide de Jeu\n"
               "    3 - Quitter\n\n"
               "Que souhaitez-vous faire :"
        );

        scanf("%d",&menuChoice);

        switch (menuChoice) {
            case 1:
                game();
                menuChoice = 0;
                break;
            case 2:
                gameHelp();
                menuChoice = 0;
                break;

            case 3:
                gameOn = 0;
                break;

            default:
                menuChoice = 0;
                break;
        }
    }
    return 0;
}
