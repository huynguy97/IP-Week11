/*
                                                      
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

/*                                                                 */

double power (double x, int n)
{
    //               
    assert (n >= 0);
    //                
    //             

    if (n == 0)
        return 1;
    else
        return x * power (x, n-1);
}

double power_efficient (double x, int n)
{
    //               
    assert (n >= 0);
    //                
    //             
    if (n == 0)
        return 1;
    else
        if (n%2 == 0)
        {
            n = n/2;
            double y = x * power_efficient (x, n-1);
            return y * y;
        }
        else
            return x * power_efficient (x, n-1);
}

/*                                                                 */

bool palindrome1(string text, int i, int j)
{
    //             
    assert(i <= j && i >=0 && j >=0);
    //                                                         

    if (i == j || i == j -1)
    {
        return text[i] == text[j];
    }
    else
    {
        if (text[i] != text[j])
            return false;
        return palindrome1 (text, i+1, j-1);
    }
}

bool palindrome2(string text, int i, int j)
{
    //             
    assert(i <= j && i >=0 && j >=0);
    //                                                                                              
    //                   

    if (i == j || i == j -1)
    {
        if (text[i] != text[j])
        {
            int inti, intj;

            inti = int(text[i]);
            intj = int(text[j]);

            cout << inti << intj;

            return inti == intj+32 || inti == intj-32;
        }

        return text[i] == text[j];
    }
    else
    {
        if (text[i] != text[j])
        {
            int inti, intj;

            inti = int(text[i]);
            intj = int(text[j]);

            if (inti != intj+32 && inti != intj-32)
            {
                return false;
            }
            else
                return palindrome2 (text, i+1, j-1);
        }
        return palindrome2 (text, i+1, j-1);
    }
}

bool palindrome3(string text, int i, int j)
{
    //             
    assert(i <= j && i >=0 && j >=0);
    //                                                                                              
    //                                                            

    while(int(text[i]) >=32 && int(text[i]) <= 47 || int(text[i]) >= 58 && int(text[i]) <=64)
        i = i+1;

    while(int(text[j]) >=32 && int(text[j]) <= 47 || int(text[j]) >= 58 && int(text[j]) <=64)
        j = j-1;

    if (i == j || i == j -1)
    {
        if (text[i] != text[j])
        {
            int inti, intj;

            inti = int(text[i]);
            intj = int(text[j]);

            cout << inti << intj;

            return inti == intj+32 || inti == intj-32;
        }

        return text[i] == text[j];
    }
    else
    {
        if (text[i] != text[j])
        {
            int inti, intj;

            inti = int(text[i]);
            intj = int(text[j]);

            if (inti != intj+32 && inti != intj-32)
            {
                return false;
            }
            else
                return palindrome3 (text, i+1, j-1);
        }
        return palindrome3 (text, i+1, j-1);
    }
}

/*                                                                 */

bool match_chars (string chars, int i, string source, int j)
{
    //            
    assert(i>=0 && j>=0);
    //                                                                                     

    if (i >= chars.length())
        return true;

    while(chars[i] != source[j] && j < source.length())
        j++;

    if (j >= source.length())
        return false;
    else
         return (match_chars(chars, i+1, source, j+1));
}

int main ()
{
    cout << power_efficient (2.30, 16) << endl;
    cout << power (2.30, 16) << endl;

    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;

    cout << match_chars ("abc", 0, "It is a bag of books", 0);

    return 0;
}

