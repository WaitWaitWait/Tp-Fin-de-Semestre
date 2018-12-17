#include <stdlib.h>
#include <stdio.h>
#include "head.h"

void InitPlateau(hole * Plateau)
{

	int a, b;

	for (a = 0; a < 12; a++)
	{

			Plateau[a].NbCailloux = 4;
			Plateau[a].start = 0;

			if (a < 6)
			{
				Plateau[a].camps = 1;
			}

			else
			{
				Plateau[a].camps = 2;
			}

	}
	return;
}

void AffichPlateau(hole * Plateau)
{

	
}
