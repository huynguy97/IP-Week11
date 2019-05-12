#include <iostream>
#include <cassert>

using namespace std;

//                                          
//                                          

int power(int x, int n){
    //             
    assert(true);
    if(n==0){
        return 1;
    } else {
        return x * power(x, n-1);
    }
}

int power2(int x, int n)
{
    //               
    assert(n >= 0);
    //                
    //           
    //                                                              
    if (n==0)
    {
        return 1;
    }else{
        if(n%2==0)
        {
            return power2(x, n/2) * power2(x, n/2);
        }else{
            return x * power2(x, n-1);
        }
    }
}

bool palindrome(string text, int i, int j){
    if(i >= j){
        return true;
    } else if(text[i] != text[j]){
        return false;
    } else {
        return palindrome(text, i+1, j-1);
    }
}

bool palindrome2(string text, int i, int j){
    char x = text[i];
    char y = text[j];
    if(x < 97){
        x += 32;
    }
    if(y < 97){
        y += 32;
    }
    if(i >= j)
        return true;
    else if(x != y)
        return false;
    else
        return palindrome2(text,i+1,j-1);
}

bool palindrome3(string text, int i, int j){
    if(text[i] < 65)
        return palindrome3(text,i+1,j);
    if(text[j] < 65)
        return palindrome3(text,i,j-1);

    char x = text[i];
    char y = text[j];

    if(x > 64 && x < 97)
        x += 32;
    if(y > 64 && y < 97)
        y += 32;

    if(i >= j)
        return true;
    else if(x != y)
        return false;
    else
        return palindrome3(text,i+1,j-1);
}

bool match_chars(string chars, int i, string source, int j){
    if(i == chars.length()){
        return true;
    } else if(chars[i] == source[j]){
        return match_chars(chars, i+1, source, j);
    } else if(j >= source.length()-1){
        return false;
    } else{
        return match_chars(chars, i, source, j+1);
    }

}

int main()
{
    cout << power(2,2) << endl;
    cout << power2(2,9) << endl;
    cout << palindrome("otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << palindrome3 ("Madam, I'm Ada.", 0, 14) << endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    return 0;
}

