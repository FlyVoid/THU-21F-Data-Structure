#include <cstdio>
//参考3：https://blog.csdn.net/qq_43636360/article/details/106961185 
/*
所以这里就要充分利用先序遍历先打印再递归左右、后序遍历是先递归左右再打印的特点建树。
 时间复杂度：O(nlogn)
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

//重构二叉树，前序序列的坐标区间[s1,e1]，后序序列的坐标区间[s2,e2] 
treeNode *build(int s1, int e1, int s2, int e2)
{   

    //首先建立树根：pre[0]是树根  
    treeNode *root = new treeNode;
    root->num = pre[s1];        
    root->rchild = root->lchild = NULL;
    
      
    if (s2 == e2)
        return root;
    int current;
    //遍历 后序遍历序列，寻找左子树树根结点在后序序列的位置 
    for (int i = s2; i <= e2; i++)  
    {
        if (post[i] == pre[s1 + 1])  // pre[s+1]：左子树树根
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

//中序遍历函数：左，根，右 
void travIn(treeNode *root)
{  
    if (root->lchild != NULL) travIn(root->lchild);  //左孩子不为空，去左孩子递归 
	printf("%d ", root->num);                        //打印该节点的值 
	if (root->rchild != NULL) travIn(root->rchild);  //最后去右孩子递归 
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
    treeNode *root = build(0, n - 1, 0, n - 1);  //重构真二叉树 
    travIn(root);      //得到后序遍历序列 
    return 0;
}
