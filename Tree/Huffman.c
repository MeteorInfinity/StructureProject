//
// Created by 孙晨星 on 2017/9/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "_Heap.h"

struct HuffmanTreeNode;
typedef struct HuffmanTreeNode *p_HTNode;

struct HeapStructure{
    KeyType *Elements;
    int Size;
    int Capacity;
};

typedef struct HuffmanTreeNode{
    int weight;
    p_HTNode leftChild;
    p_HTNode rightChild;
}HTNode;

p_HTNode CreateHuffmanTree(int Arr[],int length){
    p_Heap H = CreateHeapByArr(Arr, length);
    p_HTNode N, node[10000];
    for (int j = 0; j < length; ++j) {
        node[j] = (p_HTNode)malloc(sizeof(HTNode));
        node[j]->weight = Arr[j];
    }
    int size = H->Size;
    for (int i = 1; i < size; i++) {
        N = (p_HTNode)malloc(sizeof(HTNode));
        N->leftChild = node[DeleteHeap(H)];
        N->rightChild = node[DeleteHeap(H)];
        N->weight = N->leftChild->weight + N->rightChild->weight;
        node[N->weight] = N;
        printf("%d ", N->weight);
        InsertHeap(H, N->weight);
    }
    return node[DeleteHeap(H)];
}

void PreOrderTraverse(p_HTNode N){
    if(N == NULL) return;
    if(N->rightChild == NULL && N->leftChild == NULL){
        printf("%d ", N->weight);
        return;
    }
    if(N->leftChild != NULL)
        PreOrderTraverse(N->leftChild);
    if(N->rightChild != NULL)
        PreOrderTraverse(N->rightChild);
}
