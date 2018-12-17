#define _CRT_SECURE_NO_WARNINGS
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

void PlaceCailloux(int player, hole * Plateau, int Choix, int NbCailloux)
{

	if (Choix = 0)
		{

			Choix = 6;
			Plateau[Choix].NbCailloux++;
			NbCailloux--;
			if (NbCailloux != 0)
			{
				PlaceCailloux(player, Plateau, Choix, NbCailloux);
			}

		}

	if (Choix = 11)
		{

			Choix = 5;
			Plateau[Choix].NbCailloux++;
			NbCailloux--;
			if (NbCailloux != 0)
			{
				PlaceCailloux(player, Plateau, Choix, NbCailloux);
			}

		}

	if (0 < Choix < 6)
		{

			Choix--;
			Plateau[Choix].NbCailloux++;
			NbCailloux--;
			if (NbCailloux != 0)
			{
				PlaceCailloux(player, Plateau, Choix, NbCailloux);
			}

		}

	if (5 < Choix < 11)
		{

			Choix++;
			Plateau[Choix].NbCailloux++;
			NbCailloux--;
			if (NbCailloux != 0)
			{
				PlaceCailloux(player, Plateau, Choix, NbCailloux);
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

void Play(hole * Plateau, int player, int * Score)
{
	AffichPlateau(Plateau);
	player = 1 - player;
	int choix = 0;
	
	while (choix < 1 || choix > 6)
	{
		printf("Joueur %d, choix de la case (entre 1 et 6) :\n", player + 1);
		scanf("%d", &choix);

	}

	if (player = 0)
	{

		choix--;

	}

	else
	{

		choix += 5;

	}

	int NbCailloux = Plateau[choix].NbCailloux;
	Plateau[choix].NbCailloux = 0;
	Plateau[choix].start = 1;

	PlaceCailloux(player, Plateau, choix, NbCailloux);
	Play(Plateau, player, Score);

}
