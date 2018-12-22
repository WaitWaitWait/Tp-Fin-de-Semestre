#ifndef _IA_H_
#define _IA_H_

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "head.h"

typedef struct TreeNode_s
{
	
	hole * Plateau[12];
	int injouable;
	struct TreeNode_s * child[6];

}TreeNode;

TreeNode * NewTree(TreeNode * Tree, int Depth);

int IA(hole * Plateau, int Level);

void IAPlaceCailloux(TreeNode * Tree, int * ScoreTab);


//int Max(hole * Plateau, int Depth);
//int Min(hole * Plateau, int Depth);
#endif