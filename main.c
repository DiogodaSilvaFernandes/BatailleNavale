/*  Author     : Diogo da Silva Fernandes
 *  Project    : BatailleNavale_V0.1
 *  Last_Update: 09/03/2021
 */

#include <stdio.h>
#include <windows.h>
#include <ctype.h>

//===============================================================//
//========================= GLOBAL VAR ==========================//
//===============================================================//

//<editor-fold desc="Global var - BLOCK">
// Declaration bateaux
int nbrPorteAvion = 1, nbrCroiseur = 1, nbrContreTorpilleur = 2, nbrTorpilleur = 1;

//Déclaration autres variables
int nbrCoups = 0;

// Declaration du tableau de jeu
char gameBoard[10][10] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

char gameBoard_boats[10][10] = {
        {'1', ' ', '1', '1', '1', ' ', ' ', ' ', ' ', '1'},
        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1'},
        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1', '1'}
};
//</editor-fold>

//==============================================================//
//========================= FUNCTIONS ==========================//
//==============================================================//

//<editor-fold desc="Functions - BLOCK">
/**
 * gameBoard_Show est la fonction qui va permettre d'afficher le plateau du jeu.
 */
void gameBoard_Show(){
    // Afficher le tableau
    printf("\n        ╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╗\n");
    printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");
    printf("        ║       ║   A   ║   B   ║   C   ║   D   ║   E   ║   F   ║   G   ║   H   ║   I   ║   J   ║\n");
    printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

    for (int col = 0; col < 10; ++col) {
        printf("        ╠═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╣\n");
        printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

        if (col != 9) {
            printf("        ║   %d   ", col + 1);
        }else{
            printf("        ║   %d  ", col + 1);
        }

        for (int line = 0; line < 10; ++line) {
            printf("║   %c   ",gameBoard[col][line]);
        }
        printf("║\n");
        printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");
    }

    printf("        ╚═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╝\n");
}

/**
 * gameVerifications est la fonction qui va faire les vérifications des coordonnées entrées par rapport aux coordoonnées codées.
 * @param col : Colonne entrée
 * @param line : Ligne entrée
 */
void gameVerifications(int col, int line){
    // Verif si deja joué sinon, il fais les vérification
    if (gameBoard[col][line] == 'X' || gameBoard[col][line] == 'O' || gameBoard[col][line] == 'C'){
        printf("\nVous avez déjà tenté cette case !\n\n");

    }else {
        // Verif coordonnées entrée par rapport au données des bateaux

        if (gameBoard_boats[col][line] == '1'){
            gameBoard[col][line] = 'O';
            printf("\nTOUCHÉ !\n\n");
            nbrCoups++;
        }else{
            gameBoard[col][line] = 'X';
            printf("\nÀ L'EAU !\n\n");
            nbrCoups++;
        }

        // Verif coordonnées entrée par rapport au données des bateaux (si toutes les coordonnées sont touchées !)

        // PORTE AVION
        if (gameBoard[9][5] == 'O' && gameBoard[9][6] == 'O' && gameBoard[9][7] == 'O' && gameBoard[9][8] == 'O' &&
            gameBoard[9][9] == 'O') {
            printf("VOUS AVEZ FAIT COULÉ LE PORTE-AVIONS ! BIEN JOUÉ !\n\n");
            gameBoard[9][5] = 'C';
            gameBoard[9][6] = 'C';
            gameBoard[9][7] = 'C';
            gameBoard[9][8] = 'C';
            gameBoard[9][9] = 'C';
            nbrPorteAvion -= 1;
        }

            // CROISEUR
        else if (gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O' && gameBoard[3][0] == 'O') {
            printf("VOUS AVEZ FAIT COULÉ LE CROISEUR ! BIEN JOUÉ !\n\n");
            gameBoard[0][0] = 'C';
            gameBoard[1][0] = 'C';
            gameBoard[2][0] = 'C';
            gameBoard[3][0] = 'C';
            nbrCroiseur -= 1;
        }

            // CONTRE-TORPILLEURS
        else if ((gameBoard[0][2] == 'O' && gameBoard[0][3] == 'O' && gameBoard[0][4] == 'O') ||
                 (gameBoard[6][6] == 'O' && gameBoard[6][7] == 'O' && gameBoard[6][8] == 'O')) {
            printf("VOUS AVEZ FAIT COULÉ UN DES CONTRE-TORPILLEURS ! BIEN JOUÉ !\n\n");

            if (gameBoard[0][2] == 'O' && gameBoard[0][3] == 'O' && gameBoard[0][4] == 'O') {
                gameBoard[0][2] = 'C';
                gameBoard[0][3] = 'C';
                gameBoard[0][4] = 'C';
            } else {
                gameBoard[6][6] = 'C';
                gameBoard[6][7] = 'C';
                gameBoard[6][8] = 'C';
            }
            nbrContreTorpilleur -= 1;
        }

            // TORPILLEUR
        else if (gameBoard[0][9] == 'O' && gameBoard[1][9] == 'O') {
            printf("VOUS AVEZ FAIT COULÉ LE TORPILLEUR ! BIEN JOUÉ !\n\n");
            gameBoard[0][9] = 'C';
            gameBoard[1][9] = 'C';
            nbrTorpilleur -= 1;
        }
    }
}

/**
 * game est la fonction qui va permettre de faire tout le déroulement du jeu.
 */
void game(){
    char colChoice, lineChoiceT[3];
    int lineChoice;

    nbrCoups = 0;

    // Réinitialise le tableau
    for (int col = 1; col <= 10; ++col) {
        for (int ligne = 1; ligne <= 10; ++ligne) {
            gameBoard[col][ligne] = ' ';
        }
    }

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
            printf("\n\n-> Colonne (A à J -> Majuscule et Minuscule):");
            scanf("%s", &colChoice);

            if ((colChoice < 65 || colChoice > 74) && (colChoice < 97 || colChoice > 106)) {
                printf("Vous n'avez pas choisi une lettre en A et J !\n");
            }
        } while ((colChoice < 65 || colChoice > 74) && (colChoice < 97 || colChoice > 106));

        //Vérification que la ligne choisie est entre 1 et 10
        do {
            printf("-> Ligne (1 à 10):");
            scanf("%s", &lineChoiceT);

            lineChoice = strtol( lineChoiceT, NULL, 10);

            if (lineChoice < 1 || lineChoice > 10) {
                printf("Vous devez choisir que des chiffres entre 1 et 10 !\n");
            }
        } while (lineChoice < 1 || lineChoice > 10);

        if (colChoice >= 65 && colChoice <= 74) gameVerifications(colChoice-65,lineChoice-1);
        else if (colChoice >= 97 && colChoice <= 106) gameVerifications(colChoice-97,lineChoice-1);

        system("PAUSE");

        system("cls");
    } while (nbrPorteAvion > 0 || nbrCroiseur > 0 || nbrContreTorpilleur > 0 || nbrTorpilleur > 0);

    printf(" ____   ____      _ __     __ ___    _  __     __ ___   _   _  ____      _ __     __ _____  _____   ____     _     ____  _   _  _____   _\n"
           "| __ ) |  _ \\    / \\\\ \\   / // _ \\  | | \\ \\   / // _ \\ | | | |/ ___|    / \\\\ \\   / /| ____||__  /  / ___|   / \\   / ___|| \\ | || ____| | |\n"
           "|  _ \\ | |_) |  / _ \\\\ \\ / /| | | | | |  \\ \\ / /| | | || | | |\\___ \\   / _ \\\\ \\ / / |  _|    / /  | |  _   / _ \\ | |  _ |  \\| ||  _|   | |\n"
           "| |_) ||  _ <  / ___ \\\\ V / | |_| | |_|   \\ V / | |_| || |_| | ___) | / ___ \\\\ V /  | |___  / /_  | |_| | / ___ \\| |_| || |\\  || |___  |_|\n"
           "|____/ |_| \\_\\/_/   \\_\\\\_/   \\___/  (_)    \\_/   \\___/  \\___/ |____/ /_/   \\_\\\\_/   |_____|/____|  \\____|/_/   \\_\\\\____||_| \\_||_____| (_)"
           );
    printf("\n\nNombre de tentatives: %d",nbrCoups);
    printf("\n\nRetour au menu -> ");
    system("PAUSE");

    system("cls");
}

/**
 * gameHelp est la fonction qui va permettre d'afficher l'aide de jeu.
 */
void gameHelp(){
    char menuChoiceT[2];
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
            scanf("%s", &menuChoiceT);
            menuChoice = strtol( menuChoiceT, NULL, 10);
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
                       "    Vous pouvez tirer autant de fois que vous le souhaitez tant qu'il y a des bateaux adverses sont en vie.\n"
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

/**
 * keyboardSimulate est la fonction qui va simuler l'appuie d'une touche (F11).
 */
void keyboardSimulate(){
    //Fonction qui permet de mettre le cmd en plein écran (provient de https://batchloaf.wordpress.com/2012/04/17/simulating-a-keystroke-in-win32-c-or-c-using-sendinput/)
    // input event
    INPUT ip;

    // Met en place un clavier virtuel
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Simule la pression de la touche
    ip.ki.wVk = 0x7A;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    // Simule le relâchement de la touche
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

/**
 * printMenuP est la fonction qui va afficher à l'utilisateur le menu principal.
 */
void printMenuP(){
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
}
//</editor-fold>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale - V0.1");

    // Fonction qui permet de simuler une touche du clavier (dans notre cas, F11)
    keyboardSimulate();

    // Declaration de variables
    int gameOn = 1, menuChoice = 0;
    char menuChoiceT[3];

    while (gameOn != 0) {
        menuChoice = 0;
        system("cls");

        printMenuP();

        // Choix de l'utilisateur sur le menu principale (pris en char)
        scanf("%s",&menuChoiceT);
        // Choix en char transformé en int
        menuChoice = strtol(menuChoiceT, NULL, 10);

        switch (menuChoice) {
            case 1:
                nbrCoups = 0;
                game();
                break;

            case 2:
                gameHelp();
                break;

            case 3:
                gameOn = 0;
                break;

            default:
                break;
        }
    }
    return 0;
}