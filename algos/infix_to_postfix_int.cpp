#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(nullptr)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;

/*

RULES -:

1. Print operands as they arrive.
2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
3. If the incoming symbol is a left parenthesis, push it on the stack.
4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
7. If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
8. At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)

*/

static const int ADD_PRECEDENCE = -1000000000;
static const int SUBTRACT_PRECEDENCE = ADD_PRECEDENCE;
static const int MULTIPLY_PRECEDENCE = ADD_PRECEDENCE + 1;
static const int DIVIDE_PRECEDENCE = MULTIPLY_PRECEDENCE;

static const int ADD = -2000000000;
static const int SUBTRACT = ADD + 1;
static const int MULTIPLY = SUBTRACT + 1;
static const int DIVIDE = MULTIPLY + 1;
static const int LEFT_BRACKET = DIVIDE + 1;
static const int RIGHT_BRACKET = LEFT_BRACKET + 1;

bool IsOperator( const int& item )
{
	static const set<int> operators = {ADD, SUBTRACT, MULTIPLY, DIVIDE};
	return operators.find( item ) != operators.end();
}

bool IsOperand( const int& item )
{
	return item >= 0;
}

int precedence( const int& op )
{
	if ( op == ADD )
	{
		return ADD_PRECEDENCE;
	}
	if ( op == SUBTRACT )
	{
		return SUBTRACT_PRECEDENCE;
	}
	if ( op == MULTIPLY )
	{
		return MULTIPLY_PRECEDENCE;
	}
	if ( op == DIVIDE )
	{
		return DIVIDE_PRECEDENCE;
	}

	const string errorMsg = "Error : Unrecognized operator - '" + ToString( op ) + "'\n";
	throw runtime_error( errorMsg );
}

// The input operands should be positive integers
vector<int> InfixToPostfix( const vector<int>& infix )
{
	vector<int> postfix;
	stack<int> myStack;

	for ( size_t i = 0; i < infix.size(); i++ )
	{
		// Print operands as they arrive.
		if ( IsOperand( infix[i] ) )
		{
			postfix.push_back( infix[i] );
		}
		// If the incoming symbol is a left parenthesis, push it on the stack.
		else if ( infix[i] == LEFT_BRACKET )
		{
			myStack.push( LEFT_BRACKET );
		}
		// If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis.
		// Discard the pair of parentheses.
		else if ( infix[i] == RIGHT_BRACKET )
		{
			while ( !myStack.empty() && myStack.top() != LEFT_BRACKET )
			{
				postfix.push_back( myStack.top() );
				myStack.pop();
			}

			if ( !myStack.empty() )
			{
				myStack.pop();
			}
			else
			{
				const string errorMsg = "Error : No '(' found for corresponding ')'\n";
				throw runtime_error( errorMsg );
			}
		}
		else if ( IsOperator( infix[i] ) )
		{
			if ( myStack.empty() || myStack.top() == LEFT_BRACKET )
			{
				myStack.push( infix[i] );
			}
			else
			{
				const int stackTop = myStack.top();
				const size_t precCurrent = precedence( infix[i] );
				const size_t precTop = precedence( stackTop );

				// If the incoming operator has higher precedence than the top of the stack,
				// push it on the stack.
				if ( precCurrent > precTop )
				{
					myStack.push( infix[i] );
				}
				// If the incoming symbol has lower precedence than the symbol on the top of the stack,
				// pop the stack and print the top operator.
				// Then test the incoming operator against the new top of stack.
				else if ( precCurrent < precTop )
				{
					myStack.pop();
					postfix.push_back( stackTop );
					i--;
				}
				// If the incoming symbol has equal precedence with the top of the stack, use association.
				// If the association is left to right, pop and print the top of the stack and then push the incoming operator.
				// If the association is right to left, push the incoming operator.
				else
				{
					myStack.pop();
					postfix.push_back( stackTop );
					myStack.push( infix[i] );
				}
			}
		}
		else
		{
			const string errorMsg = "Error : Unrecognized symbol - '" + ToString( infix[i] ) + "'\n";
			throw runtime_error( errorMsg );
		}
	}

	// At the end of the expression, pop and print all operators on the stack.
	// No parentheses should remain.
	while ( !myStack.empty() )
	{
		const int stackTop = myStack.top();
		myStack.pop();

		assert( IsOperator( stackTop ) );

		postfix.push_back( stackTop );
	}

	return postfix;
}

int main()
{
	vector<int> infix = {LEFT_BRACKET, 100, ADD, 50, RIGHT_BRACKET, MULTIPLY, 200};
	cout << InfixToPostfix( infix );
}

