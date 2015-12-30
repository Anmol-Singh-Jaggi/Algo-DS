#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

// Calculate ans = (num inverse) modulo (mod) such that (ans * num)%mod = 1
int inverseMod( int num, int mod )
{
	assert( __gcd( num, mod ) == 1 );
	return ( extendedGCD( num, mod ).first + mod ) % mod;
}

int main()
{

}
