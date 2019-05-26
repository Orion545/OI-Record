#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define maxn 50005
#define INF 0x7f7f7f7f
using namespace std;
void read(int &x){
	int f=1;x=0;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
struct way{
	int to,len;
	way(){to=len=0;}
	way(int a,int b){to=a,len=b;}
};
vector<way>M[maxn];
int func(vector<int>s,int left,int right,int x){
	int ans=0;
	while(left<right){
		if(s[left]+s[right]<x) right--;
		else ans++,left++,right--;
	}
	return ans;
}
int ans=0;
bool cmp(int a,int b){return a>b;}
int dfs(int th,int fa,int mid){
	vector<int>s1;
	for(vector<way>::iterator i=M[th].begin();i!=M[th].end();i++){
		if((*i).to==fa) continue;
		int x=dfs((*i).to,th,mid)+(*i).len;
		if(x>=mid) ans++;
		else s1.push_back(x);
	}
	if(s1.size()==0) return 0;
	sort(s1.begin(),s1.end(),cmp);
	int aa=func(s1,0,(int)s1.size()-1,mid);
	ans+=aa;
	int l=-1,r=s1.size();
	while(l<r-1){
		int mm=(l+r)/2;
		for(int j=mm;j<s1.size()-1;j++) swap(s1[j],s1[j+1]);
		bool flag=func(s1,0,s1.size()-2,mid)==aa;
		for(int j=s1.size()-1;j>mm;j--) swap(s1[j],s1[j-1]);
		if(flag) r=mm;
		else l=mm;
	}
	return r==s1.size()?0:s1[r];
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	read(n),read(m);
	int sum=0;
	for(int i=1;i<n;i++){
		int a,b,w;
		read(a),read(b),read(w);
		M[a].push_back(way(b,w));
		M[b].push_back(way(a,w));
		sum+=w;
	}
	int left=0,right=sum+1;
	while(left<right-1){
		int mid=(left+right)/2;
		ans=0;
		int aa=dfs(1,0,mid);
		if(aa>=mid) ans++;
		if(ans>=m) left=mid;
		else right=mid;
	}
	printf("%d\n",left);
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
/*
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/
