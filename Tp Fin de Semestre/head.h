////////////////////////////////////////
//		Project Awalé Tp Fin S1		  //
//	     		head.h				  //
//	By Valentin Monnot / Paul Marret  //
////////////////////////////////////////

#ifndef _HEAD_H_
#define _HEAD_H_


typedef struct hole_s //Structure des cases du plateau
{
	
	int NbCailloux; // nombre de cailloux
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

void Play(hole * Plateau, int player, int * Score, int mode);

#endif;