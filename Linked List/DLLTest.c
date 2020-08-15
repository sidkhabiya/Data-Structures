#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node  {
    int key;
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* current = NULL;

//returns whether list is empty
bool isEmpty(){
    return head == NULL;
}

//returns length of linked list
int length() {
    int length = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next){
        length ++;
    }
    return length;
}

struct node* GetNewNode(int key, int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a node at head
void InsertAtHead(int key, int data) {
	struct node* newnode = GetNewNode(key, data);
	if(isEmpty()) {
		head = newnode;
        tail = newnode;
        printf("Successfully inserted data: %d with key: %d at the head\n", head->data, head->key);
        return;
	}
	head->prev = newnode;
	newnode->next = head;
	head = newnode;
    printf("Successfully inserted data: %d with key: %d at the head\n", head->data, head->key);
    return;
}

//Inserts a node at tail
void InsertAtTail(int key, int data) {
	struct node* newnode = GetNewNode(key, data);;
	if(isEmpty()) {
		head = newnode;
        tail = newnode;
        printf("Successfully inserted data: %d with key: %d at the tail\n", tail->data, tail->key);
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
	tail = newnode;
    printf("Successfully inserted data: %d with key: %d at the tail\n", tail->data, tail->key);
    return;
}

//Inserts node at specific key
void insertAfter(int key, int newKey, int data){
    struct node *current = head; 
    if(isEmpty()) { //list is empty
        printf("List is empty!\n");
    }
    while(current->key != key) {
        if (current->next == NULL){
            printf("Key not found!");
            return;
        } else {
            current = current->next;
        }
    }
    if (current->key == head->key){
        InsertAtHead(newKey, data);
    } else if (current->key == tail->key){
        InsertAtTail(newKey, data);
    } else {
        struct node *newnode = GetNewNode(newKey, data);
        newnode->next = current->next;         
        current->next->prev = newnode;
        newnode->prev = current;
        current->next = newnode;
        printf("Successfully inserted data: %d with key: %d\n", newnode->data, newnode->key); 
    }
    return;
}

//Deleted node at head
void deleteAtHead(){
    struct node *toDelete = head;
    if(head->next == NULL){ //list has one node
        tail = NULL;
    } else if (isEmpty()){ //list is empty
        printf("List is empty!\n");
        return;
    } else {
        head->next->prev = NULL;
    }
    head = head->next;
    printf("(Key, Data) to be deleted: (%d, %d)\n", toDelete->key, toDelete->data);
    free(toDelete);
    printf("Successfully deleted node at head of list!\n");
    return;
}

//Deletes node at tail
void deleteAtTail(){
    struct node *toDelete = tail;
    if(head->next == NULL) { //list has one node
        head = NULL;
    } else if (isEmpty()){ //list is empty
        printf("List is empty!\n");
        return;
    } else {
        tail->prev->next = NULL;
    }
    tail = tail->prev;
    printf("(Key, Data) to be deleted: (%d, %d)\n", toDelete->key, toDelete->data);
    free(toDelete);
    printf("Successfully deleted node at tail of list!\n");
    return;
}

//Deletes node at specific key
void delete(int key){
    struct node *toDelete = head;
    while (toDelete->key != key){
        if (toDelete->next == NULL){
            printf("Key not found!");
            return;
        } else {
            toDelete = toDelete->next;
        }
    }
    if (toDelete->key == head->key){
        deleteAtHead();
        free(toDelete);
    } else if (toDelete->key == tail->key){
        deleteAtTail();
        free(toDelete);
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        printf("(Key, Data) to be deleted: (%d, %d)\n", toDelete->key, toDelete->data);
        free(toDelete);
        printf("Successfully deleted node in list!\n");
    }
    return;
}

//Prints all the elements in linked list in forward traversal order
void printList() {
	struct node* temp = head;
	while(temp != NULL) {
		printf("(%d, %d) ", temp->key, temp->data);
		temp = temp->next;
	}
    printf("\n");
    return;
}

//Prints all elements in linked list in reverse traversal order. 
void reversePrint() {
	struct node* temp = tail;
	while(temp != NULL) {
		printf("(%d, %d) ", temp->key, temp->data);
		temp = temp->prev;
	}
    printf("\n");
    return;
}

int main() {
    InsertAtHead(1,10);
    InsertAtHead(2,20);
    InsertAtHead(3,30);
    InsertAtHead(4,1);
    InsertAtHead(5,40);
    InsertAtHead(6,56);
    InsertAtTail(0,70);

    printf("List (First to Last): ");  
    printList();

    printf("List (Last to first): "); 
    reversePrint();

    deleteAtHead();        
    printf("List after deleting head: ");
    printList();

    deleteAtTail();
    printf("List after deleting tail: ");
    printList();
 
    insertAfter(4,7,13);
    printf("List after insertion of key(4): "); 
    printList();

    delete(4);
    printf("List after deletion of key(4): ");  
    printList();
}