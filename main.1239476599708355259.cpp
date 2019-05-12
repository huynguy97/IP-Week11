//                       
//                       

#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

/*                               */

double power (double x, int n)
{
//                
    assert (n >= 0);
/*                 
                                             */

    if (n == 0)
        return 1;
    else
        return x * power (x, n - 1);
}

/*                                           */
double power_2 (double x, int n)
{
//                
    assert (n >= 0);
/*                 
                                             */

    if (n == 0)
        return 1;
    else if (n % 2 == 0) //             
        return power_2 (x, n/2) * power_2(x, n/2);
    else //            
        return x * power_2 (x, n/2) * power_2(x, n/2);
}

/*                                                                                     
                                                                                            
                                                                                         
                                                                                              
                                                                                   
                                                                                       
                                                                                     
                   */

/*                                 */
void input_user ()
{
//                
    assert (true);
/*                 
                                                      
                                                                  
                                              */

    double x;
    int n;
    cout << "What is the base you want to choose?" << endl;
    cin >> x;
    do
    {
        cout << '\n' << "What is the exponent you want to choose?" << endl;
        cin >> n;
    }
    while ( n < 0 );
    cout << '\n' << "Part 1.1: " << x << " raised to the power of " << n << " is " << power(x, n) << endl;
    cout << "Part 1.2: " << x << " raised to the power of " << n << " is " << power_2(x, n) << '\n' << endl;
}

/*                                        */
bool palindrome1 (string text, int i, int j)
{
//                
    assert (i >= 0 && i <= j && j > 0);
/*                 
                                                                            
                                                                                         
                                                            */

    if  (i == j)
        return true;
    else if (i + 1 == j)
        return text[i] == text[j];

    if (text[i] == text[j])
    {
        return palindrome1 (text, i+1, j-1);
    }
    else
        return false;
}

/*                                        */
bool palindrome2 (string text, int i, int j)
{
//                
    assert (i >= 0 && i <= j && j > 0);
/*                 
                                                                            
                                                                                             
                                                            */

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    if  (i == j)
        return true;
    else if (i + 1 == j)
        return text[i] == text[j];

    if (text[i] == text[j])
    {
        return palindrome2 (text, i+1, j-1);
    }
    else
        return false;
}

/*                                                          */
bool palindrome3 (string text, int i, int j)
{
//                
    assert (i >= 0 && i <= j && j > 0);
/*                 
                                                                            
                                                                                             
                                                           
                                                   */

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    if (isspace(text[i]) || ispunct (text[i]))
        return palindrome3 (text, i+1, j);

    if (isspace(text[j]) || ispunct (text[j]))
        return palindrome3 (text, i, j-1);

    if  (i == j)
        return true;
    else if (i + 1 == j)
        return text[i] == text[j];

    if (text[i] == text[j])
        return palindrome3 (text, i+1, j-1);
    else
        return false;
}

/*                                                 */
bool match_chars (string chars, int i, string source, int j)
{
//                
    assert (i >= 0 && j >= 0 && i <= chars.length() && j <= source.length());
/*                 
                                                                                     
                                                                                      */

    if (i == chars.length())
        return true;
    if (i != chars.length() && j == source.length())
        return false;
    if (source[j] == chars[i])
        return match_chars(chars, i+1, source, j);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
    cout << "Part 1:" << endl;
    input_user();

    cout << '\n' << "Part 2:" << endl;
    string text;
    cout << "For what string do you want to know if it is a palindrome?" << endl;
    cin >> text;

    cout << '\n' << "Part 2.1:" << endl;
    if (palindrome1(text, 0, text.length()-1))
        cout << "The string you entered is a palindrome!" << endl;
    else
        cout << "The string you entered is not a palindrome." << endl;

    cout << '\n' << "Part 2.2:" << endl;
    if (palindrome2(text, 0, text.length()-1))
        cout << "The string you entered is a palindrome!" << endl;
    else
        cout << "The string you entered is not a palindrome." << endl;

    cout << '\n' << "Part 2.3:" << endl;
    if (palindrome3(text, 0, text.length()-1))
        cout << "The string you entered is a palindrome!" << endl;
    else
        cout << "The string you entered is not a palindrome." << endl;

    cout << '\n' << "Part 3:" << endl;
    if (match_chars("abc", 0, "It is a classy bag", 0))
        cout << "returns true" << endl;
    else
        cout << "returns false" << endl;
    return 0;
}

