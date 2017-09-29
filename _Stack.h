//
// Created by Meteor on 2017/9/22.
//

#ifndef STRUCTUREPROJECT_STACK_H
#define STRUCTUREPROJECT_STACK_H

typedef int KeyType;

struct StackStructure;

typedef struct StackStructure *p_Stack;

p_Stack InitStack();

int StackEmpty(p_Stack S);

KeyType* GetTop(p_Stack S);

int Push(p_Stack S, KeyType e);

KeyType Pop(p_Stack S);

void VisitStack(p_Stack S);


#endif //STRUCTUREPROJECT_STACK_H
