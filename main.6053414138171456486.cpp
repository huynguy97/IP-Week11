#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/*
                                
                                
*/

double power(double x, int n) {
//              
    assert(n >= 0);
//                                        
    if(n != 0) {
        return x*power(x,n-1);
    } else {
        return 1.0;
    }
}
//                                                                                 
double efficient_power(double x, int n) {
//              
    assert(n >= 0);
//                                                     
    if(n != 0) {
        if (n % 2 == 0) {
            return efficient_power(x,n/2)*efficient_power(x,n/2);
        } else {
            return x*efficient_power(x,n-1);
        }
    } else {
        return 1.0;
    }
}

bool palindrome1(string text, int i, int j) {
//              
    assert(true);
//                                                                             
    if(i < j) {
        if(text[i] == text[j]) {
            return palindrome1(text, i+1, j-1);
        } else {
            return false;
        }
    } else {
        return true;
    }
}

bool palindrome2(string text, int i, int j) {
//              
    assert(true);
//                                                                             
    if(i < j) {
        if(text[i] == text[j] || text[i] == (text[j]+32) || text[i] == (text[j]-32)) {
            return palindrome2(text, i+1, j-1);
        } else {
            return false;
        }
    } else {
        return true;
    }
}

bool sub_palindrome3(string text, int i, int j) {
//              
    assert(true);
//                                                                             
    if(i < j) {
        if(text[i] == text[j] || text[i] == (text[j]+32) || text[i] == (text[j]-32)) {
            return sub_palindrome3(text, i+1, j-1);
        } else {
            return false;
        }
    } else {
        return true;
    }
}

bool palindrome3(string text, int i, int j) {
//              
    assert(true);
/*                                                                             
                                                */
    while(text.find_first_of(" .,:;\\!?-") != string::npos) {
        text = text.erase(text.find_first_of(" .,:;\\!?-"), 1);
    }
    return sub_palindrome3(text,0,text.length()-1);
}

bool match_chars(string chars, int i, string source, int j) {
//              
    assert(true);
//                                                                                                           
    if(i > chars.length()-1) {
        return true;
    } else {
        while(chars[i] != source[j]) {
            j++;
            if(j >= source.length()) {
                return false;
            }
        }
        return match_chars(chars,i+1,source,j+1);
    }
}

int main() {
    cout << "regular: 2^5 = " << power(2,5) << endl;
    cout << "regular: 10^1 = " << power(10,1) << endl;
    cout << "regular: 10000^0 = " << power(10000,0) << endl;
    cout << "efficient: 2^5 = " << efficient_power(2,5) << endl;
    cout << "efficient: 10^1 = " << efficient_power(10,1) << endl;
    cout << "efficient: 10000^0 = " << efficient_power(10000,0) << endl;
    cout << "otto: " << palindrome3("otto",0,3) << endl;
    cout << "Otto: " << palindrome3("Otto",0,3) << endl;
    cout << "lepel: " << palindrome3("lepel",0,4) << endl;
    cout << "a: " << palindrome3("a",0,0) << endl;
    cout << "appel: " << palindrome3("appel",0,4) << endl;
    cout << "aA;a xa:aA: " << palindrome3("aA;a xa:aA",0,6) << endl;
    cout << "\"abc\" and \"It is a bag of cards\": " << match_chars("abc",0,"It is a bag of cards",0) << endl;
    cout << "\"It is a bag of cards\" and \"It is a bag of cards\": " 
         << match_chars("It is a bag of cards",0,"It is a bag of cards",0) << endl;
    cout << "\"abc\" and \"It is a classy bag\": " << match_chars("abc",0,"It is a classy bag",0) << endl;
    return 0;
}
