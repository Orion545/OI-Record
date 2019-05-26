#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
#define SET set<int>
map<SET,int>id;
vector<SET>index;
int getid(SET k){
	if(id.count(k)) return id[k];
	index.push_back(k);
	return id[k]=index.size()-1;
}
int main(){
	int nn;cin>>nn;
	int n;string in;
	for(int kkk=1;kkk<=nn;kkk++){
		stack<int>x;
		cin>>n;
		for(int h=1;h<=n;h++){
			cin>>in;
			if(in[0]=='P') x.push(getid(SET()));
			else if(in[0]=='D') x.push(x.top());
			else{
				SET s1=index[x.top()];x.pop();
				SET s2=index[x.top()];x.pop();
				SET tmp;
				if(in[0]=='A'){tmp=s2;tmp.insert(getid(s1));} 
				if(in[0]=='U') set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(tmp,tmp.begin()));
				if(in[0]=='I')set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(tmp,tmp.begin())); 
				x.push(getid(tmp));
			}
			cout<<index[x.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	} 
} 
