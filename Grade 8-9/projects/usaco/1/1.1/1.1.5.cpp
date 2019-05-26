/*
ID: marcoli2
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int n,ans[20],money[20],num[20];
bool a[15][15];
map<string,int>m;
map<int,string>ma;
int main(){
	int i,j,tmp;string t1;
	std::ios::sync_with_stdio(false);
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>t1;m[t1]=i;ma[i]=t1;
	}
	for(i=1;i<=n;i++){
		cin>>t1;
		tmp=m[t1];
		cin>>money[tmp]>>num[tmp];
//		cout<<"map of "<<t1<<ends<<tmp<<endl;
		for(j=1;j<=num[tmp];j++){
			cin>>t1;
			a[tmp][m[t1]]=1;
		}
	}
//	cout<<"calc"<<endl;
	for(i=1;i<=n;i++){
//		cout<<i<<endl;
		if(num[i]==0){
			ans[i]+=money[i];continue;
		}
		ans[i]+=((money[i]%num[i])-money[i]);
		for(j=1;j<=n;j++){
//			cout<<"	"<<j<<endl;
			if(a[i][j]) ans[j]+=money[i]/num[i];
		}
	}
//	cout<<"calc end"<<endl;
	for(i=1;i<=n;i++){
		cout<<ma[i]<<" "<<ans[i]<<"\n";
	}
}
