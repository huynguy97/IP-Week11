//                                      
//                                       

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstddef>

using namespace std;

//         
int power (double x, int n)
{
    //            
    assert (n >= 0) ;
    /*
                  
                                         
    */

    if (n == 0)
        return 1 ;
    else return x * power(x, n-1) ;
}

//         
//                                        
int power2 (double x, int n)
{
    //            
    assert (n >= 0);
    /*
                  
                                         
    */

    if (n == 0)
        return 1 ;
    else
    {
        double p = power2(x, n/2);
        if (n % 2 == 0)
            return p*p ;
        else
            return x*p*p;
    }
}

//        
bool palindrome1 (string text, int i, int j)
{
    //            
    assert (true);
    /*             
                                                                    
    */

    if (i >= j)
        return true ;
    else if (text[i] != text[j])
            return false ;
         else return palindrome1(text, i + 1, j - 1) ;
}

//        
bool palindrome2 (string text, int i, int j)
{
    //            
    assert (true);
    /*             
                                                                                         
    */

    if (i >= j)
        return true ;
    else if (toupper(text[i]) != toupper(text[j]))
            return false ;
         else return palindrome2(text, i + 1, j - 1) ;
}

//        
bool palindrome3 (string text, int i, int j)
{
    //            
    assert (true);
    /*             
                                                                                                                                   
    */

    if (i >= j)
            return true ;
    else if (toupper(text[i]) != toupper(text[j]))
            {
                while(!((text[i] <= 'Z' && text[i] >= 'A') || (text[i] <= 'z' && text[i] >= 'a')))
                    i++;
                while(!((text[j] <= 'Z' && text[j] >= 'A') || (text[j] <= 'z' && text[j] >= 'a')))
                    j--;

                if(toupper(text[i]) != toupper(text[j]))
                    return false ;
                else return palindrome3(text, i + 1, j - 1) ;

            }
        else return palindrome3(text, i + 1, j - 1) ;
}

//       
bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(i <= chars.length() - 1 && j<= chars.length() - 1) ;
    /*             
                                                                                       
    */

    if(i == chars.length() - 1)
        {
            if (source.find(chars[i]) == string::npos)
                return false;
            else
                return true;
        }
    else
        {
            j = source.find_first_of(chars[i]);
            int p = source.find_first_of(chars[i+1]);
            if (j > p)
                return false;
            else
                return match_chars(chars, i+1, source, 0);
        }
}

int main()
{
    //                    
    cout<<power2(2,16) << endl ;
    //                                              
    //                                              
    cout<<palindrome3("Madam, I'm Adam.", 0, 15) << endl ;
    cout<<match_chars("abc", 0, "It is a bag of cards", 0) ;
    return 0;
}

