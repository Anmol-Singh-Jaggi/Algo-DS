#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Complexity -> O(E*log(E)+E*log(V))

struct Edge
{
	// edge joining vertices (v1,v2) having weight = "weight"
	size_t v1, v2;
	int weight;

	Edge( const size_t& _v1 = 0, const size_t& _v2 = 0, const int& _weight = 0 )
	{
		this->v1 = _v1;
		this->v2 = _v2;
		this->weight = _weight;
	}
};

ostream& operator <<( ostream& out, const Edge& edge )
{
	out << "( " << edge.v1 << ", " << edge.v2 << ", " << edge.weight << " )";
	return out;
}

bool operator <( const Edge& edge1, const Edge& edge2 )
{
	return edge1.weight < edge2.weight;
}

long long kruskalMST( vector<Edge>& edges, const size_t& numberOfVertices )
{
	assert( numberOfVertices > 0 );

	sort( edges.begin(), edges.end() );

	DisjointSet ds( numberOfVertices + 1 );

	// The resultant MST
	vector<Edge> Mst;

	long long ans = 0;
	size_t edgesIt = 0;

	while ( Mst.size() != numberOfVertices - 1 )
	{
		int parent1 = ds.findParent( edges[edgesIt].v1 );
		int parent2 = ds.findParent( edges[edgesIt].v2 );
		if ( parent1 != parent2 )
		{
			ds.join( parent1, parent2 );
			ans += edges[edgesIt].weight;
			Mst.pb( edges[edgesIt] );
		}
		edgesIt++;
	}

	print( Mst );

	return ans;
}

int main()
{
	vector<Edge> edges;
	edges.pb( Edge( 0, 1, 10 ) );
	edges.pb( Edge( 0, 2, 6 ) );
	edges.pb( Edge( 0, 3, 5 ) );
	edges.pb( Edge( 1, 3, 15 ) );
	edges.pb( Edge( 2, 3, 4 ) );

	print( kruskalMST( edges, 4 ) );
}

