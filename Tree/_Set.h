//
// Created by 孙晨星 on 2017/9/15.
//

#ifndef STRUCTUREPROJECT_SET_H
#define STRUCTUREPROJECT_SET_H

typedef struct SetTeam SetTeam;

typedef SetTeam *p_Set;

int Set_FindParent(p_Set S, int X);

void Set_Union(p_Set S, int X1, int X2);

p_Set Set_MakeSet(int n);

#endif //STRUCTUREPROJECT_SET_H
