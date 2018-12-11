#ifndef TREE_H
#define TREE_H
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

typedef struct Node {
	char *word;
	struct Node *left, *right;
} Node;

typedef Node* BSTree;

BSTree NewBSTree();

void AddNode(BSTree *bst, char *word);

int BSTHeight(BSTree bst);

int BSTNodeAmount(BSTree bst);

void PrintBSTree(BSTree bst);

void SaveBSTree(BSTree bst, FILE *fd);

void DeleteBSTree(BSTree bst);

BSTree LoadBSTree(FILE *fd);

#endif
