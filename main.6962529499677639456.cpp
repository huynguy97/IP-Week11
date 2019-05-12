#include <iostream>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

double power (double x, int n)
{
    //             
    assert (n >= 0 && x >= 0);
    //               
    //                                     

    if (n == 0)
        return 1;
    else
        return x*power(x, n-1);
}

double effective_power(double x, int n, int i, double a)
{
    //             
    assert(i > 0 && x >= 0 && a >= 0 && n>=0);
    //              
    //                                     

    if(n == 0) return 1;
    else if (n > 0)
    {
        if (i == n) return 1;
        if (i*2 <= n)
        {
            x=x*x;
            return effective_power(x, n, i*2,a);
        }
        else return x*power(a,n-i);
    }
}

bool palindrome1 (string text, int i, int j)
{
    //             
    assert(true);
    //              
    //                                                             

    if (text.size() == 1)
        return true;

    if (i >= j)
        return true;

    if (text[i] != text[j])
        return false;

    return palindrome1 (text, i+1, j-1);
}

void sensitive(string& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = tolower(a[i]);
    }
}

bool palindrome2 (string text, int i, int j)
{
    //             
    assert(true);
    //              
    //                                                                                                  

    string new_string2;
    new_string2 = text;
    sensitive (new_string2);
    if (new_string2.size() == 1)
        return true;

    if (i >= j)
        return true;

    if (new_string2[i] != new_string2[j])
        return false;

    return palindrome1 (text, i+1, j-1);
}

bool palindrome3 (string text, int i, int j)
{
    //             
    assert(true);
    //              
    //                                                                                                                   
    if (text.size() == 1)
        return true;
    else
    if (i >= j)
        return true;
    else
        if((text[i] == '.') || (text[i] == ',') || (text[i] == ':') || (text[i] == ';') || (text[i] == '\'') || (text[i] == '!') || (text[i] == '?') || (text[i] == '-') || (text[i] == ' '))
    {
        return palindrome3 (text, i+1, j);
    }
    else if ((text[j] == '.') || (text[j] == ',') || (text[j] == ':') || (text[j] == ';') || (text[j] == '\'') || (text[j] == '!') || (text[j] == '?') || (text[j] == '-') || (text[j] == ' '))
    {
        return palindrome3(text,i,j-1);
    }
    else
    if (text[i] != text[j])
        return false;
    else
    return palindrome3 (text, i+1, j-1);
}

bool match_chars (string chars, int i, string source, int j)
{

    for (j; j < source.size(); j++)
    {
        if (i+1 > chars.size()) return true;
        if (chars[i] == source [j])
            return match_chars (chars, i+1, source, j);
    }
    return false;
}

void ask_power()
{
    //              
    assert(true);
    //               
    //                                      
    //                                                                     

    //        
    double base;
    int macht;

    //     
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter power: ";
    cin >> macht;

    //                                         
    cout << base << " to the power of " << macht << " = " << power (base, macht)<<endl;
    cout << base << " to the power of(effective) "<< macht << " = "<< effective_power(base,macht,1,base);
}

void ask_word ()
{
    //        
    string word;

    //     
    do
    {
        cout << "Choose a word to check if it is a palindrome: " << endl;
        getline(cin, word);
    } while (word.size() == 0);
    int length = word.size()-1;
    int choice;

    //                 
    cout << "Pick a number: " << endl;
    cout << "1. Case sensitive" << endl;
    cout << "2. Case insensitive" << endl;
    cout << "3. Punctuation and Case insensitive" << endl;
    cin >> choice;

    //                      
    switch (choice)
    {
    case 1:
        if (palindrome1(word, 0, length))
            cout << word << " is a palindrome.";
        else
            cout << word << " is not a palindrome.";
        break;
    case 2:
        if (palindrome2(word, 0, length))
            cout << word << " is a palindrome.";
        else
            cout << word << " is not a palindrome.";
        break;
    case 3:
        if (palindrome3(word, 0, length))
            cout << word << " is a palindrome.";
        else
            cout << word << " is not a palindrome.";
        break;
    default:
        break;
    }
}

void ask_char()
{
    //              
    assert(true);

    //               
    //                                                   
    //                                                                                 

    //        
    string chars, sentence;

    //     
    cout << "Enter characters: ";
    cin >> chars;
    cin.ignore();
    cout << "Enter sentence: ";
    getline (cin, sentence);

    //         
    if (!match_chars(chars, 0, sentence, 0))
        cout << chars << " is not in the sentence: " << "'' " << sentence << " ''" <<" or is not in the right order.";
    else
        cout << chars << " is in the sentence: " << sentence;
}

int main()
{
    //            
    cout << "What do you want to do? (Pick a number)" << endl;
    cout << "1. Calculate power of a number." << endl;
    cout << "2. Check if a word is a palindrome." << endl;
    cout << "3. check matching characters."<<endl;

    int answer;
    cin >> answer;
    cin.ignore();

    switch (answer)
    {
        case 1:
            ask_power();
            break;
        case 2:
            ask_word();
            break;
        case 3:
            ask_char();
            break;
    }
    return 0;
}
/*                                    
                                               
                                       

                                                
*/

