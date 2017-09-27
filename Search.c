//
// Created by 孙晨星 on 2017/9/27.
//

#include <stdio.h>

typedef int ElemType;

int BinSearch(const ElemType* R, int n, ElemType K){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(R[mid] == K)
            return mid+1;
        if(R[mid] > K)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}
