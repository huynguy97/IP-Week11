#include <iostream>
#include <string.h>
#include <cassert>
//                            
//                          
using namespace std;

/*        */
//        
int naivePower(int x,unsigned int n)
{
    //    
    assert(true);
    /*    
               
    */
    if(n>0)
    {
        return x*naivePower(x,n-1);
    }
    return 1;
}
//        
int efficientPower(int x, unsigned int n)
{
    //    
    assert(true);
    /*    
                             
    */
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        if (n == 2)
        {
            return x * x;
        }
        return efficientPower(efficientPower(x, n / 2), 2);
    }
    else
    {
        return x * efficientPower(x, n - 1);
    }
}

/*        */
//        
bool palindrome1 (string text, int i, int j)
{
    //    
    assert(i>=0 && j>=0);
    /*    
                                  
    */
    while(i<j)
    {
     if(text[i]!=text[j])
        return false;
     else
        return palindrome1(text,text[i+1],text[j-1]);
    }

    return true;
}

//        
bool palindrome2 (string text, int i, int j)
{
    //    
    assert(i>=0 && j>=0);
    /*    
                                                          
    */
    while(i<j)
    {
     if(text[i] != text[j] && text[i]+32 != text[j] && text[i]-32 != text[j]) //                                                                                                                                                                     
        return false;
     else return palindrome2(text,text[i+1],text[j-1]);
    }
    return true;
 }
//        
bool palindrome3 (string text, int i, int j)
{
    //    
    assert(i>=0 && j>=0);
    /*    
                                                                                       
    */
    char a[9] = {' ','.', ',', ':', ';', '\'', '!', '?', '-'};

    while(i<j)
    {
        for(int k=0;k<8;k++)
        {
            if(text[i]==a[k])
                i++;
            if (text[j]==a[k])
                j--;
        }

         if(text[i] != text[j] && text[i]+32 != text[j] && text[i]-32 != text[j])
            return false;
         else return palindrome2(text,text[i+1],text[j-1]);
    }

    return true;
}
//      
bool match_chars (string chars, int i, string source, int j)
{
    //    
    assert(i>=0 && j>=0);
    /*    
                                                                                               
    */
    while(j < source.length()-1 && i < source.length())
    {
        if(chars[i]!=source[j])
            return match_chars(chars,i,source,j+1);
        else
            return match_chars(chars,i+1,source,j+1);
    }

    if(i==chars.length())
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
//           
/*        

          

                                 
                                     
*/

//      
string text;

getline(cin,text);

//             
/*                                                                        
                                        */

//             
/*                                                                        
                                        */

//             
/*                                                                        
                                        */

//           
string fulltext;
getline(cin,fulltext);
if(match_chars(text,0,fulltext,0))
{
    cout<<"The characters in "<<text<<" occur in "<<fulltext;
}
else
{
    cout<<"The characters in "<<text<<" don't occur in "<<fulltext<<endl;
}

    return 0;
}

