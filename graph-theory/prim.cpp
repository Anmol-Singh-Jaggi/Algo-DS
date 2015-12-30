#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Uses adjacency list
// Does not work on directed graphs; consider this directed graph -> [(0,1,5), (0,2,10), (2,1,4)] 

// vertex_weight.first = index of some vertex
// vertex_weight.second = weight/sum of weights of edge(s) ( exact meaning depends on the context in which it is being used)
typedef pair<size_t, int> vertex_weight;

// AdjList[i] -> vector of pair(v, weight of edge(i, v)); where v = neighbour of i
typedef vector<vector<vertex_weight> > AdjList;

// Made just for comparison
class prioritize
{
public:

	bool operator()( const vertex_weight& p1, const vertex_weight& p2 )
	{
		// Here vertex_weight refers to pair(v, shortest distance of v with the MST)
		return p1.second > p2.second;
	}
};

long long PrimMST( const AdjList& adjList )
{
	size_t numberOfVertices = adjList.size();
	assert( numberOfVertices > 0 );

	long long ans = 0;

	// vertexWeight[i] -> weight of the edge connecting a vertex in the MST to the vertex i ( where i is a vertex not in MST )
	vector<long long> vertexWeight( numberOfVertices, INT_MAX );

	// visited[i] -> Has vertex i been visited already ?
	vector<bool> visited( numberOfVertices, false );

	// For storing what edges are included in the MST eventually
	vector<size_t> parent( numberOfVertices, INT_MAX );

	// A min priority-queue used to retrieve the vertex whose key is lowest among the all the vertices not in MST
	priority_queue<vertex_weight, vector<vertex_weight>, prioritize > pq;

	vertexWeight[0] = 0;
	parent[0] = 0;

	pq.push( mp( 0, vertexWeight[0] ) );
	while ( !pq.empty() )
	{
		vertex_weight uw = pq.top();
		size_t u = uw.first;
		pq.pop();

		if ( visited[u] )
		{
			continue;
		}

		ans += uw.second;

		for ( size_t i = 0; i < adjList[u].size(); i++ )
		{
			size_t v = adjList[u][i].first;
			if ( visited[v] )
			{
				continue;
			}

			// weight = weight of the edge(u, v)
			int weight = adjList[u][i].second;

			//  If the weight of the edge(u, v) < weight of the minimum-weight edge currently connecting vertex "v" to the MST
			// "Relax" vertexWeight[v]
			if ( weight < vertexWeight[v] )
			{
				vertexWeight[v] = weight;
				pq.push( mp( v, weight ) );
				parent[v] = u;
			}
		}

		visited[u] = true;
	}

	print( parent );

	return ans;
}

int main()
{
	AdjList adjList( 4 );

	adjList[0].pb( mp( 1, 10 ) );
	adjList[1].pb( mp( 0, 10 ) );

	adjList[0].pb( mp( 2, 6 ) );
	adjList[2].pb( mp( 0, 6 ) );

	adjList[0].pb( mp( 3, 5 ) );
	adjList[3].pb( mp( 0, 5 ) );

	adjList[1].pb( mp( 3, 15 ) );
	adjList[3].pb( mp( 1, 15 ) );

	adjList[2].pb( mp( 3, 4 ) );
	adjList[3].pb( mp( 2, 4 ) );

	print( PrimMST( adjList ) );
}

