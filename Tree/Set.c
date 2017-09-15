//
// Created by 孙晨星 on 2017/9/15.
//

#include <stdlib.h>
#include "_Set.h"

struct SetTeam{
    int data;
    int parent;
    int rank;
};

int Set_FindParent(p_Set S, int X){
    if(S[X].parent != X)
        return Set_FindParent(S, S[X].parent);
    else
        return X;
}

void Set_Union(p_Set S, int X1, int X2){
    int T1 = Set_FindParent(S, X1);
    int T2 = Set_FindParent(S, X2);
    if(S[T1].rank > S[T2].rank){
        S[T2].parent = T1;
    } else {
        S[T1].parent = T2;
        if (S[T1].rank > S[T2].rank)
            S[T2].rank++;
    }
}

p_Set Set_MakeSet(int n){
    p_Set SET = (p_Set)malloc(n * sizeof(SetTeam));
    for (int i = 0; i < n; ++i) {
        SET[i].rank = 0;
        SET[i].parent = i;
    }
    return SET;
}