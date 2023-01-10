#include<bits/stdc++.h>
using namespace std;

class node   
{  
	public:
	    int data;  
	    node *next;   
}*head,*ptr,*temp,*preptr;  

void begin_insert()  
{     
    int item;   
    ptr=new node;  
    if(ptr==NULL)  
        cout<<"\nOVERFLOW";  
    else   
    {  
        cout<<"Enter the node data:";  
        cin>>item;
        ptr->data=item;  
        if(head==NULL)  
        {  
            head=ptr;  
            ptr->next=head;  
        }  
        else   
        {     
            temp=head;  
            while(temp->next!=head)  
                temp=temp->next;  
            ptr->next=head;   
            temp->next=ptr;   
            head=ptr;  
        }   
        cout<<"Node inserted!\n";  
    }  
}  
void last_insert()  
{  
    int item;   
    ptr=new node;  
    if(ptr==NULL)  
        cout<<"\nOVERFLOW";  
    else   
    {  
        cout<<"Enter the node data:";  
        cin>>item;
        ptr->data=item;  
        if(head==NULL)  
        {  
            head=ptr;  
            ptr->next=head;  
        }  
        else   
        {     
            temp=head;  
            while(temp->next!=head)  
                temp=temp->next; 
            temp->next=ptr;
            ptr->next=head;   
        }   
        cout<<"Node inserted!\n";  
    }
}  
void specific_insert()
{
	int item,flag=0,val;  
    ptr=head;   
    if(ptr==NULL)  
    {  
        cout<<"Empty List\n";  
        return;
    }   
    cout<<"Enter node after which new element will be added:"; 
    cin>>item;
    temp=new node;
    if(head->data==item)  
	{  
		cout<<"Enter new data:";
		cin>>val;
		temp->data=val;
		temp->next=ptr->next;
		ptr->next=temp;
	    flag=1;  
    }  
    else   
    {  
	    ptr=ptr->next;
	    while(ptr!=head)  
	    {  
	        if(ptr->data==item)  
	        {  
				cout<<"Enter new data:";
				cin>>val;
				temp->data=val;
				temp->next=ptr->next;
				ptr->next=temp;
	            flag=1;  
	            break;  
	        }   
	        else flag=0;
	        ptr=ptr->next;  
	    }  
    }  
    if(!flag)  
	cout<<"Item not found\n";
}
void begin_delete()  
{   
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW");    
        return;
    }  
    if(head->next==head)  
    {  
        head=NULL;  
        delete head;  
        printf("Node deleted!\n");  
    }   
    else  
    {   
		ptr=head;   
        while(ptr->next!=head)  
            ptr=ptr->next;   
        ptr->next=head->next;  
        delete head;  
        head=ptr->next;  
        printf("Node deleted!\n");  
    }  
}  
void last_delete()  
{  
	if(head==NULL)  
    {  
        printf("\nUNDERFLOW");    
        return;
    }  
    if(head->next==head)  
    {  
        head=NULL;  
        delete head;  
        printf("Node deleted!\n");  
    }   
    else  
    {   
		ptr=head;   
        while(ptr->next!=head)  
        {
        	preptr=ptr;
			ptr=ptr->next;   
		}
        preptr->next=ptr->next;  
        delete ptr;  
        printf("Node deleted!\n");  
    }   
}  
void specific_delete()
{
	int item,flag=0,val;  
    ptr=head;   
    if(ptr==NULL)  
    {  
        cout<<"Empty List\n";  
        return;
    }   
    cout<<"Enter node to be deleted:\n"; 
    cin>>item;
    if(head->data==item)  
	{  
	    begin_delete();  
	    flag=1;
    }  
    else   
    {  
	    while(ptr->next!=head)  
	    {  
	        if((ptr->next)->data==item)  
	        {  
				temp=new node;
				temp=(ptr->next)->next;
				ptr->next=temp;
	            flag=1;  
	            break;  
	        }   
	        else flag=0;  
	        ptr=ptr->next;  
	    }  
    }  
    if(!flag)  
	cout<<"Item not found\n";
}
void search()  
{
    int item,i=0,flag=0;  
    ptr=head;   
    if(ptr==NULL)  
    {  
        cout<<"Empty List\n";  
        return;
    }   
    cout<<"Enter item which you want to search?\n"; 
    cin>>item;
    if(head->data==item)  
	{  
	    cout<<"Item found at location "<<i<<"\n";  
	    flag=1;  
    }  
    else   
    {  
	    ptr=ptr->next;
	    while(ptr!=head)  
	    {  
	        if(ptr->data==item)  
	        {  
	            cout<<"Item found at location "<<i+1<<"\n";  
	            flag=1;  
	            break;  
	        }   
	        else flag=0;
	        i++;  
	        ptr=ptr->next;  
	    }  
    }  
    if(!flag)  
	cout<<"Item not found\n";             
}  
void display()  
{  
    ptr=head;  
    if(head==NULL)  
        cout<<"List empty!";  
    else  
    {  
		cout<<"The list is:\n";     
        while(ptr->next!=head)  
        {  
        	cout<<ptr->data<<"\n";
            ptr=ptr->next;  
        }  
        cout<<ptr->data<<"\n";  
    }   
}  
int main()  
{  
    int c=0;  
    while(1)   
    {  
    	cout<<"Menu\n";
        cout<<"1.Insert in begining\n2.Insert at last\n3.Insert in middle\n4.Delete from Beginning\n5.Delete from last";
		cout<<"\n6.Delete from middle.\n7.Search for an element\n8.Show\n9.Exit\n";  
        cout<<"Enter choice:";         
		cin>>c;  
        switch(c)  
        {  
            case 1:begin_insert();      
            break;  
            case 2:last_insert();         
            break;  
            case 3:specific_insert();
            break;
            case 4:begin_delete();       
            break;  
            case 5:last_delete();        
            break; 
			case 6:specific_delete();
			break; 
            case 7:search();         
            break;  
            case 8:display();        
            break;  
            case 9:exit(0);  
            break;  
            default:cout<<"Invalid choice!";  
        }  
    }
	return 0;  
}  
