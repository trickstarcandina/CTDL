#include <iostream>
#include <vector>
using namespace std;
int dem=0; vector <int> b;
void nhap(int a[],int &n){
    for (int i=0;i<n;i++){ 
        a[i]=(i+1);
    }
}
void nhap2(int c[][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>c[i][j];
    }
}
void print(int a[],int c[][10],int n,int k) { 
    int s=0;
    for(int i=0;i<n;i++){
        s+=c[i][a[i]-1];
    }
    if(s==k){
       for (int i=0; i<n; i++) 
            b.push_back(a[i]);
       // cout << a[i]<<" "; 
       b.push_back(-1);
    //cout <<endl;
    dem++;
    }   
}
void xuly(int a[],int c[][10], int n,int k) {
    while (true) {
        print(a,c,n,k); 
        int k, l;
        for (k = n-2; k>=0; k--) if (a[k] < a[k+1]) break; 
        if (k<0) break;                                   
        for (l = n-1; l>k; l--) if (a[k] < a[l]) break; 
        swap(a[k], a[l]); 
        for (int i=k+1, j=n-1; i<j; i++, j--) swap(a[i], a[j]); 
    }
}
int main(){
    int n,k; cin>>n>>k; int a[n]; int c[10][10];
    nhap(a,n); nhap2(c,n);
    xuly(a,c,n,k);
    cout<<dem<<endl;
    for(int i=0;i<b.size();i++){
        if(b[i]==-1) cout<<endl;
        else cout<<b[i]<<" ";
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