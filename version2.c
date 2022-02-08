#include <stdio.h>
#include "entetesVersion2.h"

void version2(int grille[10][10], int largeur, int cible, solution *tabSolutions, int *taille) {
    //boucle pour parcourir la liste
    boucle(grille, taille, largeur, tabSolutions,cible);
    //Trie par QUICKSORT
    quicksort(tabSolutions, 0,*taille-1);
    // Affichage des solutions
    writeSolution(tabSolutions, *taille);

}


void boucle(int grille[10][10], int *index, int largeur, solution *tabSolutions, int cible){
    // On parcourt la grille et on appelle la fonction qui permet de tester dans les 8 axes
    for(int i = 0; i < largeur; i++){
        for(int j = 0; j< largeur; j++){
            AxesCheck(grille, i, j, index, largeur, tabSolutions, cible);
        }
    }
}


void AxesCheck(int grille[10][10], int y, int x, int *index, int largeur, solution *tabSolutions, int cible) {
    //on va droite
    if (x + 2 < largeur) {
        testSolution(grille[y][x], grille[y][x + 1], grille[y][x + 2], index, tabSolutions, cible);
    }
    //on va gauche
    if (x - 2 >= 0) {
        testSolution(grille[y][x], grille[y][x - 1], grille[y][x - 2], index, tabSolutions, cible);
    }
    //on va bas
    if (y - 2 >= 0) {
        testSolution(grille[y][x], grille[y - 1][x], grille[y - 2][x], index, tabSolutions, cible);
    }
    //on va haut
    if (y + 2 < largeur) {
        testSolution(grille[y][x], grille[y + 1][x], grille[y + 2][x], index, tabSolutions, cible);
    }
    //on va diagonale haut gauche
    if (y + 2 < largeur && x - 2 >= 0) {
        testSolution(grille[y][x], grille[y + 1][x - 1], grille[y + 2][x - 2], index, tabSolutions, cible);
    }
    //on va diagonale bas droite
    if (y - 2 >= 0 && x + 2 < largeur) {
        testSolution(grille[y][x], grille[y - 1][x + 1], grille[y - 2][x + 2], index, tabSolutions, cible);
    }
    //on va diagonale haut droite
    if (y + 2 < largeur && x + 2 < largeur) {
        testSolution(grille[y][x], grille[y + 1][x + 1], grille[y + 2][x + 2], index, tabSolutions, cible);
    }
    //on va diagonale bas gauche
    if (y - 2 >= 0 && x - 2 >= 0) {
        testSolution(grille[y][x], grille[y - 1][x - 1], grille[y - 2][x - 2], index, tabSolutions, cible);
    }
}

void testSolution(int a, int b, int c, int *index, solution *tabSolutions, int cible) {
    // Teste toutes les solutions si vrai alors demande de stockage
    if (a * b + c == cible) {
        stockSolution(a, b, c, '+', index, tabSolutions, cible);
    }
    if (a * b - c == cible) {
        stockSolution(a, b, c, '-', index, tabSolutions, cible);
    }
    if (b * c + a  == cible) {
        stockSolution(b, c, a, '+', index, tabSolutions, cible);
    }
    if (b * c - a   == cible) {
        stockSolution(b, c, a, '-', index, tabSolutions, cible);
    }
    if (a * c + b == cible) {
        stockSolution(a, c, b, '+', index, tabSolutions, cible);
    }
    if (a * c - b == cible) {
        stockSolution(a, c, b, '-', index, tabSolutions, cible);
    }

}
void stockSolution(int a, int b, int c, char op, int *index, solution *tabSolutions, int cible){
    // stock la soltuion dans la liste
    tabSolutions[*index].a = a;
    tabSolutions[*index].b = b;
    tabSolutions[*index].c = c;
    tabSolutions[*index].cible = cible;
    tabSolutions[*index].op = op;
    *index = *index + 1;
}

void writeSolution(solution *tabSolutions, int taille) {
    // Ecrit les solution dals la console
    int i;
    for (i = 0; i < taille; i++) {
        printf("%d x %d %c %d = %d\n", tabSolutions[i].a, tabSolutions[i].b, tabSolutions[i].op, tabSolutions[i].c, tabSolutions[i].cible);
    }
}

void quicksort(solution *tabSolutions, int debut, int fin) {
    // Le quicksort pour trie rapidement la liste
    int i, j, pivot;
    solution temp;
    if (debut < fin) {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j) {
            while (tabSolutions[i].a < tabSolutions[pivot].a) {
                i++;
            }
            while (tabSolutions[j].a > tabSolutions[pivot].a) {
                j--;
            }
            if (i <= j) {
                temp = tabSolutions[i];
                tabSolutions[i] = tabSolutions[j];
                tabSolutions[j] = temp;
                i++;
                j--;
            }
        }
        quicksort(tabSolutions, debut, j);
        quicksort(tabSolutions, i, fin);
    }
}


