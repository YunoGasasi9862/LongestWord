#pragma once
#define CHAR_TO_INT(c) (int(c)- (int)'a')
#define ALPHABET_SIZE 25
#define ARRAY_SIZE(c) sizeof(c)/sizeof(c[0])

typedef char TType;
typedef struct Trienode
{
	Trienode* Children[ALPHABET_SIZE];
	bool isEndofWord;
	TType data;
	int counter;
}Trienode;

Trienode* GetTrieNode(TType data)
{
	Trienode* root = NULL;
	root = (Trienode*)malloc(sizeof(Trienode));

	if (root)
	{
		root->isEndofWord = false;
		root->data = data;
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			root->Children[i] = NULL;
		}

		root->counter = 0;
	}
	return root;
}

void Insert(Trienode* root, const char* key)
{
	Trienode* crawl = root;
	int index;
	
	int length = strlen(key);
	int counter = 0;

	for (int level = 0; level < length; level++)
	{

		index = CHAR_TO_INT(key[level]);

		if (crawl->Children[index]!= NULL && key[level] == crawl->Children[index]->data)
		{
			
			counter++;

		}
		if (!crawl->Children[index])
		{
			crawl->Children[index] = GetTrieNode(key[level]);

		}
		crawl = crawl->Children[index];
	}

	crawl->counter=counter;
	
	crawl->isEndofWord = true;

}
int search(Trienode* root, const char* key, int *max)
{

	Trienode* crawl = root;
	int length = strlen(key);
	int Index;

	for (int level = 0; level < length; level++)
	{
		Index = CHAR_TO_INT(key[level]);

		crawl = crawl->Children[Index];
		if (crawl->counter > *max)
		{
			*max = crawl->counter;
		}

	}
	return *max;
}