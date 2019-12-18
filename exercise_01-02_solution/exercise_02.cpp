#include <iostream>

int main()
{
    int n;

    // User input
    std::cout << "Enter a positive integer: \n";
    std::cin >> n;

    // Array declaration
    const int numberOfDigits = 50;
    int digits[numberOfDigits]; // It is sort of a waste of memory to use int, 
                                // but in this example it doesn't matter

    // Initialization
    digits[0] = 1; 
       
    for( int i = 1; i < numberOfDigits; i++ )
    {
        digits[i] = 0;
    }

    // Factorial computation
    for( int k = 2; k < n + 1; k++ )
    {
        int carry = 0;

        for( int i = 0; i < numberOfDigits; i++ )
        {
            int oldDigit = digits[i];
            digits[i] = ( k * oldDigit + carry ) % 10;
            carry = ( k * oldDigit + carry ) / 10;
        }
    }

    std::cout << "The factorial of " << n << " is ";

    bool firstDigit = false;

    for( int i = numberOfDigits - 1; i >= 0; i-- )
    {
        if( firstDigit == false && digits[i] != 0 )
        {
            std::cout << digits[i];
            firstDigit = true;
        }
        else if( firstDigit == true )
        {
            std::cout << digits[i];
        }
    }

    std::cout << "." << std::endl;

    return 0;
}
