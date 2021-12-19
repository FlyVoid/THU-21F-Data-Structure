
 #include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 
 #define MAX 1000010
 
 int n, m;    //村庄个数，道路数
 int topology[MAX],lt;    //拓扑数组,长度
 int degree[MAX];    //入度
 int maxTown = 1;    //保存答案
 

 
 struct Town{
     int num;      //村庄编号
     Town* next;   //下一个村庄 
	 int dp;       //至此可通过的最大村庄数
	 Town(){ next = NULL;dp = 1; }
	 Town(int x,Town *n){ num = x; next=n;}
     void insert(int n){
	     degree[n]++;    //直接后继城市入度+1
	     if (this->next == NULL)
	         this->next = new Town(n,NULL);
	     else{
	         Town *p = new Town(n,this->next);
	         this->next = p;
	     }
	     return;
	}
 }town[MAX];
 

 
 /*拓扑排序*/
 void Topology()
 {
     for (int i = 1; i <= n; i++)
         if (!degree[i]) topology[++lt] = i;    //入度为0的town
     //Main Content
     for (int i = 1; topology[i];i++)
     {
         int cur = topology[i];    //该town-number
         //遍历该town所有直接后继
         for (Town *tmp = town[cur].next; tmp != NULL; tmp = tmp->next)
         {
             town[tmp->num].dp = (town[cur].dp + 1) > town[tmp->num].dp ? (town[cur].dp + 1) : town[tmp->num].dp; 
             maxTown = town[tmp->num].dp > maxTown? town[tmp->num].dp :maxTown;
             //处理后继
             int num = tmp->num;
             degree[num]--;    //后继入度-1
             if (!degree[num])    topology[++lt] = num;    //若后继入度为0
         }
     }
 }
 
 int main()
 {
     scanf("%d%d", &n, &m);
     for (int i = 0; i < m; i++)
    {
         int x, y;  
         scanf("%d%d", &x, &y);
         town[x].insert(y);
    }
    Topology();
    printf("%d", maxTown);
 
     return 0;
 }
