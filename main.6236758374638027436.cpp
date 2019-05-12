#include <iostream>
#include <cassert>

using namespace std;

int power (int x, int n)
{
    //             
    assert(n >= 0);
    //              
    if (n == 0)
        return 1;
    else
        return x * power(x,n-1);
}

bool palindrome1 (string text, int i, int j)
{
    //             
    assert(i >= 0 && j >=0);
    //              
    //                                
    if (i == j || j < i)
        return true;
    if (text[i] == text[j])
        return palindrome1(text, i+1, j-1);
    else
        return false;
}

bool palindrome2 (string text, int i, int j)
{
    //             
    assert(i >= 0 && j >=0);
    //              
    //                
    if (i == j || j < i)
        return true;

    //                                   
    if (int(text[i]) >= 65 && int(text[i]) <= 90 && int(text[j]) >= 65 && int(text[j]) <= 90)
    {
        if (text[i] == text[j])
            return palindrome2(text, i+1, j-1);
        else
            return false;
    }

    //                              
    else if (int(text[i]) >= 97 && int(text[i]) <= 122 && int(text[j]) >= 97 && int(text[j]) <= 122)
    {
        if (text[i] == text[j])
            return palindrome2(text, i+1, j-1);
        else
            return false;
    }

    //                                          
    else if (int(text[i]) >= 97 && int(text[i]) <= 122 && int(text[j]) >= 65 && int(text[j]) <= 90)
    {
        if (int(text[i])-32 == int(text[j]))
            return palindrome2(text, i+1, j-1);
        else
            return false;
    }

    //                                          
    else if (int(text[i]) >= 65 && int(text[i]) <= 90 && int(text[j]) >= 97 && int(text[j]) <= 122)
    {
        if (int(text[i])+32 == int(text[j]))
            return palindrome2(text, i+1, j-1);
        else
            return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    //             
    assert(i >= 0 && j >=0);
    //              
    //                     
    while ((int(text[i]) >= 32 && int(text[i]) <= 47) || (int(text[i]) >= 58 || int(text[i]) == 64))
        i++;
    while ((int(text[j]) >= 32 && int(text[j]) <= 47) || (int(text[j]) >= 58 || int(text[j]) == 64))
        j--;

    if (i == j || j < i)
        return true;

    //                                   
    if (int(text[i]) >= 65 && int(text[i]) <= 90 && int(text[j]) >= 65 && int(text[j]) <= 90)
    {
        if (text[i] == text[j])
            return palindrome3(text, i+1, j-1);
        else
            return false;
    }

    //                              
    else if (int(text[i]) >= 97 && int(text[i]) <= 122 && int(text[j]) >= 97 && int(text[j]) <= 122)
    {
        if (text[i] == text[j])
            return palindrome3(text, i+1, j-1);
        else
            return false;
    }

    //                                          
    else if (int(text[i]) >= 97 && int(text[i]) <= 122 && int(text[j]) >= 65 && int(text[j]) <= 90)
    {
        if (int(text[i])-32 == int(text[j]))
            return palindrome3(text, i+1, j-1);
        else
            return false;
    }

    //                                          
    else if (int(text[i]) >= 65 && int(text[i]) <= 90 && int(text[j]) >= 97 && int(text[j]) <= 122)
    {
        if (int(text[i])+32 == int(text[j]))
            return palindrome3(text, i+1, j-1);
        else
            return false;
    }
}

bool match (char sub, char source)
{//              
    assert (true) ;
/*                
                                                                                  
*/
    if (sub == source)
        return true;
    else return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(true);
    //              
    //             

    for (int x = j; x < source.size()-1; x++)
    {
        if (match(chars[i], chars[x]) && i < chars.size()-1)
            match_chars(chars, i++, source, x);
        cout << x << endl;
    }
    if (i == chars.size()-1)
        return true;
    else if (j == source.size()-1 && i < chars.size()-1)
        return false;
}

int main()
{
    //                                                
    //                                                   
    //                     
    bool part3 = match_chars("abc",0,"It is a bag of cards",0);
    //                                                               
    cout << part3 << endl;
    return 0;
}

