//
// Created by ba101397 on 1/6/2022.
//
#include "entetesVersion2.h"
void version2(int grille[10][10], int largeur, int cible, solution *tabSolutions, int *taille) {
//boucle pour parcourir la liste
cheking(grille,3,3, largeur, cible, tabSolutions, taille);

}

void cheking(int grille[10][10],int y,int x, int position, int largeur, solution *tabSolutions, int *taille, int cible) {




    //on va droite
    if (grille[y][x]*grille[y][x+1]+grille[y][x+2]== cible) {
        tabSolutions[*taille].a = grille[y][x];
        tabSolutions[*taille].b = grille[y][x+1];
        tabSolutions[*taille].c = grille[y][x+2];
        tabSolutions[*taille].cible = cible;
    }
    //on va gauche
    if (grille[y][x]*grille[y][x-1]+grille[y][x-2]== cible) {
        tabSolutions[*taille].a = grille[y][x];
        tabSolutions[*taille].b = grille[y][x-1];
        tabSolutions[*taille].c = grille[y][x-2];
        tabSolutions[*taille].cible = cible;
    }
    //on va bas
    if (grille[y][x]*grille[y+1][x]+grille[y+2][x]== cible) {
        tabSolutions[*taille].a = grille[y][x];
        tabSolutions[*taille].b = grille[y+1][x];
        tabSolutions[*taille].c = grille[y+2][x];
        tabSolutions[*taille].cible = cible;
    }
    //on va haut
    if (grille[y][x]*grille[y-1][x]+grille[y-2][x]== cible) {
        tabSolutions[*taille].a = grille[y][x];
        tabSolutions[*taille].b = grille[y-1][x];
        tabSolutions[*taille].c = grille[y-2][x];
        tabSolutions[*taille].cible = cible;
    }






}
