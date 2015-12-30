#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

string DecimalToBase( size_t decimal, const size_t base )
{
	assert( base <= 36 );

	const string source = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ansReverse;

	do
	{
		ansReverse.push_back( source[decimal % base] );
		decimal /= base;
	}
	while ( decimal );

	reverse( ansReverse.begin(), ansReverse.end() );

	return ansReverse;
}

int main()
{
	print( DecimalToBase( 10, 2 ) );
}
