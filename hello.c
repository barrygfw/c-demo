/*
* @Author: barry
* @Date:   2018-09-28 11:15:07
* @Last Modified by:   barry
* @Last Modified time: 2018-09-28 12:57:46
*/
#include <stdio.h>
int a[10] = {6,1,2,7,9,3,4,5,10,8};
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void quickSort(int left,int right){
	if(left>right)
		return;
	int i=left,j=right,x=a[left];
	while(j>i){
		while(j>i && a[j]>=x)
			j--;
		while(j>i && a[i]<=x)
			i++;
		if(j>i)
			swap(&a[i],&a[j]);
	}
	swap(&a[left],&a[i]);
	quickSort(left,i-1);
	quickSort(i+1,right);
}
int main()
{
	quickSort(0,9);
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}