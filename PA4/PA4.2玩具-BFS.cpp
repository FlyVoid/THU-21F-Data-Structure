#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
//对于100%的数据，1 <= N <= 1,000 


int f[10];
int dists[40320 + 10]; //距离 
struct Node{
    int times;     
    int data[10];  //其中1-8分别是玩具格子里的数值
    int Count(){
	    times = 0;
	    for (int i = 1; i <= 8; i++){
	        int x = 0;
	        for (int j = i + 1; j <= 8; j++){
	            if (data[j] < data[i]){
	                x++;
	            }
	        }
	        times += x * f[9 - i];
	    }
	    return times;	
    }
    void Exchange(int &a, int &b){
    	int temp;
	    temp = a;
	    a = b;
	    b = temp;
    }
    void Vary1(){
    	for (int i = 1; i <= 4; i++)
        Exchange(data[i], data[9 - i]);
    }
    void Vary2(){
    	int temp;
		temp = data[1];
	    for (int i = 1; i <= 3; i++){
	        data[i] = data[i + 1];
	    }
	    data[4] = temp;
	    temp = data[8];
	    for (int i = 8; i >= 6; i--){
	        data[i] = data[i - 1];
	    }
	    data[5] = temp;
	} 
    void Vary3(){
	    int temp;
		temp = data[2];
	    data[2] = data[3];
	    data[3] = data[6];
	    data[6] = data[7];
	    data[7] = temp;
	} 
} queue[41000];




void BFS()
{
    Node current;
    for (int i = 1; i <= 8; i++){
        current.data[i] = i;
    }
    int head = 0, tail = 0;
    dists[current.Count()] = 1;
    queue[tail++] = current;
    Node temp;
    while (head != tail){
        current = queue[head++];
        head %= 40900;
        temp = current;
        temp.Vary1();
        if (!dists[temp.Count()]){
            queue[tail++] = temp;
            tail %= 40900;

            dists[temp.Count()] = dists[current.times] + 1;
        }

        temp = current;
        temp.Vary2();
        if (!dists[temp.Count()]){
            queue[tail++] = temp;
            tail %= 40900;

            dists[temp.Count()] = dists[current.times] + 1;
        }

        temp = current;
        temp.Vary3();
        if (!dists[temp.Count()]){
            queue[tail++] = temp;
            tail %= 40900;
            dists[temp.Count()] = dists[current.times] + 1;
        }
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= 8; i++){
        f[i] = f[i - 1] * (i - 1);  //f[]存储阶乘 
    }

    BFS();
    Node x;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= 8; j++)
            scanf("%d", &x.data[j]);
        printf("%d\n", dists[x.Count()] - 1);
    }
    return 0;
}



