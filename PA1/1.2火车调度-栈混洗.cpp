
#include<stdio.h>
#include <stdlib.h>
using namespace std;

//采用三个栈混洗,栈采用vector的设计方法，栈底部不变，只能从栈顶pop和push即可 

class Stack{
	private:
		int size;  //栈中实际元素个数
		int capacity;   //栈容量 
		int* data;  //指向数组，存储车厢号 		
	public:
		//构造函数与析构函数 
		Stack(int _cap){  data= new int[_cap];  size=0; capacity=_cap; }
		~Stack(){	delete[] data; }
		
		//初始化，存入capacity~1车厢号 
		void init(){
			for ( int i=0; i<capacity; i++){
				data[i]=capacity-i;
			} 
			size=capacity;
		} 
		
		//push：把元素压入栈,返回该元素值 
		int push(int x) {
			if(size < capacity){
				data[size]=x;
				size++;
				return x;
			}
			else{
				return -1;
			}

		}
		
		//pop：把最后一个元素弹出栈,返回最后一个元素的值 
		int pop(){
			if(size>0){
				size--;
				return data[size];
			}
			else{
				return -1;
			}
		}
		
		//返回size
		int getsize(){  return size; }	
		
		//返回栈顶元素
		int top(){ 
			return data[size-1]; 
		}	
};



int main(){
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m);
	int aim[n];  //aim[]存储目标序列 
	for (int i=0; i<n;i++){
		scanf("%d", &aim[i]);
	}
	
	Stack *A=new Stack(n);
	A->init();
	Stack *B=new Stack(n);
	Stack *S=new Stack(m);
	
	int *output = new int[2*n];
	int j=0;  //对output计数,此外output中采用0表pop，1表示push
	 
//列车行驶的方向只能是从A到S，再从S到B	
	for( int i=0; i<n; i++){
		while( A->getsize()!=0 && (S->getsize()==0 ||S->top()<aim[i]) && S->getsize()<m){
			S->push(A->pop());   //A压入栈的条件：【A非空】，且【S空或S栈顶元素小于aim[i]】,且【S不满】 
			output[j]= 1; 
			j++;
		}
		if( S->getsize()!=0 && S->top() ==aim[i]){ //S出栈压入B的条件：S非空，且S栈顶元素等于aim[i]
			B->push(S->pop());
			output[j]= 0; 
			j++;
		}
		else{
			delete A;
	        delete B;
			delete S;
			printf("No\n");
			return 0;
		}
	}
	
    for( int i=0;i<2*n;i++){
    	if (output[i]==0)
    		printf("pop\n"); 
    	else{
    		printf("push\n");
    	}
    }
	delete A;
	delete B;
	delete S;
	delete [] output; 
	return 0;
} 


/*
测试样例1： 
5 2
1 2 3 5 4

push
pop
push
pop
push
pop
push
push
pop
pop

测试样例2：
5 5
3 1 2 4 5
No


*/ 
