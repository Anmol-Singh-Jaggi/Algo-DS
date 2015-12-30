#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;


// The solution matrix
// -1 signifies empty cell
vector<vector<int>> solution( 8, vector<int> ( 8, -1 ) );

/* xMove[] and yMove[] define next move of Knight.
	   xMove[] is for next value of x coordinate
	   yMove[] is for next value of y coordinate */

// A knight can have only 8 possible moves from its current location
static const vector<int> xMove = {  2, 1, -1, -2, -2, -1,  1,  2 };
static const vector<int> yMove = {  1, 2,  2,  1, -1, -2, -2, -1 };


// A utility function to check if i,j are valid indexes for an N*N chessboard
bool IsSafe( const int& x, const int& y )
{
	if ( x >= 0 && x < solution.size() && y >= 0 && y < solution.size() && solution[x][y] == -1 )
	{
		return true;
	}

	return false;
}

void PrintSolution()
{
	for ( size_t x = 0; x < solution.size(); x++ )
	{
		for ( size_t y = 0; y < solution.size(); y++ )
		{
			printf( " %2d ", solution[x][y] );
		}
		printf( "\n" );
	}
}


/* A recursive utility function to solve Knight Tour problem */
int SolveKTUtil( const int& x, const int& y, const size_t& moveCount )
{

	// All cells have been filled
	if ( moveCount == solution.size() * solution.size() )
	{
		return true;
	}

	/* Try all next moves from the current coordinate x, y */
	for ( size_t i = 0; i < xMove.size(); i++ )
	{
		const int next_x = x + xMove[i];
		const int next_y = y + yMove[i];

		if ( IsSafe( next_x, next_y ) )
		{
			solution[next_x][next_y] = moveCount;

			if ( SolveKTUtil( next_x, next_y, moveCount + 1 ) == true )
			{
				return true;
			}
			else
			{
				solution[next_x][next_y] = -1;  // backtracking
			}
		}
	}

	return false;
}


/* This function solves the Knight Tour problem using Backtracking.  This
function mainly uses SolveKTUtil() to solve the problem. It returns false if
no complete tour is possible, otherwise return true and prints the tour.
Please note that there may be more than one solutions, this function
prints one of the feasible solutions.  */
bool SolveKT()
{
	// Since the Knight is initially at the first block
	// The first move is performed.
	solution[0][0]  = 0;

	/* Start from 0,0 and explore all tours using SolveKTUtil() */
	if ( SolveKTUtil( 0, 0, 1 ) == false )
	{
		cout << "Solution does not exist" << endl;
		return false;
	}
	else
	{
		PrintSolution();
	}

	return true;
}

/* Driver program to test above functions */
int main()
{
	SolveKT();
}
