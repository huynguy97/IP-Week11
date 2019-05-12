//                       
//                        

#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)
{
    cout << x << n << endl;
    //             
    assert(x > 0 && n >= 0);
    //              
    //                                                                                     
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
            }bool match_chars(string chars, int i, string source, int j) {
//              
    assert(true);
//                                                                                                           
    if(i > chars.length()-1) {bool match_chars(string chars, int i, string source, int j) {
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
        }
        return match_chars(chars,i+1,source,j+1);
    }
}
    if (n == 0)
    {
       return 1.0;
    }
    elsebool match_chars(string chars, int i, string source, int j) {
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
    {
        if (n % 2 == 0)
        {
            return power(power(x, n*0.5),2);
        }
        return x * power(x, n-1);
    }
}

bool palindrome1 (string text, int i, int j) {
//              
    assert(true);
//                                                                             
    if (i == j) {
       return true;
    }
    if (i - j == 1) {
        return text[i] == text[j];
    }
    return (text[i] == text[j]  && palindrome1(text, i+1, j-1) );
}

bool palindrome2 (string text, int i, int j) {
//              
    assert(true);
//                                                                             
    if (i == j) {
       return true;
    }
    if (i - j == 1) {
        return text[i] == text[j] || text[i] == text[j]^' ';
    }
    return ((text[i] == text[j]  || text[i] == text[j]^' ' && palindrome2(text, i+1, j-1) ));
}

bool palindrome3 (string text, int i, int j) {
//              
    assert(true);
//                                                                             
    if (text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == '-' || text[i] == ' ')
    {
        palindrome3(text, i+1, j);
    }
    if (text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-' || text[j] == ' ')
    {
        palindrome3(text, i, j-1);
    }
    if (i == j) {
       return true;
    }
    if (i - j == 1) {
        return text[i] == text[j] || text[i] == text[j]^' ';
    }
    return ((text[i] == text[j]  || text[i] == text[j]^' ' && palindrome3(text, i+1, j-1) ));
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

int main()
{
    string a;
    string b;
    cout << "Give input: " << endl;
    cin >> a;
    cout << "Give source: " << endl;
    cin >> b;
    cout << match_chars(a, 0, b, 0);
}

