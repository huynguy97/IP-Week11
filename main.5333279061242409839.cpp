#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//                                                       
//                                                   

int power0(int x, int n)
{
    //             
    assert(n >= 0);
    /*              
                                    
    */
    if (n == 0)
        return 1;

    return x * power0(x, n - 1);
}

double power0(double x, int n)
{
    //             
    assert(n >= 0);
    /*              
                                    
    */
    if (n == 0)
        return 1;

    return x * power0(x, n - 1);
}

int power(int x, int n)
{
    //             
    assert(n >= 0);
    /*              
                                    
    */
    if (n == 0)
        return 1;

    int result = power(x, n / 2);
    result *= result;
    if (n % 2 == 1)
        result *= x;
    return result;
}

double power(double x, int n)
{
    //             
    assert(n >= 0);
    /*              
                                    
    */
    if (n == 0)
        return 1;

    int result = power(x, n / 2);
    result *= result;
    if (n % 2 == 1)
        result *= x;
    return result;
}

bool palindrome1(string text, int i, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i < text.length() && j < text.length());
    /*              
                                                             
    */

    if (i >= j)
        return true;

    if (text[i] == text[j])
        return palindrome1(text, i + 1, j - 1);
    else
        return false;
}

bool same_letter(char c, char d)
{
    //             
    assert(true);
    /*              
                                                                                                       
    */

    return((c == d) || ('A' <= c && c <= 'Z' && c + 32 == d) || ('A' <= d && d <= 'Z' && d + 32 == c));
}

bool palindrome2(string text, int i, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i < text.length() && j < text.length());
    /*              
                                                                                                                                                                     
    */

    if (i >= j)
        return true;

    if (same_letter(text[i], text[j]))
        return palindrome2(text, i + 1, j - 1);
    else
        return false;
}

bool punctuation_mark(char c)
{
    //             
    assert(true);
    /*              
                                                                                                            
    */

    return(c == ' ' || c == '.' || c == ',' || c == ':' || c == ';' || c == '\'' || c == '!' || c == '?' || c == '-');
}

bool palindrome3(string text, int i, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i < text.length() && j < text.length());
    /*              
                                                                                                                                                                     
                                                   
    */

    while (i < text.length() && punctuation_mark(text[i]))
        i++;
    while (j >= 0 && punctuation_mark(text[j]))
        j--;

    if (i >= j)
        return true;

    if (same_letter(text[i], text[j]))
        return palindrome3(text, i + 1, j - 1);
    else
        return false;
}

bool match_chars(string chars, int i, string source, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i <= chars.length() && j <= source.length());
    /*              
                                                                                                                             
    */

    if (i == chars.length())
        return true;
    else if (j == source.length())
        return false;

    if (chars[i] == source[j])
        return match_chars(chars, i + 1, source, j + 1);
    else
        return match_chars(chars, i, source, j + 1);
}

int main()
{
    cout << power0(5, 3) << endl;
    cout << power(2, 11) << endl;
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome1("Otto", 0, 3) << endl;
    cout << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << palindrome2("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << palindrome3("otto", 0, 3) << endl;
    cout << palindrome3("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars ("abc", 0, "It is a bag of books", 0) << endl;
    cout << match_chars ("abc", 0, "It is a classy bag", 0) << endl;
    return 0;
}

/*
         
                                            
*/

