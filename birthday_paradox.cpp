#include<bits/stdc++.h>
using namespace std;

// this function returns 
// the number of people required in room to have 
// probability of p to have atleast 2 people with their birthday on same day 
// input: probability p (between 0 to 1)
// output: number of people required
int birthday_paradox(double p) 
{ 
    if(p<0 or p>1)
        return -1;
    if(p==1)
        return 367;
    return ceil(sqrt(2*365*log(1/(1-p)))); 
} 

int main(){

    // example
    cout<<birthday_paradox(1)<<endl;
    cout<<birthday_paradox(0.5)<<endl;
    cout<<birthday_paradox(0.9)<<endl;
    
    return 0;
}