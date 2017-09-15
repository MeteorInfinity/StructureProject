//
// Created by 孙晨星 on 2017/8/3.
//

#ifndef STRUCTUREPROJECT_QUENE_H
#define STRUCTUREPROJECT_QUENE_H

typedef int ElemType;

typedef struct QueneStructure *p_Quene;

int IsQueneEmpty(p_Quene Q);

int IsQueneFull(p_Quene Q);

p_Quene CreatQuene(int MaxElements);

int DisposeQuene(p_Quene Q);

int MakeEmpty(p_Quene Q);

int EnQuene(p_Quene Q, ElemType E);

ElemType FrontQuene(p_Quene Q);

int DeQuene(p_Quene Q);

ElemType FrontAndDequene(p_Quene Q);

#endif //STRUCTUREPROJECT_QUENE_H