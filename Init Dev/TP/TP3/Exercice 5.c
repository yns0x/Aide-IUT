#include <stdio.h>
#include <limits.h>
#pragma warning (disable 4996 6031)
#include <math.h> // on va utiliser fabs de cette librairie afin de trouver la moyenne

enum { LONGUEUR_MAX = 30, NB_ETUDIANTS_MAX = 20 };

typedef struct {
    char nom[LONGUEUR_MAX];
    unsigned int taille;
} Etudiant;

int main() {
    Etudiant tableau[NB_ETUDIANTS_MAX];
    int i = 0;
    int min = INT_MAX, max = 0;
    int i_min = 0, i_max = 0;
    double moyenne = 0; // on initialise la variable qui servira à la moyenne

    while (i < NB_ETUDIANTS_MAX) {
        printf("Rentre le nom de l'etudiant %i : ", i + 1);
        scanf("%s", tableau[i].nom);
        printf("Rentre la taille de l'etudiant %i : ", i + 1);
        scanf("%i", &tableau[i].taille);

        if (tableau[i].taille == 0) {
            break;
        }

        if (tableau[i].taille < min) {
            min = tableau[i].taille;
            i_min = i;
        }
        if (tableau[i].taille > max) {
            max = tableau[i].taille;
            i_max = i;
        }

        moyenne += tableau[i].taille; // on va stocker toutes les tailles pour le diviser après la boucle

        ++i; // i va maintenant aussi servir de compteur pour faire la moyenne, pratique nan ?
    }

    moyenne = moyenne / i; // et voilà, on a notre moyenne !

    // Maintenant, on va trouver l'étudiant avec a taille la plus proche de la moyenne

    int proche = 0;
    double ecart_min = fabs(tableau[0].taille - moyenne); // On considère que le premier étudiant est le plus proche de la moyenne pour commencer la boucle
    for (int j = 1; j < i; j++) {
        double ecart = fabs(tableau[j].taille - moyenne);
        if (ecart < ecart_min) { // En gros fabs(tableau[j].taille - moyenne) va retourner un résultat positif qui sera la différence entre la taille de l'étudiant et la moyenne.
            // exemple : l'etudiant fait 175cm de taille et la moyenne est de 178 : 175 - 178 = -3 or fabs transforme ce -3 en 3
            // Le but est trouver la taille le plus proche de 0 et du coup celui qui se rapproche le plus de la moyenne.
            ecart_min = ecart;
            proche = j; // proche est donc l'indice de l'étudiant le plus proche de la moyenne dans le tableau
        }
    }
    printf("La moyenne est %.1f et le plus proche est %s avec une taille de %i cm", moyenne, tableau[proche].nom, tableau[proche].taille);
}

// passons à l'exercice 6