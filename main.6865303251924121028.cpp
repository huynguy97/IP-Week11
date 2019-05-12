#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/*
                                                  

                            

                                                  

                                          
                                          

                                                  
*/

//                      
double power1(double x, int n)
{//               
    assert(n >= 0);
 //                
 //              
    if (n == 0)
        return 1;
    else
        return x * power1(x, n-1);
}

//                                  
//                                                                          
double power2(double x, int n)
{//               
    assert(n >= 0);
 //                
 //              
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        double s = power2(x, n/2);
        return s * s;
    }
    else
        return x * power2(x, n-1);
}

//                               
bool palindrome1 (string text, int i, int j)
{//               
    assert(i >= 0 && j >=0);
 //                
 //                                                                                     
    if (i >= j)
        return true;
    else if (text[i] == text[j])
        return palindrome1(text, i+1, j-1);
    else
        return false;
}

char to_lowercase(char c)
{//               
    assert(true);
 //                
 //                                                                       
    if (c >= 65 && c <= 90)
        c += 32;

    return c;
}

//                               
bool palindrome2 (string text, int i, int j)
{//               
    assert(i >= 0 && j >=0);
 //                
 //                                                                                     
    if (i >= j)
        return true;
    else if (to_lowercase(text[i]) == to_lowercase(text[j]))
        return palindrome2(text, i+1, j-1);
    else
        return false;
}

bool char_is_acceptable(char c)
{//               
    assert(true);
 //                
 //                                                                               
    return !(c == ' ' || c == '.' || c == ',' || c == ':' || c == ';' || c == '\'' || c == '!' || c == '?' || c == '-');
}

//                               
bool palindrome3 (string text, int i, int j)
{//               
    assert(i >= 0 && j >=0);
 //                
 //                                                                                     
    if (i >= j)
        return true;
    else if (!char_is_acceptable(text[i]))
        return palindrome3(text, i+1, j);
    else if (!char_is_acceptable(text[j]))
        return palindrome3(text, i, j-1);
    else if (to_lowercase(text[i]) == to_lowercase(text[j]))
        return palindrome3(text, i+1, j-1);
    else
        return false;
}

//                                        
bool match_chars (string chars, int i, string source, int j)
{//               
    assert(i >= 0 && j >=0);
 //                
 //                                                                                                                                                                             
    if (i >= chars.length())
        return true;
    else if (j >= source.length())
        return false;
    else if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
    cout << "Part 1: Power" << endl;
    cout << "42 ^ 37 = " << power1(42, 37) << " according to power1." << endl;
    cout << "37 ^ 42 = " << power2(37, 42) << " according to power2." << endl << endl;

    cout << "Part 2: Palindromes" << endl;
    string pali = "No lemon? No melon.";
    cout << "Is " << pali << " a palindrome according to palindrome1? " << palindrome1(pali,0, pali.length()-1) << endl;
    cout << "Is " << pali << " a palindrome according to palindrome2? " << palindrome2(pali,0, pali.length()-1) << endl;
    cout << "Is " << pali << " a palindrome according to palindrome3? " << palindrome3(pali,0, pali.length()-1) << endl << endl;

    cout << "Part 3: Matching characters in a string" << endl;
    string chars = "Characters";
    string source = "Cars have rolled around since the beginning of our universe.";
    cout << "The result of match_chars(\"" << chars << "\", 0 , \"" << source << "\", 0) is " << match_chars(chars, 0, source, 0) << endl;
    return 0;
}

