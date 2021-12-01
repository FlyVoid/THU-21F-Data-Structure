#include <stdio.h>

char s[100005];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", s); //字符串存储 
    
    int low = 0;
    int high = 0;

//区间[low, high]："未匹配的A的数量"的区间 
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A') // 最小可能值和最大可能值+1
        {
            ++low;
            ++high;
        }
        else if (s[i] == 'B') // 最小可能值和最大可能值-1
        {
            if (high <= 0)    // 最小可能值为0，再减就是-1，说明前面没有A能和B匹配
            {
                printf("False\n");
                return 0;
            }
            low= low-1 < 0 ? 0 : low-1;
            --high;
        }
        else // s[i] == 'C' 最小可能值-1，最大可能值+1
        {
            low= low-1 < 0 ? 0 : low-1;
            ++high;
        }
    }
    
    
    if (low == 0) // 检查最小可能值是否为0，若不为0说明还有A没法匹配
    {
        printf("True\n");
        return 0;
    }
    printf("False\n");
    return 0;
}
