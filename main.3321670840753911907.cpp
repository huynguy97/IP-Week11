/*                        
                          
 */

#include <iostream>
#include <cassert>

using namespace std;

//        

double naive_power (double x, int n)
{
//               
   assert (n>=0);
//                
//                                              
   if (n==0)
       return 1;
   else
       x = x*naive_power(x, n-1);
   return x;
}

//       

double efficient_power (double x, int n)
{
//               
    assert (n>=0);
//                
//                                                                       
   if ( n == 0)
       return 1;

   else if ( n % 2 == 0)
   {
       x = efficient_power(x, n / 2);
       return x*x;
   }
   else
   {
       x = x*efficient_power(x, n-1);
       return x;
   }
}

//        

bool palindrome1 (string text, int i, int j)
{
//               
   assert (i >= 0 && j >= 0);
//                
//                                                             

   if (i >= j)
       return true;
    if (text[i] != text[j])
        return false;
    return palindrome1(text, ++i, --j);
}

//        

bool palindrome2 (string text, int i, int j)
{
//               
   assert (i >= 0 && j>= 0);
//                
//                                                                                            

   if (i >= j)
       return true;

   if(text[i]>='A' && text[i]<='Z')
       text[i] += 32;

   if(text[j]>= 'A' && text[j]<= 'Z')
       text [j] += 32;

   if (text[i] != text[j])
       return false;
   return palindrome1(text, ++i, --j);
}

//        

const string exclusion_chars = " .,:;'!?-";
const int exclusion_length = 9;

bool isExclusionChar(char c) {
    //             
    assert(c >= 32 && c <= 127);
    //              
    //                                                       

    int location = exclusion_chars.find(c, 0);

    return location >= 0 && location < exclusion_length;
}

bool palindrome3 (string text, int i, int j)
{
//               
    assert (i >= 0 && j>= 0);
//                
//                                                                                            

    if(text[i]>='A' && text[i]<='Z')
        text[i] += 32;

    if(text[j]>= 'A' && text[j]<= 'Z')
        text [j] += 32;

    if (isExclusionChar(text[i]))
    {
        if (isExclusionChar(text[j]))
        {
            return palindrome3(text, i+1, j-1);
        }
        return palindrome3(text, i+1, j);
    }

    if (isExclusionChar(text[j])) {
        return palindrome3(text, i, j-1);
    }

    if (i >= j) {
        return true;
    } else if (text[i] == text[j]) {
        return palindrome3(text, i + 1, j - 1);
    } else {
        return false;
    }
}
bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i < chars.length() && j < source.length());
    //              
    //                                                                                                    

    if (j == source.length() && i < chars.length()) {
        return false;
    } else if (i == chars.length() - 1 && source[j] == chars[i]) {
        return true;
    }

    if (chars[i] != source [j])
    {
        return match_chars(chars, i, source, j+1);
    }

    if (chars [i] == source [j])
    {
        return match_chars(chars, i+1, source, j+1);
    }
}

int main ()
{
    cout << naive_power(2.0, 100) << endl;
    cout << efficient_power(2.0, 100) << endl;
    if (palindrome1("Madam, I'm Adam", 0, 15))
        cout << "Palindorme is true" << endl;
    else
        cout << "Palindrome is false" << endl;

    if (palindrome2("Madam, I'm Adam.", 0, 15))
        cout << "Palindorme is true" << endl;
    else
        cout << "Palindrome is false" << endl;
    if (palindrome3("Madam, I'm Adam.", 0, 15))
        cout << "Palindorme is true" << endl;
    else
        cout << "Palindrome is false" << endl;

    if (match_chars ("abc", 0, "It is a classy bag", 0))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (match_chars ("abc", 0, "It is a bag of books", 0))
        cout << "true" << endl;
    else
        cout << "false" << endl;

}

