#include <cstdio>
//#include <iostream>
using namespace std;
void binary_insertion_sort(int arr[], int len)
{
	int i, j, temp, m, low, high;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		low = 0; high = i - 1;
		while (low <= high)
		{
			m = (low + high) / 2;
			if (arr[m] > temp)
				high = m - 1;
			else
				low = m + 1;
		}
	}
	for (j = i - 1; j >= high + 1; j--)
		arr[j + 1] = arr[j];
	arr[j + 1] = temp;
}

int main()
{
	int a[10];
	freopen("in.txt","r",stdin);
	for(int i=0;i<10;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<10;++i)
		printf("%4d",a[i]);
//		cin>>a[i];	
    printf("\n"); 
	binary_insertion_sort(a,10);
	for(int i=0;i<10;++i)
		printf("%4d",a[i]);
	return 0;
 } 
