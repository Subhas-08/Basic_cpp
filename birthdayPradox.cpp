// C++ program to approximate number of people in Birthday Paradox 
// problem 
//Using the above approximate formula sqrt(2*365*log(1/(1-p)) , we can approximate number of people for a given probability.
//The questiopn is to find the number of person we should have so that the probability that any 2 of them have their birthday on the same date is n.

#include <math.h> 
#include <iostream> 
using namespace std; 
int find(double p) 
{ 
	return ceil(sqrt(2*365*log(1/(1-p)))); 
} 
int main() 
{ 
int n;//probability for which we have to find
cout << find(n)<<endl; 
} 
