#include <stdio.h>
#pragma warning (disable 4996 6031)
#include <string.h>

enum {LONGUEUR = 50};

int main() {
    char chaine[LONGUEUR];
    printf("Entrez une chaine : ");
    scanf("%s", chaine);
    printf("'%s'\n", chaine);
    printf("Longueur (strlen) : %zu\n", strlen(chaine));
    printf("Occupation memoire (sizeof) : %zu octets\n", sizeof(chaine));

    // Ok là, c'est le moment d'expliquer ce que le prof veut qu'on constate, le code en soit est simple, mais les executions sont bizarres
    // Quand on rentre par exemple "bonjour" on a une longueur de 7, normal vu que le max est 50.
    // Maintenant si on tape "Bonjour toi" ça nous renvois 'Bonjour' encore de longueur 7, scanf prend qu'une chaine et l'espace avec le reste est tronqué, oublié
    // Encore plus étrange, quand on rentre :
    // "ceciestunechaineassezcompacteafinquejenepuissepasetretronqueparleprogrammeetquetoutsaffichemalgrequecestvraimentddelaD" nous retourne toute la chaine
    // avec une longueur de 118 caractères. Mais attend, la limite est 50 nan ? En gros, c'est le problème que Denis nous disait qui a fait crouler un nombre
    // de grandes entreprises dans le passé : scanf n'a AUCUNE limite et donc si c'est plus grand que la limite imposée,
    // il s'en fout et déborde dans la mémoire et là tout d'un coup avec ce dépassement, on peut insérer un code qui sert à
    // voler toutes les données de l'ordinateur infecté. scanf n'a donc pas de limite et est prêt à dépasser dans la mémoire.
}