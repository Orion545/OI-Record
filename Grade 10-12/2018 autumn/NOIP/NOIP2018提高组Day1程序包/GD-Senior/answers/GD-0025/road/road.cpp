#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<iostream>
#define maxn 100005
#define cin fin
#define cout fout 
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
int n;int s[maxn];
struct node{
	int l, r, value, pos_v;
	struct node *ls,*rs;
};
void buildtree(struct node *root,int left,int right){
	root->l=left,root->r=right;
	if(left==right){
		root->ls=root->rs=NULL;
		root->value=s[left];
		root->pos_v=left;
		return;
	}
	root->ls=(struct node *)malloc(sizeof(struct node));
	root->rs=(struct node *)malloc(sizeof(struct node));
	int mid=(left+right)/2;
	buildtree(root->ls,left,mid);
	buildtree(root->rs,mid+1,right);
	if(root->ls->value < root->rs->value){
		root->value=root->ls->value;
		root->pos_v=root->ls->pos_v;
	}
	else{
		root->value=root->rs->value;
		root->pos_v=root->rs->pos_v;
	}
}
int p_min=0;
int query(struct node *root,int left,int right){
	if(root->l==left&&root->r==right){
		p_min=root->pos_v;
		return root->value;
	}
	int mid=(root->l+root->r)/2;
	if(right<=mid) return query(root->ls,left,right);
	else if(left>=mid+1) return query(root->rs,left,right);
	else{
		int ql=query(root->ls,left,mid);int p1=p_min;
		int qr=query(root->rs,mid+1,right);int p2=p_min;
		if(ql<qr){
			p_min=p1;
			return ql;
		}
		else{
			p_min=p2;
			return qr;
		}
	}
}
int ans=0;
struct node *root=(struct node *)malloc(sizeof(struct node));
void solve(int left,int right,int now){
//	cout<<"left="<<left<<" right="<<right<<" now="<<now<<endl;
	if(left>right||right>n||left<1) return; 
	int m=query(root,left,right);
//	cout<<"p_min="<<p_min<<endl;
	ans+=m-now;
	if(left==right) return;
	solve(left,p_min-1,m),solve(p_min+1,right,m);
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	buildtree(root,1,n);
	solve(1,n,0);
	cout<<ans<<endl;
	return 0;
}


