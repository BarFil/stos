#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int stack_init(struct stack_t **stack)
{
  if(stack==NULL)
  {
    return 1;
  }
  struct stack_t *temp=(struct stack_t*)malloc(sizeof(struct stack_t));
  if(temp==NULL)
  {
    *stack=NULL;
    return 2;
  }
  temp->head=NULL;

*stack=temp;
return 0;
}


int stack_push(struct stack_t *stack, int value)
{
  if(stack==NULL )return 1;
  struct node_t* new_node=(struct node_t*)malloc(sizeof(struct node_t));
  if(new_node==NULL)
    return 2;

  new_node->data=value;
  new_node->next=stack->head;
  stack->head = new_node;

  return 0;
}

int stack_pop(struct stack_t* stack, int *err_code)
{
  if(stack==NULL || stack->head==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 1;
  }

  struct node_t *temp = stack->head;
  int value=temp->data;
  stack->head = stack->head->next;
  free(temp);

  if(err_code!=NULL)*err_code=0;
  return value;
}

int stack_empty(const struct stack_t* stack)
{
  if(stack==NULL)return 2;
  if(stack->head==NULL)return 1;
  return 0;
}

void stack_destroy(struct stack_t** stack)
{
  if(stack==NULL)return;
  struct node_t* temp = (*stack)->head;

  while(temp!=NULL)
  {
    (*stack)->head = (*stack)->head->next;
    free(temp);
    temp = (*stack)->head;
  }
  free(*stack);
  *stack=NULL;
}

void stack_display(const struct stack_t* stack)
{
  if(stack==NULL || stack->head==NULL)return;
  struct node_t* temp = stack->head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}