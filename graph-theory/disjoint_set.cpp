#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

struct DisjointSet
{

	vector<size_t> parent, groupSize;

	DisjointSet( const size_t& size )
	{
		parent.resize( size, 0 );
		for ( size_t i = 0; i < size; i++ )
		{
			parent[i] = i;
		}
		groupSize.resize( size, 1 );
	}

	void reset()
	{
		for ( size_t i = 0; i < parent.size(); i++ )
		{
			parent[i] = i;
			groupSize[i] = 1;
		}
	}

	// Path compression
	// Complexity -> ??
	size_t findParent( const size_t& index )
	{
		return parent[index] = ( ( index == parent[index] ) ? index : findParent( parent[index] ) );
	}

	void join( const size_t& index1, const size_t& index2 )
	{
		int parent1 = findParent( index1 ), parent2 = findParent( index2 );
		if ( parent1 == parent2 )
		{
			return;
		}

		// Union by rank
		// Complexity -> ??
		if ( groupSize[parent1] < groupSize[parent2] )
		{
			parent[parent1] = parent2;
			groupSize[parent2] += groupSize[parent1];
		}
		else
		{
			parent[parent2] = parent1;
			groupSize[parent1] += groupSize[parent2];
		}
	}

};

int main()
{
	DisjointSet ds( 6 );

	print( ds.parent );

	ds.join( 0, 1 );
	print( ds.parent );

	ds.join( 2, 3 );
	print( ds.parent );

	ds.join( 4, 5 );
	print( ds.parent );

	ds.join( 0, 5 );
	print( ds.parent );

	ds.findParent( 5 );
	print( ds.parent );
}
