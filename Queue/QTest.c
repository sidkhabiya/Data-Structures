#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int front, back, size; 
    unsigned capacity; 
    int* array;
} Queue;

//Creates Queue
Queue* createQueue(unsigned capacity) 
{ 
    Queue* q = (Queue*)malloc(sizeof(Queue)); 
    q->capacity = capacity; 
    q->front = q->size = 0;  
    q->back = capacity - 1; 
    q->array = (int*)malloc(q->capacity * sizeof(int)); 
    return q; 
}

//Checks is queue is full
bool isFull(Queue *q){
    return q->size == q->capacity;
}

//Checks is queue is empty
bool isEmpty(Queue *q){
    return q->size == 0;
}

//Returns value in the front of queue
int peek(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty!\n");
    }
    return q->array[q->front];
}

//Returns value at back of queue
int back(Queue *q){
        if (isEmpty(q)){
        printf("Queue is empty!\n");
    }
    return q->array[q->back];
}

//Adds an item to back of queue
void enqueue(Queue *q, int item){
    if (isFull(q)){
        q->capacity *= 2;
        q->array = realloc(q->array, q->capacity * sizeof(int));
    }
    q->back = (q->back + 1) % q->capacity; 
    q->array[q->back] = item; 
    q->size++;
    printf("%d has been enqueued successfully\n", item);
}

//Returns item in front of queue
int dequeue(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty!\n");
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

void delete(Queue *q){
    free(q);
    printf("Queue Deleted!");
}

int main(){
    Queue *q = createQueue(2);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);
    printf("%d dequeued from queue\n",dequeue(q));
    printf("Size of queue is: %d\n", q->size);
    printf("Front item is %d\n", peek(q));
    printf("Rear item is %d\n", back(q));
    delete(q);
    return 0;
}
