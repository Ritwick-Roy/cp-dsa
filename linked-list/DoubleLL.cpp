#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

class double_llist
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void add_end(int value);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        double_llist()
        {
            start=NULL;  
        }
};

int main()
{
    int c,element,position;
    double_llist dl;
    while (1)
    {
        cout<<"Menu\n";
        cout<<"1.Add at beginning\n";
        cout<<"2.Add at end\n";
        cout<<"3.Add after position\n";
        cout<<"4.Delete\n";
        cout<<"5.Display\n";
        cout<<"6.Quit\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_begin(element);
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_end(element);
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert after which element to be inserted: ";
            cin>>position;
            dl.add_after(element, position);
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"List empty,nothing to delete"<<endl;   
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_element(element);
            break;
        case 5:dl.display_dlist();
        break;
        case 6:exit(1);
        default:cout<<"Invalid choice!\n";
        }
    }
    return 0;
}

void double_llist::create_list(int value)
{
    node *temp;
    temp = new node; 
    temp->info=value;
    temp->next=NULL;
    temp->prev=NULL;
    start=temp;
}
void double_llist::add_begin(int value)
{
    if(start==NULL)
	{
		create_list(value);
		return;
	}
	node *temp;
    temp=new node;
    temp->prev=NULL;
    temp->info=value;
    temp->next=start;
    start->prev=temp;
    start=temp;
    cout<<"Element inserted!\n";
}
void double_llist::add_end(int value)
{
	node *temp,*s;
    if(start==NULL)
	{
		create_list(value);
		return;
	}
    temp = new node; 
    temp->info=value;
    temp->next=NULL;
    s=start;
    while(s->next!=NULL)
        s=s->next;
    s->next=temp;
    temp->prev=s;
    cout<<"Element inserted!\n";
}
void double_llist::add_after(int value,int pos)
{
    node *tmp,*q;
    if(start==NULL)
	{
		create_list(value);
		return;
	}
    tmp=new node;
    tmp->info=value;
    if(start->info==pos)
    {
        tmp->next=start->next;
        tmp->prev=start;
        start->next=tmp;
        cout<<"Element Inserted!\n";
        return;
    }
    q=start->next;
    while(q!=NULL)
    {   
        if(q->info==pos)  
        {
        	tmp->next=q->next;
            tmp->prev=q;
            q->next=tmp;
            cout<<"Element inserted!\n";
            return;
        }
        q=q->next;
    }
    cout<<"Element "<<value<<" not found!\n";
}
void double_llist::delete_element(int value)
{
    node *tmp,*q;
    if(start->info==value)
    {
        tmp=start;
        start=start->next;  
        start->prev=NULL;
        cout<<"Element deleted!\n";
        delete tmp;
        return;
    }
    q=start;
    while(q->next->next!=NULL)
    {   
        if(q->next->info==value)  
        {
            tmp=q->next;
            q->next=tmp->next;
            tmp->next->prev=q;
            cout<<"Element deleted!\n";
            delete tmp;
            return;
        }
        q=q->next;
    }
    if(q->next->info==value)    
    { 	
        tmp=q->next;
        delete tmp;
        q->next=NULL;
        cout<<"Element deleted!\n";
        return;
    }
    cout<<"Element "<<value<<" not found!\n";
}
void double_llist::display_dlist()
{
    node *q;
    if(start==NULL)
    {
        cout<<"List empty!\n";
        return;
    }
    q=start;
    cout<<"The list is:\n";
    while(q!=NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL\n";
}
