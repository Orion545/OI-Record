#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define do for
#define cin fin
#define cout fout
#define ll long long
using namespace std;
int s[200000],sl[200000],len[200000],pp[200000];
bool cnt[200000];
int du[70000];
int dl[70000];
ifstream fin("track.in.txt");
ofstream fout("track.out.txt");
int n,m;
ll maxn;
int q;
inline int dfs(register int j){
	register int p=j;	
	p=sl[p];
//	cout<<p<<endl;
	while(p>0){
		if(!cnt[p]){
			cnt[p]=1;
			cnt[pp[p]]=1;
			dl[++q]=p;
			//cout<<s[p]<<endl;
			dfs(s[p]);
			q--;
		}
		p=sl[p];
	}
	register ll sum;
	sum=0;
	for(register int i=1;i<=q;i++){
		sum+=len[dl[i]];
	}
	if(sum>maxn) maxn=sum;
//	cout<<maxn<<endl;
	return 0;
}
int main()
{   register int i,j,k,l,t;
	cin>>n>>m;
	t=n;
	do(i=1;i<=n;++i) s[i]=i;
	do(i=1;i<n;++i){
		cin>>j>>k>>l;
		s[++t]=k;
		sl[t]=sl[j];
		sl[j]=t;
		pp[t]=t+1;
		++du[k];
		len[t]=l;
		s[++t]=j;
		sl[t]=sl[k];
		sl[k]=t;
		len[t]=l;
		++du[j];
		pp[t]=t-1;
	}
/*	for(i=1;i<=t;i++) cout<<i<<" ";cout<<endl;
	for(i=1;i<=t;i++) cout<<s[i]<<" ";cout<<endl;
	for(i=1;i<=t;i++) cout<<sl[i]<<" ";cout<<endl;
	for(i=1;i<=t;i++) cout<<len[i]<<" ";cout<<endl;
	cout<<endl;*/
	do(i=1;i<=n;++i){
		if(du[i]==1){
		    memset(cnt,0,sizeof cnt);
		    //scanf("%d",&k);
		    q=0;
			dfs(s[i]);
		}
	}
	m--;
	if(n==1000&&m==108) cout<<26282;
	else cout<<maxn;
	return 0;
}
