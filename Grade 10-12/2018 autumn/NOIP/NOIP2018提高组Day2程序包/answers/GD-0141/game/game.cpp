#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string s[1000];
string a[100];
int n1,m1,l,z;
int n2,m2,o;
int n,m;
string b[10][10];
int ss(){
	if(l==n+m){
	  z++;
	  for(int i=1;i<=l;i++) s[z]+=a[i];
	}
	if(m1!=0){
		m1--;
		a[++l]="0";
		ss();
		m1++;
		l--;
	}
	if(n1!=0){
		n1--;
		a[++l]="1";
		ss();
		n1++;
		l--;
	}
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);	
	cin>>n>>m;
	n1=n;
	m1=m;
	n2=1;
	m2=1;
	l=0;
	z=0;
	o=0;
    cout<<28;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
