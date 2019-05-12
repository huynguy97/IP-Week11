#include <iostream>
#include <cassert>
#include <string>

//                                       
//                                 

using namespace std;

long long int naive_power (double x, int n)
{//              
    assert(n >= 0);
/*               
                           
*/
    if (n == 0)
        return 1;
    else
        return x * naive_power(x, n-1);
}

long long int more_efficient_power (double x, int n)
{//              
    assert(n >= 0);
/*               
                           
*/
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return more_efficient_power(x, n/2) * more_efficient_power(x, n/2);
    else
        return x * more_efficient_power(x, n-1);
}

bool palindrome1 (string text, int i, int j)
{//              
    assert(i >= 0 && j >= 0);
/*               
                                                                                                                  
                                                          
*/
    if (i >= j)
        return true;
    else if (text.at(i) != text.at(j))
        return false;
    else
        return palindrome1(text, i+1, j-1);

}

bool palindrome2 (string text, int i, int j)
{//              
    assert(i >= 0 && j >= 0);
/*               
                                                                                                                    
                                                          
*/
    if (i >= j)
        return true;
    else
    {
        if ((text.at(i) >= 65 && text.at(i) <= 90) && (text.at(j) >= 97 && text.at(j) <= 122))
        {
            if (text.at(i) == text.at(j) - 32)
                return palindrome2(text, i+1, j-1);
            else
                return false;
        }
        else if ((text.at(i) >= 97 && text.at(i) <= 122) && (text.at(j) >= 65 && text.at(j) <= 90))
        {
            if (text.at(i) == text.at(j) + 32)
                return palindrome2(text, i+1, j-1);
            else
                return false;
        }
        else if (text.at(i) == text.at(j))
            return palindrome2(text, i+1, j-1);
        else
            return false;
    }
}

bool palindrome3(string text, int i, int j)
{//              
    assert(i >= 0 && j >= 0);
/*               
                                                                                                                    
                                                                                                      
                                                          
*/
    if (i >= j)
        return true;
    else if (text.at(i) == 32 || text.at(i) == 33 || text.at(i) == 39 || (text.at(i) >= 44 && text.at(i) <= 46) || text.at(i) == 58 || text.at(i) == 59 || text.at(i) == 63)
        return palindrome3(text, i+1, j);
    else if (text.at(j) == 32 || text.at(j) == 33 || text.at(j) == 39 || (text.at(j) >= 44 && text.at(j) <= 46) || text.at(j) == 58 || text.at(j) == 59 || text.at(j) == 63)
        return palindrome3(text, i, j-1);
    else
    {
        if ((text.at(i) >= 65 && text.at(i) <= 90) && (text.at(j) >= 97 && text.at(j) <= 122))
        {
            if (text.at(i) == text.at(j) - 32)
                return palindrome3(text, i+1, j-1);
            else
                return false;
        }
        else if ((text.at(i) >= 97 && text.at(i) <= 122) && (text.at(j) >= 65 && text.at(j) <= 90))
        {
            if (text.at(i) == text.at(j) + 32)
                return palindrome3(text, i+1, j-1);
            else
                return false;
        }
        else if (text.at(i) == text.at(j))
            return palindrome3(text, i+1, j-1);
        else
            return false;
    }
}

bool match_chars (string chars, int i, string source, int j)
{//              
    assert(i >= 0 && j >= 0);
/*               
                                                                                                  
                                         
*/
    if (i >= chars.length() && j <= source.length())
        return true;
    else if (j >= source.length())
        return false;
    else if (chars.at(i) == source.at(j))
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
    cout << naive_power(5,4) << endl;
    cout << more_efficient_power(5,4) << endl;
    string palinstr = "Madam, I'm Adam.";
    string charstr = "abcd";
    string sourcestr = "It is a bag of card";
    if (palindrome1(palinstr, 0, palinstr.length() - 1))
        cout << "It is a palindrome!" << endl;
    if (palindrome2(palinstr, 0, palinstr.length() - 1))
        cout << "It is a palindrome!" << endl;
    if (palindrome3(palinstr, 0, palinstr.length() - 1))
        cout << "It is a palindrome!" << endl;
    if (match_chars(charstr, 0, sourcestr, 0))
        cout << "Chars match!" << endl;
    return 0;
}

