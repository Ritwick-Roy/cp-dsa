#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		int info;
		node* next;
		node(int info=0)
		{
			this->info=info;
			this->next=NULL;
		}
		void display()
		{
			cout<<"The list is:\n";
			node* np=this;
			node* ptr;
			while(np!=NULL && np->next!=NULL)
			{
				cout<<np->info<<"->";
				ptr=np;
				np=np->next;
				delete ptr;
			}
			if(np!=NULL)
			{
				cout<<np->info;
				ptr=np;
				np=np->next;
				delete ptr;
			}
			cout<<"\n";
		}
}*start,*newptr;
void insert(node* ptr)
{
	if(start != NULL)
	{
		ptr->next=start;
		start=ptr;
	}
	else
		start=ptr;
}

int main()
{
	start=NULL;
	int i,n,inf;
	cout<<"Enter number of nodes:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter node info:";
		cin>>inf;
		newptr=new node(inf);
		if(newptr==NULL)
		exit(1);
		insert(newptr);
	}
	cout<<"\n";
	start->display();
	return 0;
}
