//
// Created by ba101397 on 1/6/2022.
///
#include <stdio.h>
#include "entetesVersion2.h"

void version2(int grille[10][10], int largeur, int cible, solution *tabSolutions, int *taille) {
//boucle pour parcourir la liste
    boucle(grille, taille, largeur, tabSolutions,cible);
/*
    sort(tabSolutions, *taille);
*/
    quicksort(tabSolutions, 0,*taille-1);
    printSolution(tabSolutions, *taille);

}


void boucle(int grille[10][10], int *index, int largeur, solution *tabSolutions, int cible){
    for(int i = 0; i < largeur; i++){
        for(int j = 0; j< largeur; j++){
            cheking(grille, i, j, index, largeur, tabSolutions,cible);
        }
    }
}

//sort of structure solution
void sort(solution *tabSolutions, int taille){
    int i, j;
    solution temp;
    for(i = 0; i < taille; i++){
        for(j = i+1; j < taille; j++){
            if(tabSolutions[i].a > tabSolutions[j].a){
                temp = tabSolutions[i];
                tabSolutions[i] = tabSolutions[j];
                tabSolutions[j] = temp;
            }
        }
    }
}




void cheking(int grille[10][10], int y, int x, int *index, int largeur, solution *tabSolutions, int cible) {
    //on va droite
    if (x + 2 <= largeur) {
        testsolusion(grille[y][x] , grille[y][x + 1] , grille[y][x + 2],index, tabSolutions,  cible);
    }
    //on va gauche
    if (x - 2 >= 0) {
        testsolusion(grille[y][x] , grille[y][x - 1] , grille[y][x - 2],index, tabSolutions,  cible);
    }
    //on va bas
    if (y - 2 >= 0) {
        testsolusion(grille[y][x] , grille[y - 1][x] , grille[y - 2][x],index, tabSolutions,  cible);
    }
    //on va haut
    if (y + 2 < largeur) {
        testsolusion(grille[y][x] , grille[y + 1][x] , grille[y + 2][x],index, tabSolutions,  cible);
    }
    //on va diagonale haut gauche
    if (y + 2 < largeur && x - 2 >= 0) {
        testsolusion(grille[y][x] , grille[y + 1][x - 1] , grille[y + 2][x - 2],index, tabSolutions,  cible);
    }
    //on va diagonale bas droite
    if (y - 2 >= 0 && x + 2 < largeur) {
        testsolusion(grille[y][x] , grille[y - 1][x + 1] , grille[y - 2][x + 2],index, tabSolutions,  cible);
    }
    //on va diagonale haut droite
    if (y + 2 < largeur && x + 2 < largeur) {
        testsolusion(grille[y][x] , grille[y + 1][x + 1] , grille[y + 2][x + 2],index, tabSolutions,  cible);
    }
    //on va diagonale bas gauche
    if (y - 2 >= 0 && x - 2 >= 0) {
        testsolusion(grille[y][x] , grille[y - 1][x - 1] , grille[y - 2][x - 2],index, tabSolutions,  cible);
    }
}

void testsolusion(int a, int b, int c, int *index, solution *tabSolutions,int cible) {
    if (a * b + c == cible) {
        fillstlusion(a, b, c,'+', index, tabSolutions, cible);
    }
    if (a * b - c == cible) {
        fillstlusion(a, b, c, '-', index, tabSolutions, cible);
    }
    if (b * c + a  == cible) {
        fillstlusion(b, c, a, '+', index, tabSolutions, cible);
    }
    if (b * c - a   == cible) {
        fillstlusion(b, c, a, '-', index, tabSolutions, cible);
    }
    if (a * c + b == cible) {
        fillstlusion(a, c, b, '+', index, tabSolutions, cible);
    }
    if (a * c - b == cible) {
        fillstlusion(a, c, b, '-', index, tabSolutions, cible);
    }

}
void fillstlusion(int a, int b, int c,char op, int *index, solution *tabSolutions, int cible){
    tabSolutions[*index].a = a;
    tabSolutions[*index].b = b;
    tabSolutions[*index].c = c;
    tabSolutions[*index].cible = cible;
    tabSolutions[*index].op = op;
    *index = *index + 1;
}

void printSolution(solution *tabSolutions, int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        printf("%d x %d %c %d = %d\n", tabSolutions[i].a, tabSolutions[i].b, tabSolutions[i].op, tabSolutions[i].c, tabSolutions[i].cible);
    }
}

//make a quick sort for a struct
void quicksort(solution *tabSolutions, int debut, int fin) {
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


