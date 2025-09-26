#include <stdio.h>
#include <limits.h> // on va inclure ici la limite d'un INT qui servira pour la taille minimum
#pragma warning (disable 4996 6031)

enum { LONGUEUR_MAX = 30, NB_ETUDIANTS_MAX = 20 };
typedef struct {
    char nom[LONGUEUR_MAX];
    unsigned int taille;
} Etudiant;

// On a pris la Class de l'énoncé qui a deux éléments : taille et nom. Chaque indice aura alors deux valeurs

int main() {
    Etudiant tableau[NB_ETUDIANTS_MAX];
    // On crée un tableau de la class Etudiant (si tu as fait du python, tu peux faire un parallèle à la POO).
    // Ici un while est vraiment préférable, car pour la suite, on aura besoin de notre indice i pour savoir
    // où on a arrêté d'entrer les etudiants.
    int i = 0;
    // On va aussi initialiser les variables suivantes :
    int min = INT_MAX, max = 0; // Tout le monde peut dépasser 0cm et ne peux jamais faire 6 chiffres en taille (en cm) c'est absurde sinon
    int i_min = 0, i_max = 0;
    // ces variables vont permettre de stocker l'indice et la valeur du minimum et du maximum.
    while (i < NB_ETUDIANTS_MAX) {
        printf("Rentre le nom de l'etudiant %i : ", i + 1);
        scanf("%s", tableau[i].nom);
        printf("Rentre la taille de l'etudiant %i : ", i + 1);
        scanf("%i", &tableau[i].taille);

        if (tableau[i].taille == 0) {
            // si on veut donc arrêter, on sort de la boucle
            break;
        }

        // Ok on pose la vérification min max ici car si on le fait avant if tableau[i].taille == 0, la valeur 0 pour arrêter la saisie
        // va forcément prendre 0 en minimum

        if (tableau[i].taille < min) {
            i_min = i;
        }
        else if (tableau[i].taille > max) {
            i_max = i;
        }

        // Maintenant qu'on a notre etudiant le plus grand et le plus petit sortons de la boucle pour les afficher !

        ++i; // On incrémente i comme dans un for pour qu'il avance dans le tableau des étudiants.
    }
    // on va se servir de i_min et i_max pour afficher le nom et la taille

    printf("L'etudiant le plus petit est %s qui fait %i cm.\n",tableau[i_min].nom, tableau[i_min].taille);
    printf("L'etudiant le plus grand est %s qui fait %i cm.\n",tableau[i_max].nom, tableau[i_max].taille);

}

// Passons à l'exercice 5