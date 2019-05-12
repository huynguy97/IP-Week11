#include <iostream>
#include <cassert>

//                                              

using namespace std;

/*
                              
*/

double naive_power(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n >= 1)
        return x*naive_power(x, n-1);
}

/*
                                                                   
                                        
*/
double efficient_power(double x, int n)
{
    double temp;
    if (n == 0)
        return 1;
    temp = efficient_power(x, n/2);
    if (n%2 == 0)
        return temp*temp;
    else if (n >= 1)
        return x*temp*temp;
    else
        return (temp*temp)/x;
}

/*
                       
*/

bool palindrome(string text, int i, int j)
{
    assert(i >= 0 && i < text.length() &&
           j >= 0 && j < text.length());

    if (i == j)
        return true;
    if (text[i] != text[j])
        return false;
    if (i < j+1)
        return palindrome(text, i+1, j-1);
    return true;
}

bool palindrome2(string text, int i, int j)
{
    assert(i >= 0 && i < text.length() &&
           j >= 0 && j < text.length());

    if (i == j)
        return true;
    if (tolower(text[i]) != tolower(text[j]))
        return false;
    if (i < j+1)
        return palindrome2(text, i+1, j-1);
    return true;
}

bool palindrome3(string text, int i, int j)
{
    assert(i >= 0 && i < text.length() &&
           j >= 0 && j < text.length());

    if (i == j)
        return true;
    if ((iswpunct(text[i]) || iswblank(text[i])) != 0)
        return palindrome3(text, i+1, j);
    if ((iswpunct(text[j]) || iswblank(text[j])) != 0)
        return palindrome3(text, i, j-1);
    if (tolower(text[i]) != tolower(text[j]))
        return false;
    if (i < j+1)
        return palindrome3(text, i+1, j-1);
    return true;
}

/*
                                           
*/

bool match_chars(string chars, int i, string source, int j)
{
    assert(i >= 0 && j >= 0
           && chars.size() >= 0 && source.size() >= 0);

    if (i >= chars.size() && j >= source.size())
        return false;
    if (i >= chars.size() && j < source.size())
        return true;
    if (i < chars.size() && j < source.size() &&
        tolower(chars[i]) == tolower(source[j]))
        return match_chars(chars, i+1, source, j+1);
    if (i < chars.size() && j < source.size() &&
        tolower(chars[i]) != tolower(source[j]))
        return match_chars(chars, i, source, j+1);
    return false;
}

int main()
{
    cout << naive_power(-1, 3) << endl;
    cout << efficient_power(-1, 3) << endl;

    cout << palindrome("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;

    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;

    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;

    cout << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars("abc", 0, "It is a classy bag", 0) << endl;
    return -1;
}

