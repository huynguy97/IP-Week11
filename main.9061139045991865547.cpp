#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

double naive_power (double x,int n)
{
    //    
    assert(n >= 0);
    //                  
    //               
    if (n <= 0)
        return 1;
    //                    
    else
        return x*naive_power(x,n-1);
}

double eff_power (double x, int n)
{
    //    
    assert(n >= 0);
    //                  
    //               
    if (n <= 0)
        return 1;
    //                    
    else
    {
        if (n%2 == 0)
        {
            double y = eff_power(x,n/2);
            return y*y;
        }
        else
            return x*eff_power(x,n-1);
    }
}
//                                                                                     
//                                                                                        
//                                                                         

bool palindrome1 (string text, int i, int j)
{
    //    
    assert(j>=i && i>=0 && text.length()!=0);
    //                                                                                            
    //                                        
    //               
    if (i >= j)
        return true;
    else if (i+1 == j) //                                                                                            
    {
        if (text[i]==text[j])
            return true;
        else
            return false;
    }
    //                    
    else
    {
        if (text[i] == text[j])
            return palindrome1(text, i+1, j-1);
        else
            return false;
    }
}

bool palindrome2 (string text, int i, int j)
{
    //    
    assert(j>=i && i>=0 && text.length()!=0);
    //                                                                                              
    //                                        
    //               
    if (i >= j)
        return true;
    else if (i+1 == j) //                                                                                            
    {
        if (text[i] == text[j] || (text[i] > 64 && text[i] < 91 && text[i] + 32 == text[j])
            || (text[j] > 64 && text[j] < 91 && text[j] + 32 == text[i]))
            return true;
        else
            return false;
    }
    //                    
    else
    {
        if (text[i] == text[j] || (text[i] > 64 && text[i] < 91 && text[i] + 32 == text[j])
            || (text[j] > 64 && text[j] < 91 && text[j] + 32 == text[i]))
            return palindrome1(text, i+1, j-1);
        else
            return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    //    
    assert(j>=i && i>=0 && text.length()!=0);
    //                                                                                                                    
    //                                        
    //               
    if (i >= j)
        return true;
    //                    
    else if (!(text[i] > 64 && text[i] < 91) && !(text[i] > 96 && text[i] < 123))
        return palindrome3(text, i+1, j);
    else if (!(text[j] > 64 && text[j] < 91) && !(text[j] > 96 && text[j] < 123))
        return palindrome3(text, i, j-1);
    else if (i+1 == j) //                                                                                            
    {
        if (text[i] == text[j] || (text[i] > 64 && text[i] < 91 && text[i] + 32 == text[j])
            || (text[j] > 64 && text[j] < 91 && text[j] + 32 == text[i]))
            return true;
        else
            return false;
    }
    else
    {
        if (text[i] == text[j] || (text[i] > 64 && text[i] < 91 && text[i] + 32 == text[j])
            || (text[j] > 64 && text[j] < 91 && text[j] + 32 == text[i]))
            return palindrome3(text, i+1, j-1);
        else
            return false;
    }
}

bool match_chars (string chars, int i, string source, int j)
{
    //    
    assert(chars.length()!=0 && i>=0 && j>=0 && source.length()!=0);
    //                                                                                                  
    //                                                       
    //                                                                  

    //               
    if (i > chars.length()-1)
        return true;
    else if (j > source.length()-1)
        return false;
    //                    
    else if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
    cout << naive_power(2,7) << endl; //             
    cout << eff_power(2,7) << endl; //                      
    cout << palindrome1("otto", 0, 3) << endl; //            
    cout << palindrome1("Otto", 0, 3) << endl; //            
    cout << palindrome1("Madam, I'm Adam.", 0, 15) << endl; //            
    cout << palindrome2("otto", 0, 3) << endl; //            
    cout << palindrome2("Otto", 0, 3) << endl; //            
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl; //            
    cout << palindrome3("otto", 0, 3) << endl; //            
    cout << palindrome3("Otto", 0, 3) << endl; //            
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl; //            
    cout << match_chars ("abcs", 0, "It is a bag of cards", 0) << endl; //            
    cout << match_chars ("abc", 0, "It is a bag of books", 0) << endl; //            
    cout << match_chars ("abc", 0, "It is a classy bag", 0) << endl; //            
    return 0;
}

