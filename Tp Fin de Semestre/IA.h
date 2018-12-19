#ifndef _IA_H_
#define _IA_H_
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "head.h"

typedef struct TreeNode_s
{

	int joueur1;
	int joueur2;
	TreeNode * child[6];

}TreeNode;

#endif;