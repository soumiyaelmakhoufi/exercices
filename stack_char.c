#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char* data;
    int index,len;
} Stack;
Stack* new_Stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->data= NULL;
    stack->index = -1; 
    stack->len = 0;
    return stack;
}
void push(Stack* stack, char elem) {
    if (stack->data== NULL) {
        stack->data = (char*) malloc(sizeof(char));
        stack->len = 1;
    }
    else if (stack->index == stack->len - 1) {
        stack->data = (char*) realloc(stack->data, 2 * stack->len * sizeof(char));
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
	char elem = stack->data[stack->index];
	stack->index--;
	if (stack->index == -1) {
	  free(stack->data);
	}
	else if (stack->index < stack->len / 2) {
	  stack->data = (char*) realloc(stack->data, stack->len / 2 * sizeof(char));
	  stack->len /= 2;
	}
    return elem;
      }
}
char peek(Stack* stack) {
    if (stack->index==-1) {
        printf("stack is empty\n");
        return -1;
    }
    return stack->data[stack->index];
}
int main() {
  Stack* stack =new_Stack();
  push(stack,'S');
  push(stack,'O');
  printf("%c\n", peek(stack));
  printf("stack's elements are: ");
  for(int i=0;i<stack->len;i++) {
    printf("%c ",stack->data[i]);
  }
  printf("\n");
  printf("poped elem is :%c\n", pop(stack));
  free(stack);
  return 0;
}
