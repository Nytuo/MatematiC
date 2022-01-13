
typedef struct
{
    int     a ;
    int     b ;
    int     c ;
    int     cible ;
    char    op ;       /// vaut '+' ou '-'
} solution ;


void version2 (int grille [10][10], int largeur, int cible, solution tabSolutions [], int *taille);

void cheking(int grille[10][10], int y, int x, int *index, int largeur, solution *tabSolutions, int cible);

        void printSolution(solution *tabSolutions, int taille);

void fillstlusion(int a, int b, int c,char op, int *index, solution *tabSolutions, int cible);

void testsolusion(int a, int b, int c, int *index, solution *tabSolutions,int cible);

void boucle(int grille[10][10], int *index, int largeur, solution *tabSolutions, int cible);

void sort(solution *tabSolutions, int taille);
void quicksort(solution *tabSolutions, int debut, int fin);