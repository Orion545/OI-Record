#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
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
namespace s{
    int n=0,ch[100010][2],siz[100010],num[100010],w[100010],fa[100010],root=0,cnt=0;
    int newnode(int f,int val){
//		cout<<"new node "<<f<<ends<<val<<endl;
        cnt++;ch[cnt][0]=ch[cnt][1]=0;num[cnt]=siz[cnt]=1;
        w[cnt]=val;fa[cnt]=f;return cnt;
    }
    void delnode(int pos){
        ch[pos][0]=ch[pos][1]=num[pos]=siz[pos]=w[pos]=fa[pos]=0;
    }
    void update(int pos){siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+num[pos];}
    bool get(int pos){return ch[fa[pos]][1]==pos;}
    
    void rotate(int pos){
        int f=fa[pos],ff=fa[f],son=get(pos);
//		cout<<"rotate "<<pos<<ends<<f<<ends<<ff<<ends<<son<<ends<<ch[pos][son^1]<<ends<<ch[pos][son]<<endl;
        ch[f][son]=ch[pos][son^1];
        if(ch[f][son]) fa[ch[f][son]]=f;
        fa[f]=pos;ch[pos][son^1]=f;
        fa[pos]=ff;
        if(ff) ch[ff][ch[ff][1]==f]=pos;
//		cout<<"finish rotate "<<ch[pos][son^1]<<ends<<ch[f][son]<<ends<<ch[f][son^1]<<ends<<fa[f]<<endl;
        update(f);update(pos);
    }
    void splay(int pos,int to){
        if((!pos)||(pos==to)) return;
//		cout<<"splay "<<pos<<ends<<fa[pos]<<ends<<to<<endl;
        for(int f;(f=fa[pos])!=to;rotate(pos))
            if(fa[f]!=to)
                rotate((get(f)==get(pos))?f:pos);
        if(!to) root=pos;
    }
    int getpos(int pos,int rank){
        if(rank>siz[ch[pos][0]]&&rank<=(siz[ch[pos][0]]+num[pos])){
            splay(pos,0);
            return w[pos];
        }
        if(rank<=siz[ch[pos][0]]) return getpos(ch[pos][0],rank);
        else return getpos(ch[pos][1],rank-siz[ch[pos][0]]-num[pos]);
    }
    int getrank(int pos,int val,int buff){
        if(w[pos]==val){
            splay(pos,0);
            return siz[ch[pos][0]]+buff+1;
        }
        if(w[pos]>val) return getrank(ch[pos][0],val,buff);
        else return getrank(ch[pos][1],val,buff+siz[ch[pos][0]]+num[pos]);
    }
    int getvalpos(int pos,int val){
        if(w[pos]==val) return pos;
        if(w[pos]>val) return getvalpos(ch[pos][0],val);
        else return getvalpos(ch[pos][1],val);
    }
    int pre(){
        int pos=ch[root][0];
        while(ch[pos][1]) pos=ch[pos][1];
        return pos;
    }
    int suf(){
        int pos=ch[root][1];
        while(ch[pos][0]) pos=ch[pos][0];
        return pos;
    }
    void insert(int pos,int val){
//		cout<<"insert "<<pos<<ends<<w[pos]<<ends<<val<<ends<<ch[pos][0]<<ends<<ch[pos][1]<<endl;
        if(!pos){root=newnode(0,val);return;}
        if(w[pos]==val){num[pos]++;splay(pos,0);return;}
        if(w[pos]>val){
            if(!ch[pos][0]){
                ch[pos][0]=newnode(pos,val);
                update(pos);splay(ch[pos][0],0);
            }
            else siz[pos]++,insert(ch[pos][0],val);
        }
        else{
            if(!ch[pos][1]){
                ch[pos][1]=newnode(pos,val);
                update(pos);splay(ch[pos][1],0);
            }
            else siz[pos]++,insert(ch[pos][1],val);
        }
    }
    void del(int val){
//		cout<<"del "<<val<<endl;
        int pos=getvalpos(root,val);splay(pos,0);
        if(num[pos]>1){num[pos]--;return;}
        if(!ch[pos][0]){
            root=ch[pos][1];fa[root]=0;
            delnode(pos);
        }
        else{
            int sec=pre();splay(sec,root);
            root=ch[pos][0];fa[root]=0;
            ch[root][1]=ch[pos][1];fa[ch[pos][1]]=root;
            update(root);delnode(pos);
        }
    }
}
int n,a[100010];
vector<int>ans;
int main(){
	freopen("sleepy.in","r",stdin);
	freopen("sleepy.out","w",stdout); 
	n=read();int i;
	for(i=1;i<=n;i++) a[i]=read();
	s::insert(s::root,a[n]);
	while(a[n]>a[n-1]) n--,s::insert(s::root,a[n]);
	for(i=1;i<n;i++){
		s::insert(s::root,a[i]);
		ans.push_back(n-i-1+s::getrank(s::root,a[i],0)-1);
	}
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++){
		if(i) putchar(' ');
		printf("%d",ans[i]);
	}
}
