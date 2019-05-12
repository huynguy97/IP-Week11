#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

//                                                           

double power(double x,int n){
    //        
//                   
//                                                                                                                        
//                       
//         
//                               
//                 
//     

    //        
    //                                                                  
    //             
    assert(x >= 0);
    //                                                                                                                  

    if(n == 1) return x;
    else if(n == 2) return x*x;
    else{
        x = power(x,(n/2))*power(x,(n/2)+(n%2));
        return x;
    }
}

bool palindrome1(string text,int i,int j){
    //             
    assert(i >=0 && j <= text.length());
    //                                                                                                                                          
    if(i==j||i==j-1)return text[i]==text[j];
    else
    {
        if (text[i]==text[j])return palindrome1(text,i+1,j-1);
        else return false;
    }
}

bool palindrome2(string text,int i,int j)
{
    //             
    assert(i >=0 && j <= text.length());
    //                                                                                                                                             
    int sym_i=1;
    int sym_j=1;
    if(int(text[i]) > 91) sym_i=-1;
    if(int(text[j]) > 91) sym_j=-1;
    if(i == j||i == j-1)return (int(text[i]) == int(text[j])|| int(text[i]+sym_i*32) == int(text[j])|| int(text[i]) == int(text[j])+sym_j*32);
    else
    {
        if (int(text[i]) == int(text[j])|| int(text[i]+sym_i*32) == int(text[j])|| int(text[i]) == int(text[j])+sym_j*32)return palindrome2(text,i+1,j-1);
        else return false;
    }
}

bool palindrome3(string text,int i,int j)
{
    //             
    assert(i >=0 && j <= text.length());
    //                                                                                                                                         
    while(int(text[i])<65||(int(text[i])>90&&int(text[i])<97)||int(text[i])>123)
    {
        i++;
    }
    while(int(text[j])<65||(int(text[j])>90&&int(text[j])<97)||int(text[j])>123)
    {
        j--;
    }
    int sym_i=1;
    int sym_j=1;
    if(int(text[i]) > 91) sym_i=-1;
    if(int(text[j]) > 91) sym_j=-1;
    if(i == j||i == j-1)return (int(text[i]) == int(text[j])|| int(text[i]+sym_i*32) == int(text[j])|| int(text[i]) == int(text[j])+sym_j*32);
    else
    {
        if (int(text[i]) == int(text[j])|| int(text[i]+sym_i*32) == int(text[j])|| int(text[i]) == int(text[j])+sym_j*32)return palindrome3(text,i+1,j-1);
        else return false;
    }
}

bool match_chars(string chars,int i, string source,int j){
    //             
    assert(i >= 0 && j >= 0);
    //                                                                                                                                                             
     while(chars[i]!=source[j]&&j<source.length())
     {
         j++;
     }
     if(j == source.length())return false; //                                            
     else if (i == chars.length()-1) return true;
     else
     {
       return  match_chars(chars,i+1,source,j+1);
     }

}

int main()
{
    string to_find_true = "ae";
    string to_find_false = "aeb";
    string word="hat in the";
    cout << "power: " << power(5.5,6) << endl;
    cout << "palindrome1: " << palindrome1("otto", 0, 3) << endl;
    cout << "palindrome1: " << palindrome1("Otto", 0, 3) << endl;
    cout << "palindrome1: " << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << "palindrome2: " << palindrome2("otto", 0, 3) << endl;
    cout << "palindrome2: " << palindrome2("Otto", 0, 3) << endl;
    cout << "palindrome2: " << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << "palindrome3: " << palindrome3("otto", 0, 3) << endl;
    cout << "palindrome3: " << palindrome3("Otto", 0, 3) << endl;
    cout << "palindrome3: " << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << "palindrome3: " << palindrome3("Madam, I'm Bob.", 0, 15) << endl;
    cout << "match: " << match_chars(to_find_true, 0, word, 0) << endl;
    cout << "match: " << match_chars(to_find_false, 0, word, 0) << endl;
    return 0;
}

