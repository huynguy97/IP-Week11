#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

//                                                               
//                                                       

int length(string text)
{
//              
assert(true);
//                                                            
    return static_cast<int>(text.length());
}

double power(double x, int n)
{
//              
assert(n>=0);
//                                                         
    if (n == 0)
        return 1;
    else
        return x*power(x,n-1);
}

double power2(double x, int n)
{
//              
assert(n>=0);
//                                                         
    if (n==0)
        return 1;
    if (n%2 == 0)
        return power(x,n/2) * power(x,n/2);
    else
        return x*power2(x,n-1);
}

bool palindrome1(string text, int i, int j)
{
//              
assert(i>= 0 && i<=j && (j < length(text) || (j==0 && length(text) ==0))); //                                      
//                                                                                 

    if(i == j) //                                             
        return true;

    if (i == (j-1)) //                                             
        return text[i] == text[j]; //                       
    else
        return text[i]==text[j] && palindrome1(text, i+1, j-1); //              
}

bool palindrome2(string text, int i, int j)
{
//              
assert(i>= 0 && i<=j && (j < length(text) || (j==0 && length(text) ==0))); //                                      
//                                                                                                  
    if(i == j) //                                             
        return true;

    if (i == (j-1)) //                                             
        return toupper(text[i]) == toupper(text[j]); //                       
    else
        return text[i]==text[j] && palindrome2(text, i+1, j-1); //              
}

bool symbol_ignore(string text, int a)
{
//               
assert(a>=0 && a<length(text));
//                                                                
    return (text[a] == '.'  ||
            text[a] == ','  ||
            text[a] == ':'  ||
            text[a] == ';'  ||
            text[a] == '\'' ||
            text[a] == '!'  ||
            text[a] == '?'  ||
            text[a] == '-'  ||
            text[a] == ' ');
}

bool palindrome3(string text, int i, int j)
{
//               
assert(i>=0&& i<=j && (j < length(text) || (j==0 && length(text) ==0))); //                                      
//                                                                                                                           
    if (i == j)
        return true;
    if (symbol_ignore(text, i))
        return palindrome3(text, i+1, j);
    if (symbol_ignore(text, j))
        return palindrome3(text, i, j-1);
    if (i == (j-1))
        return toupper(text[i]) == toupper(text[j]);
    if (toupper(text[i]) != toupper(text[j]))
        return false;
    return palindrome3(text, i+1, j-1);
}

bool match_chars(string chars, int i, string source, int j)
{
//             
assert(i>=0 && j>=i && length(source) > 0 && length(chars) > 0 && i<length(chars) && j<length(source));
//                                                                                                   
if (length(source) == j-1)
    return chars[i] == source[j];
if ( i == length(chars)-1)
    if (chars[i] == chars[j])
        return true;
    else
        return match_chars(chars, i, source, j+1);
else
    if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    if (chars[i] != source[j])
        return match_chars(chars, i, source, j+1);

}

int main()
{
    return 0;
}

