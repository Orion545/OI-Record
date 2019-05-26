#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#include<queue>
#define pb push_back
#define ll long long
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
int XGOD_FOREVER[2010][2010],vis[2010][2010]; 
pair<int,int> pre[2010][2010]; 
char c[2010][2010];
int main(){	
int n,m,cur=0,ans=0; 
	n=read();m=read();int i;
	vector<pair<int,int> > v[2];
	for(i=1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
	v[0].pb(make_pair(1,1));
	deque<pair<int,int> > q; 
	XGOD_FOREVER[1][1]=(c[1][1]!='a'); 
	if(XGOD_FOREVER[1][1]<=m) 
		q.pb(make_pair(1,1));
		

	while(!q.empty()){	
		int DSG=q.front().first,SJK=q.front().second; 
		q.pop_front();
		if(DSG==n&&SJK==n){
			for(i=1;i<=n*2-1;i++) 
				putchar('a');
			return 0;
		}
		if(XGOD_FOREVER[DSG][SJK]==m){	
			if(DSG+SJK-1>ans){
				ans=DSG+SJK-1;
				v[0].clear();
				v[0].pb(make_pair(DSG,SJK));
			}
			else if(DSG+SJK-1==ans) v[0].pb(make_pair(DSG,SJK));
		}
		if(DSG+1<=n&&!vis[DSG+1][SJK]){	
			if(c[DSG+1][SJK]=='a'){
				vis[DSG+1][SJK]=1;
				XGOD_FOREVER[DSG+1][SJK]=XGOD_FOREVER[DSG][SJK];
				q.push_front(make_pair(DSG+1,SJK));
			}
			else if(XGOD_FOREVER[DSG][SJK]!=m){
				vis[DSG+1][SJK]=1;
				XGOD_FOREVER[DSG+1][SJK]=XGOD_FOREVER[DSG][SJK]+1;
				q.pb(make_pair(DSG+1,SJK));
			}
		}
		if(SJK+1<=n&&!vis[DSG][SJK+1]){	
			if(c[DSG][SJK+1]=='a'){
				vis[DSG][SJK+1]=1;
				XGOD_FOREVER[DSG][SJK+1]=XGOD_FOREVER[DSG][SJK];
				q.push_front(make_pair(DSG,SJK+1));
			}
			else if(XGOD_FOREVER[DSG][SJK]!=m){
				vis[DSG][SJK+1]=1;
				XGOD_FOREVER[DSG][SJK+1]=XGOD_FOREVER[DSG][SJK]+1;
				q.pb(make_pair(DSG,SJK+1));
			}
		}
	}
	for(;;cur^=1){	
		v[cur^1].clear();
		for(i=0;i<26;i++){
			bool flag=0;
			for(auto gg:v[cur]){	
				int DSG=gg.first,SJK=gg.second;
				if(DSG==n&&SJK==n) 
					goto ext;
				if(DSG+1<=n&&c[DSG+1][SJK]-'a'==i&&!vis[DSG+1][SJK]){
					flag=1;
					v[cur^1].pb(make_pair(DSG+1,SJK));
					vis[DSG+1][SJK]=1;
					pre[DSG+1][SJK]=make_pair(DSG,SJK);
				}
				if(SJK+1<=n&&c[DSG][SJK+1]-'a'==i&&!vis[DSG][SJK+1]){
					flag=1;
					v[cur^1].pb(make_pair(DSG,SJK+1));
					vis[DSG][SJK+1]=1;
					pre[DSG][SJK+1]=make_pair(DSG,SJK);
				}
			}
			if(flag) break;
		}
	}
	ext:;
	int DSG=n,SJK=n; 
	vector<char> out;
	for(i=n*2-1;i>ans;i--){	
		int tmp=DSG; 
		out.pb(c[DSG][SJK]);
		DSG=pre[DSG][SJK].first;
		SJK=pre[tmp][SJK].second;
	}
	for(i=1;i<=ans;i++) 
		putchar('a');
	reverse(out.begin(),out.end());
	for(auto ch:out) putchar(ch);
}

