#include <stdio.h>
#include <stdlib.h>
struct list{
  int* arr1;
  int len;
};
void append(struct list * PTR,int elem)
{
  int* arr2=(int*)malloc(sizeof(int)*(PTR->len+1));
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
  PTR.arr1 =(int*)malloc(sizeof(int)*0);
  append(&PTR, 5);
  append(&PTR, 34);
  append(&PTR, 67);
  for(int i=0;i<PTR.len;i++)
    printf("%d ",PTR.arr1[i]);
  printf("\n");
  return 0;
}
 
