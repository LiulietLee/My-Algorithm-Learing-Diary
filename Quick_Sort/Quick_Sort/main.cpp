//
//  main.cpp
//  Quick_Sort
//
//  Created by Liuliet.Lee on 20/4/2016.
//  Copyright © 2016 Liuliet.Lee. All rights reserved.
//

#include <iostream>

using namespace std;

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void quick_Sort(int *arr, int left, int right) {
    int i = left, j = right;
    int mid = arr[(left + right) / 2];
    
    do {
        while (arr[i] < mid && i < right) {
            i++;
        }
        while (arr[j] > mid && j > left) {
            j--;
        }
        
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    } while (i <= j);
    
    if (left < j) {
        quick_Sort(arr, left, j);
    }
    if (right > i) {
        quick_Sort(arr, i, right);
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {1, 3, 2, 4, 6, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    quick_Sort(arr, 0, length - 1);
    
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}
