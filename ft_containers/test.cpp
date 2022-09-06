#include <iostream>
#include <string>

#include <iterator>
#include <vector>

// #include "utils/iterator.hpp"
// #include "utils/iterator_traits.hpp"
// #include "utils/type_traits.hpp"


#include <algorithm>

#include<iostream>
#include<algorithm> // for lexicographical_compare()
using namespace std;
  
// helper function to convert all into lower case:
bool comp (char s1, char s2)
{
    return tolower(s1)<tolower(s2);
}
  
int main()
{
    // initializing char arrays
    char one[] = "Fgeksforgeeks";
    char two[] = "Gfg";
      
    // using lexicographical_compare for checking 
    // is "one" is less than "two"
    // returns false as "g" has larger ASCII value than "G"
    if( lexicographical_compare(one, one+13, two, two+3))
    {
        cout << "geeksforgeeks is lexicographically less than Gfg\n";
          
    }
    else
    {
        cout << "geeksforgeeks is not lexicographically less than Gfg\n";
          
    }
      
    // using lexicographical_compare for checking 
    // is "one" is less than "two"
    // returns true this time as all converted into lowercase
    if( lexicographical_compare(one, one+13, two, two+3, comp))
    {
        cout << "geeksforgeeks is lexicographically less  ";
        cout << "than Gfg( case-insensitive )";
          
    }
    else
    {
        cout << "geeksforgeeks is not lexicographically less ";
        cout<< "than Gfg( case-insensitive )";
          
    }
      
}


