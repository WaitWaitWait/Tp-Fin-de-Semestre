////////////////////////////////////////
//		Project Awalé Tp Fin S1		  //
//	     		head.c				  //
//	By Valentin Monnot / Paul Marret  //
////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "head.h"
#include "IA.h"

//Fonction d'initialisation Plateau
void InitPlateau(hole * Plateau)
{

	int a;

	for (a = 0; a < 12; a++)			////////////////////////////////////////////////////////////////////////////////////////////////
	{									//
										//	Remplissage de chaque case du Plateau. 
			Plateau[a].NbCailloux = 4;	//	On met 4 graines dans chaque case.
			Plateau[a].start = 0;		//	La variable permettant de savoir si l’on est
										//	partie de cette case pour placer les cailloux doit être mise à 0
			if (a < 6)					//
			{							//
				Plateau[a].camps = 0;	//	Ensuite on rentre la valeur permettant de différencier
			}							//	a qui appartient qu'elle case en fonction du numéro de 
										//	la case en question.
			else                        //
			{							//
				Plateau[a].camps = 1;	//
			}							//
										//
	}									////////////////////////////////////////////////////////////////////////////////////////////////

	for (a = 5; a > 0; a--)				////////////////////////////////////////////////////////////////////////////////////////////////
	{									//
										//	Boucle servant à remplir la variable Next 
		Plateau[a].next = a - 1;		//	Pour chaque case du tableau, on rentre le numéro de la case suivante.
										//
	}									//
										//
	for (a = 6; a < 11; a++)			//
	{									//
										//
		Plateau[a].next = a + 1;		//
										//
	}									//	Sauf pour les cases 0 et 11 qui sont des cas particuliers (changement de ligne)
										//	on rentre donc la valeur de la case suivante a la main
	Plateau[11].next = 5;				//
	Plateau[0].next = 6;				////////////////////////////////////////////////////////////////////////////////////////////////

	for (a = 0; a < 5; a++)				////////////////////////////////////////////////////////////////////////////////////////////////
	{									//
										//	Même chose que la partie précédente, mais
		Plateau[a].previous = a + 1;	//	pour le numéro de la case précédente.
										//
	}									//
										//
	for (a = 11; a > 6; a--)			//
	{									//
										//
		Plateau[a].previous = a - 1;	//
										//
	}									//
										//
	Plateau[6].previous = 0;			//
	Plateau[5].previous = 11;			////////////////////////////////////////////////////////////////////////////////////////////////

	return;
} 

//Fonction d'affichage plateau (mode console)
void AffichPlateau(hole * Plateau,int * Score)
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

//Fonction de ramassage des graines
void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score)			              	//////////////////////////////////////////////////////////////////////////////////////////////
{																						//
	int tmp, famine;																	//
																						//
	if (Plateau[ActualCase].camps != player)											//	On verifie que la case ne nous appartient pas
	{																					//
		if (Plateau[ActualCase].NbCailloux > 1 && Plateau[ActualCase].NbCailloux < 4)	//	On verifie que la case contient 2 ou 3 graines
		{																				//
																						//
			Score[player] += Plateau[ActualCase].NbCailloux;					//	Si oui, on récupère les graines dans le tableau des scores du joueur correspondant
			tmp = Plateau[ActualCase].NbCailloux;										//	On stocke l'ancienne valeur avant de vider la case
			Plateau[ActualCase].NbCailloux = 0;											//	On vide la case 
																						//
			famine = Affamer(player, Plateau);											//	On vérifie que l'on n’a pas affamé le joueur
																						//
			if (famine == 1)															//	Si c'est le cas :
			{																			//
																						//
				Plateau[ActualCase].NbCailloux = tmp;									//	On rend les graines à l'adversaire
				Score[player] -= tmp;											//	On les retire de notre score
																						//
			}																			//
																						//
			else                                                                        //	Si l'adversaire n'est pas affamé
			{																			//
																						//
				ActualCase = Plateau[ActualCase].previous;								//	On remonte d'une case
				RecupCailloux(player, Plateau, ActualCase,Score);						        //	Et l’on vérifie si l’on peut récupérer les graines de la case d'avant.
																						//
			}																			//
		}																				//
	}																					///////////////////////////////////////////////////////////////////////////////////////////
	
	return;

}

//Fonction de vérification de famine
int Affamer(int player, hole * Plateau)
{
	int famine = 0;								
	int somme = 0;								
	int a;										
												
	if (player == 0)							///////////////////////////////////////////////////////////////////////////
	{											//
												//	Dans le cas où le joueur 1 ramasse,
		for (a = 6; a < 12; a++)				//	on vérifie toutes les cases du joueur 2
		{										//
												//
			somme += Plateau[a].NbCailloux;		//	On en fait la somme 
												//
		}										//
												//
		if (somme == 0)							//	Si cette somme = 0 on affame le Joueur 2
		{										//
												//
			famine = 1;							//	On met donc la variable famine à 1 pour vrai
												//
		}										//
	}											///////////////////////////////////////////////////////////////////////////
												
	if (player == 1)							///////////////////////////////////////////////////////////////////////////
	{											//
												//	Même chose mais en inversant les rôles.
		for (a = 0; a < 6; a++)					//
		{										//
												//
			somme += Plateau[a].NbCailloux;		//
												//
		}										//
												//
		if (somme == 0)							//
		{										//
												//
			famine = 1;							//
												//
		}										//
	}											///////////////////////////////////////////////////////////////////////////
							
	return famine;

}

//Fonction d'ensemencement 
void PlaceCailloux(int CaseDepart, hole * Plateau, int choix, int  NbCailloux)
{

	if (NbCailloux > 0)														/////////////////////////////////////////////////////////////////////////////////
	{																		//	En premier, on vérifie que le nombre de cailloux à distribuer est non nul.
		if (Plateau[choix].start != 1)										//	On vérifie que la case actuelle n'est pas la case de départ 
		{																	//
																			//
			Plateau[choix].NbCailloux = Plateau[choix].NbCailloux + 1;		//	On rajoute + 1 a la case
			NbCailloux--;													//	On enlève 1 au nombre de cailloux à distribuer
			choix = Plateau[choix].next;									//	On passe a la case suivante
																			//
			PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);			//
																			//
		}																	//
																			//
		else                                                                //
		{																	//
																			//
			PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);			//	Si l’on est sur la case de départ, on passe directement à la case suivante
																			//
		}																	//
	}																		//
																			//
	Plateau[CaseDepart].start = 0;											//	A la fin, on remet la variable indiquant la case départ sur 0
																			/////////////////////////////////////////////////////////////////////////////////
	return;
}

void Play(hole * Plateau, int player, int mode, int * Score)
{

	int choix = 0;
	int NbCailloux = 0;
	int CaseDepart;
	int ActualCase;
	int a;
	
	printf("Joueur %d, choix de la case (entre 1 et 6) :\n", player + 1);
	scanf("%d", &choix);

	if (choix < 0 || choix > 6)
	{

		printf("Entre 1 et 6 stp ^-^'\n"); // ¯\_(ツ)_/¯
		Play(Plateau, player, mode,Score);

	}
	
	if (player == 0)
	{

		choix = IA(Plateau,1);

	}

	if (player == 1)
	{

		choix += 5;

	}

	if (Plateau[choix].NbCailloux == 0)
	{

		printf("Une case non vide tu dois prendre !\n"); // ¯\_(ツ)_/¯
		Play(Plateau, player, mode, Score);

	}


	CaseDepart = choix;
	ActualCase = choix;
	NbCailloux = Plateau[choix].NbCailloux;
	Plateau[choix].NbCailloux = 0;
	Plateau[choix].start = 1;
	choix = Plateau[choix].next;

	PlaceCailloux(CaseDepart, Plateau, choix, NbCailloux);
	AffichPlateau(Plateau,Score);

	system("PAUSE");

	for (a = 0; a < NbCailloux; a++)
	{

		ActualCase = Plateau[ActualCase].next;

	}

	RecupCailloux(player, Plateau, ActualCase,Score);
	AffichPlateau(Plateau,Score);

	Play(Plateau, 1 - player, mode,Score);
}
