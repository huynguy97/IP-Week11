#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

//                        

double naivePower(double x, int n)
{
    //              
    assert(n >=0);
    /*               
               
    */

    if(n == 0){
        return 1;
    }
    else return (x * naivePower(x, n-1));
}

double efficientPower(double x, int n)
{
    //              
    assert(n >=0);
    /*               
                                                                               
    */

    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    else{
        double d = naivePower(x, n/2);
        if(n % 2 == 0)
            return d * d;
        else
            return x * d * d;
    }
}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert(i>=0 && j >= 0);
    /*               
                                                            
    */
    if(i>j){
        return true;
    }
    if(text[i] != text[j])
        return false;
    return palindrome1(text, i+1, j-1);
}

bool palindrome2 (string text, int i, int j)
{
    //              
    assert(i>=0 && j >= 0);
    /*               
                                                            
                    
    */
    if(i>j){
        return true;
    }
    if(toupper(text[i]) != toupper(text[j]))
        return false;
    return palindrome2(text, i+1, j-1);
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert(i>=0 && j >= 0);
    /*               
                                                            
                                                                            
                                                                                     
    */
    string punct = " .,:;!?-_'\"";
    string newstring;
    for(int k =0; k <= j; k++){
        if(punct.find(text[k]) == std::string::npos){
            newstring += text[k];
        }
    }
    return palindrome2(newstring, 0, newstring.size()-1);
}

bool match_chars (string chars, int i, string source, int j)
{
    //              
    assert(i>=0 && j >= 0);
    /*               
                                                                   
                               
    */
    if(i == chars.size())
        return true;
    if(j == source.size())
        return false;
    if(chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
    //               
    cout << "PART 1.1\n";
    cout << naivePower(2,5) << endl;
    cout << "PART 1.2\n";
    cout << efficientPower(2,5) << endl;
    cout << "PART 2.1\n";
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome1("Otto", 0, 3) << endl;
    cout << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << "PART 2.2\n";
    cout << palindrome2("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << "PART 2.3\n";
    cout << palindrome3("otto", 0, 3) << endl;
    cout << palindrome3("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << "PART 3\n";
    cout <<  match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    cout <<  match_chars ("abc", 0, "It is a bag of books", 0) << endl;
    cout <<  match_chars ("abc", 0, "It is a classy bag", 0) << endl;
    return 0;
}

