#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

bool isPrimeMillerRabin( LL num, size_t iterations = 5 )
{
	// Return false if num = 1 or num = even( except 2 obviously )
	if ( ( num == 1 ) || ( ( num != 2 ) && ( ( num & 1 ) == 0 ) ) )
	{
		return false;
	}

	LL a, temp, sbak, s = num - 1;
	// Make s such that (2^d)*s = num - 1
	while ( ( s & 1 ) == 0 )
	{
		s >>= 1;
	}

	while ( iterations-- )
	{
		// a = [1,p-1]
		a = rand() % ( num - 1 ) + 1;
		// Backup of s
		sbak = s;
		// (a ^ s) % num
		temp = PowMod( a, sbak, num );

		while ( sbak != num - 1 && temp != 1 && temp != num - 1 )
		{
			temp = MulMod( temp, temp, num );
			sbak <<= 1;  //  Multiply sbak by 2 until it becomes num - 1 [which was (2^d)*sbak]
		}

		if ( temp != num - 1 && ( sbak & 1 ) == 0 )
		{
			return false;
		}
	}

	return true;
}

int main()
{

}
