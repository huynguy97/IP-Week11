#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//                     
//                      

double power (int x,int n)
{
    if (n <= 0)
        return 1;
    else
        return x * power(x,n-1);
}

bool palindrome1(string text, int a, int b)
{
    if (a >= b)
        return true;
    if (text[a] != text[b])
            return false;
        a++;
        b--;
     if (palindrome1(text,a,b))
         return true;
     else
         return false;
}

bool palindrome2(string text, int a, int b)
{
    for (int i = 0 ; i <= b ; i++)
    {
        text[i]=tolower(text[i]);
    }
    if (a >= b)
        return true;
    if (text[a] != text[b])
        return false;
    a++;
    b--;
    if (palindrome1(text,a,b))
        return true;
    else
        return false;
}

bool palindrome3(string text, int a, int b)
{
    for (int i = 0 ; i <= b ; i++)
    {
        text[i]=tolower(text[i]);
    }
    for (int i = 0 ; i < b ; i++)
    {
        if (text[i] == '.' || text[i] == ','|| text[i] == ':'|| text[i] == ';'|| text[i] == '\'' || text[i] == '!'|| text[i] == '?'|| text[i] == '-' || text[i] == ' ')
        {
            text.erase(text[i]);
        }
    }
    if (a >= b)
        return true;
    if (text[a] != text[b])
        return false;
    a++;
    b--;
    if (palindrome1(text,a,b))
        return true;
    else
        return false;
}

bool match_chars(string chars, int i, string source, int j)
{
    //                                                                                 
/*                                               
     
                                            
         
               
         

      */
}

int main()
{
//                          
/*                                     
                               
                       
                         
    */
string a = "acek";
string b = "abcdefghijkl";
    if (match_chars(a,0,b,0));
        cout << "true";
    return 0;
}
