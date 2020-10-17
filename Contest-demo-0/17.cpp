#include<iostream>
#include<math.h> 
using namespace std;
long long ktcp(long long a){
	long long b=sqrt(a);
	if(b*b==a) return b;
	b++;
	if(b*b==a) return b;
	return 0;
}
int main(){
        long long a,b,c,d,e,f,x,y;
	    cin>>a>>b>>c>>d>>e>>f;
	    x=a*b+c*d+f*e;
	    y=ktcp(x);
	    if(y==0) cout<<"NO";
	    else{
	    	if(a>b) swap(a,b);
	    	if(c>d) swap(c,d);
	    	if(e>f) swap(e,f);
	    	if(b==d && d==f && f==y) cout<<"YES";
	    	else{
	    		if(d==y) {swap(a,c); swap(b,d);}
	    		if(f==y) {swap(a,e); swap(b,f);}
	    		if(b==y){
	    			a=y-a;
				    if((c==a && e==a) || (d==a && e==a)|| (c==a && f==a) || (d==a && f==a))  cout<<"YES";
				    else cout<<"NO";
			    }		
			    else cout<<"NO";
		    }
	    }
    return 0;	
}