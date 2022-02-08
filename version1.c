#include "entetesVersion1.h"
#include <stdio.h>

void version1(int grille[10][10], int largeur, int cible) {
    // boucle pour parcourir la liste
    boucle1(grille, largeur, cible);
}


void boucle1(int grille[10][10], int largeur, int cible) {
    // On parcourt la grille et on appelle la fonction qui permet de tester dans les 8 axes
    int i = 0, j = 0, brake = 0;
    while (i < largeur && brake == 0) {
        while (j < largeur && brake == 0) {
            brake = AxesCheck1(grille, i, j, largeur, cible);
            j++;
        }
        j = 0;
        i++;
    }
}


int AxesCheck1(int grille[10][10], int y, int x, int largeur, int cible) {
    //on va droite
    if (x + 2 < largeur) {
        return testSolution1(grille[y][x], grille[y][x + 1], grille[y][x + 2], cible);
    }
    //on va gauche
    if (x - 2 >= 0) {
        return testSolution1(grille[y][x], grille[y][x - 1], grille[y][x - 2], cible);
    }
    //on va bas
    if (y - 2 >= 0) {
        return testSolution1(grille[y][x], grille[y + 1][x], grille[y + 2][x], cible);
    }
    //on va haut
    if (y + 2 < largeur) {
        return testSolution1(grille[y][x], grille[y - 1][x], grille[y - 2][x], cible);
    }
    //on va diagonale haut droite
    if (y + 2 < largeur && x + 2 < largeur) {
        return testSolution1(grille[y][x], grille[y + 1][x + 1], grille[y + 2][x + 2], cible);
    }
    //on va diagonale haut gauche
    if (y + 2 < largeur && x - 2 >= 0) {
        return testSolution1(grille[y][x], grille[y + 1][x - 1], grille[y + 2][x - 2], cible);
    }
    //on va diagonale bas droite
    if (y - 2 >= 0 && x + 2 < largeur) {
        return testSolution1(grille[y][x], grille[y - 1][x + 1], grille[y - 2][x + 2], cible);
    }
    //on va diagonale bas gauche
    if (y - 2 >= 0 && x - 2 >= 0) {
        return testSolution1(grille[y][x], grille[y - 1][x - 1], grille[y - 2][x - 2], cible);
    }
    return 0;
}

int testSolution1(int a, int b, int c, int cible) {
    // Vérifie toutes les solutions possible
    if (a * b + c == cible) {
        return writeSolution1(a, b, c, '+', cible);
    }
    if (a * b - c == cible) {
        return writeSolution1(a, b, c, '-', cible);
    }
    if (b * c + a == cible) {
        return writeSolution1(b, c, a, '+', cible);
    }
    if (b * c - a == cible) {
        return writeSolution1(b, c, a, '-', cible);
    }
    if (a * c - b == cible) {
        return writeSolution1(a, c, b, '-', cible);
    }
    if (a * c + b == cible) {
        return writeSolution1(a, c, b, '+', cible);
    }
    return 0;
}

int writeSolution1(int a, int b, int c, char op, int cible) {
    // Fonction qui écrit dans la console le résultat
    printf("%d = %d x %d %c %d \n", cible, a, b, op, c);
    return 1;
}