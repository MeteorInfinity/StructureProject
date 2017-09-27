//
// Created by 孙晨星 on 2017/8/22.
//

#ifndef _HEAP_H
#define _HEAP_H
//
// Created by Meteor on 2017/8/18.
//

typedef struct HeapStructure *p_Heap;

typedef int ElemType;

int IsHeapFull(p_Heap H);

int IsHeapEmpty(p_Heap H);

void VisitHeap(p_Heap H);

p_Heap CreateHeap(int MaxSize);

int InsertHeap(p_Heap H, ElemType E);

ElemType DeleteHeap(p_Heap H);

void RegulateHeap(p_Heap H, int length, int child);

p_Heap CreateHeapByArr(int arr[], int length);


#endif //_HEAP_H
