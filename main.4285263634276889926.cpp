//                         
//                         

//             

#include <iostream>
#include <cassert>

using namespace std;

double enter_base (double& base)
{
//             
    assert (true);
//              
//                                                                       
    cout << "Hello, please give a base value: " << endl;
    cin >> base;
    return base;
}

int enter_power (int& power)
{
//             
    assert (true);
//              
//                                                                        
    cout << "Hello, please give the factor which is a nonnegative integer: " << endl;
    cin >> power;
    while (power < 0)
    {
        cout << "That is a negative integer... Please try again: " << endl;
        cin >> power;
    }
    return power;
}

//                                                                                                                                                                                                           
double naive_power (double base, int power)
{
//             
    assert (power >= 0);
//              
//                                                                         
    if (power == 0)
        return 1;
    else
    {
        return (base * naive_power (base,power-1));
    }
}

//                                                                                                                                                                                                           
double efficient_power (double base, int power)
{
//             
    assert (power >= 0);
//              
//                                                                         

    if (power == 0)
        return 1;
    else
    {
        if (power <=2 && power >0)
        {
            return efficient_power(base, power-1)*base;
        }
        else if (power%2 == 0)
        {
            double half_the_work = efficient_power(base,(power/2));
            return half_the_work * half_the_work;
        }
        else if (power%2 == 1)
        {
            double half_the_work = efficient_power(base,(power/2));
            return half_the_work * half_the_work * base;
        }
    }
//                                                        
}

//                                                                                                                                                                                                           
void string_input (string& text, char& whiteline)
{
//             
    assert (text.length() >=0);
//              
//                                                         
    cin.get (whiteline);
    cout << "Please enter a line of text, so we can test it on palindromes. " << endl;
    getline(cin, text);
}

bool palindrome1 (string text, int i, int j)
{
//             
//                               
    assert (i<=j && 0 <= i );
//              
//                                                                                         
    if (i == j || i+1 == j)
    {
        if (text[i] == text[j])
        {
            cout << "Yes! This word is a palindrome! " << endl;
            return true;
        }
        else
        {
            cout << "Jammer! Not a palingdroom! " << endl;
            return false;
        }
    }
    else
    {
        if (text[i] != text[j])
        {
            cout << "Jammer! Not a palingdroom! " << endl;
            return false;
        }
        else
            return palindrome1(text, i+1, j-1);
        //                            
    }

}

//                                                                                                                                                                                                            
bool palindrome2 (string text, int i, int j)
{
//             
    assert (i<=j && 0 <= i );
//              
//                                                                                         
    //                 
    //                 
    //                                     
    //                                      

    if (i == j || i+1 == j)
    {
        if (static_cast<char>(text[i]) > 90)
            text[i] -= 32;
        if (static_cast<char>(text[j]) > 90)
            text[j] -= 32;

        if (text[i] == text[j])
        {
            cout << "Cool! This word is a palindrome! " << endl;
            return true;
        }
        else
        {
            cout << "Oof! Not a palingdroom! " << endl;
            return false;
        }
    }
    else
    {
        if (static_cast<char>(text[i]) > 90)
            text[i] -= 32;
        if (static_cast<char>(text[j]) > 90)
            text[j] -= 32;

        if (text[i] != text[j])
        {
            cout << "Oof! Not a palingdroom! " << endl;
            return false;
        }
        else
            return palindrome2(text, i+1, j-1);
        //                            
    }

}

//                                                                                                                                                                                                            
bool palindrome3(string text,int i, int j)
{
//             
    assert (i<=j && 0 <= i );
//              
//                                                                                         
    //                 
    //                 
    //                                     
    //                                      

    if (i == j || i+1 == j)
    {
        if (static_cast<char>(text[i]) > 90)
            text[i] -= 32;
        if (static_cast<char>(text[j]) > 90)
            text[j] -= 32;

        if (static_cast<char>(text[i]) < 65 ||static_cast<char>(text[j]) < 65)
        {
            cout << "Nice! This word is a palindrome! " << endl;
            return true;
        }

        else if (text[i] == text[j])
        {
            cout << "Nice! This word is a palindrome! " << endl;
            return true;
        }
        else
        {
            cout << "Sike! Not a palingdroom! " << endl;
            return false;
        }
    }
    else
    {
        if (static_cast<char>(text[i]) > 90)
            text[i] -= 32;
        if (static_cast<char>(text[j]) > 90)
            text[j] -= 32;

        if (static_cast<char>(text[i]) < 65)
        {
            return palindrome3(text, i+1, j);
        }
        if (static_cast<char>(text[j]) < 65)
        {
            return palindrome3(text, i, j-1);
        }

        if (text[i] != text[j])
        {
            cout << "Sike! Not a palingdroom! " << endl;
            return false;
        }
        else
        {
            return palindrome3(text, i+1, j-1);
        }
        //                            
    }
}

//                                                                                                                                                                                                            
void match_chars_input (string& chars, string& source)
{

    cout << "Please enter the characters: " << endl;
    getline (cin, chars);
    cout << "Please enter the string of text: " << endl;
    getline (cin, source);
}

bool match_chars (string chars, int i, string source, int j)
{
//             
assert (0<= i && 0 <=j );
//              
//                                                                                                                

    if (i == chars.length())
    {
        cout << "Alles gevonden!" << endl;
        return true;
    }
    else if (j > source.length())
    {
        cout << "We hebben niet alles kunnen vinden of het zit niet in de goede volgorde...." << endl;
        return false;
    }
    else
    {
        for (int x = j; x < source.length(); x++)
        {
            if (source[x] == chars[i])
            {
                j = x+1;
                cout << "plek:" << x<< endl;
                return match_chars (chars, i+1, source, j);
            }
        }
    }
    cout << "We hebben niet alles kunnen vinden of het zit niet in de goede volgorde..." << endl;
    return false;

}

int main()
{
    int power = -100;
    double base = 0;
    enter_base(base);
    enter_power(power);
    cout << "Naive way: " << naive_power(base,power)<<endl;
    cout << "Efficient way: " << efficient_power (base,power) << endl;
    cin.clear();
    string chars, text;
    char whiteline;

    string_input (text,whiteline);
    int i = 0;
    int j = text.length();

    cout << "Palindrome 1: " << endl;
    cout << palindrome1(text, i, j)<< endl;
    cout << "Palindrome 2: " << endl;
    cout << palindrome2(text, i, j)<< endl;
    cout << "Palindrome 3: " << endl;
    cout << palindrome3(text, i, j) << endl;
    cin.clear();
    int k = 0;
    match_chars_input (chars,text);
    match_chars(chars, i, text, k);
    return 0;
}

