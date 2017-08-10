#include <stdio.h>
#include <stdlib.h>

#define MAX_PLOY_LEN 128  //����󳤶�
#define E_SUCC  1         //�ɹ�
#define E_FAIL  -1        //ʧ��

#define _ASSERT_PARAM(param) if(!(param)){return E_FAIL;}
#define _ASSERT_LEN(len) if((len) > MAX_PLOY_LEN || (len) < 0){return E_FAIL;}


/**
 * @param:  pstArray1 ����ʽ1
 * @param:  pstArray2 ����ʽ2
 * @param:  nLen  ����ʽ���������
 * @return: �ɹ�����E_SUCC,ʧ�ܷ���E_FAIL
 * @todo:   ����������ʽ�ĺ�
 * @author: ����
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
 * @param:  pstArray ����ʽ
 * @param:  nLen  ����ʽ���������
 * @return: ��0����ʽ�����ݴ�,���򷵻�0
 * @todo:   ��ȡ����ʽ���ݴ�
 * @author: ����
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
 * @param:  pstArray ����ʽ
 * @param:  nLen  ����ʽ���������
 * @return: �ɹ�����E_SUCC,ʧ�ܷ���E_FAIL
 * @todo:   ��ӡ����ʽ
 * @author: ����
 **/
int showPoly(int *pstArray, int nLen)
{

    int loop = 0;
    int power = 0;

    _ASSERT_PARAM(pstArray)
    _ASSERT_LEN(nLen)

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
            else if (0 == loop){ //��ӡ������
                printf("%d", pstArray[0]);
                break;
            }
            else{ //���������
                printf("x%d", loop);
            }
        }
    }
    printf("\n");
    return E_SUCC;
}

int main()
{
    int ratio = 0/* ϵ�� */, power = 0 /* �ݴ� */;
    int aPoly1[MAX_PLOY_LEN] = {0}, aPoly2[MAX_PLOY_LEN] = {0};
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

    nRet = polySum(aPoly1, aPoly2, MAX_PLOY_LEN);
    if (E_SUCC == nRet){
        showPoly(aPoly1, MAX_PLOY_LEN);
    }

    return 0;
}
