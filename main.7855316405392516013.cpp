#include <iostream>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

//                                              

int power_of (double x, int n)
{
    //              
    assert (n >= 0 && x > 0);
    //                                                  

    if (n == 0)
    {
        return 1;
    }
    int i = power_of(x, n-1);
    return x*i;
}

int power_of2 (double x, int n)
{
    //              
    assert (n >= 0 && x > 0);
    //                                                  
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        int i = n/2;
        return power_of2(x, i) * power_of2(x, i);
    }
    else
        return x * power_of2(x, n - 1);

}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert (j >= i);
    //                                                       
    if (j <= i)
    {
        return true;
    }
    if (text [i] != text [j])
    {
        return false;
    }
    else
        return palindrome1(text, i + 1, j - 1);
}

bool palindrome2 (string text, int i, int j)
{
    //              
    assert (j >= i);
    //                                                                                                        
    if (j <= i)
    {
        return true;
    }
    char a = text.at(i);
    if (int (a) < 97)
    {
        text.at(i) = int (a) + 32;
    }
    char b = text.at(j);
    if (int (b) < 97)
    {
        text.at(j) = int (b) + 32;
    }
    if (text [i] != text [j])
    {
        return false;
    }
    else
        return palindrome2(text, i + 1, j - 1);
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert (j >= i);
    //                                                                                                                                                        
    if (i + (j - i) == 1)
    {
        return true;
    }
    if (j <= i)
    {
        return true;
    }
    char a = text.at(i);
    if (int (a) < 97)
    {
        text.at(i) = int (a) + 32;
    }
    char b = text.at(j);
    if (int (b) < 97)
    {
        text.at(j) = int (b) + 32;
    }
    if (int (a) < 65)
    {
        return palindrome3(text, i + 1, j);
    }
    if (int (b) < 65)
    {
        return palindrome3(text, i, j - 1);
    }
    if (text [i] != text [j])
    {
        return false;
    }
    else
        return palindrome3(text, i + 1, j - 1);
}

bool match_chars (string chars, int i, string source, int j)
{
    //              
    assert (i >= 0 && j >= 0);
    //                                                                                                          
    if (i == chars.size())
        return true;
    if (j == source.size())
        return false;
    if (chars [i] != source [j])
    {
        return match_chars(chars, i, source, j + 1);
    }
    else
    {
        return match_chars(chars, i + 1, source, j);
    }

}

int main ()
{

}

