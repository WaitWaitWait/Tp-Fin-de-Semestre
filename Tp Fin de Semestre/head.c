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

	for (a = 5; a > 0; a--)
	{

		Plateau[a].next = a - 1;

	}

	Plateau[0].next = 6;

	for (a = 6; a < 11; a++)
	{

		Plateau[a].next = a + 1;

	}

	Plateau[11].next = 5;

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

void PlaceCailloux(int player, hole * Plateau, int choix, int  NbCailloux)
{

	if (NbCailloux > 0)
	{
		if (Plateau[choix].start != 1)
		{

			Plateau[choix].NbCailloux++;
			NbCailloux--;
			choix = Plateau[choix].next;

			PlaceCailloux(player, Plateau, choix, NbCailloux);

		}

		else
		{

			PlaceCailloux(player, Plateau, choix, NbCailloux);

		}
	}

	return;
}

void Play(hole * Plateau, int player, int * Score)
{

	int choix = 0;
	int NbCailloux = 0;
	
	printf("Joueur %d, choix de la case (entre 1 et 6) :\n", player + 1);
	scanf("%d", &choix);

	if (choix < 0 || choix > 6)
	{

		printf("Entre 1 et 6 stp ^-^'\n"); // ¯\_(ツ)_/¯
		Play(Plateau, player, Score);
	}

	
	if (player == 0)
	{

		choix--;

	}

	if (player == 1)
	{

		choix += 5;

	}

	NbCailloux = Plateau[choix].NbCailloux;
	Plateau[choix].NbCailloux = 0;
	Plateau[choix].start = 1;
	choix = Plateau[choix].next;

	PlaceCailloux(player, Plateau, choix, NbCailloux);
	AffichPlateau(Plateau);
	Play(Plateau, 1 - player, Score);
}
