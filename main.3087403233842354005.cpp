#define NDEBUG

#include <string>
#include <iostream>
#include <assert.h>.

using namespace std;

int power (double x, int n)
{
    //              
    assert (n >= 0);
    /*                
                              
    */
    if (n <= 0)
        return 1;
    else
    {
         return x * power(x, n-1);
    }
}

int smart_power (double x, int n)
{
    //             
    assert (n >= 0);
    /*                
                                                      
    */
    if (n <= 0)
        return 1;
    else
    {
         if (n%2)
         {
             return x * smart_power(x, n-1);
         }
         else
        {
            int k = n/2;
            double HELP = smart_power(x, k); //                             
            return (HELP * HELP);
        }
    }
}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert (text.length() > 0);
    /*               
                                           
    */
    if (text [i] != text [j])
        return false;
    else
        palindrome1 (text, i+1, j-1);
    return true;
}

bool palindrome2 (string text, int i, int j)
{
    //              
    assert (text.length() > 0);
    /*                
                                                                                            
    */
    if (text [i] != text [j] && text [i] + 32 != text [j] && text [i] != text [j] +32)
        return false;
    else
        palindrome2(text, i+1, j-1);
    return true;
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert (text.length() > 0);
    /*                
                                                                                                                             
    */
    for (int k = 0, len = text.size(); k < len; k++) //                                                                                              
    {
        if (ispunct(text[k]))
        {
            text.erase(k--, 1);
            len = text.size();
        }
    }
    char c [2];
    text [i] >> c [0];
    text [j] >> c [1];
    if (c [0] != c [1] && c [0] + 32 != c [1] && c [0] != c [1] +32)
        return false;
    else
        palindrome3(text, i+1, j-1);
    return true;
}

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert (chars.length() > 0 && source.length() > 0);
    /*                
                                                                                 
    */
    for (j <= source.length()-1 ; j++) //                                         
    {
        if (chars[i] == source [j])
        {
            match_chars(chars, i+1, source, j+1);
            return true;
        }
    }
    return false;
}

int main ()
{
    cout << power(3.0,3) <<endl;
    cout << smart_power(2.0,11) <<endl;
    cout << palindrome3("Le.pel",0,4) <<endl;
    cout << match_chars("abc",0,"abc",0) <<endl;
    return 0;
}

