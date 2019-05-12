//                                                                 
#include <iostream>
#include <cassert>

using namespace std;

//                                                                                                                                                                                    
double naive_power (double x, int n)
{
//              
    assert (n >= 0);
/*
                  
                                              
*/
    if (n == 0)
        return 1;
    else
    {
        x = x * naive_power(x,n-1);
        return x;
    }
}

double non_naive_power (double x, int n)
{
//               
    assert(n >= 0);
/*
                  
                                             
*/
    if (n == 0)
        return 1;
    if (n%2 == 0) //           
    {
        int i = non_naive_power(x, n/2);
        return i * i;
    }
    else
        return x * non_naive_power(x, n-1);
}
//                             

//                                                                                                                                                                                 

bool palindrome_1(string text, int i, int j)
{
//                
    assert (i >= 0 && j >= 0 && i <= j);
/*                
                                                              
*/

    if (j == i + 1 || j == i) //                                   
        return true;

    else
    {
        if (text[i] == text[j])
            palindrome_1(text, i+1, j-1);
        else
            return false;
    }

}

bool palindrome_2 (string text, int i, int j)
{
//                
    assert (i >= 0 && j >= 0 && i <= j);
/*                
                                                                                                       
*/

    if (j == i + 1 || j == i) //                                   
        return true;

    else
    {
        if (text[i] == text[j] || text[i] - 32 == text[j] || text[i] + 32 == text[j])
            palindrome_2(text, i+1, j-1);
        else
            return false;
    }

}

bool palindrome_3 (string text, int i, int j)
{
//                
    assert (i >= 0 && j >= 0 && i<= j);
/*                
                                                                                                                                    
*/

    if (j == i + 1 || j == i) //                                   
        return true;
    else
    {
        if (text[i] < 65)
                palindrome_3(text, i+1, j);
        else if (text [j] < 65)
                palindrome_3(text, i, j-1);
        else if (text[i] == text[j] || text[i] - 32 == text[j] || text[i] + 32 == text[j])
                palindrome_3(text, i+1, j-1);
        else
            return false;
    }
}

//                                                                                                                                                                                    

bool match_chars (string chars, int i, string source, int j)
{
//               
    assert (0 <= i && i <= chars.length() && 0 <= j && j <= source.length());
/*
                  
                                                                                 
*/
    if (i == chars.length())
        return true;
    if (j >= source.length())
        return false;

    if (chars[i] == source [j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
/*                                     
              
               
                                  
                               
         
                                
*/

    string source = "It is a classy bag";
    string chars = "abc";
    int i = 0;
    int j = 0;
    match_chars( chars, i, source, j);

    if (match_chars(chars, i, source, j))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

