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

double* createArray( std::string name, int& size )
{
    std::cout << "Input vector " << name << std::endl;
    std::cout << "    size = ";
    
    std::cin >> size;
    
    double* target = new double[size];
    
    inputVectorElements( target, size, "    " + name );

    return target;
}

void deleteArray( double* array )
{
    delete[] array;
}

int main( )
{
    int option;

    do
    {   
        std::cout << "------ Menu ------\n"
                     "[1] dot product   \n"
                     "[2] euclidean norm\n"
                     "[3] maximum norm  \n"
                     "[4] exit          \n\n";
                    
        std::cout << "Input: ";
        std::cin >> option; 
        std::cout << std::endl;
        
        if( option == 1 )
        {
            int n1, n2;
            
            double* v1 = createArray( "v1", n1 );
            double* v2 = createArray( "v2", n2 );

            if( n1 != n2 )
            {
                std::cout << "\nError: vectors sizes don't match." << "\n" << std::endl;

                continue;
            }
            
            std::cout << "\nDot product is " << dotProduct( v1, v2, n1 ) << "\n" << std::endl;
            
            deleteArray( v1 );
            deleteArray( v2 );
        }
        else if( option == 2 )
        {
            int n1;
            double* v1 = createArray( "v1", n1 );
               
            std::cout << "\nEuclidean norm is " << euclideanNorm( v1, n1 ) << "\n" << std::endl;
            
            deleteArray( v1 );
        }
        else if( option == 3 )
        {
            int n1;
            double* v1 = createArray( "v1", n1 );
               
            std::cout << "\nMaximum norm is " << maximumNorm( v1, n1 ) << "\n" << std::endl;
            
            deleteArray( v1 );
        }
    } 
    while( option != 4 );
    
    return 0;
}
