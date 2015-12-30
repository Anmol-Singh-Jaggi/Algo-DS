#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Its wrong!!!
// Output for 40 is XL not XXXX

string DecimalToRoman( size_t decimal )
{
	string roman;
	const static map<size_t, string> numerals
	{
		{1, "I"}, {2, "II"}, {3, "III"},
		{4, "IV"}, {5, "V"}, {6, "VI"},
		{7, "VII"}, {8, "VIII"}, {9, "IX"},
		{10, "X"}, {50, "L"}, {100, "C"},
		{500, "D"}, {1000, "M"}
	};

	for ( auto it = numerals.rbegin(); it != numerals.rend(); ++it )
	{
		size_t count = decimal / it->first;
		while ( count-- )
		{
			roman += it->second;
		}
		decimal %= it->first;
	}

	return roman;
}

int main()
{
	print( DecimalToRoman( 130 ) );
}
