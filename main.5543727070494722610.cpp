#include <iostream>
#include <cassert>
#include <string>
using namespace std;

//                                 

/*
      
                                                                        
                                                                                        
                                                                                                                       
       
*/

/*
         
                                                                                                           
                                                                                                                                                    
*/

int naive_power (int x, int n)
{
    //               
    assert(n >= 0);
    /*                
                            */

    if (n == 0)
        return 1;
    else
        return x * naive_power(x , n-1);
}

int efficient_power (int x, int n)
{
    //               
    assert (n >= 0);
    /*                
                            */

    if (n == 1)
        return x;
    else
    {
        int result = 0;
        if (n % 2 == 1)
        {
            result = efficient_power(x, n/2);
            return result * result * x;            //                                                                                                                           
        }
        else
           {
            result = efficient_power(x, n/2);           //                                                                                                 
            return result * result;
           }
    }
}

bool palindrome1 (string text, int i, int j)
{
    //               
    assert (i >= 0 && i < static_cast<int>(text.length()) && j >= 0 && j < static_cast<int>(text.length()));    //                                                                                   
    //                
    /*                                                                                                              */

    if (i == j)                                 //                                                                                                  
        return true;
    else if (i == j+1)
        return text[i] == text[j];

    else if (text[i] == text[j])
        return palindrome1(text, i+1, j-1);     //                                                       
    else
        return false;
}

bool palindrome2 (string text, int i, int j)
{
    //               
    assert (i >= 0 && i < static_cast<int>(text.length()) && j >= 0 && j < static_cast<int>(text.length()));
    //                
    /*                                                                                                                */

    if (i == j)
        return true;

    char a = text[i];
    char b = text[j];               //                                                                                                                                  
    if (a >= 65 && a <= 90)         //                                                                                                                             
        a = a + 32;

    if (b >= 65 && b <= 90)
        b = b + 32;

    if (i == j+1)
        return a == text[j];

    else if (a == text[j])
        return palindrome2(text, i+1, j-1);
    else
        return false;
}

bool palindrome3 (string text, int i, int j)
{
    //               
    assert (i >= 0 && i < static_cast<int>(text.length()) && j >= 0 && j < static_cast<int>(text.length()));
    //                
    /*                                                                                                                  */

    if (i == j)
        return true;

    char a = text[i];
    char b = text[j];
    if (a < 65 || (a > 90 && a < 97) || a > 122)        //                                                                                                        
        return palindrome3(text, i+1, j);

    if (b < 65 || (b > 90 && b < 97) || b > 122)
        return palindrome3(text, i, j-1);

    if (a >= 65 && a <= 90)             //                                          
        a = a + 32;

    if (b >= 65 && b <= 90)
        b = b + 32;

    if (i == j+1)
        return a == b;

    else if (a == b)
        return palindrome3(text, i+1, j-1);
    else
        return false;
}

bool match_chars (string sub, int i, string source, int j)
{//              
    int sublength = static_cast<int>(sub.length());
    int sourcelength = static_cast<int>(source.length());

    assert (i >= 0 && i <= sublength && j >= 0 && j <= sourcelength) ;
/*                
                                                                                                                                                                      
*/
    if (i ==  sublength)
        return true;
    if (j == sourcelength)
        return false;

    if (sub[i] == source[j])
        i++;
    return match_chars(sub, i, source, j+1);
}

//                                                                               

int main()
{
    cout << "Running naive_power: " << naive_power(5,5) << endl;
    cout << "Running efficient_power: " << efficient_power(5,5) << endl;

    if (palindrome1("otto", 0 , 3))
        cout << "This is a palindrome1" << endl;
    else
        cout << "This is not a palindrome1" << endl;

    if (palindrome2("Otto", 0 , 3))
        cout << "This is a palindrome2" << endl;
    else
        cout << "This is not a palindrome2" << endl;

    if (palindrome3("Madam, I'm Adam.", 0 , 15))
        cout << "This is a palindrome3" << endl;
    else
        cout << "This is not a palindrome3" << endl;

    if (match_chars ("abc", 0, "It is a bag of cards", 0))
        cout << "Matches" << endl;
    else
        cout << "Does not match" << endl;

    return 0;
}

