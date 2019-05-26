#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct erickin{
	int to,next;
}a[4000010];
int n,m,first[1000010];
int tt[1000010];
struct Queue{
    int aa[1000010],head,tail;
    Queue(){
        memset(aa,0,sizeof(aa));
        head=1;tail=1;
    }
    void push(int k){
        aa[tail++]=k;
    }
    void pop(){
        aa[head++]=0;
    }
    bool empty(){
        if(head==tail) return 1;
        else return 0;
    }
    int h(){
        return aa[head];
    }
}q;
int ans[1000010],cnt[1000010];
bool vis[1000010]={0};
void bfs(){
	memset(ans,127,sizeof(ans));
	memset(cnt,127,sizeof(cnt));
	q.push(1);vis[1]=1;ans[1]=0;cnt[1]=1;
	while(!q.empty()){
		int h=q.h(),p=first[h];
//		cout<<"doing "<<h<<endl;
		while(p!=-1){
//			cout<<"	going to "<<a[p].to<<endl;
			if(!vis[a[p].to]){
//				cout<<"		new node! "; 
				vis[a[p].to]=1;
				cnt[a[p].to]=cnt[h];ans[a[p].to]=ans[h]+1;
				q.push(a[p].to);
//				cout<<cnt[a[p].to]<<endl;
			}
			else if(ans[a[p].to]==ans[h]+1){
//				cout<<"old renewed! ";
				cnt[a[p].to]+=cnt[h];
//				cout<<cnt[a[p].to]<<endl;
			}
			p=a[p].next;
		}
		q.pop();
	}
}
int main(){
	int mm;
	cin>>n>>mm;
	for(int i=1;i<=n;i++) first[i]=tt[i]=-1;
	int ta,tb;
	for(int i=1;i<=mm;i++){
		cin>>ta>>tb;
		m++;a[m].to=ta;a[m].next=tt[tb];
		first[tb]=tt[tb]=m;
		m++;a[m].to=tb;a[m].next=tt[ta];
		first[ta]=tt[ta]=m;
	}
	bfs();
	for(int i=1;i<=n;i++){
		cout<<cnt[i]%100003;
		if(i<n) cout<<endl;
	}
}
