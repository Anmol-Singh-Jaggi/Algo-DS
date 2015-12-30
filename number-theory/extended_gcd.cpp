#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

typedef long long LL;
typedef long double LD;

// first and second must be co-prime
// Returns "x" in the equation "1 = x(first) + y(second)"
pair<int, int> extended_gcd( int first, int second )
{
	pair<int, int> coeffFirst( 1, 0 ); // first = first(1) + second(0)
	pair<int, int> coeffSecond( 0, 1 ); // second = first(0) + second(1)
	pair<int, int> temp;

	int q, r;
	do
	{
		q = first / second;
		r = first % second;
		temp = coeffSecond;
		coeffSecond = make_pair( coeffFirst.first - q * coeffSecond.first, coeffFirst.second - q * coeffSecond.second );
		coeffFirst = temp;
		first = second;
		second = r;
	}
	while ( r );

	return coeffFirst;
}


int main()
{

}
