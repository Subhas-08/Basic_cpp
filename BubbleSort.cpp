using namespace std;
#include<iostream>
void BubbleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main()
{
	int a[]={7,9,5,2,4,1,10};
	BubbleSort(a,7);
	for(int i=0;i<7;i++)
	{
	cout<<" "<<a[i];
	}
		return 0;	
}
