//              
//                            

#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)           //                             
{//              
    assert(n >= 0);

    if(n <= 0) return 1;
    else return x * power(x, n - 1);
    //               
    //             
}

int power(int x, int n)                 //                             
{//              
    assert(n >= 0);

    if(n <= 0) return 1;
    else return x * power(x, n - 1);
    //               
    //             
}

double powerImproved(double x, int n)   //                                   
{//              
    assert(n >= 0);

    if(n <= 0) return 1;
    else
    {
        if(n % 2 == 0) return powerImproved(powerImproved(x, n/2), 2);
        else return powerImproved(powerImproved(x, n/2), 2) * x;
    }
    //               
    //             
}

int powerImproved(int x, int n)         //                                   
{//              
    assert(n >= 0);

    if(n <= 0) return 1;
    else
    {
        if(n % 2 == 0) return powerImproved(powerImproved(x, n/2), 2);
        else return powerImproved(powerImproved(x, n/2), 2) * x;
    }
    //               
    //             
}

bool palindrome1 (string text, int i, int j)
{//              
    assert(i >= 0 && j >= 0);

    if(i >= j) return true;
    else
    {
        if(text[i] == text[j]) return palindrome1(text, i+1, j-1);
        else return false;
    }
    //               
    //                                                                                                         
}

bool palindrome2 (string text, int i, int j)
{//              
    assert(i >= 0 && j >= 0);

    if(i >= j) return true;
    else
    {
        char a = text[i];
        cout << a << endl;
        char b = text[j];
        cout << b << endl;
        if(a >= 90) a -= 32;
        cout << a << endl;
        if(b >= 90) b -= 32;
        cout << b << endl;
        if(a == b) return palindrome2(text, i+1, j-1);
        else return false;
    }
    //               
    //                                                                                                           
}

bool isLetter(char c)
{//              
    assert(true);

    return (c >= 65 && c <= 90 || c >= 97 && c <= 122);
    //               
    //                            
}

bool palindrome3 (string text, int i, int j)
{//              
    assert(i >= 0 && j >= 0);

    while(!isLetter(text[i]))
        i++;

    while(!isLetter(text[j]))
        j--;

    if(i >= j) return true;
    else
    {
        char a = text[i];
        char b = text[j];
        cout << a << " - " << b << endl;
        if(a >= 90) a -= 32;
        if(b >= 90) b -= 32;
        cout << a << " - " << b << endl;
        if(a == b) return palindrome3(text, i+1, j-1);
        else return false;
    }
    //               
    //                                                            
    //                                                                                       
}

bool match_chars (string chars, int i, string source, int j)
{//              
    assert(i >= 0 && j >= 0);

    if(i >= chars.length()) return true;
    else
    {
        while((chars[i] != source[j]) && j < source.length())
            j++;
        if(j == source.length()) return false;
        else return match_chars(chars, i+1, source, j+1);
    }
    //               
    //                                                                                                                
}

int main()
{

    return 0;
}

