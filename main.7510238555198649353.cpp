//                                       
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

int power (int x, int n)
{
    //    
    assert (n >= 0);

    if (n == 0) return 1;

    return x * power(x, n - 1);
}

/*
                             
                                                        
*/
int power_better (int x, int n)
{
    //    
    assert (n >= 0);

    if (n == 0) return  1;

    if (n == 1) return  x;

    if (n % 2 == 0)
        return power_better(x * x, n / 2);
    return x * power_better(x * x, (n - 1) / 2);
}

bool palindrome1 (string text, int i, int j)
{
    /*    */
    assert(i >= 0 && j < text.length());

    bool comp = text[i] == text[j];

    if (i == j || i + 1 == j)
        return comp;

    if (comp)
        return palindrome1(text, i + 1, j - 1);

    return false;
}

bool palindrome2 (string text, int i, int j)
{
    /*    */
    assert(i >= 0 && j < text.length());

    bool comp = toupper(text[i]) == toupper(text[j]);

    if (i == j || i + 1 == j)
        return comp;

    if (comp)
        return palindrome1(text, i + 1, j - 1);

    return false;
}

bool palindrome3 (string text, int i, int j)
{
    /*    */
    assert(i >= 0 && j < text.length());

    bool skip = false;
    if(!isalpha(text[i]))
    {
        i++;
        skip = true;
    }

    if(!isalpha(text[j]))
    {
        j--;
        skip = true;
    }

    if(skip)
        return palindrome3(text, i, j);

    bool comp = toupper(text[i]) == toupper(text[j]);

    if (i == j || i + 1 == j)
        return comp;

    if (comp)
        return palindrome3(text, i + 1, j - 1);

    return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    /*    */
    assert (i >= 0 && j >= 0 && i < chars.length() && j < source.length());

    if(source.length() - j < chars.length() - i)
        return false;

    if(chars[i] == source[j])
    {
        if(i == chars.length() - 1)
            return true;
        if(j == source.length() - 1)
            return false;
        return match_chars(chars, i + 1, source, j + 1);
    }
    if(j == source.length() - 1)
        return false;
    return match_chars(chars, i, source, j + 1);
}

int main()
{
    cout << power_better(5, 5) << endl;
    cout << "Palindrome 1:\n";
    cout << (palindrome1("lepel", 0, 4) ? "true" : "false") << endl;
    cout << (palindrome1("otto", 0, 3) ? "true" : "false") << endl;
    cout << (palindrome1("Otto", 0, 3) ? "true" : "false") << endl;
    cout << (palindrome1("Madam, I'm Adam.", 0, 15) ? "true" : "false") << endl;

    cout << "Palindrome 2\n";
    cout << (palindrome2("Otto", 0, 3) ? "true" : "false") << endl;

    cout << "Palindrome 3:\n";
    cout << (palindrome3("Madam, I'm Adam.", 0, 15) ? "true" : "false") << endl;

    cout << "Match chars 1:\n";
    cout << (match_chars("abc", 0, "It is a bag of cards", 0) ? "true" : "false") << endl;
    cout << (match_chars("abc", 0, "It is a bag of books", 0) ? "true" : "false") << endl;
    cout << (match_chars("abc", 0, "It is a classy bag", 0) ? "true" : "false") << endl;
    cout << (match_chars("abcddd", 0, "It is a classy bag which my dad gave me the first day of my elementary school.", 0) ? "true" : "false") << endl;

    return 0;
}

