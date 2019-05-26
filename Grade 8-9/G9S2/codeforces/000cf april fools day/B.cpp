#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	int n=10,i;string s;
	for(i=0;i<n;i++){
		fflush(stdin);fflush(stdout);
		cout<<i<<endl;
		getline(cin,s);
		fflush(stdin);fflush(stdout);
		if(s=="no") continue;
		if(s=="no way"||s=="don't even"||s=="worse"||s=="terrible"||s=="are you serious"||s=="go die in a hole"){
			cout<<"grumpy"<<endl;return 0;
		}
		else{
			cout<<"normal"<<endl;return 0;
		}
	}
}
