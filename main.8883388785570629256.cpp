#include <iostream>
#include <cassert>

using namespace std;
/*
             

                            
                       
*/

double power (double x, int n)
{
    //              
    assert(n >= 0);
    /*                                               
    */
    if(n == 0)
        return 1;
    else
    {
        double a = power(x, n-1);
        return x*a;
    }
}

bool is_even (int n)
{
    //              
    assert(n >= 0);
    /*                                                                                                  
    */
    if(n%2 == 0)
        return true;
    else
        return false;
}

double power2 (double x, int n)
{
    //              
    assert(n >= 0);
    /*                                               
    */
    if(n == 0)
        return 1;
    else
    {
        if(is_even(n))
        {
            double a = power2(x, n/2);
            return a*a;
        }
        else
        {
            double b = power2(x, n-1);
            return x*b;
        }
    }
}
//                                                                                           

bool palindrome_1(string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i <= j && j < text.length());
    /*                                                                                                                  
                                                            
    */
    if (i >= j-1)
        return true;
    else
    {
        if(text[i] == text [j])
        {
            bool a = palindrome_1(text, i+1, j-1);
            return a;
        }
        else
            return false;
    }
}

bool palindrome_2(string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i <= j && j < text.length());
    /*                                                                                                 
                                                                                                            
    */
    if(i >= j-1)
        return true;
    else
    {
        if(text[i] == text [j] || text[i]+32 == text[j] || text[i]-32 == text[j])
        {
            bool a = palindrome_2(text, i+1, j-1);
            return a;
        }
        else
            return false;
    }
}

bool palindrome_3(string text, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i <= j && j < text.length());
    /*                                                                                                 
                                                                                                 
    */
    if(i <= j-1)
        return true;
    else
    {
        if((text[i] >= 32 && text[i] <= 64) || (text[i] >= 91 && text[i] <= 96) || (text[i] >= 123))
        {
            bool a = palindrome_3(text, i+1, j);
            return a;
        }
        else if((text[j] >= 32 && text[j] <= 64) || (text[j] >= 91 && text[j] <= 96) || (text[j] >= 123))
        {
            bool b = palindrome_3(text, i, j+1);
            return b;
        }
        else if(text[i] == text [j] || text[i]+32 == text[j] || text[i]-32 == text[j])
        {
            bool c = palindrome_3(text, i+1, j+1);
            return c;
        }
        else
            return false;
    }
}

bool match_chars(string chars, int i, string source, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i < chars.length() && j < source.length());
    /*                                                                                                                
                                                                                         
    */
    if(i == chars.length()-1 && chars[i] == source[j])
        return true;
    else if(i == chars.length()-1 && j == source.length()-1 && chars[i] != source[j])
        return false;
    else
    {
        if(chars[i] == source[j])
        {
            bool a = match_chars(chars, i+1, source, j+1);
            return a;
        }
        else if(chars[i] != source[j])
        {
            bool b = match_chars(chars, i, source, j+1);
            return b;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    /*                                                                  
                    
             
             
                  
          
             
                                                               
                                                                  */

    /*                                  
                
                                     
                                              
              
                 
                                             
               
                  
                                         
                                            
        
                                                  */

    /*                                            
                 
                        
              
                                             
                  
                         
              
                                        
                                                                                                       
        
                                              */

    return 0;
}

