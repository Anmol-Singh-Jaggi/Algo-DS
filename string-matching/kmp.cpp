#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

vector<size_t> BuildFailure( const string& pattern )
{
	
	// failure[i] = length of the longest proper prefix of pattern[0,i] which is also a proper suffix of pattern[0,i]
	// i.e. failure[i] = length of the longest "prefix-suffix" of pattern[0,i] :D
	vector<size_t> failure( pattern.size(), 0 );

	// length of the previous longest prefix-suffix
	size_t len = 0, i = 1;

	while ( i < pattern.size() )
	{
		if ( pattern[i] == pattern[len] )
		{
			failure[i++] = ++len;
		}
		else
		{
			if ( len )
			{
				// This is tricky. Consider the example AAACAAAA and i = 7.
				// Also, note that we do not increment i here
				len = failure[len - 1];
			}
			else
			{
				failure[i++] = 0;
			}
		}
	}
	return failure;
}

void KMP( const string& text, const string& pattern )
{
	assert( text.size() >= pattern.size() );
	
	vector<size_t> failure = BuildFailure( pattern );

	size_t i = 0, j = 0;
	while ( i < text.size() )
	{
		if ( pattern[j] == text[i] )
		{
			j++;
			i++;
		}

		if ( j == pattern.size() )
		{
			cout << "Found pattern at index " << i - j << "\n";
			j = failure[j - 1];
		}
		// Mismatch after j matches
		else if ( pattern[j] != text[i] )
		{
			if ( j )
			{
				// Do not match failure[0..failure[j-1]] characters; they will match anyway!!
				j = failure[j - 1];
			}
			else
			{
				i++;
			}
		}
	}
}

int main()
{
	string text = "AAACAAAA";
	string pattern = "ACA";
	KMP( text, pattern );
}
