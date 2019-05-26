#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

const int maxn=25050;
int T,n,m;
int a[maxn];

void init(){
	int j;
	fin>>n;
	for(j=1;j<=n;j++) fin>>a[j];	
	sort(a,a+n+1);
}

void find(){
	int i,t,mod;
	a[0]=-1;
	m=1;
	if(a[2]%a[1]!=0) m++;
	for(i=3;i<=n;i++){
		t=i-1;//cout<<t<<endl;
		mod=a[i]%a[t];//cout<<a[i]<<" "<<a[t]<<mod<<endl;
		while(mod!=0&&t>1){
			t--;
			mod=mod%a[t];//cout<<"i:"<<i<<" "<<mod<<endl;
		}
		//cout<<"i:"<<i<<" "<<mod<<endl;
		if(mod%a[1]!=0) t=0; 
		//cout<<"i:"<<i<<" "<<t<<endl;
		if(t==0) m++;
		//cout<<endl<<endl;
	}
	fout<<m<<endl;
}

int main(){
	int i,j,k;
	
	fin>>T;
	for(i=1;i<=T;i++){
		init();
		find();
	}
	fin.close();
	fout.close();
	return 0;
}
