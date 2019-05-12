//                              
//                                

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

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

double power2 (double x, int n)
{
    //                
    assert(n >= 0);

    //                 
    // 

    if (n == 0)
        return 1;
    else if (n % 2 != 0)
        return x * power2 (x, n-1);
    else
    {
        double z = power2(x, n/2);
        return z * z;
    }
}
//                                                                      

//       
bool palindrome1 (string text, int i, int j)
{
    //                
    assert(i >= 0 && j >= i-1);

    //                 
    //                                                                                                           
    //                                                          

    if (text [i] == text [j])
    {
        if (i >= j)
            return true;

        return palindrome1(text, ++i, --j);
    }
    else
        return false;
}

bool palindrome2 (string text, int i, int j)
{
    //                
    assert(i >= 0 && j >= i-1);

    //                 
    //

    char letter_i = text [i];
    char letter_j = text [j];

    if (letter_i == letter_j || (letter_i >= 'A' && letter_i <= 'Z' && letter_i + 32 == letter_j) || (letter_j >= 'A' && letter_j <= 'Z' && letter_j + 32 == letter_i))
    {
        if (i >= j)
            return true;

        return palindrome2(text, ++i, --j);
    }
    else
        return false;
}

bool punctuation_mark(char c)
{
    //                
    assert (true);

    //                 
    //

    switch (c)
    {
        case ' ': case '.': case ',': case ':': case ';': case '\'': case '!': case '?': case '-': return true;
        default: return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    //                
    assert(i >= 0 && j >= i-1);

    //                 
    //

    /*
                                              
                                                                                                                                                                                    
            

                                                                                                                                                                                    
            
    */

    //                          
    if (punctuation_mark(text [i]))
        return palindrome3 (text, ++i, j);

    if (punctuation_mark(text[j]))
        return palindrome3(text, i, --j);

    char char_i = text [i];
    char char_j = text [j];

    if (char_i == char_j || (char_i >= 'A' && char_i <= 'Z' && char_i + 32 == char_j) || (char_j >= 'A' && char_j <= 'Z' && char_j + 32 == char_i))
    {
        if (i >= j)
            return true;

        return palindrome3(text, ++i, --j);
    }
    else
        return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    //                
    assert (i < chars.length() && j < source.length());

    //                 
    //                                                                                                                                                                   
    //                                                                                                               

    if (chars[i] == source[j])
    {
        if (i == chars.length()-1)
            return true;
        else
            return match_chars(chars, ++i, source, ++j);
    }
    else
        if (j == source.length()-1)
            return false;
        else
            return match_chars(chars, i, source, ++j);
}

int main ()
{

    /*          
    */
    //       
    double number = 2;
    int power = 2;

    cout << "power1: " << power1(number, power) << endl;
    cout << "power2: " << power2(number, power) << endl;

    //       
    string test = "LepEl";
    string test2 = "Madam, I'm Adam.";

    cout << "palindrome1: " << palindrome1(test, 0, test.length() - 1) << endl;
    cout << "palindrome2: " << palindrome2(test, 0, test.length() - 1) << endl;
    cout << "palindrome3: " << palindrome3(test2, 0, test2.length() - 1) << endl;

    //       
    string sub = "acbbc";
    string source = "It is a bag of cards";

    cout << "Match: " << match_chars(sub, 0, source, 0) << endl;

    return 0;
}
