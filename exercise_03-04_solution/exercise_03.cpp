#include <iostream>
#include <string>
#include <cmath>

void inputVectorElements( double vector[], int size, std::string name )
{
    for( int i = 0; i < size; ++i )
    {
        std::cout << name << "[" << i << "] = ";
        std::cin >> vector[i];
    }
}

void printVector( double vector[], int size, std::string name )
{
    std::cout << name << " = [";
        
    for( int i = 0; i < size - 1; ++i )
    {
        std::cout << vector[i] << ", ";
    }
    
    if( size != 0 )
    {
      std::cout << vector[size - 1];
    }
    
    std::cout << "]" << std::endl;
}

bool checkSize( int size )
{
    if( size == 0 )
    {
        std::cout << "Warning: Vector has size zero." << std::endl;
    }
    
    return size == 0;
}

double dotProduct( double vector1[], double vector2[], int size )
{
    if( checkSize( size ) )
    {
        return 0.0;
    }

    double result = 0.0;
    
    for( int i = 0; i < size; ++i )
    {
      result += vector1[i] * vector2[i];
    }
    
    return result;
}

double euclideanNorm( double vector[], int size )
{
    return std::sqrt( dotProduct( vector, vector, size ) );
}

double maximumNorm( double vector[], int size )
{
    if( checkSize( size ) )
    {
        return 0.0;
    }
    
    double maximumValue = std::abs( vector[0] );
    
    for( int i = 0; i < size; ++i )
    {
        int absValue = std::abs( vector[i] );
        
        if( absValue > maximumValue )
        {
            maximumValue = absValue;
        }
    }
    
    return maximumValue;
}


int main( )
{
    const int n = 2;
   
    double a[n];
    double b[n];
    
    inputVectorElements( a, n, "a" );
    inputVectorElements( b, n, "b" );
    
    std::cout << std::endl;
    
    printVector( a, n, "a" );
    printVector( b, n, "b" );
    
    std::cout << std::endl;
    
    std::cout << "a * b = " << dotProduct( a, b, n ) << "\n\n";
    
    std::cout << "|| a ||_euc = " << euclideanNorm( a, n ) << "\n";
    std::cout << "|| b ||_euc = " << euclideanNorm( b, n ) << "\n\n";
    
    std::cout << "|| a ||_max = " << maximumNorm( a, n ) << "\n";
    std::cout << "|| b ||_max = " << maximumNorm( b, n ) << "\n";
    
    return 0;  
}
