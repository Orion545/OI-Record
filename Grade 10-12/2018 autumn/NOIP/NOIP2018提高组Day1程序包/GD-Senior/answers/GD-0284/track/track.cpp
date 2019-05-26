#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int MAXN=50001;

struct edge{
	int from,to,len,nxt;
	edge(int from_=0,int to_=0,int len_=0,int nxt_=0){from=from_;to=to_;len=len_;nxt=nxt_;}
}e[MAXN*2];

int n,m,x,y,z,max_w,ans_of_m_1,ans_of_a_1,ans_of_b_1,num_of_edge,head[MAXN],len[MAXN];

void add_edge_(int from,int to,int len){e[++num_of_edge]=edge(from,to,len,head[from]);head[from]=num_of_edge;}

void add_edge(int from,int to,int len){add_edge_(from,to,len);add_edge_(to,from,len);}

void dfs_m_1(int now,int fa,int sum){
	if(sum>ans_of_m_1){ans_of_m_1=sum,max_w=now;}
	for(int i=head[now];~i;i=e[i].nxt)if(e[i].to!=fa)dfs_m_1(e[i].to,now,sum+e[i].len);
}

bool check_1(int mid){
	int re=0,l=1,r;
	for(r=1;len[r]<mid&&r<=n-1;r++);r--;
	re=re+n-r-1;
	while(l<r){
		if(len[l]+len[r]>=mid){l++;r--;re++;}else l++;
	}
	return re>=m;
}

bool check_2(int mid){
	int re=0,sum=0;
	for(int i=1;i<=n-1;i++){
		sum=sum+len[i];
		if(sum>=mid){sum=0;re++;}
	}
	return re>=m;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n-1;i++){
			scanf("%d%d%d",&x,&y,&z);
			add_edge(x,y,z);
		}
		dfs_m_1(1,-1,0);
		ans_of_m_1=0;
		dfs_m_1(max_w,-1,0);
		printf("%d\n",ans_of_m_1);
		/*
		7 1
		1 2 10
		1 3 5
		2 4 9
		2 5 8
		3 6 6
		3 7 7
		*/
	}else{
		bool tf_1=true;
		bool tf_2=true;
		int l=0x7f7f7f7f,r=0;
		for(int i=1;i<=n-1;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x<y)swap(x,y);
			if(y!=1)tf_1=false;
			if(x!=y+1)tf_2=false;
			len[x-1]=z;
			r=r+z;
			l=min(l,z);
		}
		if(tf_1){
			sort(len+1,len+n);
			while(l<r){
				int mid=(l+r)>>1;
				if(check_1(mid)){ans_of_a_1=mid;l=mid+1;mid=l+1;}else r=mid-1;
			}
			if(check_1(l))ans_of_a_1=l;
			printf("%d\n",ans_of_a_1);
		}else if(tf_2){
			while(l<r){
				int mid=(l+r)>>1;
				if(check_2(mid)){ans_of_b_1=mid;l=mid+1;mid=l+1;}else r=mid-1;
			}
			if(check_2(l))ans_of_b_1=l;
			printf("%d\n",ans_of_b_1);
		}
	}
}
