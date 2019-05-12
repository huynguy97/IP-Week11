#include <cctype>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>

using namespace std;

//                       
//             

//      
int power (int x, int n){
    //               
    assert(n>=0);
    //                
    //                          
    if (n==0)
        return 1;
    else
        return x*power(x, n-1);
}
//                              
int power_n_even (int x, int n){
    //               
    assert(n>=0);
    //                
    //                          
    if (n==0)
        return 1;
    else if (n%2==0)
    n=n/2;
        return power(x, n)*power(x, n);
}

//      

bool palindrome1(string text, int i, int j){
    //               
    assert(i>=0 && j>=0);
    //                
    //                                                   
    //                           
    if (i==j-1 || i==j)
        return true;
    else{
        if(text[i]==text[j])
           return palindrome1(text, i+1, j-1);
        }
    return false;
}

bool palindrome2(string text, int i, int j){
    //               
    assert(i>=0 && j>=0);
    //                
    //                                                                
    //                                               
    //                                                   
    //                           
    string lowercase;
    for (int c=i; c<=j; c++)
        lowercase+=tolower(text[c]);
    //                          
    return palindrome1(lowercase, i, j);
}

bool palindrome3(string text, int i, int j){
    //               
    assert(i>=0 && j>=0);
    //                
    //                                                        
    //                                                                
    //                                                       
    //                                                   
    //                           
    string only_letters;
    for (int c=i; c<=j; c++){
        switch (text[c])
        {
            case ' ':
            case '.':
            case ',':
            case ':':
            case ';':
            case '\'':
            case '!':
            case '?':
            case '-': break;
            default: only_letters+=text[c];
        }
    }
    //                     
    j=only_letters.length()-1;
    return palindrome2(only_letters, i, j);
}

//       
bool match_chars (string chars, int i, string source, int j){
    //               
    assert(i>=0 && j>=0);
    //                
    //                                               
    //                                                    
    if(i==chars.length())//                                                                                       
        return true;
    if(j==source.length())//                                                                                                                                                  
        return false;
    if(chars[i]==source[j])//                                                            
        return match_chars(chars, i+1, source, j+1);
    else//                                                               
        return match_chars(chars, i, source, j+1);
}

int main()
{
    cout << power(3, 3) << endl;
    cout << power_n_even(2,8) << endl;
    cout << palindrome1 ("legovogel", 0, 8) << endl;
    cout << palindrome1 ("Legovogel", 0, 8) << endl;
    cout << palindrome2 ("Legovogel", 0, 8) << endl;
    cout << palindrome3 ("Madam, I'm Adam.", 0, 15) << endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars ("abc", 0, "It is a bag of books", 0) << endl;
    cout << match_chars ("abc", 0, "It is a classy bag", 0) << endl;
    return 0;
}

