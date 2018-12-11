#define _CRT_SECURE_NO_WARNINGS

#include "bstree.h"

BSTree NewBSTree()
{
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	//Adds one node to the tree in its rightful place
	//Alphabetically

	if (*bst == NULL)
	{
		*bst = malloc(sizeof(Node));
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}

	if (strcmp((*bst)->word, word) > 0)
		AddNode(&(*bst)->left, word);

	else if (strcmp((*bst)->word, word) < 0)
		AddNode(&(*bst)->right, word);
}

int BSTHeight(BSTree bst)
{
	//Height of the tree

	if (bst == NULL)
		return 0;

	int heightLeft = BSTHeight(bst->left);
	int heightRight = BSTHeight(bst->right);
	int heightMax = heightLeft;
	if (heightRight > heightLeft)
		heightMax = heightRight;

	return 1 + heightMax;
}

int BSTNodeAmount(BSTree bst)
{
	//Number of nodes that the tree contains

	if (bst == NULL)
		return 0;

	return 1 + BSTNodeAmount(bst->left) + BSTNodeAmount(bst->right);
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
	//Writes tree into file
	//Pre-order walk through tree (first node, then children)
	if (bst == NULL)
		return;

	fputs(bst->word, fd);
	fputs("\n", fd);

	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	//Deletes tree (string word and point) from memory
	//Post-order walk through tree (first children, then node)
	if (bst == NULL)
		return;

	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	//Loads word by word from .txt file and adds them to the tree through AddNode() function
	//Word must be copied with strdup()
	BSTree newTree = NewBSTree();
	int c;

	while (1)
	{
		c = fgetc(fd);
		if (c == EOF)
			break;
		char *buffer = malloc (sizeof(char) * 1024);
		int i = 0;
		while (isalpha(c) || c == '\'') 
		{
			buffer[i] = tolower(c);
			i++;
			c = fgetc(fd);
			if (c == 146)
				c = '\'';
		}
		buffer[i] = '\0';
		AddNode(&newTree, _strdup(buffer));
	}
	return newTree;
}
