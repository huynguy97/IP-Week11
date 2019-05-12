/*  
                          
                 
                     
            
  */

#include <iostream>
#include <cassert>
using namespace std;

int c = 0;

int power(double x, int n)
{
    //              
    assert(n >= 0);
    //                                                      
    c++;
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n-1);
    }
}

//                                                                             
//                                             
int efficient_power(double x, int n)
{
    //              
    assert(n >= 0);
    //                                                                                    
    c++;
    if(n == 0)
    {
        return 1;
    }

    else if(n % 2 == 0)
    {
      return efficient_power(x, n/2) *  efficient_power(x, n/2);
    }

    else
    {
        return x * power(x, n-1);
    }
}

bool palindrome1(string text, int i, int j)
{
    //              
    assert(true);
    //                                                                          
    if(i >= j)
    {
        return true;
    }

    if(text[i] != text[j])
    {
        return false;
    }

    return palindrome1(text, i+1, j-1);

}

bool palindrome2(string text, int i, int j)
{
    //              
    assert(true);
    //                                                                   
    //                                           
    if(i >= j)
    {
        return true;
    }

    if(tolower(text[i]) != tolower(text[j]))
    {

        return false;
    }

    return palindrome2(text, i+1, j-1);
}

string remove_special_chars(string str)
{
    //              
    assert(true);
    //                                                                               
    for(int i = 0; i < str.size(); ++i)
    {
        if (!((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i]<='Z')))
        {
            str[i] = '\0';
        }
        tolower(str[i]);
    }
    return str;
}

bool palindrome3(string text, int i, int j)
{
    //              
    assert(true);
    //                                                                   
    //                                                            
    string text_no_space = remove_special_chars(text);
    if(i >= j)
    {
        return true;
    }

    if(tolower(text_no_space[i]) != tolower(text_no_space[j]))
    {

        return false;
    }

    return palindrome3(text_no_space, i+1, j-1);
}

bool match_chars(string chars, int i, string source, int j)
{
    //              
    assert(true);
    //                                                                                     
    //                                                             
    //                                                                                                                                                      
    if (j == source.length()-1  )
    {
        return false;
    }

    else if (chars[i] != source[j])
    {
        if ( i <=  source.length() -1 )
        {

            return match_chars(chars, i, source, j+1);
        }
        else
        {
             i = 0;
            return match_chars(chars, i+1, source, j);
        }
    }

    else if (chars[i] == source[j])
    {
        if (i == chars.length()-1){
            return true;
        }
        else
        {
            return match_chars(chars, i+1, source, j+1);
        }
    }
    return true;
}

int main()
{
    cout << "Power calculation algorithms:\n";

    //         
    int x = 2;
    int n = 3;
    cout << "Naive implementation: the power of " << x << " to the power of " << n << "  is " << power(x,n) << ".\n";
    cout << "Number of recursive iterations: " << c << endl;

    //         
    cout << "Efficient implementation: the power of " << x << " to the power of " << n << "  is " << efficient_power(x,n) << ".\n";
    cout << "Number of recursive iterations: " << c << endl << endl;

    cout << "Palindrome algorithms:\n";

    //         
    string text = "Otto";
    bool truth1 = palindrome1(text, 0, 3);
    cout << "The truth value of string " << text << " being a palindrome using \'palindrome1\' is " << truth1 << endl;

    //         
    bool truth2 = palindrome2(text, 0, 3);
    cout << "The truth value of string " << text << " being a palindrome using \'palindrome2\' is " << truth2 << endl;

    //         
    string space_text = "Madam, I'm Adam.";
    bool truth3 = palindrome3(space_text, 0, 4);
    cout << "The truth value of string " << space_text << " being a palindrome using \'palindrome3\' is " << truth3 << endl << endl;

    //       

    cout << "Matching strings:\n";

    cout << "The truth value of the string \'abc\' matching the string \'It is a bag of cards\' is " << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    cout << "The truth value of the string \'abc\' matching the string \'It is a bag of books\' is " << match_chars("abc", 0, "It is a bag of books", 0) << endl;
    cout << "The truth value of the string \'abc\' matching the string \'It is a classy bag\' is "   << match_chars("abc", 0, "It is a classy bag", 0) << endl;

    return 0;
}

