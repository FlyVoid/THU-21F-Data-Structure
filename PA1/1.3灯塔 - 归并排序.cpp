#include<cstdio>
#include <stdlib.h>

using namespace std;
struct Point{
	long long  x,y;
};


long long count=0;//��¼y��˳��Եĸ���

 
//����xֵ�Խṹ����������
//�˴��ο���ҳ��https://blog.csdn.net/qq_37729102/article/details/82756328?spm=1035.2023.3001.6557&utm_medium=distribute.pc_relevant_bbs_down.none-task-blog-2~all~sobaiduend~default-1.nonecase&depth_1-utm_source=distribute.pc_relevant_bbs_down.none-task-blog-2~all~sobaiduend~default-1.nonecase 
//�Թ鲢�����㷨�������Ż���ֻҪBԽ���˾Ͳ����������� 
void mergeX(Point* elem,int lo,int mi,int hi) {
   Point* A = elem+lo;                    //�ϲ��������A[0, hi - lo) = elem[lo, hi)
   int lb = mi-lo; Point* B = new Point[lb+3];   //ǰ������B[0, lb) = elem[lo, mi)
   for ( int i=0; i<lb; i++ )  B[i]=A[i];;    //����ǰ������
   int lc = hi-mi; Point* C = elem + mi;  //��������C[0, lc) = elem[mi, hi)
	for(int i=0,ib=0,ic=0;ib<lb;)  //ֻҪBԽ���˾Ͳ����������ˣ�����Թ鲢�����㷨�������Ż� 
	{
		if(  lc<=ic  ||  B[ib].x<C[ic].x  )    A[i++]=B[ib++];
		if(  ic<lc   &&  C[ic].x<=B[ib].x )    A[i++]=C[ic++];
	}
	delete [] B; 
}

void mergeSortX ( Point * elem, int lo, int hi ) {  
	if (hi-lo<2) return; 
	int mi = (lo+hi)/2; 
	mergeSortX (elem,lo,mi); 
	mergeSortX (elem,mi,hi); 
	mergeX(elem,lo,mi,hi); 
}



//��Yֵ�������� 
void mergeY(Point *elem,int lo,int mi,int hi){   	
	Point* A = elem+lo;                    //�ϲ��������A[0, hi - lo) = elem[lo, hi)
	int lb = mi-lo; Point* B = new Point[lb+3];   //ǰ������B[0, lb) = elem[lo, mi)
	for ( int i=0; i<lb;i++)  B[i]=A[i];    //����ǰ������
	int lc = hi-mi; Point* C = elem + mi;  //��������C[0, lc) = elem[mi, hi)

	for(int i=0,ib=0,ic=0;ib<lb;)  //ֻҪBԽ���˾Ͳ����������� 
	{
		if(  lc<=ic  ||  B[ib].y<C[ic].y  ){
			A[i++]=B[ib++];     
			if(ic<lc) 
				count+=lc-ic;   //ֻҪic��Խ�磬��ôic֮���Ԫ�ظ���+1����˳�����	
		}
		if(  ic<lc   &&  C[ic].y<=B[ib].y )    A[i++]=C[ic++];
	}
	delete [] B;
}
void mergeSortY(Point* elem,int lo,int hi){
	if(hi-lo<2)return;
	int mi=(hi+lo)>>1;
	mergeSortY(elem,lo,mi);
	mergeSortY(elem,mi,hi);
	mergeY(elem,lo,mi,hi);
}

int main()
{
	int n;
	scanf("%d",&n);
	Point *points =new Point[3*n];
	for(int i=0;i<n;i++)
		scanf("%lld %lld",&points[i].x,&points[i].y);		
		
	mergeSortX(points,0,n);  //��X�������� 
	
	mergeSortY(points,0,n);    //��Y�������� 
	
	printf("%lld\n",count);
	delete[]  points;
	return 0;
}

/*
�������ݣ� 
3
2 2
4 3
5 1
*/ 
