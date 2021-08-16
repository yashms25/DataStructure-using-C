#include <stdio.h>
struct node
{
  int data;
  struct node *next,*prev;
};
struct node *first,*last,*current,*follow,*ahead,*pnode;
void create()
{
  pnode=(struct node *)malloc(sizeof(struct node));
  if (pnode==NULL)
     printf("Insufficient memory");
  else
  {
    printf("Enter a number:");
    scanf("%d",&pnode->data);
    if (first==NULL)
    {
      first=pnode;
      last=pnode;
      pnode->next=NULL;
      pnode->prev=NULL;
    }
    else
    {
      last->next=pnode;
      pnode->prev=last;
      last=pnode;
      last->next=NULL;
    }
  }

}
void insertbefore()
{
  int x;
  if(first==NULL)
    printf("list not created");
  else
  {
  pnode=(struct node *)malloc(sizeof(struct node));
  if (pnode==NULL)
     printf("Insufficient memory");
  else
  {
    printf("Enter a number:");
    scanf("%d",&pnode->data);
    printf("Enter number before which insertion should be done:\n");
    scanf("%d",&x);
    current=first;
    follow=NULL;
    while(current->data!=x && current!=NULL)
    {
      current=current->next;
      if(current==NULL)
      break;
      follow=current->prev;
      }
    if(current==NULL)
       printf("Node not found");
    else
    {
      printf("%d is inserted",pnode->data);
      if(current==first)
      {
        pnode->next=first;
        first->prev=pnode;
        first=pnode;
        first->prev=NULL;
      }
      else
      {
        follow->next=pnode;
        pnode->prev=follow;
        pnode->next=current;
        current->prev=pnode;
      }
    }
  }
 }
}
void insertafter()
{
  int x;
  if(first==NULL)
    printf("list not created");
  else
  {
  pnode=(struct node *)malloc(sizeof(struct node));
  if (pnode==NULL)
     printf("Insufficient memory");
  else
  {
    printf("Enter a number:");
    scanf("%d",&pnode->data);
    printf("Enter number after which insertion should be done:\n");
    scanf("%d",&x);
    current=first;
    while(current->data!=x && current!=NULL)
      {current=current->next;
      if(current==NULL)
      break;
      ahead=current->next;}
    if(current==NULL)
       printf("Node not found");
    else
    { 
      printf("%d is inserted",pnode->data);
      if(current==last)
      {
        current->next=pnode;
        pnode->prev=current;
        pnode->next=NULL;
        last=pnode;
      }
      else
      {
        current->next=pnode;
        pnode->prev=current;
        pnode->next=ahead;
        ahead->prev=pnode;
      }
    }
  }
 }
}
void deletion()
{
  int x;
  if(first==NULL)
    printf("list is empty");
  else
  {
  printf("Enter element to be delete:");
  scanf("%d",&x);
  current=first;
  follow=NULL;
  while(current->data!=x && current!=NULL)
      {current=current->next;
      if(current==NULL)
      break;
    follow=current->prev;
    ahead=current->next;}
    if(current==NULL)
       printf("Node not found");
    else
    {
      printf("%d is removed",current->data);
      if(current==first && current==last)
         first=NULL;
      else
      {
        if(current==first)
        {
           first=first->next;
           first->prev=NULL;
        }
        else
        {
          if(current==last)
          {
            last=follow;
            last->next=NULL;
          }
          else
          {
            follow->next=ahead;
            ahead->prev=follow;
          }
        }
      }
      free(current);
    }
  }
}
void search()
{
  int x;
  if(first==NULL)
    printf("list not created");
  else
  {
  printf("Enter element to be search:");
  scanf("%d",&x);
  current=first;
  while(current->data!=x && current!=NULL)
      {current=current->next;
      if(current==NULL)
      break;}
  if (current==NULL)
    printf("%d is not found",x);
  else
     printf("%d is found",x);
   }
}
void traversalforward()
{
  if(first==NULL)
    printf("list is empty");
  else
  {
    printf("The elements in the list are:\n");
    current=first;
    while(current!=NULL)
    {
      printf("%d ",current->data);
      current=current->next;
    }
  }
}
void traversalbackward()
{
  if(first==NULL)
    printf("list is empty");
  else
  {
    printf("The elements in the list are:\n");
    current=last;
    while(current!=NULL)
    {
      printf("%d ",current->data);
      current=current->prev;
    }
  }
}
int main()
{
  int ch;
  do
  {
    printf("\n1.create\n2.insertafter\n3.insertbefore\n4.deletion\n5.search\n6.traversalforward\n7.traversalbackward\n8.exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1: create();
                break;
        case 2: insertafter();
                break;
        case 3: insertbefore();
                break;
        case 4: deletion();
                break;
        case 5: search();
                break;
        case 6: traversalforward();
                break;
        case 7: traversalbackward();
                break;   
        case 8: exit(0);
      }
   }while(ch!=8);
}