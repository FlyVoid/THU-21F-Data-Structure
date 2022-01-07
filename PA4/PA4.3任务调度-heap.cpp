#include <cmath>
#include <cstring>
#include <iostream>
//0 ≤ n ≤ 4,000,000, 0 ≤ m ≤ 2,000,000,0 < 每个任务的初始优先级 < 2^32 
using namespace std;
#define MAXSIZE  10000010


struct Node{
    long long int key;
    char name[11];
    friend bool operator<(Node x, Node y)
    {
        if (x.key != y.key)
            return x.key < y.key;  //该数值越小优先级越高 
        return strcmp(x.name, y.name) < 0;  //若优先级数相等，则任务名ASCII字典顺序低者优先 
    }
} heap[MAXSIZE];
int n = 0;

void up(int p){
    while (p > 1){
        if (heap[p] < heap[p / 2]){
            swap(heap[p], heap[p / 2]);
            p /= 2;
        }
        else
            break;
    }
}


void down(int p){
    int temp = p * 2;
    while (temp <= n){
        if (temp < n && heap[temp + 1] < heap[temp])
            temp++;
        if (heap[temp] < heap[p]){
            swap(heap[p], heap[temp]);
            p = temp;
            temp *= 2;
        }
        else
            break;
    }
}

void Delete(){
    heap[1] = heap[n];
    n -= 1;
    down(1);
}

void Insert(Node key){
    n += 1;
    heap[n] = key;
    up(n);
}

int main()
{
    int a, b;
    Node x;
    scanf("%d %d", &a, &b);
    long long int p = 1;
    for (int i = 0; i < 32; i++)
        p *= 2;
    for (int i = 0; i < a; i++){   
        scanf("%lld %s", &x.key, x.name);
        Insert(x);
    }
    while (b-- && n >= 1){
        printf("%s\n", heap[1].name);
        x = heap[1];
        x.key *= 2;
        Delete();
        if (x.key < p)
         Insert(x);
    }
    return 0;
}




