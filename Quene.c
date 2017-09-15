//
// Created by 孙晨星 on 2017/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include "_Quene.h"

struct QueneStructure{
    int Capacity;
    int Front;
    int Rear;
    int Length;
    ElemType *Elements;
};

static int Succ(p_Quene Q, int Value){
    return ++Value == Q->Capacity? 0: Value;
}

int IsQueneEmpty(p_Quene Q){
    return Q->Length == 0;
}

int IsQueneFull(p_Quene Q){
    return Q->Length == Q->Capacity;
}

p_Quene CreatQuene(int MaxElements){
    if(MaxElements<10) MaxElements = 10;
    p_Quene Q = (p_Quene)malloc(sizeof(struct QueneStructure));
    if(!Q){
        printf("Create p_Quene Error: Memmory Fault\n");
        return NULL;
    }
    Q->Elements = (ElemType*)malloc(MaxElements * sizeof(ElemType));
    if(!Q->Elements){
        printf("Create p_Quene Elements Error: Memmory Fault\n");
        return NULL;
    }
    Q->Front = 1;
    Q->Rear = 0;
    Q->Length = 0;
    Q->Capacity = MaxElements;
    return Q;
}

int DisposeQuene(p_Quene Q){
    free(Q->Elements);
    free(Q);
    return 1;
}

int MakeEmpty(p_Quene Q){
    Q->Front = 1;
    Q->Rear = 0;
    Q->Length = 0;
    return 1;
}

int EnQuene(p_Quene Q, ElemType E){
    if(IsQueneFull(Q)){
        printf("EnQuene Error: p_Quene Full\n");
        return 0;
    }
    Q->Length++;
    Q->Rear = Succ(Q, Q->Rear);
    Q->Elements[Q->Rear] = E;
    return 1;
}

ElemType FrontQuene(p_Quene Q){
    if(IsQueneEmpty(Q)){
        printf("FrontQuene Error: p_Quene Umpty\n");
        return NULL;
    }
    return Q->Elements[Q->Front];
}

int DeQuene(p_Quene Q){
    if(IsQueneEmpty(Q)){
        printf("DeQuene Error: p_Quene Umpty\n");
        return 0;
    }
    Q->Length--;
    Q->Front = Succ(Q, Q->Front);
    return 1;
}

ElemType FrontAndDequene(p_Quene Q){
    if(IsQueneEmpty(Q)){
        printf("DeQuene Error: p_Quene Umpty\n");
        return NULL;
    }
    ElemType E = FrontQuene(Q);
    DeQuene(Q);
    return E;
}