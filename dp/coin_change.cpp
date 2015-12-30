#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

size_t CoinChange( const vector<size_t> denominations, const size_t& TargetValue )
{
	const size_t numberOfDenominations = denominations.size();

	vector<vector<size_t>> dp( TargetValue + 1, vector<size_t>( numberOfDenominations, 0 ) );

	// Fill the entries for the 0-value case.
	for ( size_t i = 0; i < numberOfDenominations; i++ )
	{
		dp[0][i] = 1;
	}

	// Fill rest of the table enteries in bottom up manner
	for ( size_t value = 1; value < TargetValue + 1; value++ )
	{
		for ( size_t denominationsIt = 0; denominationsIt < numberOfDenominations; denominationsIt++ )
		{
			// Number of solutions including at least one coin having value "denominations[denominationsIt]"
			size_t part1 = ( value >= denominations[denominationsIt] ) ? dp[value - denominations[denominationsIt]][denominationsIt] : 0;

			// Number of solutions excluding all the denominationsIt having value "denominations[j]"
			size_t part2 = ( denominationsIt >= 1 ) ? dp[value][denominationsIt - 1] : 0;

			// Total count
			dp[value][denominationsIt] = part1 + part2;
		}
	}

	return dp[TargetValue][numberOfDenominations - 1];
}

int main()
{
	vector<size_t> denominations = {2, 3, 5, 6};
	print( CoinChange( denominations, 10 ) );
}
