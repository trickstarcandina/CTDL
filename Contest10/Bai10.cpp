#include <bits/stdc++.h> 
using namespace std; 
int V,E;
struct canh{
  int dau,cuoi;
  int ts;
};
canh dscanh[1001];
int goc[1001];
void nhap(){
  memset(dscanh,0,sizeof(dscanh));
  cin>>V>>E;
	for (int i=0; i<E; i++)
		cin>>dscanh[i].dau>>dscanh[i].cuoi>>dscanh[i].ts;
}
int find(int i){
  if(goc[i]==-1) 
    return i;
  return find(goc[i]);
}
void Union(int x,int y){
  int xset=find(x);
  int yset=find(y);
  if(xset!= yset) goc[xset]=yset;
}
bool chutrinh(vector<canh> a){
  memset(goc,-1,sizeof(goc));
  for(int i=0;i<a.size();i++){
    int d=find(a[i].dau);
    int c=find(a[i].cuoi);
    if(d==c) return true;
    Union(d,c);
  }
  return false;
}
bool cmp(canh a, canh b){
  return a.ts<b.ts;
}
void Kruskal(){
  vector<canh> caykhung;
  sort(dscanh,dscanh+E,cmp);
  int temp=dscanh[0].ts;
  caykhung.push_back(dscanh[0]);
  for(int i=1;i<E;i++){
    caykhung.push_back(dscanh[i]);
    if(!chutrinh(caykhung))
      temp+=dscanh[i].ts;
    else{
      caykhung.pop_back();
      continue;
    }
    if(caykhung.size()>V-1) 
      break;
  
  }
  cout<<temp<<endl;
}
int main(){
	int t; cin >> t;
	while(t--){
	    nhap();
      Kruskal();
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
