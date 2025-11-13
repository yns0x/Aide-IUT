#include <stdio.h>
#include <string.h>

enum {TAILLE = 11};

typedef struct {
	int bombe[TAILLE][TAILLE];
	int masque[TAILLE][TAILLE];
} Terrain;


void permutation(Terrain *p, int i, int j) {

}

void initialisation(Terrain* p) {
	for (int ligne = 0; ligne < TAILLE; ++ligne) {
		for (int colonne = 0; colonne < TAILLE; ++colonne) {
			p->masque[ligne][colonne] = 1;
			p->bombe[ligne][colonne] = 0;
		}
	}
	/*for (int i = 0; i < TAILLE; ++i) {
		int j = rand() % i + 1
	}*/
}

void afficher(Terrain p) {
	for (int ligne = 0; ligne < TAILLE; ++ligne)
		printf("%3d", ligne);
	printf("\n");
	for (int ligne = 0; ligne < TAILLE; ++ligne) {
		printf("%3d", ligne);
		for (int colonne = 0; colonne < TAILLE; ++colonne) {
				printf(p.masque[ligne][colonne] == 1 ? " . " : "   ");
		}
		printf("\n");
	}
}

int main() {
	Terrain partie = { 0 };
	initialisation(&partie);
	afficher(partie);
}
