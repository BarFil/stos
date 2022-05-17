#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
struct stack_t* stos;
if( stack_init(&stos) == 2)
{
  printf("Failed to allocate memory");
  return 8;
}
int i=1;
int x,err;
while(i!=0)
{
  printf("Co chcesz zrobić: ");
  if( scanf("%d",&i) !=1)
  {
    printf("Incorrect input\n");
    stack_destroy(&stos);
    return 1;
  }
  if(i==1)
  {
    printf("Podaj liczbę: ");
    if( scanf("%d",&x) !=1)
    {
    stack_destroy(&stos);
    printf("Incorrect input\n");
    return 1;
    }
    int push = stack_push(stos, x);
    if(push==2)
    {
      printf("Failed to allocate memory\n");
      stack_destroy(&stos);
      return 8;
    }


  }
  else if(i==2)
  {
    int pop = stack_pop(stos, &err);
    if(err==1)
    {
      printf("Stack is empty\n");
    }
    else
    {
      printf("%d\n",pop);
    }
  }
  else if(i==3)
  {
    printf("%d\n",stack_empty(stos));
  }
  else if(i==4)
  {
    if(stos->head==0)
    {
      printf("Stack is empty\n");
    }
    else
    {
      stack_display(stos);
    } 
  }
  else
  {
    printf("Incorrect input data\n");
  }

}
  stack_destroy(&stos);
  return 0;
}