#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

//                                                     
//                                                     
//                                                     

double power(double x, int n)
{   //             
    assert(n>=0);
    //                                                           

    if(n == 0)
    {
       return 1;
    }
    else
    {
        double b=power(x,n-1);
        return b*x;
    }

}

bool palindrome1 (string text, int i, int j)
{   //             
    assert(text.length()>0);
    //                                                                                                     
    //                                                                                              

    if(text.length() == 1)
        return true;

    if(text[i] != text[j] && i < j)
        return false;

    if (text[i]==text[j] && i < j)
        return palindrome1(text,i+1,j-1);

    if(text[i]==text[j] && i>=j)
        return true;

}

bool palindrome2 (string text, int i, int j)
{   //             
    assert(text.length()>0);
    //                                                                                                     
    //                                                                                                                                         

    if(text.length() == 1)
        return true;

        text[i] = toupper(text[i]);
        text[j] = toupper(text[j]);

    if(text[i] != text[j] && i < j)
        return false;

    if (text[i]==text[j] && i < j)
        return palindrome2(text,i+1,j-1);

    if(text[i]==text[j] && i>=j)
        return true;

}

bool palindrome3 (string text, int i, int j)
{   //             
    assert(text.length()>0);
    //                                                                                                    
    //                                                                                                              

    if(text.length() == 1)
        return true;

    if(int(text[i])>31 && int(text[i])<48 || int(text[i])>57 && int(text[i])<65 || int(text[i])>90 && int(text[i])<97 || int(text[i])>122 && int(text[i])<127)
        return palindrome3(text,i+1,j);

    if(int(text[j])>31 && int(text[j])<48 || int(text[j])>57 && int(text[j])<65 || int(text[j])>90 && int(text[j])<97 || int(text[j])>122 && int(text[j])<127)
        return palindrome3(text,i,j-1);

        text[i] = toupper(text[i]);
        text[j] = toupper(text[j]);

    if(text[i] != text[j] && i < j)
        return false;

    if (text[i]==text[j] && i < j)
        return palindrome3(text,i+1,j-1);

    if(text[i]==text[j] && i>=j)
        return true;

}

bool match_chars (string chars, int i, string source, int j)
{   //             
    assert(chars.length()>0 && source.length()>0);
    //                                                                                                                                   

    if(i>chars.length()-1)
            return true;

    if(j>source.length()-1)
            return false;

    if(chars[i] != source[j])
        return match_chars(chars,i,source,j+1);

    if (chars[i] == source[j])
        return match_chars(chars,i+1,source,j+1);

    return false;
}

int main()
{
    /*         
          
                                                                  
               
                     */

    /*            
                                                                           
              
            
                          
               */

    /*                          
                                                     
        
                                                        */

    /*                          
                                                     
        
                                                        */

    /*                          
                                                     
        
                                                        */

    int h=0;
    int g=0;
    string letters;
    string sour;
    string input;
    cout<<"Write down chars which you want to check if it is in source: ";
    cin>>letters;
    cout <<endl<<"Write down source: ";
    cin >> input;
    getline(cin, sour);
    cout<<endl;
    sour = input + sour;

    if (match_chars(letters,h,sour,g))
        cout<<"Yes, this source contain "<<letters<<" !"<<endl;
    else
        cout<<"No, this source is not contain "<<letters<<" !"<<endl;

    return 0;
}

