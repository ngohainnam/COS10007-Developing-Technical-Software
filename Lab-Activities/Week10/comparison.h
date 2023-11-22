// or template< typename T 
template < class T >
T maximum( T value1, T value2)
{
    T maximumValue = value1; // assume value1 is maximum

    // determine whether value2 is greater than maximumValue
    if ( value2 > maximumValue )
    maximumValue = value2;

    return maximumValue;
} // end function template maximum

template < class T >
T minimum( T value1, T value2)
{
    T minimumValue = value1; // assume value1 is minimum
    // determine whether value2 is less than minimumValue
    if ( value2 < minimumValue )
    minimumValue = value2;

    return minimumValue;
}