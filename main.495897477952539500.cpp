#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//                                                       
void NoSpace (string& text, int& i, int& j){
    //     
    assert(i < j);
    //                                                                                   
    int NewI = i;
    int NewJ = j;

    string NewText = "";
    for (int k = 0; k <= text.length(); k ++)
        if (text[k] >= 65 && text[k] <= 90 || text[k] >= 97 && text[k] <= 122)
            NewText += text[k];
        else{
            if (k <= i && k < j) {
                NewI -= 1;
                NewJ -= 1;
            }
            if (k > i && k <= j)
                NewJ -= 1;
        }
    text = NewText;
    i = NewI;
    j = NewJ;
}

int power(int x, int n){
    //                                                                           
    assert(true);
    //                                 
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(x , n/2) * power(x, n/2);
    if (n > 0)
        return x * power(x, n-1);

}

bool palindrome1 (string text, int i, int j){
    //     
    assert(i > j);
    //                                                                        
    if (i == j || i + 1 == j)
        return true;
    if (text[i] == text[j])
        return palindrome1(text, i + 1, j - 1);
    else
        return false;
}

bool palindrome2 (string text, int i, int j){
    //    
    assert(i < j);
    //                                                                                                         
    if (i == j || i + 1 == j)
        return true;
    if (text[i] == text[j] || text[i] == text[j] + 32 || text[i] + 32 == text[j])
        return palindrome2(text,i + 1, j - 1);
    else
        return false;
}

bool palindrome3 (string text, int i, int j){
    //    
    assert(i > j);
    //                                                                                                      
    NoSpace(text, i, j);
    return palindrome2(text, i, j);
}

bool match_chars (string chars, int i, string source, int j) {
    //    
    assert(i < j);
    //                                                                            
    if (i == chars.length())
        return true;
    if (j == source.length())
        return false;
    if (chars[i] == source[j])
        return match_chars(chars, i + 1, source, j + 1);
    else
        return match_chars(chars, i, source, j + 1);
}

int main() {
    cout << palindrome3("Madam, I'm Adam", 0, 15) << endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;

    return 0;
}
