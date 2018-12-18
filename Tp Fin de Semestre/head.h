#ifndef _HEAD_H_
#define _HEAD_H_


typedef struct hole_s
{
	
	int NbCailloux;
	int camps;
	int start;
	int previous;
	int next;

}hole;

void InitPlateau(hole * Plateau);

void AffichPlateau(hole * Plateau, int * Score);

int PlaceCailloux(int CaseDepart, hole * Plateau, int choix, int NbCailloux);

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score);

void Play(hole * Plateau, int player, int * Score);

#endif;