/*
* @Author: barry_g
* @Date:   2018-10-12 10:49:10
* @Last Modified by:   barry_g
* @Last Modified time: 2018-11-30 12:34:52
*/
/**
 * 最大子段和
 */
#include <stdio.h>
#define MAX 100
int a[MAX];
int L=0;
int R=0;
int answer=0;
/**
 * [maxsub 最大子段和函数]
 * @param  a     [保存数字的数组]
 * @param  left  [左边界]
 * @param  right [右边界]
 * @return       [最大子段和]
 */
int maxsub(int *a,int left,int right){
	int i,l,r;
	int center;
	int sum,left_sum=0,right_sum=0;//left_sum左子段最大子段和、right_sum右子段最大子段和
	int left_max=0,right_max=0;//left_max中间往左最大子段和、right_max中间往右最大子段和
	center = (left+right)/2;
	//递归出口
	if(left==right){	
		if(a[left]>0)
			return a[left];
		else
			return 0;
	}else{
		//递归
		left_sum = maxsub(a,left,center);
		right_sum = maxsub(a,center+1,right);
		//求中间往左最大子段和
		sum = 0;
		l=center;
		for(i=center;i>=left;i--){
			sum+=a[i];
			if(sum>left_max){
				l=i;
				left_max = sum;
			}
		}
		//求中间往右最大子段和
		sum=0;
		r=center;
		for(i=center+1;i<=right;i++){
			sum+=a[i];
			if(sum>right_max){
				r=i;
				right_max = sum;
			}
		}
		sum = left_max+right_max;
		//判断最大子段和是在中间还是在两边
		if(sum<left_sum){
			sum = left_sum;
		}
		if(sum<right_sum)
			sum = right+sum;
		if(sum>answer){
			answer=sum;L=l;R=r;
		}
	}
	return sum;
}
int main()
{
	int count,i;
	printf("please input array length:\n");
	scanf("%d",&count);
	printf("please input %d numbers：\n",count);
	for(i=0;i<count;i++){
		scanf("%d",&a[i]);
	}
	maxsub(a,0,count-1);
	printf("the MaxSubNum is:%d\nthe answer index of (%d,%d)",answer,L,R);
	return 0;
}