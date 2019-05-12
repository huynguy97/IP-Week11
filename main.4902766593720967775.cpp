//                                                             

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

double naive_power(double x, int n)
{
assert(n>=0);
 if(n==0)
  {
   return 1;
  }
 else
 {
   x=x*naive_power(x,n-1);
   return x;
 }
}

double efficient_power(int x, int n)
//                 
{
    assert(n>=0);
    if(n==0)
    {
        return 1;
    }
    else
    {
    if(n%2==0)
    {
        x=efficient_power(x,n/2);
        x=efficient_power(x,n/2);
    }
    else
    {
        x=x*naive_power(x,n-1);

    }
    return x;
    }
}
bool palindrome1(string text, int i, int j)
{
    if(i>=j)
    {
        return true;
    }
    if(text[i]==text[j])
        {
        return palindrome1(text,i+1,j-1);
        }
        else
        {
            return false;
        }
}
void convert_to_lower(string& text)
{
    for(int i=0; i<text.length(); i++){
       convert_to_lower(text);
}
}
void remove_punctuation(string& text){
    for(int i; i<text.length(); i++){
        if(ispunct(text[i])){
           text.erase(i-1,1);
           i=text.length();
           }
    }

}
bool palindrome2(string text, int i, int j)
{
convert_to_lower(text);
   if(i>=j)
    {
        return true;
    }
    if(text[i]==text[j])
        {
        return palindrome2(text,i+1,j-1);
        }
        else
        {
            return false;
        }
}

bool palindrome3(string text, int i, int j){
convert_to_lower(text);
remove_punctuation(text);
   if(i>=j)
    {
        return true;
    }
    if(text[i]==text[j])
        {
        return palindrome3(text,i+1,j-1);
        }
        else
        {
            return false;
        }
}

bool match_chars(string chars, int i, string source, int j){

}

int main()
{
    cout<<naive_power(5,3.0)<<endl;
    cout<<efficient_power(5,3.0)<<endl;
    cout<<palindrome1("otto",0,3)<<endl;
    cout<<palindrome2("Otto",0,3)<<endl;
    cout<<palindrome3("Otto!",0,3)<<endl;
    return 0;
}

