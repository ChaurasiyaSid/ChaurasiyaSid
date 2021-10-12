#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *next;
  };
  typedef struct node*nodeptr;
  nodeptr create(nodeptr list)
{
  int n,i;
  nodeptr newnode,curr;
  printf("how many numbers");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter number");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(list==NULL)
  {
  list=newnode;
  curr=newnode;
  }
  else
  {
  curr->next=newnode;
  curr=newnode;
  }
  }
  return list;
  }
  nodeptr insert(nodeptr list,int pos)
  {
  nodeptr newnode,curr;
  int i;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter number");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(list==NULL)
  {
  list=newnode;
  return list;
  }
  if(pos==1)
  {
  newnode->next=list;
  list=newnode;
  return list;
  }
  for(i=1,curr=list;i<pos-1 && curr->next!=NULL;i++,curr=curr->next);
  newnode->next=curr->next;
  curr->next=newnode;
  return list;
  }
  nodeptr delpos(nodeptr list,int pos)
  {
  nodeptr curr=list,curr1;
  int i;
  if(list==NULL)
  {
  printf("list is empty");
  return list;
  }
  if(pos==1)
  {
  list=curr->next;
  free(curr);
  return list;
  }
  for(i=1,curr=list;i<pos-1 && curr->next!=NULL;i++,curr=curr->next);
  if(curr->next==NULL)
  {
  printf("List is NULL");
  return list;
  }
  curr1=curr->next;
  curr->next=curr1->next;
  free(curr1);
  return list;
  }
  nodeptr delnum(nodeptr list,int num)
  {
  int i;
  nodeptr curr=list,curr1;
  if(list==NULL)
  {
  printf("list is empty");
  return list;
  }
  if(curr->data==num)
  {
  list=curr->next;
  free(curr);
  return list;
  }
  for(curr=list;curr->next!=NULL;i++,curr=curr->next)
  {
  if(curr->next->data==num)
  {
  curr1=curr->next;
  curr->next=curr1->next;
  free(curr1);
  }
  }
  printf("Element not found");
  return list;
  }
  nodeptr reverse(nodeptr list)
  {
  nodeptr curr1,curr2,curr3;
  curr1=list;
  curr2=curr1->next;
  curr3=curr2->next;
  curr1->next=NULL;

  while(curr3!=NULL)
  {
  curr2->next=curr1;
  curr1=curr2;
  curr2=curr3;
  curr3=curr2->next;
  }
  curr2->next=curr1;
  list=curr2;
  return list;
  }
  void display(nodeptr list)
  {
  nodeptr curr;
  for(curr=list;curr->next!=NULL;curr=curr->next)
  {
  printf("%d",curr->data);
  }
  }
  int search(nodeptr list,int r)
  {
  nodeptr curr;
  int i;
  for(i=1,curr=list;curr!=NULL;i++,curr=curr->next);
  {
  if(curr->data==r)
  return i;
  }
  return -1;
  }
  void main()
  {
  int r,pos,num,ch;
  nodeptr list=NULL;
  clrscr();
  do
  {
  printf("\n0.Exit\n1.Create\n2.Display\n3.Search\n4.Insert\n5.Delete by position\n6.Delete\n7.Reverse");
  printf("\n Enter your Choice:");
  scanf("%d",&ch);
  switch(ch)
  {
  case 0:exit (0);
  case 1:list=create(list);break;
  case 2:display(list);break;
  case 3:printf("Enter number to search:");
	 scanf("%d",&r);
	 pos=search(list,r);
	 if(pos==1)
	 printf("%d not found",r);
	 else
	 printf("%d found at position %d",r,pos);break;
  case 4:printf("Enter position:");
	 scanf("%d",&pos);
	 list=insert(list,pos);break;
  case 5:printf("Enter position:");
	 scanf("%d",&pos);
	 list=delpos(list,pos);break;
  case 6:printf("Enter position:");
	 scanf("%d",&num);
	 list=delnum(list,num);break;
  case 7:list=reverse(list);
	 break;
  default: printf("Invalid choice");
  }
  }while(ch!=0);
  getch();
  }