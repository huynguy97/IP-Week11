#include <iostream>
#include <assert.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <locale>
using namespace std;

double power (double x, int n){
    assert(n >= 0);

    /*
                                                                   
     */

    if (n == 0){
        return 1;
    }
    else{
        return x * power(x, n-1);
    }
}

double efficientpower (double x, int n){
    assert(n >= 0);

    /*
                                                                   
     */

    if(n == 0){
        return 1;
    }
    else if(n % 2 == 0){
        //          
        double p = (efficientpower(x, n/2));
        return p * p;
    }
    else if(n == 2){
        return x*x;
}
    else {
        //         
        double p = (efficientpower(x, n/2));
        return (p * p * x);
    }

}

bool palindrome1(string text, int i, int j){
    assert(i >= 0 && j >= 0);

    /*
                                                                          
     */

    int textlength = j - i;

    if(textlength == 1 || textlength == 0){
        return true;
    }
    if(text.at(i) == text.at(j)){
            return palindrome1(text, i+1, j-1);
        }
    else{
        return false;
    }
}

bool palindrome2(string text, int i, int j){
    assert(i >= 0 && j >= 0);

    /*
                                                                         
    */

    int textlength = j - i;
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    if(textlength == 1 || textlength == 0){
        return true;
    }
    if(text.at(i) == text.at(j)){
        return palindrome2(text, i+1, j-1);
    }
    else{
        return false;
    }
}

bool isjunk(char c) {
    assert(true);

    /*
                                                                                 
    */

    int ascii_c = int(c);
    return (ascii_c <= 47 || (ascii_c >= 58 && ascii_c <= 64));

}

bool palindrome3 (string text, int i, int j){
    assert(i >= 0 && j >= 0);

    /*
                                                                         
    */

    int textlength = j - i;
    locale loc;
    char p = tolower(text.at(i), loc);
    char q = tolower(text.at(j), loc);

    if(textlength == 1 || textlength == 0){
        return true;
    }
    else if(isjunk(p)){
        return palindrome3(text, i+1, j);
    }
    else if(isjunk(q)){
        return palindrome3(text, i, j-1);
    }
    else if(p == q){
        return palindrome3(text, i+1, j-1);
    }
    else{
        return false;
    }
}

bool matches_chars(string chars, int i, string source, int j){
    assert(i >= 0 && j >= 0 && i <= chars.length() && j <= source.length());

    /*
                                                                                                                  
    */

    if(i == chars.length()){
        return true;
    }
    if(i != chars.length() && j == source.length()){
        return false;
    }
    if(chars[i] == source[j]){
        return matches_chars(chars, i+1, source, j);
    }
    else{
        return matches_chars(chars, i, source, j+1);
    }
}

int main() {
    //         

    int n;
    double x;
    //         
    //         
    //                                    

    //         
    //                                     
    //                                            

    //         
    string p;
   /*                                                                         
                    
                                        
                                                  
     
         
                                                       
     

               
                                        
                                                     
     
         
                                                       
     
               
                                        
                                                     
     
         
                                                       
     
    */
    //       
    int s;
    int t;
    string string1;
    string string2;
    getline(cin, string1);
    getline(cin, string2);
    cin >> s;
    cin >> t;

    if(matches_chars(string1, s, string2, t))
    {
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}
