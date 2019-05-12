#include <iostream>
#include <assert.h>
#include <cctype>

using namespace std;
//                                                       

double naive_power (double x, int n)
{//             
    assert (n >= 0);
//                                                                                    

    if(n <= 0)
        return 1;
    else{
        return x * naive_power ( x, n-1) ;
        }
}
double power (double x, int n)
{//             
    assert (n >= 0);
//                                                                                                                                 
//                                                                                                                 
//                                            
    int help = n%2;
    if(n <= 0)
        return 1;
    else if (n <= 1)
        return x;
    else{
        if ( help == 0)
        {
             return power ( x, n/2)* power ( x, n/2) ;
        }
        else
        {
            return power (x, n/2 +1) * power ( x, n/2 );
        }
        }
}

bool palindrome1 (string text, int i, int j)
{//             
    assert (i >= 0 && j > 0);
//                                                                                                                                      
    if (i>=j)
        return true;
    else
    {
        if(text[i] == text [j])
        {
             palindrome1 (text, i+1,j-1);
        }
        else
            return false;
    }
    return true;
}

bool palindrome2 (string text, int i, int j)
{//             
    assert (i >= 0 && j > 0);
//                                                                                                                                  
    if (i>=j)
        return true;
    else
    {
        if(toupper(text[i]) == toupper(text [j]))
        {
             palindrome2 (text, i+1,j-1);
        }
        else
            return false;
    }
    return true;

}

bool checking_letters (string text, int i, int j)
{//             
    assert (true);
//                                                                                                                        
    if (text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == '-'|| text[i] == ' ')
        i++;
    if (text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-'|| text[j] == ' ')
        j--;
    if(toupper(text[i]) == toupper(text [j]))
        return true;
    else
        return false;
}

bool palindrome3 (string text, int i, int j)
{//             
    assert (i >= 0 && j > 0);
//                                                                                          
    if (i>=j)
        return true;
    else
    {
        if(checking_letters (text, i, j))
        {
             palindrome3 (text, i+1,j-1);
        }
        else
            return false;
    }
    return true;
}

bool match_chars (string chars, int i, string source, int j)
{//             
    assert (i >= 0 && j >= 0);
//                                                                                                            

    if  (chars[i] == source[j])
    {
        if (i >= chars.length()-1)
            return true;
        else
        {
            return match_chars(chars, i+1, source, j+1);
        }
    }
    else
    {
        if (j >= source.length()-1)
            return false;
        else
        return match_chars (chars,i,source,j+1);
    }
}

int main ()
{
    //         
    double x = 4.2;
    int n = 3;
    string low = "lepel";
    string cap = "Lepel";
    string sentence = "Madam, I'm Adam." ;
    string source = "Somewhere over the rainbow! " ; //                 
    string chars;
    int i = 0;
    int j = 0;

    //       
    cout << naive_power (x, n)<< endl;
    cout << power (x, n)<< endl << endl;
    cout << "palindrome1:  " << low <<palindrome1 (low, 0, 4) << endl;
    cout << cap << palindrome1 (cap, 0, 4) << endl;
    cout << sentence << palindrome1 (sentence, 0, 15) << endl << endl;
    cout << "palindrome2:  " << low << palindrome2 (low, 0, 4) << endl;
    cout << cap << palindrome2 (cap, 0, 4) << endl;
    cout << sentence << palindrome2 (sentence, 0, 15) << endl << endl;
    cout << "palindrome3:  " << low << palindrome2 (low, 0, 4) << endl;
    cout << cap << palindrome3 (cap, 0, 4) << endl;
    cout << sentence << palindrome3 (sentence, 0, 15) << endl << endl;
    cout << "Please enter characters to be searched for in the source: "  << source << endl;
    cin >> chars;
    cout << source << match_chars ( chars, i, source, j) << endl;
    return 0;
}

