//                                               

#include <iostream>
#include <cassert>
#include <time.h>

using namespace std;

template <typename NUMERIC>
NUMERIC power1(NUMERIC x, int n){
    //               
    assert(n >= 0);
    //                                               
    if (n == 0){
        return static_cast<NUMERIC>(1);
    } else {
        return x*power1(x, n-1);
    }
} //                                           

template <typename NUMERIC>
NUMERIC power2(NUMERIC x, int n){
    //               
    assert(n >= 0);
    //                                               
    if (n == 0){
        return static_cast<NUMERIC>(1);
    } else {
        NUMERIC pow = power2(x, n/2);
        if (n%2 == 0){
            return pow*pow;
        }
        return x*pow*pow;
    }
} //                                                

bool palindrome1(string text, int i, int j){
    //                
    assert(i >= 0 && i < static_cast<int>(text.size())
           && j >= 0 && j < static_cast<int>(text.size()));
    //                                                               
    if (i >= j){
        return true;
    } else {
        return text[i] == text[j] && palindrome1(text, i+1, j-1);
    }
}

bool palindrome2(string text, int i, int j){
    //                
    assert(i >= 0 && i < static_cast<int>(text.size())
           && j >= 0 && j < static_cast<int>(text.size()));
    //                                                               
    //                                                   
    if (i >= j){
        return true;
    } else {
        string temp = text;
        if (temp[i] >= 65 && temp[i] <= 90) temp[i] = temp[i] + (97 - 65);
        if (temp[j] >= 65 && temp[j] <= 90) temp[j] = temp[j] + (97 - 65);
        return temp[i] == temp[j] && palindrome2(temp, i+1, j-1);
    }
}

bool palindrome3(string text, int i, int j){
    //                
    assert(i >= 0 && i < static_cast<int>(text.size())
           && j >= 0 && j < static_cast<int>(text.size()));
    //                                                               
    //                                                                                        
    if (i >= j){
        return true;
    } else {
        if (text[i] < 65 || (text[i] > 90 && text[i] < 97) || text[i] > 122){
            return palindrome3(text, i+1, j);
        } else if (text[j] < 65 || (text[j] > 90 && text[j] < 97) || text[j] > 122){
            return palindrome3(text, i, j-1);
        }
        string temp = text;
        if (temp[i] >= 65 && temp[i] <= 90) temp[i] = temp[i] + (97 - 65);
        if (temp[j] >= 65 && temp[j] <= 90) temp[j] = temp[j] + (97 - 65);
        return temp[i] == temp[j] && palindrome3(temp, i+1, j-1);
    }
}

bool match_chars (string chars, int i, string source, int j){
    //                
    assert(i >= 0 && j >= 0);
    //                                                                                        
    if (i > static_cast<int>(chars.size())-1){
        return true;
    } else if (j > static_cast<int>(source.size()-1)){
        return false;
    } else {
        if (chars[i] == source[j]){
            return match_chars(chars, i+1, source, j+1);
        }
        return match_chars(chars, i, source, j+1);
    }
}

int main(){
    double a = 1.001;
    int n = 40000;

    clock_t before = clock();
    cout << "power1(" << a << ", " << n << ") = ";
    cout << power1(a, n) << endl;
    clock_t after = clock();
    cout << "Runtime: " << static_cast<double>(after - before)/CLOCKS_PER_SEC << " s" << endl << endl;

    before = clock();
    cout << "power2(" << a << ", " << n << ") = ";
    cout << power2(a, n) << endl;
    after = clock();
    cout << "Runtime: " << static_cast<double>(after - before)/CLOCKS_PER_SEC << " s" << endl << endl;

    cout << "power1(a,n) is O(n), whereas power2(a,n) is O(log(n))" << endl << endl;

    string text = "lepel";
    cout << "palindrome1(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome1(text, 0, static_cast<int>(text.size()-1)) << endl;
    cout << "palindrome2(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome2(text, 0, static_cast<int>(text.size()-1)) << endl;
    cout << "palindrome3(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome3(text, 0, static_cast<int>(text.size()-1)) << endl << endl;

    text = "Otto";
    cout << "palindrome1(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome1(text, 0, static_cast<int>(text.size()-1)) << endl;
    cout << "palindrome2(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome2(text, 0, static_cast<int>(text.size()-1)) << endl;
    cout << "palindrome3(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome3(text, 0, static_cast<int>(text.size()-1)) << endl << endl;

    text = "Madam, I'm Adam.";
    cout << "palindrome1(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome1(text, 0, static_cast<int>(text.size()-1)) << endl;
    cout << "palindrome2(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome2(text, 0, static_cast<int>(text.size()-1)) << endl;
    cout << "palindrome3(" << text << ", 0, " << text.size()-1 << ") = ";
    cout << palindrome3(text, 0, static_cast<int>(text.size()-1)) << endl << endl;

    string abc = "abc";
    string source = "It is a bag of cards";
    cout << "match_chars(" << abc << ", 0, " << source << ", 0) = ";
    cout << match_chars(abc, 0, source, 0) << endl;
    source = "It is a bag of books";
    cout << "match_chars(" << abc << ", 0, " << source << ", 0) = ";
    cout << match_chars(abc, 0, source, 0) << endl;
    source = "It is a classy bag";
    cout << "match_chars(" << abc << ", 0, " << source << ", 0) = ";
    cout << match_chars(abc, 0, source, 0) << endl << endl;
    return 0;
}

