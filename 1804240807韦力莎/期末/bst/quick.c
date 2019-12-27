#include <stdio.h>
#include "stdafx.h"

 
void quick_sort(int s[], int l, int r)
{
    int i, j, x;
    if (l < r)
    {
        i = l;
        j = r;
        x = s[i];
        while (i < j)
        {
            while(i < j && s[j] > x) 
				j--; /* 从右向左找第一个小于x的数 */
            if(i < j) 
				s[i++] = s[j];
	
 
            while(i < j && s[i] < x) 
				i++; /* 从左向右找第一个大于x的数 */
            if(i < j) 
				s[j--] = s[i];
 
        }
        s[i] = x;
        quick_sort(s, l, i-1); /* 递归调用 */
        quick_sort(s, i+1, r);
    }
}
 
 
int _tmain(int argc, _TCHAR* argv[])
{
	
	int a[]={49,38,65,97,76,13,27};
	int l = 0;
	int r = 6;
	quick_sort(a,l,r);
 
	for(int i=0;i<=r;i++)
		printf("%4d",a[i]);
	return 0;
}