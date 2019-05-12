#include <iostream>
#include <string>
#include <cstring>
#include <assert.h>
using namespace std;

//                                                       
//                                                 

double power(double x, int n)
{
    //             
    assert(n>=0);
    //                                         
    if(n==0)
        return 1;
    else if(n%2==0)
    {
        x=power(x,n/2);
        return x*x;
    }
    else if(n%2!=0)
    {
        return x*power(x,n-1);
    }
}
//                                                                              

bool palindrome1 (string text, int i, int j)
{
    //             
    assert(i>=0&&j<=text.size());
    //                                                                       
    int x=(i+j)/2;
    if (j==x)
        return (text[i]==text[j]);
    else
    {
        if (text[i]==text[j])
        {
            i++;
            j--;
            return palindrome1(text,i,j);
        }
        else
            return false;
    }
}

bool letter (char a, char b)
{
    //             
    assert(true);
    //                                                             
    //                                                   

        if(a<97)
            a+=32;
        if (b<97)
            b+=32;
        return (a==b);
}

bool marks (char a)
{
    //             
    assert(true);
    //                                                                               
    //                                                             
    return ((a<65 || a>123) || (a>91 && a<97) || (a==32));
}

bool palindrome2 (string text, int i, int j)
{
    //             
    assert(i>=0&&j<=text.size());
    //                                                                                         
    //                                                                                       
    //                                     

    int x=(i+j)/2;
    if (j==x)
        return letter(text[i],text[j]);

    else
    {
        if (letter(text[i],text[j]))
        {
            i++;
            j--;
            return palindrome2(text,i,j);
        }
        else
            return false;
    }
}

bool palindrome3 (string text, int i, int j)
{
    //             
    assert(i>=0&&j<=text.size());
    //                                                                                         
    //                                                                                        
    //                                                                                          

    int x=(i+j)/2;
    if (j==x)
        return letter(text[i],text[j]);

    else
    {
        if (marks(text[i]))
            {
                i++;
                return palindrome3(text,i,j);
            }
            if (marks(text[j]))
            {
                j--;
                return palindrome3(text,i,j);
            }
        if (letter(text[i],text[j]))
        {
            i++;
            j--;
            return palindrome3(text,i,j);
        }
        else
            return false;
    }
}

bool occur (char a,string b,int& j)
{
    //             
    assert(true);
    //                                                                               
    //                                                    

    for(int i=j;i<b.size();i++)
        if(a==b[i])
        {
            j=i;
            return true;
        }

    return false;
}

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(i>=0&&i<chars.size()&&j>=0&&j<source.size());
    //                                                                        
    //                                                                                         

    if (i==(chars.size()-1))
        return (occur(chars[i],source,j));
    else
    {
      if (occur(chars[i],source,j))
      {
       i++;
       return match_chars(chars,i,source,j);
      }
      else
        return false;
    }

}

int main()
{
    cout << power(4.0,4) << endl;
    cout<<palindrome1("otto",0,3)<< endl;
    cout<<palindrome2("OtTo",0,3)<< endl;
    cout<<palindrome3("Madam, I'm Adam.", 0, 15)<< endl;
    cout<<match_chars ("abc", 0, "It is a bag of cards", 0)<< endl;
    cout<<match_chars ("abc", 0, "It is a bag of books", 0)<< endl;
    cout<<match_chars ("abc", 0, "It is a classy bag", 0);
    return 0;
}

