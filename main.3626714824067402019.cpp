#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//                              
//                              

double power(double x, int n)
{
    //              
    assert(n >= 0);
    //                                                    

    if (n == 0)
        return 1;
    if (n > 0)
        return x * power(x, n-1);
}

double power_2(double x, int n)
{
    //              
    assert(n >= 0);
    //                                                                                        

    if (n == 0)
        return 1;

    if (n % 2 == 1)
        return x * power(x, n / 2) * power(x, n / 2);
    return power(x, n / 2) * power(x, n / 2);
}

bool palindrome1(string text, int i, int j)
{
    //              
    assert(true);
    //                                                                                   

    cout << "i: " << i << "\t" << "j: " << j << endl;
    cout << text[i] << "\t" << text[j]<<endl;
    if (i <= j) {
        if (text[i] == text[j])
            return palindrome1(text, i + 1, j - 1);
    }
    else
        return true;
}

bool palindrome2(string text, int i, int j)
{
    //              
    assert(true);
    //                                                                                                                             
    //                                                                         

    if (int(text[i]) > 64 && int(text[i]) < 91)
    text[i] = int(text[i]) + 32;
    if (int(text[j]) > 64 && int(text[j]) < 91)
    text[j] = int(text[j]) + 32;
    if (i < j) {
        if (text[i] == text[j])
            return palindrome1(text, i + 1, j - 1);
    }
    else
        return true;
}

bool palindrome3(string text, int i, int j)
{
    //              
    assert(true);
    //                                                                                                                             
    //                                                                                                        
    //                                                                                       

    while (int(text[i]) > 31 && int(text[i]) < 48)
    i++;
    while (int(text[j]) > 31 && int(text[j]) < 48)
    j--;

    if (int(text[i]) > 64 && int(text[i]) < 91)
    text[i] = int(text[i]) + 32;
    if (int(text[j]) > 64 && int(text[j]) < 91)
    text[j] = int(text[j]) + 32;
    if (i < j) {
        if (text[i] == text[j])
            return palindrome3(text, i + 1, j - 1);
    }
    else
        return true;
}

bool match_chars(string chars, int i, string source, int j)
{
    //              
    assert(true);
    //                                                                                                           
    //                                                                                       

    if (int(source[j]) > 64 && int(source[j]) < 91)
    source[j] = int(source[j]) + 32;

    if (j >= source.size())
        return false;
    if (i < chars.size()) {
        if (chars[i] == source[j])
            return match_chars(chars, i + 1, source, j + 1);
        if (chars[i] != source[j])
            return match_chars(chars, i, source, j + 1);
    }
    else
        return true;
}

int main()
{
    double x = 0.0;
    int n = 0;
    cout << "Please enter a number" << endl;
    cin >> x;
    cout << "To which power?" << endl;
    cin >> n;
    cout << power_2(x, n) << endl << endl;

    string text = "empty";
    cout << "Enter your palindrome." << endl;
    cin >> text;
    if (palindrome3(text, 0, (text.size()-1)))
        cout << "This is a palindrome"<<endl<<endl;
    else
        cout << "This isn't a palindrome"<<endl << endl;

    if(match_chars("abc", 0, "It is a bag of cards", 0))
        cout << "true"<<endl<<endl;
    else
        cout << "false"<<endl;

    return 0;
}
