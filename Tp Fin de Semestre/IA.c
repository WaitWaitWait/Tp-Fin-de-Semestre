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

/*
fonction cherchegain(Plateau, depth) //appel recusif pour remplir etage noeud
{

	int tab[6];

	for (i = 0; i < maxnoeud; i++)
	{

		tab[i] = gainnoeud[i];

		//apres stock tableau regarder max(val) etage 1
		//puis min val etage 2
	}

	return tab(i);
}


int Max(tab(i)) //etage 1 noeud
{

	if (Depth == 0 || Victoire(Plateau))
	{

		Eval(Plateau);

	}

	int max, i, tmp;

	max = -99999; //tres petit pour etre sur que pas d erreur

	else
	{

		for (i = 0; i < 6; i++)
		{

			tmp = parcourir tab(i);

			if (tmp > max)
			{

				max = tmp; //au finalmax est le max du tab qui regroupe le gain des noeud de l etage

			}

		}

	}

	return max;
}

int Min(tabenfant(i)) //etage suivant (joueur adverse)
{


	if (Depth == 0)
	{

		Eval(Plateau);

	}


	else //comme max mais a l inverse
	{
		int min, i, tmp;
		min = 99999;
		for (i = 0; i < 6; i++)
		{

			GenererCoups(Plateau, 0, 6, abr);

			if (Plateau < Depth - 1)
			{

				tmp = Plateau;

			}
			else
			{

				tmp = Depth - 1;

			}

			if (tmp < min)
			{

				min = tmp;

			}

		}

	}

	return min;
}

fonction seleccase()
{

	faire le calcul de gain de chaque noeud : max(noued) - min(enfant) = x // pour 2 etages
	valeur noeud = x;
	max(noeud) = case a jouer;

	return casejouée;

}

void alphabeta(noeud, alpha, beta) //alpha < beta
{
	int i, v;

	if (noeud a pas d enfants)
	{

		retourner la valeur du noeud;

	}

	if (i = 0; noeud est un Min; i++)
		{

			v = 99999;


			for (tous les fils du noeud)
			{

				v = min(v, alphabeta(fils, alpha, beta));

				if (alpha >= v) //coupure alpha
				{

					retourner v;
					beta = Min(beta, v);

				}
			}

	}


	else
	{

		v = -99999;

		for (tout fils de noeud faire)
		{

			v = max(v, alphabeta(fils, alpha, beta));

		}


		if (v >= beta)// coupure beta
		{

			retourner v;
			alpha = Max(alpha, v)

		}

	}




	return v;

}
*/

TreeNode * NewTree(TreeNode * Tree, int Depth)
{
	
	int i;

	if (!Tree)
	{

		Tree = (TreeNode *)calloc(1, sizeof(TreeNode*));
		Tree->injouable = 0;

	}

	if (Depth == 0)
	{

		for (i = 0; i < 6; i++)
		{

			Tree->child[i] = NULL;
					
		}
	}

	else
	{

		for (i = 0; i < 6; i++)
		{

			NewTree(Tree->child[i], Depth - 1);

		}
	}

	return Tree;
}

int IA(hole * Plateau, int Level)
{

	TreeNode * IATree = NULL;
	TreeNode * Child = NULL;
	IATree = NewTree(IATree, Level);

	int i, BestScore = -1, BestChoix;
	int Score[6] = { 0,0 };
	int * p_Score = NULL;
	p_Score = Score;

	for (i = 0; i < 12; i++)
	{

		*IATree->Plateau[i] = Plateau[i];

	}

	IAPlaceCailloux(IATree,p_Score);

	for (i = 0; i < 6; i++)
	{

		Child = IATree->child[i];

		if (Child->injouable != 1)
		{
			if (BestScore < Score[i])
			{

				BestScore = Score[i];
				BestChoix = i;

			}
		}
	}

	return 0;
}

void IAPlaceCailloux(TreeNode * Tree,int * ScoreTab)
{

	int CaseDepart, ActualCase, NbCailloux, i, j, k,choix;
	int Score[2];

	TreeNode * Child =NULL;
	hole * Plateau = NULL;

	for (i = 0; i < 6; i++)
	{

		Child = Tree->child[i];
		
		for (j = 0; j < 12; j++)
		{

			Child->Plateau[i] = Tree->Plateau[i];

			if (j < 2)
			{

				Score[j] = 0;

			}

		}
			
		Plateau = &Child->Plateau;
		CaseDepart = i;
		ActualCase = i;

		if (Plateau[i].NbCailloux == 0)
		{

			Child->injouable = 1;
			

		}

		else
		{
			
			NbCailloux = Plateau[i].NbCailloux;
			Plateau[i].NbCailloux = 0;
			Plateau[i].start = 1;
			choix = Plateau[i].next;

			PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);

			for (k = 0; k < NbCailloux; k++)
			{

				ActualCase = Plateau[ActualCase].next;

			}

			RecupCailloux(0, Plateau, ActualCase,Score);
			ScoreTab[i] = Score[0];

		}
	}
}
