#include <stdio.h>
#include "polycal.h"

#define MAX_PLOY_LEN 128  //����󳤶�
#define MAX_MUL_LEN  256
#define E_SUCC  1         //�ɹ�
#define E_FAIL  -1        //ʧ��

int main()
{
    int ratio = 0/* ϵ�� */, power = 0 /* �ݴ� */;
    int aPoly1[MAX_PLOY_LEN] = {0}, aPoly2[MAX_PLOY_LEN] = {0};
    int aPolyMul[MAX_MUL_LEN] = {0};
    int nRet = 0;

    while (1){ //���յ�1������
        scanf("%d%*c%d", &power, &ratio);
        aPoly1[power] = ratio;
        if (!power){ // �����⵽�ݴ�Ϊ0�������һ������
            break;
        }
    }
    while (1){ //���յ�2������
        scanf("%d%*c%d", &power, &ratio);
        aPoly2[power] = ratio;
        if (!power){ // �����⵽�ݴ�Ϊ0�������һ������
            break;
        }
    }

    nRet = polyMulti(aPolyMul, aPoly1, aPoly2, MAX_PLOY_LEN);

    showPoly(aPolyMul, MAX_MUL_LEN);

    return 0;
}
