//                       

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

double power(double x, int n){
//                            
    assert(n >= 0);
//                    

    if(n == 0)
        return 1;
    else
        return x * power(x, n-1);
}

//                                                 
double power_efficient(double x, int n){
//                            
    assert(n >= 0);
//                    

    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return power_efficient(x, n/2) * power_efficient(x, n/2);
    else
        return x * power_efficient(x, n-1);
}

bool palindrome1(string text, int i, int j){
//                               
    assert(i >= 0 && j >= 0);
//                                                          

    if(i == j)
        return true;
    else if(i > j)
        return true;
    else
        return text[i] == text[j] && palindrome1(text, i+1, j-1);
}

bool palindrome2(string text, int i, int j){
//                                
    assert(i >= 0 && j >= 0);
//                                                                                                    
//                                                                             

    string newText = "";
    locale loc;

    for(int x = 0; x <= j; x++)
        newText += tolower(text[x], loc);

    return palindrome1(newText, i, j);
}

bool is_letter(char a){
//      
    assert(true);
//                                                  

    if(a - 'a' >= 0 && a - 'z' <= 0)
        return true;
    if(a - 'A' >= 0 && a - 'Z' <= 0)
        return true;

    return false;
}

bool palindrome3(string text, int i, int j){
//                                
    assert(i >= 0 && j >= 0);
//                                                                                                     
//                                                                                                            
//                                                                                                    

    string newText = "";
    int newJ = j - i;

    for(int x = i; x <= j; x++)
        if(is_letter(text[x]))
            newText += text[x];
        else
            newJ--;

    return palindrome2(newText, 0, newJ);
}

bool match_chars(string chars, int i, string source, int j){
//                                
    assert(i >= 0 && j >= 0);
//                                                                                              
//                                                                                         

    if(i == chars.length())
        return true;
    if(j == source.length())
        return false;

    if(chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main(){

    cout << power(2, 10) << endl;
    cout << power_efficient(2, 10) << endl;
    cout << palindrome1("lepel", 0, 4) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << match_chars("abc", 0, "It is a bag of cards.", 0) << endl;

    return 0;
}

