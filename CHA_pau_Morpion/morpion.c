#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void affiche_grille(char grille[9]) {
	/*
	Affiche la grille
	*/
	printf("%c|%c|%c\n", grille[0], grille[1], grille[2]);
	printf("-+-+-\n");
	printf("%c|%c|%c\n", grille[3], grille[4], grille[5]);
	printf("-+-+-\n");
	printf("%c|%c|%c\n", grille[6], grille[7], grille[8]);
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
		Tour du joueur 1
		*/
		if (tour % 2 == 1) {
			do {
				printf("Joueur 1, ou voulez-vous jouer ? (cases de 1 a 9)\n");
				scanf("%d", &case_jouee);
			} while (grille[case_jouee - 1] != ' ');
			grille[case_jouee - 1] = 'X';
		}
		/*
		Tour du joueur 2
		*/
		else {
			do {
				printf("Joueur 2, ou voulez-vous jouer ? (cases de 1 a 9)\n");
				scanf("%d", &case_jouee);
			} while (grille[case_jouee - 1] != ' ');
			grille[case_jouee - 1] = 'O';
		}
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