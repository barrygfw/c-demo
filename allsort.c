/**
 * 全排列
 */
#include <stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}
void Perm(int list[],int k,int m)
{
    int i;
    if(k==m)
    {
        for(i=0;i<=m;i++)
            printf("%d\t",list[i]);
        printf("\n");
    }
    else{
        for(i=k;i<=m;i++)
        {
            swap(&list[k],&list[i]);
            Perm(list,k+1,m);
            swap(&list[k],&list[i]);
        }
    }
}
int main()
{
    int num,i,j;
    printf("please input allsort numbers:");
    scanf("%d",&num);
    int list[num];
    for(i=0;i<num;i++)
    {
        list[i] = i+1;
    }
    Perm(list,0,i-1);
    return 0;
}
