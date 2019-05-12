#include <iostream>
#include <cassert>

using namespace std;

//                             
//                        

int power(double x, int n)
{
    /*               */
    assert(x >= 0 && n >= 0);
    /*               
                                                                   
    */
    if(n == 0)
        return 1;
    else
    {
        return x * power(x, n-1);
    }
}

int eff_power(double x, int n)
{
    /*               */
    assert(x >= 0 && n >= 0);
    /*               
                                                                                            
                                   
    */

    //                             
    int k;
    if(n == 0)
        return 1;
    if(n%2==0)
    {
        k = eff_power(x, n / 2);
        return k*k;
    }
    else
    {
        return x * eff_power(x, n-1);
    }
}

bool palindrome1 (string text, int i, int j)
{
    /*               */
    assert(i >= 0 && j > i && j < text.length());
    /*               
                                                                                      
    */
    if(j <= i)
        return true;
    else{
        if (text[i] != text[j])
        return false;
        return palindrome1(text, i+1, j-1);
    }
}

bool palindrome2 (string text, int i, int j)
{
    /*               */
    assert(i >= 0 && j > i && j < text.length());
    /*               
                                                                  
                                                        
    */
    if(j <= i)
        return true;
    else{
        if (toupper(text[i]) != toupper(text[j]))
        return false;
        return palindrome2(text, i+1, j-1);
    }
}

bool special_char(char theChar)
{
    /*               */
    assert(true);
    /*               
                                                                                              
    */
    char special[] = {' ','.',',',':',';','\'','!','?','-'};
    for(int i = 0; i < 9; i++)
    {
        if(theChar == special[i])
            return true;
    }
    return false;
}

bool palindrome3 (string text, int i, int j)
{
    /*               */
    assert(i >= 0 && j < text.length());
    /*               
                                                                  
                                                                             
    */
    while(special_char(text[i]))
    {
        i++;
    }

    while(special_char(text[j]))
    {
        j--;
    }

    if(j <= i)
        return true;
    else{
        if (toupper(text[i]) != toupper(text[j]))
        return false;

        return palindrome3(text, i+1, j-1);
    }
}

bool match_chars (string chars, int i, string source, int j)
{
    /*               */
    assert(i >= 0);
    /*               
                                                                                          
                                             
    */
    bool foundLast = i == chars.length() - 1 && chars[i]==source[j];
    if(foundLast){
        return true;
    }
    else{
        if(chars[i]==source[j])
            i++;

        if(j == source.length())
            return false;

        j++;

        return match_chars(chars, i, source, j);
    }
}

int main()
{
    double x = 4;
    int n = 3;
    string chars = "abc";
    string source = "It is a bag of cards";
    string input = "Otto!";

    cout << "Efficient power function of " << x << " to the power of " << n << " = " << eff_power(x,n) << endl;
    cout << "Is " << input << " a palindrome?: " << palindrome3(input, 0, input.length()-1) << endl;
    cout << "Matching input?: " << match_chars(chars, 0, source, 0) << endl;
    return 0;
}

