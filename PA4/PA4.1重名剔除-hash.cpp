#include <cstring>
#include <iostream>
using namespace std;

const int MAXSIZE = 6e5 + 10;  //1 < n < 6 * 10^5
char str[45];   //��ʱ�洢ÿһ��������ַ��� 

typedef struct node{
    char val[45];      //�洢�ַ��� 
    int repeat;       //�洢�ظ����� 
    node(){  repeat = 0;}
    node *next;
} * Node;
Node nodeList[MAXSIZE];

int main()
{
	int n;
    scanf("%d", &n);
    
    int length; 
    int mod = 6e5 + 10, p = 13331; 
    long long int hight = 0;   

    for (int i = 0; i < n; i++){
        hight = 0;
        scanf("%s", str);
        length = strlen(str);
        for (int j = 0; j < length; j++){
            hight = (hight * p % mod + (str[j] - 'a' + 1)) % mod; 
        }
        node *current = nodeList[hight];
        int flag = 0;
        if (nodeList[hight] == NULL)
            nodeList[hight] = new node;  // 

        while (NULL != current){
            if (strcmp(current->val, str) == 0){ //���ַ���һ�� 
                current->repeat++;              
                if (current->repeat == 2){
                    printf("%s\n", str);
                }
                flag = 1;
                break;
            }
            current = current->next;
        }
        if (!flag){
            node *temp = new node;
            strcpy(temp->val, str);       //��str����nodeList[hight]���� 
            temp->next = nodeList[hight]->next;
            temp->repeat = 1;
            nodeList[hight]->next = temp;
        }
    }
    return 0;
}
