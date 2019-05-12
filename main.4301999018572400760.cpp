#include <iostream>
#include <cassert>

using namespace std;

//                                                                      

int power_1 (int x, int n)
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
        return x * power_1(x,n-1);
    }
}

int power_2 (int x, int n)
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
        if (n%2==0)
        {
            int halve_power = power_2(x, (n/2));
            return halve_power * halve_power;
        }
        else
        {
            return x * power_2(x,n-1);
        }
    }
}

bool same_letter(char a, char b)
{
//             
assert(true);
//              
//                                                                                                                 

    int asciiA = static_cast<int>(a);
    int asciiB = static_cast<int>(b);

    if (asciiA>= 65 && asciiA <= 90)
        asciiA = asciiA + 32;

    if (asciiB>= 65 && asciiB <= 90)
        asciiB = asciiB + 32;

    return (asciiA == asciiB);
}

bool palindrome1 (string text, int i, int j)
{
//             
assert((i >= 0) && (j >= 0));
//              
//                                                                                                                                                
//                                                                                                                                                         
//                                                                   
    if (i + (j-i) == 1)
        return true;
    if (i+1 == j)
    {
        return (text.at(i)==text.at(j));
    }
    else
    {
        if (text.at(i)==text.at(j))
            return palindrome1(text, i+1, j-1);
        else
        {
            return false;
        }
    }
}

bool palindrome2 (string text, int i, int j)
{
//             
assert((i >= 0)&&(j >= 0));
//              
//                                                                                                                                                            
//                                                                                                                      
    if (i + (j-i) == 1)
        return true;
    if (i+1 == j)
    {
        return (same_letter(text.at(i), text.at(j)));
    }
    else
    {
        if (same_letter(text.at(i), text.at(j)))
            return palindrome2(text, i+1, j-1);
        else
        {
            return false;
        }
    }
}

bool ignore_char (char a)
{
//             
assert(true);
//              
//                                                                             
    int asciiA = static_cast<int>(a);

    if (asciiA >= 32 && asciiA <= 47)
    {
        return true;
    }
    return false;
}

bool palindrome3 (string text, int i, int j)
{
//             
assert((i >= 0)&&(j >= 0));
//              
//                                                                                                                                                
//                                                                                                                                        
//                                                                                                                                                           
    if (i + (j-i) == 1)
        return true;
    if (i+1 == j)
    {
        return (same_letter(text.at(i), text.at(j)));
    }
    else
    {
        if (ignore_char(text.at(i)))
            return palindrome3(text, i+1, j);
        if (ignore_char(text.at(j)))
            return palindrome3(text, i, j-1);
        if (same_letter(text.at(i), text.at(j)))
            return palindrome3(text, i+1, j-1);
        else
        {
            return false;
        }
    }
}

bool match1char (char a, char b)
{
//             
assert(true);
//              
//                                                                              
    return (a == b);
}

bool match_chars(string chars, int i, string source, int j)
{
//             
assert((i >= 0)&&(j >= 0));
//              
//                                                                                                                                                   
//                                                                                                                                                    
//                                                                                                                           
    if(i == chars.length())
    {
        return true;
    }
    else
    {
        if(j > source.length())
        {
            return false;
        }
        if(match1char(chars[i], source[j]))
        {
            return match_chars(chars, i+1, source, j+1);
        }
        if(!match1char(chars[i], source[j]))
        {
            return match_chars(chars, i, source, j+1);
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    cout << power_1(5,5)<< ", must be: 3125" << endl;
    cout << power_2(5,5)<< ", must be: 3125" <<endl;
    cout << palindrome1("legovogel", 0, 8)<< ", must be: 1" << endl;
    cout << palindrome1("lepels", 0, 5)<< ", must be: 0" << endl;
    cout << palindrome2("leGovogel", 0, 8)<< ", must be: 1" << endl;
    cout << palindrome2("lePels", 0, 5)<< ", must be: 0" << endl;
    cout << palindrome3("leGovogel!", 0, 9)<< ", must be: 1" << endl;
    cout << palindrome3("  ", 0, 1)<< ", must be: 1" << endl;
    cout << palindrome3("lePels", 0, 5)<< ", must be: 0" << endl;
    cout << match_chars("abc", 0, "It is a bag of cards", 0)<< ", must be: 1"<< endl;
    cout << match_chars("kz", 0, "It is a bag of cards", 0)<< ", must be: 0"<< endl;
    return 0;
}

