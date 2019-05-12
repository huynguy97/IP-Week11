#include <iostream>
#include <cassert>

using namespace std;

//                                                                                 

int PowerNaive(int x, int n)
{
//               
    assert (n >= 0);
/*                
                                          
*/
    if (n == 0)
        return 1;
    else
        return x * PowerNaive(x, n-1);
}

//                                                           
int PowerEfficient(int x, int n)
{
//               
    assert (n >= 0);
/*                
                                          
*/
    if (n == 0)
        return 1;
    if (n % 2 != 0)
        return x * PowerEfficient(x, n-1);
    int a = PowerEfficient(x, n/2);
    return a * a;
}

bool Palindrome1(string text, int i, int j)
{
//               
    assert (i >= 0 && i < text.length() && j >= 0 && j < text.length());
/*                
                                                                                                                                                
*/
    if (i > j)
        return true;
    return (text[i] == text[j]) && Palindrome1(text, i+1, j-1);
}

bool Palindrome2(const string text, int i, int j)
{
//               
    assert (i >= 0 && i < text.length() && j >= 0 && j < text.length());
/*                
                                                                                                                                                
                                                                                                                                           
*/
    if (i > j)
        return true;
    return (tolower(text[i]) == tolower(text[j])) && Palindrome2(text, i+1, j-1);
}

bool Palindrome3(string text, int i, int j)
{
//               
    assert (i >= 0 && i < text.length() && j >= 0 && j < text.length());
/*                
                                                                                                                                                
                                                                                                                                           
                                                                                                                                                   
                                                                                         
*/
    if (i > j)
        return true;
    if (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
        return (Palindrome3(text, i+1, j));
    if (!((text[j] >= 65 && text[j] <= 90) || (text[j] >= 97 && text[j] <= 122)))
        return (Palindrome3(text, i, j-1));
    return (tolower(text[i]) == tolower(text[j]) && Palindrome3(text, i+1, j-1));
}

bool MatchChars(string chars, int i, string source, int j)
{
//               
    assert (i >= 0 && j >= 0);
/*                
                                                                                                                                              
*/
    if (i > chars.length())
        return true;
    if (j >= source.length())
        return false;
    if (chars[i] == source[j])
        i++;
    return MatchChars(chars, i, source, j+1);
}

int main()
{
    cout << Palindrome1("Otto", 0, 3);
    return 0;
}

