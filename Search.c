//
// Created by 孙晨星 on 2017/9/27.
//

#include <stdio.h>
#include <stdlib.h>

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

#define MAXM 3

typedef struct BTNode *p_BTNode;

struct BTNode{
    int keyNum;
    p_BTNode parent;
    KeyType key[MAXM];
    p_BTNode ptr[MAXM];
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
        i = 0;
        while(i < p->keyNum && p->key[i+1] <= K)
            i++;
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

void BTNodeInsert(p_BTNode q, int i, KeyType K, p_BTNode ap){
    for (int j = q->keyNum-1; j >= i+1; --j) {
        q->key[j+1] = q->key[j];
        q->ptr[j+1] = q->ptr[j];
    }
    q->key[i+1] = K;
    q->ptr[i+1] = ap;
    q->keyNum++;
}

int BTreeInsert(p_BTNode T, KeyType K){
    Result R = BTreeSerach(T, K);
    if(R.flag) return 0;
    p_BTNode q = R.pt, ap = NULL;
    int i = R.no, tmp = K, flag = 0;
    while(q && !flag){
        for (int j = q->keyNum-1; j >= i+1; --j) {
            q->key[j+1] = q->key[j];
            q->ptr[j+1] = q->ptr[j];
        }
        q->key[i+1] = tmp;
        q->ptr[i+1] = ap;
        q->keyNum++;

        // BTNodeInsert(q, i, K, ap);

        if(q->keyNum < MAXM) {      // 插入完成
            flag = 1;
        } else {                    // 分裂节点
            ap = (p_BTNode)malloc(sizeof(struct BTNode));
            int m = 0;
            ap->ptr[m++] = q->ptr[MAXM/2];
            for (int j = MAXM/2+1; j < q->keyNum; ++j) {
                ap->key[m] = q->key[j];
                ap->ptr[m] = q->ptr[j];
            }
            tmp = q->key[MAXM/2];
            q = q->parent;
            if(q) i = BTNodeSearch(q, tmp);
        }
    }
    if(!flag){
        p_BTNode N = (p_BTNode)malloc(sizeof(struct BTNode));
        N->keyNum = 1;
        N->key[1] = tmp;
        N->ptr[0] = T;
        N->ptr[1] = ap;
    }
    return 1;
}