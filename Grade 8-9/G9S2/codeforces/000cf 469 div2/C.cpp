#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
priority_queue<int,vector<int>,greater<int> >zero;
//vector<int>x[200010];
struct node{
	int num,last;
	bool operator <(node b) const{
		if(last!=b.last) return last<b.last;
		else return num<b.num;
	}
};
bool operator <(int a,node b){
	return a>b.last;
}
multiset<node>x;
vector<int>t[200010],ans0;
char s[200010];
int a[200010],n,tot,ans[200010];
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,j,k,tmp;multiset<node>::iterator l;
	scanf("%s",s);n=strlen(s);
	for(i=0;i<n;i++) a[i+1]=s[i]-'0';
	for(i=1;i<=n;i=j+1){
		if(i%10000==0) cout<<i<<endl;
		j=i;
		if(!a[i]){zero.push(i);continue;}
		while(a[j+1]) j++;
//		cout<<"into "<<j<<endl;
		for(k=i;k<=j;k++){
			if(zero.empty()){
				printf("-1\n");return 0;
			} 
			l=x.begin();tmp=0;
			l=upper_bound(x.begin(),x.end(),zero.top());
			if(l!=x.end()){
					tmp=(*l).num;x.erase(*l);
					t[tmp].push_back(zero.top());zero.pop();
					t[tmp].push_back(k);
					x.insert((node){tmp,k});
			}
			else{
//				cout<<"	add new"<<endl;
				if(!zero.empty()&&zero.top()<k) {
					t[x.size()+1].push_back(zero.top());zero.pop();
					t[x.size()+1].push_back(k);
					x.insert((node){x.size()+1,k});
				}
				else{
					printf("-1\n");return 0;
				}
			}
		}
	}
//	cout<<"end of main"<<endl;
//	for(l=x.begin();l!=x.end();l++){
//		cout<<"check x "<<((*l)[(*l).size()-1])<<endl;
//	}
	while((l=x.begin())!=x.end()){
//		cout<<zero.top()<<ends<<((*l)[(*l).size()-1])<<endl;
		while(!zero.empty()){
			if(zero.top()>((*l).last)) break;
			else ans0.push_back(zero.top()),zero.pop();
		}
		if(zero.empty()){
			printf("-1");return 0;
		}
		tmp=(*l).num;x.erase(*l);
//		cout<<"erase\n";
		t[tmp].push_back(zero.top());zero.pop();
//		cout<<"add\n";
		ans[++tot]=tmp;
	}
//	cout<<"end of final insert"<<endl;
	printf("%d\n",tot+zero.size()+ans0.size());
	for(i=1;i<=tot;i++){
		printf("%d",t[ans[i]].size());
		for(j=0;j<t[ans[i]].size();j++) printf(" %d",t[ans[i]][j]);
		puts("");
	}
	for(i=0;i<ans0.size();i++) printf("1 %d\n",ans0[i]); 
	while(!zero.empty()){
		printf("1 %d\n",zero.top());zero.pop();
	}
}
