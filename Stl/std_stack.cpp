#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

double evaluateRPN( std::string_view expression )
{
    std::stack<double, std::vector<double>>
        s; // Use vector as the underlying container for the stack to avoid reallocations
    std::istringstream iss( expression.data() );
    std::string token;

    while( iss >> token )
    {
        if( std::all_of( std::begin( token ), std::end( token ), ::isdigit ) )
        {
            s.push( std::stod( token ) );
        }
        else
        {
            if( s.size() < 2 )
            {
                throw std::runtime_error( "Invalid RPN expression: not enough operands" );
            }
            double y = s.top();
            s.pop();
            double x = s.top();
            s.pop();
            switch( token[0] )
            {
                case '+': s.push( x + y ); break;
                case '-': s.push( x - y ); break;
                case '*': s.push( x * y ); break;
                case '/':
                    if( y == 0 )
                    {
                        std::cerr << "Division by zero\n";
                        return 0;
                    }
                    s.push( x / y );
                    break;
            }
        }
    }

    if( s.size() != 1 )
    {
        std::cerr << "Invalid RPN expression\n";
        return 0;
    }

    return s.top();
}

int main()
{
    std::string_view expression{ "46 2 3 + * 2 /" };
    std::string_view expression2{ "5 1 2 + 4 * + 3 -" };
    std::string_view expression3{ "3 4 5 * -" };
    try
    {
        // Evaluate the RPN expressions
        auto start1 = std::chrono::high_resolution_clock::now();
        std::cout << "46 2 3 + * 2 / = " << evaluateRPN( expression ) << '\n';
        std::cout << "5 1 2 + 4 * + 3 - = " << evaluateRPN( expression2 ) << '\n';
        std::cout << "3 4 5 * - = " << evaluateRPN( expression3 ) << '\n';
        auto end1                              = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed1 = end1 - start1;
        std::cout << "Time taken: " << elapsed1.count() << "s\n";
    }
    catch( const std::exception & e )
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return 0;
}