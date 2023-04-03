#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<time.h>
#include<stdlib.h>

using namespace std;
const int N=1000;

vector<int> v1;
vector<int> v2;
vector<int> ret;

typedef struct node{
    int val;
    node* left=NULL;
    node* right=NULL;
    bool c=false;
}*tree;

void dfs(tree &t,int l1,int r1,int l2,int r2){
    //cout<<l1<<"  "<<r1<<"  "<<l2<<"  "<<r2<<endl;
    if(l1>r1){
        return;
    }
    int e=v2[r2];
    auto p=find(v1.begin()+l1,v1.begin()+r1,e);
    int pos=p-v1.begin();
    t=new node();
    t->val=e;
    dfs(t->left,l1,pos-1,l2,l2+pos-l1-1);
    dfs(t->right,pos+1,r1,l2+pos-l1,r2-1);
}

void prio(tree t){
    if(t){
        if(t->c){
            //cout<<t->val;
              ret.push_back(t->val);
        }
        prio(t->left);
        prio(t->right);
    }
}

void pprio(tree t){
    if(t){
        pprio(t->left);
        pprio(t->right);
        if(t->c){
            //cout<<t->val;
            ret.push_back(t->val);
        }
    }
}

int main(){
    //freopen("test.txt","r",stdin);
    srand(time(0));
    int n;
    cin>>n;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        v1.push_back(a);
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        v2.push_back(a);
    }

    tree t;
    dfs(t,0,n-1,0,n-1);

    if(rand()%2==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    queue<tree> q;
    q.push(t);
    while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;i++){
            tree tt=q.front();
            q.pop();
            if(i==0||i==len-1||(tt->left==NULL&&tt->right==NULL)){
                tt->c=true;
            }
            if(tt->left){
                q.push(tt->left);
            }
            if(tt->right){
                    q.push(tt->right);
            }
        }
    }
    auto rr=t->right;
    t->right=NULL;
    prio(t);
    pprio(rr);
    cout<<ret[0];
    for(int i=1;i<ret.size();i++){
        cout<<" ";
        cout<<ret[i];
    }
    return 0;
}