#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long long ULL;
typedef long double LD;

ULL PowerInFactorial( ULL num, const ULL& prime )
{
	ULL ans = 0;

	while ( num )
	{
		ans += num / prime;
		num /= prime;
	}

	return ans;
}

int main()
{

}
