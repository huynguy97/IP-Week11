#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

/*                                                             
*/

double naive_power (double x, int n)
{
//               
    assert (n >= 0) ;
//                
//                                           
    if (n == 0)
    {
        return 1 ;
    }
    else
    {
        return x*naive_power(x,n-1) ;
    }

}

double efficient_power (double x, int n)
{
//               
    assert (n >= 0) ;
//                
//                                           
    if (n == 0)
        return 1 ;
    if (n % 2 == 0)
        return efficient_power(x,n/2)*efficient_power(x,n/2) ;
    else
        return x*efficient_power(x,n/2)*efficient_power(x,n/2) ;
    //                                 
}

bool palindrome1 (string text, int i, int j)
{
//               
    assert (true) ;
//                
//                                                                                                           
//                                                      
    if (i >= j)
        return true ;
    else if (text[i] == text[j])
        return palindrome1(text, i+1, j-1);
    else
        return false;
}

bool palindrome2 (string text, int i, int j)
{
//               
    assert (true) ;
//                
//                                                                                                           
//                                                      
    if (i >= j)
        return true ;
    else if (toupper(text[i]) == toupper(text[j]))
        return palindrome2(text, i+1, j-1);
    else
        return false;
}

bool palindrome3 (string text, int i, int j)
{
//               
    assert (true) ;
//                
//                                                                                                           
//                                                      
    if (i >= j)
        return true ;
    while (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == '-')
        i = i+1 ;
    while (text[j] == ' ' || text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-')
        j = j-1 ;
    if (toupper(text[i]) == toupper(text[j]))
        return palindrome3(text, i+1, j-1);
    else
        return false;
}

bool match_chars (string chars, int i, string source, int j)
{
//               
    assert (true);
//                
//                                                                    
//                                                                    
    while (j <= source.length())
    {
        if (chars[i] == source[j])
            return match_chars(chars, i+1, source, j) ;
        else
            j = j+1 ;
    }
    if (i > chars.length())
        return true ;
    else return false ;
}

int main()
{
    //                                    
    if (match_chars("abc",0,"It is a classy bag.",0))
        cout << "true" ;
    else
        cout << "false" ;
}

