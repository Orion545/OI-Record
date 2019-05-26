#include<cstring>
#include<ctype.h>
#include<cstdio>
#include<queue>
#include<iostream>
#define N 2500050
#define mp make_pair
#define pr pair<Node*,pair<int,int> >
using namespace std;
inline int read(){
    int x=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:f; while(!isdigit(c));
    do x=(x<<3)+(x<<1)+c-'0',c=getchar(); while(isdigit(c));
    return x*f;
}
int n,k,cnt,id,state;
int fa[N],a[N];
char s[55];
bool b[1020][1<<12];
struct Node{
    Node *ch[26],*nex;
    int state,id;///������������״̬���ڵ���
    Node():state(0),nex(NULL),id(++cnt){
        for(int i=0;i<26;i++)
            ch[i]=NULL;
    }
}*root=new Node,*node;
void print(int x){
    if(!x) return;
    print(fa[x]);
    printf("%c",a[x]+'A');
}
struct Aho_Corasick_Automaton{
    inline void Insert(char *s,int id){
        int len=strlen(s+1);
        Node *x=root;
        for(int i=1;i<=len;i++){
            if(!x->ch[s[i]-'A']) x->ch[s[i]-'A']=new Node;
            x=x->ch[s[i]-'A'];
        }
        x->state|=1<<id>>1;
    }
    inline void GetFail(){
        queue<Node*>q;
        for(int i=0;i<26;i++)
            if(!root->ch[i]) root->ch[i]=root;
            else root->ch[i]->nex=root,q.push(root->ch[i]);
        while(!q.empty()){
            Node *x=q.front();q.pop();
            for(int i=0;i<26;i++)
                if(x->ch[i]) x->ch[i]->nex=x->nex->ch[i],q.push(x->ch[i]);
                else x->ch[i]=x->nex->ch[i];
            Node *tmp=x->nex;
            while(tmp!=root && !tmp->state) tmp=tmp->nex;
            x->state|=tmp->state;///�̳����к�׺��״̬
//            if(x->state) std::cout<<x->id<<' '<<x->state<<'\n';
        }
    }
    inline void solve(){
        queue<pr>q;
        q.push(mp(root,mp(root->state,cnt=0)));
        b[root->id][root->state]=true;
        while(!q.empty()){
            pr x=q.front();q.pop();
            id=x.second.second;
            state=x.second.first;
            node=x.first;
//			if(id%1000==0) std::cout<<id<<'\n';
//			if(state>=4080) std::cout<<state<<'\n';
            if(state==(1<<n)-1){///�ҵ�����ģ����
                print(id);
                return;
            }
            for(int i=0;i<26;i++){
                k=state|node->ch[i]->state;///��ת�Ƴ���״̬
                if(b[node->ch[i]->id][k]) continue;///�����ظ���
//				if(state>=4080) std::cout<<"	"<<node->ch[i]->id<<' '<<state<<' '<<k<<'\n';
                b[node->ch[i]->id][k]=true;
                fa[++cnt]=id;a[cnt]=i;///��¼·��
                q.push(mp(node->ch[i],mp(k,cnt)));
            }
        }
    }
}AC;
int main(){
//	freopen("1.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        AC.Insert(s,i);
    }
    AC.GetFail();///��Failָ��
    AC.solve();
return 0;
}
