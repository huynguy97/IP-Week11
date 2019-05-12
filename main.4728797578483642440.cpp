#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

double power (double x, int n)
{//               
    assert ( n >= 0 ) ;
//                 
//                                            
    if ( n <= 0 )
        return 1;
    else
        return x * power (x, --n) ;
}
double powerplus (double x, int n)
{//               
    assert ( n >= 0 ) ;
//                 
//                                                 
//                                                                                     
    if ( n <= 0 )
        return 1;
    else
    {
        if ( n%2 == 1 )
        {
            n = (n - 1)/2;
            return x * powerplus (x, n) * powerplus (x, n);
        }
        else
        {
            n = n/2 ;
            return powerplus (x, n) * powerplus (x,n) ;
        }
    }
}

bool palindrome1 (string text, int i, int j)
{//               
    assert (i >= 0 && j >= 0 && j >= i) ;
//                 
//                                                                                 
    if (j == i || j - i == 1 && text[i] == text[j]  )
        return true;
    else if (text [i] == text[j])
        return palindrome1(text, ++i, --j) ;
    return false;
}

bool palindrome2 (string text, int i, int j)
{//               
    assert (i >= 0 && j >= 0 && j >= i) ;
//                 
//                                                      
    if (j == i || (j - i == 1 && text[i] == text[j]) || (j - i == 1 && text[i] == text[j] - 32) || (j - i == 1 && text[i] == text[j] + 32)  )
        return true;
    else if (text [i] == text[j] || text[i] == text[j] + 32 || text [i] == text[j] - 32)
        return palindrome2(text, ++i, --j) ;
    return false ;
}

bool palindrome3 (string text, int i, int j)
{//               
    assert (i >= 0 && j >= 0 && j >= i) ;
//                 
//                                                                                          
    if (text [i] < 65 || text[i] > 122 || text[i] > 90 && text [i] < 97)
            return palindrome3 (text, ++i, j) ;
    if (text [j] > 122 || text[j] < 65 || text[j] > 97 && text[j] < 97)
            return palindrome3 (text, i, --j) ;
    if (j == i || (j - i == 1 && text[i] == text[j]) || (j - i == 1 && text[i] == text[j] - 32) || (j - i == 1 && text[i] == text[j] + 32)  )
        return true;
    else if (text [i] == text[j] || text[i] == text[j] + 32 || text [i] == text[j] - 32)
        return palindrome3(text, ++i, --j) ;
    return false;
}

bool match_chars (string chars, int i, string source, int j)
{//               
    assert (i >= 0 && j >= 0) ;
//                 
//                                                                    
    if ( i >= chars.length())
        return true;
    if ( j >= source.length())
        return false;
    else
    {
        if (chars [i] == source [j])
            return match_chars (chars, ++i, source, ++j) ;
        else
            return match_chars (chars, i, source, ++j) ;
    }
}

int main()
{
    //       
    cout << "PART 1" << endl;
    double z = power (2.5, 4) ;
    double y = powerplus (2.5, 4) ;
    cout << "x is " << 2.5 << " n is " << 4 << endl;
    cout << "using the normal powerfunction: " << z << ", using the improved powerfunction: " << y << endl;

    //       
    cout << "PART 2" << endl;
    string text1 = "otto" ;
    string text2 = "Otto" ;
    string text3 = "Madam, I'm Adam." ;
    if (palindrome1 (text1, 0, 3))
        cout << "The text " << text1 << " is a palindrome in v1" << endl;
    if (palindrome2 (text1, 0, 3))
        cout << "The text " << text1 << " is a palindrome in v2" << endl;
    if (palindrome3 (text1, 0, 3))
        cout << "The text " << text1 << " is a palindrome in v3" << endl;
    if (palindrome1 (text2, 0, 3))
        cout << "The text " << text2 << " is a palindrome in v1" << endl;
    if (palindrome2 (text2, 0, 3))
        cout << "The text " << text2 << " is a palindrome in v2" << endl;
    if (palindrome3 (text2, 0, 3))
        cout << "The text " << text2 << " is a palindrome in v3" << endl;
    if (palindrome1 (text3, 0, 15))
        cout << "The text " << text3 << " is a palindrome in v1" << endl;
    if (palindrome2 (text3, 0, 15))
        cout << "The text " << text3 << " is a palindrome in v2" << endl;
    if (palindrome3 (text3, 0, 15))
        cout << "The text " << text3 << " is a palindrome in v3" << endl;

    //       
    cout << "PART 3" << endl;
    string chars = "abc" ;
    string source1 = "It is a bag of books" ;
    string source2 = "It is a bag of cards" ;
    string source3 = "It is a classy bag" ;
    if (match_chars(chars, 0, source1, 0))
        cout << "The string " << source1 << " contains the characters " << chars << endl;
    else
        cout << "The string " << source1 << " does not contain the characters " << chars << endl;
    if (match_chars(chars, 0, source2, 0))
        cout << "The string " << source2 << " contains the characters " << chars << endl;
    else
        cout << "The string " << source2 << " does not contain the characters " << chars << endl;
    if (match_chars(chars, 0, source3, 0))
        cout << "The string " << source3 << " contains the characters " << chars << endl;
    else
        cout << "The string " << source3 << " does not contain the characters " << chars << endl;
}

