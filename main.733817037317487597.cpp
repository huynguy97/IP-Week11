#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

//                             

double naive_power (double x, int n)
{
//               
    assert(n >= 0);
//                                                                                 
    if (n == 0)
        return 1;

    return x * naive_power(x, n-1);
}

double power (double x, int n)      //                                                                                       
{                                   //                                                                                                              
//               
    assert(n >= 0);
//                                                                             

    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return power(x, n/2) * power (x, n/2);

    return x * power(x, n-1);
}

bool palindrome1 (string text, int i, int j)
{
//               
    assert(text.length() > 0);
//                                                                                                                                                
//                                                                          
    if (i >= j)
        return true;
    if (text[i] == text[j])
        return palindrome1(text, ++i, --j);
    else
        return false;
}

bool palindrome2 (string text, int i, int j)
{
//               
    assert(text.length() > 0);
//                                                                                                                                                
//                                                                                
    if (i >= j)
        return true;
    if (text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j])
        return palindrome2(text, ++i, --j);
    else
        return false;
}

bool palindrome3 (string text, int i, int j) //                                                                              
{
//               
    assert(text.length() > 0);
//                                                                                                                                                
//                                                                              
    if (i >= j)
        return true;
    if (text[i] <= 64 || text[i] == 92)
        return palindrome3(text, ++i, j);
    if (text[j] <= 64 || text[j] == 92)
        return palindrome3(text, i, --j);
    if (text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j])
        return palindrome3(text, ++i, --j);

    return false;
}

bool match_chars (string chars, int i, string source, int j)
{
//               
    assert(chars.length() > 0 && source.length() > 0);
//                                                                                                                       

    if (i == chars.length())
        return true;
    if (j == source.length())
        return false;
    if (chars[i] == source[j])
        return match_chars(chars, ++i, source, j);
    if (chars[i] != source[j])
        return match_chars(chars, i, source, ++j);
}

int main()
{//                                
    double x;
    int n;
    cout << "x: ";
    cin >> x;
    cout << "n: ";
    cin >> n;
    cout << x << "^" << n << " = " << power(x, n) << endl; //                                             

//                        
    string  text1 = "A man, a plan, a canal: Panama.",  //           
            text2 = "Racecar",                          //          
            text3 = "palindrome";                       //           

    cout << "\nIs '" << text1 << "' a palindrome?\t";
    if (palindrome3(text1, 0, 30))                          //                                           
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

//                        
    string chars = "NS";                                    //                                           
    string source = "Being on time";
    cout << "\nCan the letters of '" << chars << "' be found in '" << source << "'?\t";
    if (match_chars(chars, 0, source, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

