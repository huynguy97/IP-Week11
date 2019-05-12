//                                 
//                                 

#include <iostream>
#include <math.h>
#include <assert.h>
#include <string>

using namespace std;

double calculate_power(double x, int n){
    //              
    assert(n >= 0 && x >=0);
    //                
    //                                        
    if (n==0)
        return 1;
    return x * calculate_power(x, n-1);

}

double power_naive(double x, int n){
    //              
    assert(n >= 0 && x >=0);
    //                
    //                                        
    //                           
    return calculate_power(x, n);
}

double power_efficient(double x, int n)
{
    //              
    assert(n >= 0 && x >=0);
    //                
    //                                        
    //                                       
    //                                  
    if (n % 2 == 0){
        double y = calculate_power(x,n/2);
        return y * y;
    }
    return calculate_power(x,n);

}

void part1()
{
    //              
    assert(true);
    //                
    //                                                   
    //                                                    
    //                           
    double x = 16;
    int n = 5;
    cout << "Naive: \t \t \t" << power_naive(x, n) << endl;
    cout << "Efficient: \t \t" << power_efficient(x,n) << endl;
    cout << "Standard function: \t" << pow(x,n) << endl;
}

bool palindrome(string& word, int i, int j){
    //              
    assert(word.length() >= i >= 0 && word.length() >= j >=0);
    //                
    //                                       
    //                                     
    //                                 
    if (i >= j)
        return true;
    else{
        if (word[i] != word[j])
            return false;
        return palindrome(word, i + 1, j - 1);
    }
}

bool  palindrome1(string word, int i, int j){
     //              
    assert(word.length() >= i >= 0 && word.length() >= j >=0);
    //                
    //                                                  
    palindrome(word, i, j);
}

bool CaseInsensitive(string& word, int i, int j){
    //              
    assert(word.length() >= i >= 0 && word.length() >= j >=0);
    //                
    //                                                         
    if (i > j){
        return true;
    }
    else{
        if (65 <= int(word[i]) && int(word[i]) <= 90){
            word[i] = char(int(word[i] + 32));
        }
        return true;
    }

}
bool  palindrome2(string word, int i, int j){
     //              
    assert(word.length() >= i >= 0 && word.length() >= j >=0);
    //                
    //                                                    
    for(int k = 0; k <= word.length()-1; k++){
        CaseInsensitive(word, k, j);
    }
    palindrome(word, i, j);
}

bool swap(string word, int i){
    //              
    assert(word.length() >= i >= 0);
    //                
    //                                                                                 
    //                            
    if (i >= word.length()-1){
        word[word.length()-1] = ' ';
        return true;
    }

    else{
        word[i] = word[i+1];
        return swap(word, i + 1);
    }
}

bool SpecialChar(string word, const int i, int j, int n){
    //              
    assert(word.length() >= i >= 0 && word.length() >= j >=0 && n >= 0);
    //                
    //                                                
    const int SPECIALCHARS = 9;
    if(i > word.length()-1 || n >= SPECIALCHARS)
        return true;
    else{
        char signs [SPECIALCHARS] = {' ', '.', ',', ':', ';', '\'', '!', '?', '-'};
        if(word[i] == signs[n] && i <= word.length()-1){
            swap(word,i);
            j--;

        }
        else if(word[i] == signs[j] && i == word.length() - 1){
            j--;
        }
        else
            return SpecialChar(word, i, j, n+1);
    }
}
bool  palindrome3(string word, int i, int j){
    //              
    assert(word.length() >= i >= 0 && word.length() >= j >=0);
    //                
    //                                                                                 
    for(int k = 0; k <= word.length()-1; k++){
        SpecialChar(word, k, j, 0);
        CaseInsensitive(word, k, j);
    }
   palindrome(word, i, j);
}

void part2(){
    //              
    assert(true);
    //                
    //                                                   
    //                                                       

    const string word = "m:adaM.imadam," ;
    const int i = 0;
    const int j = word.length() - 1;

    if (palindrome1(word, i, j))
        cout << endl << word << " is a case sensitive palindrome." << endl;
    else
        cout << endl << word << " is not a case sensitive palindrome." << endl;

    if (palindrome2(word, i, j))
        cout << endl << word << " is a case insensitive palindrome." << endl;
    else
        cout << endl << word << " is not a case insensitive palindrome." << endl;

    if (palindrome3(word, i, j))
        cout << endl << word << " is a case insensitive palindrome ignoring special characters." << endl;
    else
        cout << endl << word << " is not a case insensitive palindrome ignoring special characters." << endl;
}

bool match_chars(string chars,int i,string source, int j){
    //              
    assert(chars.length() >= j >= 0);
    //                
    //                                                     
    if(i >= chars.length())
        return true;
    else{
        if(j >= source.length())
            return false;
        else{
            if(source[j] != chars[i])
                return match_chars(chars, i, source, j+1);
            return match_chars(chars, i+ 1, source, j);
        }
    }
}
void part3(){
    //              
    assert(true);
    //                
    //                                                   
    //                                              
    string chars ="aca";
    string source ="It is a bag of cards";
    int i = 0;
    int j = 0;
    if(match_chars(chars,i,source, j))
        cout << "Found the sequence: \"" << chars << "\" in the source text: \"" << source << "\"." << endl << endl ;
    else
        cout << "Could not find the sequence: \"" << chars << "\" in the source text: \"" << source << "\"." << endl << endl;
}
int main() {
    cout << endl << endl << "********************************** PART 1 **********************************" << endl << endl;
    part1();
    cout << endl << endl << "********************************** PART 2 **********************************" << endl << endl;
    part2();
    cout << endl << endl << "********************************** PART 3 **********************************" << endl << endl;
    part3();
    return 0;
}

