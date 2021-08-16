#include <stdio.h>

#define  MAX 5
struct dqueue
{
  int f,r;
  int elem[MAX];
}dq;

int empty()
{
  if(dq.f>dq.r)
      return 1;
  else
      return 0;    
}
int full()
{
  if(dq.r==MAX-1)
      return 1;
  else
      return 0;
}

void insert(int x)
{
  if(full())
      printf("\n dqueue is full\n");
  else
      dq.elem[++dq.r]=x;  
}

int deleteR()
{
 if(empty())
      return -1;
 else
      {
        return dq.elem[dq.r--];
      }
       
}

int deleteF()
{
 if(empty())
      return -1;
 else
      {
        return dq.elem[dq.f++];
      }        
}


void show()
{
  int i;
  if(empty())
      printf("\n dqueue is empty\n");
  else
  {
      printf("The elements in queue are:\n");
      for(i=dq.f;i<=dq.r;i++)
            printf("%d\t ",dq.elem[i]);
  }    
}

void main()
{
  dq.r=-1;
  dq.f=0;
  int ch,x;
  do
  {
    printf("\n1. insert\n2. remove from rear\n3. remove from front\n4. show\n5. exit\n");
    printf("\n Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\nEnter value to be insert\n");
              scanf("%d",&x);
              insert(x);
              break;
      case 2: x=deleteR();
              if(x==-1)
                printf("\ndqueue is empty\n");
              else
                printf("\n%d is removed\n",x);
                break;
      case 3:x=deleteF();
              if(x==-1)
                printf("\ndqueue is empty");
              else
                printf("\n%d is removed\n",x);
                break;
      case 4: show();
              break;
      case 5: exit(0);                  
   }
  }while(ch!=5);
}












