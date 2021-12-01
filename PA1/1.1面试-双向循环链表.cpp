#include<stdio.h>
using namespace std;


class Person{
private:
	 static int size; //桌上人数 		       
     Person* pre; //前指针
	 Person* next;//后指针
	 int id;
public:
	Person(){}
	Person(int _id){ next=this;  pre=this ; id=_id; size++;}   //初始化第一个人 
	Person* insert(int _id, int m);   //在当前元素后的m个位置的后面插入（当前元素是第1个）,返回插入元素的指针
	void reverse_traverse(); 
	~Person(){ }		 
}; 

int Person::size = 0;

Person* Person::insert(int _id, int m){
	Person* temp=this;	
	for(int i=1;i<m;i++){      //先找到插入位置 
		temp=temp->next;
	}  //此时temp为待插入元素的前一位的指针	
	//在temp和temp->next之间插入当前节点 
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
	 
	int* array = new int[n];	//id存入数组 
	for(int i=0; i<n; i++){
		scanf("%d", &array[i]);		
	}

	Person * p0= new Person(array[0]);    //先初始化第一个人
	Person* temp=p0;  	                         	
	for (int j=1;j<n;j++){              //再放其他人 
		temp=(temp->insert(array[j], m));      //insert 				
	}                                 //最后temp就是最后一位面试者的指针
	 
	temp->reverse_traverse();
	delete [] array;
	delete p0; 
	
	return 0;
}




