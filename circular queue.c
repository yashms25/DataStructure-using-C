#include <stdio.h>

#define  MAX 4
struct cqueue
{
  int f,r;
  int elem[MAX];
}cq;

int empty()
{
  if(cq.f==cq.r)
      return 1;
  else
      return 0;    
}
int full()
{
  if(cq.f==cq.r)
      return 1;
  else
      return 0;
}

void insert(int x)
{
  cq.r=(cq.r+1)%MAX;
  if(full()){
      printf("\n circular queue is full\n");
      cq.r--; }
  else
      cq.elem[cq.r]=x;  
}

int delete()
{
 if(empty())
      return -1;
 else{
      cq.f=(cq.f+1)%MAX;
      return cq.elem[cq.f];
      }
             
}

void show()
{
  int i;
  if(empty())
      printf("\n circular queue is empty\n");
  else
  {
      printf("The elements in queue are:\n");
      if(cq.f<cq.r){
        for(i=cq.f+1;i<=cq.r;i++)
            printf("%d\t ",cq.elem[i]);}
      else{
        for(i=cq.f+1;i<=MAX-1;i++)
        printf("%d\t ",cq.elem[i]);
        for(i=0;i<=cq.r;i++)
        printf("%d\t ",cq.elem[i]);
      }
  }    
}

void main()
{
  cq.r=MAX-1;
  cq.f=MAX-1;
  int ch,x;
  do
  {
    printf("\n1. insert\n2. remove\n3. show\n4. exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\nEnter value to be insert\n");
              scanf("%d",&x);
              insert(x);
              break;
      case 2: x=delete();
              if(x==-1)
                printf("\n circular queue is empty");
              else
                printf("\n%d is removed\n",x);
                break;
      case 3: show();
              break;
      case 4: exit(0);                  
   }
  }while(ch!=4);
}












