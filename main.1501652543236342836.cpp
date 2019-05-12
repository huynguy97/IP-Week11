#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//                                                                                          
//                                                                                          

int naive_power(int x,int n)
{
    assert(n>=0);
    //                                                  
    if(n==0)
        return 1;
    else{
        x=x*naive_power(x,n-1);
        return x;}
}

int efficient_power(int x,int n)
{
    assert(n>=0);
    //                                                  
    int r;
    if(n == 0)
        return 1;
    if(n % 2 == 0) {
        r=efficient_power(x,n/2);
        return r*r;}
    else
        return x*efficient_power(x,n-1);
}

//                                                                            

bool palindrome1(string text,int i,int j)
{
    assert(text.size()>0&&i>=0);
    //                                                                                        
    if(i>=j)
        return true;
    if (text[i] != text[j])
        return false;
    else
        return palindrome1(text,i+1,j-1);
}

bool palindrome2(string text,int i,int j)
{
    assert(text.size()>0&&i>=0);
    //                                                                                        
    if(i>=j)
        return true;
    if(tolower(text[i])!=tolower(text[j]))
        return false;
    else
        return palindrome2(text,i+1,j-1);
}

bool palindrome3(string text,int i,int j)
{
    assert(text.size()>0&&i>=0);
    //                                                                                        
    if(i>=j)
        return true;
    if(ispunct(text[i])||isspace(text[i]))
        i++;
    if(ispunct(text[j])||isspace(text[j]))
        j--;
    if(tolower(text[i])!=tolower(text[j]))
        return false;
    else
        return palindrome3(text,i+1,j-1);
}

bool match_chars(string chars,int i,string source,int j)
{
    assert(source.size()>=chars.size()&&i>=0&&j>=0);
    //                                                                                                                                                                                                
    if(i<chars.size()-1&&j==source.size()-1){
        return false;
    }
    if(i==chars.size()-1){
        if(tolower(source[j])==tolower(chars[i]))
            return true;
    }
    if(i==chars.size()-1&&j==source.size()-1){
        if(tolower(source[j])==tolower(chars[i]))
            return true;
        else
            return false;
    }
    if(tolower(chars[i])==tolower(source[j]))
        return match_chars(chars,i+1,source,j+1);
    else
        return match_chars(chars,i,source,j+1);
}

int main()
{
    cout<<naive_power(3,5)<<endl;
    cout<<efficient_power(3,5)<<endl;
    if(palindrome3("o'tt o",0,5))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    if(match_chars("aBc",0, "abc",0))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

