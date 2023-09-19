#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
string data;
Node* next;
Node* prev;
bool completion;
Node(string val)
{
data=val;
next=NULL;
prev=NULL;
completion=0;
}
};


class List
{
private:
Node *head;
int length;
public:
List()
{
head=NULL;
length=0;
}
~List()
{
Node* curr=head;
while(head!=NULL)
{
curr=head;
head=head->next;
delete curr;
}
}

void insert(string task,int pos)
{
if(pos<1||pos>length+1)
cout<<"Invalid position"<<endl;

Node* n=new Node(task);

if(pos==1)
{
n->next-head;
if(head!=NULL)
{
head->prev=n;
}

head=n;
}
else 
{
Node* curr=head;
for(int i=1;i<pos-1;i++)
{
curr=curr->next;
}
n->prev=curr;
n->next=curr->next;
if(curr->next=NULL)
{
curr->next->prev=n;
}
curr->next=n;
}
length++;
}

void remove(int pos)
{
if(head==NULL)
cout<<"Empty List"<<endl;
if(pos<1||pos>length)
cout<<"Invalid Position"<<endl;


Node* curr=head;
if(pos==1)
{
head=head->next;
delete curr;
if(head!=NULL)
head->prev=NULL;
}
else
{
Node* slow=NULL;
for(int i=1;i<pos;i++)
{
slow=curr;
curr-curr->next;
}
if(curr->next!=NULL)
curr-> next->prev=slow;
delete curr;
}
length--;
}

void displayForward()
{
Node* curr=head;
int count=1;
while(curr!=NULL)
{
if(curr->completion==0)
{
cout<<""<<count<<")"<<""<<curr->data<<"-Not Completed"<<endl;
count++;
curr=curr->next;

}
else if(curr->completion==1)
{
cout<<""<<count<<")"<<""<<curr->data<<"-Completed"<<endl;
curr=curr->next;
count++;
}
cout<<endl;
}
}
void displayReverse()
{
Node* curr=head;
while(curr->next!=NULL)
{
curr=curr->next;
}
int count=1;
while(curr->prev!=NULL)
{
if(curr->completion==0)
{
cout<<""<<count<<")"<<""<<curr->data<<"-Not Completed"<<endl;
curr=curr->prev;
count++;
}
else if(curr->completion==1)
{
cout<<""<<count<<")"<<""<<curr->data<<"-Completed"<<endl;
curr=curr->prev;
count++;
}


cout<<endl;
}
}

void MarkComplete(int pos)
{
 Node* curr=head;
 while (curr!=NULL) 
 {
    if (pos==1) 
    {
      curr->completion=1;
      break;
    }
   
   curr = curr->next;
   pos--;
 }
}


};

int main()
{
List Task;
int choice;

do
{
cout<<"---MAIN MENU---"<<endl;
cout<<"1)Add Task"<<endl;
cout<<"2)Mark as Completed"<<endl;
cout<<"3)Remove Completed Tasks"<<endl;
cout<<"4)Display Tasks"<<endl;
cout<<"5)Exit"<<endl;
cout<<"Please enter your choice"<<endl;
cin>>choice;

if(choice==1)
{
string task;
int pos;
cout<<"Enter the Task Description:"<<endl;
cin.ignore();
getline(cin,task);

cout<<"---Enter its Priority Level---"<<endl;
cin>>pos;

Task.insert(task,pos);
Task.displayForward();
}

else if(choice==2)
{
int pos;
Task.displayForward();
cout<<"Enter the Task Number which you have Completed"<<endl;
cin>>pos;
Task.MarkComplete(pos);
cout<<"Task is marked as completed"<<endl;
Task.displayForward();
}

else if(choice==3)
{
int pos;
Task.displayForward();
cout<<"Enter position of Task which you want to remove"<<endl;
cin>>pos;
Task.remove(pos);
}
else if(choice==4)
{
int option;
cout<<"Select order of display"<<endl;
cout<<"1)Forward Order"<<endl;
cout<<"2)Reverse Order"<<endl;
cin>>option;
if(option==1)
Task.displayForward();
if(option==2)
Task.displayReverse();
}
}while (choice!=5);
}



