#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
#include <array>

using namespace std;

//                          
//                    

//                                                                    
int fac(int n)
{
    if (n <= 0)
        return 1;
    else
        return n * fac(n-1);
}

//        
double power(const double x, int n)
{
    //               
    assert(n >= 0);
    //                
    //                                          
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
double power2(const double x, int n)
{
    //               
    assert (n >= 0);
    //                
    //                               
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0) //             
    {
        double m = power2(x, n/2);
        return m * m;
    }
    else //         
    {
        return x * power2(x, n-1);
    }
}
//                                                                                                                                                                                                        
//                                                             

//        
bool palindrome1 (string text, int i, int j)
{
    //               
    assert(text.length() >= 1 && i >= 0 && i <= j);
    //                
    //                                                    
    //                                                             
    //                                                                     
    if (i == j)
    {
        return true;
    }
    else    //                                                                                                                                                  
    {
        //                  
        if (text[i] == text[j])
        {
            if (i+1 > j-1)
            {
                return true;
            }
            else
            {
                return palindrome1(text, i+1, j-1);
            }
        }
        else
        {
            return false;
        }
    }
}

//        
bool palindrome2(string text, int i, int j)
{
    //               
    assert(text.length() >= 1 && i >= 0 && i <= j);
    //                
    //                                                                               
    //                                                              
    //                                                                     
    if (i == j)
    {
        return true;
    }
    else    //                                                                                                                                                  
    {
        //                                                                              
        if (text[i] >= 65 && text[i] <= 90)
            text[i] += 32;
        if (text[j] >= 65 && text[i] <= 90)
            text[j] += 32;

        //                  
        if (text[i] == text[j])
        {
            if (i+1 > j-1)
            {
                return true;
            }
            else
            {
                return palindrome2(text, i+1, j-1);
            }
        }
        else
        {
            return false;
        }
    }
}

//        
bool palindrome3(string text, int i, int j)
{
    //               
    assert(text.length() >= 1 && i >= 0 && i <= j);
    //                
    //                                                                                                                          
    //                                                              
    //                                                                     
    if (i == j)
    {
        return true;
    }
    else    //                                                                                                                                                  
    {
        //                                                                                                                                                   
        bool checking = true;
        while (checking)
        {
            if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '\'' || text[i] == '!' || text[i] == '?' || text[i] == '-')
            {
                return palindrome3(text, i+1, j);
            }
            else if (text[j] == ' ' || text[j] == '.' || text[j] == ',' || text[j] == ':' || text[j] == ';' || text[j] == '\'' || text[j] == '!' || text[j] == '?' || text[j] == '-')
            {
                return palindrome3(text, i, j-1);
            }
            else
            {
                checking = false;
            }
        }

        //                                                                                          
        if (text[i] >= 65 && text[i] <= 90)
            text[i] += 32;
        if (text[j] >= 65 && text[j] <= 90)
            text[j] += 32;

        //                  
        if (text[i] == text[j])
        {
            if (i+1 > j-1)
            {
                return true;
            }
            else
            {
                return palindrome3(text, i+1, j-1);
            }
        }
        else
        {
            return false;
        }
    }
}

//      
bool match_chars(const string chars, int i, const string source, int j)
{
    //              
    assert(chars.length() > 0 && i >= 0 && source.length() > 0 && j >= 0);
    //               
    //                                                                                                                                                      
    //                                                                  
    //                                              
    int n = chars.length();
    char array_chars[n];
    strcpy(array_chars, chars.c_str());
    int m = source.length();
    char array_source[m];
    strcpy(array_source, source.c_str());

    //                                                                            
    if (i == n-1)
    {
        //                                                                                                                                                               
        if (array_chars[i] == array_source[j])
        {
            return true;
        }
        else
        {
            if (j < m-1)   //                                             
            {
                return match_chars(chars, i, source, j+1); //                          
            }
            else //                                                                                             
            {
                return false;
            }
        }
    }
    else if (array_chars[i] == array_source[j])
    {
        return match_chars(chars, i+1, source, j+1);
    }
    else
    {
        if (j < m-1) //                                                
        {
            return match_chars(chars, i, source, j+1); //                          
        }
        else //                                        
        {
            return false;
        }
    }
}

int main()
{
    /*                            
                                                              
                                                        
             
             
                                                  
          
             

                                
                                 
    */

      //                        
    cout << "Enter a text to check if part of it is a palindrome" << endl;
    string text;
    getline(cin, text); //                                      
    cout << "Now enter a non-negative integer as the starting index i:" << endl;
    int i;
    cin >> i;
    cout << "Now enter an integer larger than or equal to i as the ending index j:" << endl;
    int j;
    cin >> j;

    if (palindrome1(text, i, j))
    {
        cout << "The text fragment is a palindrome" << endl;
    }
    else
    {
        cout << "The text fragment is not a palindrome" << endl;
    }

    /*
                             
                                                                            
                 
                                                                 
                                                                    
                 
                                                                                                          
                             
                                                 
                  
                                                                        
                                                                      
                                                                                                   
                        
                             

                                         
     
                                                         
     
        
     
                                                             
     
    */

    return 0;
}

