#include <iostream>
#include <cassert>
#include <string>
using namespace std;
//                        

double power (double x, int n)
{//             
    assert(n>= 0);
/*             
                               
*/
if (n == 0)
{
    return 1;
}
else
{
    return x*power(x, n-1);
}
}

double ef_power(double x, int n)
{//             
    assert(n>= 0);
/*             
                               
*/
if (n == 0)
{
    return 1;
}
else if (n%2 == 0)
{
    double value = ef_power(x, n/2);
    return value*value;
}
else
{
    return x*ef_power(x, n-1);
}
/*                              
                                                 
                                                   
                                        
                               
                               */
}

bool palindrome1 (string text, int i, int j)
{//             
    assert(i >= 0 && j>=i);
/*             
                                                                                         
                                                    
*/
if (i==j)
{
    return true;
}
else if (i+1 == j)
{
    return text[i] == text[j];
}
else
{
    if(palindrome1(text, i+1, j-1) && text[i] == text[j])
    {
        return true;
    }
    else
    {
        return false;
    }
}
}

bool palindrome2 (string text, int i, int j)
{//             
    assert(i >= 0 && j>=i);
/*             
                                                                                         
                                                        
*/
if (i==j)
{
    return true;
}
else if (i+1 == j)
{
    return (text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j]); //                                                   
}
else
{
    if(palindrome2(text, i+1, j-1) && (text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j]))
    {
        return true;
    }
    else
    {
        return false;
    }
}
}

bool palindrome3 (string text, int i, int j)
{//             
    assert(i >= 0 && j >= i);
/*             
                                                                                         
                                                                
*/
while(text[i] <= 64 || text[i] >=123) //                                                                                    
{
    i++;
}
while(text[j] <= 64 || text[j] >=123)
{
    j--;
}
if(j<i)
{
    j=i;
}

if (i==j)
{
    return true;
}
else if (i+1 == j)
{
    return (text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j]);
}
else
{
    if(palindrome3(text, i+1, j-1) && (text[i] == text[j] || text[i]+32 == text[j] || text[i]-32 == text[j]))
    {
        return true;
    }
    else
    {
        return false;
    }
}
}

bool match_chars(string chars, int i, string source, int j)
{//             
    assert(i >= 0 && j >= 0);
/*             
                                                                                           
                                                                                           
                                                                            
*/

if (j > source.length()-1)
{
    return false;
}
else if (i > chars.length()-1)
{
    return true;
}
else if (chars[i] == source[j])
{
    return match_chars(chars, i+1, source, j+1);
}
else
{
    return match_chars(chars, i, source, j+1);
}
}

void return_power_results()
{//             
    assert(true);
/*             
                                                             
*/
double x1 = 5;
double x2 = 1.73205081;
int n1 = 3;
int n2 = 4;
cout << "----------------------PART I----------------------";
cout << "\nResults of naive power:";
cout << "\n\t" << x1 << " to the power of " << n1 << " is " << power(x1, n1);
cout << "\n\t" << x2 << " to the power of " << n2 << " is " << power(x2, n2);
cout << "\nResults of efficient power:";
cout << "\n\t" << x1 << " to the power of " << 4 << " is " << ef_power(x1, 4);
cout << "\n\t" << x2 << " to the power of " << 8 << " is " << ef_power(x2, 8);
}

void return_palindrome_results()
{//             
    assert(true);
/*             
                                                             
*/
    string otto = "otto";
    string otto2 = "Otto";
    string madam = "Madam, I'm Adam.";
    cout << "\n\n----------------------PART II----------------------";
    cout << "\nResults of palindrome1:";
    cout << "\n\tString '" << otto << "' returns:\t\t\t" << palindrome1(otto, 0,3);
    cout << "\n\tString '" << otto2 << "' returns:\t\t\t" << palindrome1(otto2, 0,3);
    cout << "\n\tString '" << madam << "' returns:\t" << palindrome1(madam, 0,15);
    cout << "\nResults of palindrome2:";
    cout << "\n\tString '" << otto << "' returns:\t\t\t" << palindrome2(otto, 0,3);
    cout << "\n\tString '" << otto2 << "' returns:\t\t\t" << palindrome2(otto2, 0,3);
    cout << "\n\tString '" << madam << "' returns:\t" << palindrome2(madam, 0,15);
    cout << "\nResults of palindrome3:";
    cout << "\n\tString '" << otto << "' returns:\t\t\t" << palindrome3(otto, 0,3);
    cout << "\n\tString '" << otto2 << "' returns:\t\t\t" << palindrome3(otto2, 0,3);
    cout << "\n\tString '" << madam << "' returns:\t" << palindrome3(madam, 0,15);
}

void return_match_chars_results()
{//             
    assert(true);
/*             
                                                             
*/
    string abc = "abc";
    string string1 = "It is a bag of cards";
    string string2 = "It is a bag of books";
    string string3 = "It is a classy bag";
    cout << "\n\n----------------------PART III----------------------";
    cout << "\nResult of string '" << string1 << "'\twith chars '" << abc << "' and i = j = 0:\t"<<match_chars(abc, 0, string1, 0);
    cout << "\nResult of string '" << string2 << "'\twith chars '" << abc << "' and i = j = 0:\t"<<match_chars(abc, 0, string2, 0);
    cout << "\nResult of string '" << string3 << "'\twith chars '" << abc << "' and i = j = 0:\t"<<match_chars(abc, 0, string3, 0)<<"\n\n";
}

int main()
{
    return_power_results();
    return_palindrome_results();
    return_match_chars_results();
    return 0;
}

