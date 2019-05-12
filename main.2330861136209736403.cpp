/*
             
                      
              
*/

#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)
{
    //             
    assert(n >= 0);
    //                                                       
    if(n == 0)
        return 1;
    else
        return x*power(x,n-1);
}

double efficient_power(double x, int n)
{
    //             
    assert(n >= 0);
    //                                                       
    double result;
    if(n == 0)
        return 1;
    else
    {
         if(n%2 == 0) //                        
         {
             result = power(x,n/2);
             return result*result;
         }
         else
            return power(x,n);
    }
/*
                                                                                                    
                                     
*/
}

bool palindrome1(string text, int i, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i <= j);
    //                                                                          

    if(i == j) //                                       
        return true;
    else if(j-i == 1) //                                                                     
        return text[i]==text[j];
    else
        return (text[i]==text[j] && palindrome1(text,i+1,j-1));
}

bool palindrome2(string text, int i, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i <= j);
    //                                                                                             
    if(i == j) //                                       
        return true;
    else if(j-i == 1) //                                                                     
        return toupper(text[i])==toupper(text[j]);
    else
        return (toupper(text[i])==toupper(text[j]) && palindrome2(text,i+1,j-1));
}

bool occurs(char character, char char_array [], int length)
{
    //             
    assert(length >= 0);
    //                                                                      
    for(int i = 0;i < length;i++)
    {
        if(character == char_array[i])
            return true;
    }
    return false;
}

string remove_punctuation(string text, int from, int to, int& new_length)
{
    //             
    assert(from >= 0 && to >= 0 && from <= to);
    //                                                                       
    char punct_array [9] = {' ','.',',',':',';','\'', '!', '?', '-'};
    string removed;
    new_length = 0;
    for(int i = from; i<=to; i++)
    {
        if(!(occurs(text[i],punct_array,9))) //                         
        {
            removed = removed + text[i];
            new_length++;
        }
    }
    return removed;
}

bool palindrome3(string text, int i, int j)
{
    //             
    assert(i >= 0 && j >= 0 && i <= j);
    //                                                                                                       
    string removed;
    int removed_length;
    removed = remove_punctuation(text,i,j,removed_length); //                                                 
    i = 0;
    j = removed_length - 1;

    //                        
    if(i == j) //                                       
        return true;
    else if(j-i == 1) //                                                                     
        return toupper(removed[i])==toupper(removed[j]);
    else
        return (toupper(removed[i])==toupper(removed[j]) && palindrome3(removed,i+1,j-1));
}

bool match_chars (string chars, int i, string source, int j)
{
    int chars_len = static_cast<int>(chars.length());
    int source_len = static_cast<int>(source.length());
    //             
    assert(i>=0 && j>=0 && i <= chars_len && j <= source_len);
    //                                                                      
    //                                                              

    if(chars[i]==source[j]) //                   
    {
        if(i != chars_len-1) //                                            
            return match_chars(chars, i+1,source, j+1);
        else //                                             
            return true;
    }
    else //          
    {
        if(j < source_len) //                                         
            return match_chars(chars,i,source,j+1);
        else //                                                                                                            
            return false;
    }

}

int main()
{
    cout << palindrome3 ("otto", 0, 3) << endl;
    cout << palindrome3 ("Otto", 0, 3) << endl;
    cout << palindrome3("Madam, I'm Adam.", 0, 15)  << endl;
    cout << endl;

    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    cout << match_chars ("abc", 0, "It is a bag of books", 0) << endl;
    cout << match_chars ("abc", 0, "It is a classy bag", 0) << endl;

    return 0;
}

