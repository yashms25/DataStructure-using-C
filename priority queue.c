#include <stdio.h>

#define  MAX 5
struct priorityqueue
{
  int f,r;
  int elem[MAX];
}pq;

int empty()
{
  if(pq.f>pq.r)
      return 1;
  else
      return 0;    
}
int full()
{
  if(pq.r==MAX-1)
      return 1;
  else
      return 0;
}

void insert(int x)
{
  if(full())
      printf("\n priority queue is full\n");
  else
      pq.elem[++pq.r]=x;  
}

int deleteAsc()
{
 int min,p,i;
 if(empty())
      return -1;
 else
      {
        min=pq.elem[0];
        p=0;
        for(i=1;i<=pq.r;i++)
        {
          if(pq.elem[i]<min)
          {
            min=pq.elem[i];
            p=i;
          }
        }
        for(i=p+1;i<=pq.r;i++)
        {
          pq.elem[i-1]=pq.elem[i];
          }
          pq.r--;
        return min;
      }
       
}

int deleteDsc()
{
 int max,p,i;
 if(empty())
      return -1;
 else
      {
        max=pq.elem[0];
        p=0;
        for(i=1;i<=pq.r;i++)
        {
          if(pq.elem[i]>max)
          {
            max=pq.elem[i];
            p=i;
          }
        }
        for(i=p+1;i<=pq.r;i++)
        {
          pq.elem[i-1]=pq.elem[i];
          }
          pq.r--;
        return max;
      }
       
}


void show()
{
  int i;
  if(empty())
      printf("\n priority queue is empty\n");
  else
  {
      printf("The elements in queue are:\n");
      for(i=0;i<=pq.r;i++)
            printf("%d\t ",pq.elem[i]);
  }    
}

void main()
{
  pq.r=-1;
  pq.f=0;
  int ch,x;
  do
  {
    printf("\n1. insert\n2. removeAsc\n3. removeDsc\n4. show\n5. exit");
    printf("\n Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter value to be insert\n");
              scanf("%d",&x);
              insert(x);
              break;
      case 2: x=deleteAsc();
              if(x==-1)
                printf("\n priority queue is empty\n");
              else
                printf("\n%d is removed\n",x);
                break;
      case 3:x=deleteDsc();
              if(x==-1)
                printf("\n priority queue is empty");
              else
                printf("\n%d is removed\n",x);
                break;
      case 4: show();
              break;
      case 5: exit(0);                  
   }
  }while(ch!=5);
}













