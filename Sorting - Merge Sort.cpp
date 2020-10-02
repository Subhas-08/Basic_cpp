
  // Sorting - Merge Sort

#include<iostream>
using namespace std;
void Merge(int A[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];
    for(i=0;i<n1;i++)
       L[i]=A[l+i];
    for(j=0;j<n2;j++)
       R[j]=A[m+1+j];

    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
      if(L[i]<=R[j]){
          A[k]=L[i];
          i++;
      }else{
         A[k]=R[j];
         j++;
       }
      k++;
    }
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
     while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}
void Mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        Mergesort(arr,l,m);
        Mergesort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}
int main()
{
    int arr[]={2,1,3,4,8,5,7,6};
    int arr_size=sizeof(arr)/sizeof(arr[0]);

    cout<<"Given array :\n";
    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";

    Mergesort(arr,0,arr_size-1);

    cout<<"\n\nAfter sorting :\n";
    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";
    cout<<"\n\n";
}
