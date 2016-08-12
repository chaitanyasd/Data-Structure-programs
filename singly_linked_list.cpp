//============================================================================
// Name        : singly_linked_list.cpp
// Author      : CAAI
//============================================================================

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *cur  = NULL;
struct node *head = NULL;
int c = 0;

void add_first(int v)
{
	struct node *nn = malloc(sizeof(nn));
	if(!nn){
			printf("Memory error");
			return;
	}
	nn->next = NULL;
	nn->data = v;
	if(head == NULL)
		head = nn;
}

void add(int v)
{
	struct node *nn = malloc(sizeof(nn));
	if(!nn){
		printf("Memory error");
		return;
	}
	nn->next = NULL;
	nn->data = v;
	cur = head;
	if(head == NULL)
		add_first(v);
	else
	{
	    while(cur->next != NULL){
		    cur = cur->next;
	    }
	    cur->next = nn;
	}
}

void display()
{
	if(head == NULL)
	{
		printf("Empty List\n");
		return;
	}
	cur = head;
	while(cur != NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int count()
{
	if(head == NULL)
		return 0;
	else{
		cur = head;
		while(cur != NULL){
			c++;
			cur = cur->next;
		}
		return c;
	}

}

void ins_end(int v)
{
	struct node *nn = malloc(sizeof(nn));
	if(!nn){
		printf("Memory error");
		return;
	}
	nn->data = v;
	nn->next = NULL;
	cur = head;
	while(cur->next != NULL)
	{
		cur=cur->next;
	}
	cur->next = nn;

}

void insert(int v,int pos)
{
	count();
	struct node *nn = malloc(sizeof(nn));
	if(!nn){
		printf("Memory error");
		return;
	}
	nn->data = v;
	nn->next = NULL;
	cur = head;
	int k = 1;
	struct node *temp;

	if(pos > c)
		pos = c + 1 ;
	if(pos <= 0)
		pos = 1;
	if(pos>1)
	{
		while(k < pos){
			temp = cur;
			cur = cur->next;
			k++;
		}
		temp->next = nn;
		nn->next = cur;
	}
	else
	{
		nn->next = head;
		head=nn;
	}
}

void del_all()
{
	cur = head;
	struct node *temp;
	while(cur!= NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	head = NULL;
	display();
}

void del_first()
{
	if(head != NULL)
	{
		cur = head;
		head = head->next;
		free(cur);
		display();
	}
}

void del_pos(int pos)
{
	cur = head;
	struct node *temp;
	int k = 1;
	while(k < pos)
	{
		temp = cur;
		cur = cur->next;
		k++;
	}
	temp->next = cur->next;
	free(cur);
	display();
}

int main()
{
	for(int i=0;i<5;i++)
		add(i+1);
	display();
	insert(15,0);
	display();
	ins_end(33);
	display();
	del_first();
	del_pos(3);
	del_all();
	return 0;
}
