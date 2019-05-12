#include <iostream>
#include <assert.h>

using namespace std;

//                       

double power1 (double x, int n)
{//              
    assert (n >= 0);
/*                
                                         
*/
    if (n == 0)
        return 1;
    else
    {
        return x * power1(x, n-1);
    }
}

//                                                                                                        
double power2 (double x, int n)
{//              
    assert (n >= 0);
/*                
                                         
*/
    if (n == 0)
        return 1;
    else
    {
        double result = power2(x, n/2);
        if (n%2 == 0)
        {
            return result * result;
        }
        if (n%2 == 1)
        {
            return x * result * result;
        }
    }
}

bool palindrome1 (string text, int i, int j)
{//              
    assert (i >= 0 && j >= 0);
/*                
                                                                                              
*/
    if (i == j)
        return true;
    if (text[i] != text[j])
        return false;
    if (i < j+1)
        return palindrome1(text, i+1, j-1);
}

void convertUpperCase (string& text, int i, int j)
{//              
    assert (i >= 0 && j >= 0);
/*                
                                                        
*/
    for (int n = i; n < j+1; n++)
    {
        if (int(text[n]) > 64 && int(text[n]) < 91)
            text[n] = int(text[n]) + 32;
    }
}

bool palindrome2 (string text, int i, int j)
{//              
    assert (i >= 0 && j >= 0);
/*                
                                                                     
                                                                  
*/
    if (i == j)
        return true;
    convertUpperCase(text, i, j);
    if (text[i] != text[j])
        return false;
    if (i < j+1)
        return palindrome1(text, i+1, j-1);
}

bool palindrome3 (string text, int i, int j)
{//              
    assert (i >= 0 && j >= 0);
/*                
                                                                     
                                                                                                           
*/
    convertUpperCase(text, i, j);
    while (text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' || text[i] == '?' ||
    text[i] == '-' || text[i] == ' ')
        i = i+1;
    while (text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' ||
    text[j] == '-' || text[j] == ' ')
        j = j-1;
    if (i == j)
        return true;
    if (text[i] != text[j])
        return false;
    if (i < j+1)
        return palindrome3(text, i+1, j-1);
}

bool match_chars (string chars, int i, string source, int j)
{//              
    assert (i >= 0 && j >= 0);
/*                
                                                                                      
                       
*/
    if (i == chars.length())
        return true;
    while (chars[i] != source[j])
    {
        j++;
        if (j == source.length())
            return false;
    }
    return match_chars(chars, i+1, source, j);
}

int main()
{
    return 0;
}

