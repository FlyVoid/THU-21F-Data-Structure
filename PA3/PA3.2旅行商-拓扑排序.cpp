
 #include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 
 #define MAX 1000010
 
 int n, m;    //��ׯ��������·��
 int topology[MAX],lt;    //��������,����
 int degree[MAX];    //���
 int maxTown = 1;    //�����
 

 
 struct Town{
     int num;      //��ׯ���
     Town* next;   //��һ����ׯ 
	 int dp;       //���˿�ͨ��������ׯ��
	 Town(){ next = NULL;dp = 1; }
	 Town(int x,Town *n){ num = x; next=n;}
     void insert(int n){
	     degree[n]++;    //ֱ�Ӻ�̳������+1
	     if (this->next == NULL)
	         this->next = new Town(n,NULL);
	     else{
	         Town *p = new Town(n,this->next);
	         this->next = p;
	     }
	     return;
	}
 }town[MAX];
 

 
 /*��������*/
 void Topology()
 {
     for (int i = 1; i <= n; i++)
         if (!degree[i]) topology[++lt] = i;    //���Ϊ0��town
     //Main Content
     for (int i = 1; topology[i];i++)
     {
         int cur = topology[i];    //��town-number
         //������town����ֱ�Ӻ��
         for (Town *tmp = town[cur].next; tmp != NULL; tmp = tmp->next)
         {
             town[tmp->num].dp = (town[cur].dp + 1) > town[tmp->num].dp ? (town[cur].dp + 1) : town[tmp->num].dp; 
             maxTown = town[tmp->num].dp > maxTown? town[tmp->num].dp :maxTown;
             //������
             int num = tmp->num;
             degree[num]--;    //������-1
             if (!degree[num])    topology[++lt] = num;    //��������Ϊ0
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
