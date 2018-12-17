#ifndef _HEAD_H_
#define _HEAD_H_


typedef struct hole_s
{
	
	int NbCailloux;
	int camps;
	int start;

}hole;

void InitPlateau(hole * Plateau);

void AffichPlateau(hole * Plateau);

void Play(hole * Plateau, int player, int * Score);

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score);

#endif;