#include "IA.h"
#include "head.h"

void GenererCoups(hole * Plateau, int player, int * Score, TreeNode * Abr)
{
	
	hole TempPlateau[12];
	
	int a;

	for (a = 0; a < 12; a++)
	{

		TempPlateau[a] = Plateau[a];

	}

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

TreeNode * NewTree(TreeNode * Tree, int Depth, int NumCase)
{
	if (!Tree)
	{

		Tree = (TreeNode *)calloc(1 ,sizeof(TreeNode));
		Tree->gain = 0;
		Tree->NumCase = NumCase;
		Tree->injouable = 0;

	}
	int a, b;

	if (Depth > 0)
	{
		for (a = 0; a < 6; a++)
		{

			NewTree(Tree->child[a], Depth - 1, a + 1);

		}
	}

	else
	{

		return Tree;

	}
}

int IA(hole * Plateau, int * Score, int player, int IALevel)
{
	int BestChoixEver_________Maybe ;

	TreeNode * IATree = NULL;

	IATree = NewTree(NULL, IALevel, 0);

	BestChoixEver_________Maybe = IAChoix(Plateau, IATree, Score, player, IALevel);

	return BestChoixEver_________Maybe;

}

int IAChoix(hole * Plateau, TreeNode * Node, int * Score, int player, int Level)
{
	int BestChoix, jaaj;

	if (Level == 1)																		// Easy mode, made the easiest way ?
	{

		for (jaaj = 0; jaaj < 6; jaaj++)
		{


		}
	}
	return BestChoix;
}
