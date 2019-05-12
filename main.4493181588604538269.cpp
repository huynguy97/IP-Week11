#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

//                          
//                      

bool valid_ascii (char c)
{
    //               
    assert ( true ) ;
    //                
    //                                                                          
    //                         
    if (c >= 65 && c <= 90)
    {
        return true ;
    }
    if (c >= 97 && c <= 122)
    {
        return true ;
    }
    return false ;
}

int power (double x, int n)
{
    //                
    assert ( n >= 0 ) ;
    //                 
    //                    
    //                                  
    if (n > 0)
    {
        return (x * power(x, n - 1)) ;
    }
    return 1 ;
}

int betterpower (double x, int n)
{
    //                
    assert ( n >= 0 ) ;
    //                 
    //                                                                                              
    //                                                                            
    //                     
    if (n % 2 == 0)
    {
        return (betterpower(x, n/2) * betterpower(x, n/2)) ;
    }
    else if (n % 2 != 0)
    {
        return (x * betterpower(x, n-1)) ;
    }
    return 1 ;
}

bool palindrome1 (string text, int i, int j)
{
    //               
    assert ( text.length() >= i && text.length() >= j && i >= 0 && j>= 0 ) ;
    //                
    //                                                              
    if (text[i] != text[j])
    {
        return false ;
    }
    else if (i >= j)
    {
        return true ;
    }
    return palindrome1(text, ++i, --j) ;
}

bool palindrome2 (string text, int i, int j)
{
    //                
    assert ( text.length() >= i && text.length() >= j && i >= 0 && j>= 0 ) ;
    //                 
    //                                                                                                
    char a = text[i] ;
    char b = text[j] ;
    if ( j <= i )
    {
        return true ;
    }
    else if (text[i] != text[j] && abs(a-b) != 32)
    {
        return false ;
    }
    return palindrome2(text, ++i, --j) ;
}

bool palindrome3 (string text, int i, int j)
{
    //               
    assert ( text.length() >= i && text.length() >= j && i >= 0 && j>= 0 ) ;
    //                
    //                                                                                                                        
    char a = text[i] ;
    char b = text[j] ;
    while (!valid_ascii(a))
    {
        i++ ;
        a = text[i] ;
    }
    while (!valid_ascii(b))
    {
        j-- ;
        b = text[j] ;
    }
    if ( j <= i )
    {
        return true ;
    }
    else if (text[i] != text[j] && abs(a-b) != 32)
    {
        return false ;
    }
    return palindrome3(text, ++i, --j) ;
}

bool match_chars (string chars, int i, string source, int j)
{
    //               
    assert ( i <= chars.length() && j <= source.length() && i >= 0 && j >= 0 ) ;
    //                
    //                                                                                       
    //                                                                                               
    if (chars[i] != source[j])
    {
        if (j == source.length()-1)
        {
            return false ;
        }
        return match_chars(chars, i, source, ++j) ;
    }
    if (chars[i] == source[j] && i == chars.length()-1)
    {
        return true ;
    }
    return match_chars(chars, ++i, source, j) ;
}

int main()
{
    return 0;
}

