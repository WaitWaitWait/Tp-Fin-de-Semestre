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

void PlaceCailloux(int CaseDepart, hole * Plateau, int choix, int NbCailloux);

void RecupCailloux(int player, hole * Plateau, int ActualCase, int * Score);

int Affamer(int player, hole * Plateau);

void Play(hole * Plateau, int player, int * Score);

#endif;