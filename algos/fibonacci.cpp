#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

const int MOD = 1000000007;

typedef unsigned long long ULL;
typedef vector<vector<ULL> > Matrix;

Matrix MatrixMul( Matrix matrix1, Matrix matrix2 )
{
	Matrix product( 2, vector<ULL>( 2, 0 ) );
	for ( size_t i = 0; i < 2; i++ )
		for ( size_t j = 0; j < 2; j++ )
			for ( size_t k = 0; k < 2; k++ )
			{
				product[i][j] = ( product[i][j] + matrix1[i][k] * matrix2[k][j] ) % MOD;
			}
	return product;
}

Matrix MatrixPow( Matrix matrix, ULL power )
{
	if ( power == 1 )
	{
		return matrix;
	}

	if ( power & 1 )
	{
		return MatrixMul( matrix, MatrixPow( matrix, power - 1 ) );
	}

	Matrix temp = MatrixPow( matrix, power / 2 );
	return MatrixMul( temp, temp );
}

ULL Fibonacci( ULL n )
{
	if ( n <= 1 )
	{
		return 1;
	}

	Matrix ans( 2, vector<ULL>( 2 ) );
	ans[0][0] = 1, ans[0][1] = 1;
	ans[1][0] = 1, ans[1][1] = 0;

	ans = MatrixPow( ans, n - 1 );

	return ans[0][0];
}

int main()
{
	for ( size_t i = 0; i < 10; i++ )
	{
		print( Fibonacci( i ) );
	}
}
