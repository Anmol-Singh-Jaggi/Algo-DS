#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef unsigned long long ULL;

// precision = Total number of digits after the decimal
void longDiv( ULL dividend, const ULL& divisor, const ULL& precision = 10 )
{
	ULL digitsPrinted = 0;

	cout << dividend / divisor;
	dividend %= divisor;

	if ( precision )
	{
		cout << ".";
	}

	while ( digitsPrinted < precision )
	{
		if ( dividend < divisor )
		{
			dividend *= 10;
		}

		while ( dividend < divisor && digitsPrinted < precision )
		{
			dividend *= 10;
			cout << "0";
			digitsPrinted++;
		}

		if ( digitsPrinted < precision )
		{
			cout << dividend / divisor;
			dividend %= divisor;
			digitsPrinted++;
		}
	}
}

int main()
{
	longDiv( 1250, 103, 100 );
}
