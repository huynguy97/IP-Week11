#include <cassert>
#include <iostream>

using namespace std;

//                          
//                       

long double power(double x, unsigned int n) {
    assert(true);
    /*               
                           
                                                                           
              
     */

    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n-1);
    }
}

long double opti_power(double x, unsigned int n) {
    assert(true);
    /*               
                           
                                                                           
                      
                                                                           
                    
     */
    long double pow;

    if (n == 0) {
        return 1;
    } else if ( n % 2 == 0) {
        pow = power(x, n/2);
        return pow * pow;
    } else {
        return x * power(x, n-1);
    }
}

bool palindrome1(string text, int i, int j) {
    assert(i >= 0);
    assert(j > 0);
    assert(j < (int)text.length());
    assert(i <= j);
    /*               
                                                                           
                           
                                                                    
                                                                   
     */

    if (i == j) {
        return true;
    } else if (j - i < 2) {
        return text[i] == text[j];
    } else {
        return text[i] == text[j] && palindrome1(text, i+1, j-1);
    }
}

bool palindrome2(string text, int i, int j) {
    assert(i >= 0);
    assert(j > 0);
    assert(j < (int)text.length());
    assert(i <= j);
    /*               
                                                                           
                                            
                                                                    
                                                                   
     */

    char a = text[i];
    char b = text[j];

    if (a > 64 && a < 91)
        a += 32;
    if (b > 64 && b < 91)
        b += 32;

    if (i == j) {
        return true;
    } else if (j - i < 2) {
        return a == b;
    } else {
        return a == b && palindrome2(text, i+1, j-1);
    }
}

bool palindrome3(string text, int i, int j) {
    assert(i >= 0);
    assert(j > 0);
    assert(j < (int)text.length());
    assert(i <= j);
    /*               
                                                                           
                                            
                                                                    
                                                                       
                                
                                                                   
     */

    char a = text[i];
    char b = text[j];

    switch (a) {
        case ' ':
        case '.':
        case ',':
        case ':':
        case ';':
        case '\'':
        case '!':
        case '?':
        case '-':
            return palindrome3(text, i+1, j);
            break;
    }

    switch (b) {
        case ' ':
        case '.':
        case ',':
        case ':':
        case ';':
        case '\'':
        case '!':
        case '?':
        case '-':
            return palindrome3(text, i, j-1);
            break;
    }

    if (a > 64 && a < 91)
        a += 32;
    if (b > 64 && b < 91)
        b += 32;

    if (i == j) {
        return true;
    } else if (j - i < 2) {
        return a == b;
    } else {
        return a == b && palindrome3(text, i+1, j-1);
    }
}

bool match_chars(string chars, int i, string source, int j) {
    assert(chars.length() > 0);
    assert(i >= 0);
    assert(source.length() > 0);
    assert(j >= 0);
    /*               
                                                                
                             
                                                                         
                                                     
                                                                               
                                
                                                                               
                                 
     */

    bool last_char = (chars.length() - i == 1);
    bool last_source = (source.length() - j == 1);

    if (!last_char && last_source) {
        return false;
    } else if (last_char && last_source) {
        return chars[i] == source[j];
    } else {
        if (chars[i] == source[j]) {
            if (last_char) {
                return true;
            } else {
                return match_chars(chars, ++i, source, j);
            }
        } else {
            return match_chars(chars, i, source, ++j);
        }
    }
}

int main(int argc, char* argv[]) {
    string palindrome, chars, source;

    if (argc < 6) {
        cerr << "Usage: ./a.out x n palindrome chars source" << endl;
    } else {
        cout << argv[1] << '^' << argv[2] << " = " <<
            power(stod(argv[1]), stoul(argv[2])) << endl;
        cout << argv[1] << '^' << argv[2] << " = " <<
            opti_power(stod(argv[1]), stoul(argv[2])) << endl;
        palindrome = argv[3];
        cout << palindrome1(palindrome, 0, palindrome.length()-1) << endl;
        cout << palindrome2(palindrome, 0, palindrome.length()-1) << endl;
        cout << palindrome3(palindrome, 0, palindrome.length()-1) << endl;
        chars = argv[4];
        source = argv[5];
        cout << match_chars(chars, 0, source, 0) << endl;
    }
}

