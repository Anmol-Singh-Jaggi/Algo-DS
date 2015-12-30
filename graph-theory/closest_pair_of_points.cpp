#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

#define Square(x) ((x)*(x))

struct Point
{
	int x, y;
};

ostream& operator << ( ostream& out, const Point& point )
{
	out << make_pair( point.x, point.y );
	return out;
}

bool compareX( const Point& point1, const Point& point2 )
{
	return ( point1.x ) < ( point2.x );
}

bool compareY( const Point& point1, const Point& point2 )
{
	return ( point1.y ) < ( point2.y );
}

// A utility function to find the distance between two points
double Distance( const Point& p1, const Point& p2 )
{
	return sqrt( Square( p1.x - p2.x ) + Square( p1.y - p2.y ) );
}

// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted according to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
double StripClosest( const vector<Point>& strip )
{
	double lowest = std::numeric_limits<double>::max();

	// This is a proven fact that this loop runs at most 6 times
	for ( size_t i = 0; i < strip.size(); ++i )
	{
		for ( size_t j = i + 1; j < strip.size() && ( strip[j].y - strip[i].y ) < lowest; ++j )
		{
			auto distance = Distance( strip[i], strip[j] );
			if ( distance < lowest )
			{
				lowest = distance;
			}
		}
	}

	return lowest;
}

// A recursive function to find the smallest distance among every pair of points.
double ClosestPairOfPointsUtil( const vector<Point>& pointsX, const vector<Point>& pointsY )
{
	const size_t& size = pointsX.size();

	assert( size > 0 );
	assert( pointsX.size() == pointsY.size() );

	if ( size == 1 )
	{
		return INT_MAX;
	}

	// If there are 2 points, return the answer directly
	if ( size == 2 )
	{
		return Distance( pointsX[0], pointsX[1] );
	}

	// Find the middle point
	const size_t& mid = size / 2;
	const Point& midPoint = pointsX[mid];

	vector<Point> pointsXLeft, pointsXRight;
	pointsXLeft.insert( pointsXLeft.end(), pointsX.begin(), pointsX.begin() + mid );
	pointsXRight.insert( pointsXRight.end(), pointsX.begin() + mid, pointsX.end() );

	// Divide points in y-sorted array around the vertical line.
	// Assumption: All x coordinates are distinct.

	// y-sorted points on left of vertical line
	vector<Point> pointsYLeft( pointsXLeft.size() );

	// y-sorted points on right of vertical line
	vector<Point> pointsYRight( pointsXRight.size() );

	size_t pointsYLeftIt = 0;
	size_t pointsYRightIt = 0;
	for ( size_t i = 0; i < size; i++ )
	{
		if ( pointsY[i].x <= midPoint.x && pointsYLeftIt < pointsYLeft.size() )
		{
			pointsYLeft[pointsYLeftIt++] = pointsY[i];
		}
		else
		{
			pointsYRight[pointsYRightIt++] = pointsY[i];
		}
	}

	// Calculate the smallest distance on the left and right of middle line
	const double leftSmallest = ClosestPairOfPointsUtil( pointsXLeft, pointsYLeft );
	const double rightSmallest = ClosestPairOfPointsUtil( pointsXRight, pointsYRight );

	// Find the smaller of two distances
	const double lowestDistance = min( leftSmallest, rightSmallest );

	// Build an array strip[] that contains points close (closer than lowerDistance)
	// to the line passing through the middle point
	vector<Point> strip;
	for ( size_t i = 0; i < size; i++ )
	{
		if ( abs( pointsY[i].x - midPoint.x ) < lowestDistance )
		{
			strip.push_back( pointsY[i] );
		}
	}

	// Find the closest points in strip. Return the minimum of lowestDistance and closest distance is strip[]
	return min( lowestDistance, StripClosest( strip ) );
}

// Complexity - O(nlogn), where n is the number of points
double ClosestPairOfPoints( const vector<Point>& points )
{
	assert( points.size() >= 2 );

	// The array of points sorted by x-coordinate
	vector<Point> pointsX = points;
	sort( pointsX.begin(), pointsX.end(), compareX );

	// The array of points sorted by y-coordinate
	vector<Point> pointsY = points;
	sort( pointsY.begin(), pointsY.end(), compareY );

	return ClosestPairOfPointsUtil( pointsX, pointsY );
}

int main()
{
	vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	cout << "The smallest distance is " << ClosestPairOfPoints( points );
}
