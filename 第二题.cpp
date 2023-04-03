#include<iostream>
#include<stdio.h>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

typedef struct node{
    int val;
    int num;
    node* left;
    node* right;
}*dlist;

typedef struct lis_{
    dlist head;
    dlist tail;
    int len=0;
}*dlis_;

void pushback(dlis_ lis,int idx,int num){
    dlist no=new node();
    no->val=idx;
    no->num=num;
    lis->tail->right=no;
    no->left=lis->tail;
    lis->tail=no;
    lis->len++;
}

void popfront(dlis_ lis){
    auto rr=lis->head->right->right;
    lis->head->right=rr;
    rr->left=lis->head;
    lis->len--;
}

void del(dlist ite){
    auto r=ite->right;
    auto l=ite->left;
    r->left=l;
    l->right=r;
}

int main(){
    //freopen("test.txt","r",stdin);
    int k,n,m;
    cin>>k>>n>>m;
    dlis_ q1=new lis_();
    q1->head=new node();
    q1->head->left=NULL;
    q1->head->right=NULL;
    q1->tail=q1->head;

    dlis_ q2=new lis_();
    q2->head=new node();
    q2->head->left=NULL;
    q2->head->right=NULL;
    q2->tail=q2->head;

    unordered_map<int,dlist> m1;
    unordered_map<int,dlist> m2;
    int idx;
    for(int i=0;i<m;i++){
        cin>>idx;
        auto iter=m2.find(idx);
        if(iter==m2.end()){
            auto iter2=m1.find(idx);
            if(iter2==m1.end()){
                pushback(q1,idx,1);
                m1.insert({idx,q1->tail});
                if(q1->len>n){
                    int ee=q1->head->right->val;
                    popfront(q1);
                    m1.erase(ee);
                }
            }else{
                auto ite=iter2->second;
                ite->num++;
                if(ite->num==k){
                    if(ite!=q1->tail){
                        del(ite);
                        q1->len--;
                        m1.erase(idx);
                        pushback(q2,idx,k);
                        m2.insert({idx,q2->tail});
                        if(q2->len>n){
                            int ee=q2->head->right->val;
                            popfront(q2);
                            m2.erase(ee);
                        }
                    }else{
                        q1->tail=q1->tail->left;
                        q1->tail->right=NULL;
                        q1->len--;
                        pushback(q2,idx,k);
                        if(q2->len>n){
                            int ee=q2->head->right->val;
                            popfront(q2);
                            m2.erase(ee);
                        }
                        m1.erase(idx);
                        m2.insert({idx,q2->tail});
                    }
                }else{
                    if(ite!=q1->tail){
                        int id_=ite->val;
                        int nu=ite->num;
                        del(ite);
                        q1->len--;
                        pushback(q1,id_,nu);
                        m1[id_]=q1->tail;
                    }
                }
            }
        }else{
            auto ite=iter->second;
            if(ite!=q2->tail){
                del(ite);
                q2->len--;
                pushback(q2,idx,k);
                m2[idx]=q2->tail;
            }
        }
    }

    if(q1->len>n||q2->len>n){
        while(true){
            int x=1;
        }
    }

    if(q1->len==0){
        cout<<"-"<<endl;
    }else{
        auto h=q1->head->right;
        for(int i=0;i<q1->len&&h;i++){
            cout<<h->val;
            if(i!=q1->len-1){
                cout<<" ";
            }
            h=h->right;
        }
        cout<<endl;
    }

    if(q2->len==0){
        cout<<"-"<<endl;
    }else{
        auto h=q2->head->right;
        for(int i=0;i<q2->len&&h;i++){
            cout<<h->val;
            if(i!=q2->len-1){
                cout<<" ";
            }
            h=h->right;
        }
        cout<<endl;
    }
    return 0;
}