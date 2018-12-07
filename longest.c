/*
* @Author: barry_g
* @Date:   2018-12-07 13:57:42
* @Last Modified by:   barry_g
* @Last Modified time: 2018-12-07 13:59:46
*/
#include <stdio.h>

#define MAX_N 1001

int arr[MAX_N];
int longest_num[MAX_N];
int bt[MAX_N];
int max_point = 0;

int LIS(int n)
{
    int max = 1;  //最长上升子序列的个数
    int i,j;
    for (i = 0; i < n; i++)   //i下标之前(包括i)的最长上升子序列的个数
    {
        longest_num[i] = 1;
    }
    for (i = 0; i < n; i++)   //用于回溯
    {
        bt[i] = -1;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && longest_num[i] < longest_num[j] + 1)
            {
                longest_num[i] = longest_num[j] + 1;
                bt[i] = j;
                if (longest_num[i] >= max)
                {
                    max = longest_num[i];
                    max_point = i;
                }
            }
        }
    }
    return max;
}

void backtrack(int point)
{
    if (-1 == bt[point])
    {
        printf("%d ",arr[point]);
        return;
    }
    else
    {
        backtrack(bt[point]);
        printf("%d ",arr[point]);
    }
}

int main()
{
    int n,i,ret;
    printf("请输入序列长度：\n");
    scanf("%d",&n);
    int nums[n];
    printf("请输入序列内容：\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    ret = LIS(n);
    printf("%d\n",ret);

    backtrack(max_point);
    printf("\n");

    return 0;
}
