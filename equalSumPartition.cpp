#include <iostream>
using namespace std;

bool SubsetSum(int arr[],int n, int sum)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
             if(i==0)
               t[i][j]=false;
            else if(j==0)
               t[i][j]=true;
            else if(arr[i-1]<=j)  
                t[i][j]=t[i-1][j-arr[i-1]] ||t[i-1][j];
            else
               t[i][j]=t[i-1][j];  //exclude
        }
    }
 return t[n][sum];
}
bool EqualSumPartition(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
       sum+=arr[i];
    if(sum%2!=0)
         return false;
    else
        return SubsetSum(arr,n,sum/2);
}
int main()
{
	    int n;
	    cout<<"array size : ";
	    cin>>n;
	    int arr[n];
	    cout<<"array element :\n";
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	  if(EqualSumPartition(arr,n))
	     cout<<"YES"<<endl;
	   else

	     cout<<"Not Possible"<<endl;
	return 0;
}
