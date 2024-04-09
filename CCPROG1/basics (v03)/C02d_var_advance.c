#include <stdio.h>

int main(){
    // There are other data types but with different capacities
    // Variables have a limit to how much can be contained
    
    // Whole number variants
    short nShort =  11;
    long nLong =  12345667;
    long long fLongLong = 987654321;
    
    // Decimal variants
    double fDouble = 3.5;
    long double fLongDouble = 987654321.9876;
    
    // How to display these variable types
    printf("%hd\n", nShort);
    printf("%ld\n", nLong);
    printf("%lld\n", fLongLong);
    printf("%lf\n", fDouble);
    printf("%Lf\n", fLongDouble);
    
    return 0;
}

/*
  ( ͡🔥 - ͡🔥)
  These allow bigger capacities and may be useful for certain cases.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_data_types.htm
*/
