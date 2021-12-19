//������1���Դ�㣬-1����ڽӵ㣬1����ڽӵ���ڽӵ�
/*
4 3
1 2
1 3
2 4
*/
 #include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;

 #define MAX 10010
 
int n, m;        //С����,���20Km��С�����
int queue[MAX],head,tail;    //����
int broadcast;    //Broadcast������


 //С��
 struct Town{
     int state;  //״̬
     int num;    //�洢С���� 
     Town *next; //����ָ����һ��С�� 
     Town(){ state = 0; next = NULL;}
     Town(int state_, int num_, Town *next_){state=state_;num=num_; next=next_;}
     void insert(int num){   /*�����±�*/
     	if (this->next == NULL)
     	this->next = new Town(0,num,NULL);
        else this->next = new Town(0,num,this->next);
     }
 }town[MAX];



 bool BFS(int x)
 {
     queue[tail++] = x;
     town[x].state = 1;
     broadcast++;   
     while (head < tail)
    {
        Town cur = town[queue[head]];    //��ǰС��
        Town *tmp = cur.next;        //ָ��nextTown
         while (tmp != NULL)
         {
            if (!town[tmp->num].state){
                 town[tmp->num].state = -cur.state;    //cover��ͬBroadcast
                 broadcast++;        //No.(tmp->num)��cover
                 queue[tail++] = tmp->num;
             }
             else if (town[tmp->num].state == cur.state)    //������
                 return false;
             tmp = tmp->next;
         }
        head++;
     }
     return true;
 }
 
 int main()
 {
     scanf("%d%d", &n, &m);
     for (int i = 0; i < m; i++)
     {
         int x, y;
         scanf("%d%d", &x, &y);    //d(x,y)<20Km
         town[x].insert(y);
         town[y].insert(x);
     }
     for (int i = 1; i <= n; i++)
     {
         if (!town[i].state){    
             if (BFS(i) == false){    //����BFS-�źű�����
                printf("-1\n");
                return 0;
            }
                 printf("1\n");
                 return 0;
        }
     }
 
     return 0;
 }
