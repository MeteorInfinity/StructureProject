//
// Created by 孙晨星 on 2017/10/10.
//

#include <stdio.h>
#include <stdlib.h>

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
