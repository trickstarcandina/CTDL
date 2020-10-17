#include <bits/stdc++.h>
using namespace std;
int main ()
{
  int matrix[10][10] ;
  //memset (str,'-',sizeof(str));
  memset(matrix, 0, sizeof(matrix));
  for (int i = 0; i < 10; i++)
  {
      for(int j=0;j<10;j++)
      cout<<matrix[i][j];
      /* code */
      cout<<endl;
  }
  
  return 0;
}