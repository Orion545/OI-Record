#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cnt,root;
struct node{
	int l,r,w,siz,num,fa;
}a[100010];
void update(int x){
	if(x==0) return;
//	if(x==0) system("pause");
	a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].num;
//	cout<<"update "<<x<<ends<<a[x].siz<<ends<<a[x].l<<ends<<a[x].r<<ends<<a[a[x].l].siz<<ends<<a[a[x].r].siz<<ends<<a[x].num<<endl;
}
void left(int x){
//	if(x==0) system("pause");
	int f=a[x].fa,ff=a[f].fa,l=a[x].l;
	if(ff==0) goto skip;
	if(a[ff].l==f) a[ff].l=x;
	else a[ff].r=x;
	skip:a[x].fa=ff;
	a[f].fa=x;a[x].l=f;
	a[l].fa=f;a[f].r=l;
	update(f);update(x);
	return;
}
void right(int x){
//	if(x==0) system("pause");
	int f=a[x].fa,ff=a[f].fa,r=a[x].r;
	if(ff==0) goto skip1;
	if(a[ff].l==f) a[ff].l=x;
	else a[ff].r=x;
	skip1:a[x].fa=ff;
	a[f].fa=x;a[x].r=f;
	a[r].fa=f;a[f].l=r;
	update(f);update(x);
	return;
}
void splay(int x,int rt){
//	cout<<"enter splay "<<x<<" to son of "<<rt<<endl;
//	if(x==0) system("pause");
	if(x==0) return;
	while(a[x].fa!=rt){
		int f=a[x].fa,ff=a[f].fa;
//		cout<<"	do "<<x<<ends<<f<<ends<<ff<<endl;
//		if(x==f) system("pause");
		if(ff==rt){
			if(a[f].l==x) right(x);
			else left(x);
			break;
		}
		else{
			if(a[f].l==x&&a[ff].l==f) right(f),right(x);
			if(a[f].r==x&&a[ff].r==f) left(f),left(x);
			if(a[f].l==x&&a[ff].r==f) right(x),left(x);
			if(a[f].r==x&&a[ff].l==f) left(x),right(x);
//			x=ff;
		}
	}
	if(rt==0) root=x;
}
void insert(int w,int x){
//	cout<<"insert "<<w<<ends<<x<<ends<<a[x].w<<ends<<a[a[x].l].w<<ends<<a[a[x].r].w<<ends<<a[a[x].l].siz<<ends<<a[a[x].r].siz<<endl;
//	if(x==0) system("pause");
	if(a[x].w==w){
		a[x].num++;
		update(x);splay(x,0);root=x;
		return;
	}
	if(a[x].w>w){
		if(a[x].l) insert(w,a[x].l);
		else{
			cnt++;
//			cout<<"	"<<cnt<<" inserted at left of "<<x<<endl;
			a[cnt].w=w;
			a[cnt].siz=a[cnt].num=1;
			a[cnt].l=a[cnt].r=0;
			a[cnt].fa=x;
			if(x==0) root=cnt;
			else a[x].l=cnt,splay(cnt,0),root=cnt;
			update(x);
			return;
		}
	}
	if(a[x].w<w){
		if(a[x].r) insert(w,a[x].r);
		else{
			cnt++;
//			cout<<"	"<<cnt<<" inserted at right of "<<x<<endl;
			a[cnt].w=w;
			a[cnt].siz=a[cnt].num=1;
			a[cnt].l=a[cnt].r=0;
			a[cnt].fa=x;
			if(x==0) root=cnt;
			else a[x].r=cnt,splay(cnt,0),root=cnt;
			update(x);
			return;
		}
	}
}
int rank(int x,int pos,int tmp){
//	cout<<"rank "<<x<<ends<<pos<<ends<<tmp<<ends<<a[pos].num<<ends<<a[pos].l<<ends<<a[pos].r<<ends<<a[a[pos].l].siz+1<<endl;
	int tt=tmp+a[a[pos].l].siz+1,ttt=tmp+a[a[pos].l].siz+a[pos].num;
//	cout<<"t: "<<tt<<ends<<ttt<<endl;
//	if(pos==0) system("pause");
	if(a[pos].w==x){
//		cout<<"	return "<<tmp<<ends<<a[a[pos].l].siz+1<<ends<<tt<<endl;
		splay(pos,0);root=pos;
		return tt;
	} 
	if(a[pos].w>x) return rank(x,a[pos].l,tmp);
	if(a[pos].w<x) return rank(x,a[pos].r,ttt);
}
int rankx(int x,int pos){
//	cout<<"rankx "<<x<<ends<<pos<<ends<<a[pos].num<<ends<<a[a[pos].l].w<<ends<<a[a[pos].r].w<<ends<<a[a[pos].l].siz+a[pos].num<<endl;
//	if(pos==0) system("pause");
	if(a[a[pos].l].siz+a[pos].num>=x&&a[a[pos].l].siz+1<=x){
		splay(pos,0);root=pos;
		return a[pos].w;
	} 
	if(a[a[pos].l].siz+a[pos].num<x) return rankx(x-a[a[pos].l].siz-a[pos].num,a[pos].r);
	if(a[a[pos].l].siz+1>x) return rankx(x,a[pos].l);
}
int prepos(){
//	cout<<"prepos "<<root<<endl;
	int tmp=a[root].l;
	while(a[tmp].r) tmp=a[tmp].r;
//	cout<<"return "<<tmp<<endl;
	return tmp;
}
int sufpos(){
//	cout<<"sufpos "<<root<<endl;
	int tmp=a[root].r;
	while(a[tmp].l) tmp=a[tmp].l;
//	cout<<"return "<<tmp<<endl;
	return tmp;
}
int pre(){
//	cout<<"pre "<<root<<endl;
	int tmp=a[root].l;
	while(a[tmp].r) tmp=a[tmp].r;
//	cout<<"return "<<a[tmp].w<<endl;
	return a[tmp].w;
}
int suf(){
//	cout<<"suf "<<root<<endl;
	int tmp=a[root].r;
	while(a[tmp].l) tmp=a[tmp].l;
//	cout<<"return "<<a[tmp].w<<endl;
	return a[tmp].w;
}
void del(int w,int x){
//	cout<<"del "<<w<<ends<<x<<ends<<a[x].w<<ends<<a[a[x].l].w<<ends<<a[a[x].r].w<<endl;
//	if(x==0) system("pause");
	if(a[x].w==w){
		a[x].num--;
		update(x);
		if(a[x].num>=1){
			splay(x,0);update(x);
			return;
		} 
		if(a[x].l==0&&a[x].r==0){
//			cout<<"	type 1"<<endl;
			if(a[x].fa==0) return;
			if(x==a[a[x].fa].l) a[a[x].fa].l=0;
			else a[a[x].fa].r=0;
			update(a[x].fa);splay(a[x].fa,0);root=a[x].fa;
			return;
		}
		if(a[x].l==0){
//			cout<<"	type 2"<<endl;
			if(a[x].fa==0){
				root=a[x].r;a[a[x].r].fa=0;
				return;
			}
			if(x==a[a[x].fa].l) a[a[x].fa].l=a[x].r,a[a[x].r].fa=a[x].fa;
			else a[a[x].fa].r=a[x].r,a[a[x].r].fa=a[x].fa;
			update(a[x].fa);splay(a[x].fa,0);root=a[x].fa;
			return;
		}
		if(a[x].r==0){
//			cout<<"	type 3"<<endl;
			if(a[x].fa==0){
				root=a[x].l;a[a[x].l].fa=0;
				return;
			}
			if(x==a[a[x].fa].l) a[a[x].fa].l=a[x].l,a[a[x].l].fa=a[x].fa;
			else a[a[x].fa].r=a[x].l,a[a[x].l].fa=a[x].fa;
			update(a[x].fa);splay(a[x].fa,0);root=a[x].fa;
			return;
		}
		splay(x,0);root=x;
		if(a[a[x].l].siz>a[a[x].r].siz){
//			cout<<"	type 4"<<endl;
			int pos=prepos();
			splay(pos,x);
			a[pos].r=a[x].r;a[a[x].r].fa=pos;
			a[pos].fa=a[x].fa;
			if(a[x].fa){
				if(a[a[x].fa].l==x) a[a[x].fa].l=pos;
				else a[a[x].fa].r=pos;
			} 
			root=pos;
		}
		else{
//			cout<<"	type 5"<<endl;
			int pos=sufpos();
			splay(pos,x);
			a[pos].l=a[x].l;a[a[x].l].fa=pos;
			a[pos].fa=a[x].fa;
			if(a[x].fa){
				if(a[a[x].fa].l==x) a[a[x].fa].l=pos;
				else a[a[x].fa].r=pos;
			} 
			root=pos;
		}
	}
	if(a[x].w>w) del(w,a[x].l);
	if(a[x].w<w) del(w,a[x].r);
}
int main(){
//	freopen("splay.out","w",stdout); 
	int i,t1,t2;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&t1,&t2);
		if(t1==1) insert(t2,root);
		if(t1==2) del(t2,root);
		if(t1==3) insert(t2,root),printf("%d\n",rank(t2,root,0)),del(t2,root);
		if(t1==4) printf("%d\n",rankx(t2,root));
		if(t1==5) insert(t2,root),printf("%d\n",pre()),del(t2,root);
		if(t1==6) insert(t2,root),printf("%d\n",suf()),del(t2,root);
	}
}
/*
10
1 1
1 1
1 1
1 1
1 5
1 4
1 4
2 4
1 6
3 7

*/
