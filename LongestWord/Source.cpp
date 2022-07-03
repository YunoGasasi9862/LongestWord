#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Trie.h"

int main(void)
{
	Trienode* root = GetTrieNode(NULL);
	char words[][7] = { "a","banana","app","appl","ap","apply","apple" };
	int size = ARRAY_SIZE(words);
	for (int i = 0; i < size; i++)
	{
		Insert(root, words[i]);
	}

	//search
	int max = 0;
	int score = 0;
	for (int i = 1; i < size; i++)
	{
	 score = search(root, words[i], &max);
	}
	return 0;
}