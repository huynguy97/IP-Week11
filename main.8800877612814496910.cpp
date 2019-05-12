#include <iostream>
#include <assert.h>
using namespace std;

//                        
double power(double x, int n)
{
    //             
    assert(n >= 0);
    //                                                       
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else if(n%2 == 0)
        return power(x,n/2)*power(x,n/2);
    else
        return x*power(x,n-1);
}
void capital_letter (char& x)
{
    //             
    assert(true);
    //                                                                                                          
    if(x < 91 && x > 64)
        x += 32;
}

void correcting_letter (char& x,int& i,int n, string text)
{
    //             
    assert(n == 1 || n == -1);
    //                                                                              
    //                                                                                    
    //                   
    while(x == 32 || x == 33 || (x >= 44 && x <= 46) || x == 58 || x == 59 || x == 63 || x == 92)
    {
        i += n;
        x = text[i];
    }
    if(x < 91 && x > 64)
        x += 32;
}

bool palindrome1 (string text, int i, int j)
{
    //             
    assert(i<=j && text.length() > 0);
    //                                                                                                               
    //                                                                                                                     
    char x = text[i];
    char y = text[j];
    correcting_letter(x,i,1,text);   //                                                         
    correcting_letter(y,j,-1,text);  //                                                         
    if(j <= i)
        return true;
    else if (x != y)
        return false;
    else
        return palindrome1(text,i+1,j-1);
}

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(chars.length() > 0 && source.length() > 0);
    //              
    char v = chars[i];
    char w = source[j];
    if(chars.length() < i)          
        return true;
    else if (chars.length() < j)        
        return false;
    else if (v == w)
        match_chars (chars,i+1,source,j+1);
    else
        match_chars (chars,i,source,j+1);
}

int main()
{
    //            
    int n;
    double x;
    cin >> x >> n;
    cout << power(x,n) << "\n";

    //            
    cout << palindrome1(" meE t. . Sys t e eM ,",0,21) << "\n";

    //            
    cout << match_chars("abc",0,"It is a bag of books",0);

    return 0;
}

/*
   
                                                                             

*/

