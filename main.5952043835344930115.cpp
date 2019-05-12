#include <iostream>
#include<cassert>
#include<cmath>
#include<string>

//                                
//                         

using namespace std;

int power (int base, int exponent)
{
    //            
    assert(exponent >= 0);
    //                                                 
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}

int power_efficient (int base, int exponent)
{
    //            
    assert(exponent>=0);
    //                                                     
    if (exponent == 0)
        return 1;
    else if (exponent == 1)
        return base;
    else if (exponent % 2 == 0)
        return power_efficient(base * base, exponent / 2);
    else if((exponent % 2) != 0)
        return base * power_efficient(base * base, (exponent - 1) / 2);
    else;
}
//                                                                       

bool palindrome1(string text, int unsigned i, int unsigned j)
{
    //            
    assert(i>=0 && j>=0 && j<text.length());
    //                                                                        
    if(text[i]!=text[j])
    {
        return false;
    }
    else if(i>j)
    {
        return true;
    }
    else
    {
        return palindrome1(text,i+1,j-1);
    }
}

bool palindrome2(string text, int unsigned i, int unsigned j)
{
    //            
    assert(i>=0 && j>=0 && j<text.length());
    //                                                                                                     
    if(text[i]!=text[j]&& text[i]!=text[j]-32 && text[i]-32!=text[j])
    {
        return false;
    }
    else if(i>j)
    {
        return true;
    }
    else
    {
        return palindrome2(text,i+1,j-1);
    }
}

bool palindrome3(string text, int unsigned i, int unsigned j)
{
    //            
    assert(i>=0 && j>=0 && j < text.length());
    //                                                                                                                     
    if(i>j)
    {
        return true;
    }
    else
    {
        if((text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122) && !(text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122))
            return palindrome3(text,i+1,j);
        else if((text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122) && !(text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122))
            return palindrome3(text,i,j-1);
        else if((text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122) &&(text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122) )
            return palindrome3(text,i+1,j-1);
        else if (!(text[i]!=text[j] && text[i]!=text[j]-32 && text[i]-32!=text[j]))
            return palindrome3(text,i+1,j-1);
        else
            return false;
    }
}

bool match_chars (string chars, int unsigned i, string source, int unsigned j)
{
    //            
    assert(j <= source.length() && i <= chars.length());
    //                                                                                                                                             
    if (i == chars.length())
    {
        return true;
    }

    else if (j == source.length())
    {
        return false;
    }

    else if (chars[i] == source[j])
    {
        return match_chars(chars, i+1, source, j+1);
    }
    else if (chars[i] != source[j])
    {
        return match_chars(chars, i, source, j+1);
    }
    else;
}

int main()
{
     //           
    //                                 
    //                                           
    //                                                       

    return 0;
}

