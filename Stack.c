#include <stdio.h>

#define  MAX 50
struct stack
{
  int tos;
  int elem[MAX];
}s;

int empty()
{
  if(s.tos==-1)
      return 1;
  else
      return 0;    
}
int full()
{
  if(s.tos==MAX-1)
      return 1;
  else
      return 0;
}

void push(int x)
{
  if(full())
      printf("\nStack is full\n");
  else
      s.elem[++s.tos]=x;  
}

int pop()
{
 if(empty())
      return -1;
 else
      return s.elem[s.tos--];
             
}

void show()
{
  int i;
  if(empty())
      printf("\nstack is empty\n");
  else
  {
      printf("The elements in stack are:\n");
      for(i=0;i<=s.tos;i++)
            printf("%d\t ",s.elem[i]);
  }    
}

void main()
{
  s.tos=-1;
  int ch,x;
  do
  {
    printf("\n 1. push  2. pop  3. show  4. exit");
    printf("\n Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\nEnter value to be push\n");
              scanf("%d",&x);
              push(x);
              break;
      case 2: x=pop();
              if(x==-1)
                printf("\n Stck is empty");
              else
               printf("\n %d is removed\n",x);
                break;
      case 3: show();
              break;
      case 4: exit(0);                  
   }
  }while(ch!=4);
}












