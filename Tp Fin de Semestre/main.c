#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "head.h"



int main()
{
	int StartPlayer = rand() % 2;
	int Score[2] = { 0,0 };
	hole Plateau[12];

	hole * p_Plateau = NULL;
	int * p_Score = NULL;

	p_Plateau = Plateau;
	p_Score = Score;

	if (!p_Plateau || !p_Score)
	{

		printf("Erreur d'initialisation Pointeur");
		return EXIT_FAILURE;

	}

	InitPlateau(p_Plateau);
	AffichPlateau(p_Plateau,p_Score);
	Play(p_Plateau, StartPlayer, p_Score);


	system("PAUSE");

	return EXIT_SUCCESS;
}

