//                         
//                            

#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)
{
    //    
    assert(n >= 0);
    //     
    //                              
    if(n==0)
        return 1;
    else{
        return x*power(x, n-1);
    }
}

double power_faster(double x, int n)
{
    //                                                 
    //                                                         
    //    
    assert(n >= 0);
    //     
    //                              
    if(n==0)
        return 1;
    if(n%2==0)
    {
        double a = power(x, 0.5*n);
        return a*a;
    }
    else{
        return x*power(x, n-1);
    }
}

bool palindrome1(string text, int i, int j)
{
    //    
    assert(i >= 0 && j <= text.length());
    //     
    //                                                              
    if(j<i)
    {
        return true;
    }
    else{
        return text[i] == text[j] && palindrome1(text, i+1, j-1);
    }
}

bool palindrome2(string text, int i, int j)
{
    //                                                        
    //                                            
    //    
    assert(i >= 0 && j <= text.length());
    //     
    //                                                              
    if(j<i)
    {
        return true;
    }
    else{
        return tolower(text[i]) == tolower(text[j]) && palindrome2(text, i+1, j-1);
    }
}

bool palindrome3(string text, int i, int j)
{
    //                                                        
    //                                                
    //    
    assert(i >= 0 && j <= text.length());
    //     
    //                                                              
    while(text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?' || text[i] == ';' || text[i] == ':' || text[i] == '\'' || text[i] == '-')
    {
        i++;
    }
    while(text[j] == ' ' || text[j] == '.' || text[j] == ',' || text[j] == '!' || text[j] == '?' || text[j] == ';' || text[j] == ':' || text[j] == '\'' || text[j] == '-')
    {
        j--;
    }
    if(j<=i)
    {
        return true;
    }
    else{
        return (tolower(text[i]) == tolower(text[j])) && palindrome3(text, i+1, j-1);
    }
}

bool match_chars(string chars, int i, string source, int j)
{
    //    
    assert(i >= 0 && j >= 0);
    //     
    //                                                                    
    //                    
    for(int p = j; p<source.length();p++)
    {
        if(chars[i] == source[p])
        {
            if(i == chars.length()-1)
                return true;
            return match_chars(chars, i+1, source, p+1);
        }
    }
    return false;
}

int main()
{
    return 0;
}

