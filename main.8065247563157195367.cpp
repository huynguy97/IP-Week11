#include <iostream>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

double power (double x, int n) {
    assert(n >= 0);
    //                                        
    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n-1);
    }
}

//                                    

double power_not_so_naive(double x, int n) {
    assert (n >= 0);
    //                                       
    double result = 0;
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else {
        if (n % 2 == 0) {
            result =  power_not_so_naive(x, n/2 ) * power_not_so_naive(x, n/2 );
        } else {
            result =  power_not_so_naive(x, n/2 ) * power_not_so_naive(x, (n + 1)/2 );
        }
        return result;
    }
}

bool palindrome1 (string text, int i, int j) {
    assert (i >= 0 && j >= 0);
    //                                                                  
    //                            
    int str_length = text.length();
    char str_arr[str_length - 1];
    strcpy(str_arr, text.c_str());
    cout << endl << "i is " << i << " and j is " << j << endl;
    for (int a = 0; a < str_length; a++) {
        cout << text[a] << ' ';
        if (a == (i - 1) || a == j) {
            cout << '|' << ' ';
        }
    }
    cout << endl;
    if (i == j || i == j - 1) {
        return true;
    } else if (text[i] == text[j]){
        return palindrome1(text, i + 1, j - 1);
    } else {
        return false;
    }
}

bool palindrome2 (string text, int i, int j) {
    assert (i >= 0 && j >= 0);
    //                                                                                                                      
    //                            
    int str_length = text.length();
    char str_arr[str_length - 1];
    strcpy(str_arr, text.c_str());
    cout << endl << "i is " << i << " and j is " << j << endl;
    for (int a = 0; a < str_length; a++) {
        cout << str_arr[a] << ' ';
        if (a == (i - 1) || a == j) {
            cout << '|' << ' ';
        }
    }
    if (i == j || i == j - 1) {
        return true;
    } else if (tolower(text[i]) == tolower(text[j])){
        return palindrome2(text, i + 1, j - 1);
    } else {
        return false;
    }
}

bool palindrome3(string text, int i, int j) {
    assert (i >= 0 && j >= 0);
    //                                                                                                                                                       
    //                             
    int str_length = text.length();
    char str_arr[str_length - 1];
    strcpy(str_arr, text.c_str());
    cout << endl << "i is " << i << " and j is " << j << endl;
    for (int a = 0; a < str_length; a++) {
        cout << str_arr[a] << ' ';
        if (a == (i - 1) || a == j) {
            cout << '|' << ' ';
        }
    }
    while (text[i] < 65){
        i = i + 1;
    }
    while (text[j] < 65){
        j = j - 1;
    }
    if (i == j || i == j - 1) {
        return true;
    } else if (tolower(text[i]) == tolower(text[j])){
        return palindrome3(text, i + 1, j - 1);
            } else {
                return false;
            }
}

bool match_chars (string chars, int i, string source, int j){
    (assert i >= 0 && j >= 0);
    //                                                                                                                                                        
    int chars_length = chars.length();
    int source_length = source.length();
    char chars_arr[chars_length];
    char source_arr[source_length];
    strcpy(chars_arr, chars.c_str());
    strcpy(source_arr, source.c_str());
    cout << endl << "i is " << i << " and j is " << j << endl;
        if (chars_arr[i] == source_arr[j]) {
            if (i == chars_length - 1) {
                return true;
            } else {
                return match_chars(chars, ++i, source, ++j);
            }
        } else if(j == source_length - 1) {
            return false;
        } else {
            return match_chars(chars, i, source, ++j);
        }
}

int main()
{
    cout << power(4, 1) << endl;
    cout << power_not_so_naive(4, 1) << endl;
    string test = "Madam, I'm Adam.";
    cout << endl << "palindrome1 result: "<< palindrome1(test, 0, test.length() - 1) << endl << endl;
    cout << endl << "palindrome2 result: "<< palindrome2(test, 0, test.length() - 1) << endl << endl;
    cout << endl << "palindrome3 result: "<< palindrome3(test, 0, test.length() - 1) << endl << endl;
    cout << endl << "match_chars: " << match_chars("abc", 0, "It is a bag of books", 0);
    return 0;
}

