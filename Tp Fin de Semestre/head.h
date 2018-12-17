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

void recup_graines(int joueur, hole * Plateau, int case_actuelle);
#endif 

