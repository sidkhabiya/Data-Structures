#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *root = NULL;
int size = 0;

node *newNode (int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printInOrder(node *root){
    if (root != NULL){
        printInOrder(root->left);
        printf("%d \n", root->data);
        printInOrder(root->right);
    }
}

node *insert(node *node, int data){
    if (node == NULL){
        printf("Successfully inserted %d\n", data);
        size++;
        return newNode(data);
    }
    if (data < node->data){
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

bool search(node *root, int data){
    if (root == NULL){
        return false;
    }
    if (data < root->data){
        return search(root->left, data);
    }else if (data > root->data){
        return search(root->right, data);
    }else{
        return true;
    }
}

node *minTreeValue(node *root){
    node *current = root;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

node *delete(node *root, int data){
    if (search(root, data)){
        if (root == NULL){
            return root;
        }
        if (data < root->data){
            root->left = delete(root->left, data);
        } else if (data > root->data){
            root->right = delete (root->right, data);
        } else {
            if (root->left == NULL){
                node *temp = root->right;
                printf("Successfully deleted: %d\n", root->data);
                size--;
                free(root);
                return(temp);
            } else if (root->right == NULL){
                node *temp = root->left;
                printf("Successfully deleted: %d\n", root->data);
                size--;
                free(root);
                return(temp);
            }
            node *temp = minTreeValue(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        return root;
    }else{
        return root;
    }
}

int main(){
    srand(time(NULL));
    for (int i = 0; i < 30; i++){
        int data = rand() % 100;
        root = insert(root, data);
    }
    printf("Size of BST: %d\n", size);
    printInOrder(root);
    for (int i = 0; i < 50; i++){
        int data = rand() % 100;
        root = delete(root, data);
    }
    printf("Size of BST: %d\n", size);
    printInOrder(root);
}