#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

//             

//                             
double power (double x, int n)
{//               
    assert(x >= 0 & n >= 0);
 /*                
                                                       
 */
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n-1);
    }
}

//                                                 
double power_efficient (double x, int n)
{//               
    assert(x >= 0 & n >= 0);
 /*                
                                                       
 */
    if (n == 0)
    {
        return 1;
    }

    else if (n % 2 != 0)
    {
        return power(x, n);
    }

    else
    {
        return power_efficient(x, n/2) * power_efficient(x, n/2);
    }
}

void testing_part1()
{//               
    assert(true);
 /*                
                                                                  
 */
    cout << power(1, 5) << endl;
    cout << power(5, 1) << endl;
    cout << power(10, 0) << endl;
    cout << power(12, 3) << endl;
    cout << power(6, 2) << endl;
    cout << power(4, 4) << endl;
    cout << power(10, 2) << endl;
    cout << "----------" << endl;
    cout << power_efficient(1, 5) << endl;
    cout << power_efficient(5, 1) << endl;
    cout << power_efficient(10, 0) << endl;
    cout << power_efficient(12, 3) << endl;
    cout << power_efficient(6, 2) << endl;
    cout << power_efficient(4, 4) << endl;
    cout << power_efficient(10, 2) << endl;
    cout << "----------" << endl;
}
//              

//             

//                            
bool palindrome1 (string text, int i, int j)
{//               
    assert( i >= 0 && j <= text.length());
 /*                
                                                                    
 */
    if (text[i] != text[j])
    {
        return false;
    }

    else if ( j <= i )
    {
        return true;
    }

    else
    {
        return palindrome1(text, ++i, --j);
    }
}

//                            
bool palindrome2 (string text, int i, int j)
{//               
    assert( i >= 0 && j <= text.length());
 /*                
                                                                    
 */
    if (tolower(text[i]) != tolower(text[j]))
    {
        return false;
    }

    else if ( j <= i )
    {
        return true;
    }

    else
    {
        return palindrome2(text, ++i, --j);
    }
}

//     
bool is_letter (char c)
{//               
    assert(true);
 /*                
                                                          
 */
    return (tolower(c) >= 'a' && tolower(c) <= 'z');
}

//                            
bool palindrome3 (string text, int i, int j)
{//               
    assert(i >= 0 && j <= text.length());
 /*                
                                                                    
 */
    //                                                                  
    if (is_letter(text[i]) & is_letter(text[j]) )
    {
        if (tolower(text[i]) != tolower(text[j]))
        {
            return false;
        }
    }
    else if (is_letter(text[i]))
    {
        return palindrome3(text, i, --j);
    }
    else if (is_letter(text[j]))
    {
        return palindrome3(text, ++i, j);
    }
//                               
    if ( j <= i )
    {
        return true;
    }
    else
    {
        return palindrome3(text, i+1, j-1);
    }
}

//     
void testing_part2()
{//               
    assert(true);
 /*                
                                                                  
 */
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome1("Otto", 0, 3) << endl;
    cout << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << "----------" << endl;
    cout << palindrome2("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << "----------" << endl;
    cout << palindrome3("otto", 0, 3) << endl;
    cout << palindrome3("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << "----------" << endl;
}
//              

//             

//                                                                   
bool match_chars (string chars, int i, string source, int j)
{//               
    assert( i <= chars.length() & j <= source.length());
 /*                
                                                                    
 */
    if ( i == chars.length())
    {
        return true;
    }
    else if (j < source.length())
    {
        if (chars[i] == source[j])
        {
            return match_chars(chars, i+1, source, j+1);
        }

        else
        {
            return match_chars(chars, i, source, j+1);
        }
    }
    else
    {
        return false;
    }
}

//     
void testing_part3()
{//               
    assert(true);
 /*                
                                                                  
 */
    cout << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars("abc", 0, "It is a bag of books", 0) << endl;
    cout << match_chars("abc", 0, "It is a classy bag", 0) << endl;
    cout << "----------" << endl;
}
//              

int main()
{
    cout << "Power function:" << endl;
    testing_part1();
    cout << "Palindrome:" << endl;
    testing_part2();
    cout << "match chars:" << endl;
    testing_part3();
    return 0;
}

