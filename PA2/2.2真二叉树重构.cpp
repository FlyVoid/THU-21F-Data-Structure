#include <cstdio>
//�ο�3��https://blog.csdn.net/qq_43636360/article/details/106961185 
/*
���������Ҫ���������������ȴ�ӡ�ٵݹ����ҡ�����������ȵݹ������ٴ�ӡ���ص㽨����
 ʱ�临�Ӷȣ�O(nlogn)
*/
const int maxn = 4000010;
int pre[maxn] ;
int post[maxn];
int n;
struct treeNode
{
    treeNode *lchild, *rchild;
    int num;
};

//�ع���������ǰ�����е���������[s1,e1]���������е���������[s2,e2] 
treeNode *build(int s1, int e1, int s2, int e2)
{   

    //���Ƚ���������pre[0]������  
    treeNode *root = new treeNode;
    root->num = pre[s1];        
    root->rchild = root->lchild = NULL;
    
      
    if (s2 == e2)
        return root;
    int current;
    //���� ����������У�Ѱ����������������ں������е�λ�� 
    for (int i = s2; i <= e2; i++)  
    {
        if (post[i] == pre[s1 + 1])  // pre[s+1]������������
        {
            current = i;
            break;
        }
    }
    int left = current - s2 + 1;
    root->lchild = build(s1 + 1, s1 + left, s2, current);
    root->rchild = build(s1 + left + 1, e1, current + 1, e2 - 1);
    return root;
}

//��������������󣬸����� 
void travIn(treeNode *root)
{  
    if (root->lchild != NULL) travIn(root->lchild);  //���Ӳ�Ϊ�գ�ȥ���ӵݹ� 
	printf("%d ", root->num);                        //��ӡ�ýڵ��ֵ 
	if (root->rchild != NULL) travIn(root->rchild);  //���ȥ�Һ��ӵݹ� 
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    
    for (int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    treeNode *root = build(0, n - 1, 0, n - 1);  //�ع�������� 
    travIn(root);      //�õ������������ 
    return 0;
}
