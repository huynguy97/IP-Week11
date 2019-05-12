#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <math.h>
#include <tuple>

using namespace std;

//                               

int counter_1a=0, counter_1b=0;

//      
double power(double x, int n)
{
    //               
    assert(n>=0);
    /*                
                                                       */
    counter_1a++;
    if (n==0)
    {
        return 1;
    }
    else
    {
        return x*power(x,n-1);
    }
}

double power2 (double x, int n)
{
    //               
    assert(n>=0);
    /*                
                                                                      */
    counter_1b++;
    if (n==1)
    {
        return x;
    }
    else
    {
        if (n%2==0)
        {
            double a= power2(x,n/2);
            return a*a;
        }
        else
        {
            return x*power2(x,n-1);
        }
    }
}

//      
bool palindrome1 (string text, int i, int j)
{
    //               
    assert(i>=0 && j>=0 && j>=i);
    /*                
                                                                                                              
                                                            */
    if (text[i]!=text[j])
    {
        return false;
    }
    else
    {
        if (i==j ||(j-i)==1)
        {
            return true;
        }
        else
        {
            palindrome1(text, i+1, j-1);
        }
    }
}

bool palindrome2 (string text, int i, int j)
{
    //               
    assert(i>=0 && j>=0 && j>=i);
    /*                
                                                                                                                  
                                                            */
    if (tolower(text[i])!=tolower(text[j]))
    {
        return false;
    }
    else
    {
        if (i==j ||(j-i)==1)
        {
            return true;
        }
        else
        {
            palindrome2(text, i+1, j-1);
        }
    }
}

bool palindrome3 (string text, int i, int j)
{
    //               
    assert(i>=0 && j>=0 && j>=i);
    /*                
                                                                                                                                               
                                                                                                   */
    string test=" .,:;!?-\\";
    for (int k=0; k<=8; k++)
    {
        if (text[i]==test[k])
        {
            i++;
        }
        else if (text[j]==test[k])
        {
            j--;
        }
    }
    if (tolower(text[i])!=tolower(text[j]))
    {
        return false;
    }
    else
    {
        if (i==j ||(j-i)==1)
        {
            return true;
        }
        else
        {
            palindrome3(text, i+1, j-1);
        }
    }
}

//      

bool match_chars (string chars, int i, string source, int j)
{
    //               
    assert((chars.length()>=i) && (source.length()>=j) && i>=0 && j>=0);
    /*                
                                                                                                                                         
                                                                      
    */
    if (i>=chars.length())
    {
        return true;
    }
    else
    {
        string source_new=source.substr(j,source.length());
        size_t found = source_new.find(chars[i]);
        if (found==string::npos)
        {
            return false;
        }
        else
        {
            return match_chars (chars, i+1, source, found);
        }
    }
}

int main()
{
    //      
    int _1a=power(2,8);
    int _1b=power2(2,8);
    cout << "2 to the power 8 is: " << _1a << " algorithm 1a uses: " << counter_1a << " steps." << endl;
    cout << "2 to the power 8 is: " << _1b <<" algorithm 1b uses: " << counter_1b << " steps." << endl;

    //      
    if (palindrome1("Otto", 0, 3))
    {
        cout << "This is a palindrome";
    }
    else
    {
        cout << "This is NOT a palindrome";
    }
    cout << ", this was tested with palindrome1." << endl;

    if (palindrome2("Otto", 0, 3))
    {
        cout << "This is a palindrome";
    }
    else
    {
        cout << "This is NOT a palindrome";
    }
    cout << ", this was tested with palindrome2." << endl;

    if (palindrome3("Madam, I'm Adam.", 0, 15))
    {
        cout << "This is a palindrome";
    }
    else
    {
        cout << "This is NOT a palindrome";
    }
    cout << ", this was tested with palindrome3." << endl;

    //      
    if (match_chars ("abc", 0, "It is a classy bag", 0))
    {
        cout << "This is a match";
    }
    else
    {
        cout << "This is NOT a match";
    }
    cout << ", this was tested with match_chars." << endl;

}

