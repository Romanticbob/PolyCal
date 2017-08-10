#include <stdio.h>
#include <stdlib.h>

#define MAX_PLOY_LEN 128  //幂最大长度
#define E_SUCC  1         //成功
#define E_FAIL  -1        //失败

#define _ASSERT_PARAM(param) if(!(param)){return E_FAIL;}
#define _ASSERT_LEN(len) if((len) > MAX_PLOY_LEN || (len) < 0){return E_FAIL;}


/**
 * @param:  pstArray1 多项式1
 * @param:  pstArray2 多项式2
 * @param:  nLen  多项式的最大项数
 * @return: 成功返回E_SUCC,失败返回E_FAIL
 * @todo:   求两个多项式的和
 * @author: 王翔
 **/
int polySum(int *pstArray1, int *pstArray2, int nLen)
{

    int loop = 0;

    _ASSERT_PARAM(pstArray1)
    _ASSERT_PARAM(pstArray2)
    _ASSERT_LEN(nLen)

    for (; loop < nLen; ++loop)
    {
        pstArray1[loop] += pstArray2[loop];
    }

    return E_SUCC;
}

/**
 * @param:  pstArray 多项式
 * @param:  nLen  多项式的最大项数
 * @return: 非0多项式返回幂次,否则返回0
 * @todo:   获取多项式的幂次
 * @author: 王翔
 **/
int getPowerOfPoly(int *pstArray, int nLen)
{

    int loop = nLen - 1;

    _ASSERT_PARAM(pstArray)
    _ASSERT_LEN(nLen)

    for (; loop > 0; loop--)
    {
        if (pstArray[loop])
        {
            return loop;
        }
    }
    return 0;
}

/**
 * @param:  pstArray 多项式
 * @param:  nLen  多项式的最大项数
 * @return: 成功返回E_SUCC,失败返回E_FAIL
 * @todo:   打印多项式
 * @author: 王翔
 **/
int showPoly(int *pstArray, int nLen)
{

    int loop = 0;
    int power = 0;

    _ASSERT_PARAM(pstArray)
    _ASSERT_LEN(nLen)

    power = getPowerOfPoly(pstArray, nLen);

    if (1 == power)
    { //如果为常数多项式则展示常数
        printf("%d", pstArray[0]);
    }
    else if (0 == power)
    { //如果为0多项式则展示0
        printf("0");
    }
    else
    { //按照规则展示
        for (loop = power; loop >= 0; loop--)
        {

            if (!pstArray[loop])
            {
                continue;
            }

            /* 先打印系数 */
            if(loop != power)
            {
                if (pstArray[loop] > 0)
                {
                    if (1 != pstArray[loop])
                    {
                        printf("+%d", pstArray[loop]);
                    }
                    else
                    {
                        printf("+");
                    }
                }
                else
                {
                    printf("%d", pstArray[loop]);
                }
            }
            else  //对于最高次项的正负号需要特殊处理
            {
                if (1 != pstArray[power])
                {
                    printf("%d", pstArray[power]);
                }
            }

            /* 再打印幂次 */
            if (1 == loop){ //打印1次项
                printf("x");
            }
            else if (0 == loop){ //打印常数项
                printf("%d", pstArray[0]);
                break;
            }
            else{ //输出常规项
                printf("x%d", loop);
            }
        }
    }
    printf("\n");
    return E_SUCC;
}

int main()
{
    int ratio = 0/* 系数 */, power = 0 /* 幂次 */;
    int aPoly1[MAX_PLOY_LEN] = {0}, aPoly2[MAX_PLOY_LEN] = {0};
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

    nRet = polySum(aPoly1, aPoly2, MAX_PLOY_LEN);
    if (E_SUCC == nRet){
        showPoly(aPoly1, MAX_PLOY_LEN);
    }

    return 0;
}
