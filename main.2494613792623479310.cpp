#include <iostream>
#include <cassert>

using namespace std;
//                      
//                               

//         
double power (double x, int n)
{//              
    assert(n >= 0) ;
//                                                         
    if (n == 0)
        return 1 ;
    else
        return x*power(x, n-1) ;
}

//         
double power2 (double x, int n)
{//              
    assert(n >= 0) ;
//                                                         
    if (n == 0)
        return 1 ;
    if (n % 2 == 0)
        return power2(x, n/2)*power2(x, n/2) ;
    else
        return x*power2(x, n-1) ;
}
//                                                                                                 

//        
bool palindrome1 (string text, int i, int j)
{//              
    assert(i<=j) ;
 //                                                                                     
    if (i == j)
        return true ;
    if (text[i] == text[j])
    {
        if (i+1 == j)
            return true ;
        else
            return palindrome1(text, i+1, j-1) ;
    }
    else
            return false ;
}

//        
bool palindrome2 (string text, int i, int j)
{//              
    assert(i<=j) ;
 //                                                                                     
 //                                                       
    if (i == j)
        return true ;
    else if (text[i] == text[j] || text[i] == text[j]+32 || text[i]+32 == text[j])
    {
        if (i+1 == j)
            return true ;
        else
            return palindrome2(text, i+1, j-1) ;
    }
    else
            return false ;
}

//        
bool palindrome3 (string text, int i, int j)
{//              
    assert(i<=j) ;
 //                                                                                     
 //                                                                                             
 //        
    if (i == j)
        return true ;
    char c = text[i] ;
    char d = text[j] ;
    if (c == ' ' || c == '.' || c == ',' || c == ':' || c == ';' || c == '\'' || c == '!' || c == '?' || c == '-')
        return palindrome3(text, i+1, j) ;
    if (d == ' ' || d == '.' || d == ',' || d == ':' || d == ';' || d == '\'' || d == '!' || d == '?' || d == '-')
        return palindrome3(text, i, j-1) ;
    if (c == d || c == d+32 || c+32 == d)
    {
        if (i+1 == j)
            return true ;
        else
            return palindrome3(text, i+1, j-1) ;
    }
    else
            return false ;
}

//      
bool match_one_char(char c, string source, int& j)
{//              
    assert (j >= 0) ;
//                                                                                                     
    for (int i = j ; i < source.length() ; i++)
    {
        if (source[i] == c)
        {
            j = i+1 ;
            return true ;
        }
    }
    return false ;
}

bool match_chars (string chars, int i, string source, int j)
{//              
    assert (i<= chars.length() && i >= 0 && j >= 0) ;
//                                                                                 
//                                                                                  
//                     
    if (i == chars.length())
        return true ;
    if (match_one_char(chars[i], source, j))
        return match_chars(chars, i+1, source, j) ;
    else
        return false ;
}

int main()
{
    if (match_chars("abc", 0, "It is a classy bag", 0))
            cout << "Hello world!" << endl;
    return 0;
}

