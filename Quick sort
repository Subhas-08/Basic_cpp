
  // Sorting - Quick Sort

#include<iostream>
using namespace std;

int partition(int A[],int start,int end)
{
    int pivot=A[end];
    int pIndex=start;
    for(int i=start;i<end;i++)
    {
        if(A[i]<=pivot)
        {
            swap(A[i],A[pIndex]);
            pIndex+=1;
        }
    }
    swap(A[pIndex],A[end]);
    return pIndex;
}
/*void randomized partition(int A[],int start,int end)
{
    int Pivot Index=rand(start,end);
    swap(A[Pivot Index],A[end]);
    Partition(A,start,end);
}*/
void QuickSort(int A[],int start,int end)
{
  if(start<end)
  {
      int pIndex=/*randomized*/  partition(A,start,end);
      QuickSort(A,start,pIndex-1);
      QuickSort(A,pIndex+1,end);
  }
}
int main()
{
    int arr[]={10,7,1,18,2,9,11,4};
    int arr_size=sizeof(arr)/sizeof(arr[0]);

    cout<<"Given array : \n";
    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";

    QuickSort(arr,0,arr_size-1);

    cout<<"\n\nSorted array : \n";
    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";
}
