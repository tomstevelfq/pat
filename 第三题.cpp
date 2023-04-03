#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<list>

using  namespace std;
const int N=1e5;
int ine[N];
int oute[N];

int main(){
    freopen("test.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<string> name;
    vector<string> ret;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        ine[b]++;
        oute[a]++;
    }
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        name.push_back(str);
    }
    for(int i=0;i<n;i++){
        if(oute[i]>ine[i]){
            ret.push_back(name[i]);
        }
    }
    sort(ret.begin(),ret.end());
    for(auto it:ret){
        cout<<it<<endl;
    }
    return 0;
}