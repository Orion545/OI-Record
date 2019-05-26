#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define hash deep_dark_fantasy
#define inf 1e9
using namespace std;
inline ll read(){
    ll re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
ll n,m,x[150][150],cur,pre,ex,ey;
ll st[2][300010];ll ans[2][300010],re;
ll tot[2],bit[110],state[300010],st_tot,hash=300000;
struct edge{
    ll to,next;
}a[300010];
void insert(ll sta,ll val){
    ll p=sta%hash,i;
    for(i=state[p];i;i=a[i].next){
        if(st[cur][a[i].to]==sta){
            ans[cur][a[i].to]=max(ans[cur][a[i].to],val);return;
        }
    }
    tot[cur]++;
    a[++st_tot].to=tot[cur];
    a[st_tot].next=state[p];
    state[p]=st_tot;st[cur][tot[cur]]=sta;ans[cur][tot[cur]]=val;
}
void dp(){
    ll i,j,k,l,now,down,right;ll val;re=-inf;
    for(i=1;i<=n;i++){
    	for(j=1;j<=m;j++){
    		re=max(re,x[i][j]);
		}
	}
    cur=0;tot[cur]=1;ans[cur][1]=0;st[cur][1]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=tot[cur];j++) st[cur][j]<<=2;
        for(j=1;j<=m;j++){
            pre=cur;cur^=1;tot[cur]=0;st_tot=0;memset(state,0,sizeof(state));
            cout<<"do "<<i<<' '<<j<<'\n';
            for(k=1;k<=tot[pre];k++){
                now=st[pre][k];val=ans[pre][k];
                right=(now>>bit[j-1])%4;down=(now>>bit[j])%4;
                cout<<"	cur "<<right<<' '<<down<<' '<<val<<'\n';;
                if(!down&&!right){
                    insert(now,val);
                    if(j!=m) 
                        insert(now+(1<<bit[j])+((1<<bit[j])<<1),val+x[i][j]);
                    if(i!=n) 
                        insert(now+(1<<bit[j-1])+((1<<bit[j-1])<<1),val+x[i][j]);
                    if(j!=m&&i!=n) 
                        insert(now+(1<<bit[j])+((1<<bit[j])<<1),val+x[i][j]);
                }
                if(down&&!right){
                	if(down==3){
                		if((now==down*(1<<bit[j]))&&(val+x[i][j]>re))
                        	re=val+x[i][j];
					}
					if(i!=n) insert(now-down*(1<<bit[j])+down*(1<<bit[j-1]),val+x[i][j]);
                    if(j!=m) insert(now,val+x[i][j]);
                }
                if(!down&&right){
                	if(right==3){
                		if((now==right*(1<<bit[j-1]))&&(val+x[i][j]>re))
                        	re=val+x[i][j];
					}
					if(j!=m) insert(now-right*(1<<bit[j-1])+right*(1<<bit[j]),val+x[i][j]);
                    if(i!=n) insert(now,val+x[i][j]);
                }
                if(right==1&&down==1){
                    ll cnt=1;
                    for(l=j+1;l<=m;l++){
                        if((now>>bit[l])%4==1) cnt++;
                        if((now>>bit[l])%4==2) cnt--;
                        if(!cnt){
                            insert(now-(1<<bit[l])-(1<<bit[j])-(1<<bit[j-1]),val+x[i][j]);
                            break;
                        }
                    }
                }
                if(right==2&&down==2){
                    ll cnt=1;
                    for(l=j-2;l>=0;l--){
                        if((now>>bit[l])%4==1) cnt--;
                        if((now>>bit[l])%4==2) cnt++;
                        if(!cnt){
                            insert(now+(1<<bit[l])-((1<<bit[j])<<1)-((1<<bit[j-1])<<1),val+x[i][j]);
                            break;
                        }
                    }
                }
                if(right==2&&down==1){
                    insert(now-((1<<bit[j-1])<<1)-(1<<bit[j]),val+x[i][j]);
                }
                if(right==1&&down==2){
                    if((now==(1<<bit[j-1])+((1<<bit[j])<<1))&&(val+x[i][j]>re)){
                        re=val+x[i][j];
                    }
                }
                if(right==3&&down==1){
                	ll cnt=1;
                	for(l=j+1;l<=m;l++){
                        if((now>>bit[l])%4==1) cnt++;
                        if((now>>bit[l])%4==2) cnt--;
                        if(!cnt){
                            insert(now+(1<<bit[l])-(1<<bit[j])-3*(1<<bit[j-1]),val+x[i][j]);
                            break;
                        }
					}
				}
                if(right==3&&down==2){
                	ll cnt=1;
                	for(l=j-2;l>=0;l--){
                        if((now>>bit[l])%4==1) cnt--;
                        if((now>>bit[l])%4==2) cnt++;
                        if(!cnt){
                            insert(now+((1<<bit[l])<<1)-((1<<bit[j])<<1)-3*(1<<bit[j-1]),val+x[i][j]);
                            break;
                        }
					}
				}
                if(down==3&&right==1){
                	ll cnt=1;
                	for(l=j+1;l<=m;l++){
                        if((now>>bit[l])%4==1) cnt++;
                        if((now>>bit[l])%4==2) cnt--;
                        if(!cnt){
                            insert(now+(1<<bit[l])-(1<<bit[j-1])-3*(1<<bit[j]),val+x[i][j]);
                            break;
                        }
					}
				}
                if(down==3&&right==2){
                	ll cnt=1;
                	for(l=j-2;l>=0;l--){
                        if((now>>bit[l])%4==1) cnt--;
                        if((now>>bit[l])%4==2) cnt++;
                        if(!cnt){
                            insert(now+((1<<bit[l])<<1)-((1<<bit[j-1])<<1)-3*(1<<bit[j]),val+x[i][j]);
                            break;
                        }
					}
				}
				if(down==3&&right==3){
					if((now==3*((1<<bit[j])+(1<<bit[j-1])))&&(re<val+x[i][j])){
						re=val+x[i][j];
					}
				}
			}
        }
    }
}
int main(){
    ll i,j;
    n=read();m=read();
    for(i=1;i<=100;i++) bit[i]=(i<<1);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) x[i][j]=read();
    dp();
    printf("%lld",re);
}
