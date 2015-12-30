#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;


// num = input
// n =  "n'th" root
// e = Required Accuracy
// iterLimit = Max. limit of iterations to be performed
double NewtonRaphson( const double& num, const int& n = 2, const double& e = 0.0001, const size_t& iterLimit = 1000000 )
{
	// Initial Guess
	double guess = 1.00;
	// Counting the number of iterationns
	size_t iter = 0;

	while ( abs( guess * guess - num ) > e )
	{
		++iter;
		if ( iter == iterLimit )
		{
			cout << "Iteration limit reached!!\n";
			break;
		}
		guess = ( ( n - 1 ) * guess + num * pow( guess, 1 - n ) ) / n;
	}

	cout << "Number of iterations = " << iter << "\n";
	cout << "Iterations remaining = " << iterLimit - iter << "\n";

	return guess;
}

int main()
{
	print( NewtonRaphson( 100000 ) );
}
