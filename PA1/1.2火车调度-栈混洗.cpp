
#include<stdio.h>
#include <stdlib.h>
using namespace std;

//��������ջ��ϴ,ջ����vector����Ʒ�����ջ�ײ����䣬ֻ�ܴ�ջ��pop��push���� 

class Stack{
	private:
		int size;  //ջ��ʵ��Ԫ�ظ���
		int capacity;   //ջ���� 
		int* data;  //ָ�����飬�洢����� 		
	public:
		//���캯������������ 
		Stack(int _cap){  data= new int[_cap];  size=0; capacity=_cap; }
		~Stack(){	delete[] data; }
		
		//��ʼ��������capacity~1����� 
		void init(){
			for ( int i=0; i<capacity; i++){
				data[i]=capacity-i;
			} 
			size=capacity;
		} 
		
		//push����Ԫ��ѹ��ջ,���ظ�Ԫ��ֵ 
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
		
		//pop�������һ��Ԫ�ص���ջ,�������һ��Ԫ�ص�ֵ 
		int pop(){
			if(size>0){
				size--;
				return data[size];
			}
			else{
				return -1;
			}
		}
		
		//����size
		int getsize(){  return size; }	
		
		//����ջ��Ԫ��
		int top(){ 
			return data[size-1]; 
		}	
};



int main(){
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m);
	int aim[n];  //aim[]�洢Ŀ������ 
	for (int i=0; i<n;i++){
		scanf("%d", &aim[i]);
	}
	
	Stack *A=new Stack(n);
	A->init();
	Stack *B=new Stack(n);
	Stack *S=new Stack(m);
	
	int *output = new int[2*n];
	int j=0;  //��output����,����output�в���0��pop��1��ʾpush
	 
//�г���ʻ�ķ���ֻ���Ǵ�A��S���ٴ�S��B	
	for( int i=0; i<n; i++){
		while( A->getsize()!=0 && (S->getsize()==0 ||S->top()<aim[i]) && S->getsize()<m){
			S->push(A->pop());   //Aѹ��ջ����������A�ǿա����ҡ�S�ջ�Sջ��Ԫ��С��aim[i]��,�ҡ�S������ 
			output[j]= 1; 
			j++;
		}
		if( S->getsize()!=0 && S->top() ==aim[i]){ //S��ջѹ��B��������S�ǿգ���Sջ��Ԫ�ص���aim[i]
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
��������1�� 
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

��������2��
5 5
3 1 2 4 5
No


*/ 
