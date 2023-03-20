#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int *arr;
  int front,rear,size,max;
} Queue;

Queue *new_Queue(int max) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->arr = (int *) malloc(sizeof(int) * max);
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->max = max;
    return queue;
}
void push(Queue *queue, int elem) {
  if (queue->size==queue->max){
    queue->max *= 2;
    queue->arr = (int *) realloc(queue->arr, sizeof(int) * queue->max);
  }
  if(queue->size==0) {
        queue->front =queue->rear= 0;
        queue->arr[queue->rear] = elem;
  }
  else {
        queue->rear = (queue->rear + 1) % queue->max;
        queue->arr[queue->rear] = elem;
    }
    queue->size++;
}
int pop(Queue *queue) {
    if (queue->size==0) {
        printf("Queue is empty\n");
        return -1;
    }
    int elem = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->max;
    }
    queue->size--;
    return elem;
}
int peek(Queue *queue) {
  if (queue->front==-1 && queue->rear==-1) {
    printf("Queue is empty\n");
    }
  else{
    return queue->arr[queue->front];
}
}
int main() {
    Queue *queue = new_Queue(1);
    push(queue, 3);
    push(queue, 5);
    push(queue, 100);
    for(int i=0;i<queue->size;i++) {
      printf("%d ",queue->arr[i]);
    }
    printf("\n");
    printf("%d\n",peek(queue));
    printf("poped elem from the queue: %d\n", pop(queue));
    return 0;
}
    
