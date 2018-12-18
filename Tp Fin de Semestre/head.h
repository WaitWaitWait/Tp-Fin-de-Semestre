#ifndef _HEAD_H_
#define _HEAD_H_


typedef struct hole_s
{
	
	int NbCailloux;
	int camps;
	int start;
	int next;

}hole;

void InitPlateau(hole * Plateau);

void AffichPlateau(hole * Plateau);

void PlaceCailloux(int player, hole * Plateau, int choix, int * NbCailloux);

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score);

void Play(hole * Plateau, int player, int * Score);

#endif;