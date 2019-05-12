#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

#define NDEBUG

using namespace std;

//                       
//                   
//                     

//          
//          
//          
double power(double x, int n)
{
    //              
    assert(true);
    //                                                     
    if(n==0)
        return 1;
    else if(n > 0)
        return x * power(x, n-1);
}
//          
//          
//          
//                                 
double effpow(double x, int n)
{
    //              
    assert(true);
    //                                                    
    if(n == 0)
        return 1;
    else if(n % 2 == 1)
        return x * effpow(x*x, (n-1)/2);
    else
        return effpow(x*x, n/2);
}

//          
//          
//          
bool palindrome1(string text, int i, int j)
{
    //              
    assert(text.size >= 0 && i >= 0 && j >= 0);
    //                                                               
    if(text.size() <= 1)
        return true;
    else if (text[i] != text[j])
        return false;
    else
    {
        //                                                                        
        if (text.size() == 2)
            return true;
        return palindrome1(text.substr(1, text.size() - 2), 0, text.size() - 3);
    }
}

//          
//          
//          
bool palindrome2(string text, int i, int j)
{
    //              
    assert(text.size >= 0 && i >= 0 && j >= 0);
    //                                                                                 
    if(text.size() <= 1)
        return true;
    else if (tolower(text[i]) != tolower(text[j]))
        return false;
    else
    {
        if (text.size() == 2)  //            
            return true;
        return palindrome2(text.substr(1, text.size() - 2), 0, text.size() - 3);
    }
}

//          
//          
//          

bool palindrome3(string text, int i, int j)
{
    //              
    assert(text.size >= 0 && i >= 0 && j >= 0);
    //                                                                                                                      
    const int n_punct = 10;
    char punctuation [n_punct] = {' ', '.',',',':',';','\\','!','?','-', '\''};

    //                                                                                                                                  
    for(int x = text.size() - 1; x >= 0; x--)
    {
        for(int y = 0; y < n_punct; y++)
        {
            if (text[x] == punctuation[y])
            {
                text = text.erase(x, 1);
                j--;
            }
        }
    }

    //                                                                
    return palindrome2(text, i, j);
}

//          
//          
//          

bool match_chars (string chars, int i, string source, int j){
    //              
    assert(chars.size >= 0 && source.size >= 0 && i >= 0 && j >= 0);
    //                                                                                               
    if(j == source.size()){
        return false;
    }
    else if (i == chars.size()){
        return true;
    }
    else if(chars[i] == source[j]){
        return match_chars(chars, i + 1, source, j + 1);
    } else {
        return match_chars(chars, i, source, j + 1);
    }
}

int main()
{
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
    return 0;
}

