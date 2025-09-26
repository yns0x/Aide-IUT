#include <stdio.h>

enum {TAILLE_TABLEAU = 5};

int main() {

    int Tableau_A[TAILLE_TABLEAU] = {78,75,92,95,93};

    /* Maintenant, on veut un tableau B qui est l'inverse de notre Tableau A
       Pour cela, on va d'abord créer ce nouveau tableau. */

    int Tableau_B[TAILLE_TABLEAU]; // On a initialisé un tableau B vide et on va maintenant faire une boucle for

    for (int i = 0; i < TAILLE_TABLEAU; ++i) {
        // On va faire la boucle 4 fois ici i va prendre les valeurs : 0 1 2 3 4
        // soit 5 valeurs et respectivement les indices disponibles de notre tableau A.

        Tableau_B[i] = Tableau_A[(TAILLE_TABLEAU - i) - 1];
        // Le - 1 en plus permet au début et la fin. Quand i = 0, TAILLE_TABLEAU - 0 = 5, or 5 n'est pas dans les indices de nos deux tableaux.
        // Aussi quand i = 4 soit la dernière boucle, TAILLE_TABLEAU - 4 = 1, mais 1 n'est pas notre première valeur qu'on veut ici vu
        // qu'ici, on échange un nombre du tableau avec son opposé d'indice (l'opposé de 0 est 4, celui de 1 est 3 et 2 restera à sa place, car c'est son propre opposé).
    }

    // Maintenant, on vérifie que ce que l'on a fait est bon :
    for (int i = 0; i < TAILLE_TABLEAU; ++i) {
        printf("Element %i du tableau A : %i\n", i, Tableau_A[i]);
    }

    printf("\n***************************\n\n");

    for (int i = 0; i < TAILLE_TABLEAU; ++i) {
        printf("Element %i du tableau B : %i\n", i, Tableau_B[i]);
    }

    // Dans l'exercice 3 on va maintenant voir comment échanger les valeurs directement au sein de notre Tableau A

}