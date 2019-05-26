#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	string s;getline(cin,s);int n=s.length();
	int ans=0,tmp=0,i,j,flag=1;
	for(i=0;i<n;i++){
		cout<<i<<ends<<tmp<<ends<<ans<<endl;
		if(s[i]=='+'||s[i]=='-'){
			ans+=tmp*flag;
			if(s[i]=='+') flag=1;
			else flag=-1;
			tmp=0;
		}
		else{
			tmp=tmp*10+(s[i]-'0');
		}
	}
	ans+=tmp*flag;
	cout<<ans<<endl;
}
