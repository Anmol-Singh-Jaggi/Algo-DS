#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Wikipedia has a very nice article about it...

string string1; // "babxaab"
size_t size1;

string string2; // "abcaba"
size_t size2;

vector<vector<size_t>> dp;

// solution contains all the LCS of the 2 strings
set<string> solution;

// Function to fill 'solution'
void retrace( string parent, size_t i , size_t j )
{
	if ( i == 0 || j == 0 )
	{
		if ( !parent.empty() )
		{
			string parentReverse = parent;
			reverse( parentReverse.begin(), parentReverse.end() );
			solution.insert( parentReverse );
		}
		return;
	}

	if ( string1[i - 1] == string2[j - 1] )
	{
		parent += string2[j - 1];
		retrace( parent, i - 1, j - 1 );
	}
	else
	{
		if ( dp[i][j - 1] >= dp[i - 1][j] )
		{
			retrace( parent, i, j - 1 );
		}

		if ( dp[i][j - 1] <= dp[i - 1][j] )
		{
			retrace( parent, i - 1, j );
		}
	}
}

size_t LCS()
{
	size1 = string1.length();
	size2 = string2.length();

	dp.resize( size1 + 1, vector<size_t> ( size2 + 1, 0 ) );

	for ( size_t i = 0; i < size1; i++ )
	{
		for ( size_t j = 0; j < size2; j++ )
		{
			if ( string1[i] == string2[j] )
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max( dp[i + 1][j], dp[i][j + 1] );
			}
		}
	}

	retrace( "", size1, size2 );

	return dp[size1][size2];
}

int main()
{
	string1 = "babxaab";
	string2 = "abcaba";
	print( LCS() );
	print( solution );
	for ( size_t i = 0; i < dp.size(); i++ )
	{
		for ( size_t j = 0; j < dp[i].size(); j++ )
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}
