#include <iostream>

using namespace std;

//                        
//                      

int power(int x,int n){
//   
    assert(n>=0);
//                                             

    if(n==0)return 1;
    if(n>0)return x*power(x,n-1);
}

int power2(int x,int n){
//   
    assert(n>=0);
//                                                               

    if(n==0)return 1;
    return power(power(x,n/2),2)*power(x,n%2);
}

bool palindrome1(string text, int i, int j){
//   
    assert(i>=0 && j<text.length());
//                                                                       

    if(text[i]!=text[j])return false;
    if(i>=j) return true;
    return palindrome1(text,i+1,j-1);
}

bool palindrome2(string text, int i, int j){
//   
    assert(i>=0 && j<text.length());
//                                                                         

    char ci = text[i];
    char cj = text[j];
    if(ci>=65 && ci<=90) ci+=32;
    if(cj>=65 && cj<=90) cj+=32;
    if(ci!=cj)return false;
    if(i>=j) return true;
    return palindrome2(text,i+1,j-1);
}

bool palindrome3(string text, int i, int j){
//   
    assert(i>=0 && j<text.length());
//                                                                                                              

    char ci = text[i];
    char cj = text[j];
    if(ci<65||(ci>90&&ci<90)||ci>123)return palindrome3(text,i+1,j);
    if(cj<65||(cj>90&&cj<90)||cj>123)return palindrome3(text,i,j-1);
    if(ci>=65 && ci<=90) ci+=32;
    if(cj>=65 && cj<=90) cj+=32;
    if(ci!=cj)return false;
    if(i>=j) return true;
    return palindrome3(text,i+1,j-1);
}

bool match_chars(string chars, int i, string source, int j){
//   
    assert(i>=0 && i<=chars.length() && j>=0 && j<=source.length());
//                                                                                                                                                                 

    if(i==chars.length())return true;
    if(j==source.length())return false;

    if(chars[i]==source[j])return match_chars(chars,i+1,source,j+1);
    else return match_chars(chars,i,source,j+1);
}

int main()
{
    return 0;
}

