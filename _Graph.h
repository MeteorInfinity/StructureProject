//
// Created by 孙晨星 on 2017/9/15.
//

#ifndef STRUCTUREPROJECT_GRAPH_H
#define STRUCTUREPROJECT_GRAPH_H

typedef struct GraphMartix GMartix;

typedef GMartix *p_GMartix;

typedef struct GraphAdjacencyArc GAArc;

typedef GAArc *p_GAArc;

typedef struct GraphAdjacencyVertexNode GAVNode;

typedef struct GraphAdjacencyList GAList;

typedef GAList *p_GAList;

p_GAList GraphMartix2AList(p_GMartix GM);

p_GMartix GraphAList2Martix(p_GAList GAL);

void DFS(p_GAList GAL, int v);

void BFS(p_GAList GAL,int v);

void UnweightedShortPath(p_GAList GAL, int V);

void Dijkstra(p_GMartix GM, int V);

void DisPath(p_GMartix GM, int dist[], int path[], int S[], int V);

void Prim(p_GMartix GM ,int V);

int* inDegree(p_GAList GA);

int* outDegree(p_GAList GA);

int TopoSort(p_GAList GA);

#endif //STRUCTUREPROJECT_GRAPH_H
