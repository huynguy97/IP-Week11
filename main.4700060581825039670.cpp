#include <iostream>
#include <cassert>
#include <string>

using namespace std;

double power(double x, int n)
{
    //    
    assert(n>=0);
    //     
    //                           
    if(n==0)
        return 1;
    return x*power(x,n-1);
}

double square(double x)
{
    //    
    assert(true);
    //     
    //                       
    return x*x;
}

double power2(double x, int n)
{
    //    
    assert(n>=0);
    //     
    //                           
    if(n==0)
        return 1;
    if( n%2==0 )
        return square(power2(x,n/2));//                                                                  
    return x*power2(x,n-1);
}

bool palindrome1(string text, int i, int j)
{
    //    
    assert(i>=0 && j<text.length() );
    //     
    //                                                                                                     
    //                                 
    if(i>=j)
        return true;
    if(text[i]==text[j])//                                  
        return palindrome1(text, i+1, j-1);//                                                          
    return false;
}

bool char_compare(char char1, char char2)
{
    //    
    assert(true);
    //     
    //                                                                                                                             
    if(char1==char2)
        return true;
    if(char1>='A' && char1<='Z' && char1 == char2 - 32)//                                                                  
        return true;
    if(char2>='A' && char2<'Z' && char2 == char1 - 32)//                                                                  
        return true;
    return false;
}

bool palindrome2(string text, int i, int j)
{
    //    
    assert(i>=0 && j<text.length() );
    //     
    //                                                                                                     
    //                                   
    //                                 
    if(i>=j)
        return true;
    if(char_compare(text[i],text[j]))
        return palindrome2(text, i+1, j-1);
    return false;
}

bool is_symbol(char c)
{
    //    
    assert(true);
    //     
    //                                                                   
    return c=='.'||c== ','||c==':'||c==';'||c=='\''||c=='!'||c=='?'||c=='-'||c==' ';
}

void ignore_symbols(string text, int& i, int& j)
{
    //    
    assert(i>=0 && j<text.length() );
    //     
    //                                                                                        

    while( i<j && is_symbol(text[j]) )//                   
        j--;
    while(i<j && is_symbol(text[i]) )//                    
        i++;
}

bool palindrome3(string text, int i, int j)
{
    //    
    assert(i>=0 && j<text.length() );
    //     
    //                                                                                                     
    //                                   
    //                                 
    ignore_symbols(text, i, j);
    if(i>=j)
        return true;
    if(char_compare(text[i],text[j]))
        return palindrome3(text, i+1, j-1);
    return false;
}

bool match_chars(string chars, int i, string source, int j)
{
    //    
    assert(i>=0 && j>=0 );
    //     
    //                                                                                                                    
    if(i>=chars.length())//                                                          
        return true;
    else if(j>=source.length())//                                                                                                  
        return false;
    if(chars[i]==source[j])
        return match_chars(chars, i+1, source, j+1);
    return match_chars(chars, i, source, j+1 );//                                                                    
}

int main()
{

/*
                               
                               

                            
                                               
                                               
                                                          
                                                     
                            
                                               
                                               
                                                          
                                                     
                            
                                               
                                               
                                                          
                                                     
                                                        

                             
                                                                      
                                                                      
                                                                    
*/
    return 0;
}
/*
                                                                                                                                
                                                                                                                                                   
*/

