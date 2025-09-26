#include <stdio.h>
#include <assert.h> // Toujours importer assert si besoin, car il n'est pas dans la librairie classique.
enum {TAILLE_TABLEAU = 5};

int main() {
    int Tableau_A[TAILLE_TABLEAU] = {78,75,92,95,93};
    int Tableau_B[TAILLE_TABLEAU];
    for (int i = 0; i < TAILLE_TABLEAU; ++i) {
        Tableau_B[i] = Tableau_A[TAILLE_TABLEAU - (i + 1)];
    }

                    // On a au-dessus notre tableau A et B, le tableau B nous servira dans assert (que le tableau A a bien été retourné).

    for (int i = 0; i < TAILLE_TABLEAU / 2; i++) {
                    // On fait une boucle de taille ici 5/2 (division d'entiers, il n'y a pas de décimale) = 2.
                    // On va donc faire un echange de ce style pour changer a et b:
                    // c = a
                    // a = b
                    // b = c
                    // et donc on va changer : 0 avec 4; 1 avec 3; 2 avec 2 (2 est le milieu donc normal)
                    // si on aurait la boucle de TAILLE_TABLEAU éléments, on aurait continué avec
                    // un échange de 3 avec 1; 4 avec 0 et si tu remarques avec ce que j'ai dit avant, on a
                    // retourné de nouveau le tableau soit on l'a remise à la normale, on doit donc s'arrêter
                    // à la moitié.
        int change = Tableau_A[i];
                    // ici change est notre c dans l'échange entre a et b
        Tableau_A[i] = Tableau_A[TAILLE_TABLEAU - (i + 1)];
                    // le + 1 est le même principe que le - 1 dans l'exo 2, 5 - 0 = 5 est hors du champs du tableau et
                    // 5 - 2 = 3 n'est pas la moitié (qui était 2) donc le + 1 est nécessaire (c'est intuitif si tu comprends le raisonement)
        Tableau_A[TAILLE_TABLEAU - (i + 1)] = change;

    }

                    // si tu fais
                    // assert(Tableau_A == Tableau_B);
                    // il y aura une erreur, rappelle-toi de l'exercice 1
                    // quand on appelle le tableau seul, on appelle la valeur de la mémoire RAM
                    // à laquelle elle a été attribuée/stockée (car un tableau est un pointeur,
                    // on doit donc parcourir par indice que chaque élément de A inversé correspond à
                    // element de B qui est donc send être le tableau A inversé

    for (int i = 0; i < TAILLE_TABLEAU; i++) {
        assert(Tableau_A[i] == Tableau_B[i]);
    }

                    // Tout est bon, si tu as compris passe à l'exo 4
}