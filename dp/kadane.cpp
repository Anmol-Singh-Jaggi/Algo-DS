#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

int Kadane( const vector<int>& numbers )
{
	int maxTillNow = numbers[0];
	int maxSoFar = numbers[0];

	// OPTIONAL: These variables can be added in to track the position of the subarray
	// size_t begin = 0;
	// size_t beginTemp = 0;
	// size_t end = 0;

	for ( size_t i = 1; i < numbers.size(); i++ )
	{
		if ( maxTillNow < 0 )
		{
			maxTillNow = numbers[i];
			// beginTemp = i;
		}
		else
		{
			maxTillNow += numbers[i];
		}

		if ( maxTillNow >= maxSoFar )
		{
			maxSoFar  = maxTillNow;
			// begin = beginTemp;
			// end = i;
		}
	}

	return maxSoFar ;
}

int main()
{
	vector<int> vec = { -2, -3, 4, -1, -2, 1, 5, -3};
	print( Kadane( vec ) );
}
