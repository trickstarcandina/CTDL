#include <bits/stdc++.h> 
using namespace std; 
string str;
pair <  vector<int>,vector<int>  >  a;
void nhap(){
    cin>>str;
    int l=str.length();
    //cout<<l<<endl;
    for(int i=0;i<l;i++){
        if(str[i]=='(') {
            a.first.push_back(1); a.second.push_back(i);
        }
        else {
            a.first.push_back(0); a.second.push_back(i);
        }
    }
}
void in(){
    int l=a.second.size();
    for(int i=0;i<l;i++)
        cout<<a.first[i]<<" ";
    cout<<endl;
    for(int i=0;i<l;i++)
        cout<<a.second[i]<<" ";
    cout<<endl;
}
int check(){
    int n=a.first.size();
    int mo=0,dong=0;
    for(int i=0;i<n;i++){
        if(a.first[i]==1) mo++;
        else dong++;
    }
    if(mo==dong) return 0;
    else return (mo-dong);
}
void xuat(){
    int n=a.first.size();
    for(int i=0;i<n;i++){
        cout<<str[a.second[i]];
    }
    cout<<" ";
}
void tryhard1(int &i,int &j){
    while (i<j){
        if(a.first[i]==0){
            //cout<<"."<<endl;
            a.first.erase(a.first.begin());
            a.second.erase(a.second.begin());
            //j=a.first.size(); 
            j--;
            tryhard(i,j);  
        } 
        break; 
    }
    while (i<j){
        if(a.first[j-1]==1){
            //cout<<","<<endl;
            a.first.erase(a.first.begin()+j-1);
            a.second.erase(a.second.begin()+j-1);
            //j=a.first.size();
            j--;
            tryhard(i,j);  
        }
        break;
    }
}
void tryhard2(int &i,int &j){
    int t=check();
    if(t==0){
        xuat();
        return;
    }
    else if(t>0){
        for(int k=i;k<j-1;k++){
            if(t!=0){
                if(a.first[k]==1){
                    tryhard2(k+1,j);
                    t--;
                }
            }
            else {
                xuat();
                tryhard2(i+check(),j);
            }
        }
    }
    else{

    }
}
int main() { 
    int t; cin>>t;
    while(t--){
        nhap();
        //in();
        int i=0;
        int j=a.first.size();
        tryhard(i,j);
        in();
    }
    return 0; 
} 
/*
Trickstar Candina
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
*/