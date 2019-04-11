#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
	char key[20];
	struct treenode *ln;
	struct treenode *rn;
}tnode;

tnode *insert(tnode *root,char word[])
{
	tnode *tmp,*pre;
	if(root==NULL)
	{
		root=(tnode*)malloc(sizeof(tnode));
		strcpy(root->key,word);
		root->ln=NULL;
		root->rn=NULL;
		return root;
	}
	else
	{
		tmp=root;
		while(tmp!=NULL)
		{
			pre=tmp;
			if(strcmp(tmp->key,word)<0)
				tmp=tmp->rn;
			else
				tmp=tmp->ln;
		}
		if(strcmp(pre->key,word)<0)
		{
			pre->rn=(tnode*)malloc(sizeof(tnode));
			strcpy(pre->rn->key,word);
			pre->rn->ln=NULL;
			pre->rn->rn=NULL;
		}
		else
		{
			pre->ln=(tnode*)malloc(sizeof(tnode));
			strcpy(pre->ln->key,word);
			pre->ln->ln=NULL;
			pre->ln->rn=NULL;
		}
		return root;
	}
}

void inorder(tnode *root)
{
	tnode *tmp=root;;
	if(tmp!=NULL)
	{
		inorder(tmp->ln);
		printf("%s",tmp->key);
		inorder(tmp->rn);
	}
}

int main()
{
	tnode *root=NULL;
	char word[20];
	while(fgets(word,30,stdin)!=NULL)
		root=insert(root,word);
	inorder(root);
	return 0;
}
