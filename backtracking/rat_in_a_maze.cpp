#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

vector<vector<int>> maze( 4, vector<int> ( 4, -1 ) );
vector<vector<int>> solution( 4, vector<int> ( 4, 0 ) );

/* A utility function to print the solution matrix */
void PrintSolution()
{
	for ( size_t i = 0; i < solution.size(); i++ )
	{
		for ( size_t j = 0; j < solution.size(); j++ )
		{
			cout << " " << solution[i][j] << " ";
		}
		cout << endl;
	}
}

/* A utility function to check if x,y is valid index for the maze */
bool IsSafe( const int& x, const int& y )
{
	if ( x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1 )
	{
		return true;
	}

	return false;
}

/* A recursive utility function to solve Maze problem */
bool SolveMazeUtil( const int& x, const int& y )
{
	if ( x == maze.size() - 1 && y == maze.size() - 1 )
	{
		solution[x][y] = 1;
		return true;
	}

	if ( IsSafe( x, y ) )
	{
		// mark x,y as part of solution path
		solution[x][y] = 1;

		/* Move forward in x direction */
		if ( SolveMazeUtil( x + 1, y ) == true )
		{
			return true;
		}

		/* If moving in x direction doesn't give solution then
		   Move down in y direction  */
		if ( SolveMazeUtil( x, y + 1 ) == true )
		{
			return true;
		}

		/* If none of the above movements work then BACKTRACK:
		    unmark x,y as part of solution path */
		solution[x][y] = 0;

		return false;
	}

	return false;
}

bool SolveMaze()
{
	if ( SolveMazeUtil( 0, 0 ) == false )
	{
		cout << "Solution doesn't exist" << endl;
		return false;
	}

	PrintSolution();
	return true;
}

int main()
{
	maze[0] = {1, 0, 0, 0};
	maze[1] = {1, 1, 0, 1};
	maze[2] = {0, 1, 0, 0};
	maze[3] = {1, 1, 1, 1};

	SolveMaze();
}
