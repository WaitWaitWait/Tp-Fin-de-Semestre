////////////////////////////////////////
//		Project Awalé Tp Fin S1		  //
//	     		head.h				  //
//	By Valentin Monnot / Paul Marret  //
////////////////////////////////////////

#ifndef _HEAD_H_
#define _HEAD_H_


typedef struct hole_s //Structure des cases du plateau. J'ai décidé d'appeler la structure trou, car, si l’on regarde le plateau de jeu les cases sont creuse et peuvent s'apparenter a un trou
{
	
	int NbCailloux; // nombre de cailloux (C'est censé être des graines, mais lorsque l'on n’a rien pour y jouer on u ¯\_(ツ)_/¯)
	int camps; //Appartenance a un joueur
	int start; //Case de départ ?
	int previous; // Numero case précédente
	int next; // Numero case suivante

}hole;

void InitPlateau(hole * Plateau);

void AffichPlateau(hole * Plateau, int * Score);

void PlaceCailloux(int CaseDepart, hole * Plateau, int choix, int NbCailloux);

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score);

int Affamer(int player, hole * Plateau);

void Play(hole * Plateau, int player, int mode, int * Score);

#endif