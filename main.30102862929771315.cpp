//                      
//                  

#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

int power(int x, int n)
{
    //             
    assert(x>=0&&n>=0);
    /*              
                                                     
    */
    if (n==0)
        return 1;

    return x*power(x,n-1);
}

int power_efficient(int x, int n)
{
        //             
    assert(x>=0&&n>=0);
    /*              
                                                     
                                                               
    */
    if (n==0)
    {
        return 1;
    }

    if(n%2==0)
    {
        int y = power_efficient(x , n/2);
        return y*y;
    }

    return x*power_efficient(x,n-1);
}
//                                      

bool same(int a, int b)
{//             
    assert(true);
/*              
                   
                                                                     
                                                                     
*/
    if (a == b)
        return true;
    if (a>=65&&a<=90&&(a +32 ==b))
        return true;
    if (a>=97&&a<=122&&(a - 32 == b))
        return true;
    else
        return false;
}
bool palindrome1 (string text, int i, int j)
{
    //             
    assert(i>=0&&j>=0);
/*              
                                  
                                                
                                                 
                   
*/
    if (i>=j)
        return true;

    if (text[i] !=text[j])
{
        cout<<"not_pal";
        return false;
}

    cout<<"palindromel!";
    return palindrome1(text,++i,j--);

}

bool palindrome2 (string text, int i, int j)
{
    //             
    assert(i>=0&&j>=0);
/*              
                                  
                                                                       
                                                 
                   
*/
    if (i>=j)
        return true;

    if (!same(text[i],text[j]))
{
        cout<<"not_pal";
        return false;
}

    cout<<"palindromel!"<<"\n";
    return palindrome1(text,++i,j--);

}

bool palindrome3 (string text, int i, int j)
{
    //             
    assert(i>=0&&j>=0);
/*              
                                                                       
                                  
                                                                       
                                                 
                   
*/
    if (i>=j)

return true;

if  (!((65<=text[i]&&90>=text[i])||(97<=text[i]&&122>=text[i])))
    i++;

if  (!((65<=text[j]&&90>=text[j])||(97<=text[j]&&122>=text[j])))
    j--;

    if (!same(text[i],text[j]))
{
        cout<<"not_pal";
        return false;

}
    cout<<"palindromel!"<<"\n";
        return palindrome1(text,++i,j--);

}

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(i>=0&&j>=0);
    /*              
                                                                     
                                                                                      
                                 
                                              

    */
   if (i == chars.length())
    return true;
   if (j ==source.length())
    return false;
   if (chars[i]==source[j])
    return match_chars(chars, i+1, source, j+1);
    if(chars[i]!=source[j])
    return match_chars(chars, i, source, j+1);
}

int main()
{
    int i =0;
    int j =0;
    //                           
    string text = "Otto";
    string text2 = "Mddap, I'p Addm.";
    string text3 = "abc";
    string text4 =  "It is a bag of cards";
    //                      
    //                      
    //                        

    if(match_chars(text3,i,text4,j))
        cout<<"true";
}

