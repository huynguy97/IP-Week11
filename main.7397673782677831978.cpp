#include <iostream>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

//                           
//                         

//         
double power1 (double x, int n)
{
//                
    assert (n >= 0);
//                 
//                                     

    if (n == 0)
        return 1;
    else
        return x * power1(x, n-1);
}

//         
double power2 (double x, int n)
{
//                
    assert (n >= 0);
//                 
//                                                             

    if (n == 0)
        return 1;
    else
    {
        if (n % 2 == 0)
            return power2(x, n/2) * power2(x, n/2);
        return x * power2(x, n-1);
    }

}

bool palindrome1 (string text, int i, int j)
{
//                
    assert (i >= 0 && i < text.length() && j >= 0 && j < text.length());
//                 
//                                                                                    

    if (text[i] != text[j])
        return false;
    else if (text[i] == text[j] && i <= j)
        return palindrome1(text, i+1, j-1);
    else if (text[i-1] == text[j+1] && i > j)
        return true;
    return false;
}

bool palindrome2 (string text, int i, int j)
{
//                
    assert (i >= 0 && i < text.length() && j >= 0 && j < text.length());
//                 
//                                                                                    

    if (text[i] != text[j] && text[i] != text[j] - 32 && text[i] != text[j] + 32)
        return false;
    else if ((text[i] == text[j] || text[i] == text[j] - 32 || text[i] == text[j] + 32) && i < j)
        return palindrome2(text, i+1, j-1);
    else if (i >= j)
        return true;
    return false;
}

bool palindrome3 (string text, int i, int j)
{
//                
    assert (i >= 0 && i < text.length() && j >= 0 && j < text.length());
//                 
//                                                                                    

    if ((text[i] == 32 || text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == '-') && i < j)
        return palindrome3(text, i+1, j);
    if ((text[j] == 32 || text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-') && i < j)
        return palindrome3(text, i, j-1);
    if (text[i] != text[j] && text[i] != text[j] - 32 && text[i] != text[j] + 32)
        return false;
    else if ((text[i] == text[j] || text[i] == text[j] - 32 || text[i] == text[j] + 32) && i < j)
        return palindrome3(text, i+1, j-1);
    else if (i >= j)
        return true;
    return false;
}

bool match_chars (string chars, int i, string source, int j)
{
//                
    assert ( i >= 0 && j >= 0 && i < chars.length() && j < source.length());
//                 
//                                                                                                                                                  

    if (i == chars.length() - 1)
    {
        for (int y = j; y < source.length(); y++)
            if (chars[i] == source[y])
                return true;
        return false;
    }
    for (int x = j; x < source.length(); x++)
    {
        if (chars[i] == source[x])
            return match_chars(chars, i+1, source, x);
    }
}

int main()
{
    double x;
    int n, i, j;
    char text[80];
/*         
                                                             
             
                                                           
             
                                               
*/

/*         
                                                
                                
                                                                         
              
                                                                                        
             
                                
                                                 
        
                                                   
*/

//         
    if (match_chars ("abc", 0, "It is a bag of cards", 0))
        cout << "First is true\n";
    else
        cout << "First is false\n";
    if (match_chars ("abc", 0, "It is a bag of books", 0))
        cout << "Second is true\n";
    else
        cout << "Second is false\n";
    if (match_chars ("abc", 0, "It is a classy bag", 0))
        cout << "Third is true\n";
    else
        cout << "Third is false\n";

    return 0;
}

