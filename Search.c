//
// Created by 孙晨星 on 2017/9/27.
//

#include <stdio.h>

typedef int KeyType;

int BinSearch(const KeyType* R, int n, KeyType K){
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

#define MAXM 3;

typedef struct BTNode *p_BTNode;

struct BTNode{
    int keyNum;
    p_BTNode parent;
    KeyType *key;
    p_BTNode *ptr;
    //Record *recPtr;
};

typedef struct {
    p_BTNode pt;
    int no;
    int flag;
}Result;

int BTNodeSearch(p_BTNode P, KeyType K){
    int i = 0;
    while(i < P->keyNum && P->key[i+1] <= K)
        i++;
    return i;
}

Result BTreeSerach (p_BTNode T, KeyType K){
    p_BTNode p = T, q = NULL;
    int flag = 0, i = 0;

    while (p && !flag){
        i = BTNodeSearch(p, K);
        if(i>0 && p->key[i] == K) {
            flag = 1;
        } else {
            q = p;
            p = p->ptr[i];
        }
    }

    if(flag)
        return {p,i,1}; //查找成功，返回节点与序号
    else
        return {q,i,0}; //查找不成功，返回K的插入位置信息
}