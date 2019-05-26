#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<cmath>
#define cin fin
#define cout fout
using namespace std;
ofstream fout("travel.out.txt");
ifstream fin("travel.in.txt");
int n,t,m;
int s[20000],sl[20000];
int d[20000],b[20000];
int p;
bool ff[10000];
void dfs(int j){
	//cout<<j<<" "<<k<<endl;
	int p1=j;
	int g=0,g1=0;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    g1++;
		}
		p1=sl[p1];
	}
	if(g1<5){
		int df[5];
		p1=j;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    df[++g]=s[p1];
		    ff[s[p1]]=1;
		}
		p1=sl[p1];
	}
	sort(df+1,df+1+g);
	for(int i=1;i<=g;++i){
		d[++p]=df[i];
		dfs(df[i]);
	}
	return ;
}
	else if(g1<8){
		int df[8];
		p1=j;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    df[++g]=s[p1];
		    ff[s[p1]]=1;
		}
		p1=sl[p1];
	}
	sort(df+1,df+1+g);
	for(int i=1;i<=g;++i){
		d[++p]=df[i];
		dfs(df[i]);
	}
	return ;
	}  
	else if(g1<11){
		int df[11];
		p1=j;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    df[++g]=s[p1];
		    ff[s[p1]]=1;
		}
		p1=sl[p1];
	}
	sort(df+1,df+1+g);
	for(int i=1;i<=g;++i){
		d[++p]=df[i];
		dfs(df[i]);
	}
	return ;
	}  
	else if(g1<100){
		int df[100];
		p1=j;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    df[++g]=s[p1];
		    ff[s[p1]]=1;
		}
		p1=sl[p1];
	}
	sort(df+1,df+1+g);
	for(int i=1;i<=g;++i){
		d[++p]=df[i];
		dfs(df[i]);
	}
	return ;
	}  
	else if(g1<1000){
		int df[1000];
		p1=j;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    df[++g]=s[p1];
		    ff[s[p1]]=1;
		}
		p1=sl[p1];
	}
	sort(df+1,df+1+g);
	for(int i=1;i<=g;++i){
		d[++p]=df[i];
		dfs(df[i]);
	}
	return ;
	}  
	else{
		int df[5000];
			p1=j;
	p1=sl[p1];
	while(p1>0){
		if(!ff[s[p1]]){
		    df[++g]=s[p1];
		    ff[s[p1]]=1;
		}
		p1=sl[p1];
	}
	sort(df+1,df+1+g);
	for(int i=1;i<=g;++i){
		d[++p]=df[i];
		dfs(df[i]);
	}
	return ;
	} 
	
}
int main()
{
     cin>>n>>m;
     int i,j,k,k1;
     t=n;
     for(i=1;i<=n;++i) s[i]=i;
     for(i=1;i<=m;++i){
     	cin>>j>>k;
     	s[++t]=k;
     	sl[t]=sl[j];
     	sl[j]=t;
     	s[++t]=j;
     	sl[t]=sl[k];
     	sl[k]=t;
     }
    // for(i=1;i<=t;++i) cout<<i<<"  "<<s[i]<<"  "<<sl[i]<<endl;
    	d[++p]=1;
    	ff[1]=1;
    	dfs(1);
    	for(i=1;i<=p;i++) cout<<d[i]<<" ";
    fin.close();
    fout.close();
	return 0;
}
