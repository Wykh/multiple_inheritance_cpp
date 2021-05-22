#pragma once
#include "Kitchenware.h"

struct Tree
{
//private:
	Kitchenware* Data;
	int Height;
	Tree* Left;
	Tree* Right;
};
typedef Tree* PTree;

void Insert(PTree&, Kitchenware*);
void PrintHello();
void Delete(PTree&, int);
PTree Find(PTree, int);
void Balance(PTree& p);
void PrintTree(PTree, int = 0);
void DeleteTree(PTree root);
//Tree traversals
//Pre-order 
void NLR(PTree);
//In-order
void LNR(PTree);
void PrintObject(const PTree& root);
// Post-order
void LRN(PTree);