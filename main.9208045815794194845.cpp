#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
int counter1 = 0;
int counter2 = 0;

double power(double x, int n)
{
    //            
    assert(n >=0);
    //             
    //                          

    counter1++;
    if (n <= 0){
        return 1;
    }
    else {
        return x * power(x, n-1);
    }
}

double power_efficient(double x, int n)
{
    //            
    assert(n >=0);
    //             
    //                                        
    counter2++;
    if (n <= 0){
        return 1;
    }
    else{
        if (n % 2 == 0){
            double y = power_efficient(x, n/2);
            return y*y;
        }
        else {
            return x * power_efficient(x, n-1);
        }
    }
}

bool palindrome1 (string text, int i, int j)
{
    //            
    assert(true);
    //             
    //                              

    if (j-i <= 0){
        return true;
    }
    else {
        if(text[i] == text[j])
        {
            return palindrome1(text, i+1 , j-1);
        }
        else {
            return false;
        }
    }
}

string lower(string str)
{
    //            
    assert(true);
    //             
    //                               

    for(int i = 0; i <= str.length()-1; i++){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
    }
    return str;
}

bool palindrome2 (string text, int i, int j)
{
    //            
    assert(true);
    //             
    //                                            
     return palindrome1(lower(text), i, j);
}

string strip(string str)
{
    //            
    assert(true);
    //             
    //                                                           
    string tmp;
    for(int i = 0; i <= str.length()-1; i++){
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)){
            tmp = tmp + str[i];
        }
    }

    return tmp;
}

bool palindrome3 (string text, int i, int j)
{
    //            
    assert(true);
    //             
    //                                                             

    string x = strip(lower(text));
    return palindrome1(x, i, x.length()-1);
}

bool match_chars (string chars, int i, string source, int j)
{
    //            
    assert(true);
    //             
    //                                         

    if(i >= chars.length()){
        return true;
    }
    if(j >= source.length()){
        return false;
    }
    if(chars[i] == source[j]){
        i++;
        return match_chars(chars, i, source, j);
    }
    else{
        j++;
        return match_chars(chars, i, source, j);
    }
}

//                  
bool match_pattern (string pattern, string source)
{
    //            
    assert(true);
    //             
    //                                                    

    if (pattern.length() == 0 && source.length() == 0){
        return true;
    }
    if (pattern[pattern.length()-1] == '.' || pattern[pattern.length()-1] == source[source.length()-1]){
        pattern.erase(pattern.length()-1);
        source.erase(source.length()-1);
        return match_pattern(pattern,source);
    }
    else if (pattern[pattern.length()-1] == '*'){
        if (pattern.length() == 1){
            return true;
        }
        pattern.erase(pattern.length()-1);
        string temp;
        while(source.length() > 0){
            temp = source;
            if (match_pattern(pattern,temp) == false){
                cout << source[source.length()-1] << endl;
                source.erase(source.length()-1);
            }
            else {
                return true;
            }
        }
    }
    else {
        return false;
    }
}

int main()
{
    /*
          
                            
                          
    */

    //               
    cout << power(2.0, 64);
    cout << " - " << counter1 << endl;

    //                    
    cout << power_efficient(2.0, 64);
    cout << " - " << counter2 << endl;

    //      
    cout << palindrome1 ("otyto", 0, 4) << endl;
    cout << palindrome2 ("OtYto", 0, 4) << endl;
    cout << palindrome3 ("O.tY!to.", 0, 7) << endl;

    //     
    cout << match_chars ("abc", 0, "It bis a aag of cards", 0) << endl;

    //     
    //                                             
    //                                            
    //                                                  
    cout << match_pattern("*","m Theater") << endl;
    //                                                     
    return 0;
}

