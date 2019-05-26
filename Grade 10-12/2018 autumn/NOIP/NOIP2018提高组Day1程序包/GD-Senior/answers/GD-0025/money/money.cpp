#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
#define maxn 105
#define cin fin
#define cout fout
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
int ans=0;
int n;
int s[maxn];
bool dfs(int now,bool status){
	if(now==0){
		return false;	
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(now<s[i]) continue;
		if(status==true&&now==s[i]) continue;
		int cnt=1;
		while(now>=s[i]*cnt){
			flag&=dfs(now%(s[i]*cnt),false); 
			if(flag==false) return flag;
			cnt++;
		}
	}
	return flag;
}
int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		if(n==2){
			if(s[1]%s[2]==0||s[2]%s[1]==0){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<2<<endl;
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			if(dfs(s[i],true)==true){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
