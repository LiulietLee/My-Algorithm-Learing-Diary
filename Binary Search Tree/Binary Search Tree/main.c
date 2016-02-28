//
//  main->c
//  Binary Search Tree
//
//  Created by Liuliet->Lee on 27/2/2016->
//  Copyright © 2016 Liuliet->Lee-> All rights reserved->
//

#include <stdio.h>
#include <stdlib.h>

#define nil NULL

struct Node {
    int value;
    int numberOfSubtree;
    struct Node *upNode;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *head;

void createTree(int firstValue) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));
    
    node->value = firstValue;
    node->numberOfSubtree = 1;
    node->upNode = head;
    node->leftNode = nil;
    node->rightNode = nil;

    head->leftNode = node;
}

void InsertNode(int newValue) {
    struct Node *node = head->leftNode;
    
    while (1) {
        node->numberOfSubtree++;
        
        if (newValue <= node->value) {
            if (node->leftNode == nil) {
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                
                newNode->value = newValue;
                newNode->numberOfSubtree = 1;
                newNode->upNode = node;
                newNode->leftNode = nil;
                newNode->rightNode = nil;
                
                node->leftNode = newNode;
                
                break;
            } else {
                node = node->leftNode;
            }
        } else {
            if (node->rightNode == nil) {
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                
                newNode->value = newValue;
                newNode->numberOfSubtree = 1;
                newNode->upNode = node;
                newNode->leftNode = nil;
                newNode->rightNode = nil;
                
                node->rightNode = newNode;
                
                break;
            } else {
                node = node->rightNode;
            }
        }
    }
}

int numberOfNodes() {
    int num = head->leftNode->numberOfSubtree;
    return num;
}

int findValue(int value) {
    struct Node *node = head->leftNode;

    while (1) {
        if (value < node->value) {
            if (node->leftNode == nil) {
                printf("Cannot find value %d\n", value);
                return -1;
            } else {
                node = node->leftNode;
            }
        } else if (value > node->value) {
            if (node->rightNode == nil) {
                printf("Cannot find value %d\n", value);
                return -1;
            } else {
                node = node->rightNode;
            }
        } else {
            return 1;
        }
    }
}

int deleteNode(int valueOfNode) {
    struct Node *node = head->leftNode;
    int isExist = findValue(valueOfNode);
    
    if (isExist == -1) {
        return -1;
    }
    
    int leftOrRight = 0;
    
    while (1) {
        node->numberOfSubtree--;
        
        if (valueOfNode < node->value) {
            node = node->leftNode;
            leftOrRight = 0;
        } else if (valueOfNode > node->value) {
            node = node->rightNode;
            leftOrRight = 1;
        } else {
            if (node->leftNode == nil && node->rightNode == nil) {
                if (leftOrRight == 0) {
                    node->upNode->leftNode = nil;
                } else {
                    node->upNode->rightNode = nil;
                }

                free(node);
                return 1;
            } else if (node->rightNode == nil) {
                node->leftNode->upNode = node->upNode;
                
                if (leftOrRight == 0) {
                    node->upNode->leftNode = node->leftNode;
                } else {
                    node->upNode->rightNode = node->leftNode;
                }
                
                free(node);
                return 1;
            } else if (node->leftNode == nil) {
                node->rightNode->upNode = node->upNode;
                
                if (leftOrRight == 0) {
                    node->upNode->leftNode = node->rightNode;
                } else {
                    node->upNode->rightNode = node->rightNode;
                }

                free(node);
                return 1;
            } else {
                struct Node *n = node->rightNode;
                n->numberOfSubtree += node->leftNode->numberOfSubtree;

                while (n->leftNode != nil) {
                    n = n->leftNode;
                    n->numberOfSubtree += node->leftNode->numberOfSubtree;
                }
                
                node->leftNode->upNode = n;
                n->leftNode = node->leftNode;
                
                node->rightNode->upNode = node->upNode;
                
                if (leftOrRight == 0) {
                    node->upNode->leftNode = node->rightNode;
                } else {
                    node->upNode->rightNode = node->rightNode;
                }
                
                free(node);
                return 1;
            }
        }
    }
}

int minTree() {
    struct Node *node = head->leftNode;
    
    while (node->leftNode != nil) {
        node = node->leftNode;
    }
    
    return node->value;
}

int maxTree() {
    struct Node *node = head->leftNode;
    
    while (node->rightNode != nil) {
        node = node->rightNode;
    }
    
    return node->value;
}

int main(int argc, const char * argv[]) {
    createTree(10);
    
    int insertArray[] = {1, 2, 20, 19, 18, 21};
    int lengthOfArray = sizeof(insertArray) / sizeof(insertArray[0]);
    for (int i = 0; i < lengthOfArray; i++) {
        InsertNode(insertArray[i]);
    }
    
    int number = numberOfNodes();
    printf("Now the number of nodes in the tree = %d\n", number);
    
    deleteNode(20);

    number = numberOfNodes();
    printf("Now the number of nodes in the tree = %d\n", number);

    deleteNode(1);
    
    number = numberOfNodes();
    printf("Now the number of nodes in the tree = %d\n", number);

    printf("Min number = %d\n", minTree());
    printf("Max number = %d\n", maxTree());

    return 0;
}

/*
 
 Print:
 
 Now the number of nodes in the tree = 7
 Now the number of nodes in the tree = 6
 Now the number of nodes in the tree = 5
 Min number = 2
 Max number = 21
 
 */
