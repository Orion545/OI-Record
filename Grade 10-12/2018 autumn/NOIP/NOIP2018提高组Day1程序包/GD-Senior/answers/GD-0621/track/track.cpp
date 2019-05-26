#include<bits/stdc++.h>
using namespace std;
namespace noip{
	int readu(){
		int ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	void writeu(int a){
		if(a<10)
			putchar(a+'0');
		else{
			writeu(a/10);
			putchar(a%10+'0');
		}
	}
	struct edge{
		int to;
		int length;
		int next;
	};
	edge edges[(50000-1)*2];
	int edge_num;
	int first_edge[50000+1];
	void insert(int from, int to, int length){
		edges[edge_num].to=to;
		edges[edge_num].length=length;
		edges[edge_num].next=first_edge[from];
		first_edge[from]=edge_num++;
	}
	int father[50000+1];
	int preorder[50000];
	int dfs_time;
	void dfs(int cur){
		preorder[dfs_time++]=cur;
		for(int e=first_edge[cur]; e!=-1; e=edges[e].next){
			int to=edges[e].to;
			if(to==father[cur])
				continue;
			father[to]=cur;
			dfs(to);
		}
	}
	int dp[50000+1];
	int test(int n, int length){
		int result=0;
		for(int dfn=n-1; dfn>=0; --dfn){
			int cur=preorder[dfn];
			static int value[50000+2];
			static int prev[50000+2];
			static int next[50000+2];
			int num=0;
			for(int e=first_edge[cur]; e!=-1; e=edges[e].next){
				int to=edges[e].to;
				if(to==father[cur])
					continue;
				if(dp[to]+edges[e].length>=length){ // <---------------------------
					++result;
					continue;
				}
				value[num++]=dp[to]+edges[e].length;
			}
			dp[cur]=0;
			value[num++]=-1000000000;
			value[num++]=1000000000;
			sort(value, value+num);
			for(int i=0; i<num; ++i){
				prev[i]=i-1;
				next[i]=i+1;
			}
			for(int i=1, j=num-1; true; i=next[i]){
				if(i==num-1)
					break;
				while(value[i]+value[prev[j]]>=length)
					j=prev[j];
				if(i==j)
					j=next[j];
				if(j==num-1){
					dp[cur]=max(dp[cur], value[i]);
					continue;
				}
				++result;
				next[prev[j]]=next[j];
				prev[next[j]]=prev[j];
				j=next[j];
				next[prev[i]]=next[i];
				prev[next[i]]=prev[i];
			}
		}
		return result;
	}
	void run(){
		freopen("track.in", "r", stdin);
		freopen("track.out", "w", stdout);
		memset(first_edge, -1, sizeof first_edge);
		int n=readu();
		int m=readu();
		for(int i=1; i<n; ++i){
			int a=readu();
			int b=readu();
			int l=readu();
			insert(a, b, l);
			insert(b, a, l);
		}
		father[1]=0;
		dfs(1);
		int left=0/*last ok*/, right=50000*10000+1/*first not ok*/;
		while(left+1!=right){
			int cur=(left+right)/2;
			if(test(n, cur)>=m)
				left=cur;
			else
				right=cur;
		}
		writeu(left);
		putchar('\n');
	}
}
int main(){
	noip::run();
}
