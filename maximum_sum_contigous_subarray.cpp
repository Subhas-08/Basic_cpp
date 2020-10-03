//to find maximum sum contigous subsrray .This is also known as kadane's algorithm;
//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
//Input:
//The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

//Output:
//Print the maximum sum of the contiguous sub-array in a separate line for each test case

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    //to input test case
    int t;
    cin>>t;
    while(t--){
    int n;//inputting size of array
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    cin>>ar[i];
    int b[n];//another auxillary array to keep max sum visited till now
    b[0]=ar[0];
    for(int i=1;i<n;i++){
        b[i]=max(b[i-1]+ar[i],ar[i]);
    }
    cout<<*max_element(b,b+n)<<endl;//to calculate max element in b array
    }
	//code
	return 0;
}