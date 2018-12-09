#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	BSTree newTree = malloc(sizeof(Node));
	newTree->word = "";
	newTree->left = NULL;
	newTree->right = NULL;

	return newTree;
}

void AddNode(BSTree *bst, char *word)
{
	if (*bst == NULL)
		*bst = NewBSTree();

	if ((*bst)->word == "") {
		(*bst)->word = word;
		return;
	}

	if (strcmp((*bst)->word, word) == 0)
		return;

	else if (strcmp((*bst)->word, word) > 0)
		AddNode(&(*bst)->left, word);

	else
		AddNode(&(*bst)->right, word);
}

int BSTHeight(BSTree bst)
{
	if (bst == NULL)
		return 0;

	int heightLeft = BSTHeight(bst->left);
	int heightRight = BSTHeight(bst->right);
	int heightMax = heightLeft;
	if (heightRight > heightRight)
		heightMax = heightRight;

	return 1 + heightMax;
}

int BSTUnits(BSTree bst)
{
	if (bst == NULL)
		return 0;

	return 1 + BSTUnits(bst->left) + BSTUnits(bst->right);
}

void PrintBSTree(BSTree bst)
{
	if (bst == NULL)
		return;

	PrintBSTree(bst->left);

	printf("%s\n", bst->word);

	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	

}

void DeleteBSTree(BSTree bst)
{
	//Deletes tree (string word and point) from memory
	//Post-order walk through tree (first children then point)
}

BSTree LoadBSTree(FILE *fd)
{
	//Loads word by word from .txt file and adds them to the tree through AddNode() function
	//Word must be copied with strdup()
}
