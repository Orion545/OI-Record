#include<iostream>
using namespace std;
int p,n;
int h[128];
int g[60][60];
int d[60];
bool v[60],c[60];
int mini,minn=1000000000;
char num;
struct Queue{
    int a[10000];
    int f,r;
    bool empty(){return f==r;}
       void push(int x){a[f++]=x;}
       int pop(){return a[r++];}
}q;
int z;
int i,j,k;
int main(){
    cin>>p;
    for(i=0;i<60;i++)
      	for(j=0;j<60;j++)
        	if(i!=j)g[i][j]=1000000000;
    for(i=0;i<p;i++){
      	char x,y;
      	int l;
      	cin>>x>>y>>l;
      	if(x==y)continue;
      	if(h[x]==0)h[x]=++n;
      	if(h[y]==0)h[y]=++n;
      	if(x<'Z')c[h[x]]=true;
      	if(y<'Z')c[h[y]]=true;
      	if(x=='Z')z=h[x];
     	if(y=='Z')z=h[y];
      	g[h[x]][h[y]]=g[h[y]][h[x]]=min(g[h[x]][h[y]],l);
    }
    for(i=1;i<=n;i++) d[i]=1000000000;
    q.push(z);
    d[z]=0;
    while(!q.empty()){
      	int t=q.pop();
      	v[t]=false;
      	for(i=1;i<=n;i++)if(d[t]+g[t][i]<d[i]){
      	  	d[i]=d[t]+g[t][i];
      	  	if(!v[i]){
      	    	q.push(i);
      	    	v[i]=true;
      	  	}
      	}
    }
    for(i=1;i<=n;i++) if(c[i]&&minn>d[i]){minn=d[i];mini=i;}
    i=65;
    while(h[i]!=mini)i++;
    num=i;
    cout<<num<<' '<<minn<<endl;
    return 0;
}
