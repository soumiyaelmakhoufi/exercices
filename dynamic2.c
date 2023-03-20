#include <stdio.h>
#include <stdlib.h>
struct list{
  char* arr1;
  int len;
};
void append(struct list *PTR,char elem)
{
  char* arr2=(char*)malloc(sizeof(char)*(PTR->len+1));
  for(int i=0;i<PTR->len;i++)
    arr2[i]=PTR->arr1[i];
  free(PTR->arr1);
  PTR->arr1 =arr2;
  PTR->arr1[PTR->len]= elem;
  PTR->len+=1;
}
int main() {
  struct list PTR;
  PTR.len =0;
  PTR.arr1 =(char*)malloc(sizeof(char)*0);
  append(&PTR, 'k');
  append(&PTR, 'f');
  append(&PTR, 'g');
  for(int i=0;i<PTR.len;i++)
    printf("%c ",PTR.arr1[i]);
  printf("\n");
}
 
