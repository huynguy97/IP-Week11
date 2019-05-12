#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//                                                                                                                                                  

double naivepower (double x, int n)
{
    //              
    assert (n >= 0);
    //                             
    if (n == 0)
    {
     return 1;
    }
    return x*naivepower(x,n-1);
}

double efficientpower (double x, int n)
{
      //              
    assert (n >= 0);
    //                             
    if (n==0)
    {
        return 1;
    }

    if (n%2 == 0)
    {
        double temp = efficientpower(x,n/2);
        return temp * temp;
    }
    else
    {
         return x*efficientpower(x,n-1);
    }
}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert(text.length() >= 0 &&  i>=0 &&  j >=0);
    //                                                                                         
    if (i==j)
    {
        return true;
    }
    if (j-i==1)
    {
        return (text.at(i) == text.at (j));
    }
    if (text.at(i) == text.at (j))
    {
        return palindrome1(text, i+1, j-1);

    }
    return false;
}
bool checkChar(char a, char b)
{//              
    assert(true);
    //                                                                                                                 
    int ca = static_cast<int>(a);
    int cb = static_cast<int>(b);
    if (ca >= 97 && ca <= 122)
    {
        ca -= 32;
    }
    if (cb >= 97 && cb <= 122)
    {
        cb -= 32;
    }
    return (ca == cb);
}

bool palindrome2(string text, int i, int j)
{    //              
    assert (text.length() >= 0 &&  i>=0 &&  j >=0);
    //                                                                                          
    if (i==j)
    {
        return true;
    }
    if (j-i==1)
    {
        return (checkChar(text.at(i),text.at(j)));
    }
    if (checkChar(text.at(i), text.at(j)))
    {
        return palindrome2(text, i+1, j-1);

    }
    return false;
}

bool ignore(char c)
{
    //             
    assert (true);
    //                                                                  
    int ic = static_cast<int>(c);
    return !((ic >= 65 && ic <= 90) || (ic >= 97 && ic <= 122));

}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert (text.length() >= 0 &&  i>=0 &&  j >=0);
    //                                                                                                                                
    if (i == j){
        return true;
    }
    if (ignore(text.at(i))){
        return palindrome3(text, i+1,j);
    }
    if (ignore(text.at(j))){
        return palindrome3(text, i,j-1);
    }
    if (i+1 == j){
        return (checkChar(text.at(i),text.at(j)));
    }
    if (checkChar(text.at(i),text.at(j))){
        return palindrome3(text, i+1,j-1);
    } else {
        return false;
    }
}

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(chars.length() >= 0 && i >= 0 && source.length() >= 0 && j >=0);
    //                                                                                           
 if (i >= chars.length())
 {
     return true;
 }
 if (j >= source.length())
 {
     return false;
 }
 if (chars.at(i) == source.at(j))
 {
     return match_chars(chars, i+1, source, j+1);
 }
 return match_chars(chars, i, source, j+1);
}

int main()
{

    cout << "Naive power: " << endl;
    cout << "1^10: " << naivepower(1.0,10) << endl;
    cout << "2^0: " << naivepower(2.0,0) << endl;
    cout << "2^23: " << naivepower(2.0,23) << endl;
    cout << "2.5^30: " << naivepower(2.5,30) << endl;
    cout << endl << endl;

    cout << "Efficient power: " << endl;
    cout << "1^10: " << efficientpower(1.0, 10) << endl;
    cout << "2^0: " << efficientpower(2.0, 0) << endl;
    cout << "2^23: " << efficientpower(2.0, 23) << endl;
    cout << "2.5^30: " << efficientpower(2.5, 30) << endl;
    cout << endl << endl;

    cout << "Straight Palindrome (1): " << endl;
    cout << "otto - " << palindrome1 ("otto", 0, 3) << endl;
    cout << "Otto - " << palindrome1 ("Otto", 0, 3) << endl;
    cout << "Madam, I'm Adam. - " << palindrome1 ("Madam, I'm Adam.", 0, 15)  << endl;
    cout << endl << endl;

    cout << "Case-insensitive Palindrome (2): " << endl;
    cout << "otto - " << palindrome2 ("otto", 0, 3) << endl;
    cout << "Otto - " << palindrome2 ("Otto", 0, 3) << endl;
    cout << "Madam, I'm Adam. - " << palindrome2 ("Madam, I'm Adam.", 0, 15)  << endl;
    cout << endl << endl;

    cout << "Case-and-space-insensitive Palindrome (3): " << endl;
    cout << "otto - " << palindrome3 ("otto", 0, 3) << endl;
    cout << "Otto - " << palindrome3 ("Otto", 0, 3) << endl;
    cout << "Madam, I'm Adam. - " << palindrome3 ("Madam, I'm Adam.", 0, 15)  << endl;
    cout << endl << endl;

    cout << "Matching characters: " << endl;
    cout << "abc - It is a bag of cards - " << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    cout << "abc - It is a bag of books - " << match_chars("abc", 0, "It is a bag of books", 0) << endl;
    cout << "abc - It is a classy bag - " << match_chars("abc", 0, "It is a classy bag", 0) << endl;

    return 0;
}

