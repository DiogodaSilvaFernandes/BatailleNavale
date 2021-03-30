/*  Author      : Diogo da Silva Fernandes
 *  Project     : BatailleNavale
 *  Last_Update : 25/03/2021
 *  Version     : V1
 *  Description : Jeu de la Bataille Navale, développée en C pendant les modules I-CT 431 et MA-20.
 */

#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

//===============================================================//
//========================= GLOBAL VAR ==========================//
//===============================================================//

//<editor-fold desc="Global var - BLOCK">
// Declaration bateaux
int nbrPorteAvion = 5, nbrCroiseur = 4, nbrContreTorpilleur1 = 3, nbrContreTorpilleur = 3, nbrTorpilleur = 2;

// Déclaration pseudo
char username[21];
int goodUsername = 0;

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
//</editor-fold>

//==============================================================//
//========================= FUNCTIONS ==========================//
//==============================================================//

//<editor-fold desc="Functions - BLOCK">
/**
 * music est la fonction qui va permettre d'avoir une musique d'arrière plan. (Inspiré du code d'Eliott Jaquier, SI-C2b)
 * @param choiceM
 */
void music(int choiceM){
    switch (choiceM) {
        // Musique fond
        case 1:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /id start /stopbyid ./BatailleNavale_files/sounds/background.wav");
            break;

        // Effet clic
        case 2:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /id choice /stopbyid ./BatailleNavale_files/sounds/choice.wav");
            break;

        // Musique chargement
        case 3:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /id choice /stopbyid ./BatailleNavale_files/sounds/loading.wav");
            break;

        // Effet à l'eau
        case 4:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /id choice /stopbyid ./BatailleNavale_files/sounds/eau.wav");
            break;

        // Effet touché
        case 5:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /id choice /stopbyid ./BatailleNavale_files/sounds/touche.wav");
            break;

        // Effet coulé
        case 6:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /id choice /stopbyid ./BatailleNavale_files/sounds/coule.wav");
            break;

        case 8:
        default:
            system("start /min ./BatailleNavale_files/sounds/sounder.exe /stop");
            break;
    }
}

/**
 * loading est la fonction qui va permettre d'afficher un chargement.
 */
void loading(){
    // Changement de la couleur du text en bleu
    printf("\033[0;36m");
    for (int i = 0; i < 2; ++i) {
        printf("  ____  _                                                       _\n"
               " / ___|| |__    __ _  _ __  __ _   ___  _ __ ___    ___  _ __  | |_\n"
               "| |    | '_ \\  / _` || '__|/ _` | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __|\n"
               "| |___ | | | || (_| || |  | (_| ||  __/| | | | | ||  __/| | | || |_  _\n"
               " \\____||_| |_| \\__,_||_|   \\__, | \\___||_| |_| |_| \\___||_| |_| \\__|(_)\n"
               "                           |___/");
        Sleep(1000);

        system("cls");

        printf("  ____  _                                                       _\n"
               " / ___|| |__    __ _  _ __  __ _   ___  _ __ ___    ___  _ __  | |_\n"
               "| |    | '_ \\  / _` || '__|/ _` | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __|\n"
               "| |___ | | | || (_| || |  | (_| ||  __/| | | | | ||  __/| | | || |_  _  _\n"
               " \\____||_| |_| \\__,_||_|   \\__, | \\___||_| |_| |_| \\___||_| |_| \\__|(_)(_)\n"
               "                           |___/");
        Sleep(1000);

        system("cls");

        printf("  ____  _                                                       _\n"
               " / ___|| |__    __ _  _ __  __ _   ___  _ __ ___    ___  _ __  | |_\n"
               "| |    | '_ \\  / _` || '__|/ _` | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __|\n"
               "| |___ | | | || (_| || |  | (_| ||  __/| | | | | ||  __/| | | || |_  _  _  _\n"
               " \\____||_| |_| \\__,_||_|   \\__, | \\___||_| |_| |_| \\___||_| |_| \\__|(_)(_)(_)\n"
               "                           |___/");

        Sleep(1000);

        system("cls");
    }
    // Changement de la couleur du text en blanc
    printf("\033[0;37m");
}

/**
 * logsFunc est la fonction qui va permettre de créer, ouvrir et écrire dans le fichier logs.
 * @param choice : choix (1:lancement jeu/2:autres)
 * @param log : message à afficher dans les logs
 */
void logsFunc(char *log){
    FILE *logs;
    logs = fopen("logs.txt","a");

    // Permet de récupérer la date/heure
    // code tiré de https://www.codevscolor.com/c-print-current-time-day-month-year
    time_t s;
    struct tm* current_time;
    s=time(NULL);
    current_time = localtime(&s);

    fprintf(logs,"%02d:%02d:%02d - %02d/%02d/%2d     %s\n",current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_mday, current_time->tm_mon+1, current_time->tm_year+1900, log);
    fclose(logs);
}

/**
 * scoresFunc est la fonction qui va permettre, dépendant du @param choice, d'enregistrer un scores ou afficher les scores précédents.
 * @param choice : Choix (1:enregistrement/2:affichage)
 */
void scoresFunc(int choice){
    FILE *scoreEcr = fopen("BatailleNavale_files/userFiles/scores.bndds","a");
    FILE *scoreLect = fopen("BatailleNavale_files/userFiles/scores.bndds","r");

    int numLigne = 1;

    char c;

    // Permet de récupérer la date/heure
    // code tiré de https://www.codevscolor.com/c-print-current-time-day-month-year
    time_t s;
    struct tm* current_time;
    s=time(NULL);
    current_time = localtime(&s);

    switch (choice) {

        // Enregistrement d'un score
        case 1:
            fprintf(scoreEcr,"%s: %d coups, %02d/%02d/%2d-", username, nbrCoups, current_time->tm_mday, current_time->tm_mon+1, current_time->tm_year+1900);
            fclose(scoreEcr);
            break;

        // Affichage des scores
        case 2:
            system("cls");
            printf(" ____    ____  ___   ____   _____  ____\n"
                   "/ ___|  / ___|/ _ \\ |  _ \\ | ____|/ ___|\n"
                   "\\___ \\ | |   | | | || |_) ||  _|  \\___ \\\n"
                   " ___) || |___| |_| ||  _ < | |___  ___) |\n"
                   "|____/  \\____|\\___/ |_| \\_\\|_____||____/\n\n"
                   "        Les scores précédents:"
            );

            c = fgetc(scoreLect);

            // Si le premier caractère récupérer du fichier est différent de la fin du fichier, il va lire dans le fichier, sinon, il va dire qu'il y a aucun score trouvé.
            if (c != EOF) {
                printf("\n            %d) ", numLigne);

                //tant que la lecture du fichier n'est pas arrivée à la fin
                while (c != EOF) {
                    //Si elle arrive à la fin d'un score
                    if (c != '-') {
                        printf("%c", c);
                        c = fgetc(scoreLect);

                        //Sinon elle va passer à la lecture du score suivant
                    } else {
                        numLigne++;
                        c = fgetc(scoreLect);
                        if (c == EOF) {
                            break;
                        } else {
                            printf("\n            %d) ", numLigne);
                        }
                    }
                }
            }else{
                printf("\n            Aucun score trouvé !");
            }

            printf("\n\nRetour au menu -> ");
            system("Pause");
            music(2);
            numLigne = 1;
            break;

        default:
            break;
    }
}

/**
 * gameBoard_choice est la fonction qui va choisir aléatoirement une grille de jeu.
 */
void gameBoard_choice(){
    FILE *grille;

    // réinistialisation tableau bateaux
    for (int col = 0; col < 10; ++col) {
        for (int line = 0; line < 10; ++line) {
            gameBoard_boats[line][col] = ' ';
        }
    }

    // choix nombre aléatoire grille
    int grilleChoix = 1 + rand() % 5;

    switch (grilleChoix) {
        case 1:
            grille = fopen("BatailleNavale_files/maps/grille1.bndds","r");
            break;

        case 2:
            grille = fopen("/BatailleNavale_files/maps/grille2.bndds","r");
            break;

        case 3:
            grille = fopen("BatailleNavale_files/maps/grille3.bndds","r");
            break;

        case 4:
            grille = fopen("BatailleNavale_files/maps/grille4.bndds","r");
            break;

        case 5:
            grille = fopen("BatailleNavale_files/maps/grille5.bndds","r");
            break;

        default:
            break;
    }

    for (int col = 0; col < 10; ++col) {
        for (int line = 0; line < 10; ++line) {
            fscanf(grille,"%c",&gameBoard_boats[line][col]);
        }
    }
}

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
            printf("║   ");
            if (gameBoard[line][col] == 'O'){
                printf("\033[0;34m");
            }else if(gameBoard[line][col] == 'X'){
                printf("\033[0;33m");
            }else if(gameBoard[line][col] == 'C'){
                printf("\033[0;31m");
            }

            printf("%c",gameBoard[line][col]);

            printf("\033[0;37m");

            printf("   ");
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
        if (gameBoard_boats[col][line] == '2' || gameBoard_boats[col][line] == '3' || gameBoard_boats[col][line] == '4' || gameBoard_boats[col][line] == '5' || gameBoard_boats[col][line] == '6'){
            switch (gameBoard_boats[col][line]) {
                case '2':
                    nbrTorpilleur -= 1;
                    break;

                case '3':
                    nbrContreTorpilleur -= 1;
                    break;

                case '6':
                    nbrContreTorpilleur1 -= 1;
                    break;

                case '4':
                    nbrCroiseur -= 1;
                    break;

                case '5':
                    nbrPorteAvion -= 1;
                    break;

                default:
                    break;
            }

            music(5);
            gameBoard[col][line] = 'X';
            printf("\nTOUCHÉ !\n\n");
            nbrCoups++;
        }else{
            music(4);
            gameBoard[col][line] = 'O';
            printf("\nÀ L'EAU !\n\n");
            nbrCoups++;
        }

        // Verif coordonnées entrée par rapport au données des bateaux (si toutes les coordonnées sont touchées !)

        if(nbrPorteAvion == 0){
            music(6);
            for (int colv = 0; colv < 10; ++colv) {
                for (int linev = 0; linev < 10; ++linev) {
                    if (gameBoard_boats[colv][linev] == '5'){
                        gameBoard[colv][linev] = 'C';
                    }
                }
            }
            printf("\nCOULÉ !\n\n");
            nbrPorteAvion = 10;

        }else if (nbrCroiseur == 0){
            music(6);
            for (int colv = 0; colv < 10; ++colv) {
                for (int linev = 0; linev < 10; ++linev) {
                    if (gameBoard_boats[colv][linev] == '4'){
                        gameBoard[colv][linev] = 'C';
                    }
                }
            }
            printf("\nCOULÉ !\n\n");
            nbrCroiseur = 10;

        }else if (nbrContreTorpilleur == 0) {
            music(6);
            for (int colv = 0; colv < 10; ++colv) {
                for (int linev = 0; linev < 10; ++linev) {
                    if (gameBoard_boats[colv][linev] == '3'){
                        gameBoard[colv][linev] = 'C';
                    }
                }
            }
            printf("\nCOULÉ !\n\n");
            nbrContreTorpilleur = 10;

        }else if (nbrContreTorpilleur1 == 0){
            music(6);
            for (int colv = 0; colv < 10; ++colv) {
                for (int linev = 0; linev < 10; ++linev) {
                    if (gameBoard_boats[colv][linev] == '6'){
                        gameBoard[colv][linev] = 'C';
                    }
                }
            }
            printf("\nCOULÉ !\n\n");
            nbrContreTorpilleur1 = 10;

        }else if (nbrTorpilleur == 0){
            music(6);
            for (int colv = 0; colv < 10; ++colv) {
                for (int linev = 0; linev < 10; ++linev) {
                    if (gameBoard_boats[colv][linev] == '2'){
                        gameBoard[colv][linev] = 'C';
                    }
                }
            }
            printf("\nCOULÉ !\n\n");
            nbrTorpilleur = 10;
        }

    }
}

/**
 * game est la fonction qui va permettre de faire tout le déroulement du jeu.
 */
void game(){
    char colChoice, lineChoiceT[3];
    int lineChoice;

    nbrCoups = 0; nbrTorpilleur = 2; nbrContreTorpilleur = 3; nbrContreTorpilleur1 = 3; nbrCroiseur = 4; nbrPorteAvion = 5;

    // Réinitialise le tableau
    for (int col = 0; col < 10; ++col) {
        for (int ligne = 0; ligne < 10; ++ligne) {
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
    } while (nbrPorteAvion != 10 || nbrCroiseur != 10 || nbrContreTorpilleur != 10 || nbrContreTorpilleur1 != 10 || nbrTorpilleur != 10);

    printf(" ____   ____      _ __     __ ___    _  __     __ ___   _   _  ____      _ __     __ _____  _____   ____     _     ____  _   _  _____   _\n"
           "| __ ) |  _ \\    / \\\\ \\   / // _ \\  | | \\ \\   / // _ \\ | | | |/ ___|    / \\\\ \\   / /| ____||__  /  / ___|   / \\   / ___|| \\ | || ____| | |\n"
           "|  _ \\ | |_) |  / _ \\\\ \\ / /| | | | | |  \\ \\ / /| | | || | | |\\___ \\   / _ \\\\ \\ / / |  _|    / /  | |  _   / _ \\ | |  _ |  \\| ||  _|   | |\n"
           "| |_) ||  _ <  / ___ \\\\ V / | |_| | |_|   \\ V / | |_| || |_| | ___) | / ___ \\\\ V /  | |___  / /_  | |_| | / ___ \\| |_| || |\\  || |___  |_|\n"
           "|____/ |_| \\_\\/_/   \\_\\\\_/   \\___/  (_)    \\_/   \\___/  \\___/ |____/ /_/   \\_\\\\_/   |_____|/____|  \\____|/_/   \\_\\\\____||_| \\_||_____| (_)"
    );
    printf("\n\nBien joué %s !\n", username);
    printf("Nombre de tentatives: %d",nbrCoups);
    scoresFunc(1);
    printf("\n\nRetour au menu -> ");
    system("PAUSE");
    logsFunc("Fin de partie");
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
            music(2);
        }

        switch (menuChoice) {
            case 1:
                logsFunc("Affichage règles");
                system("cls");

                printf(" ____   _____  ____  _      _____  ____\n"
                       "|  _ \\ | ____|/ ___|| |    | ____|/ ___|\n"
                       "| |_) ||  _| | |  _ | |    |  _|  \\___ \\\n"
                       "|  _ < | |___| |_| || |___ | |___  ___) |\n"
                       "|_| \\_\\|_____|\\____||_____||_____||____/");

                printf("\n\n    Vous êtes face à une flotte de 5 bateaux. Celle-ci est composée d'un porte-avions (5 cases), d'un croiseur (4 cases), de deux contre-torpilleurs (2x 3 cases) et d'un torpilleur (2 cases).\n"
                       "    Vous pouvez tirer autant de fois que vous le souhaitez tant qu'il y a des bateaux adverses en vie.\n"
                       "    A chaque coup, vous devez entrer la case sur laquelle vous souhaitez tier, par exemple B2 ou H6.\n"
                       "    Trois symboles peuvent apparaitre dans une case:\n"
                       "        - O : A l'eau\n"
                       "        - X : Touché\n"
                       "        - C : Coulé\n"
                       "    Vous ne pouvez tirer qu'une seule fois par case !\n\n"
                       "Retour au menu -> "
                );
                system("PAUSE");
                music(2);
                menuChoice = 0;
                break;

            case 2:
                logsFunc("Affichage techniques");
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
                       "    La croix:\n"
                       "        Cette technique consiste à tirer sur plusieurs cases formant le dessin d'une croix.\n"
                       "        Vous avez 2 styles de croix à faire: X ou +. La croix X offre plus de chances mais fais beaucoup plus de tir."
                       "        Cette technique n'est pas la meilleure, votre score de coups sera assez élevé.\n\n"
                       "    D'autres techniques arriveront...\n\n"
                       "Retour au menu -> "
                );
                system("PAUSE");
                music(2);
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
    printf(" ____          _          _  _  _         _   _                      _                __     __ _\n"
           "| __ )   __ _ | |_  __ _ (_)| || |  ___  | \\ | |  __ _ __   __ __ _ | |  ___          \\ \\   / // |\n"
           "|  _ \\  / _` || __|/ _` || || || | / _ \\ |  \\| | / _` |\\ \\ / // _` || | / _ \\  _____   \\ \\ / / | |\n"
           "| |_) || (_| || |_| (_| || || || ||  __/ | |\\  || (_| | \\ V /| (_| || ||  __/ |_____|   \\ V /  | |\n"
           "|____/  \\__,_| \\__|\\__,_||_||_||_| \\___| |_| \\_| \\__,_|  \\_/  \\__,_||_| \\___|            \\_/   |_|"
    );

    printf("\n============================================================================================================\n"
           " __  __  _____  _   _  _   _   ____   _   _       _  _____  _   _\n"
           "|  \\/  || ____|| \\ | || | | | |  _ \\ | | | |     | || ____|| | | |\n"
           "| |\\/| ||  _|  |  \\| || | | | | | | || | | |  _  | ||  _|  | | | |\n"
           "| |  | || |___ | |\\  || |_| | | |_| || |_| | | |_| || |___ | |_| |\n"
           "|_|  |_||_____||_| \\_| \\___/  |____/  \\___/   \\___/ |_____| \\___/\n\n"
           "    1 - Jouer\n"
           "    2 - Scores\n"
           "    3 - Aide de Jeu\n"
           "    4 - Quitter\n\n"
           "Que souhaitez-vous faire :"
    );
}

/**
 * connexion est la fonction qui va permettre à l'utilisateur de se connecter avec son pseudo.
 */
void connexion(){
    do {
        system("cls");
        printf("  ____  ___   _   _  _   _  _____ __  __ ___  ___   _   _\n"
               " / ___|/ _ \\ | \\ | || \\ | || ____|\\ \\/ /|_ _|/ _ \\ | \\ | |\n"
               "| |   | | | ||  \\| ||  \\| ||  _|   \\  /  | || | | ||  \\| |\n"
               "| |___| |_| || |\\  || |\\  || |___  /  \\  | || |_| || |\\  |\n"
               " \\____|\\___/ |_| \\_||_| \\_||_____|/_/\\_\\|___|\\___/ |_| \\_|"
        );

        printf("        \n\nVotre pseudo (a-Z/0-9):");
        scanf("%s", &username);

        for (int i = 0; i < 20; ++i) {
            if (username[i] == '\00'){
                goodUsername = 1;
                break;
            }else{
                if ((username[i] < 'A' || username[i] > 'Z') && (username[i] < 'a' || username[i] > 'z') && (username[i] < '0' || username[i] > '9')){
                    // Met la couleur du texte en rouge
                    printf("\033[1;31m");
                    printf("        \nVotre pseudo ne doit contenir que des caractères entre a et z, A et Z ou 1 et 9 !\n");
                    // Reset la couleur du text
                    printf("\033[0m");
                    system("Pause");
                    break;
                }
            }
        }

    } while (goodUsername != 1);

    logsFunc("Connexion");
}
//</editor-fold>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale - V1");
    //Réinistialise la valeur de grille aléatoire
    srand( (unsigned)time( NULL ) );

    // Fonction qui permet de simuler une touche du clavier (dans notre cas, F11)
    keyboardSimulate();

    // Declaration de variables
    int gameOn = 1, menuChoice = 0;
    char menuChoiceT[3];

    // Lancement de la musique de chargement.
    music(3);
    loading();
    // Stop la musique de chargement
    music(8);

    // Lance la musique du jeu.
    music(1);
    connexion();

    while (gameOn != 0) {
        menuChoice = 0;

        system("cls");

        printMenuP();

        // Choix de l'utilisateur sur le menu principale (pris en char)
        scanf("%s",&menuChoiceT);
        // Choix en char transformé en int
        menuChoice = strtol(menuChoiceT, NULL, 10);
        music(2);

        switch (menuChoice) {
            case 1:
                logsFunc("Lancement d'une partie");
                gameBoard_choice();
                nbrCoups = 0;
                game();
                break;

            case 2:
                logsFunc("Affichage des scores");
                scoresFunc(2);
                break;

            case 3:
                logsFunc("Affichage menu aide de jeu");
                gameHelp();
                break;

            case 4:
                logsFunc("Quitte le jeu");
                music(8);
                gameOn = 0;
                break;

            default:
                break;
        }
    }
    return 0;
}