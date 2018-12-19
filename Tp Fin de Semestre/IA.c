#include "IA.h"
#include "head.h"

void GenererCoups(hole * Plateau, int player, int * Score, TreeNode * Abr)
{
	
	hole TempPlateau[12] = Plateau;
	hole * p_TempPlateau = NULL;	
	p_TempPlateau = TempPlateau; 

	int CaseDepart ;
	int ActualCase = 0;
	int NbCailloux = 0;

	int TabScoreCase[6];

	int TempScore[2];
	int * p_TempScore = NULL;
	p_TempScore = TempScore;

	int tmp;
	

	if (!p_TempPlateau || !p_TempPlateau)
	{

		printf("Erreur d'initialisation Pointeur TempTab ou TempScore");
		return EXIT_FAILURE;

	}
	
	int choix, CaseMax;

	if (player == 0)
	{

		choix = 0;
		CaseMax = 6;

	}

	if (player == 1)
	{

		choix = 6;
		CaseMax = 11;

	}

	for (choix; choix < CaseMax + 1; choix++)
	{

		if (TempPlateau[choix].NbCailloux == 0)
		{

			Abr->injouable = 1;

		}
		else
		{
			
			ActualCase = choix;
			CaseDepart = choix;
			NbCailloux = TempPlateau[choix].NbCailloux;
			TempPlateau[choix].NbCailloux = 0;
			TempPlateau[choix].start = 1;
			choix = TempPlateau[choix].next;

			PlaceCailloux(CaseDepart, p_TempPlateau, choix, NbCailloux);

			int a;

			for (a = 0; a < NbCailloux; a++)
			{

				ActualCase = TempPlateau[ActualCase].next;

			}

			tmp = TempScore[player];

			RecupCailloux(player, TempPlateau, ActualCase, p_TempScore);

		}

		TabScoreCase[choix] = TempScore[player];
		
	}



}