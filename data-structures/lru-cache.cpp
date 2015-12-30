#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

class LruCache
{
	// The maximum items which can be held by the cache at a time
	const size_t maxCacheSize;

	// Holds the page numbers
	// The item at (end()-1) is the most recently used page
	// The item at begin() is the least recently used page
	list<int> cacheQueue;

	// Holds the node in the linked list corresponding to every page number
	unordered_map<int, list<int>::iterator> cacheHashTable;

	// Determines if the page is present in the cache or not
	bool IsPagePresent( const int& pageNumber ) const
	{
		return ( cacheHashTable.find( pageNumber ) != cacheHashTable.end() );
	}

	// Removes a page from the cache
	void RemovePage( const int& pageNumber )
	{
		cacheQueue.erase( cacheHashTable[pageNumber] );
		cacheHashTable.erase( pageNumber );
	}

	// Inserts a page into the cache
	void InsertPage( const int& pageNumber )
	{
		cacheQueue.push_back( pageNumber );
		cacheHashTable[pageNumber] = --cacheQueue.end();
	}

public:

	LruCache( const size_t& _maxCacheSize ): maxCacheSize( _maxCacheSize ) {}

	void ReferencePage( const int& pageNumber )
	{
		if ( IsPagePresent( pageNumber ) )
		{
			RemovePage( pageNumber );
		}
		else if ( cacheQueue.size() == maxCacheSize )
		{
			RemovePage( cacheQueue.front() );
		}

		InsertPage( pageNumber );

		assert( cacheQueue.size() == cacheHashTable.size() );
		assert( cacheQueue.size() <= maxCacheSize );

	}

	// Prints the contents of the cache in the order -> least-recent to most-recent
	void Print() const
	{
		cout << cacheQueue;
	}

};

int main()
{
	LruCache cache( 4 );

	cache.ReferencePage( 1 );
	cache.ReferencePage( 2 );
	cache.ReferencePage( 3 );
	cache.ReferencePage( 1 );
	cache.ReferencePage( 4 );
	cache.ReferencePage( 5 );

	cache.Print();
}
