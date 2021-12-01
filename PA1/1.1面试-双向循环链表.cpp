#include<stdio.h>
using namespace std;


class Person{
private:
	 static int size; //�������� 		       
     Person* pre; //ǰָ��
	 Person* next;//��ָ��
	 int id;
public:
	Person(){}
	Person(int _id){ next=this;  pre=this ; id=_id; size++;}   //��ʼ����һ���� 
	Person* insert(int _id, int m);   //�ڵ�ǰԪ�غ��m��λ�õĺ�����루��ǰԪ���ǵ�1����,���ز���Ԫ�ص�ָ��
	void reverse_traverse(); 
	~Person(){ }		 
}; 

int Person::size = 0;

Person* Person::insert(int _id, int m){
	Person* temp=this;	
	for(int i=1;i<m;i++){      //���ҵ�����λ�� 
		temp=temp->next;
	}  //��ʱtempΪ������Ԫ�ص�ǰһλ��ָ��	
	//��temp��temp->next֮����뵱ǰ�ڵ� 
	Person * current=new Person();
	
	current->next = temp->next ;
	current->pre=temp; 	
	temp->next->pre=current; 
	temp->next=current;
	
	current->id=_id;
	size++;
	return  current;
  
}

void Person::reverse_traverse(){
	printf("%d ", this->id);
	Person* p=this; 
	for(int i=0;i<size-1;i++ ){		
		p= (p->pre);
		printf("%d ", p->id); 
	}
}


int main(){
	int m,n; 
    scanf("%d", &n);//size 
	scanf("%d", &m);
	 
	int* array = new int[n];	//id�������� 
	for(int i=0; i<n; i++){
		scanf("%d", &array[i]);		
	}

	Person * p0= new Person(array[0]);    //�ȳ�ʼ����һ����
	Person* temp=p0;  	                         	
	for (int j=1;j<n;j++){              //�ٷ������� 
		temp=(temp->insert(array[j], m));      //insert 				
	}                                 //���temp�������һλ�����ߵ�ָ��
	 
	temp->reverse_traverse();
	delete [] array;
	delete p0; 
	
	return 0;
}




