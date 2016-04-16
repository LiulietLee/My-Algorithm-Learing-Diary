//
//  main.cpp
//  Merge Sort
//
//  Created by Liuliet.Lee on 16/4/2016.
//  Copyright © 2016 Liuliet.Lee. All rights reserved.
//

#include <iostream>

using namespace std;

void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

int main()
{
    int a[5] = {5, 4, 3, 2, 1};

    mergesort(a, 0, 4);
    
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i];
    }
}
