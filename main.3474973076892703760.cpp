#include <iostream>
#include <cassert>

using namespace std;

double naive_power (double x, int exp)
{
    assert (exp >= 0);
    //                            
    if (exp == 0)
        return 1;
    else
        return (x * naive_power(x, exp-1));
}

double efficient_power (double x, int exp)
{
    assert (exp >= 0);
    //                            
    if (exp == 0)
        return 1;
    else if (exp%2 == 0)
        {
            int x = efficient_power(x, exp/2);
            return (x * x);
        }
    else
        return (x * efficient_power(x, exp-1));
}
//                      

bool palindrome1 (string s, int i, int j)
{
    assert (i>=0 && i<=j && j<s.length());
    //                                               
    if (s[i] != s[j])
        return false;
    else if (j-1 > i)
        return (palindrome1 (s, i+1, j-1));
    else
        return true;
}

bool palindrome2 (string s, int i, int j)
{
    assert (i>=0 && i<=j && j<s.length());
    //                                                                   
    if (s[i] == s[j] ||
        (s[i] >= 65 && s[i] <= 90 && s[i]+32 == s[j]) ||
        (s[i] >= 97 && s[i] <= 122 && s[i]-32 == s[j]))
        if (j-1 > i)
            return (palindrome2 (s, i+1, j-1));
        else
            return true;
    else
        return false;
}

bool palindrome3 (string s, int i, int j)
{
    assert (i>=0 && i<=j && j<s.length());
    //                                                                                                           
    if (i == j)
        return true;
    if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122)
        return (palindrome3 (s, i+1, j));
    if (s[j] < 65 || (s[j] > 90 && s[j] < 97) || s[j] > 122)
        return (palindrome3 (s, i, j-1));
    if (s[i] == s[j] || (s[i]+32 == s[j]) || (s[i]-32 == s[j]))
        if (j-1 > i)
            return (palindrome3 (s, i+1, j-1));
        else
            return true;
    else
        return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    assert (i >= 0 && i <= chars.length() && j >= 0 && j <= source.length());
    //                                                                                               
    if (j == source.length())
        return false;
    if (i == chars.length())
        return true;

    if (chars[i] == source[j])
        return (match_chars (chars, i+1, source, j));
    else
        return (match_chars (chars, i, source, j+1));
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

