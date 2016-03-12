//
//  main.c
//  Binary Search Tree
//
//  Created by Liuliet.Lee on 27/2/2016.
//  Copyright © 2016 Liuliet.Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define nil NULL

struct Node {
    int value;
    int numberOfNodes;
    struct Node *upNode;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *head;

void createTree(int firstValue) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    head = (struct Node*)malloc(sizeof(struct Node));
    
    node->value = firstValue;
    node->numberOfNodes = 1;
    node->upNode = head;
    node->leftNode = nil;
    node->rightNode = nil;

    head->leftNode = node;
}

void InsertNode(int newValue) {
    struct Node *node = head->leftNode;
    
    while (1) {
        node->numberOfNodes++;
        
        if (newValue <= node->value) {
            if (node->leftNode == nil) {
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                
                newNode->value = newValue;
                newNode->numberOfNodes = 1;
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
                newNode->numberOfNodes = 1;
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
    int num = head->leftNode->numberOfNodes;
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
        node->numberOfNodes--;
        
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
                n->numberOfNodes += node->leftNode->numberOfNodes;

                while (n->leftNode != nil) {
                    n = n->leftNode;
                    n->numberOfNodes += node->leftNode->numberOfNodes;
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

void printSortedValues(struct Node *node) {
    if (node->leftNode == nil) {
        printf("\n%d", node->value);
        
        if (node->rightNode != nil) {
            struct Node *n = node->rightNode;
            printSortedValues(n);
            
            return;
        }
    } else {
        struct Node *n = node->leftNode;
        printSortedValues(n);
        
        printf("\n%d", node->value);
    }
    
    if (node->rightNode != nil) {
        struct Node *n = node->rightNode;
        printSortedValues(n);
    }
}

int nextLarger(int item) {
    struct Node *node = head->leftNode;
    
    while (node->value != item) {
        if (item < node->value) {
            if (node->leftNode == nil) {
                printf("Cannot find item!\n");
                return 0;
            }
            
            node = node->leftNode;
        } else {
            if (node->rightNode == nil) {
                printf("Cannot find item!\n");
                return 0;
            }
            
            node = node->rightNode;
        }
    }
    
    if (node->rightNode == nil) {
        printf("This is the largest item of this BST");
        return 0;
    }
    
    return node->rightNode->value;
}

int nextSmaller(int item) {
    struct Node *node = head->leftNode;
    
    while (node->value != item) {
        if (item < node->value) {
            if (node->leftNode == nil) {
                printf("Cannot find item!\n");
                return 0;
            }
            
            node = node->leftNode;
        } else {
            if (node->rightNode == nil) {
                printf("Cannot find item!\n");
                return 0;
            }
            
            node = node->rightNode;
        }
    }
    
    if (node->leftNode == nil) {
        printf("This is the largest item of this BST");
        return 0;
    }
    
    return node->leftNode->value;
}

int main(int argc, const char * argv[]) {
    createTree(10);
    
    int insertArray[] = {5, 20, 1, 9, 0, 2, 8, 15, 29};
    int lengthOfArray = sizeof(insertArray) / sizeof(insertArray[0]);
    for (int i = 0; i < lengthOfArray; i++) {
        InsertNode(insertArray[i]);
    }
    
    int number = numberOfNodes();
    printf("Now the number of nodes in the tree = %d\n", number);
    
    deleteNode(1);
    
    number = numberOfNodes();
    printf("Now the number of nodes in the tree = %d\n", number);

    printf("Min number = %d\n", minTree());
    printf("Max number = %d\n", maxTree());
    
    printf("20's next Larger = %d\n", nextLarger(20));
    printf("20's next smaller = %d\n", nextSmaller(20));
    
    printSortedValues(head->leftNode);
    printf("\n");
    
    return 0;
}

/*
 
 Print:
 
 Now the number of nodes in the tree = 10
 Now the number of nodes in the tree = 9
 Min number = 0
 Max number = 29
 20's next Larger = 29
 20's next smaller = 15
 
 0
 2
 5
 8
 9
 10
 15
 20
 29
 
 */
