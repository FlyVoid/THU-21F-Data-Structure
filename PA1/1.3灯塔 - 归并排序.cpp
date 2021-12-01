#include<cstdio>
#include <stdlib.h>

using namespace std;
struct Point{
	long long  x,y;
};


long long count=0;//记录y中顺序对的个数

 
//根据x值对结构体数组排序
//此处参考网页：https://blog.csdn.net/qq_37729102/article/details/82756328?spm=1035.2023.3001.6557&utm_medium=distribute.pc_relevant_bbs_down.none-task-blog-2~all~sobaiduend~default-1.nonecase&depth_1-utm_source=distribute.pc_relevant_bbs_down.none-task-blog-2~all~sobaiduend~default-1.nonecase 
//对归并排序算法进行了优化：只要B越界了就不用再排序了 
void mergeX(Point* elem,int lo,int mi,int hi) {
   Point* A = elem+lo;                    //合并后的向量A[0, hi - lo) = elem[lo, hi)
   int lb = mi-lo; Point* B = new Point[lb+3];   //前子向量B[0, lb) = elem[lo, mi)
   for ( int i=0; i<lb; i++ )  B[i]=A[i];;    //复制前子向量
   int lc = hi-mi; Point* C = elem + mi;  //后子向量C[0, lc) = elem[mi, hi)
	for(int i=0,ib=0,ic=0;ib<lb;)  //只要B越界了就不用再排序了，这里对归并排序算法进行了优化 
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



//对Y值进行排序 
void mergeY(Point *elem,int lo,int mi,int hi){   	
	Point* A = elem+lo;                    //合并后的向量A[0, hi - lo) = elem[lo, hi)
	int lb = mi-lo; Point* B = new Point[lb+3];   //前子向量B[0, lb) = elem[lo, mi)
	for ( int i=0; i<lb;i++)  B[i]=A[i];    //复制前子向量
	int lc = hi-mi; Point* C = elem + mi;  //后子向量C[0, lc) = elem[mi, hi)

	for(int i=0,ib=0,ic=0;ib<lb;)  //只要B越界了就不用再排序了 
	{
		if(  lc<=ic  ||  B[ib].y<C[ic].y  ){
			A[i++]=B[ib++];     
			if(ic<lc) 
				count+=lc-ic;   //只要ic不越界，那么ic之后的元素个数+1就是顺序对数	
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
		
	mergeSortX(points,0,n);  //对X进行排序 
	
	mergeSortY(points,0,n);    //对Y进行排序 
	
	printf("%lld\n",count);
	delete[]  points;
	return 0;
}

/*
测试数据： 
3
2 2
4 3
5 1
*/ 
