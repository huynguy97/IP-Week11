#include <iostream>
#include <cassert>
#include <string>

using namespace std;

double y;

double naive_power(double x, int n)
{
    assert(n>=0);
//                                                    
    if(n==0)
    {
        return 1;
    }
    else
    {
        return x*naive_power(x,n-1);
    }
}

double power(double x, int n)
{
    assert(n>=0);
//                                                    
    if(n==0)
    {
        return 1;
    }
    else if(n%2 == 0)
    {
        y = power(x,n/2);
        return y*y;
    }
    else
    {
        return x*naive_power(x, n-1);
    }
}

bool palindrome1 (string text, int i, int j)
{
    assert(i >= 0 && j < text.size());
    //                                                                                 
    if(i >= j)
    {
        return true;
    }
    else if( text[i] == text[j])
    {
        return palindrome1(text,i+1,j-1);
    }
    return false;
}

bool palindrome2 (string text, int i, int j)
{
    assert(i >= 0 && j < text.size());
    //                                                                                 
    if(i >= j)
    {
        return true;
    }
    else if(tolower(text[i]) == tolower(text[j]))
    {
        return palindrome2(text,i+1,j-1);
    }
    return false;
}

bool palindrome3 (string text, int i, int j)
{
    assert(i >= 0 && j < text.size());
    //                                                                                 
    if(i >= j)
    {
        return true;
    }
    else if(ispunct(text[i])|| text[i] == ' ')
    {
        return palindrome3(text,i+1,j);
    }
    else if(ispunct(text[j]) || text[j] == ' ')
    {
        return palindrome3(text,i,j-1);
    }
    else if(tolower(text[i]) == tolower(text[j]))
    {
        return palindrome3(text,i+1,j-1);
    }
    else
    {
        return false;
    }
}

bool match_chars(string chars, int i, string source, int j)
{
    assert( i>=0 && j>=0 );
    //                                                                                                            
    //                                                                        
    if(i == chars.length())
    {
        return true;
    }
    else if(j == source.length())
    {
        return false;
    }
    else if(chars[i] == source[j])
    {
        return match_chars(chars, i+1, source, j);
    }
    else
    {
        return match_chars(chars, i, source, j+1);
    }
}

/*                                                                 */
int main()
{
    cout << naive_power(2.2,640) << endl;
    cout << power(2.2,640) << endl << endl;
    cout << palindrome1("otto",0,3) << endl;
    cout << palindrome1("Otto",0,3) << endl;
    cout << palindrome1("Madam, I'm Adam.",0,15) << endl << endl;
    cout << palindrome2("otto",0,3) << endl;
    cout << palindrome2("Otto",0,3) << endl;
    cout << palindrome2("Madam, I'm Adam.",0,15) << endl << endl;
    cout << palindrome3("otto",0,3) << endl;
    cout << palindrome3("Otto",0,3) << endl;
    cout << palindrome3("Madam, I'm Adam.",0,15) << endl << endl;
    cout << match_chars("abc", 0,"It is a bag of cards",0) << endl;
    cout << match_chars("abc", 0,"It is a bag of books",0) << endl;
    cout << match_chars("abc", 0,"It is a classy bag",0) << endl;
    return 0;
}

