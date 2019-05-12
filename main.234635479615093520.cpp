#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

//                               
//                              

//    
//                                           

int power(int x, int n)
{
    assert(n >= 0 );
    //               
    //                            
    if(n == 0)
        return 1;
    else if (n > 0)
        return x * power(x, n-1);
}

int power_2(int x, int n)
{
    assert(n >= 0);
    //                                             
    if(n==0)
        return 1;
    else if(n % 2 ==  1)
        return power(x, (n-1)/2) * power(x, (n-1)/2)  * power(x,1);
    else if(n % 2 == 0)
        return power(x, (n-1)/2) * power(x, (n-1)/2);
}

bool palindrome1(string text, int i, int j)
{
    assert(i>=0 && j<= text.length());
    //               
    //                                                       
    if(i > j)
        return true;
    else if(text[i] == text[j])
        palindrome1(text, i+1, j-1);
    else
        return false;

}

bool palindrome2(string text, int i, int j)
{
    assert(i>=0 && j<= text.length());
    //               
    //                                                                                                        
    if(i > j)
        return true;
    else if(tolower(text[i]) == tolower(text[j]))
        palindrome1(text, i+1, j-1);
    else
        return false;
}

bool palindrome3(string text, int i, int j)
{
    assert(i>=0 && j<= text.length());
    //               
    //                                                                                                                                    
    if(i > j)
        return true;
    else if(ispunct(text[i]))
        palindrome3(text, i+1, j);
    else if(ispunct(text[j]))
        palindrome3(text, i, j-1);
    else if(tolower(text[i]) == tolower(text[j]))
        palindrome1(text, i+1, j-1);
    else
        return false;
}

bool match_chars(string chars, int i, string source, int j)
{
    assert(i>=0 && j>= 0);
    //               
    //                               
    cout <<i<< '\t' << j<<endl;
    cout << source.length()<<endl;
    cout << chars.length()<<endl;
    if(i > chars.length()-1 )
        return true;
    else if(j >= source.length()-1)
        return false;
    else if(chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else if(chars[i] != source[j])
    {
        return match_chars(chars, i, source, j+1);

    }

}

int main() {
//                                
//                            
    if(match_chars ("abc", 0, "It is a bag of books", 0))
        cout << "true";
    else
        cout << "false";

    return 0;
}

