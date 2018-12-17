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

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score)
{
	
	if (Plateau[ActualCase].camps != player)
	{
		if (1 < Plateau[ActualCase].NbCailloux < 4)
		{

			Score[player] += Plateau[ActualCase].NbCailloux;
			Plateau[ActualCase].NbCailloux = 0;

		}
	}
	
	if (1 < Plateau[ActualCase - 1].NbCailloux < 4 && ActualCase != 11 || ActualCase != 0)
	{

		RecupCailloux(player, Plateau, ActualCase - 1, Score);

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

void Play(hole * Plateau, int player, int * Score)
{

	player = 1 - player;
	int choix = 0;
	
	if (choix < 1 || choix > 6)
	{
		printf("Joueur %d, choix de la case (entre 1 et 6) :\n", player + 1);
		scanf("%d", &choix);

	}


}
