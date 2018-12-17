#include <stdlib.h>
#include <stdio.h>
#include "head.h"

void InitPlateau(hole * Plateau)
{

	int a;

	for (a = 0; a < 12; a++)
	{

			Plateau[a].NbCailloux = 4;
			Plateau[a].start = 0;

			if (a < 6)
			{
				Plateau[a].camps = 0;
			}

			else
			{
				Plateau[a].camps = 1;
			}

	}
	return;
}

void AffichPlateau(hole * Plateau)
{

	int a;

	printf("|");

	for (a = 0; a < 6; a++)
	{

		printf(" %d |", Plateau[a].NbCailloux);

	}

	printf("\n|");

	for (a = 6; a < 12; a++)
	{

		printf(" %d |", Plateau[a].NbCailloux);

	}

	printf("\n");
	return;
}

void Play(hole * Plateau, int player)
{

	player = 1 - player;
	int choix = 0;
	
	if (choix < 1 || choix > 6)
	{
		printf("Joueur %d+1, choix de la case (entre 1 et 6) :\n");
		scanf("%d", &choix);

	}


}
