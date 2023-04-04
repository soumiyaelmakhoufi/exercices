#include <stdio.h>
#include <stdlib.h>
typedef struct s_node {
  int data;
  struct s_node* next;
} node;

void append(node** head, int val) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = val;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  node* ptr = *head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = new_node;
}

void delete(node** head, int val) {
  if (*head == NULL) {
    printf("this linked list is empty\n");
    return;
  }

  node* curr = *head;
  node* prev = NULL;

  while (curr != NULL) {
    if (curr->data == val) {
      if (prev == NULL) {
        *head = curr->next;
        free(curr);
        curr = *head;
      } else {
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
      }
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}

int main() {
  node* head = NULL;
  append(&head, 60);
  append(&head, 13);
  printf("Linked list: ");
  node* ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");

  delete(&head, 13);

  printf("Linked list after: ");
  ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");

  ptr = head;
  while (ptr != NULL) {
    node* temp = ptr;
    ptr = ptr->next;
    free(temp);
  }

  return 0;
}
