#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "head.h"

int main()
{
	int StartPlayer = rand() % 2;
	hole Plateau[12];
	hole * p_Plateau = NULL;

	p_Plateau = Plateau;

	if (!p_Plateau)
	{

		printf("Erreur d'initialisation Pointeur Plateau");
		return EXIT_FAILURE;

	}

	InitPlateau(p_Plateau);
	AffichPlateau(p_Plateau);
	Play(p_Plateau, StartPlayer);


	system("PAUSE");

	return EXIT_SUCCESS;
}