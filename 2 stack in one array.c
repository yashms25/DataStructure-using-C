#include <stdio.h>

//Compiler version gcc  6.3.0
#define  MAX 10
struct stack
{
  int tos1,tos2;
  int elem[MAX];
}s;

int empty1()
{
  if(s.tos1==-1)
      return 1;
  else
      return 0;        
}
int empty2()
{
  if(s.tos2==MAX)
      return 1;
  else
      return 0;  
 }  
int full()
{
  if(s.tos2==s.tos1+1)
      return 1;
  else
      return 0;
}

void push1(int x)
{
  if(full())
      printf("\nStack 1 is full\n");
  else
      s.elem[++s.tos1]=x;  
}
void push2(int x)
{
  if(full())
      printf("\nStack 2 is full\n");
  else
      s.elem[--s.tos2]=x;  
}

int pop1()
{
 if(empty1())
      return -1;
 else
      return s.elem[s.tos1--];
             
}
int pop2()
{
 if(empty2())
      return -1;
 else
      return s.elem[s.tos2++];
             
}

void show1()
{
  int i;
  if(empty1())
      printf("\nstack 1 is empty\n");
  else
  {
      printf("The elements in stack 1 are:\n");
      for(i=0;i<=s.tos1;i++)
            printf("%d\t ",s.elem[i]);
  }    
}
void show2()
{
  int i;
  if(empty2())
      printf("\nstack 2 is empty\n");
  else
  {
      printf("The elements in stack 2 are:\n");
      for(i=MAX-1;i>=s.tos2;i--)
            printf("%d\t ",s.elem[i]);
  }    
}

void main()
{
  s.tos1=-1;
  s.tos2=MAX;
  int ch,x;
  do
  {
    printf("\n1. push(1)\n2. push(2)\n3. pop(1)\n4. pop(2)\n5. show(1)\n6. show(2)\n7. exit");
    printf("\n Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\nEnter value to be push\n");
              scanf("%d",&x);
              push1(x);
              break;
      case 2: printf("\nEnter value to be push\n");
              scanf("%d",&x);
              push2(x);
              break; 
      case 3: x=pop1();
              if(x==-1)
                printf("\n Stack 1 is empty");
              else
               printf("\n %d is removed\n",x);
                break;
      case 4:    x=pop2();
              if(x==-1)
                printf("\n Stck 2 is empty");
              else
               printf("\n %d is removed\n",x);
                break;     
      case 5: show1();
              break;
      case 6: show2();
              break;        
      case 7: exit(0);                  
   }
  }while(ch!=7);
}