#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/*
                             
                      
                         
                      
*/

//         

int power(int x, int n) {
    //               
    assert(n >= 0);
    //                
    //                                 
    //                                     
    if(n == 0) return 1;
    else return x * power(x,n-1);
}

//         

int power_fast(int x, int n) {
    //               
    assert(n >= 0);
    //                
    //                                 
    //                                     
    if(n == 0) return 1;
    else if(n == 1) return x;
    else if(n % 2 != 0) return x * power_fast(x, (n-1));
    else return power_fast(x, n/2) * power_fast(x, n/2);
}

//         

bool palindrome1 (string text, int i, int j) {
    //               
    assert(i >= 0 && i < text.length() && j >= 0 && j < text.length());
    //                
    //                                                   
    if(text[i] != text[j]) return false;
    else if(j == 0) return true;
    else palindrome1(text, i+1, j-1);
}

//         

bool is_equal_i(char a, char b) {
    //               
    assert(true);
    //                
    //                                                                
    //                                     
    if(a >= 65 && a <= 90) a += 32;
    if(b >= 65 && b <= 90) b += 32;
    return a == b;
}

bool palindrome2(string text, int i, int j) {
    //               
    assert(i >= 0 && i < text.length() && j >= 0 && j < text.length());
    //                
    //                                                   
    //                                  
    if(!is_equal_i(text[i], text[j])) return false;
    else if(j == 0) return true;
    else palindrome2(text, i+1, j-1);
}

//         

bool is_equal_i_space(char a, char b)  {
    //               
    assert(true);
    //                
    //                                                                            
    //                       
    if(a == ' ' || a == '.' || a == ',' || a == ':' || a == ';' || a == '\'' || a == '!'
      || a == '!' || a == '?' || a == '-') return true;
    if(b == ' ' || b == '.' || b == ',' || b == ':' || b == ';' || b == '\'' || b == '!'
      || b == '!' || b == '?' || b == '-') return true;
    else return is_equal_i(a, b);
}

bool palindrome3(string text, int i, int j) {
    //               
    assert(i >= 0 && i < text.length() && j >= 0 && j < text.length());
    //                
    //                                                   
    //                                  
    if(!is_equal_i_space(text[i], text[j])) return false;
    else if(j == 0) return true;
    else palindrome3(text, i+1, j-1);
}

//       

bool match_chars(string chars, int i, string source, int j) {
    //               
    assert(i >= 0 && j >= 0);
    //                
    //                                                                    
    //                                                                    
    //                                       
    if(i == chars.length()) return true;
    if(j == source.length()) return false;
    if(chars[i]==source[j]) return match_chars(chars, i+1, source, j+1);
    else return match_chars(chars, i, source, j+1);
}
int main()
{
    return 0;
}

