/*
                                 
                          
                            
 */

//              
#include <iostream>
#include <cassert>

using namespace std;

bool palindrome1(const string& text, int i, int j) {
    //                                             
    assert(0 <= i && i <= j && j < text.length());
    //                
    //                                                                           

    bool result = text[i] == text[j];

    if (result && j > i + 2) { //                                                                                             
        result = palindrome1(text, i + 1, j - 1);
    }
    return result;
}

bool equals(char a, char b) {
    //               
    assert(true);
    //                
    //                                                                                      

    if (a >= 'A' && a <= 'Z') //                                                       
        a += 'a' - 'A'; //                                                      
    if (b >= 'A' && b <= 'Z') //          
        b += 'a' - 'A';

    return a == b;
}

bool palindrome2(const string& text, int i, int j) {
    //                                             
    assert(0 <= i && i <= j && j < text.length());
    //                
    //                                                                             

    bool result = equals(text[i], text[j]);

    if (result && j > i + 2) { //                                                                                             
        result = palindrome2(text, i + 1, j - 1);
    }
    return result;
}

bool space_or_punct(char c) {
    //               
    assert(true);
    //                
    //                                                                

    switch (c) {
        //                 
        case ' ':
        case '.' :
        case ',' :
        case ':' :
        case ';' :
        case '\'':
        case '!' :
        case '?' :
        case '-':
            return true;
        default:
            return false;
    }
}

bool palindrome3(const string& text, int i, int j) {
    //               
    assert(0 <= i && i <= j && j < text.length());
    //                
    //                                                                                                                            

    //                             
    while (i < j && space_or_punct(text[i])) {
        ++i;
    }
    while (j > i && space_or_punct(text[j])) {
        --j;
    }
    bool result = equals(text[i], text[j]);

    if (result && j > i + 2) { //                                                                                             
        result = palindrome3(text, i + 1, j - 1);
    }
    return result;
}

bool match_chars(const string& chars, int i, const string& source, int j) {
    //               
    assert(0 <= i && i <= chars.length());
    assert(0 <= j && i <= source.length());
    //                
    //                                                                                                                                                           

    bool result = i == chars.length();
    //                                                                                        
    //                                                                          
    if (!result && j < source.length()) {
        if (chars[i] == source[j]) { //                                               
            result = match_chars(chars, i + 1, source, j);
        } else { //                                                                  
            result = match_chars(chars, i, source, j + 1);
        }
    }
    return result;
}

double power(double x, int n) {
    //               
    assert(n >= 0);
    //                
    //                                

    if (n == 0)
        return 1;

    return x * power(x, n - 1);
}

double moreEffectivePower(double x, int n) {
    //               
    assert(n >= 0);
    //                
    //                                            

    if (n == 0)
        return 1;

    double result = moreEffectivePower(x, n / 2); //                                                           
    result *= result;

    if ((n & 1) == 1) //                                                           
        result *= x;

    return result;

}

int main() {
    cout << "Is otto a palindrome? " << (palindrome1("otto", 0, 3) ? "yes" : "no") << endl;
    cout << "Is Otto a palindrome? " << (palindrome1("Otto", 0, 3) ? "yes" : "no") << endl;
    cout << "Is \"Madam, I'm Adam.\" a palindrome? " << (palindrome1("Madam, I'm Adam.", 0, 15) ? "yes" : "no") << endl;

    cout << "Is otto a palindrome? " << (palindrome2("otto", 0, 3) ? "yes" : "no") << endl;
    cout << "Is Otto a palindrome? " << (palindrome2("Otto", 0, 3) ? "yes" : "no") << endl;
    cout << "Is \"Madam, I'm Adam.\" a palindrome? " << (palindrome2("Madam, I'm Adam.", 0, 15) ? "yes" : "no") << endl;

    cout << "Is otto a palindrome? " << (palindrome3("otto", 0, 3) ? "yes" : "no") << endl;
    cout << "Is Otto a palindrome? " << (palindrome3("Otto", 0, 3) ? "yes" : "no") << endl;
    cout << "Is \"Madam, I'm Adam.\" a palindrome? " << (palindrome3("Madam, I'm Adam.", 0, 15) ? "yes" : "no") << endl;

    cout << "Is 'abc' in 'It is a bag of cards'? " << (match_chars("abc", 0, "It is a bag of cards", 0) ? "yes" : "no") << endl;
    cout << "Is 'abc' in 'It is a bag of books'? " << (match_chars("abc", 0, "It is a bag of books", 0) ? "yes" : "no") << endl;
    cout << "Is 'abc' in 'It is a classy bag'? " << (match_chars("abc", 0, "It is a classy bag", 0) ? "yes" : "no") << endl;

    double x;
    int n;
    cout << "please specify the number you want to have a power of:"<< endl;
    cin >> x;
    cout << endl << "please specify the power you want:" << endl;
    cin >> n;

    cout << power(x, n) << endl;
    cout << moreEffectivePower(x, n) << endl;

    /*
                                                                                            
                                                                       
                                                                         
                                                                               
     */

    return 0;
}

