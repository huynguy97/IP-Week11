#include <iostream>
#include <cassert>

using namespace std;

//                             
//                         

//        

//                 
//                          
// 
//               
//               
//              
//                                             
//
//           
//             
//    
//                           
// 

//             
int power(double x, int n)
{
//             
assert(n >= 0);
//               
//                                             

if (n == 0)
    return 1;
else if ( n % 2 == 0)
    return power(x*x, n/2);
else
   return x * power(x, n-1);
}

//        

bool palindrome1 (string text, int i, int j)
{
//             
assert(j <= text.length() && i >= 0);
//              
//                                                               
//                                                        
    if (text[i] == text[j])
    {
        if (i == j || i + 1 == j)
        {
            return true;
        }
        else
        {
            return palindrome1(text, i+1, j-1);
        }
    }
    else
    {
        return false;
    }
}

bool palindrome2 (string text, int i, int j)
{
//             
assert (j <= text.length() && i >= 0);
//              
//                                                                
    if (text[i] == text[j] || text[i] - 32 == text[j] || text[i] == text[j] - 32)
    {
        if (i == j || i + 1 == j)
        {
            return true;
        }
        else
        {
            return palindrome2(text, i+1, j-1);
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
assert (j <= text.length() && i >= 0);
//              
//                                                                                      
    if (text[i] == ' ' ||text[i] == '.' ||text[i] == ',' ||text[i] == ':' ||text[i] == ';' ||text[i] == 92 ||text[i] == '!' ||text[i] == '?' ||text[i] == '-' || text[i] == 39 || text[i] == 96)
    {
        return palindrome3(text, i + 1, j);
    }
    else if (text[j] == ' ' ||text[j] == '.' ||text[j] == ',' ||text[j] == ':' ||text[j] == ';' ||text[j] == 92 ||text[j] == '!' ||text[j] == '?' ||text[j] == '-' || text[j] == 39 || text[j] == 96)
    {
        return palindrome3(text, i, j - 1);
    }

    if (text[i] == text[j] || text[i] - 32 == text[j] || text[i] == text[j] - 32)
    {
        if (i == j || i + 1 == j)
        {
            return true;
        }
        else
        {
            return palindrome3(text, i+1, j-1);
        }
    }
    else
    {
        return false;
    }
}

//        

bool match_chars (string chars, int i, string source, int j)
{
//             
assert(i >= 0 && j >= 0 && i <= chars.length() && j <= source.length());
//              
//                                                                                             
    if (i == chars.length() && j == source.length())
    {
        return true;
    }
    else if (i != chars.length() && j == source.length())
    {
        return false;
    }

    if (chars[i] != source [j])
    {
        return match_chars(chars, i, source, j + 1);
    }
    else
    {
        return match_chars(chars, i + 1, source, j);
    }
}

int main()
{
    cout << match_chars("abc", 0, "It is a classy bag.", 0);
    return 0;
}

