#include <iostream>
#include <cmath>

int main ( )
{    
    int numberOfBytes = sizeof( int );
    int maximumValue = std::pow( 2, numberOfBytes * 8 - 1 ) - 1;
       
    int number;
    
    std::cout << "Input integer number in [" << -maximumValue << ", " << maximumValue << "]: ";
    std::cin >> number;

    if( !std::cin ) // 1)
    {
        std::cout << "Error in input detected!" << std::endl;
        
        return 0;
    }
    
    int sign = number < 0;

    std::cout << "Bitwise representation is";
    
    for( int j = numberOfBytes; j > 0; --j ) 
    {
        std::cout << " ";
        
        for( int i = 0; i < 8 - ( j == 1 ); ++i )
        {
            int bit = number % 2 != 0; // 2)
            
            std::cout << bit;

            number = number / 2;
        }
    }
    
    std::cout << sign << std::endl;

    if( number != 0 ) // 3)
    {
        std::cout << "Warning: Overflow in algorithm!" << std::endl;
    }

    return 0;
}

// 1) Convert std::cin to a boolean value indicating if std::cin is ready for in-
//    put and no errors occured. Negating that indicated that there was an error.
//
// 2) number % 2 gives the remainder of the integer division number / 2. We want
//    to output 1 if the remainder is != 0 and 0 if it is == 0. Therefore, we use
//    a comparison operator giving us true in case we have a remainder and false 
//    if not. This boolean value we convert to an integer by declaring a new int 
//    variable and assigning it the result of this comparison.
//
// 3) If number is declared as int and numberOfBytes is sizeof( int ), then num-
//    ber should always be zero. However, depending on the storage scheme the in-
//    put -maximumValue - 1 might be valid but cause an overflow in the algorithm.  
