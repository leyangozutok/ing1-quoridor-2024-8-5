#include <stdio.h>
#include <windows.h>
#define LIGNES 17
#define COLONNES 17

void gotoligcol(int lig, int col) {
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}


int afficherMenu() {
    printf("\nMenu:\n");
    printf("1- Regles du jeu\n");
    printf("2- Nouvelle partie 2 joueurs\n");
    printf("3- Nouvelle partie 4 joueurs\n");
    printf("4- Charger partie deja existante\n");
    printf("5- Scores\n");
    printf("6- Quitter\n");
    printf("Choisissez une option: \n");
}
void afficherRegle() {
    printf("Regles pour jeu a 2:\n ");
    printf("But du jeu: Chaque joueur doit amener son pion de depart a la ligne opposee du plateau avant ses adversaires.\n");
    printf("Le jeu debute avec les pions de chaque joueur au centre de leur ligne de depart.\nLes joueurs recoivent 10 murs chacun et un tirage au sort determine qui commence.\n ");
    printf("A tour de role, un joueur peut deplacer son pion d'une case en avant, arriere, gauche ou droite, placer un mur pour bloquer le chemin de l'adversaire, passer son tour ou annuler le coup du jouer precedent.\n ");
    printf("Lorsqu'un des joueurs n’a plus de barrieres,celui-ci est oblige de deplacer son pion.\n ");
    printf("Attention il est interdit de fermer totalement l'acces de son adversaire a sa ligne de but: il faut toujours lui laisser une solution.\n");
    printf("Le premier joueur a atteindre une case de la ligne opposee avec son pion remporte la partie.\n ");
    printf("Attention les murs une fois poses ne peuvent plus etre deplaces,et les pions peuvent sauter par-dessus un adversaire si celui-ci se trouve directement devant lui et qu'il n'y a pas de mur bloquant le saut.\n ");
    printf("Regles pour jeu a 4:\n ");
    printf("Le jeu debute avec les 4 pions disposes au centre de chacun des 4 cotes du plateau et chaque joueur dispose de 5 barrieres.\n");
    printf("A part cela,les regles sont strictement les meme que lorsqu'on joue a 2,mais on ne peut sauter plus d'un pion a la fois");
}
int main(void) {
    char matrice[LIGNES][COLONNES] = {0};
    char lignejoueur1=8; //va servir pour quand on va vouloir placer les différents pions en début de partie
    char lignejoueur2=8;
    char lignejoueur3;
    char lignejoueur4;
    char colonnejoueur1=0;
    char colonnejoueur2=17;
    char colonnejoueur3;
    char colonnejoueur4;
    char joueur1='J';
    char joueur2='D';

    int choix=0;


    while (choix!=6) {
        afficherMenu();
        scanf("%d", &choix);
        getchar();
        switch (choix){
            case 1:
                afficherRegle();
            printf("\n Appuyez sur entrer pour revenir au menu.");
            getchar();
            break;
            case 2:
                system("cls");
            for (int i = 0; i < LIGNES; ++i) {
                for (int j = 0; j < COLONNES; ++j) {
                    matrice[i][j] = '.';
                }
            }
            // Affiche la matrice en utilisant gotoligcol
            for (int i = 0; i < LIGNES; ++i) {
                for (int j = 0; j < COLONNES; ++j) {
                    gotoligcol(i, j);
                    if (i == lignejoueur1 && j == colonnejoueur1){
                        printf("J");
                    } else {
                        printf("%c",matrice[i][j]);
                    }
                }
            }
            getchar();
            break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }

    }

    return 0;
}
