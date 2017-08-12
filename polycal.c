#include <stdio.h>
#include "polycal.h"

#define MAX_PLOY_LEN 128  //����󳤶�
#define E_SUCC  1         //�ɹ�
#define E_FAIL  -1        //ʧ��

#define _ASSERT_PARAM(param) if(!(param)){return E_FAIL;}
#define _ASSERT_LEN(len) if((len) > MAX_PLOY_LEN || (len) < 0){return E_FAIL;}

/**
 * @param:  pstArray ����ʽ
 * @param:  nLen  ����ʽ���������
 * @return: ��0����ʽ�����ݴ�,���򷵻�0
 * @todo:   ��ȡ����ʽ���ݴ�
 * @author: Romanticbob
 **/
int getPowerOfPoly(int *pstArray, int nLen)
{

    int loop = nLen - 1;

    _ASSERT_PARAM(pstArray)

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
 * @param:  pstArray1 ����ʽ1
 * @param:  pstArray2 ����ʽ2
 * @param:  nLen  ����ʽ���������
 * @return: �ɹ�����E_SUCC,ʧ�ܷ���E_FAIL
 * @todo:   ����������ʽ�ĺ�
 * @author: Romanticbob
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
 * @param:  pstArrayMul  ����ʽ�˻�
 * @param:  pstArray1 ����ʽ1
 * @param:  pstArray2 ����ʽ2
 * @param:  nLen  ����ʽ���������
 * @return: �ɹ�����E_SUCC,ʧ�ܷ���E_FAIL
 * @todo:   ����������ʽ�ĺ�,ע��ʹ��ʱ�ǵ�pstArrayMul��󳤶�Ϊ2*MAX_PLOY_LEN�����ұ����ʼ��Ϊ0����ʽ
 * @author: Romanticbob
 **/
int polyMulti(int *pstArrayMul, int *pstArray1, int *pstArray2, int nLen)
{
    int col = 0, row = 0;
    int power1 = 0, power2 = 0;

    _ASSERT_PARAM(pstArrayMul)
    _ASSERT_PARAM(pstArray1)
    _ASSERT_PARAM(pstArray2)
    _ASSERT_LEN(nLen)

    power1 = getPowerOfPoly(pstArray1, nLen);
    power2 = getPowerOfPoly(pstArray2, nLen);

    for (row = 0; row <= power1; row++)
    {
        if (!pstArray1[row])
        {
            continue;
        }
        else{
            for (col = 0; col <= power2; col++)
            {
                if (!pstArray2[col])
                {
                    continue;
                }
                else{
                    pstArrayMul[row + col] += pstArray1[row]*pstArray2[col];
                }
            }
        }
    }

    return E_SUCC;
}


/**
 * @param:  pstArray ����ʽ
 * @param:  nLen  ����ʽ���������
 * @return: �ɹ�����E_SUCC,ʧ�ܷ���E_FAIL
 * @todo:   ��ӡ����ʽ
 * @author: Romanticbob
 **/
int showPoly(int *pstArray, int nLen)
{

    int loop = 0;
    int power = 0;

    _ASSERT_PARAM(pstArray)

    power = getPowerOfPoly(pstArray, nLen);

    if (1 == power)
    { //���Ϊ��������ʽ��չʾ����
        printf("%d", pstArray[0]);
    }
    else if (0 == power)
    { //���Ϊ0����ʽ��չʾ0
        printf("0");
    }
    else
    { //���չ���չʾ
        for (loop = power; loop >= 0; loop--)
        {

            if (!pstArray[loop])
            {
                continue;
            }

            /* �ȴ�ӡϵ�� */
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
            else  //������ߴ������������Ҫ���⴦��
            {
                if (1 != pstArray[power])
                {
                    printf("%d", pstArray[power]);
                }
            }

            /* �ٴ�ӡ�ݴ� */
            if (1 == loop){ //��ӡ1����
                printf("x");
            }
            else if (0 != loop){ //�����ǳ�����������ӡ
                printf("x%d", loop);
            }
        }
    }
    printf("\n");
    return E_SUCC;
}

