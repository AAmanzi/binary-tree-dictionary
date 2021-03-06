#define _CRT_SECURE_NO_WARNINGS

#include "bstree.h"

int readWord(FILE *fd, char *buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
}

void main()
{
	int wc;
	FILE *fd;
	char buffer[1024];
	BSTree bst;
	bst = NewBSTree();

	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	wc = 0;
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		AddNode(&bst, _strdup(buffer));
		wc++;
	}

	fclose(fd);

	PrintBSTree(bst);
	int height = BSTHeight(bst);
	int sizeOfBSTree = BSTNodeAmount(bst);
	printf("\nHeight: %d\nWords in file: %d\nWords in binary tree: %d\n", height, wc, sizeOfBSTree);

	if ((fd = fopen("BSTree.txt", "wt")) == NULL)
	{
		printf("Error opening file for writing.\n");
		return;
	}
	SaveBSTree(bst, fd);
	fclose(fd);
	DeleteBSTree(bst);

	// Load tree
	
	if ((fd = fopen("BSTree.txt", "rt")) == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}
	bst = LoadBSTree(fd);
	fclose(fd);

	printf("\nH = %d\n", BSTHeight(bst));
	DeleteBSTree(bst);

	system("pause");
}