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

typedef struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
} treeNode;

treeNode * maxNode(treeNode *node) {
    if (node == nil) {
        return nil;
    }
    
    if (node->rightNode) {
        treeNode *n = maxNode(node->rightNode);
        return n;
    } else {
        return node;
    }
}

treeNode * minNode(treeNode *node) {
    if (node == nil) {
        return nil;
    }
    
    if (node->leftNode) {
        treeNode *n = minNode(node->leftNode);
        return n;
    } else {
        return node;
    }
}

treeNode * searchNode(treeNode *node, int value) {
    if (node == nil) {
        return nil;
    }
    
    if (value < node->value) {
        treeNode *n = searchNode(node->leftNode, value);
        return n;
    } else if (value > node->value) {
        treeNode *n = searchNode(node->rightNode, value);
        return n;
    } else {
        return node;
    }
}

treeNode * nextLarger(treeNode *node, int value) {
    if (node == nil) {
        return nil;
    }
    
    treeNode *item = searchNode(node, value);
    
    if (item == nil || item->rightNode == nil) {
        return nil;
    }
    
    return item->rightNode;
}

treeNode * nextSmaller(treeNode *node, int value) {
    if (node == nil) {
        return nil;
    }
    
    treeNode *item = searchNode(node, value);
    
    if (item == nil || item->leftNode == nil) {
        return nil;
    }
    
    return item->leftNode;
}

treeNode * insert(treeNode *node, int value) {
    if (node == nil) {
        treeNode *temp;
        temp = (treeNode *)malloc(sizeof(treeNode));
        temp->value = value;
        temp->leftNode = temp->rightNode = nil;
        return temp;
    }
    
    if (value < node->value) {
        node->leftNode = insert(node->leftNode, value);
    } else {
        node->rightNode = insert(node->rightNode, value);
    }
    
    return node;
}

treeNode * delete(treeNode *node, int value) {
    if(node == nil) {
        printf("Item not found\n");
    } else if(value < node->value) {
        node->leftNode = delete(node->leftNode, value);
    } else if(value > node->value) {
        node->rightNode = delete(node->rightNode, value);
    } else {
        if(node->rightNode && node->leftNode) {
            treeNode *temp = minNode(node->rightNode);
            node->value = temp->value;
            node->rightNode = delete(node->rightNode,temp->value);
        } else {
            treeNode *temp = node;
            if(node->leftNode == nil) {
                node = node->rightNode;
            } else if(node->rightNode == nil) {
                node = node->leftNode;
            }
            
            free(temp);
        }
    }
    
    return node;
}

void printInOrder(treeNode *node) {
    if (node == nil) {
        return;
    }
    
    printInOrder(node->leftNode);
    printf("%d ", node->value);
    printInOrder(node->rightNode);
}

int main(int argc, const char * argv[]) {
    treeNode *root = nil;
    
    int insertArray[] = {10, 5, 20, 1, 9, 0, 2, 8, 15, 29};
    int lengthOfArray = sizeof(insertArray) / sizeof(insertArray[0]);
    
    for (int i = 0; i < lengthOfArray; i++) {
        root = insert(root, insertArray[i]);
    }
    
    printInOrder(root); printf("\n");
    
    treeNode *max = maxNode(root);
    treeNode *min = minNode(root);
    
    if (max == nil) {
        printf("No items in this tree\n");
    } else {
        printf("Max is %d\n", max->value);
    }
    
    if (min == nil) {
        printf("No items in this tree\n");
    } else {
        printf("Min is %d\n", min->value);
    }
    
    treeNode *nextL = nextLarger(root, 20);
    treeNode *nextS = nextSmaller(root, 20);
    
    if (nextL == nil) {
        printf("Cannot find next larger\n");
    } else {
        printf("20's next larger is %d\n", nextL->value);
    }
    
    if (nextS == nil) {
        printf("Cannot find next smaller\n");
    } else {
        printf("20's next smaller is %d\n", nextS->value);
    }
    
    root = delete(root, 20);
    
    printInOrder(root);
    
    return 0;
}

/*
 
 Print:
 
 0 1 2 5 8 9 10 15 20 29
 Max is 29
 Min is 0
 20's next larger is 29
 20's next smaller is 15
 0 1 2 5 8 9 10 15 29
 
 */
