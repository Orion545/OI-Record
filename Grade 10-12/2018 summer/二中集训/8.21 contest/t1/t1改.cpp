#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque> 
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n;char s[1000010],t[1000010];
deque<int>q;
int main(){
	n=read();int i,ans=0,j=n,add=0,now;
	scanf("%s",s);scanf("%s",t);
	q.push_back(n);
	for(i=n-1;i>=0;i--){
		now=j;
		while(~j&&((j>i)|(s[j]!=t[i]))) j--;
//		cout<<i<<' '<<j<<' '<<now<<'\n'; 
		if(j==-1){
			puts("-1");return 0;
		}
		if(now==j){
			while(!q.empty()&&q.back()-add>=i) q.pop_back();
			q.push_back(i+add);
		}
		else{
			add++;
			if(i!=j){
				ans=((ans<q.size())?q.size():ans);
				q.push_front(j+add);
			}
		}
	}
	printf("%d\n",ans);
} 
