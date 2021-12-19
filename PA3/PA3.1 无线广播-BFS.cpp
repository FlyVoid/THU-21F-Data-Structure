//这里用1标记源点，-1标记邻接点，1标记邻接点的邻接点
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
 
int n, m;        //小镇数,相距20Km内小镇对数
int queue[MAX],head,tail;    //队列
int broadcast;    //Broadcast的数量


 //小镇
 struct Town{
     int state;  //状态
     int num;    //存储小镇编号 
     Town *next; //用于指向下一个小镇 
     Town(){ state = 0; next = NULL;}
     Town(int state_, int num_, Town *next_){state=state_;num=num_; next=next_;}
     void insert(int num){   /*插入新边*/
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
        Town cur = town[queue[head]];    //当前小镇
        Town *tmp = cur.next;        //指向nextTown
         while (tmp != NULL)
         {
            if (!town[tmp->num].state){
                 town[tmp->num].state = -cur.state;    //cover不同Broadcast
                 broadcast++;        //No.(tmp->num)被cover
                 queue[tail++] = tmp->num;
             }
             else if (town[tmp->num].state == cur.state)    //被干扰
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
             if (BFS(i) == false){    //调用BFS-信号被干扰
                printf("-1\n");
                return 0;
            }
                 printf("1\n");
                 return 0;
        }
     }
 
     return 0;
 }
