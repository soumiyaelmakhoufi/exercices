#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int* data;
  int index,len;
}Stack;
Stack* new_Stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->data= NULL;
    stack->index = -1; 
    stack->len = 0;
    return stack;
}
void push(Stack* stack, int elem) {
    if (stack->data== NULL) {
        stack->data = (int*) malloc(sizeof(int));
        stack->len = 1;
    }
    else if (stack->index == stack->len - 1) {
        stack->data = (int*) realloc(stack->data, 2 * stack->len * sizeof(int));
        stack->len *= 2;
    }
    stack->index++;
    stack->data[stack->index]=elem;
}
int pop(Stack* stack) {
    if (stack->index==-1) {
        printf("stack is empty\n");
        return -1;
    }
    else
      {
	int elem = stack->data[stack->index];
	stack->index--;
	if (stack->index == -1) {
	  free(stack->data);
	}
    return elem;
      }
}
int peek(Stack* stack) {
    if (stack->index==-1) {
        printf("stack is empty\n");
        return -1;
    }
    return stack->data[stack->index];
}
int main() {
  Stack* stack =new_Stack();
  push(stack,6);
  push(stack,8);
  printf("%d\n", peek(stack));
  printf("stack's elements are: ");
  for(int i=0;i<stack->len;i++) {
    printf("%d ",stack->data[i]);
  }
  printf("\n");
  printf("poped elem is :%d\n", pop(stack));
  free(stack);
  return 0;
}

