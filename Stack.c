//
// Created by Meteor on 2017/9/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "_Stack.h"

#define STACK_INIT_SIZE 50
#define STACK_INCREASE 10

struct StackStructure{
    KeyType *base;
    KeyType *top;
    int stackSize;
};

p_Stack InitStack(){
    p_Stack S = (p_Stack)malloc(sizeof(struct StackStructure));
    S->base = (KeyType*)malloc(STACK_INIT_SIZE * sizeof(KeyType));
    if(!S->base) return NULL;
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return S;
}

int StackEmpty(p_Stack S){
    if (S->top == S->base)
        return 1;
    return 0;
}

KeyType* GetTop(p_Stack S){
    if (!StackEmpty(S)) {
        return S->top - 1;
    } else {
        return NULL;
    }
}

int Push(p_Stack S, KeyType e){
    if(S->top - S->base >= S->stackSize){
    S->base = (KeyType*)realloc(S->base, STACK_INCREASE * sizeof(KeyType));
    if(!S->base) return 0;
    S->top = S->base + S->stackSize;
    S->stackSize += STACK_INCREASE;
    }
    *S->top++ = e;
    return 1;
}

KeyType Pop(p_Stack S){
    if (!StackEmpty(S)) {
        return *--S->top;
    } else {
        return -1;
    }
}

void VisitStack(p_Stack S){
    if(StackEmpty(S)) printf("Stack umpty");
    for(KeyType* p = S->top-1; p >= S->base; p--){
        printf("%d ",*p);
    }
    printf("\n");
}