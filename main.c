#include <stdio.h>
#include <windows.h>
#define LIGNES 19
#define COLONNES 37

void gotoligcol(int lig, int col) {
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}
int afficherMenu() {
    printf("\nMenu:\n");
    printf("1- Regles du jeu\n");
    printf("2- Nouvelle partie\n");
    printf("3- Charger partie deja existante\n");
    printf("4- Scores\n");
    printf("5- Quitter\n");
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
void afficherTableau(int posA[2], int posB[2]) {
    for (int i = 0; i < LIGNES; ++i) {
        for (int j = 0; j < COLONNES; ++j) {
            gotoligcol(i, j);
            if (i % 2 == 0) {
                if (j % 4 == 0) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else {
                if (j % 4 == 0) {
                    printf("|");
                } else {
                    if (i == posA[0] && j == posA[1]) {
                        printf("A");
                    } else if (i == posB[0] && j == posB[1]) {
                        printf("B");
                    } else {
                        printf(" ");
                    }
                }
            }
        }
    }
    gotoligcol(LIGNES, 0);
    printf("\n");
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
    int posA[2] = {9, 2}; //coordonnées debut partie A
    int posB[2] = {9, 34}; //coordonnées début partie B
    int a=0;

    while (choix!=5) {
        afficherMenu();
        scanf("%d", &choix);
        getchar();
        switch (choix){
            case 1:
                afficherRegle();
            printf("\n appuyez sur entrer pour revenir au menu.");
            getchar();
            system("cls");
            break;
            case 2:
                system("cls");
            afficherTableau(posA,posB);
            getchar();
            break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
                }
        }
    return 0;
    }
