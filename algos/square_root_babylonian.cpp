#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;


// num = input
// e = Required Accuracy
// iterLimit = Max. limit of iterations to be performed
double BabylonianSquareRoot( const double& num, const double& e = 0.0001, const size_t& iterLimit = 1000000 )
{
	// We are using the number itself as the initial approximation
	double guess = num;
	double y = 1;

	size_t iter = 0;

	while ( guess - y > e )
	{
		++iter;
		if ( iter == iterLimit )
		{
			cout << "Iteration limit reached!!\n";
			break;
		}

		guess = ( guess + y ) / 2;
		y = num / guess;
	}

	return guess;
}

int main()
{
	print( BabylonianSquareRoot( 10000 ) );
}
