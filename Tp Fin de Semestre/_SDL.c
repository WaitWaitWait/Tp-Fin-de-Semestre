////////////////////////////////////////
//		Project Awalé Tp Fin S1		  //
//	     		_SDL.h				  //
//	By Valentin Monnot / Paul Marret  //
////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "_SDL.h"
#include "SDL.h"

Config LectureConfig()
{
	Config cfg;

	FILE *pFichier = NULL;
	pFichier = fopen("cfg.txt", "r");

	if (!pFichier)
	{

		printf("Pas de fichier de configuration.\nCréation de cfg.txt avec les paramètres par défaut.\n");

		pFichier = fopen("cfg.txt", "w");

		if (!pFichier)
		{

			printf("Erreur lors de la création de cfg.txt\nLa modification des paramètres ne sera pas enregistrée");

			cfg.Size_X = 1280;
			cfg.Size_Y = 720;
			cfg.Advantage_P1 = 0;
			cfg.Advantage_P2 = 0;
			cfg.IaLevel = 2;
			cfg.Mode = 2;
			cfg.Music_State = 1;
			cfg.StartPlayer = 0;

		}

		else
		{

			fprintf(pFichier, "Size_X : 1280\n");
			fprintf(pFichier, "Size_Y : 720\n");
			fprintf(pFichier, "Advantage_P1 : 0\n");
			fprintf(pFichier, "Advantage_P2 : 0\n");
			fprintf(pFichier, "IaLevel : 2\n");
			fprintf(pFichier, "Mode : 2\n");
			fprintf(pFichier, "Music_State = 1\n");
			fprintf(pFichier, "StartPlayer = 0\n");
			fclose(pFichier);

			printf("Fichier de configuration créé avec succès !\n");

			cfg.Size_X = 1280;
			cfg.Size_Y = 720;
			cfg.Advantage_P1 = 0;
			cfg.Advantage_P2 = 0;
			cfg.IaLevel = 2;
			cfg.Mode = 2;
			cfg.Music_State = 1;
			cfg.StartPlayer = 0;

		}

	}

	else
	{


	}
	return cfg;
}
