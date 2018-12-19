////////////////////////////////////////
//		Project Awalé Tp Fin S1		  //
//	     		main.c				  //
//	By Valentin Monnot / Paul Marret  //
////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "head.h"
#include "_SDL.h"
#include "SDL.h"

int main()
{
	int mode = 0;

	while (mode < 1 || mode > 2)
	{

		printf("Option de lancement :\n1 - Mode Graphique\n2 - Mode Console\n? : ");
		scanf("%d", &mode);

	}

	int StartPlayer = 0; // Choix du joueur qui commence
	int Score[2] = { 0,0 }; // Tableau des scores
	hole Plateau[12]; //Plateau de jeu (Tableau de cases)

	hole * p_Plateau = NULL; 
	int * p_Score = NULL;

	p_Plateau = Plateau;
	p_Score = Score;

	if (!p_Plateau || !p_Score) // Sécuriter init pointeur
	{

		printf("Erreur d'initialisation Pointeur");
		return EXIT_FAILURE;

	}

	InitPlateau(p_Plateau);

	if (mode == 1)
	{


	}

	else
	{

		AffichPlateau(p_Plateau, p_Score);

	}

	Play(p_Plateau, StartPlayer, p_Score, mode);

	system("PAUSE");

	return EXIT_SUCCESS;
}

