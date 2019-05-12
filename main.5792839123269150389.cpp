#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)
{
    //            
    assert(n >= 0);
    /*               
                                                            
    */
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        return x * power(x, n-1);
    }
}

int power(int x, int n)
{
    //            
    assert(n >= 0);
    /*               
                                                            
    */
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        return x * power(x, n-1);
    }
}

/*                                                                                             
                                                                          
                                                                                                    
                                                                                                           
                                                                                                            
*/
double power2(double x, int n)
{
    //            
    assert(n >= 0);
    /*               
                                                            
    */
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else if(n % 2 == 0){
        return power(x, n/2) * power(x, n/2);
    }else{
        return x * power(x, n-1);
    }
}

int power2(int x, int n)
{
    //            
    assert(n >= 0);
    /*               
                                                            
    */
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else if(n % 2 == 0){
        return power(x, n/2) * power(x, n/2);
    }else{
        return x * power(x, n-1);
    }
}

bool palindrome1(string text, int i, int j)
{
    //            
    assert(i <= j);
    assert(i < text.length());
    assert(j < text.length());
    /*               
                                                                                 
                               
    */
    if(i == j){
        return true;
    }else if(i + 1 == j){
        return text[i] == text[j];
    }else{
        return text[i] == text[j] && palindrome1(text, i+1, j-1);
    }
}

bool compare_case_insensitive(char i, char j)
{
    //            
    assert(0 <= i && i < 128);
    assert(0 <= j && j < 128);
    /*               
                                                                                  
                                                     
    */
    if( 64 < i && i < 91 && 96 < j && j < 123 ){
        return i == j - 32;
    }else if( 64 < j && j < 91 && 96 < i && i < 123 ){
        return i - 32 == j;
    }else{
        return i == j;
    }
}

bool palindrome2(string text, int i, int j)
{
    //            
    assert(i <= j);
    assert(i < text.length());
    assert(j < text.length());
    /*               
                                                                               
                                                                   
    */
    if(i == j){
        return true;
    }else if(i + 1 == j){
        return compare_case_insensitive(text[i], text[j]);
    }else{
        return compare_case_insensitive(text[i], text[j]) && palindrome2(text, i+1, j-1);
    }
}

bool is_punctuation(char i){
    //            
    assert(0 <= i && i < 128);
    /*               
                                                                                                        
    */
    return i==' ' || i=='.' || i==',' || i==':' || i==';' || i=='\'' || i=='!' || i=='?' || i=='-';
}

bool compare_case_insensitive_ignore_punctuation(string text, int& i, int& j)
{
    //            
    assert(i < j);
    assert(i < text.length());
    assert(j < text.length());
    /*               
                                                                                                 
                                                                                                   
                              
    */
    while( is_punctuation(text[i]) ){
        if(i + 1 == j){
            return true;
        }
        i++;
    }
    while( is_punctuation(text[j]) ){
        if(i == j - 1){
            return true;
        }
        j--;
    }
    return compare_case_insensitive(text[i], text[j]);
}

bool palindrome3(string text, int i, int j)
{
    //            
    assert(i <= j);
    assert(i < text.length());
    assert(j < text.length());
    /*               
                                                                                             
                                                                                   
    */
    if(i == j){
        return true;
    }else if(i + 1 == j){
        return compare_case_insensitive_ignore_punctuation(text, i, j);
    }else{
        //                                                                                                       
        //                                                                                                           
        //                                                                                                              
        //                                                                                           
        return compare_case_insensitive_ignore_punctuation(text, i, j) && (i + 1 == j || palindrome3(text, i+1, j-1));
    }
}

bool match_chars(string chars, int i, string source, int j)
{
    //            
    assert(i < chars.length());
    assert(j < source.length());
    /*               
                                                                                                 
                                                                                                     
                               
    */
    if(chars[i] == source[j] && i + 1 == chars.length()){
        return true;
    } else if(j + 1 == source.length()){
        return false;
    } else if(chars[i] == source[j]){
        return match_chars(chars, i+1, source, j+1);
    } else{
        return match_chars(chars, i, source, j+1);
    }
}

//                         

int main()
{
    //                       
    int x = 5;
    cout << power(x,2) << endl;
    cout << power(1.5,4) << endl;
    cout << power(0.9,9) << endl;
    cout << endl;
    cout << power2(x,2) << endl;
    cout << power2(1.5,4) << endl;
    cout << power2(0.9,9) << endl;
    cout << endl;
    cout << palindrome1("otto", 0, 3) << endl;
    cout << palindrome1("Otto", 0, 3) << endl;
    cout << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << endl;
    cout << palindrome2("otto", 0, 3) << endl;
    cout << palindrome2("Otto", 0, 3) << endl;
    cout << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << endl;
    cout << palindrome3("otto", 0, 3) << endl;
    cout << palindrome3("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout << endl;
    cout << match_chars("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars("abc", 0, "It is a bag of books", 0) << endl;
    cout << match_chars("abc", 0, "It is a classy bag", 0) << endl;
    cout << match_chars("s a classy b", 0, "It is a classy bag", 2) << endl;
}

