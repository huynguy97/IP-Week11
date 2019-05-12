#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

//                        
//                       

double power (double x, int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return x*power(x, n-1);
    }
}

double effpower (double x, unsigned int n)
//                                                           
{
    if (n==0)
    {
        return  1;
    }
    else if (n==1)
    {
        return x*power(x, n-1);
    }
    else
        return (x*x*(power(x, n-2)));
}

bool palindrome1 (string text, int i, int j)
{
    if (j <= i)
    {
        return true;
    }
    else
    {
        if (text[i] == text[j])
        {
          return palindrome1(text, (i+1), (j-1));
        }
        if (text[i] != text[j])
        {
            return false;
        }
    }
}

bool palindrome2 (string text, int i, int j)
{
    for(int l =0; l <= j; l++)
    {
        text[l] = tolower(text[l]);
    }
    if (j <= i)
    {
        return true;
    }
    else
    {
        if (text[i] == text[j])
        {
            return palindrome2(text, (i+1), (j-1));
        }
        if (text[i] != text[j])
        {
            return false;
        }
    }
}

bool palindrome3 (string text, int i, int j)
{
    for(int l =0; l <= j; l++)
    {
        text[l] = tolower(text[l]);
    }
    if (j <= i)
    {
        return true;
    }
    else
    {
        if ((text)[i]  == char(32) || text[i]  == char(33) || text[i]  == char(39) || text[i]  == char(44) || text[i]  == char(45) || text[i]  == char(46) || text[i]  == char(47) || text[i]  == char(58) || text[i]  == char(59) || text[i]  == char(63) || text[i]  == char(96))
        {
            return palindrome3(text, (i+1), j);
        }
        else  if ((text)[j]  == char(32) || text[j]  == char(33) || text[j]  == char(39) || text[j]  == char(44) || text[j]  == char(45) || text[j]  == char(46) || text[j]  == char(47) || text[j]  == char(58) || text[j]  == char(59) || text[j]  == char(63) || text[j]  == char(96))
        {
           return palindrome3(text, (i), (j-1));
        }
        else
        {
            if (text[i] == text[j])
            {
                return palindrome3(text, (i+1), (j-1));
            }
            if (text[i] != text[j])
            {
                return false;
            }
        }
    }
}

bool match_chars (string chars, int i, string source, int j)
{
    if (i == chars.length())
    {
        return true;
    }
    else
    {

        for (j; j < source.length(); j++)
        {

            if (source[j] == chars[i])
            {

                return match_chars(chars,i+1,source,j+1);
            }
        }
    }
    return false;
}

int main()
{
    cout << power(2,3) << endl;
    cout << effpower(2,3)  << endl;
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome3("O;tto", 0, 4) << endl;
    cout << match_chars("abc",0,"a big coach",0) << endl;
}

