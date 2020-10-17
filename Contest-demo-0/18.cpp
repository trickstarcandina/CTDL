#include<bits/stdc++.h>
using namespace std;
void xuat(int a[]){
    for(int i=1;i<=26;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void check(int a[],int b[]){
    int dem=0;
    for(int i=1;i<26;i++){
        if(a[i]<a[i+1] && a[i+1]<b[i] && b[i]<b[i+1]) dem++; 
    }
    cout<<dem;
}
void pro(string s){
    int a[26]; int b[26];
    char x='A';
    int j=1; int k=1;
    int c[52];
    for(int i=0;i<52;i++) c[i]=1;
    for(int m=0;m<26;m++){
        for(int i=0;i<s.length();i++){
            if(c[i]!=0){
                if(s[i]==x) {
                    a[j]=i; j++; c[i]=0;
                    break;

                }
            }    
        }
        for(int i=0;i<s.length();i++){
            if(c[i]!=0){
                if(s[i]==x) {
                    b[k]=i; k++; c[i]=0;
                    break;
                }
            }    
        }
        x++;
    }
    //xuat(a);
    //xuat(b);
    check(a,b);
}
int main(){
    string s;
    cin>>s;
    pro(s);
    cout<<endl;
    return 0;
}