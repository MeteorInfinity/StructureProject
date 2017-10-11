//
// Created by 孙晨星 on 2017/8/22.
//

#ifndef _HEAP_H
#define _HEAP_H
//
// Created by Meteor on 2017/8/18.
//

typedef struct HeapStructure *p_Heap;

typedef int KeyType;

int IsHeapFull(p_Heap H);

int IsHeapEmpty(p_Heap H);

void VisitHeap(p_Heap H);

p_Heap CreateHeap(int MaxSize);

int InsertHeap(p_Heap H, KeyType E);

KeyType DeleteHeap(p_Heap H);

void RegulateHeap(p_Heap H, int length, int child);

p_Heap CreateHeapByArr(int arr[], int length);

p_Heap CreateHeapByArr2(int arr[], int i, int j);

#endif //_HEAP_H
