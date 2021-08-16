#include <stdio.h>

#define  MAX 5
struct queue
{
  int f,r;
  int elem[MAX];
}q;

int empty()
{
  if(q.f>q.r)
      return 1;
  else
      return 0;    
}
int full()
{
  if(q.r==MAX-1)
      return 1;
  else
      return 0;
}

void insert(int x)
{
  if(full())
      printf("\nqueue is full\n");
  else
      q.elem[++q.r]=x;  
}

int delete()
{
 if(empty())
      return -1;
 else
      return q.elem[q.f++];
             
}

void show()
{
  int i;
  if(empty())
      printf("\nqueue is empty\n");
  else
  {
      printf("The elements in queue are:\n");
      for(i=q.f;i<=q.r;i++)
            printf("%d\t ",q.elem[i]);
  }    
}

void main()
{
  q.r=-1;
  q.f=0;
  int ch,x;
  do
  {
    printf("\n 1. insert\n  2. remove\n  3. show\n  4. exit\n");
    printf("\n Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\nEnter value to be insert\n");
              scanf("%d",&x);
              insert(x);
              break;
      case 2: x=delete();
              if(x==-1)
                printf("\n queue is empty");
              else
                printf("\n %d is removed\n",x);
                break;
      case 3: show();
              break;
      case 4: exit(0);                  
   }
  }while(ch!=4);
}












