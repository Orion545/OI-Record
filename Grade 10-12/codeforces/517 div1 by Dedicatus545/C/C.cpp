#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n;bool a[100010];
vector<int>cnt[3];int re;
int cnta,al[100010],ar[100010],am[100010];
int main(){
	n=read();int i,cur,len,tl,tr;
	for(i=1;i<=n;i++){
		a[i]=read();
	}
	if(n>12){
		for(cur=1;cur<=min(n/3,90);cur++){
			for(i=cur+1;i<=n-cur;i++){
				if(a[i-cur]&&a[i]&&a[i+cur]){
					cout<<"get "<<i<<' '<<cur<<'\n';
					a[i-cur]=a[i]=a[i+cur]=0;
					cnta++;
					al[cnta]=i-cur;
					am[cnta]=i;
					ar[cnta]=i+cur;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		cout<<i<<' '<<a[i]<<'\n';
		if(a[i]) cnt[i%3].push_back(i);
	}
	cout<<"tmp fin "<<cnta<<' '<<cnt[0].size()<<' '<<cnt[1].size()<<' '<<cnt[2].size()<<'\n';
	for(cur=0;cur<3;cur++){
		len=cnt[cur].size();
		for(i=0;i<len/2;i++){
			//do cnt[cur][i], cnt[cur][len-1-i]
			tl=cnt[cur][i]+(cnt[cur][len-1-i]-cnt[cur][i])/3;
			tr=cnt[cur][len-1-i]-(cnt[cur][len-1-i]-cnt[cur][i])/3;
			cnta++;
			al[cnta]=cnt[cur][i];
			am[cnta]=tl;ar[cnta]=tr;
			cnta++;
			al[cnta]=tl;am[cnta]=tr;
			ar[cnta]=cnt[cur][len-i-1];
		}
		if(len&1){
			//singly do i(i+1)
			re=cnt[cur][i];
//			cout<<"*** "<<cur<<' '<<n<<' '<<re<<' '<<i<<'\n';
			if(!((re>3&&re<=(n-3))||(re>6)||(re<=(n-6)))){
				puts("NO");return 0;
			}
			if(re>6){
				cnta++;
				al[cnta]=re-6;am[cnta]=re-3;ar[cnta]=re;
				cnta++;
				al[cnta]=re-6;am[cnta]=re-5;ar[cnta]=re-4;
				cnta++;
				al[cnta]=re-5;am[cnta]=re-4;ar[cnta]=re-3;
			}
			else{
				if(re<=(n-6)){
					cnta++;
					ar[cnta]=re+6;am[cnta]=re+3;al[cnta]=re;
					cnta++;
					ar[cnta]=re+6;am[cnta]=re+5;al[cnta]=re+4;
					cnta++;
					ar[cnta]=re+5;am[cnta]=re+4;al[cnta]=re+3;
				}
				else{
					cnta++;
					al[cnta]=re-3;am[cnta]=re;ar[cnta]=re+3;
					cnta++;
					al[cnta]=re-3;am[cnta]=re-1;ar[cnta]=re+1;
					cnta++;
					al[cnta]=re-1;am[cnta]=re+1;ar[cnta]=re+3;
				}
			}
		}
	}
	puts("YES");
	cout<<cnta<<'\n';
	for(i=1;i<=cnta;i++){
		printf("%d %d %d\n",al[i],am[i],ar[i]);
	}
	return 0;
}
/*
7
0 0 0 1 0 0 0

8
1 1 1 1 0 1 0 0

*/		
