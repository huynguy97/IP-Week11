#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <math.h>

using namespace std;

/*                                              
                                                
                                                
                                                
                                                
                                                
                                                
                                              */
double power1(double x, int n)
{
   /*               */
    assert (x >= 0 && n >= 0);
    /*               
                                      */
   if (n == 0)
        return 1;
    else
        return x * power1(x, n - 1);
}
/*                                              
                                                
                                              */
double power2(double x, int n)
{
    /*               */
    assert (x >= 0 && n >= 0);
    /*               
                                      */
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        return power2(x, n / 2) * power2(x, n / 2);
    }
    else
        return x * power2(x, n - 1);
}
//           

/*                                              
                                               
                                              */
bool palindrome1 (string text, int i, int j)
{
    /*               */
    assert (i >= 0 && (text.length() >= 1));
    /*               
                                                   */
    if (i == j)
        return true;
    if (text[i] != text[j])
        return false;
    if (i < j + 1)
        return palindrome1(text, i+1, j-1);
    return true;
}

/*                                              
                                                
                                              */
bool palindrome2 (string text, int i, int j)
{
    /*               */
    assert (i >= 0 && (text.length() >= 1));
    /*               
                                                                                                       */
    if (i == j)
        return true;
    if (tolower(text[i]) != tolower(text[j]))
        return false;
    if (i < j + 1)
        return palindrome2(text, i+1, j-1);
    return true;
}

/*                                              
                                                
                                              */
bool palindrome3 (string text, int i, int j)
{
    /*               */
    assert (i >= 0 && (text.length() >= 1));
    /*               
                                                                                                                                                         */
    for (int i = 0; i < text.length(); i++)
    {
        if (ispunct(text[i]) || text[i] == ' ')
        {
            text.erase(i, 1);
            i--;
            j--;
        }
    }
    if (i == j)
        return true;
    if (tolower(text[i]) != tolower(text[j]))
        return false;
    if (i < j + 1)
        return palindrome2(text, i+1, j-1);
    return true;
}

/*                                              
                                                
                                              */
bool match_chars (string chars, int i, string source, int j)
{
    /*               */
    assert (i >= 0 && j >= 0);
    /*               
                                                                                           
                                                                                             */
    if (i == chars.length())
        return true;
    if (j > source.length())
        return false;
    if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}
int main()
{
    cout << "==-- Part 1.1 --==" << endl << power1(2.0, 100) << endl << endl;
    cout << "==-- Part 1.2 --==" << endl << power2(2.0, 100) << endl << endl;
    cout << "==-- Part 2.1 --==" << endl << "Returns: " << palindrome1("supermanamrepus", 0, 14) << endl << endl;
    cout << "==-- Part 2.2 --==" << endl << "Returns: " << palindrome2("HaLlOoLlAh", 0, 9) << endl  << endl;
    cout << "==-- Part 2.3 --==" << endl << "Returns: " << palindrome3("H.aLl!Oo.L..lAh", 0, 14) << endl << endl;
    cout << "==-- Part 3 --==" << endl << "Returns: " << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
}

