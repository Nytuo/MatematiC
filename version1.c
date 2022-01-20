//
// Created by ba101397 on 1/6/2022.
//

#include "entetesVersion1.h"
#include <stdio.h>

void version1(int grille[10][10], int largeur, int cible) {
//boucle pour parcourir la liste
    boucle1(grille, largeur, cible);

}


void boucle1(int grille[10][10], int largeur, int cible) {

    int i = 0, j = 0, brake=0;
    while (i < largeur && brake == 0) {
        while (j < largeur && brake == 0) {

            brake =cheking1(grille, i, j, largeur, cible);
            j++;
        }
        j = 0;
        i++;
    }
}


int cheking1(int grille[10][10], int y, int x, int largeur, int cible) {
    //on va droite
    if (x + 2 < largeur) {
        return testsolusion1(grille[y][x], grille[y][x + 1], grille[y][x + 2], cible);
    }
    //on va gauche
    if (x - 2 >= 0) {
        return testsolusion1(grille[y][x], grille[y][x - 1], grille[y][x - 2], cible);
    }
    //on va bas
    if (y - 2 >= 0) {
        return testsolusion1(grille[y][x], grille[y + 1][x], grille[y + 2][x], cible);
    }
    //on va haut
    if (y + 2 < largeur) {
        return testsolusion1(grille[y][x], grille[y - 1][x], grille[y - 2][x], cible);
    }
    //on va diagonale haut droite
    if (y + 2 < largeur && x + 2 < largeur) {
        return testsolusion1(grille[y][x], grille[y + 1][x + 1], grille[y + 2][x + 2], cible);
    }
    //on va diagonale haut gauche
    if (y + 2 < largeur && x - 2 >= 0) {
        return testsolusion1(grille[y][x], grille[y + 1][x - 1], grille[y + 2][x - 2], cible);
    }
    //on va diagonale bas droite
    if (y - 2 >= 0 && x + 2 < largeur) {
        return testsolusion1(grille[y][x], grille[y - 1][x + 1], grille[y - 2][x + 2], cible);
    }
    //on va diagonale bas gauche
    if (y - 2 >= 0 && x - 2 >= 0) {
        return testsolusion1(grille[y][x], grille[y - 1][x - 1], grille[y - 2][x - 2], cible);
    }
    return 0;
}

int testsolusion1(int a, int b, int c, int cible) {
    if (a * b + c == cible) {
        return fillstlusion1(a, b, c, '+', cible);
    }
    if (a * b - c == cible) {
        return fillstlusion1(a, b, c, '-', cible);
    }
    if (b * c + a == cible) {
        return fillstlusion1(b, c, a, '+', cible);
    }
    if (b * c - a == cible) {
        return fillstlusion1(b, c, a, '-', cible);
    }
    if (a * c - b == cible) {
        return fillstlusion1(a, c, b, '-', cible);
    }
    if (a * c + b == cible) {
        return fillstlusion1(a, c, b, '+', cible);
    }
    return 0;
}

int fillstlusion1(int a, int b, int c, char op, int cible) {
    printf("%d = %d x %d %c %d \n", cible,a, b, op, c);
    return 1;
}

