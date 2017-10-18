//
// Created by 孙晨星 on 2017/10/18.
//

#include <stdlib.h>
#include <memory.h>
#include "String.h"

int* get_next(const char* T, int n){
    int i = 0, j = -1;
    int* next = (int*)malloc(sizeof(int) * n);
    next[1] = 0;
    //memset(next, '0', sizeof(next));
    while(i < n){
        if(j == -1 || T[i] == T[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    return next;
}

int* get_nextval(const char* T, int n){
    int i = 0, j = -1;
    int* nextval = (int*)malloc(sizeof(int) * n);
    nextval[1] = 0;
    //memset(next, '0', sizeof(next));
    while(i < n-1){
        if(j == -1 || T[i] == T[j]){
            i++;
            j++;
            if(T[i] != T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }else{
            j = nextval[j];
        }
    }
    return nextval;
}

int Index_KMP(const char* S, const char* T, int Sn, int Tn, int pos){
    int i = pos;
    int j = 0;
    int *next = get_nextval(T, Tn);

    while(i < Sn && j < Tn){
        if(j == -1 || S[i] == T[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }

    return j > Tn ? i - Tn : 0;
}
