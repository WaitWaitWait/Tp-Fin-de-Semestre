#ifndef _HEAD_H_
#define _HEAD_H_

typedef struct hole_s
{
	
	int NbCailloux;
	int camps;
	int start;

}hole;

typedef struct score_s
{

	int P1;
	int P2;

}score;

void InitPlateau(hole * Plateau);

void AffichPlateau(hole * Plateau);

void Play(hole * Plateau, int player);

#endif 

