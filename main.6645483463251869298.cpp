/*                                                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

double naive_power (double x, int n)
{
    //               
    assert (n >= 0);
    /*                 
                                                
    */
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
        return (x * naive_power(x, n-1));
}

double power (double x, int n)
{
    //               
    assert (n >= 0);
    /*                 
                                                                        
    */
    double temp;
    if (n == 0)
        return 1;
    temp = power (x, n/2);
    if (n%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;

    /*                                              
    */
}

bool palindrome1 (string text, int i, int j)
{
    //               
    assert (i >= 0 && j >= 0);
    /*                                                            
    */
    if (i >= j)
        return true;
    if (text[i] != text[j])
        return false;
    return palindrome1(text,i+1,j-1);
}

bool palindrome2 (string text, int i, int j)
{
    //               
    assert (i >= 0 && j >= 0);
    /*                                                                                         
    */
    text[i] = tolower(text[i]);
    text[j] = tolower(text[j]);
    if (i >= j)
        return true;
    if (text[i] != text[j])
        return false;
    return palindrome2(text,i+1,j-1);
}

bool palindrome3 (string text, int i, int j)
{
    //               
    assert (i >= 0 && j >= 0);
    /*                                                                                                                  
    */
    for (int i = 0, len = text.size(); i < len; i++)
    {
        if (ispunct(text[i]) || isspace(text[i]))
        {
            text.erase(i--, 1);
            len = text.size();
            j--;
        }
    }
    text[i] = tolower(text[i]);
    text[j] = tolower(text[j]);
    if (i >= j)
        return true;
    if (text[i] != text[j])
        return false;
    return palindrome3(text,i+1,j-1);
}

bool match_chars (string chars, int i, string source, int j)
{
    //               
    assert (i >= 0 && j >= 0);
    /*                 
                                                                                                                              
    */
    if (chars.length() == 0)
        return true;
    if (j == source.length()-1)
        return false;
    if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    return match_chars(chars, i, source, j+1);
}

int main()
{
    double number;
    int raised;
    string test;
    int pos_one;
    int pos_two;
    string characters;
    int one;
    string main;
    int two;
    cout << "Enter a number: " ;
    cin >> number ;
    cout << "To what power to raise: " ;
    cin >> raised ;
    cout << naive_power(number,raised) << endl;
    cout << power(number,raised) << endl;
    cout << "Enter a text: " ;
    getline(cin, test);
    cout << "Enter start: ";
    cin >> pos_one ;
    cout << "Enter end: ";
    cin >> pos_two ;
    if (palindrome1(test, pos_one, pos_two))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if (palindrome2(test, pos_one, pos_two))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if (palindrome3(test, pos_one, pos_two))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "Enter a text: " ;
    getline(cin, main);
    cout << "Enter characters: " ;
    getline(cin, characters);
    cout << "Enter start for text: ";
    cin >> one ;
    cout << "Enter start for characters: ";
    cin >> two ;
    if (match_chars(characters, one, main, two))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

