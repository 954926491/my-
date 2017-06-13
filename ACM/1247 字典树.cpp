#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct node
{
	int flash;
	node *next[26];
}*root;
void tree(char *q)
{
	node *p=root;
	//int len=strlen(str);
	for(;*q!='\0';q++)
	{
		int t=*q-'a';
		if(p->next[t]==NULL)
		{
            p->next[t]=new node();
            p=p->next[t];
		}
		else
		p=p->next[t];
	}
	p->flash=1;
}
int find1(char *q)
{
	//int len=strlen(str);
	node *p=root;
	for(;*q!='\0';)
	{
		int t=*q-'a';
		if(p->next[t]!=NULL)
		{
			p=p->next[t];
			if(p->flash==1&&*(q+1)=='\0')
			return 1;
			q++;	
		}
		else
		return 0;
	}
	return 0;
}
int find(char *q)
{
	//int len=strlen(str);
	node *p=root;
	for(;*q!='\0';)
	{
		int t=*q-'a';
		p=p->next[t];
		if(p!=NULL)
		{
			if(p->flash==1&&find1(q+1))
			return 1;
			q++;
		}
		else
		return 0;
	}
	return 0;
}
char str[50002][50];
int main()
{
	int i=0,j;
	root=new node();	
	while(~scanf("%s",str[i]))
	{
		tree(str[i]);
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(find(str[j]))
		printf("%s\n",str[j]);
	}
	return 0;
}