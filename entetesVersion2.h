
typedef struct
{
    int     a ;
    int     b ;
    int     c ;
    int     cible ;
    char    op ;       /// vaut '+' ou '-'
} solution ;


void version2 (int grille [10][10], int largeur, int cible, solution tabSolutions [], int *taille);

void cheking(int grille[10][10],int y,int x, int position, int largeur, solution *tabSolutions, int *taille, int cible);

