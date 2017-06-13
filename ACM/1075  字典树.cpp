#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
struct node
{
	struct node *next[26];
	int flash;
	char str[15];
}*root,*p,*q;
void tree(char *word1,char *word2)
{
	p=root;
	for(int i=0;i<word1[i]!='\0';i++)
	{
		int t=word1[i]-'a';
		if(p->next[t]==NULL)
		{
			q=(struct node*)malloc(sizeof(struct node));
			memset(q,NULL,sizeof(struct node));
			p->next[t]=q;
		}
			p=p->next[t];
	}
	p->flash=1;
	strcpy(p->str,word2);
}
void find(char *word)
{
	p=root;
	for(int i=0;word[i]!='\0';i++)
	{
		int t=word[i]-'a';
		if(p->next[t]!=NULL)
		{
			p=p->next[t];
		}
		else
		{
			printf("%s",word);
			return;
		}
	}
	if(p->flash==1)
	{
		printf("%s",p->str);
	}
	else
	printf("%s",word);
}
int main()
{
	int i,j,k;
	char a[15],b[15],str[3005],t[15];
	root=(struct node*)malloc(sizeof(struct node));
    memset(root,NULL,sizeof(struct node));
    scanf("%s",a);
    getchar();
    while(scanf("%s",a),strcmp(a,"END"))
    {
    	scanf("%s",b);
    	tree(b,a);
    }
    scanf("%s",a);
    getchar();
    while(gets(str),strcmp(str,"END"))
    {
 	     for(int i=0,k=0;str[i]!='\0';i++)
 	     {
     	 	if(islower(str[i]))
     	 	{
	 	     	t[k++]=str[i];
            }
            else
            {
            	t[k]='\0';
            	find(t);
            	memset(t,0,sizeof(t));
            	k=0;
            	printf("%c",str[i]);
            }
     	 }
     	 printf("\n");
    }
}