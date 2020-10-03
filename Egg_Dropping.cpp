#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int Egg_Dropping(int e, int f)
{
	//Base Case
	if(e==1)
		return f;
	if(f==0||f==1)
		return f;
	//Memoization
	if(t[e][f]!=-1)
		return t[e][f];
	//K loop
	int mn = INT_MAX;
	for(int k=1; k<=f; k++)
	{
		//taking max in the next line because we've to consider the worst case senario
		int temp_ans = 1 + max(Egg_Dropping(e-1,k-1),Egg_Dropping(e,f-k));
		mn = min(mn,temp_ans); //Min because we've to minimize num of attemps in the worst case	
	}
	t[e][f] = mn;
	return mn;	
}

int main()
{
	int e,f;
	cin>>e>>f;
	memset(t,-1,sizeof(t));
	cout<<Egg_Dropping(e,f)<<endl;
	return 0;
}
