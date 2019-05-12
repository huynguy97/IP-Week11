#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

/*            
                     
                             
*/

double power (double x, int n)
{
    assert(n >= 0);
    /*               
               
    */

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x*power(x, n-1);
    }
}

double betterpower (double x, int n)
{
    assert(n >= 0);
    /*               
               
    */

    if(n == 0)
    {
        return 1;
    }
    else if(n%2 == 0)
    {
        double temp = betterpower(x, n/2);
        return temp *temp;
    }
    else
    {
        double temp = betterpower(x, (n-1)/2);
        return x * temp * temp;
    }
    //          
}

bool palindrome1(string text, int i, int j)
{
    assert(i >= 0 && i >= 0);
    /*               
                                                                               

    */
    if (j <= i)
    {
        return true;
    }

    if (text[i] == text[j])
    {
        return palindrome1(text, i+1, j-1);
    }
    return false;

}

bool is_letter(char c)
{
    assert(true);
    //                                

    int i = static_cast<int>(c);
    if ((i > 64 && i <91)||(i > 96 && i <123))
    {
        return true;
    }
    return false;
}

bool is_punctuation(char c)
{
    assert(true);
    //                                          
    if (c == '.'|| c ==',' || c ==':' || c ==';'|| c =='\''|| c =='!'|| c =='?'|| c =='-'|| c ==' ')
    {
        return true;
    }
    return false;
}

bool palindrome2(string text, int i, int j)
{
    assert(i >= 0 && i >= 0);
    /*               
                                                                               
    */

    if (j <= i)
    {
        return true;
    }

    if (is_letter(text[i]) && is_letter(text[j]))
    {
        int diff = abs(static_cast<int>(text[i])-static_cast<int>(text[j]));
        if(diff == 32 || diff == 0)
        {
            return palindrome2(text, i+1, j-1);
        }
    }
    else if (text[i] == text[j])
    {
        return palindrome2(text, i+1, j-1);
    }
    return false;

}

bool palindrome3(string text, int i, int j)
{
     assert(i >= 0 && i >= 0);
    /*               
                                                                               
    */
    while (is_punctuation(text[i]))
    {
        i++;
    }
    while (is_punctuation(text[j]))
    {
        j--;
    }

    if (j <= i)
    {
        return true;
    }

    if (is_letter(text[i]) && is_letter(text[j]))
    {
        int diff = abs(static_cast<int>(text[i])-static_cast<int>(text[j]));
        if(diff == 32 || diff == 0)
        {
            return palindrome3(text, i+1, j-1);
        }
    }if (j <= i)
    {
        return true;
    }

    if (is_letter(text[i]) && is_letter(text[j]))
    {
        int diff = abs(static_cast<int>(text[i])-static_cast<int>(text[j]));
        if(diff == 32 || diff == 0)
        {
            return palindrome2(text, i+1, j-1);
        }
    }
    else if (text[i] == text[j])j++;
    {
        return palindrome2(text, i+1, j-1);
    }
    return false;
}

bool match_chars(string chars, int i, string source, int j)
{
    assert(i >= 0 && j >= 0);
    /*               
                                                                                                                                           
    */

    if (i == chars.length())
    {
        return true;
    }
    while (j < source.length())
    {
        if (chars[i] == source[j])
        {
            return match_chars(chars, i+1, source, j+1);
        }
        j++;
    }
    return false;

}

int main()
{
    cout << "power(2, 2) =  " << power(2, 2) << endl;
    cout << "betterpower(2, 2) =  " << betterpower(2, 2) << endl;
    cout << "palindrome1 (Madam, I'm Adam, 0, 15) = " << palindrome1 ("Madam, I'm Adam.", 0, 15) << endl;
    cout << "palindrome2 (Madam, I'm Adam, 0, 15) = " << palindrome2 ("Madam, I'm Adam.", 0, 15) << endl;
    cout << "palindrome3 (Madam, I'm Adam, 0, 15) = " << palindrome3 ("Madam, I'm Adam.", 0, 15) << endl;
    cout << "match_chars(abc, 0, It is a bag of cards, 0) = " << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
}

