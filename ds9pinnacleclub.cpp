#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class node
{
int v;
int data;
char name[33];
node *next;
public:
node * create(node *);
void insert(node *);
void display(node *);
void reverse(node *);
void reverse1(node *);
void del(node *);
void count(node *);
void rev(node *);
void merge(node*,node*);
};

node * node:: create(node * head)
{
head=new node;
head->data=0;
head->next=NULL;
return head;
}


void node:: count(node *head)
{
int c=0;
node * temp;
temp=head->next;
while(temp!=NULL)
{
c++;
temp=temp->next;
}
cout<<"\n Total nodes="<<c;
}



void node:: del(node *head)
{
node *temp;
temp=head;
int d;
cout<<"\nEnter the location  \n";
cin>>d;

while(temp->next->data!=d)
{
temp=temp->next;
}
node *t1;
t1=new node;
t1=temp->next;
temp->next=t1->next;
delete t1;
}


void node::insert(node *head)
{
node *t1;
t1=new node;

node *temp;
node *t;
t=new node;
temp=head;
cout<<"\nEnter the Rollno \n";
int g;
cin>>g;
cout<<"\nEnter the Name \n";
char na[21];
cin>>na;

t->data=g;
strcpy(t->name,na);

t->next=NULL;

static int c=0;
cout<<"\n1:Add members/president/secretory";
char ch;
cin>>ch;

if(ch=='p')
{
 if(temp->next==NULL)
 {
  temp->next=t;
 }
else
{
t->next=temp->next;
temp->next=t;
}
}

if(ch=='s')
{
 while(temp->next!=NULL)
 {
  
  temp=temp->next;
 }

 c++;
 temp->next=t;
}
if(ch=='m')
{
temp=head;
 if(c!=0)
 {
  while(temp->next->next!=NULL)
  { 
   temp=temp->next;
  }
 t->next=temp->next;
 temp->next=t;
 }
 else
 {
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
 temp->next=t;
}
}
}

void node:: display(node *head)
{
node *temp;
temp=head->next;
while(temp!=NULL)
{
cout<<"["<<temp->data<<"|";
cout<<temp->name<<"]";
temp=temp->next;
cout<<"->";
 if(temp==NULL)
 cout<<"NULL";
}

}

void node:: reverse(node * head)
{
static int d;
node *p;
p=head->next;
while(p!=NULL)
{
p->v=0;
cout<<p->v;
p=p->next;
}
cout<<"\nHello\n";
p=head->next;
while(p->v==0)
{
while(p->next!=NULL && p->next->v==0)
{
p=p->next;
}
cout<<"["<<p->data<<"]";
p->v=1;
p=head->next;
}

}




void node:: reverse1(node * head)
{
node *prev,*temp,*next1;
prev=head->next;
temp=prev->next;
prev->next=NULL;

while(temp!=NULL)
{
next1=temp->next;
temp->next=prev;
prev=temp;
temp=next1;
}
head->next=prev;
}


void node:: rev(node *head)
{
if(head->next==NULL)
{
cout<<"hiiii";
return ;
}
rev(head->next);

cout<<"["<<head->next->data<<"|";
cout<<head->next->name<<"]";
cout<<"->";
}

void node::merge(node* head, node*head1)
{
node *curr;
curr=head;
while(curr->next!=NULL)
curr=curr->next;
curr->next=head1->next;
}


int main()
{
node *head,*head1;
node s;
head=new node;
head1=new node;
while(1)
{
cout<<"\n1: Create\n";
cout<<"\n2: Insert\n";
cout<<"\n3: Display\n";
cout<<"\n5: Reverse\n";
cout<<"\n4: Exit\n";
cout<<"\n6: Delete\n";
cout<<"\n7: Count\n";
cout<<"\n8: Revers Recursion\n";
cout<<"\n9: Merge \n";
cout<<"\nEnter your choice\n";
int ch;
cin>>ch;

switch(ch)
{
case 1:
 head=s.create(head); 
 break;
case 2:
 s.insert(head);
 break;
case 3:
 s.display(head);
 break;
case 4:
 exit(0);
case 5:
 s.reverse1(head);
 break;
case 6:
 s.del(head);
 break;
case 7:
 s.count(head);
 break;
case 8:
 s.rev(head);
 break;
 
case 9: int n;
 cout<<"\nFirst we create another(2) list \n";
 head1=s.create(head1); 
 cout<<"\nHow many nodes you have to insert in 2 list\n";
 cin>>n;
 for (int i=0;i<n;i++)
 s.insert(head1);
 cout<<"\nWe merge list1 and list2\n";
 s.merge(head,head1);
 break;  
}
}
return 0;
}