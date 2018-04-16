#include<iostream>
#include<cmath>
using namespace std;

#define ll long long int

bool check_prime(ll num)
{
	int i;
	if(num==0|| num==1)
		return false;
	if(num==2)
		return true;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
			return false;

	}
return true;
}
ll gcd(ll a,ll b)
{
	ll temp;
	while(1)
	{
		temp=a%b;
		if(temp==0)
			return b;
		else
		{
			a=b;
			b=temp;
		}
	}
}

ll getd(ll e,ll phi)
{
	ll d,i;
	for( i=2;i<phi;i++)
	{

		d=(e*i) % phi;
		if(d==1)
			return i;

	}
}

ll powmod(ll a,ll b, ll c)
{

	ll i;
	int ans=1;
	for(i=1;i<=b;i++)
	{
		ans=(ans*a)%c;

	}
	return ans %c;

}

void encrypt(ll P,ll e,ll n)
{
	ll cipher;
	if(P)
	cipher=powmod(P,e,n);
	cout<<"cipher text is: "<<cipher<<endl;


}
void decrypt(ll C,ll d,ll n)
{
	ll plain=powmod(C,d,n);
	cout<<"Plain text is: "<<plain<<endl;


}
int main()
{
	ll p,q,phi,n,e,d;
	cout<<"-----------RSA------------"<<endl;
	cout<<"Enter the value of p:"<<endl;
	cin>>p;
	cout<<"Enter the valut of q:"<<endl;
	cin>>q;
	if(check_prime(p)==false ||check_prime(q)==false || p==q)
	{
		cout<<"Invalid input ... try again..!"<<endl;
		return 0;



	}

	n=p*q;
	phi=(p-1)*(q-1);
	cout<<"The value of n="<<n<<endl;
	cout<<"The value of phi="<<phi<<endl;
	cout<<"Enter value of e:(1<e<phi)"<<endl;
	cin>>e;
	if(gcd(e,phi)==1)
	{
		d=getd(e,phi);
		cout<<"Value of d="<<d<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"public key"<<"["<<n<<" "<<e<<"]"<<endl;
		cout<<"private key"<<"["<<n<<" "<<d<<"]"<<endl;
		cout<<"-----------------------------------------"<<endl;
		int ch;
		ll P,C;
		while(true)
		{

			cout<<"--------MENU-------"<<endl;
			cout<<"1. Encrypt a message:"<<endl;
			cout<<"2. Decrypt a message:"<<endl;
			cout<<"Enter choice:"<<endl;
			cin>>ch;
			switch(ch)
			{

				case 1:
					cout<<"Enter message:";
					cin>>P;
					encrypt(P,e,n);
					cout<<endl;
				case 2:
					cout<<"Enter encrypted message:";
					cin>>C;
					decrypt(C,d,n);
					cout<<endl;
				case 3:
                    return 0;

			}



		}
	}
	else
 		cout<<"Invalid input";
return 0;
}

