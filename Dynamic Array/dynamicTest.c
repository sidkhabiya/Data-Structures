#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

int getItem(Array *a, int index){
    if (index > a->size || index < 0){
        return -1;
    }
    return (a->array[index]);
}

int setElement(Array *a, int index, int element){
    if (index > a->size || index < 0){
        return -1;
    }
    a->array[index] = element;
}

void removeAtIndex(Array *a, int index){
    for (int i = index; i < a->size; i++){
        a->array[i] = a->array[i+1];
    }
    a->used -= 1;
}

bool removeItem(Array *a, int element){
  for (int i = 0; i < a->used; i++){
    if(a->array[i] == element){
      removeAtIndex(a, i);
      return true;
    }
  }
  return false;
}

int indexOfElement(Array *a, int element){
  for (int i = 0; i < a->used; i++){
    if(a->array[i] == element){
      return i;
    }
  }
  return -1;
}

void printArray(Array *a){
  for (int i = 0; i < a->used; i++){
    if (i == a->used - 1){
      printf("%d]\n", a->array[i]);
    } else if (i == 0) {
      printf("[%d, ", a->array[i]);
    } else {
      printf("%d, ", a->array[i]);
    }
  }
}

int main(){
  Array a;
  int i;

  initArray(&a, 5);
  for (i = 0; i < 60; i++){
    insertArray(&a, i);
  }
  printArray(&a);
  printf("9th element: %d\n", getItem(&a, 9));
  removeAtIndex(&a, 9);
  printf("9th Element after removeAtIndex: %d\n", a.array[9]);
  setElement(&a, 9, 2314);
  printf("9th Element after setElement: %d\n", a.array[9]);
  removeItem(&a, 2314);
  printf("9th Element after removeItem: %d\n", a.array[9]);
  printArray(&a);
  printf("Number of elements in list: %d\n", a.used);
  freeArray(&a);
}