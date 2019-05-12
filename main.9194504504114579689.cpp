#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

//                             
//                        

//                       
double power1 (int x, int n)
{
//               
    assert(n >= 0);
//                
//                           
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x*power1(x,n-1);
    }
}

//                                   
double power2 (int x, int n)
{
//               
    assert(n >= 0);
//                
//                           
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return power2(x, n / 2) * power2(x, n / 2);
    }
    else
    {
        return x*power2(x,n-1);
    }
}

//                                
bool palindromel (string text, int i, int j)
{
//               
    assert(i >= 0);
//                
//                                                                                    
    if (i == j || i-1 == j)
    {
        return true;
    }
    if (text[i] == text[j])
    {
        return palindromel(text, i+1,j-1);
    }
    return false;
}
//                                        
bool palindrome2 (string text, int i, int j)
{
//               
    assert(i >= 0);
//                
//                                                                                   
    if (i == j || i-1 == j)
    {
        return true;
    }
    if (tolower(text[i]) == tolower(text[j]))
    {
        return palindrome2(text, i+1,j-1);
    }
    return false;
}

//                                                  
bool palindrome3 (string text, int i, int j)
{
//               
    assert(i >= 0);
//                
//                                                                                                                                         
    for (int i = 0; i < text.size(); i++)
    {
        if (ispunct(text[i]) || text[i] == ' ')
        {
            text.erase(i, 1);
            i = i - 1;
            j = j - 1;
        }
    }
    return palindrome2(text, i, j);
}

bool match_chars (string chars, int i, string source, int j)
{
//               
assert (i>= 0 && j>= 0);
//                
//                                                                   
    if (chars.length() == i)
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
    cout << power2(2,100) << endl;
    cout << palindrome3("madam", 0, 4) << endl;
    cout << match_chars("abc", 0, "It is a classy bag ", 0) << endl;
}

