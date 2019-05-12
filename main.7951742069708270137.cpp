#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;
//                                         
double naivepower(double x, int n)
{
    assert(n>=0);
    if (n==0)
        return 1;
    else
        return x*naivepower(x,n-1);
}

double power(double x,int n) //          
{
    assert(n>=0);
    if (n==0)
        return 1;
    else
        if (n==1)//                                                      
            return x;
        else
        {
            double seperate= power(x,n/2); //                                                  
            return seperate*seperate*power(x,n%2);//                                                                                                               
        }
}//                                                                                                       
bool palindrome1(string text, int i, int j) //                                                                                    
{
    assert(text.length()>=i&& text.length()>=j&&i>=0 && j>=0);
    if (i>=j) //                                                                                           
        return true;
    else
        if(text[i]!=text[j]) //                             
            return false;
        else
            return palindrome1(text,i+1,j-1); //                         
}
bool palindrome2(string text, int i, int j)
{
    assert(text.length()>=i&& text.length()>=j&&i>=0 && j>=0);
    if (i>=j)
        return true;
    else
        if(text[i]!=text[j])
        {
            if (abs((int)text[i]-(int)text[j])==32) //                                                                                              
                return palindrome2(text,i+1,j-1); //                                                            
            else
                return false;//                      
        }
        else
            return palindrome2(text,i+1,j-1);
}
bool palindrome3(string text, int i, int j)
{
    assert(text.length()>=i&& text.length()>=j&&i>=0 && j>=0);
    //                                                                                                    
    while (! ( ((int)text[i]>=65 && (int)text[i]<=90) ||((int)text[i]>=97 && (int)text[i]<=122) ) ) //                  
            i++;//                     
    while (! ( ((int)text[j]>=65 && (int)text[j]<=90) ||((int)text[j]>=97 && (int)text[j]<=122) ) )
        j--;
    if (i>=j)
        return true;
    else
        if(text[i]!=text[j])
        {
            if (abs((int)text[i]-(int)text[j])==32)
                return palindrome3(text,i+1,j-1);
            else
                return false;
        }
        else
            return palindrome3(text,i+1,j-1);
}
bool match_chars(string chars, int i, string source, int j)
{
    assert(i>=0&&j>=0);//                                                             
    if (i>=chars.length()) //                                                                                                                                                        
        return true;
    if ((chars.length()-i> source.length()-j))
        return false;
    else //                                            
    {
        while(chars[i]!=source[j] && j<source.length()) //                                                           
            j++;
        if (j==source.length()) //                                   
            return false;//                  
        else
            return match_chars(chars,i+1,source,j+1);//                                                                                                                                     
    }
}
/*                                                                                                                                                                                               
                                                                         
 
                                                                                                                                                                                     
                    
                                              
                     
                                                       
     
                                                                                                                     
                
                                                                     
                                             
            
                                                                                                                                                                                            
     
 
*/
int main()
{
    //                             
    //          
    //        
    //        
    //         
    double ans= power(2.5,6);
    //                  
    cout << ans << "\n";

    //                                                              
    string text="Madam, i'm adam.";
    bool palin=palindrome3(text,0,text.length()-1);
    cout<< palin<<"\n";

    //                         
    bool matching1=match_chars("hel lo",0,"here lives a person named l",0);
    bool matching2=match_chars("hel lO",0,"here lives a strange fellOw",0);
    bool matching3=match_chars("hel lo",0,"herelivesastrangefellow",0); //                                      
    cout<<matching1<<"\t"<<matching2<<"\t"<<matching3;
    return 0;
}

