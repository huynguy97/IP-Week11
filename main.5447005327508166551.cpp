//                        

#include <iostream>

using namespace std;

double power (double x, int n){
    if (n == 0){
        return 1;
    }
    else if (n > 0)
       return x * power(x, n-1);
}

double efficient (double x, int n){
      if (n == 0){
        return 1;
    }

    else if (n%2 == 0){
        double a = efficient(x, n/2);
        return a * a;
    }

    else if (n > 0){
        return x * efficient(x, n-1);
    }

}

bool palindrome1 (string text, int i, int j){
    if (text [i] != text [j] && i <= j){
        return false;
    }

    else if (text [i] == text [j] && (i == j || i == j-1)){
        return true;
    }

    else if (text[i] == text[j] && i < j){
        return palindrome1(text, i+1, j-1);
    }
}

bool palindrome2 (string text, int i, int j){

    if (toupper(text[i]) != toupper(text[j]) && i <= j){
        return false;
    }

    else if (toupper(text [i]) == toupper(text [j]) || (i == j || i == j-1)){
        return true;
    }

    else if (toupper(text[i]) == toupper(text[j]) && i < j){
        return palindrome1(text, i+1, j-1);
    }
}

bool palindrome3 (string text, int i, int j){
    while ((ispunct(text[i]) || isspace(text[i])) && i < j){
        i++;
    }

     while ((ispunct(text[i]) || isspace(text[i])) && i < j){
        j--;
    }

    if (toupper(text[i]) != toupper(text[j]) && i <= j){
        return false;
    }

    else if (toupper(text [i]) == toupper(text [j]) || (i == j || i == j-1)){
        return true;
    }

    else if (toupper(text[i]) == toupper(text[j]) && i < j){
        return palindrome1(text, i+1, j-1);
    }
}

bool match_chars (string chars, int i, string source, int j){
    if (chars.length() == i + 1){
        return true;
    }

    for (int k = 0; k < j; k++){
        if (chars[i] == source[k]){
            return match_chars(chars, i+1, source, j);
        }

    }
    return false;
}

int main()
{
    string text;
    string chars;
    string source;

    cin >> text;
    cin >> chars;
    cin >> source;

    int i = 0;
    int j = text.length() - 1;

    palindrome1(text, i, j);
    palindrome2(text, i, j);
    palindrome3(text, i, j);
    match_chars(chars, i, source, j);

    return 0;
}

