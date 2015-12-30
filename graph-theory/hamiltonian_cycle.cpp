#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

// adjMatrix[u][v] = true if there exists an edge between u and v
vector<vector<bool>> adjMatrix;
// An auxiliary set to check if a vertex is currently included in the ham cycle or not
set<size_t> hamCycleSet;
// Contains the resultant ham cycle
vector<size_t> hamCycle;

// Add vertex to the hamiltonian cycle at the specified position
void IncludeInHamCycle( const size_t& vertex, const size_t& pos )
{
	hamCycle[pos] = vertex;
	hamCycleSet.insert( vertex );
}

// Remove vertex from the hamiltonian cycle
void RemoveFromHamCycle( const size_t& vertex )
{
	hamCycleSet.erase( vertex );
}

// Checks if a vertex can be added at index 'pos' in the Hamiltonian Cycle constructed so far
bool IsSafe( const size_t& vertex, const size_t& pos )
{
	if ( hamCycleSet.find( vertex ) != hamCycleSet.end() )
	{
		return false;
	}

	const size_t& u = hamCycle[pos - 1];
	const size_t& v = vertex;
	if ( !adjMatrix[u][v] )
	{
		return false;
	}

	return true;
}

// Returns if a hamiltonian cycle can be formed or not
bool FindHamCycleHelper( const size_t& pos )
{
	static const auto& numberOfVertices = adjMatrix.size();
	if ( pos == numberOfVertices )
	{
		const auto& u = hamCycle[pos - 1];
		const auto& v = hamCycle[0];

		if ( adjMatrix[u][v] )
		{
			return true;
		}

		return false;
	}

	for ( size_t i = 1; i < numberOfVertices; i++ )
	{
		if ( IsSafe( i, pos ) )
		{
			IncludeInHamCycle( i, pos );

			if ( FindHamCycleHelper( pos + 1 ) )
			{
				return true;
			}
			else
			{
				RemoveFromHamCycle( i );
			}
		}
	}

	return false;
}

// Returns if a hamiltonian cycle can be formed or not
bool FindHamCycle()
{
	assert( adjMatrix.size() );

	hamCycle.resize( adjMatrix.size(), -1 );
	IncludeInHamCycle( 0, 0 );

	return FindHamCycleHelper( 1 );
}

int main()
{
	adjMatrix = vector<vector<bool> >
	{
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{0, 1, 1, 1, 0},
	};

	if ( FindHamCycle() )
	{
		print( hamCycle );
	}

	adjMatrix = vector<vector<bool> >
	{
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 0},
		{0, 1, 1, 0, 0},
	};

	if ( FindHamCycle() )
	{
		print( hamCycle );
	}
}
