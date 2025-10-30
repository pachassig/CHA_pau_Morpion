#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void affiche_grille(char grille[9]) {
	/*
	Affiche la grille
	*/
	printf("          7  |8  |9  \n");
	printf("           %c | %c | %c\n",grille[6],grille[7],grille[8]);
	printf("             |   |   \n");
	printf("          ---+---+---\n");
	printf("          4  |5  |6  \n");
	printf("           %c | %c | %c\n", grille[3], grille[4], grille[5]);
	printf("             |   |   \n");
	printf("          ---+---+---\n");
	printf("          1  |2  |3  \n");
	printf("           %c | %c | %c\n", grille[0], grille[1], grille[2]);
	printf("             |   |   \n");
}

bool est_gagne(char grille[9], char symbole) {
	/*
	Vérifie les conditions de victoire
	*/
	if (grille[0] == grille[4] && grille[0] == grille[8] && grille[0] == symbole) {
		return true;
	}
	else if (grille[0] == grille[3] && grille[0] == grille[6] && grille[0] == symbole) {
		return true;
	}
	else if (grille[0] == grille[1] && grille[0] == grille[2] && grille[0] == symbole) {
		return true;
	}
	else if (grille[1] == grille[4] && grille[1] == grille[7] && grille[1] == symbole) {
		return true;
	}
	else if (grille[2] == grille[5] && grille[2] == grille[8] && grille[2] == symbole) {
		return true;
	}
	else if (grille[2] == grille[4] && grille[2] == grille[6] && grille[2] == symbole) {
		return true;
	}
	else if (grille[3] == grille[4] && grille[3] == grille[5] && grille[3] == symbole) {
		return true;
	}
	else if (grille[6] == grille[7] && grille[6] == grille[8] && grille[6] == symbole) {
		return true;
	}
	return false;
}

bool est_complet(char grille[9]) {
	/*
	Vérifie le nul
	*/
	for (int i = 0; i < 9; i++) {
		if (grille[i] == ' ') {
			return false;
		}
	}
	return true;
}

int main() {
	char grille[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	int tour = 0;
	while (est_gagne(grille, 'X') == false && est_gagne(grille, 'O') == false && est_complet(grille) == false) {
		tour += 1;
		int case_jouee;
		affiche_grille(grille);
		/*
		Gestion du tour en fonction du joueur
		*/
		int joueur = 1;
		char joue = 'X';

		if (tour % 2 == 0) {
			joueur = 2;
			joue = 'O';
		}
		do {
			printf("Joueur %d, ou voulez-vous jouer ? (cases en fonction du pave numerique)\n", joueur);
			scanf("%d", &case_jouee);
		} while (grille[case_jouee - 1] != ' ');
		grille[case_jouee - 1] = joue;
		system("cls");
	}
	affiche_grille(grille);
	if (est_complet(grille)) {
		printf("La partie est nulle !\n");
	}
	else if (est_gagne(grille, 'X')) {
		printf("Le joueur 1 a gagne !\n");
	}
	else if (est_gagne(grille, 'O')) {
		printf("Le joueur 2 a gagne !\n");
	}

	return 0;
}