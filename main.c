#include <stdio.h>
#include "polycal.h"

#define MAX_PLOY_LEN 128  //幂最大长度
#define MAX_MUL_LEN  256
#define E_SUCC  1         //成功
#define E_FAIL  -1        //失败

int main()
{
    int ratio = 0/* 系数 */, power = 0 /* 幂次 */;
    int aPoly1[MAX_PLOY_LEN] = {0}, aPoly2[MAX_PLOY_LEN] = {0};
    int aPolyMul[MAX_MUL_LEN] = {0};
    int nRet = 0;

    while (1){ //接收第1次输入
        scanf("%d%*c%d", &power, &ratio);
        aPoly1[power] = ratio;
        if (!power){ // 如果检测到幂次为0则结束第一次输入
            break;
        }
    }
    while (1){ //接收第2次输入
        scanf("%d%*c%d", &power, &ratio);
        aPoly2[power] = ratio;
        if (!power){ // 如果检测到幂次为0则结束第一次输入
            break;
        }
    }

    nRet = polyMulti(aPolyMul, aPoly1, aPoly2, MAX_PLOY_LEN);

    showPoly(aPolyMul, MAX_MUL_LEN);

    return 0;
}
