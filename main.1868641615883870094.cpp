/*                                                                      
                                                   
                                                   
                                                                      */

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

const char   weird_chars_array[] = {'.', ',', ':', ';', '\'', '!', '?', '-', ' '};
const string weird_chars(weird_chars_array);

/*                                                                      
         
                                                                      */

double power_inef (double x, int n)
{
//                
    assert(n>=0);
//                 
//                                                                
    if (n =0)
        return 1;
    else
        return x*power_inef(x,n-1);
}

double power_eff (double x, int n)
{
//                
    assert(n>=0);
//                 
//                                                                   
//                                                                   
    if (n==0)
        return 1;
    else if (n%2==0)
    {
        double help = power_eff(x,n/2);
        return help*help;
    }
    else
        return x*power_eff(x,n-1);
}

/*                                                                      
         
                                                                      */

bool palindrome1 (string text, int i, int j)
{
//                
    assert (i>=0 && j < text.length() && i<=j);
//                 
//                                                                      
//                                                                    
//                                                                         
//                                      
    if (text[i] != text[j])
        return false;
    else
    {
        if (i == j-1 || i == j)
            return true;
        return palindrome1(text, ++i, --j);
    }
}

char caps_to_normal (char& a)
{
//                
    assert (true);
//                 
//                                                                       
//                                       
    if (65 <= a && a <= 90)
        return a+32;
    return a;
}

bool palindrome2 (string text, int i, int j)
{
//                
    assert (i >= 0 && j < text.size() && i <= j);
//                 
//                                                                      
//                                                                    
//                                                                        
//                                                             
    if (caps_to_normal(text[i]) != caps_to_normal(text[j]))
        return false;
    else
    {
        if (i == j-1 || i == j)
            return true;
        return palindrome2(text, ++i, --j);
    }
}

bool is_weird_char (char& a)
{
//                
    assert (true);
//                 
//                                                                          
//                                                                 
    return weird_chars.find(a) != string::npos; //                                                 
}                                               //                                                
                                                //                              

void weird_char_check (string text, int& i, int& j)
{
//                
    assert (true);
//                 
//                                                                        
//                                                
    if (weird_chars.find(text[i]) != string::npos)
        j++;
    else if (weird_chars.find(text[j]) != string::npos)
        i--;
}

bool palindrome3 (string text, int i, int j)
{
//                
    assert (i >= 0 && j < text.size() && i <= j);
//                 
//                                                                      
//                                                                    
//                                                                
//                                                 
    if ( caps_to_normal(text[i]) != caps_to_normal(text[j])
        && !is_weird_char(text[i])
        && !is_weird_char(text[j]) )
        return false;

    else
    {
        if ( i == j-1 || i == j )
            return true;
        weird_char_check (text,i,j);         //                                                       
        return palindrome3 (text, ++i, --j); //                                                       
    }                                        //                                                           
}                                            //                                                           
                                             //          

/*                                                                      
         
                                                                      */

bool match_chars (string chars, int i, string source, int j)
{
//                
    assert (0 <= i && i <= chars.length() && 0 <= j && j <= source.length());
//                 
//                                                                     
//                                                                         
//                            
    if (i == chars.length())
        return true;
    else
    {
        int pos = source.find (chars[i], j);
        if (pos != string::npos)
            return match_chars (chars, ++i, source, ++pos);
        else
            return false;
    }
}

int main()
{
    cout << "Checks if the examples from the exercise are palindromes: 0 if not, 1 if it is." << endl;
    cout << "function: palindrome1:" << endl;
    cout << "otto is a palindrome:\t\t\t"            << palindrome1 ("otto", 0, 3) << endl;
    cout << "Otto is a palindrome:\t\t\t"            << palindrome1 ("Otto", 0, 3) << endl;
    cout << "Madam, I'm Adam. is a palindrome:\t"    << palindrome1 ("Madam, I'm Adam.", 0, 15) << endl << endl;

    cout << "function: palindrome2:" << endl;
    cout << "otto is a palindrome:\t\t\t"            << palindrome2 ("otto", 0, 3) << endl;
    cout << "Otto is a palindrome:\t\t\t"            << palindrome2 ("Otto", 0, 3) << endl;
    cout << "Madam, I'm Adam. is a palindrome:\t"    << palindrome2 ("Madam, I'm Adam.", 0, 15) << endl << endl;

    cout << "function: palindrome3:" << endl;
    cout << "otto is a palindrome:\t\t\t"            << palindrome3 ("otto", 0, 3) << endl;
    cout << "Otto is a palindrome:\t\t\t"            << palindrome3 ("Otto", 0, 3) << endl;
    cout << "Madam, I'm Adam. is a palindrome:\t"    << palindrome3 ("Madam, I'm Adam.", 0, 15) << endl << endl;

    cout << "Checks if the examples of part 3 are correct:" << endl;
    cout << "Does abc appear consecutively in the sentence: It is a bag of cards: " << match_chars("abc",0,"It is a bag of cards", 0) << endl;
    cout << "Does abc appear consecutively in the sentence: It is a bag of books: " << match_chars("abc",0,"It is a bag of books", 0) << endl;
    cout << "Does abc appear consecutively in the sentence: It is a classy bag:   " << match_chars("abc",0,"It is a classy bag", 0)   << endl;
    return 0;
}

/*                                                                      
             
                                                                      */
//                                             
//                                                                         
//                                                     

/*                                                                      
             
                                                                      */
//                                                                       
//                                    

/*                                                                      
             
                                                                      */
//                                                                      
//                                      

