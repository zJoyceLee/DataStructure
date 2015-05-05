#pragma once
#include "AdjMatrixUndirGraph.h"

template <class ElemType>
int Is_it_all_in_circle(AdjMatrixUndirGraph<ElemType> tmp2)
{
    int degreeNum;
    for(int i = 0; i < tmp2.vexNum; i++)
    {
        degreeNum = 0;
        for(int j = 0; j < tmp2.vexNum; j++)
        {
            if(tmp2.arcs[i][j] >0)
                degreeNum++;
        }
        if(degreeNum == 1)
            return 0;
    }
    return 1;
}


template <class ElemType>
AdjMatrixUndirGraph<ElemType> MST(AdjMatrixUndirGraph<ElemType> tmp)
{
    AdjMatrixUndirGraph<ElemType> tmp2 = tmp;
    int t_i, t_j, maxweight;
    while(tmp.arcNum > (tmp.vexNum - 1))
    {
        maxweight = 0;
        //while(!Is_it_all_in_circle<ElemType>(tmp2))
            for(int i = 0; i < tmp2.vexNum; i++)//�ҳ���Ϊ1�Ķ���
            {
                int degreeNum = 0;
                for(int j = 0;j < tmp2.vexNum; j++)
                {
                    if(tmp2.arcs[i][j] > 0)
                    {
                        t_i = i;
                        t_j = j;
                        degreeNum++;
                    }
                }
                if(degreeNum == 1)//����Ϊ1�ĵ��ų����⣬���ж��ų���ʣ�µĶ��㶼��Ȧ��
                {
                    tmp2.arcs[t_i][t_j] = 0;
                    tmp2.arcs[t_j][t_i] = 0;
                }
            }

        for(int i = 0; i < tmp2.vexNum; i++) //�ҳ�Ȧ��Ȩ���ıߣ�ɾȥ
            for(int j = i;j < tmp2.vexNum; j++)
            {
                if(tmp2.arcs[i][j] > maxweight)
                {
                    maxweight = tmp2.arcs[i][j];
                    t_i = i;
                    t_j = j;
                }
            }
        tmp.arcs[t_i][t_j] = 0;
        tmp.arcs[t_j][t_i] = 0;
        tmp.arcNum--;
        tmp2 = tmp;
    }
    return tmp;
}
