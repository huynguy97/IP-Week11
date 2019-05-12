//                      
//                     

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int power (int x, int n){
    assert (n >= 0);
    //                                    
    if (n == 0)
        return 1;
    else
        return x * power(x, n-1);
}

int power2 (int x, int n){
    assert (n >= 0);
    //                                    
    if (n == 0)
        return 1;
    else if(n%2 == 0){
        return power2(x, n/2) * power2(x, n/2);
    }
    else
        return power2(x, n-1);
}

bool palindrome1 (string text, int i, int j)
{
    assert (i >= 0 && j >= 0);
    //                                                                                         
    if (text[i] == text[j]){
        if (i == j || i+1 == j)
            return true;
        else
            return palindrome1 (text, i+1, j-1);
    }
    else{
        return false;
    }
}

bool palindrome2 (string text, int i, int j)
{
    assert (i >= 0 && j >= 0);
    //                                                                                         
    if (text[i] == text[j] || text[i]+32 == text[j] || text[i] == text[j]+32){
        if (i == j || i+1 == j)
            return true;
        else
            return palindrome2 (text, i+1, j-1);
    }
    else{
        return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    assert (i >= 0 && j >= 0);
    //                                                                                         
    if (text[i] < 65){
        return palindrome3 (text, i+1, j);
    }
    else if (text[j] < 65){
        return palindrome3 (text, i, j-1);
    }
    else {
        if (text[i] == text[j] || text[i]+32 == text[j] || text[i] == text[j]+32){
            if (i == j || i+1 == j)
                return true;
            else
                return palindrome3 (text, i+1, j-1);
        }
        else{
            return false;
        }
    }
}

bool match_chars (string chars, int i, string source, int j){
    assert (i >= 0 && j >= 0);
    //                                                                                                                                   
    //                      
    if (i == chars.length()){
        return true;
    }
    else if (j == source.length()){
        return false;
    }
    else if (chars[i] != source[j]){
        return match_chars (chars, i, source, j+1);
    }
    else {
        return match_chars (chars, i+1, source, j+1);
    }
}

int main(){
    cout << power(2, 3) << endl;
    cout << power2(2, 3) << endl;
    if (palindrome3 ("o.Tto", 0, 4))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if (match_chars("abc", 0, "It is a bag of cards", 0))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

