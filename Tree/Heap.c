//
// Created by 孙晨星 on 2017/8/22.
//

//
// Created by Meteor on 2017/8/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "_Heap.h"

struct HeapStructure{
    ElemType *Elements;
    int Size;
    int Capacity;
};

int IsHeapFull(p_Heap H){
    if(!H) return 0;
    return H->Size >= H->Capacity? 1: 0;
}

int IsHeapEmpty(p_Heap H){
    if(!H) return 0;
    return H->Size == 0? 1: 0;
}

void VisitHeap(p_Heap H){
    if(!H) return;
    int P = 1;
    while (P <= H->Size){
        printf("%d ", H->Elements[P++]);
    }
    printf("\n");
}

p_Heap CreateHeap(int MaxSize){
    p_Heap H = (p_Heap)malloc(sizeof(struct Heap_t));
    if(!H) return NULL;
    H->Elements = (ElemType*)malloc((MaxSize+1) * sizeof(ElemType));
    if(!H->Elements) return NULL;
    H->Capacity = MaxSize;
    H->Size = 0;
    return H;
}

int InsertHeap(p_Heap H, ElemType E){
    if(IsHeapFull(H)) return 0;
    int i = ++H->Size;
    //while(H->Elements[i/2] < E && i > 1){     // MaxHeap
    while(H->Elements[i/2] > E && i > 1){       // MinHeap
        H->Elements[i] = H->Elements[i/2];
        i/=2;
    }
    H->Elements[i] = E;
    return 1;
}

ElemType DeleteHeap(p_Heap H){
    int parent, child;
    ElemType item, temp;
    if(IsHeapEmpty(H)) return 0;
    item = H->Elements[1];
    temp = H->Elements[H->Size--];
    for(parent = 1; parent*2 <= H->Size; parent = child){
        child = parent*2;
        //if((child != H->Size) && (H->Elements[child] < H->Elements[child+1]))  // MaxHeap
        if((child != H->Size) && (H->Elements[child] > H->Elements[child+1]))    // MinHeap
            child++;
        if(temp >= H->Elements[child])
            break;
        else
            H->Elements[parent] = H->Elements[child];
    }
    H->Elements[parent] = temp;
    return item;
}

void RegulateHeap(p_Heap H, int length, int child){
    ElemType Tmp;
    int parent = child/2;
    if(parent<1) return;
    //if(H->Elements[parent] < H->Elements[child]) {    // MaxHeap
    if(H->Elements[parent] > H->Elements[child]) {      // MinHeap
        Tmp = H->Elements[parent];
        H->Elements[parent] = H->Elements[child];
        H->Elements[child] = Tmp;
    }
    if(child * 2 + 1 <= length) RegulateHeap(H, length, child*2+1);
    if(child*2 <= length) RegulateHeap(H, length, child*2);
}

p_Heap CreateHeapByArr(int arr[], int length){
    if(!arr[length-1]) return NULL;
    p_Heap H = CreateHeap(length);
    for(int i = 0; i<length; i++){
        H->Elements[i+1] = (ElemType)malloc(sizeof(int));
        H->Elements[i+1] = arr[i];
        H->Size++;
    }
    for(int child = length; child > 0; child--){
        RegulateHeap(H, length, child);
    }
    H->Size = length;
    return H;
}
