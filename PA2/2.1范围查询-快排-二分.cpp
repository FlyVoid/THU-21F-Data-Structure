#include <stdio.h>


int s[500010];

 //���ֲ��Ҳ��������� 
 int binSearch_right(int num,int lo,int hi){
     while(lo<hi){
         int mi=(lo+hi)/2;
         if(num<s[mi]) hi=mi;   
         else if(num==s[mi]) return mi;
         else  lo=mi+1;  
     }
     return lo-1;
 }
 
 //���ֲ��������� 
  int binSearch_left(int num,int lo,int hi){
  	 if(lo==hi) return lo;
     while(lo<hi){
         int mi=(lo+hi)/2;
         if(num<s[mi]) hi=mi;      
         else if(num==s[mi]) return mi;
         else  lo=mi+1; 
     }
     return lo;
 }
  
//�ο�����������ε�������ݽṹ��
int Paritition1(int A[], int low, int high) {
   int pivot = A[low];
   while (low < high) {
     while (low < high && A[high] >= pivot) {
       --high;
     }
     A[low] = A[high];
     while (low < high && A[low] <= pivot) {
       ++low;
     }
     A[high] = A[low];
   }
   A[low] = pivot;
   return low;
 }

 void QuickSort(int A[], int low, int high) //����ĸ����
 {
   if (low < high) {
     int pivot = Paritition1(A, low, high);
     QuickSort(A, low, pivot - 1);
     QuickSort(A, pivot + 1, high);
   }
 }


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }
    //�ȿ�����������s[], ����(s,s+n); 
     QuickSort(s,0,n-1);
  
    
	for (int i = 0; i < m; ++i) {
        //�������� 
		int a, b;
        scanf("%d %d", &a, &b);
        
        if (a > s[n-1] || b < s[0]) { 
           printf("0\n");
        }
        else if(b>=s[n-1]){ 	//���ڵ��ڵ�ʱ��ֱ�ӷ���������n-1 
			 printf("%d\n",n-1-binSearch_left(a,0,n-1)+1);
        }
        else {
			 printf("%d\n",binSearch_right(b,0,n-1)-binSearch_left(a,0,n-1)+1);
        }
    }
    return 0;    
}

