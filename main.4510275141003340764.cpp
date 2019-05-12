#include <iostream>
#include <cassert>
using namespace std;
//                                                  

double power ( double x, int n )
{
//               
assert ( n >= 0 );
//                                          
    if ( n == 0 )
    {
        return 1 ;
    }
    else if (n%2 != 0)
    {
        return x * power ( x, n -1 ) ;
    }
    else
    {
        double y = power ( x, n/2 ) ;
        return y * y ;
    }
}

bool palindrome1 ( string text, int i, int j )
{
//               
assert ( i >= 0 );
//                                                                   
    if ( j <= i )
        return true ;
        if ( text[i] != text[j] )
        {
            return false ;
        }
        else
        {
            return palindrome1 ( text, i+1, j-1 ) ;
        }
}

bool palindrome2 ( string text, int i, int j)
{
//               
assert ( i >= 0 );
//                                                                    
//                              
    if ( j <= i )
        return true ;
        if ( tolower(text[i]) != tolower(text[j]) )
        {
            return false ;
        }
        else
        {
            return palindrome2 ( text, i+1, j-1 ) ;
        }
}

bool palindrome3 ( string text, int i, int j)
{
//               
assert ( i >= 0 );
//                                                                    
//                                              
    if ( j <= i )
        return true ;
    int A = int(tolower(text[i]));
    int B = int(tolower(text[j]));
    if ( A < 97 || A > 122 )
        return palindrome3(text, i+1, j);
    if ( B < 97 || B > 122 )
        return palindrome3(text, i, j-1);
    if ( tolower(text[i]) != tolower(text[j]) )
        {
            return false ;
        }
    else
        {
            return palindrome3 ( text, i+1, j-1 ) ;
        }
}

bool match_chars ( string chars, int i, string source, int j )
{
//               
assert ( i >= 0 && j >= 0 );
//                                                                        
//                                                
if ( i == chars.length() )
    return true ;
if ( i != chars.length() && j == source.length()-1)
    return false ;
    if ( chars[i] == source[j] )
    {
        return match_chars(chars, i+1, source, j);
    }
    else if ( chars[i] != source[j] )
    {
        return match_chars(chars, i, source, j+1);
    }
}

int main()
{
    cout << power(2.5, 3) << endl ;
    cout << palindrome1 ("otto", 0, 3) << endl;
    cout << palindrome2 ("Otto", 0, 3) << endl;
    cout << palindrome3 ("Madam, I'm Adam.", 0, 15) << endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars ("abc", 0, "It is a classy bag", 0) << endl ;
}

