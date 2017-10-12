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

void Heap_Sort_Low(int A[], int n){
    p_Heap heap = CreateHeapByArr(A, n);
    for (int i = 0; i < n; ++i) {
        A[i] = DeleteHeap(heap);
    }
}

// 筛选法建立最大堆
void Heap_Sift(int A[], int low, int high){
    int i = low, j = 2 * i; // A[j]是A[i]的左孩子
    int tmp = A[i];
    while (j <= high){
        if(j < high && A[j] < A[j+1]) // 若右孩子较大，将j指向右孩子
            j++;
        if(tmp < A[j]){
            A[i] = A[j]; // 将A[j]调整到双亲节点
            i = j; // 继续向下筛选
            j = i * 2;
        }else{
            break;
        }
    }
    A[i] = tmp;
}

void Heap_Sort(int A[], int n){
    int i, tmp;
    for(i = n/2; i >= 1; i--){
        Heap_Sift(A, i , n);
    }
    for(i = n; i > 1; i--){
        tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        Heap_Sift(A, 1, i-1);
    }
}

// 筛选法建立最大堆(从零开始)
void Heap_Sift_0(int A[], int low, int high){
    int i = low, j = 2 * (i + 1) - 1; // A[j]是A[i]的左孩子
    int tmp = A[i];
    while (j <= high){
        if(j < high && A[j] < A[j+1]) // 若右孩子较大，将j指向右孩子
            j++;
        if(tmp < A[j]){
            A[i] = A[j]; // 将A[j]调整到双亲节点
            i = j; // 继续向下筛选
            j = 2 * (i + 1) - 1;
        }else{
            break;
        }
    }
    A[i] = tmp;
}

void Heap_Sort_0(int A[], int n){
    int i, tmp;
    for(i = n/2; i >= 0; i--){
        Heap_Sift_0(A, i , n);
    }
    for(i = n-1; i > 0; i--){
        tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        Heap_Sift_0(A, 1, i);
    }
}

void Merge(int A[], int C[], int L, int R, int RE){
    int LE = R - 1;
    int num = RE - L + 1;
    int tmp = L;
    while(L <= LE && R <= RE){
        if(A[L] <= A[R])
            C[tmp++] = A[L++];
        else
            C[tmp++] = A[R++];
        //C[tmp++] = A[L] <= A[R]? A[L++]: A[R++];
    }
    while(L <= LE)
        C[tmp++] = A[L++];
    while(R <= RE)
        C[tmp++] = A[R++];
    for (int i = 0; i < num; ++i, RE--) {
        A[RE] = C[RE];
    }
}

void MSort(int A[], int C[], int L, int RE){
    int center;
    if(L < RE){
        center = (L + RE) / 2;
        MSort(A, C, L, center);
        MSort(A, C, center+1, RE);
        Merge(A, C, L, center+1, RE);
    }
}

void Merge_Sort(int A[], int n){
    int *C = (int*)malloc(n * sizeof(int));
    if(C == NULL) return;
    MSort(A, C , 0, n-1);
    free(C);
}

void Merge_UR(int A[], int C[], int L, int R, int RE){
    int LE = R - 1;
    int num = RE - L + 1;
    int tmp = L;
    while(L <= LE && R <= RE){
        if(A[L] <= A[R])
            C[tmp++] = A[L++];
        else
            C[tmp++] = A[R++];
        //C[tmp++] = A[L] <= A[R]? A[L++]: A[R++];
    }
    while(L <= LE)
        C[tmp++] = A[L++];
    while(R <= RE)
        C[tmp++] = A[R++];
}

void Merge_Pass(int A[], int C[], int n, int length){
    int i;
    for(i = 0; i <= n-2*length; i += 2*length)
        Merge_UR(A, C, i, i+length, i+2*length-1);
    if(i+length < n)
        Merge_UR(A, C, i, i+length, n-1);
    else
        for(int j = i; j < n; j++)
            C[j] = A[j];
}

void Merge_Sort_RC(int A[], int n){
    int length = 1;
    int *C = (int*)malloc(n * sizeof(int));
    if(C == NULL) return;
    while(length < n){
        Merge_Pass(A, C, n, length);
        length *= 2;
        Merge_Pass(C, A, n, length);
        length *= 2;
    }
    free(C);
}





