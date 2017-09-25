//
// Created by 孙晨星 on 2017/9/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "_Graph.h"
#include "_Quene.h"
#include "_Stack.h"
#include "Tree/_Set.h"

#define MAXV 100

struct GraphMartix{
    int edges[MAXV][MAXV];
    int vertexNum;
    int edgeNum;
    int vertexs[MAXV];
};

struct GraphAdjacencyArc{
    int aVertexNo;
    struct GraphAdjacencyArc *nextArc;
};

struct GraphAdjacencyVertexNode{
    int vertex;
    p_GAArc firstArc;
};

struct GraphAdjacencyList{
    GAVNode aList[MAXV];
    int vertexNum;
    int edgeNum;
};

p_GAList GraphMartix2AList(p_GMartix GM){
    p_GAArc tmp;
    p_GAList GAL = (p_GAList)malloc(sizeof(GAList));

    for(int i=0; i<GM->vertexNum; i++){
        GAL->aList[i].firstArc = NULL;
        for(int j=GM->vertexNum-1; j>=0; j--){
            if(GM->edges[i][j] != 0){
                tmp = (p_GAArc)malloc(sizeof(GAArc));
                tmp->aVertexNo = j;
                tmp->nextArc = GAL->aList[i].firstArc;
                GAL->aList[i].firstArc = tmp;
            }
        }
    }
    GAL->vertexNum = GM->vertexNum;
    GAL->edgeNum = GM->edgeNum;

    return GAL;
}

p_GMartix GraphAList2Martix(p_GAList GAL){
    p_GAArc tmp;
    p_GMartix GM = (p_GMartix)malloc(sizeof(GMartix));
    for(int i=0; i<GAL->vertexNum; i++){
        tmp = GAL->aList[i].firstArc;
        while (tmp){
            GM->edges[i][tmp->aVertexNo] = 1;
            tmp = tmp->nextArc;
        }
    }
    GM->vertexNum = GAL->vertexNum;
    GM->edgeNum = GAL->edgeNum;

    return GM;
}

void DFS(p_GAList GAL, int v) {
    p_GAArc tmp;
    int visited[GAL->vertexNum+1];
    visited[v] = 1;
    printf("%d ", v);
    tmp = GAL->aList[v].firstArc;
    while (tmp){
        if(visited[tmp->aVertexNo] == 0)
            DFS(GAL, tmp->aVertexNo);
        tmp = tmp->nextArc;
    }
}

void BFS(p_GAList GAL,int v){
    p_GAArc tmp;
    int visited[GAL->vertexNum+1] = {0};
    int w;
    p_Quene Q = CreatQuene(MAXV);
    printf("%d ", v);
    visited[v] = 1;
    EnQuene(Q, v);
    while (!IsQueneEmpty(Q)){
        w = DeQuene(Q);
        tmp = GAL->aList[w].firstArc;
        while (tmp){
            if(visited[tmp->aVertexNo] == 0){
                printf("%d ", tmp->aVertexNo);
                visited[tmp->aVertexNo] = 1;
                EnQuene(Q, tmp->aVertexNo);
            }
            tmp = tmp->nextArc;
        }
    }
    printf("\n");
}

void UnweightedShortPath(p_GAList GAL, int V){
    p_GAArc tmp;
    int dist[GAL->vertexNum+1] = {-1};
    int path[GAL->vertexNum+1] = {0};
    int w;
    p_Quene Q = CreatQuene(MAXV);
    printf("%d ", V);
    dist[V] = 0;
    EnQuene(Q, V);
    while (!IsQueneEmpty(Q)){
        w = DeQuene(Q);
        tmp = GAL->aList[w].firstArc;
        while (tmp){
            if(dist[tmp->aVertexNo] == -1){
                dist[tmp->aVertexNo] = dist[V]+1;
                path[tmp->aVertexNo] = V;
                EnQuene(Q, tmp->aVertexNo);
            }
            tmp = tmp->nextArc;
        }
    }
    printf("\n");
}

#define INF 100000

void Dijkstra(p_GMartix GM, int V){
    int dist[GM->vertexNum];
    int path[GM->vertexNum];
    int S[GM->vertexNum];
    int minDis,u = 0;

    // 初始化 -> 循环V的邻接点
    for(int i = 0; i<GM->vertexNum; i++){
        dist[i] = GM->edges[V][i];
        S[i] = 0;
        if(GM->edges[V][i] < INF)
            path[i] = V;
        else
            path[i] = -1;
    }
    S[V] = 1;
    path[V] = 0;

    for(int i=0; i<GM->vertexNum; i++){
        minDis = INF;
        for(int j=0; j<GM->vertexNum; j++){
            if(S[j] == 0 && dist[j] < minDis){
                u = j;
                minDis = dist[j];
            }
        }
        S[u] = 1; // 将不在S中且具有最小距离的点U加入S中

        // 修改被影响的各点的距离
        for(int j=0; j<GM->vertexNum; j++){
            if(S[j] == 0){
                // 寻找邻接点，并更新存在的最小距离(dist)
                if(GM->edges[u][j] < INF && dist[u] + GM->edges[u][j] < dist[j]){
                    dist[j] = dist[u] + GM->edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    DisPath(GM, dist, path, S, V);
}

void DisPath(p_GMartix GM, int dist[], int path[], int S[], int V){
    int sPath[GM->vertexNum];
    int preV,thisV;
    for(int i=0; i<GM->vertexNum; i++){
        printf("Shortest Path %d TO %d: Distance = %d; Path = ", V, i, dist[i]);
        thisV = 0;
        sPath[thisV] = i;
        preV = i;
        printf("%d->",i);
        if(preV == -1)
            printf("NULL");
        else{
            while (preV != V){
                printf("%d->",preV);
                preV = path[preV];
            }
            printf("%d \n",preV);
        }
    }
}

void Prim(p_GMartix GM ,int V){
    int dist[MAXV], parent[MAXV];
    int min = 0, tmpV = -1;
    for(int i = 0; i<GM->vertexNum; i++){
        dist[i] = GM->edges[V][i];
        parent[i] = 0;
    }

    for(int i = 0; i<GM->vertexNum; i++){
        min = INF;
        for (int j = 0; j < GM->vertexNum; ++j) {
            if(dist[j] != 0){
                if(dist[j] < min){
                    dist[j] = GM->edges[V][j];
                    min = dist[j];
                    tmpV = j;
                }
            }
        }
        V = tmpV; // 以tmp为新迭代点更新候选集dist[]
        for(int j = 0; j < GM->vertexNum; ++j){
            if (dist[j] != 0)
                if(GM->vertexNum < dist[j]){
                    dist[j] = GM->vertexNum;
                    parent[j] = V;
                }
        }
    }
}

typedef struct EdgeStructure{
    int head;
    int rear;
    int weight;
}Edge, *p_Edge;

void Kruskal(p_GMartix GM){
    int vest[MAXV];
    Edge edge[GM->edgeNum];
    int e = 0;
    for (int i = 0; i < GM->vertexNum; ++i) {
        for (int j = 0; j < GM->vertexNum; ++j) {
            if(GM->edges[i][j] != 0 && GM->edges[i][j] != INF){
                edge[e].weight = GM->edges[i][j];
                edge[e].head = i;
                edge[e].head = j;
                e++;
            }
        }
    }

    for(int i= 1; i<GM->edgeNum; i++){
        if(edge[i].weight < edge[i-1].weight){               //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            int j= i-1;
            Edge x = edge[i];        //复制为哨兵，即存储待排序元素
            edge[i] = edge[i-1];           //先后移一个元素
            while(x.weight < edge[j].weight){  //查找在有序表的插入位置
                edge[j+1] = edge[j];
                j--;         //元素后移
            }
            edge[j+1] = x;      //插入到正确位置
        }
    }

    p_Set set = Set_MakeSet(GM->vertexNum);
    int k = 1, head, rear, headT, rearT;

    for(e = 1;k < GM->edgeNum; e++){
        head = edge[e].head;
        headT = Set_FindParent(set, head);
        rear = edge[e].rear;
        rearT = Set_FindParent(set, rear);
        if(headT != rearT){
            k++;
            Set_Union(set, headT, rearT);
        }
    }
}

int* inDegree(p_GAList GA) {
    p_GAArc arc;
    int *inDs = (int*)malloc(GA->vertexNum * sizeof(int));
    for (int i = 0; i < GA->vertexNum; ++i) {
        inDs[i] = 0;
    }
    for(int i = 0; i < GA->vertexNum; i++) {
        arc = GA->aList[i].firstArc;
        while(arc != NULL) {
            inDs[arc->aVertexNo]++;
            arc = arc->nextArc;
        }
    }
    return inDs;
}

int* outDegree(p_GAList GA) {
    p_GAArc arc;
    int *outDs = (int*)malloc(GA->vertexNum * sizeof(int));
    for(int i = 0; i < GA->vertexNum; i++) {
        outDs[i] = 0;
        arc = GA->aList[i].firstArc;
        while(arc != NULL) {
            outDs[i]++;
            arc = arc->nextArc;
        }
    }
    return outDs;
}

int TopoSort(p_GAList GA){
    int* inDs = inDegree(GA);
    p_Stack S = InitStack();

    for (int i = 0; i < GA->vertexNum; ++i) {
        if (!inDs[i]) {
            Push(S, i);
        }
    } // 入度为0的顶点入栈

    int count = 0;
    int vertex;
    while (!StackEmpty(S)){
        vertex = Pop(S);
        printf(vertex+" ");
        count++;
        p_GAArc arc = GA->aList[vertex].firstArc;
        while (arc){
            int k = arc->aVertexNo;
            if(--inDs[k] == 0) Push(S, k); //当入度为0时入栈
            arc = arc->nextArc;
        } // 对i号顶点的每个邻接点的入度-1；
    }
    if(count < GA->vertexNum) return 0;
    else return 1;
}