#include <iostream>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

double power(double x, int n)
{
    //             
    assert(n >= 0);
    //              
    //                                              
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n-1);
    }
}

double power_2 (const double x, int n)
{
    //             
    assert(n >= 0);
    //              
    //                                                                                   
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0) //                                  
    {
        double m = power_2(x, n/2);
        return m * m;

    }
    else //                                     
    {

        return x * power_2(x, n-1);
    }

    //                                                                                                                                   
}

bool palindrome1 (string text, int i, int j)
{
//             
    assert(text.length() >= 1 && i>= 0 && i <=j);
//              
//                                                                  

    if (i == j)
    {
        return true;
    }

    else if(text[i] == text[j])
    {

        if(i + 1 > j - 1)
        {
            return true;
        }
        else
        {
            return palindrome1(text, i + 1, j - 1);
        }

    }
    else
    {
        return false;
    }
}

char toSmall(char a)
{
    //               
    assert(a >= 0 );
    //                                                           
    if (a >= 65 && a <= 90 )
    {
        return a += 32;
    }
    else
    {
        return a;
    }
}

bool palindrome2 (string text, int i, int j)
{
//             
    assert(text.length() >= 1 && i>= 0 && i <=j);
//              
//                                                                                                             
//                                                  
    char a = toSmall(text[i]);
    char b = toSmall(text[j]);

    if (i == j)
    {
        return true;
    }
    else if(a==b)
    {
        if(i + 1 > j - 1)
        {
            return true;
        }
        else
        {
            return palindrome2(text, i + 1, j - 1);
        }

    }
    else
    {
        return false;
    }
}
bool palindrome3 (string text, int i, int j)
{
//             
    assert(text.length() >= 1 && i>= 0 && i <=j);
//              
//                                                                                                             
//                                                                                     
//                                                           
    char a = toSmall(text[i]);
    char b = toSmall(text[j]);
    if (( a== ' ' || a == '.' || a == ',' || a == ':' || a == ';' || a + 0 == '\'' || a == '!' || a == '?' || a == '-'))
    {
        i++;
        return palindrome3(text, i, j );
    }
    if ( b== ' ' || b == '.' || b == ',' || b == ':' || b == ';' || b + 0 == '\'' || b == '!' || b == '?' || b == '-')
    {
        j--;
        return palindrome3(text, i, j);
    }

    if (i == j)
    {
        return true;
    }
    else if(a==b)
    {
        if(i + 1 > j - 1)
        {
            return true;
        }
        else
        {
            return palindrome3(text, i + 1, j - 1);
        }

    }
    else
    {
        return false;
    }
}

bool match_chars (string chars, int i, string source, int j)
{
//             
assert(chars.length() > 0 && i >= 0 && source.length() > 0 && j >= 0);
//                                                                                                             
    //                                                           
    if (j >= source.length())
    {
        //                                                                                         
        return false;
    }
    else if ( chars[i] == source[j])
    {
        i++;
        if (i >= chars.length())
        {
            return true;
        }
    }
    j++;
    return match_chars(chars,i,source,j);
}

int main()
{

    //      
    /*
             
          
                                          
             
                                          
             
                                 
                                  
    */

    //      
    /*
          
          
                
                                         
                            
                                         
             
                                        
             
                                              
                                              
                                            
    */

    //      
    int i;
    int j;
    string chars;
    string source;
    cout << "Input value for i:" << endl;
    cin >> i;
    cout << "Input value for j: " << endl;
    cin >> j;
    cout << "Input char string: " << endl;
    cin >> chars;
    cin.ignore();
    cout << "Input source string: " << endl;
    getline(cin, source, '\n');
    cout <<  match_chars(chars, i, source, j) << endl;

}

