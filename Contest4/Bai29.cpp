#include<bits/stdc++.h> 
using namespace std;
pair <double ,double> a[100000];
pair <double ,double> t[100000];
void nhap(int n){
	for (int i=0; i<n; i++) 
		cin >> a[i].first >> a[i].second;
}
// tinh kcach A va B + update
void kcach(pair <double ,double> &a,pair <double ,double> &b,double & res) {
    double kq = sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) );
    if (kq < res) res = kq;
}
bool sxep1(pair <double ,double> &a,pair <double ,double> &b) {
    return a.first < b.first;
}
bool sxep2(pair <double ,double> &a,pair <double ,double> &b) {
    return a.second < b.second;
}
void xuly(int l, int r,double &res) {
    if (r <= l) return;
    // đoạn [l,r] có 2 phần tử
    if (r == l + 1) {
        kcach(a[l], a[r],res);
        // sắp các phần tử lại theo y
        if (!sxep2(a[l], a[r])) swap(a[l], a[r]);
        return;
    }
    int m = (l + r) / 2;
    double midx = a[m].first;
    xuly(l, m,res);
    xuly(m+1, r,res);
    // trộn a[l,m] và a[m+1,r] lại, lưu vào mảng tạm t
    merge(a+l, a+m+1, a+m+1, a+r+1, t, sxep2);
    // copy từ t về lại a
    copy(t, t+r-l+1, a+l);
    // mảng t ở đây lưu các phần tử thỏa |x_i - midx| < res, với số lượng phần tử là tmp do đã sort nên các phần tử sẽ có y tăng dần
    int tmp = 0;
    for (int i=l; i<=r; i++) 
		if (abs(a[i].first-midx) < res) {
        	for (int j=tmp-1; j>=0 && t[j].second > a[i].second-res; j--)
            	kcach(a[i], t[j],res);
        	t[tmp++] = a[i];
    }
}
int main() {
	int t; cin>>t;
	while (t--){
		int n; cin >> n;
		double res; // luu ket qua
    	res = 3e6;
		nhap(n);
    	sort(a, a+n, sxep1);
    	xuly(0, n-1,res);
		printf("%0.6lf", res);
		cout<<endl;
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