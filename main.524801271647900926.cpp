#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

//                                              
//                                                   

double power(double x, int n)
{   //             
    assert( n >= 0 );
    /*              
                                       
    */

    if(n == 0)
        return 1;
    if(n > 0)
        return x*power(x, n-1);
}

double power2(double x, int n)
{   //             
    assert( n >= 0 );
    /*              
                                       
    */
    if(n == 0)
        return 1;
    if(n > 0)
        return (x*power(x, n-1))*(x*power2(x, n-1));
}

double power3(double x, int n)
{   //             
    assert( n >= 0 );
    /*              
                                                                 
    */
    n = n/2;
    return power2(x,n);
}

bool palindrome1(string text, int i, int j)
{   //             
    assert( i >= 0 && j >= 0);
    /*              
                                                                                                             
    */

    if(i > j)
        return true;
    if(text[i] == text[j])
        return palindrome1(text, i+1, j-1);
    else
        return false;
}

bool palindrome2(string text, int i, int j)
{   //             
    assert( i >= 0 && j >= 0);
    /*              
                                                                                                              
                                                     
    */

    if(i > j)
        return true;
    if(tolower(text[i]) == tolower(text[j]))
        return palindrome1(text, i+1, j-1);
    else
        return false;

}

bool palindrome3(string text, int i, int j)
{    //             
    assert( i >= 0 && j >= 0);
    /*              
                                                                                                              
                                                                                               
    */
    while(text[i] == ' '  || text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' ||  text[i] == '?' || text[i] == '-')
    {
        i++;
        if(i > j)
            return true;
    }
    while(text[j] == ' ' || text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-')
    {
        j--;
        if(i > j)
            return true;
    }

    if(i > j)
        return true;
    if(tolower(text[i]) == tolower(text[j]))
        return palindrome3(text, i+1, j-1);
    else
        return false;

}

bool match_chars(string chars, int i, string source, int j)
{   //             
    assert( i >= 0 && j >= 0 );
    /*              
                                                                                                                     
    */

    if(i > chars.length()-1)
        return true;

    while(chars[i] != source[j])
    {
        j++;
        if(j > source.length()-1)
            return false;
    }

    if(chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    }

int main()
{
    return 0;
}

