/*                                                 
                         
                                    
                                                  
                                                 */

#include <iostream>
#include <cassert>

using namespace std;

/*             
                          */
int power(int x, int n)
{
    //                 
    assert(n >= 0);
    //                  
    //                            
    if (x == 0)
        return 1;
    else if (n == 1)
        return n;
    else
        return x * power(x, --n);
}

/*             
                                                                    
                                            */
int superpower(int x, int n)
{
    //                 
    assert(n >= 0);
    //                  
    //                            
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else if (n % 2 == 0)
        return superpower(x, n/2) * superpower(x, n/2);
    else
        return x * superpower(x, --n);
}

bool palindrome1 (string text, int i, int j)
{
    //                 
    assert(true);
    //                  
    //                                                     
    //                         
    if (i > j)
        return true;
    else if (text[i] == text[j])
        return palindrome1(text, ++i, --j);
    else
        return false;
}

/*                      
                          */
bool same(char a, char b)
{
    //                 
    assert(true);
    //                  
    //                                                     
    //                                           
    //                         
    return (a == b ||
           (a >= 'A' && a <= 'Z' && a + 32 == b) ||
           (b >= 'A' && b <= 'Z' && b + 32 == a));
}

bool palindrome2 (string text, int i, int j)
{
    //                 
    assert(i >= 0 && j < text.length());
    //                  
    //                                                     
    //                                                       
    //                         
    if (i > j)
        return true;
    else if (same(text[i], text[j]))
        return palindrome2(text, ++i, --j);
    else
        return false;
}

bool ispunc(char c) {
    //                 
    assert(true);
    //                  
    //                                                                    
    //                         
    switch(c)
    {
        case ' ':
        case '.':
        case ',':
        case ':':
        case ';':
        case '\\':
        case '!':
        case '?':
        case '-':
            return true;
        default:
            return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    //                 
    assert(i >= 0 && j <= text.length());
    //                  
    //                                                     
    //                                                                                                    
    //                         
    if (i > j)
        return true;
    else if(ispunc(text[i]))
        return palindrome3(text, ++i, j);
    else if (ispunc(text[j]))
        return palindrome3(text, i, --j);
    else if (same(text[i], text[j]))
        return palindrome3(text, ++i, --j);
    else
        return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    //                 
    assert(true);
    //                  
    //                                                                                                                    
    //                                                           
    //                          
    if (i >= chars.length())
        return true;
    else if (j >= source.length())
        return false;
    else if(chars[i] == source[j])
        return match_chars (chars, ++i, source, j);
    else
        return match_chars (chars, i, source, ++j);
}

int main() {
//                            
//                       
//                                        
//                                         
//                                        
//                                                             
    return 0;
}

