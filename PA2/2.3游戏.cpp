#include <stdio.h>

char s[100005];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", s); //�ַ����洢 
    
    int low = 0;
    int high = 0;

//����[low, high]��"δƥ���A������"������ 
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A') // ��С����ֵ��������ֵ+1
        {
            ++low;
            ++high;
        }
        else if (s[i] == 'B') // ��С����ֵ��������ֵ-1
        {
            if (high <= 0)    // ��С����ֵΪ0���ټ�����-1��˵��ǰ��û��A�ܺ�Bƥ��
            {
                printf("False\n");
                return 0;
            }
            low= low-1 < 0 ? 0 : low-1;
            --high;
        }
        else // s[i] == 'C' ��С����ֵ-1��������ֵ+1
        {
            low= low-1 < 0 ? 0 : low-1;
            ++high;
        }
    }
    
    
    if (low == 0) // �����С����ֵ�Ƿ�Ϊ0������Ϊ0˵������Aû��ƥ��
    {
        printf("True\n");
        return 0;
    }
    printf("False\n");
    return 0;
}
