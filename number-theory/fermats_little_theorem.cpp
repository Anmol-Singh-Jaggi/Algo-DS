#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

bool isPrimeFermat( LL num, int iterations = 2 )
{
	if ( num == 1 )
	{
		return false;
	}

	LL a;
	while ( iterations-- )
	{
		// a = [1, num-1]
		a = rand() % ( num - 1 ) + 1;
		if ( PowMod( a, num - 1, num ) != 1 )
		{
			return false;
		}
	}

	return true;
}

int main()
{

}
