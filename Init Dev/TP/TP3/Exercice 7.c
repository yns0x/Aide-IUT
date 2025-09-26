#include <stdio.h>
#include <string.h>
#include <assert.h>

enum { LONGUEUR = 20 };

int main() {
    char original[LONGUEUR];
    char copie[LONGUEUR];
    char crypte[LONGUEUR];
    char decrypte[LONGUEUR];
    int decalage;

    // On va donc créer plusieurs tableaux, le tableau original, celui où on va mettre notre chaine dans le terminal
    // copie, copie de l'original où on va pas faire les modifications (copie est important car on veut vérifier que
    // le message decrypté correspond à l'original).

    printf("Entrez une chaine (majuscules uniquement) : ");
    scanf("%s", original);

    printf("Entrez le decalage : ");
    scanf("%d", &decalage);

    strcpy(copie, original);  // strcpy sert à copier une chaine de caractère d'un tableau à un autre

    // Maintenant on va crypter
    int i = 0;
    while (original[i] != '\0') { // en gros la fin d'une chaine, comme dit en cours, se fini toujours par \0, il signifie la fin dde la chaine
        if (original[i] >= 'A' && original[i] <= 'Z') { // en C on peut utiliser les lettres de l'alphabet comme des nombres, on peut juste pas mélanger majuscules et minuscules
            crypte[i] = ((original[i] - 'A' + decalage) % 26) + 'A'; // là ce calcul permet le décalage. original[i] - 'A' permet de nous trouver la position de la lettre dans l'alphabet, + decalage pour faire le cryptage, %26 au cas où on arrive à Z et qu'on doit encore décaler enfin + 'A' afin dde la remettre sous forme d'alphabet
        } else {
            crypte[i] = original[i]; // caractères pas alphabétiques pas modifiés, pas de bug
        }
        i++;
    }
    crypte[i] = '\0'; // la fameuse fin de chaine

    printf("Chaine cryptee : %s\n", crypte);

    // Maintenant on décrypte, même principe que le cryptage juste le calcul est différent
    i = 0;
    while (crypte[i] != '\0') {
        if (crypte[i] >= 'A' && crypte[i] <= 'Z') {
            decrypte[i] = ((crypte[i] - 'A' - decalage + 26) % 26) + 'A'; // (crypte[i] - 'A' - decalage + 26) juste ici + 26 sert à rester dans notre alphabet et %26 encore si on va trop loin de l'alphabet
        } else {
            decrypte[i] = crypte[i];
        }
        i++;
    }
    decrypte[i] = '\0';

    printf("Chaine decryptee : %s\n", decrypte);

    // Vérification que notre chaine originale est la même que le message décrypté :
    assert(strcmp(copie, decrypte) == 0);
    printf("la chaine decryptee est identique a l'original !\n");
}

// Passons à l'exercice 8