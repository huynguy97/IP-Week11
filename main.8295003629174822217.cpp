#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

//                     
double power (double& x, int n)
{
    //              
    assert(n>=0);
    //               
    //                

    if (n==0)
        return 1;
    else
    {
        x=x*power(x, n-1);
        return x;
    }
}

//                                 
double efficient_power (double& x, int n)
{
    //              
    assert(n>=0);
    //               
    //                

    if (n==0)
        return 1;
    else if (n%2 == 0)
    {
        x= (efficient_power(x, n/2)) * (efficient_power(x, n/2));
        return x;
    }
    else
    {
        x = x * efficient_power(x, n - 1);
        return x;
    }
}

void powers (double x, double z, int n)
{
    power (x, n);
    cout << x << endl;
    efficient_power(z, n);
    cout << z << endl;
    cout << endl;
}

//                              
bool palindrome1 (string text, int i, int j)
{
    //              
    //                          
    //               
    //                                             

    if (text[i] != text[j])
        return false;
    else if (i>=0 && j>=0)
    {
        palindrome1(text, i+1, j-1);
        return true;
    }
}

//                                      
bool palindrome2 (string text, int i, int j)
{
    //              
    //                         
    //               
    //                                             

    if (text [i] >= 65 && text [i] <= 90)
        text [i] = text [i] +32;
    else if (text [j] >= 65 && text [j] <= 90)
        text [j] = text [j] +32;

    if (text[i] != text[j])
        return false;
    else if (i>=0 && j>=0)
    {
        palindrome1(text, i+1, j-1);
        return true;
    }
}

//                                                
bool palindrome3 (string text, int i, int j)
{
    //              
    //                         
    //               
    //                                             

    if ((text [i] >= 32 && text [i] <= 47) || (text [i] >= 58 && text [i] <= 64))
    {
        text.erase(i, 1);
        palindrome3(text, i, j);
    }
    else if ((text [j] >= 32 && text [j] <= 47) || (text [j] >= 58 && text [j] <= 64))
    {
        text.erase(j, 1);
        palindrome3(text, i, j);
    }
    else if (text [i] >= 65 && text [i] <= 90)
        text [i] = text [i] +32;
    else if (text [j] >= 65 && text [j] <= 90)
        text [j] = text [j] +32;

    else if (text[i] != text[j])
        return false;
    else if (i>=0 && j>=0)
    {
        palindrome1(text, i+1, j-1);
        return true;
    }
}

void palindromes ()
{
    if (palindrome1("otto", 0, 3))
        cout << "Palindrome1 is true." << endl;
    else
        cout << "Palindrome1 is false." << endl;

    if (palindrome2("Otto", 0, 3))
        cout << "Palindrome2 is true." << endl;
    else
        cout << "Palindrome2 is false." << endl;

    if (palindrome3("Madam, I'm Adam.", 0, 3))
        cout << "Palindrome3 is true." << endl;
    else
        cout << "Palindrome3 is false." << endl;
    cout << endl;
}

//                                        
bool match_chars (string chars, int i, string source, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    //               
    //                                                                             

    if (i < chars.length()-1 && j == source.length())
        return false;
    else if (i == chars.length() -1 && chars [i] == source [j])
        return true;
    else if (chars [i] == source [j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

void matching_chars ()
{
    if (match_chars("abc", 0, "It is a bag of cards", 0))
        cout << "The characters match." << endl;
    else
        cout << "The characters do not match." << endl;

    if (match_chars("abc", 0, "It is a bag of books", 0))
        cout << "The characters match." << endl;
    else
         cout << "The characters do not match." << endl;

    if (match_chars("abc", 0, "It is a classy bag", 0))
        cout << "The characters match." << endl;
    else
        cout << "The characters do not match." << endl;
}

int main()
{
    powers(2.0, 2.0, 4);
    palindromes();
    matching_chars();
    return 0;
}
