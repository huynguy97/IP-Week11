#include <iostream>
#include <cassert>

//                                                              
//     

using namespace std;

int naive_power(double x, int n)
{
    //               
    assert(n >= 0);

    //                                    
    if (n==0)
        return 1;
    else
        x = x*naive_power(x , n-1);
    return x;
}

//                                                                                     
int efficient_power(double x, int n)
{
    //              
    assert (n >= 0);

    //                                                
    if (n==0)
        return 1;
    if (n > 1)
    {
        if (n%2 == 0)
        {
            x = efficient_power(x,n/2);
            x = x*x;
        }
        else if (n%2 != 0)
        {
            x = x *efficient_power(x,n-1);
        }
    }
    return x;
}

bool palindrome1(string text, int i, int j)
{
	//              
	assert (i >= 0 && j >= 0);

	//                                                                                       
	if (j > i)
    {
        if(text[i] == text[j])
        {
            return palindrome1(text, i+1, j-1);
        }
        return false;
    }

    return true;
}

bool palindrome2(string text, int i, int j)
{
	//              
	assert (i >= 0 && j >= 0);

	//                                                                                           
	if (j > i)
    {
        if(text[i] == text[j])
            return palindrome2(text, i+1, j-1);
        else if (toupper(text[i]) == text[j])
            return palindrome2(text, i+1, j-1);
        else if (tolower(text[i]) == text[j])
            return palindrome2(text, i+1, j-1);

        return false;
    }

    return true;
}

bool palindrome3(string text, int i, int j)
{
	//              
	assert (i >= 0 && j >= 0);

	//                                                                                                                   
	if (j > i)
    {
        if (tolower(text[i]) < 97 || tolower(text[i] > 122))
            return palindrome3(text, i+1, j);
        else if (tolower(text[j]) < 97 || tolower(text[j] > 122))
            return palindrome3(text, i, j-1);
        else if(tolower(text[i]) == tolower(text[j]))
            return palindrome3(text, i+1, j-1);

        return false;
    }

    return true;
}

bool match_chars(string chars, int i, string source, int j)
{
    //               
    assert (i >= 0 && j >= 0);

    //                                                                                                        
    if (i > (chars.length() - 1))
        return true;
    if (j <= (source.length() - 1))
    {
        if (chars[i] == source[j])
        {
            return match_chars(chars, i+1, source, j);
        }
        if (chars[i] != source[j])
            return match_chars(chars, i, source, j+1);
    }
    if (j > source.length() - 1)
        return false;
}

int main()
{
    cout << "What do you want to do?" << endl;
    cout << "Type 1 for naive_power" << endl << "Type 2 for efficient_power" << endl << "Type 3 for palindrome1" << endl;
    cout << "Type 4 for palindrome2" << endl << "Type 5 for palindrome3" << endl << "Type 6 for match_chars" << endl;
    cout << "Type exit to stop" << endl << endl;

    int input;
    cin >> input;

    if (input == 1)
    {
        cout << "Give a number: ";
        int x;
        cin >> x;
        cout << "to the power: ";
        int n;
        cin >> n;
        cout << endl << "Answer: " << naive_power(x, n) << endl;
    }

    if (input == 2)
    {
        cout << "Give a number: ";
        int x;
        cin >> x;
        cout << "to the power: ";
        int n;
        cin >> n;
        cout << endl << efficient_power(x, n) << endl;
    }

    if (input == 3)
    {
        cout << "Palindrome-checking! Warning: case and punctuation sensitive!" << endl << endl;
        cin.ignore();
        cout << "Enter text: ";
        string text;
        getline(cin, text);
        if (palindrome1(text, 0, (text.length() -1)))
            cout << endl << "Yeah! Palindrome baby!" << endl;
        else
            cout << endl << "Sorry. No palindrome..." << endl;
    }

    if (input == 4)
    {
        cout << "Palindrome-checking! Warning: punctuation sensitive!" << endl << endl;
        cin.ignore();
        cout << "Enter text: ";
        string text;
        getline(cin, text);
        if (palindrome2(text, 0, (text.length() -1)))
            cout << endl << "Yeah! Palindrome baby!" << endl;
        else
            cout << endl << "Sorry. No palindrome..." << endl;
    }

    if (input == 5)
    {
        cout << "Palindrome-checking!" << endl;
        cin.ignore();
        cout << "Enter text: ";
        string text;
        getline(cin, text);
        if (palindrome3(text, 0, (text.length() -1)))
            cout << endl << "Yeah! Palindrome baby!" << endl;
        else
            cout << endl << "Sorry. No palindrome..." << endl;
    }

    if (input == 6)
    {
        cout << "Enter a text: ";
        cin.ignore();
        string source;
        getline(cin, source);
        cout << "What characters do you want to find in the text: ";
        string chars;
        getline(cin, chars);
        if (match_chars(chars, 0, source, 0))
            cout << endl << "Found the characters! Congrats." << endl;
        else
            cout << endl << "Nope! Not found." << endl;
    }

    cout << endl << "See ya!" << endl;

    return 0;
}

