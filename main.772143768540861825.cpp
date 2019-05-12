#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                                                        

double power(int n, double x)
{
    assert(n >= 0);
    //                
    //                    
    if(n == 0)
        return 1;
    else if(n > 0)
    {
        double i = power(n-1,x);
        return x * i;
    }
}

double power_eff(int n, double x)
{
    assert(n >= 0);
    //                  
    //                    
    if (n == 0)
        return 1;
    else if(n % 2 ==0)
        return power(2,power(n/2,x));
    else
        return x * power(n-1,x);
}
bool palindrome1(string text, int i, int j)
{
    assert(i <= j && i >= 0 && j >= 0);
    //                
    //                                                                                                                     
    if(i + 1 == j || i == j)
    {
        if(text[i] == text[j])
            return true;
        else
            return false;
    }
    else
    {
        if(text[i] == text[j])
            return palindrome1(text,i+1,j-1);
        else
            return false;
    }
}
bool palindrome2(string text, int i, int j)
{
    assert(i <= j && i >= 0 && j >= 0);
    //                
    //                                                                                                                 
    if(i + 1 == j || i == j)
    {
        if(tolower(text[i]) == tolower(text[j])) //                                                                                      
            return true;
        else
            return false;
    }
    else
    {
        if(tolower(text[i]) == tolower(text[j]))
            return palindrome2(text,i+1,j-1);
        else
            return false;
    }
}
bool palindrome3(string text, int i, int j)
{
    assert(i <= j && i >= 0 && j >= 0);
    //                
    //                                                                                                                 
    if(!isalpha(text[i]))
        return palindrome3(text,i+1,j);
    if(!isalpha(text[j]))
        return palindrome3(text,i,j-1);
    if(i + 1 == j || i == j)
    {
        if(tolower(text[i]) == tolower(text[j]))
            return true;
        else
            return false;
    }
    else
    {
        if(tolower(text[i]) == tolower(text[j]))
        {
            return palindrome3(text,i+1,j-1);
        }

        else
            return false;
    }
}
bool match_chars(string chars, int i, string source, int j)
{
    assert(i >= 0 && j >= 0);
    //                
    //                                                                                                                                   
    //                                                    
    if (i == chars.length())
        return true;
    if (j == source.length())
        return false;
    if(!isalpha(chars[i]))
        return match_chars(chars,i+1,source,j);
    if(!isalpha(source[j]))
        return match_chars(chars,i,source,j+1);
    if(source[j] != chars[i])
    {
        for(int k = i+1; k < chars.length();k++)
        {
            if(source[j] == chars[k])
                return false;
        }
        return match_chars(chars,i,source,j+1);
    }
    else
        return match_chars(chars,i+1,source,j+1);
}
int main()
{
    cout << "Which number do you want to power?" << endl;
    double power_x;
    cin >> power_x;
    cout << "By which power (please enter integer)?" << endl;
    int power_power;
    cin >> power_power;
    cout << "The result is: " << power_eff(power_power, power_x) << endl;
}

