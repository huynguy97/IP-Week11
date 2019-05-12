/*                                                                    
                                                                      
 */

#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

/*                                  
                                                                                
 */

double naive_power(double x, double n)
{//               
    assert(n >= 0);
/*                 
                
*/
    if (n == 0)
        return 1;

    return x * naive_power(x, n-1);
}

double efficient_power(double x, double n)
{//               
    assert(n >= 0);
/*                 
                                                       
*/
    if (n == 0)
        return 1;

    div_t result = div(n, 2);
    double y = efficient_power(x, result.quot);

    if (fmod(n, 2) == 0)
        return y * y;

    return (x * y * y);
}

char to_lowercase(char c)
{//               
    assert(isalpha(c) != 0);
/*                 
                                                     
*/
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

bool palindrome1(string text, int i, int j)
{//               
    assert(i >= 0 && j <= text.size()-1);
/*                 
                                                                         
*/
    if (i >= j)
        return true;
    if (text[i] == text[j])
        palindrome1(text, i+1, j-1);
    else if (text[i] != text[j])
        return false;
}

bool palindrome2(string text, int i, int j)
{//               
    assert(i >= 0 && j <= text.size()-1);
/*                 
                                                                       
                                                                      
*/
    if (i >= j)
        return true;
    if (to_lowercase(text[i]) == to_lowercase(text[j]))
        palindrome2(text, i+1, j-1);
    else if (text[i] != text[j])
        return false;
}

bool palindrome3(string text, int i, int j)
{//               
    assert(i >= 0 && j <= text.size()-1);
/*                 
                                                                       
                                                                               
                    
*/
    int len = text.size();
    for (int k = 0; k < len; k++) {
        if (ispunct(text[k])) {
            text.erase(k--, 1);
            len = text.size();
        }
    }
    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    len = text.size();
    return palindrome2(text, i, len-1);
}

bool match_chars(string chars, int i, string source, int j)
{//               
    assert(i >= 0 && i <= chars.length()-1 && j >= 0 && j <= source.length()-1);
/*                 
                                                                  
                                                                           
*/
    if (chars[i] != source[j] && j == source.length()-1)
        return false;
    else if (chars[i] == source[j] && i == chars.length()-1)
        return true;

    if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);

    return match_chars(chars, i, source, j+1);
}

int main() {
    double n = naive_power(2, 31);
    double e = efficient_power(2, 31);

    cout << "    Naive power of 2^31 = " << n << '\n';
    cout << "Efficient power of 2^31 = " << e << '\n' << '\n';
    cout << "Is 'Madam, I'm Adam.' a palindrome? " << '\n';

    if (palindrome3("Madam, I'm Adam.", 0, 15))
        cout << "true" << '\n' << '\n';
    else
        cout << "false" << '\n' << '\n';

    cout << "Do 'abc' and 'It is a bag of cards' match? " << '\n';

    if (match_chars("abc", 0, "It is a bag of cards", 0))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';

    return 0;
}

