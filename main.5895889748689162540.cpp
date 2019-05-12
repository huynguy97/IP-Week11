#include <iostream>
#include <cassert>

using namespace std;

/*                                           

                                                
                                               

                                            */

char uncapitalize(char A)
{
    //              
    assert(true);
    //                                                                                                                           
    if (A >= 'A' && A <= 'Z')
    {
        A = A - ('A' - 'a');
    }
    return A;
}

bool is_letter(char a)
{
    //              
    assert(true);
    //                                                                                       
    if (a == 32 || a == ',' || a == ':' || a == ';' || a == '.' || a == '\'' || a == '?' || a == '!' || a == '?' || a == '-')
        return false;
    else
        return true;
}

int power(double  x, int n)
{
//               
    assert(n>=0);
//                                                                
    if(n==0)
    {
        return 1;
    }
    else
    {
        return x*power(x,n-1);
    }
}

int power2(double x, int n)
{
    //               
    assert(n>=0);
//                                                               
//                                                      
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return x;
    }
    else
    {
        int k=n%2;
        int l=n/2;
        int y= power2(x,l);
        return y*y*power2(x,k);
    }
}
/*                                                      
                                         
                                                             
                                                                     

                                                       */

bool palindrome(string word, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i <= j);
    //                                                                                                                     
    //                                                                           
    if (i >= j)
    {
        return true;
    }
    else if (word[i] == word[j])
    {
        return palindrome(word, ++i, --j);
    }
    else
    {
        return false;
    }
}

bool palindrome2(string word, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i <= j);
    //                                                                                                                                                       
    //                                                                           
    word[i] = uncapitalize(word[i]);
    word[j] = uncapitalize(word[j]);
    if (i >= j)
    {
        return true;
    }
    else if (word[i] == word[j])
    {
        return palindrome2(word, ++i, --j);
    }
    else
    {
        return false;
    }
}

bool palindrome3(string word, int i, int j)
{
    //              
    assert(i >= 0 && j >= 0 && i <= j);
    //                                                                                              
    //                                                                                                                                                    
    //                                                                           
    word[i] = uncapitalize(word[i]);
    word[j] = uncapitalize(word[j]);
    //                                      
    if (i >= j)
    {
        return true;
    }
    else if (!is_letter(word[i]))
    {
        return palindrome3(word, ++i, j);
    }
    else if (!is_letter(word[j]))
    {
        return palindrome3(word, i, --j);
    }
    else if (word[i] == word[j])
    {
        return palindrome3(word, ++i, --j);
    }
    else
    {
        return false;
    }
}

bool match_chars(string chars, int i, string source, int j)
{
    //              
    assert(i >= 0 && j >= 0);
    //                                                                                                                                      
    //                                                                                                 
    cout << chars[i] << '\t' << source[j] << endl;
    if (i == chars.length())
        return true;
    else if (j == source.length())
    {
        return false;
    }
    else if (chars[i] == source[j])
    {
        return match_chars(chars, ++i, source, ++j);
    }
    else if (chars[i] != source[j])
    {
        return match_chars(chars, i, source, ++j);
    }

}

void ask_for_palindrome()
{
    //              
    assert(true);
    //                                                                                               
    //                                                                                                                              
    string word;
    power(2,4);
    cout << "say something that could be a palindrome" << endl;
    getline(cin, word);
    if (palindrome3(word, 0, (word.length() - 1)))
    {
        cout << "this is a palindrome" << endl;
    }
    else
    {
        cout << "This is not a palindrome" << endl;
    }
}

int main()
{
    ask_for_palindrome();
    /*                                              
                      
        
                     */
    //              
}

