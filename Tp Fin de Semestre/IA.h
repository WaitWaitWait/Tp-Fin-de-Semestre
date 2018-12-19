#ifndef _IA_H_
#define _IA_H_
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "head.h"

typedef struct TreeNode_s
{

	int gain;
	int NumCase;
	int injouable; //si = 1 pas d enfant
	struct TreeNode * child[6];

}TreeNode;

TreeNode * NewTree(TreeNode * Tree, int Depth, int NumCase);

int IA(hole * Plateau, int * Score, int player, int IALevel);

int IAChoix(hole * Plateau, TreeNode * Node, int * Score, int player, int Level);

int Max(hole * Plateau, int Depth);
int Min(hole * Plateau, int Depth);
#endif