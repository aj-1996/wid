#include<iostream>
#include<cmath>
using namespace std;
#define ll long long int

ll q_div[10001];

bool check_prime(ll p)
{

	if(p==1)
		return false;
	if(p==2)
		return true;
	for(int i=2;i<=sqrt(p);i++)
	{
		if(p%i==0)
			return false;

	}

return true;
}

ll getd(ll e,ll phi)
{
	ll i;
	ll d;
	for(i=2;i<=phi;i++)
	{
		d=(e*i) % phi;
		if(d==1)
			return i;

	}

}

ll powmod(ll a,ll b,ll c)
{
	ll ans=1;
	ll i;
	for(i=0;i<b;i++)
	{
		ans=(ans*a)%c;

	}

return ans%c;
}

ll prime_div(ll p)
{
	ll i;
	ll cnt=0;
	for(i=2;i<=p-1;i++)
	{
		if(check_prime(i))
		{
			ll chk=(p-1)%i;
			if(chk==0)
			{

				q_div[cnt++]=i;
				if(cnt>10)
					return cnt;

			}

		}
	}
return cnt;
}

int main()
{

	cout<<"-------------------DSA ALGORITHM-----------"<<endl;
	ll p,q,r,s,g,x,y,w,u1,u2,v,h,k,msg;
	cout<<"---------KEY GENERATION----------"<<endl;
	cout<<"Enter the value of p: "<<endl;
	cin>>p;

	q=prime_div(p);
	q=q_div[q-1];
	cout<<"The value of q is:  "<<q<<endl;

    	cout<<"Enter the message:"<<endl;

	cin>>msg;
	ll t=(p-1)/q;
    g=powmod(msg,t,p);

    cout << "The value of g is :" <<g <<endl;
	cout<<"Enter the value of private key x less than q: "<<endl;
	cin>>x;

	y=powmod(g,x,p);
	cout<<"Value of y is:  "<<y<<endl;
	cout<<"-------SIGNATURE GENERATION-----"<<endl;
	cout<<"Enter an arbitrary value of K:"<<endl;
	cin>>k;
	ll mid=powmod(g,k,p);
	r=mid%q;
	cout<<"Value of r is  "<<r<<endl;
	cout<<"Enter the message:"<<endl;

	cin>>msg;

	ll kinv=getd(k,q);

	int lol= kinv*(msg+ x*r);
	s= lol %q;

	cout<<"Value of s is  "<<s<<endl;
	cout<<"-------SIGNATURE VERIFICATION-----"<<endl;
	w=getd(s,q);
	cout<<"Value of w is  "<<w<<endl;
	cout<<"Enter the message:"<<endl;

	cin>>msg;
	u1=(msg*w)%q;
	cout<<"Value of u1 is  "<<u1<<endl;
	u2=(r*w)%q;
	cout<<"Value of u2 is  "<<u2<<endl;
	v=((powmod(g,u1,p)*powmod(y,u2,p))%p)%q;
	cout<<"Value of v is  "<<v<<endl;

	if(v==r)
		cout<<"Signature verified!"<<endl;
	else
		cout<<"Invalid Signature!"<<endl;


return 0;

}


