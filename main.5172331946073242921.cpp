#include <iostream>
#include <assert.h>
#include <string>
#include <locale>

//                                                     
using namespace std;

//        
double power(double x, int n) {

    //             
    assert (n >= 0);
    //                                                        

    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n-1);
    }

}

//        
double efficientpower (double x, int n){
    //             
    assert (n >= 0);
    //                                                        

    if (n == 0){
        return 1;
    } else if(n % 2 != 0) { //                
        double p = efficientpower(x, n/2);
        return x * p * p;
    } else { //           
        double p = efficientpower(x, n/2);
        return p * p;
    }

    //                                               

}

//        

bool palindrome1 (const string text, int i, int j){
    //             
    assert (i >= 0);
    //                                                                                                            
    int text_length = j - i;
    if (text_length == 0 || text_length == 1) {
        return true;
    } else {
        if (text.at(i) == text.at(j)) {
            return palindrome1 (text, i + 1, j - 1);
        }
    }
}

//        

bool palindrome2 (const string text, int i, int j) {
//             
    assert (i >= 0);
    //                                                                                                         

    locale loc;

    int text_length = j - i;
    if (text_length == 0 || text_length == 1) {
        return true;
    } else {

        if (toupper(text.at(i), loc) == toupper(text.at(j), loc)) {
            return palindrome2 (text, i + 1, j - 1);
        }
    }

}

//        

bool isjunk(char c) {
    //             
    assert (true);
    //                                                                                                           
    int ascii_c = int(c);
    return (ascii_c <= 47 || (ascii_c >= 58 && ascii_c <= 64)) ;

}
bool palindrome3 (const string text, int i, int j) {
    //             
    assert (i >= 0);
    //                                                                                                                                                              
    locale loc;
    int text_length = j - i;
    if (text_length == 0 || text_length == 1) {
        return true;
    } else {
        char ic = toupper(text.at(i), loc);
        char jc = toupper(text.at(j), loc);

        if (isjunk(ic))  {
            return palindrome3 (text, i +1, j);
        } else if (isjunk(jc)) {
            return palindrome3 (text, i, j - 1);
        } else if ( ic == jc) {
            return palindrome3 (text, i + 1, j - 1);
        }
    }
}

//      

bool match_chars (string chars, int i, string source, int j) {
    //             
    assert (i >= 0 && j >= 0);
    //                                                                                                                              

    if (i == chars.length()) {
        return true;
    } else if(j == source.length()) {
        return false;
    } else if(chars.at(i) == source.at(j))  {
        return match_chars(chars, i + 1, source, j);
    } else {
        return match_chars(chars, i, source, j + 1);
    }

}

int main() {
    cout << match_chars("abc", 0, "alle dieren cabbelen er op bos", 0);
    return -1;
}
