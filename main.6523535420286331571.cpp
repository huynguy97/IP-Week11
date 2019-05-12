/*
                
                             
                         
 */
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//         
double power(double x, int n)
{
    //     
    assert(n >= 0);
    //                                    
    //                                               
    if(n == 0)
        return 1;
    else
        return(x * power(x, n - 1));
}

//         
double power2 (double x, int n)
{
    //     
    assert (n >= 0);
    //                                                                               
    //                                                                                                         
    //                                                   
    if (n == 0)
        return 1;
    if ((n % 2) == 0 && (n != 2))
        return power2(power2(x,n/2),2) ;

    return x*power2(x,n-1);
}

//         
bool palindrome1 (string text, int i , int j)
{
    //     
    assert(text.length() > 0);
    //                                                                    
    if(text[i] == text[j] && (i == j + 1 || i == j))
        return true;
    if(text[i] != text[j])
        return false;
    return palindrome1(text, i + 1, j - 1);
}

//         
bool palindrome2(string text, int i, int j)
{
    //     
    assert(text.length() > 0);
    //                                                                                                                
    //                           
    if((text[i] == text[j]) || (text[i] + 32 == text[j]) || (text[i] - 32 == text[j]))
    {
        if((i == j + 1) || (i == j))
            return true;
        return palindrome2(text, i + 1, j - 1);
    }
    else
        return false;
}

//         
bool palindrome3 (string text, int i, int j)
{
    //    
    assert(text.length() > 0);
    //                                                                                       
    //                                       
    //                                              
    if (text[i] < 65)
        return palindrome3(text, i + 1, j);

    if (text[j] < 65)
        return palindrome3(text, i, j - 1);

    if ((text[i] == text[j]) || (text[i] == (text[j] + 32)) || (text[i] == (text[j] - 32)))
    {
        if((i == j + 1)|| i == j)
            return true;
        else
            return palindrome3(text, i + 1, j - 1);
    }
    else
        return false;
}

//       
bool match_chars(string chars, int i, string source, int j) {
    //     
    assert(chars.length() > 0 && source.length() >= chars.length());
    //                                                                       
    //                                                                  
    //                       
    if(i == chars.length())
        return true;
    if(j == source.length())//                         
        return false;
    if(chars[i] == source[j])
        return(match_chars(chars, i + 1, source, j + 1));
    else
        return(match_chars(chars, i, source, j + 1));
}

int main()
{
    int i = 0;
    int j = 4;
    double x = 4;
    int n = 5;
    string source = "otto";
    string chars = "abc";

    /*                                    
                       
        
                       */

    return 0;
}

