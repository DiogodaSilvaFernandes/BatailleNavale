#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Declaration de variables
    char colChoice;
    int lineChoice = 0, colChoiceNb = 0, gameOn = 1;

    // Declaration du tableau de jeu
    char gameBoard[11][11] = {
            {' ','1','2','3','4','5','6','7','8','9','0'},
            {'A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'F',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'I',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'J',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };

    printf("Lancement de la partie ! Bonne chance !\n\n");

    // Afficher le tableau
    printf("\n        ╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╗\n");
    printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

    for (int col = 0; col < 11; ++col) {
        printf("        ║");

        for (int line = 0; line < 11; ++line) {
            if (col == 10 && line == 0){
                printf("  10   ║");
            }else{
                printf("   %c   ║",gameBoard[line][col]);
            }
        }

        printf("\n        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

        if (col != 10){
            printf("        ╠═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╬═══════╣\n");
            printf("        ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║       ║\n");

        }else{
            printf("        ╚═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╝\n");
        }
    }

    //Vérification que la colone choisie est entre A et J
    do{
        printf("\n\n-> Colonne (A à J -> En majuscule):");
        scanf("%s", &colChoice);

        if (colChoice < 65 || colChoice > 74){
            printf("Vous n'avez pas choisi une lettre en A et J !\n");
        }
    }while (colChoice < 65 || colChoice > 74);

    //Vérification que la ligne choisie est entre 1 et 10
    do{
        printf("-> Ligne (1 à 10):");
        scanf("%d", &lineChoice);

        if (lineChoice < 1 || lineChoice > 10){
            printf("Vous devez choisir que des chiffres entre 1 et 10 !\n");
        }
    }while (lineChoice < 1 || lineChoice > 10);

    // Transforme lettre en numéro entre 1 et 10
    if (colChoice == 65) {
        colChoiceNb = 1;
    } else if (colChoice == 66) {
        colChoiceNb = 2;
    } else if (colChoice == 67) {
        colChoiceNb = 3;
    } else if (colChoice == 68) {
        colChoiceNb = 4;
    } else if (colChoice == 69) {
        colChoiceNb = 5;
    } else if (colChoice == 70) {
        colChoiceNb = 6;
    } else if (colChoice == 71) {
        colChoiceNb = 7;
    } else if (colChoice == 72) {
        colChoiceNb = 8;
    } else if (colChoice == 73) {
        colChoiceNb = 9;
    } else if (colChoice == 74) {
        colChoiceNb = 10;
    }

    return 0;
}
