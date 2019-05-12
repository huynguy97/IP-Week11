#include <iostream>
#include <cassert>
#include <cstring>
//                     
//                             

//                                                                                                                                                                                                    

using namespace std;

double power (double x, int n)
{
    //              
    assert (n>=0);
    //                                          
    if (n==0)
        return x=1;
    else return x*power(x, n-1);
}

double efficient_power (double x, int n)
{
    //              
    assert (n>=0);
    //                                                                                                        
    if (n==0)
        return x=1;
    else if (n%2==0)
    {
        double k = efficient_power(x, n/2);
        return k*k;
    }
    else return x*efficient_power(x, (n-1));
}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert (i>=0 && j>=0 && i<=text.length() && j<=text.length());
    //                                                                     
    if (i>=j)
        return true;
    else if (text[i]==text[j])
        return palindrome1(text, i+1, j-1);
    else return false;
}

bool palindrome2 (string text, int i, int j)
{
    //              
    assert (i>=0 && j>=0 && i<=text.length() && j<=text.length());
    //                                                                                                              
    int char_value_i, char_value_j;
    char_value_i = static_cast<int>(text[i]);
    char_value_j = static_cast<int>(text[j]);
    if (i>=j)
        return true;
    else if (char_value_i==char_value_j)
        return palindrome2(text, i+1, j-1);
    else if (char_value_i+32==char_value_j || char_value_i-32==char_value_j)
        return palindrome2(text, i+1, j-1);
    else return false;
}

void remove_punctuation (string& text)
{
    //              
    assert (true);
    //                                                         
    for (int i = 0, textlength = text.size(); i < textlength; i++)
    {
        if (ispunct(text[i]))
        {
            text.erase(i--, 1);
            textlength = text.size();
        }
    }
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert (i>=0 && j>=0 && i<=text.length() && j<=text.length());
    //                                                                                                                                                                                                                  
    remove_punctuation(text);
    int char_value_i, char_value_j;
    char_value_i = static_cast<int>(text[i]);
    char_value_j = static_cast<int>(text[j]);
    if (char_value_i >=65 && char_value_i <=90)
        char_value_i = char_value_i+32;
    if (char_value_j >=65 && char_value_j <=90)
        char_value_j = char_value_j+32;
    if (i>=j)
        return true;
    else if (char_value_i==char_value_j)
        return palindrome3(text, i+1, j-1);
    else return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    //              
    assert (i>=0 &&j>=0 && i<=chars.length() && j<=source.length());
    //                                                                                                      
    //                                                                                   
    if (i>=chars.length())
        return true;
    for (; j<source.length(); j++)
        if (chars[i]==source[j])
            return match_chars(chars, i+1, source, j);
    return false;

}

int main()
{
    cout << "Hello world!" << endl;
    cout << power(5,3) << endl;
    cout << efficient_power(5,5) << endl;
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome3("Otto!!&", 0, 3) << endl;
    cout << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    return 0;
}

