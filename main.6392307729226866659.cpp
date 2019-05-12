#include <iostream>
#include <cassert>

using namespace std;

//                
//                 

//        
double power(double x, int n){
    //               
    assert(true);
    //                
    //                        
    if(n == 0)
        return 1;
    else{
        cout << n << ' ' << x << '\n';
        double i = x * power(x,n-1);
        return i;
    }
}

//         
double power_2(double x, int n){
//                                                                 
    if (n<=0)
        return 1;
    else {
        if(n%2==0 && n>0){
            n=n/2;
            double i=power(x, n);
            return i*i;
        }
        else
            return x*power(x,n-1);
        }
    }
//                                    

//        
bool palindrome1(string text, int i, int j){
    //               
    assert(j>=i);
    //                
    //                                                        
    if (text[i] != text[j])
        return false;
    else if(text[i] == text[j] && j >= i){
        palindrome1(text, i+1, j-1);
    }
    else
        return true;
}

//        
bool palindrome2(string text, int i, int j){
    //               
    assert(j>=i);
    //                
    //                                                                     
    //                                                 
    if(65 <= static_cast<int>(text[i]) && static_cast<int>(text[i]) <= 90)
        text[i] = static_cast<int>(text[i]) + 32;
    if(65 <= static_cast<int>(text[j]) && static_cast<int>(text[j]) <= 90)
        text[j] = static_cast<int>(text[j]) + 32;
    if (text[i] != text[j])
        return false;
    else if(text[i] == text[j] && j >= i){
        palindrome2(text, i+1, j-1);
    }
    else
        return true;
}

//        
bool palindrome3(string text, int i, int j){
    //               
    assert(j>=i);
    //                
    //                                                                     
    //                                                                                      
    if(65 <= static_cast<int>(text[i]) && static_cast<int>(text[i]) <= 90)
        text[i] = static_cast<int>(text[i]) + 32;
    if(65 <= static_cast<int>(text[j]) && static_cast<int>(text[j]) <= 90)
        text[j] = static_cast<int>(text[j]) + 32;
    if(32 <= static_cast<int>(text[i]) && static_cast<int>(text[i]) <= 96)
        i++;
    if(32 <= static_cast<int>(text[j]) && static_cast<int>(text[j]) <= 96)
        j--;
    cout << text[i] << text[j] << '\n';
    if (text[i] != text[j])
        return false;
    else if(text[i] == text[j] && j >= i){
        palindrome3(text, i+1, j-1);
    }
    else
        return true;
}

//        
int counter = 0;

bool match_chars (string chars, int i, string source, int j){
    //              
    assert(true);
    //               
    //                                                                   
    if (j == source.length())
        return false;
    if (counter == chars.length())
        return true;
    if(chars[i]!=source[j]){
        return match_chars(chars, i, source, j + 1);
    }
    else if(chars[i]=source[j]){
        counter++;
        return match_chars(chars, i + 1, source, j);
    }
}

int main() {
    return 0;
}
