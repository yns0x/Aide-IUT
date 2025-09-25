#include <stdio.h> // on inclut la librairie par défaut (je vais vraiment sur-commenter à mort).

enum {TAILLE_TABLEAU = 5}; // On crée une variable constante (non-modifiable) utilisable partout dans le code.

int main() {
    int Tableau_Entiers[TAILLE_TABLEAU] = {78,75,92,95,93};
    /* Grâce à notre constante, on crée un tableau d'entiers et, comme demande l'énoncé, on met déjà les valeurs.
     Faire print Tableau_Entiers n'est pas bon, on peut le faire comme ceci. */
    printf("%p\n",Tableau_Entiers);
    /* Problème les tableaux en C sont des pointeurs (pas encore vu en cours)
     et donc là, on affiche la valeur de la mémoire en RAM dont le tableau a été affecté.
     Pour voir les valeurs, on doit faire une boucle par indice : */
    for (int i = 0; i < TAILLE_TABLEAU; ++i) {
        /* C'est là que notre constante devient important
            Pour des parcours dans un tableau, on a besoin de savoir sa longueur
            A moins que tu as fait "Tableau_Entiers[7] = ..." par exemple, mais là 7 est un nombre dur, pénalisant.
            On va donc parcourir ici TAILLE_TABLEAU éléments (ici 5) soit 0,1,2,3,4 puis 5 ne sera pas pris,
            car 5 < 5 est faux dans le for sinon on aurait parcouru 6 élements */
        printf("Element %i : %i\n", i, Tableau_Entiers[i]);
    }

    printf("**************************************\n");

    // je fais la même avec while pour ceux qui préfèrent, mais l'explication est la même
    int i = 0;
    while (i < TAILLE_TABLEAU) {
        printf("Element %i : %i\n", i, Tableau_Entiers[i]);
        ++i;
    }

}