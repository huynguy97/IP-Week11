#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//                          
//                         

double power (double x, int n)
{
    //                                                   
    assert(n >= 0);
    //              
    //                                                                  
    //             

    if (n == 0)
        return 1;
    return x * power(x, n-1);
}

double eff_power (double x, int n)
{
    //              
    assert(n >= 0);
    //              
    //                                                                  
    //                                                                     

    //                                       

    if (n == 0)
        return 1;
    else if (n % 2 == 0 && n / 2 > 1)
        return eff_power (eff_power(x, n / 2), 2);
    else return x * eff_power (x, n - 1);
}

void power_display()
{
    //             
    assert(true);
    //               
    //                                                                                              
    //                                                                                                     
    //                      

    bool action = true;
    double x;
    int n;
    char q;
    while(action)
    {
        cout << "Please fill in x and n: ";
        cin >> x
            >> n;
        cout << x << " to the power " << n
             << " is equal to " << eff_power(x,n) << endl;
        cout << "Do you want to enter another power? y/n: ";
        cin >> q;
        if (q != 'y')
            action = false;
    }
}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    assert(i <= j);
    //               
    //                                              
    //                                         

    if (text[i] != text[j])
        return false;
    else if (i+1 <= j-1)
        return palindrome1(text, i + 1, j - 1);
    else return true;
}

bool palindrome2 (string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    assert(i <= j);
    //               
    //                                                  
    //                                                     

    if (!(text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j]))
        return false;
    else if (i+1 <= j-1)
        return palindrome2 (text, i + 1, j - 1);
    else return true;
}

bool next_char(char c, int& i, int& j, bool reduce)
{
    //              
    assert( i >= 0 && j >= 0);
    assert (i <= j);
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
        case '\'':
        case '!':
        case '?':
        case '-':
            {
                if(reduce && j-1 >= i)
                {
                    j--;
                    return true;
                }
                else if (i+1 <= j)
                {
                    i++;
                    return true;
                }
                return false;
            }
        default: return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    assert(i <= j);
    //               
    //                                                  
    //                                                                                    

    //                           
    while(next_char(text[i], i, j, false));
    while(next_char(text[j], i, j, true));
    if (!(text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j]))
        return false;
    else if (i+1 <= j-1)
        return palindrome3 (text, i + 1, j - 1);
    return true;
}

void palindromes(string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    assert(i <= j);
    //               
    //                                                                      
    //                      
    if(palindrome1(text, i, j))
        cout << "palindrome1 is true\n";
    else cout << "palindrome1 is false\n";
    if(palindrome2(text, i, j))
        cout << "palindrome2 is true\n";
    else cout << "palindrome2 is false\n";
    if(palindrome3(text, i, j))
        cout << "palindrome3 is true\n";
    else cout << "palindrome3 is false\n";
}

bool match_chars(string chars, int i, string source, int j)
{
    //               
    assert(i >= 0);
    assert(j >= 0 && j <= static_cast<int>(source.length()-1));
    //                
    //                                                                                                                                        

    if(i > static_cast<int>(chars.length()-1))
        return true;
    for(; j < static_cast<int>(source.length()); j++)
        if(chars[i] == source[j])
            return match_chars(chars, i+1, source, j);
    return false;
}

int main()
{
    power_display();
    palindromes("abba", 0, 3);
    if(match_chars("abc", 0, "It is a bag of chips", 0))
        cout << "It matches!";
    else cout << "Nay! No match has been found" << endl;
    return 42;
}

