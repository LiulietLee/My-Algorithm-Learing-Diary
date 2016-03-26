//
//  main.c
//  Hashing with Chaining
//
//  Created by Liuliet.Lee on 26/3/2016.
//  Copyright © 2016 Liuliet.Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define nil NULL
#define SIZE 100

typedef struct Node {
    int key;
    int value;
    struct Node *nextNode;
} Node;

Node hashTable[SIZE];

void insert(int key, int value) {
    int index = key % SIZE;
    
    if (hashTable[index].value == 0) {
        hashTable[index].key = key;
        hashTable[index].value = value;
        hashTable[index].nextNode = nil;
    } else {
        Node *next = (Node *)malloc(sizeof(Node));
        Node *last = &hashTable[index];
        
        next->key = key;
        next->value = value;
        next->nextNode = nil;

        while (last->nextNode) {
            last = last->nextNode;
        }
        
        last->nextNode = next;
    }
}

void deleteFromChaining(Node *node, int key) {
    if (!node->nextNode) {
        printf("Cannot find item\n");
        return;
    }
    
    if (node->nextNode->key == key) {
        Node *temp = node->nextNode;
        node->nextNode = temp->nextNode;
        free(temp);
    } else {
        deleteFromChaining(node->nextNode, key);
    }
}

void delete(int key) {
    int index = key % SIZE;
    
    if (index == key) {
        if (hashTable[index].nextNode) {
            hashTable[index] = *hashTable[index].nextNode;
        } else {
            hashTable[index].key = 0;
            hashTable[index].value = 0;
        }
    } else {
        Node *node = &hashTable[index];
        deleteFromChaining(node, key);
    }
}

Node * searchFromChaining(Node *node, int key) {
    Node *next = node->nextNode;
    
    if (!next) {
        printf("This key has no value.\n");
        return nil;
    }
    
    if (next->key == key) {
        return next;
    } else {
        return searchFromChaining(next, key);
    }
}

int search(int key) {
    int index = key % SIZE;
    if (index == key) {
        if (hashTable[index].value == 0) {
            printf("This key has no value.\n");
        }
        
        return hashTable[index].value;
    } else {
        Node *result = searchFromChaining(&hashTable[index], key);
        
        if (result) {
            return result->value;
        } else {
            return 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < SIZE * 3; i++) {
        insert(i, i);
    }
    
    int result = search(123);
    printf("key(123) = %d\n", result);
    
    delete(123);
    result = search(123);
    
    delete(3000);
    
    return 0;
}

/*
 
 Print:
 
 key(123) = 123
 This key has no value.
 Cannot find item
 
 */
