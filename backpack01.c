/*
* @Author: barry_g
* @Date:   2018-11-30 12:54:05
* @Last Modified by:   barry_g
* @Last Modified time: 2018-11-30 13:01:48
*/
#include<stdio.h>
/**
 * 01背包问题，动态规划求解
 */
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
/**
 * [getAns 求解方法]
 * @param  s [背包容量]
 * @param  n [物品个数]
 * @param  w [存放物品重量的数组]
 * @param  v [存放物品价值的数组]
 * @return   [description]
 */
int getAns(int s,int n,int w[],int v[])
{
    int i,j;
    int ans[n +1][s + 1];
    //初始化第一个物品
    for(j=0;j<=s;j++) ans[1][j]=w[1]<=j?v[1]:0;
    for(i=2;i<=n;i++)
    {
        int jmin=w[i]<s?w[i]:s;
        //物品重量大于容量的情况
        for(j=0;j<jmin;j++) ans[i][j]=ans[i-1][j];
        //物品重量小于容量的情况
        for(j=w[i];j<=s;j++){
        	ans[i][j]=max(ans[i-1][j],ans[i-1][j-w[i]]+v[i]);
        }
    }
    return ans[n][s];
}
int main()
{
    int i,answer;
    int s;
    int n;
    printf("Please enter the capacity of the backpack and the number of items：\n");
    scanf("%d %d",&s,&n);
    int w[n+1];
    int v[n+1];
    printf("Please enter the weight and value of the item in turn：\n");
    for(i=1;i<=n;i++) scanf("%d %d",&w[i],&v[i]);
    answer=getAns(s,n,w,v);
    printf("Maximum value：%d\n",answer);
    return 0;
}