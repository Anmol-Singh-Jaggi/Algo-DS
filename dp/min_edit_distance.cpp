#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

size_t MinEditDistance( const string& string1, const string& string2 )
{
	vector<vector<size_t>> dp;
	dp.resize( string1.size() + 1, vector<size_t> ( string2.size() + 1, 0 ) );

	// Initializing boundary values
	for ( size_t i = 0; i <= string1.size(); i++ )
	{
		for ( size_t j = 0; j <= string2.size(); j++ )
		{
			if ( i == 0 || j == 0 )
			{
				dp[i][j] = max( i, j );
			}
		}
	}

	for ( size_t i = 0; i < string1.size(); i++ )
	{
		for ( size_t j = 0; j < string2.size(); j++ )
		{
			size_t temp = min( dp[i][j + 1], dp[i + 1][j] ) + 1;
			dp[i + 1][j + 1] = min( temp, dp[i][j] + ( string1[i] != string2[j] ) );
		}
	}

	// Printing the dp matrix
	for ( size_t i = 0; i < dp.size(); i++ )
	{
		for ( size_t j = 0; j < dp[i].size(); j++ )
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	return dp[string1.size()][string2.size()];
}

int main()
{
	string string1 = "kitten";
	string string2 = "sitting";

	print( MinEditDistance( string1, string2 ) );
}
