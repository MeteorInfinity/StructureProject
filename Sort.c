//
// Created by 孙晨星 on 2017/10/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "Tree/_Heap.h"

void Bubble_Sort(int A[], int n){
    int flag,tmp;
    for (int p = n-1; p >= 0; p--) {
        flag = 0;
        for (int i = 0; i < p; ++i) {
            if(A[i] > A[i+1]) {
                tmp = A[i+1];
                A[i+1] = A[i];
                A[i] = tmp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

void Insertion_Sort(int A[], int n){
    int tmp,i;
    for (int p = 1; p < n; ++p) {
        tmp = A[p]; // 下一位
        for (i = p; i>0 && A[i-1]>tmp; i--) {
            A[i] = A[i-1]; // 移出空位
        }
        A[i] = tmp; // 插入落位
    }
}

void MidInsertion_Sort(int A[], int n){
    int tmp, low, high, mid;
    for (int i = 1; i < n; ++i) {
        tmp = A[i]; // 下一位
        low = 0;
        high = i-1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (tmp < A[mid]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i-1; j >= high + 1; j--) {
            A[j+1] = A[j];
        }
        A[high+1] = tmp; // 插入落位
    }
}

void Shell_Sort(int A[], int n){
    int tmp,i;
    for (int d = n/2; d > 0; d/=2) {
        for (int p = d; p < n; p++) {
            tmp = A[p]; // 下一位
            for (i = p; i>=d && A[i-d]>tmp; i-=d) {
                A[i] = A[i-d]; // 移出空位
            }
            A[i] = tmp; // 插入落位
        }
    }
}

void Quick_sort(int A[], int low, int high) {
    int i = low;
    int j = high;
    if(i < j){
        int tmp = A[i];
        while(i != j){
            while(i<j && A[j]>=tmp) // 从右到左找到第一个小于tmp的值
                j--;
            A[i] = A[j];
            while(i<j && A[i]<=tmp) // 从左到右找到第一个大于tmp的值
                i++;
            A[j] = A[i];
        }
        A[i] = tmp;
        Quick_sort(A, low, i-1);
        Quick_sort(A, i+1, high);
    }
}

void Select_Sort(int A[], int n){
    int min, tmp;
    for (int i = 0; i < n; ++i) {
        min = A[0];
        for (int j = 1; j < n; ++j) {
            if(A[j] > min)
                min = A[j];
        }
        tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
    }
}

void Heap_Sort0(int A[], int n){
    p_Heap heap = CreateHeapByArr(A, n);
    for (int i = 0; i < n; ++i) {
        A[i] = DeleteHeap(heap);
    }
}