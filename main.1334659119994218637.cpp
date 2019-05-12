//                                                 
//                                            

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

//                           
int power1(double x, int n)
{
    //            
    assert(n >= 0);
    //             
    //                                                                                
    //                                                                              

    if (n == 0)
        return 1;
    else
        return x * power1(x, n-1);
}

//                                       
int power2(double x, int n)
{
    //            
    assert(n >= 0);
    //             
    //                                                        

    if (n ==0)
        return 1;
    else
    {
        if ((n % 2) == 0)
            return power2(x, n/2) * power2(x, n/2);
        else
            return x * power2(x, n/2) * power2(x, n/2);
    }
}

//                                    
bool palindrome1(string text, int i, int j)
{
    //            
    assert(i >= 0 && j >= 0 && i < text.length() && j < text.length());
    //             
    //                                                                              

    if (j <= i)
        return true;

    else if (text[i] == text[j])
        return palindrome1(text, i+1, j-1);
    else
        return false;
}

//                                            
bool palindrome2(string text, int i, int j)
{
    //            
    assert(i >= 0 && j >= 0 && i < text.length() && j < text.length());
    //             
    //                                                                                                                                    
    //                                                                                                                              

    if (j <= i)
        return true;

    else if (tolower(text[i]) == tolower(text[j]))
        return palindrome2(text, i+1, j-1);
    else
        return false;
}

//                                                      
bool punctuation(string text, int c)
{
    //            
    assert(true);
    //             
    //                                                                                                      

    if (text[c] == ' ' || text[c] == '.' || text[c] == ',' || text[c] == ':' || text[c] == ';' || text[c] == '\'' || text[c] == '!' || text[c] == '?' || text[c] == '-')
        return true;
    else
        return false;
}

bool palindrome3(string text, int i, int j)
{
    //            
    assert(i >= 0 && j >= 0 && i < text.length() && j < text.length());
    //             
    //                                                                                                                               
    //                                                                                                                                  
    //                                                        

    if (j <= i)
        return true;

    else if (punctuation(text, i))
        return palindrome3(text, i+1, j);
    else if (punctuation(text, j))
        return palindrome3(text, i, j-1);
    else if (tolower(text[i]) == tolower(text[j]))
        return palindrome3(text, i+1, j-1);
    else
        return false;
}

//                                             
bool match_chars(string chars, int i, string source, int j)
{
    //            
    assert(i >= 0 && j >= 0 && i < chars.length() && j < source.length());
    //             
    //                                                                                                                               
    //                                                                                

    if (chars[i] != source[j] && j == source.length()-1)
        return false;
    if (chars[i] == source[j] && i == chars.length()-1)
        return true;

    else if (chars[i] != source[j])
    {
        if (j < source.length()-1)
            return match_chars(chars, i, source, j+1);
    }
    else if (chars[i] == source[j])
    {
        if (i < chars.length()-1)
            return match_chars(chars, i+1, source, j);
    }
}

int main()
{
    cout << "***power1***" << endl;
    cout << power1(5,5) << endl;
    cout << power1(5,0) << endl;
    cout << endl;

    cout << "***power2***" << endl;
    cout << power2(5,5) << endl;
    cout << power2(5,0) << endl;
    cout << endl;

    cout << "***palindrome1***" << endl;
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome1("Otto", 0, 3) << endl;
    cout << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << endl;

    cout << "***palindrome2***" << endl;
    cout << palindrome2("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << endl;

    cout << "***palindrome3***" << endl;
    cout << palindrome3("otto", 0, 3) << endl;
    cout << palindrome3("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << endl;

    cout << "***match_chars***" << endl;
    cout << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars("abc", 0, "It is a bag of books", 0) << endl;
    cout << match_chars("abc", 0, "It is a classy bag", 0) << endl;

    return 0;
}

