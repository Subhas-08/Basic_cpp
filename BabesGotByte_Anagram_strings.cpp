#include<iostream>
using namespace std;
#include<bits/stdc++.h>


bool check_anagram(string a, string b){
    map<char,int> m;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        if(m.find(b[i])!=m.end()){
            m[b[i]]--;
        }
        else{
            return false;
        }
    }
    for(auto itr=m.begin();itr!=m.end();itr++){
        if(itr->second==0){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){

	string a="";
	string b="";
	
	cin>>a>>b;
	bool answer;
	answer=check_anagram(a,b);
    cout<<answer;

	return 0;
}
