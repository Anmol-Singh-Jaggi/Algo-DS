#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// Complexity -> O( E + V )

typedef vector<vector<size_t> > AdjList;
AdjList adjList;

// visited[i] -> Has vertex i been visited already?
vector<bool> visited;

// parent[i] -> Predecessor of vertex i in the DFS tree
// Used just for printing the DFS tree
vector<size_t> parent;

size_t target;
void DFS ( const size_t& source )
{
  if ( visited[target] )
  {
    return;
  }
  visited[source] = true;

  const size_t& u = source;
  for ( size_t i = 0; i < adjList[u].size(); i++ )
  {
    size_t v = adjList[u][i];
    if ( visited[v] )
    {
      continue;
    }

    parent[v] = u;
    DFS ( v );
  }
}


int main()
{
  adjList.resize ( 5 );
  visited.resize ( adjList.size(), false );
  parent.resize ( adjList.size(), 0 );

  adjList[0].pb ( 1 );
  adjList[0].pb ( 2 );

  adjList[1].pb ( 2 );
  adjList[1].pb ( 4 );

  adjList[2].pb ( 1 );
  adjList[2].pb ( 3 );

  adjList[3].pb ( 4 );

  const size_t source = 0;
  target = 3;

  DFS ( source );

  print ( parent );
}
