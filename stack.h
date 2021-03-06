#ifndef _STACK_H_
#define _STACK_H_

struct node_t
{
  int data;
  struct node_t* next;
};


struct stack_t
{
  struct node_t* head;
};


int stack_init(struct stack_t **stack);
int stack_push(struct stack_t *stack, int value);
void stack_display(const struct stack_t* stack);
int stack_pop(struct stack_t* stack, int *err_code);
void stack_destroy(struct stack_t** stack);
int stack_empty(const struct stack_t* stack);

#endif