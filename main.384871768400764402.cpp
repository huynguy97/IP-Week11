#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/*                                           
                       
                         
                                           */

int power(double x, int n)
{
//                
    assert(n >= 0);
/*                 
                                      
*/
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n-1);
    }
}

int power2(double x, int n)
{
//                
    assert(n >= 0);
/*                 
                                                                            
*/
    if(n == 0)
    {
        return 1;
    }
    else
    {
        if (n == 1)
        {
            return x;
        }
        else
        {
            if (n % 2 == 0)
            {
                return power(power(x, n/2), 2);
            }
            else
            {
                return x * power(power(x, n/2), 2);
            }
        }
    }
}
//                            

bool palindrome1 (string text, int i, int j)
{//               
    assert (i >= 0 && j >= 0 && i < text.length() && j < text.length());
/*                 
                                                                                
                                          
*/
    if (i >= j)
    {
        return true;
    }
    else
    {
        if (text[i] != text[j])
        {
            return false;
        }
        else
        {
            return palindrome1(text, i+1, j-1);
        }
    }
}

bool palindrome2 (string text, int i, int j)
{//               
    assert (i >= 0 && j >= 0 && i < text.length() && j < text.length());
/*                 
                                                                                
                                                                              
                        
*/
    if (i >= j)
    {
        return true;
    }
    else
    {
        if (tolower(text[i]) != tolower(text[j]))
        {
            return false;
        }
        else
        {
            return palindrome2(text, i+1, j-1);
        }
    }
}

bool palindrome3 (string text, int i, int j)
{//               
    assert (i >= 0 && j >= 0 && i < text.length() && j < text.length());
/*                 
                                                                                
                                                                              
                                                                     
*/
    while (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == '-')
    {
        i++;
    }
    while (text[j] == ' ' || text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-')
    {
        j--;
    }
    if (i >= j)
    {
        return true;
    }
    else
    {
        if (tolower(text[i]) != tolower(text[j]))
        {
            return false;
        }
        else
        {
            return palindrome3(text, i+1, j-1);
        }
    }
}

bool match_chars(string chars, int i, string source, int j)
{//               
    assert (i >= 0 && i <= chars.length() && j >= 0 && j <= source.length());
/*
                  
                                                                           
                                                                              
             
*/
    if (i == chars.length())
    {
        return true;
    }
    else if (j == source.length())
    {
        return false;
    }
    else if (chars[i] == source[j])
    {
        return match_chars(chars, i+1, source, j+1);
    }
    else
    {
        return match_chars(chars, i, source, j+1);
    }
}

int main()
{
    cout << palindrome3("Eevee", 0, 4) << endl;
    return 0;
}

