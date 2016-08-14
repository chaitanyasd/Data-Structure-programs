//============================================================================
// Name        : sll_class.cpp
// Author      : Chaitanya
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next = NULL;
	friend class sll;
};

class sll{
public:
	node *head = NULL;
	void create(int v){
		node *nn,*temp;
		nn = new node();
	    nn->next = NULL;
	    nn->data = v;
	    if(head==NULL)
	    	head=nn;
	    else{
	    	temp=head;
	    	while(temp->next!=NULL){
	    		temp=temp->next;
	    	}
	    	temp->next=nn;
	    }
	}

	void display(){
		if(head==NULL)
			cout<<"Empty";
		else{
			cout<<"LIST : ";
			node *temp;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		cout<<endl;
	}
};

int main()
{
	sll s=new sll();
	for(int i=1;i<=5;i++)
		s.create(i);
	s.display();
	return 0;
}
