#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

class TinyURLWebsite
{
	// Mapping integers(short URL's in base 10) to strings(long URL's)
	vector<string> mapping;
	// Mapping strings(long URL's) to integers(short URL's in base 10)
	// Used for preventing duplicate entries
	unordered_map<string, size_t> reverseMapping;
	// Used for base conversion
	string charset;

	// Returns the index of the new long URL as the unique ID
	size_t GetUniqueID() const
	{
		return mapping.size();
	}

	string Base10To62( size_t base10 ) const
	{
		string result;

		do
		{
			result.push_back( charset[base10 % 62] );
			base10 /= 62;
		}
		while ( base10 );

		reverse( result.begin(), result.end() );
		return result;
	}

	size_t Base62To10( const string& base62 ) const
	{
		size_t base10 = 0;

		for ( size_t i = 0; i < base62.length(); i++ )
		{
			const size_t index = charset.find( base62[i] );
			assert( index != string::npos );

			base10 = base10 * 62 + index;
		}

		return base10;
	}

public:

	TinyURLWebsite()
	{
		charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}

	// Returns the short version of the input long-URL
	// Note that the return value does not hold any relation with the input string's value
	string ToShort( const string& longUrl )
	{
		size_t shortUrlBase10;

		const auto it = reverseMapping.find( longUrl );
		// If the long URL is already present
		if ( it != reverseMapping.end() )
		{
			cout << "Input URL - '" << longUrl << "' already in database!\n";
			shortUrlBase10 = it->second;
		}
		// Else insert it into the database
		else
		{
			shortUrlBase10 = GetUniqueID();
			mapping.push_back( longUrl );
			reverseMapping[longUrl] = shortUrlBase10;
		}

		const string shortUrlBase62 = Base10To62( shortUrlBase10 );
		return shortUrlBase62;
	}

	// Returns the original form the short URL
	string ToLong( const string& shortUrl ) const
	{
		const size_t shortUrlBase10 = Base62To10( shortUrl );
		assert( shortUrlBase10 < mapping.size() );
		return mapping[shortUrlBase10];
	}
};

int main()
{
	TinyURLWebsite website1;
	string longUrl, shortUrl;

	longUrl = "www.google.com";
	print( longUrl );
	shortUrl = website1.ToShort( longUrl );
	print( shortUrl );
	longUrl = website1.ToLong( shortUrl );
	print( longUrl );
	cout << "\n\n";

	longUrl = "www.tumblr.com";
	print( longUrl );
	shortUrl = website1.ToShort( longUrl );
	print( shortUrl );
	longUrl = website1.ToLong( shortUrl );
	print( longUrl );
	cout << "\n\n";

	longUrl = "www.youtube.com";
	print( longUrl );
	shortUrl = website1.ToShort( longUrl );
	print( shortUrl );
	longUrl = website1.ToLong( shortUrl );
	print( longUrl );
	cout << "\n\n";

	longUrl = "www.google.com";
	print( longUrl );
	shortUrl = website1.ToShort( longUrl );
	print( shortUrl );
	longUrl = website1.ToLong( shortUrl );
	print( longUrl );
	cout << "\n\n";

}
