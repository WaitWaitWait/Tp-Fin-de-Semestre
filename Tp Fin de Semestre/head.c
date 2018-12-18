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

	for (a = 6; a < 11; a++)
	{

		Plateau[a].next = a + 1;

	}

	Plateau[11].next = 5;
	Plateau[0].next = 6;

	for (a = 0; a < 5; a++)
	{

		Plateau[a].previous = a + 1;

	}

	for (a = 11; a > 6; a--)
	{

		Plateau[a].previous = a - 1;

	}

	Plateau[6].previous = 0;
	Plateau[5].previous = 11;

	return;
}

void AffichPlateau(hole * Plateau, int * Score)
{

	int a;

	printf("|");

	for (a = 0; a < 6; a++)
	{

		printf(" %d |", Plateau[a].NbCailloux);

	}

	printf("     P1 : %d", Score[0]);
	printf("\n|");

	for (a = 6; a < 12; a++)
	{

		printf(" %d |", Plateau[a].NbCailloux);

	}

	printf("     P2 : %d", Score[1]);
	printf("\n");
	return;
}

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score)
{
	ActualCase = Plateau[ActualCase].previous;

	if (Plateau[ActualCase].camps != player)
	{
		if (1 < Plateau[ActualCase].NbCailloux < 4)
		{

			Score[player] += Plateau[ActualCase].NbCailloux;
			Plateau[ActualCase].NbCailloux = 0;

			RecupCailloux(player, Plateau, ActualCase, Score);

		}

	}
	
	return;

}

int PlaceCailloux(int CaseDepart, hole * Plateau, int choix, int  NbCailloux)
{

	if (NbCailloux > 0)
	{
		if (Plateau[choix].start != 1)
		{

			Plateau[choix].NbCailloux = Plateau[choix].NbCailloux + 1;
			NbCailloux--;
			choix = Plateau[choix].next;

			PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);

		}

		else
		{

			PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);

		}
	}

	Plateau[CaseDepart].start = 0;

	return choix;
}

void Play(hole * Plateau, int player, int * Score)
{

	int choix = 0;
	int NbCailloux = 0;
	int CaseDepart;
	int ActualCase;
	
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

	CaseDepart = choix;
	NbCailloux = Plateau[choix].NbCailloux;
	Plateau[choix].NbCailloux = 0;
	Plateau[choix].start = 1;
	choix = Plateau[choix].next;

	ActualCase = PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);
	AffichPlateau(Plateau, Score);

	system("PAUSE");

	RecupCailloux(player, Plateau, ActualCase, Score);
	AffichPlateau(Plateau, Score);

	Play(Plateau, 1 - player, Score);
}
