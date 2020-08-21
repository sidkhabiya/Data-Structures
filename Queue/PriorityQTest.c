#include <stdio.h>
#include <stdlib.h>

int heap_size = 0; //global var for heap size
int arr_size = 20; //global var for array size

//prints values in heap
void printHeap(int arr[]){
    for (int i = 0; i < heap_size; i++){
        if(i == 0){
            printf("[%d, ", arr[i]);
        } else if (i == heap_size - 1){
            printf("%d]\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

//swaps two elements in array
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

//return index of left child of given index
int left_child(int index){
    if ((2*index) < heap_size && index >= 0){
        return (2*index) + 1;
    }
}

//return index of right child of given index
int right_child(int index){
    if ((2*index) < heap_size && index >= 0){
        return (2*index) + 2;
    }
}

//returns parent of given index
int parent(int index){
    if (index <= heap_size && index > 0){
        return (index-1)/2;
    }
}

//moves values down the min binary heap
void bubble_down(int arr[], int index){
    int left_index = left_child(index);
    int right_index = right_child(index);
    int smallest_index = index;
    if ((left_index <= heap_size) && (arr[left_index] < arr[smallest_index])){
        smallest_index = left_index;
    }
    if ((right_index <= heap_size) && (arr[right_index] < arr[smallest_index])){
        smallest_index = right_index;
    }
    if (smallest_index != index){
        swap(arr, index, smallest_index);
        bubble_down (arr, smallest_index);
    }
}

//moves values up the min binary heap
void bubble_up(int arr[], int index){
    if (index == 0){
        return;
    }
    int smallest_index = index;
    int parent_index = parent(index);
    if (arr[smallest_index] < arr[parent_index]){
        swap (arr, parent_index, smallest_index);
        bubble_up(arr, parent_index);
    }
}

//remove value at specific index
void removeAt(int arr[], int index){
    int data = arr[index];
    heap_size--;
    arr[index] = arr[heap_size];
    bubble_down(arr, index);
    printf("Successfully removed element: %d\t\tHeap size: %d\n", data, heap_size);
}

//insert value to heap
void insert(int arr[], int element){
    if (heap_size >= arr_size){
        printf("Heap is full!\n");
        return;
    }
    arr[heap_size] = element;
    bubble_up(arr, heap_size);
    heap_size++;
    printf("Successfully inserted element: %d\tHeap size: %d\n", element, heap_size);
}

//removes value at top index
void removemin(int arr[]){
    removeAt(arr, 0);
}

//test code
int main(){
    int arr[arr_size];
    insert(arr, 11);
    insert(arr, 6);
    insert(arr, 10);
    insert(arr, 2);
    insert(arr, 5);
    insert(arr, 100);
    insert(arr, 2);
    insert(arr, 42);
    printHeap(arr);
    removemin(arr);
    printHeap(arr);
    insert(arr, 2);
    insert(arr, 2);
    insert(arr, 7);
    insert(arr, 315);
    insert(arr, 15);
    insert(arr, 135);
    insert(arr, 24);
    insert(arr, 63);
    printHeap(arr);
    removeAt(arr, 9);
    printHeap(arr);
}