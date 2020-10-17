#include <bits/stdc++.h>
using namespace std;
long long n,c[50],a[50],stop=0,s;
void sinh(long long k)
{
	long long i=k;
	while(i>0&&c[i]==n-k+i) i-=1;
	if(i<=0) stop=1;
	else{
		c[i]+=1;
		for(long long j=i+1;j<=k;j++)
		c[j]=c[j-1]+1;
	}
}
void Slove()
{
	cin>>n>>s;
		for(long long i=1;i<=n;i++)
		cin>>a[i];
		for(long long i=1;i<=n;i++)
		{
			stop=0;
			for(long long j=1;j<=i;j++)
			c[j]=j;
			while(!stop)
			{
				long long res=0;
				for(long long j=1;j<=i;j++)
				res+=a[c[j]];
				if(res==s)
				{
					cout<<i;
					return;
				}
				sinh(i);
			}
		}
		cout<<"-1";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Slove();
		cout<<endl;
	}
}