#include <stdlib.h>
#include <stdio.h>
#include "head.h"

void InitPlateau(hole * Plateau)
{

	int a, b;

	for (a = 0; a < 12; a++)
	{

			Plateau[a].NbCailloux = 4;
			Plateau[a].start = 0;

			if (a < 6)
			{
				Plateau[a].camps = 1;
			}

			else
			{
				Plateau[a].camps = 2;
			}

	}
	return;
}

void recup_graines(joueur, Plateau)
{

	if (1 < Plateau[actuel] < 4)
	{
		score[joueur] += Plateau[actuel];

		while (Plateau[actuel-1])
		{
			score[joueur] += Plateau[actuel - 1];
		}
	}
	else
	{
		tour(joueur2);
	}

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
