//                             
//                          

#include <iostream>
#include <cassert>

using namespace std;

double power (double x, double n)
{
    //             
    assert (n >= 0);
    //                                                  
    if ( n == 0.0)
        return 1.0;
    else
    {
        int z = x*power(x, n-1);
        return z;
    }
}

int efficient_power(int x, int n)
{
    //             
    assert(n >= 0);
    //                                                                   
    if (n == 0)
    {
        return 1;
    }

    if (n%2 == 0)
    {
        x = efficient_power(x , n/2);
        x = x*x;
    }

    else
        if (n%2 != 0)
        {
            x = x*efficient_power(x, n-1);
        }
    return x;
}

//                                
//
//                                                   
//              

bool palindrome1(string text, int i, int j)
{
    //             
        assert(i < j);
    //                                                                                
    if (i == j || i > j)
        return true;
    if (text[i] != text[j])
        return false;
    else if (text[i] == text[j])
    {
        return palindrome1(text, i+1, j-1);
    }
}

bool palindrome2(string text, int i, int j)
{
    //             
        assert(i < j && i >= 0 && i >= 0);
    //                                                                                                       
    if (i == j || i > j)
        return true;
    if (tolower(text[i]) != tolower(text[j]))
        return false;
    else
        if (tolower(text[i]) == tolower(text[j]))
        {
            return palindrome2(text, i+1, j-1);
        }
}

bool palindrome3(string text, int i, int j)
{
    //             
    assert (i < j && j >= 0 && i >= 0);
    //                                                                                                                                                
    if (i == j || i > j)
        return true;

    if (!isalpha(text[i]))
            return palindrome3(text, i+1, j);
    if (!isalpha(text[j]))
            return palindrome3(text, i, j-1);
    if (tolower(text[i] != tolower(text[j])))
        return false;

    else
    {
        if (tolower(text[i]) == tolower(text[j]))
        return palindrome3(text, i+1, j-1);
    }
}

bool match_chars (string chars, int i, string source, int j)
{//             
   assert(i >= 0);
//                                                                                                              
    if (i > chars.length()-1)
        return true;
    if (chars[i] != source[j])
        return match_chars(chars, i, source, j+1);
    if (j > source.length()-1)
        return false;
    if (chars[i] == source [j])
        return (match_chars(chars, i+1, source, j));
}

int main()
{

    cout << ""

    return 0;
}

