#include <iostream>
#include <algorithm>
#include <iomanip>
#include "BinTree.h"

using namespace std;

void NewHeight(PTree);
void PrintOblect(const PTree&);

void Insert(PTree& root, Kitchenware* x)
{
	if (root == nullptr) {
		root = new Tree;
		root->Data = x;
		root->Height = 1;
		root->Left = root->Right = nullptr;
		return;
	}

	if (x->GetNumber() < root->Data->GetNumber())
		Insert(root->Left, x);
	else if (x->GetNumber() > root->Data->GetNumber())
		Insert(root->Right, x);
	else if (x->GetNumber() == root->Data->GetNumber())
		throw "X already exists in the tree";
	NewHeight(root);
	Balance(root);
}

void PrintHello() {
	std::cout << "hello";
}

//It finds replacement in right sub tree, cut and return it
PTree FindSub(PTree& root)
{
	if (root->Left != nullptr)
		return FindSub(root->Left);
	PTree cur = root;
	root = root->Right;
	if (root != nullptr)
	{
		NewHeight(root);
		Balance(root);
	}
	return cur;
}

void Delete(PTree& root, int x)
{
	if (root == nullptr)
		return;
	if (x < root->Data->GetNumber())
		Delete(root->Left, x);
	else if (x > root->Data->GetNumber())
		Delete(root->Right, x);
	else {
		PTree toDel = root;
		if (root->Left == nullptr)
			root = root->Right;
		else if (root->Right == nullptr)
			root = root->Left;
		else
		{
			PTree sub = FindSub(root->Right);
			sub->Left = root->Left;
			sub->Right = root->Right;
			toDel = root;
			root = sub;
		}
		delete toDel->Data;
		delete toDel;
	}
	if (root != nullptr)
	{
		NewHeight(root);
		Balance(root);
	}
}

PTree Find(PTree root, int x)
{
	PTree cur = root;
	while (cur != nullptr)
		if (x < cur->Data->GetNumber())
			cur = cur->Left;
		else if (x > cur->Data->GetNumber())
			cur = cur->Right;
		else break;
	return cur;
}

int Height(PTree p)
{
	return p == nullptr ? 0 : p->Height;
}

void NewHeight(PTree p)
{
	int hl = Height(p->Left);
	int hr = Height(p->Right);
	p->Height = max(hl, hr) + 1;
}

int Say_Balance(PTree p)
{
	return Height(p->Right) - Height(p->Left);
}

void LL(PTree& p)
{
	PTree left = p->Left;
	p->Left = left->Right;
	left->Right = p;
	NewHeight(p);
	p = left;
	NewHeight(p);
}

void RR(PTree& p)
{
	PTree right = p->Right;
	p->Right = right->Left;
	right->Left = p;
	NewHeight(p);
	p = right;
	NewHeight(p);
}

void RL(PTree& p)
{
	LL(p->Right);
	RR(p);
}

void LR(PTree& p)
{
	RR(p->Left);
	LL(p);
}

void Balance(PTree& p)
{
	if (Say_Balance(p) == 2)
	{
		if (Say_Balance(p->Right) >= 0)
			RR(p);
		else
			RL(p);
	}
	else if (Say_Balance(p) == -2)
	{
		if (Say_Balance(p->Left) <= 0)
			LL(p);
		else
			LR(p);
	}
}

void PrintTree(PTree root, int level)
{
	if (root == nullptr)
		return;
	PrintTree(root->Right, level + 1);
	for (int i = 0; i < level; i++)
		cout << setw(4) << ' ';
	cout << setw(4) << left << root->Data->GetNumber() << endl;
	PrintTree(root->Left, level + 1);
}

void DeleteTree(PTree root)
{
	if (root == nullptr)
		return;
	DeleteTree(root->Left);
	DeleteTree(root->Right);
	delete root->Data;
	delete root;
}

void NLR(PTree root)
{
	if (root == nullptr)
		return;
	PrintObject(root);
	NLR(root->Left);
	NLR(root->Right);
}

void LNR(PTree root)
{
	if (root == nullptr)
		return;
	LNR(root->Left);
	PrintObject(root);
	LNR(root->Right);
}

void LRN(PTree root)
{
	if (root == nullptr)
		return;
	LRN(root->Left);
	LRN(root->Right);
	PrintObject(root);
	cout << endl;
}

void PrintObject(const PTree& root)
{
	root->Data->PrintType();
	root->Data->Print();
	cout << endl;
}
