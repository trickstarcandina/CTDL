#include <bits/stdc++.h> 
using namespace std;
vector <string> res;
int m[10][10], n;
void nhap(){
    res.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
}
bool kt(int dong, int cot, bool a[][10]) {
    if (dong == -1 || dong == n || cot == -1 || cot == n || a[dong][cot] || m[dong][cot] == 0)
        return false;
    return true;
}
void Try(int dong, int cot, string ans, bool a[][10]) {
    if (dong == -1 || dong == n || cot == -1 || cot == n || a[dong][cot] || m[dong][cot] == 0)
        return;
    if (dong == n - 1 && cot == n - 1) {
        res.push_back(ans);
        return;
    }
    a[dong][cot] = true;
    if (kt(dong + 1, cot, a)) {
        ans.push_back('D');
        Try(dong+ 1, cot, ans, a);
        ans.erase(ans.length()-1);
    }
    if (kt(dong, cot - 1, a)) {
        ans.push_back('L');
        Try(dong, cot - 1, ans, a);
        ans.erase(ans.length()-1);
    }
    if (kt(dong, cot + 1, a)) {
        ans.push_back('R');
        Try(dong, cot + 1, ans, a);
        ans.erase(ans.length()-1);
    }
    if (kt(dong - 1, cot,a)) {
        ans.push_back('U');
        Try(dong - 1, cot, ans, a);
        ans.erase(ans.length()-1);
    }
    a[dong][cot] = false;
}
void print() {
    bool a[10][10];
    memset(a, false, sizeof(a));
    string ans;
    Try(0, 0, ans, a);
    if (res.size()) {
        int p=res.size();
        for (int i = 0; i < p; i++) {
            int o=res[i].size();
            for (int j = 0; j < o ; j++) {
                cout << res[i][j];
            }
            cout << " ";
        }
    }
    else {
        cout << -1;
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        nhap();
        if (m[0][0] == 0) cout << -1 << endl;
        else {
            print();
        }
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