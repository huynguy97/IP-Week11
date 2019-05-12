#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                                              
//                                          

bool check_case_insensitive(char first, char last)
{
    assert(true);
    //                                                                             
    //                                                       
    int a = first, b = last;
    return (a == b || a == b+32 || a+32 == b);
}

bool check_space_insensitive(string text, int letter)
{
    assert(true);
    //                                                                          
    //                          
    int a = text[letter];
    return (a == 32 || a == 46 || a == 44 || a == 58 || a == 59 || a == 92 || a == 33 || a == 63 || a == 45);
}

//      
double power(double x, int n)
{
    assert(n >= 0);
    //                                                                        
    //                                                                         
    //                                          
    if(n == 0)
        return 1;
    else
    {
        if(n >= 2)
            return x * x * power(x,n-2);
        else
            return x * power(x,n-1);
    }
}

bool palindrome1 (string text, int i, int j)
{
    assert(j-i >= 0 && i >= 0 && j >= 0 && i < text.length() && j <= text.length());
    //                                                                                      
    //                                                                                       
    //                                                                        
    //                             
    if(j-i == 1 || j-i == 0)
        return true;
    else
    {
        if(text[i] == text[j])
        {
            return palindrome1(text,i+1,j-1);
        }
        else
            return false;
    }
}

bool palindrome2 (string text, int i, int j)
{
    assert(j-i >= 0 && i >= 0 && j >= 0 && i < text.length() && j <= text.length());
    //                                                                                    
    //                                                                     
    //                                                     
    //                                                                        
    //                             
    if(j-i == 1 || j-i == 0)
        return true;
    else
    {
        if(check_case_insensitive(text[i],text[j]))
        {
            return palindrome2(text,i+1,j-1);
        }
        else
            return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    assert(j-i >= 0 && i >= 0 && j >= 0 && i < text.length() && j <= text.length());
    //                                                                   
    //                                                          
    //                                                                 
    //                                                                    
    //                                                    
    //                                                                        
    //                             
    if(j-i == 1 || j-i == 0)
        return true;
    else
    {
        if(check_space_insensitive(text,i))
        {
            return palindrome3(text,i+1,j);
        }
        if(check_space_insensitive(text,j))
        {
            return palindrome3(text,i,j-1);
        }
        if(check_case_insensitive(text[i],text[j]))
            {
                return palindrome3(text,i+1,j-1);
            }
            else
                return false;

    }
}

bool match_chars (string chars, int i, string source, int j)
{
    assert(i<chars.length()&&j<source.length());
    //                                                                                                                       
    //                                                                                                                       
    //                                                                                                                                                                                 
	if(j==source.length())
		{
			return false;
		}
	if(chars.at(i)==source.at(j))
	{
		i++;
		if(chars.length()==i){
			return true;
		}
		return match_chars (chars, i, source, j);
	}
	if(chars.at(i)!=source.at(j))
		{
			j++;
			return match_chars (chars, i, source, j);
		}
}

int main()
{
    int powers, letter_f, letter_l;
    double number;
    string text, chars;
//                               
//                  
//                              
//                  
//                                     
//                       
    cout << "Enter the text "<<endl;
    getline(cin,text);
    cout << "First number please : ";
    cin >> letter_f ;
    cout << "Last number please : ";
    cin >> letter_l ;
//                                          
//                                            
//     
//                              
//     
//                                            
//     
//                              
//     
    if (palindrome3(text,letter_f,letter_l))
    {
        cout << "TRUE" <<endl;
    }
//                                                    
//     
//                              
//     
//                                
    return 0;
}

