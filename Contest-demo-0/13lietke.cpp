#include<iostream>
using namespace std;
int a[10000],b[10000],n=0;
int tim(int x){
    for(int i=0;i<n;i++)
        if(a[i]==x) return i;
    return -1;
}
int csnt(int n){
    while(n>0){
        int t=n%10;
        if(t!=2 && t!=3 && t!=5 && t!=7) return 0;
        n=n/10;
    }
    return 1;
}
main(){
    int x,i;
    while(cin>>x){
        if(csnt(x)){
            int t=tim(x);
            if(t==-1){
                a[n]=x; b[n]=1;
                n++;
            }
            else b[t]++;
        }
    }
    for(i=0;i<n;i++) cout<<a[i]<<" "<<b[i]<<endl;    
}