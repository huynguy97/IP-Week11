//                    
//                      

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <stdio.h>

using namespace std;

double power (double x, int n){
//              
assert (n>=0);
//               
    if (n==0)
        return 1;
    if (n>0)
        return x*power(x, n-1);

}

double power1(double x, int n)
{
//                                        
//              
assert (n>=0);
//               
double a = n % 2;
    if (n==0)
        return 1;

    if (n>0)
        if (a==0)
            return x*power(x*x,n/2-1);
    else return x*power(x, n-1);

}

bool palindrome1 (string text, int i, int j){
//              
assert(i<=j && j>0);
int r=1;
for (i = 0; i<=j; i++)
    {if (text[i] == text[j])
    {
        j--;
    }
    else r=0;
    }
if (r==0)
    return false;
if (r==1)
    return true;

}

bool palindrome2 (string text, int i, int j)
{
//              
assert(i<=j && j>0);
for (i = 0; i<=j; i++)
{

        if (text[i] == text[j])
    {
        j--;
    }

    else if (text [j] == text[i]-32)
                j--;
    else if (text[i] == text[j]-32)
                j--;
    else return false;

}
  return true;
}

bool palindrome3 (string text, int i, int j)
{
//              
assert(i<=j && j>0);
    int b = 0;
for (i = 0; i<=j; i++)
{
    if (text[i]=='.'||text[i]==','||text[i]==':'||text[i]==';'||text[i]=='\''||text[i]=='!'||text[i]=='?'||text[i]=='-')
        {
            j--;
            b++;
        }
}
 j=j-b;
 if (text[i]=='.'||text[i]==','||text[i]==':'||text[i]==';'||text[i]=='\''||text[i]=='!'||text[i]=='?'||text[i]=='-'){
        for (i = 0; i<=j; i++)
    {
            text[i] = text[i+1];
    }
 }
for (i = 0; i<j-b; i++)
{

    if (text[i] == text[j])
    {
        j--;
    }

    else if (text [j] == text[i]-32)
                j--;
    else if (text[i] == text[j]-32)
                j--;
    else return false;

    }
  return true;
}

bool match_chars (string chars, int i, string source, int j)
{
//                                     
}

int main()
{
    cout << "give a number: ";
    double x;
    cin >> x;
    cout << "to what power: ";
    int n;
    cin >> n;
    cout << power (x, n) << endl;
    cout << power1(x,n) << endl;

    cout << "give a word: ";
    string text;
    cin >> text;
    int j = text.size()-1;
    int i = 0;
    if (palindrome1(text,i,j))
        cout << "word is palindrome1";
    if (palindrome2(text,i,j))
        cout << "word is palindrome2";
    if (palindrome3(text,i,j))
        cout << "word is palindrome3";

}

