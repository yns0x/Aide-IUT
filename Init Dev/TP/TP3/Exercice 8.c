#include <stdio.h>
#include <ctype.h> // va permettre toupper (mettre les caractères en majuscules, on évite tout problèmes comme "Brahim" ou "yAssa"
#include <string.h>

enum { LONGUEUR = 50 };

int main() {
    char prenom[LONGUEUR];
    int total = 0;

    printf("Entrez votre prenom : ");
    scanf("%s", prenom);

    // On va dans une première boucle for normaliser notre prénom et faire la première somme de celui-ci.
    for (int i = 0; prenom[i] != '\0'; i++) {
        char c = toupper(prenom[i]); // comme dit dans le include là on évite tout problème et on va tout mettre en majuscule.
        if (c >= 'A' && c <= 'Z') { // toujours la vérification comme dans l'exo 7 que notre caactère est une lettre
            total += c - 'A' + 1; // encore, comme dans l'exo 7 c - 'A' permet de transfomer notre lettre en nombre de la position du caactère dans l'alphabet et +1 permettra
                                  // de faire dynamiquement le numéro de la lettre comme dans l'énoncé : A = 1, B = 2 etc... vu que vu qu'en info
                                  // on commence toujours par 0 sans le + 1 on aurait eu A = 0, B = 1 etc...
        }
    }

    // Maintenant qu'on a notre total on va sommer chaque partie du nombre afin qu'on a le nombre magique
    // Etant donné qu'on doit à la fin tomber sur un seul chiffre comme résultat vu que c'est un nombre magique,
    // il ne pourra jamais dépasser 10, on a donc notre idée de boucle, le for servira à rien ici on va initialiser le
    // i pour ne même pas l'utiliser donc on fait simplement un while
    while (total >= 10) {
        int somme = 0; // somme va stocker le résultat de notre somme des deux parties du total actuel
        while (total > 0) {
            somme += total % 10; // addition des chiffres comme dans "EVE" on a en total au début 32 ça permet de faire ici à la première itération
                                 // somme = 0 + 2 (le reste de 32 % 10) = 2
            total /= 10;        // total = 32 / 10 = 3
                               // et là, on a une succession d'opérations
                                // somme = 2 + 3 = 5
                                // total = 3 / 10 = 0
                                // là c'est rapide on a pas besoin de beaucoup d'itération vu que EVE est assez cours mais j'espère que t'as maintenant la logique

        }
        total = somme; // comme j'ai dit EVE est rapide, avec YOUNES ça aurait été BIIIEEEEENNN plus long donc le while est là pour refaire notre logique jusqu'à ce que ce soit bon
    }

    printf("Le chiffre magique de %s est : %d\n", prenom, total);

}

// Bien joué tu as fini ce TP, n'hésite pas à t'exercer si tu bloques