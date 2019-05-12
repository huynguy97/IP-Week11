#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
using namespace std;

//                                                                             
//                                                                             
//                                                                              
//                                                                             
//                                                                             

double power(double x,int n){

//                                                                         
    assert(n>=0);
//                                                               

    if(n==0){
        return 1;
    }
    else {
        x=x*power(x,n-1);
        return x;
    }
}

double power_improved(double x,int n){

//                                                                         
    assert(n>=0);
//                                                               

    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return power_improved(x,n/2)*power_improved(x,n/2);
    }
    else {
        return x*power_improved(x,n/2)*power_improved(x,n/2);
    }
}

bool palindrome1 (string text, int i, int j){

    //                                                                                                    
    assert(i>=0 && j>=0 && j<=text.length()-1 && i<=text.length()-1);

    //                                                                                                                                                   
    if(i>j){
        return true;
    }

    if(text[i]!=text[j])
    {
        return false;
    }
    else{
        palindrome1(text,i+1,j-1);
    }
}

bool palindrome2 (string text, int i, int j){

    //                                                                                                    
            assert(i>=0 && j>=0 && j<=text.length()-1 && i<=text.length()-1);

    //                                                                                                                                          

    char a =text[i];
    char b = text[j];
    if (a<91 && a>65){
        a+=32;
    }
    if (b<91 && b>65){
        b+=32;
    }

    if(i>j){
        return true;
    }

    if(a!=b)
    {
        return false;
    }
    else{
        palindrome2(text,i+1,j-1);
    }
}

bool palindrome3 (string text, int i, int j){

    //                                                                                                    
            assert(i>=0 && j>=0 && j<=text.length()-1 && i<=text.length()-1);

    //                                                                                                                                                             

    char a =text[i];
    char b = text[j];

    while(a<65){
        a=text[i+1];
    }

    while(b<65){
        b=text[j-1];
    }

    if (a<91 && a>65){
        a+=32;
    }
    if (b<91 && b>65){
        b+=32;
    }

    if(i>j){
        return true;
    }

    if(a!=b)
    {
        return false;
    }
    else{
        palindrome3(text,i+1,j-1);
    }
}

bool match_chars (string chars, int i, string source, int j){

    //                                                                                                 
            assert(i>=0 && j>=0 && j<=source.length()-1 && i<=chars.length()-1);

    //                                                                                 

    while(j<=source.length()-1){
        if(chars[i]==source[j]){
            if(i<chars.length()-1){
                if(match_chars(chars,i+1,source,j+1)){
                    return true;
                }
            }
            else{
                return true;
            }
        }
        j++;
        }
    return false;
    }

int main() {

    //           

cout<<power(2,3)<<endl;
cout<<power_improved(2,4)<<endl;
cout<<power_improved(2,5)<<endl;
    if(palindrome1("Otto",0,3)) {
        cout << "true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    if(palindrome2("Otto",0,3)) {
        cout << "true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    if(palindrome3("Madam, I'm Adam.",0,15)) {
        cout << "true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    if(match_chars("abc", 0, "It is a classy bag c",0)) {
        cout << "true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
