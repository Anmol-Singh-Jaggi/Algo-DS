#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Forward declaration of the class
template<typename T> class HashTable;

// Declaration for friend functions
template<typename T>
std::ostream& operator <<( std::ostream&, const HashTable<T>& );

// A hash-table in which nodes are a pair of <string, T> where T can be any compound structure.
// In other words, pair.first(string) is the key and pair.second(T) is the corresponding value.
template<typename T>
class HashTable
{
	typedef pair<string, T> Node;

	const size_t hashTableSize;
	vector<list<Node> > hashTableArr;
	// A list of indices in the hash-table array where there are nodes present
	set<size_t> occupied;

	size_t GenerateHash( const string& key )
	{
		unsigned long long ans = 0, j = 1;
		for ( size_t i = 0; i < key.length(); i++ )
		{
			ans += ( ( key[i] - 'a' ) * j ) % hashTableSize;
			j <<= 1;
		}

		return ans % hashTableSize;
	}

public:

	HashTable( const size_t hashTableSiz = 1000 ): hashTableSize( hashTableSiz )
	{
		hashTableArr.resize( hashTableSize );
	}

	// Find the node with the specified key
	Node* Find( const string& key ) const
	{
		const auto hash = GenerateHash( key );
		const list<Node>& bucket = hashTableArr[hash];

		for ( const auto it = bucket.begin(); it != bucket.end(); ++it )
		{
			if ( ( *it ).first == key )
			{
				return &( *it );
			}
		}

		return nullptr;
	}

	// Return the number of nodes in the hash table
	size_t Size() const
	{
		return occupied.size();
	}

	// Insert a new node in the hash table
	void Insert( const Node& node )
	{
		const size_t hash = GenerateHash( node.first );
		hashTableArr[hash].push_back( node );
		occupied.insert( hash );
	}

	// Delete all the nodes in the hash table
	void Clear()
	{
		// Doing this instead of `hashTableArr.clear()` to improve performance
		for ( const auto& it : occupied )
		{
			hashTableArr[it].clear();
		}
		occupied.clear();
	}

	// Remove the specified node
	void Remove( const Node& node )
	{
		const auto hash = GenerateHash( node.first );
		hashTableArr[hash].remove( node );
		occupied.erase( hash );
	}

	friend std::ostream& operator << <>( std::ostream&, const HashTable<T>& );
};


// Print a HashTable
template<typename T>
std::ostream& operator <<( std::ostream& out, const HashTable<T>& hashTable )
{
	for ( const auto& it : hashTable.occupied )
	{
		const list<typename HashTable<T>::Node>& bucket = hashTable.hashTableArr[it];
		cout << it << " => " << bucket << endl;
	}
	return out;
}


int main()
{
	HashTable<pair<string, int>> ht;

	pair<string, int> x;

	x.first = "a";
	x.second = 1;
	ht.Insert( mp( x.first, x ) );

	x.first = "b";
	x.second = 2;
	ht.Insert( mp( x.first, x ) );

	x.first = "c";
	x.second = 3;
	ht.Insert( mp( x.first, x ) );

	x.first = "d";
	x.second = 4;
	ht.Insert( mp( x.first, x ) );

	x.first = "e";
	x.second = 5;
	ht.Insert( mp( x.first, x ) );

	print( ht );

	x.first = "b";
	x.second = 2;
	ht.Remove( mp( x.first, x ) );

	print( ht );
}
