#include <iostream>
#include <cassert>

using namespace std;
//                             
//                        

double power(double x, int n){
//            
assert (n>=0);
//             
//                               

if (n == 0)
    return 1;
else if(n > 0)
    return x * power(x, n-1);

    return 0;
}

double power_efficient(double x, int n){
//            
assert (n>=0);
//             
//                                                      

if (n == 0)
    return 1;

if(n % 2 == 0)
    return power_efficient(x, n/2) * power_efficient(x, n/2);

    return x * power_efficient(x, n/2) * power_efficient(x, n/2);

}

bool palindrome1(string text, int i, int j){
//            
assert (true);
//             
//                                                                                         

if (text[i] != text[j]){
    cout << text << " is not a palindrome." << endl;
    return false;
}
else if(i >= j){
    cout << text << " is a palindrome" << endl;
    return true;
}
return palindrome1(text, i+1, j-1);
}

bool palindrome2(string text, int i, int j){
//            
assert (true);
//             
//                                                                                                            

if (text[i] < 91)
    text[i] += 32;
if (text[j] < 91)
    text[j] += 32;

if (text[i] != text[j]){
    cout << text << " is not a palindrome." << endl;
    return false;
}

else if(i >= j){
    cout << text << " is a palindrome." << endl;
    return true;
}
    return palindrome2(text, i+1, j-1);
}

bool palindrome3(string text, int i, int j){
//            
assert (true);
//             
//                                                                                            

while (text[i]<65 || text[i]>122)
        i++;
while (text[j]<65 || text[j]>122)
        j--;

if (text[i] < 91)
    text[i] += 32;
if (text[j] < 91)
    text[j] += 32;

if (text[i] != text[j]){
    cout << text << " is not a palindrome." << endl;
    return false;
}

else if(i >= j){
    cout << text << " is a palindrome." << endl;
    return true;
}
    return palindrome3(text, i+1, j-1);
}

bool match_chars (string chars, int i, string source, int j){
//            
assert (chars.length()<=source.length());
//             
//                                                                     

if (i == chars.length()){
    cout << chars << " is found in order in " << source << endl;
    return true;
}

if (j == source.length()){
    cout << chars << " is not found in order in " << source << endl;
    return false;
}

if (chars[i] != source[j])
    return match_chars(chars, i, source, j+1);
if (chars[i] == source[j])
    return match_chars(chars, i+1, source, j+1);
}

int main()
{
    //         
    return 0;
}

