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


bool IsOperator( const char& c )
{
	static const set<char> operators = {'+', '-', '*', '/'};
	return operators.find( c ) != operators.end();
}

bool IsOperand( const char& c )
{
	return isalpha( c );
}

size_t precedence( const char& op )
{
	static const map<char, size_t> precMapping =
	{
		{
			'+', 1
		},
		{
			'-', 1
		},
		{
			'*', 2
		},
		{
			'/', 2
		}
	};

	if ( precMapping.find( op ) == precMapping.end() )
	{
		const string errorMsg = "Error : Unrecognized operator - '" + ToString( op ) + "'\n";
		throw runtime_error( errorMsg );
	}

	return precMapping.at( op );
}

string InfixToPostfix( const string& infix )
{
	string postfix;
	stack<char> myStack;

	for ( size_t i = 0; i < infix.size(); i++ )
	{
		if ( isspace( infix[i] ) )
		{
			continue;
		}
		// Print operands as they arrive.
		else if ( IsOperand( infix[i] ) )
		{
			postfix += infix[i];
		}
		// If the incoming symbol is a left parenthesis, push it on the stack.
		else if ( infix[i] == '(' )
		{
			myStack.push( '(' );
		}
		// If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis.
		// Discard the pair of parentheses.
		else if ( infix[i] == ')' )
		{
			while ( !myStack.empty() && myStack.top() != '(' )
			{
				postfix += myStack.top();
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
			if ( myStack.empty() || myStack.top() == '(' )
			{
				myStack.push( infix[i] );
			}
			else
			{
				const char stackTop = myStack.top();
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
					postfix += stackTop;
					i--;
				}
				// If the incoming symbol has equal precedence with the top of the stack, use association.
				// If the association is left to right, pop and print the top of the stack and then push the incoming operator.
				// If the association is right to left, push the incoming operator.
				else
				{
					myStack.pop();
					postfix += stackTop;
					myStack.push( infix[i] );
				}
			}
		}
		else
		{
			const string errorMsg = "Error : Unrecognized character - '" + ToString( infix[i] ) + "'\n";
			throw runtime_error( errorMsg );
		}
	}

	// At the end of the expression, pop and print all operators on the stack.
	// No parentheses should remain.
	while ( !myStack.empty() )
	{
		const char stackTop = myStack.top();
		myStack.pop();

		assert( IsOperator( stackTop ) );

		postfix += stackTop;
	}

	return postfix;
}

int main()
{
	string infix = "A * ((B + C * D)) + E";
	print( InfixToPostfix( infix ) );
}

