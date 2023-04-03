#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;
const int N=20;
bool pi[N];
bool sq[N];
bool vis[N];
int v[N];

int  main(){
    for(int i=1;i<N;i++){
        pi[i]=true;
    }
    pi[1]=false;
    pi[2]=true;
    for(int i=2;i<N;i++){
        if(pi[i]){
            for(int j=2;j*i<N;j++){
                pi[i*j]=false;
            }
        }
    }

    for(int i=1;i<N;i++){
        int q=sqrt(i);
        if(q*q==i){
            sq[i]=true;
        }
    }

    bool flag=true;
    bool cha=true;

    int n;
    cin>>n;
    int gap=n;
    for(int i=1;i<=n;i++){
        v[i]=i;
    }

    while(true){
        if(gap==1){
            cout<<v[1]<<endl;
            break;
        }
        if(!cha){
            break;
        }
        cha=false;
        memset(vis,0,sizeof(bool)*N);
        if(flag){
            for(int i=1;i<=gap;i++){
                if(sq[i]){
                    cha=true;
                    vis[i]=true;
                }
            }
            int left=1;
            for(int i=1;i<=gap;i++){
                if(!vis[i]){
                    v[left++]=v[i];
                }
            }
            gap=left-1;
            flag=!flag;
        }else{
                for(int i=1;i<=gap;i++){
                    if(pi[i]){
                        cha=true;
                        vis[i]=true;
                    }
                }
                int left=1;
                for(int i=1;i<=gap;i++){
                    if(!vis[i]){
                        v[left++]=v[i];
                    }
                }
                gap=left-1;
                flag=!flag;
        }
        
    }
    return 0;
}