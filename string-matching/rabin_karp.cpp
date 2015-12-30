#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

void RabinKarp( const string& text, const string& pattern )
{
	assert( text.size() >= pattern.size() );

	const int mod = 10000009;
	const long long base = 33;

	// pHash = pattern's hash
	// sHash = text's substring hash
	size_t weight = 1, pHash = 0, sHash = 0;

	for ( size_t i = 0; i < pattern.size() - 1; i++ )
	{
		// weight = base ^ (len(pattern)-1)
		weight = ( weight * base ) % mod;
	}
	
	// hash = str[0] + str[1] * base + str[2] * base^2 + str[3] * base^3 + .... str[n-1] * base^n-1
	for ( size_t i = 0; i < pattern.size(); i++ )
	{
		pHash = ( pHash * base + pattern[i] ) % mod;
		sHash = ( sHash * base + text[i] ) % mod;
	}

	for ( size_t i = 0; i < text.size() - pattern.size(); i++ )
	{
		if ( pHash == sHash )
		{
			if ( text.substr( i, pattern.size() ) == pattern )
			{
				cout << "Match found at index " << i << "\n";
			}
		}
		
		sHash = ( sHash - ( text[i] * weight ) % mod + mod ) % mod;
		sHash = ( sHash * base ) % mod;
		sHash = ( sHash + text[i + pattern.size()] ) % mod;
	}
}

int main()
{
	string text = "AAACAAAA";
	string pattern = "ACA";
	RabinKarp( text, pattern );
}
