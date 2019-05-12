//                          
//                       

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//                          
//                     

double power(float x, int  n)
{
    //                                           
    assert(n>=0);
    //                              

    if(n==0) return 1;
    else return x*power(x,n-1);
}

//                                 

double new_power(float x, int n)
{
    //                                           
    assert(n>=0);
    //                              

    if (n==0) return 1;
    else if (n%2==0){
        int y = new_power(x, n/2);
        return y*y;
    }
    else return x * new_power(x, n-1);
}

//                   
//                              

bool palindromel (string text, int i, int j)
{
    //             
    assert(true);
    //                                                                              

    if (i==j || j+1==i) return true;
    else if (text[i]==text[j]) return palindromel(text, i+1, j-1);
    else return false;

}

//                                      

bool palindrome2 (string text, int i, int j)
{
    //             
    assert(true);
    //                                                                                       
    //                                                                                              

    char texti = text[i];
    char textj = text[j];

    if ( 64 < texti && texti < 91) texti += 32;
    if ( 64 < textj && textj < 91) textj += 32;

    if (i==j || j+1==i) return true;
    else if (texti==textj) return palindrome2(text, i+1, j-1);
    else return false;

}

//                                                

bool char_is_punctuation_mark_or_space(char c)
{
    //             
    assert(true);
    //                                                                                                                  

    if (c=='.' || c== ',' || c== ':' || c== ';' || c == 39 || c=='!' || c=='?' || c== '-' || c == ' ') return true;
    else return false;
}

bool palindrome3 (string text, int i, int j)
{
    //             
    assert(true);
    //                                                                                       
    //                                                                                                                            

    char texti = text[i];
    char textj = text[j];

    if ( 64 < texti && texti < 91) texti += 32;
    if ( 64 < textj && textj < 91) textj += 32;

    if (i==j || j < i) return true;
    else if (char_is_punctuation_mark_or_space(texti)) return palindrome3(text, i+1, j);
    else if (char_is_punctuation_mark_or_space(textj)) return palindrome3(text, i, j-1);
    else if (texti==textj) return palindrome3(text, i+1, j-1);
    else return false;

}

//                                        

bool match_chars (string chars, int i, string source, int j)
{
    //             
    assert(true);
    //                                                                                          
    //                                                                                               

    if (i == chars.length()) return true;
    else if (j == source.length()) return false;
    else if (chars[i]==source[j]) return match_chars(chars, i+1, source, j+1);
    else return match_chars(chars, i, source, j+1);

}

int main()
{
    cout << power(3,9) << endl;
    cout << new_power (3, 9 ) << endl;

    string test1 = "otto";
    string test2 = "Otto";
    string test3 = "Madam, I'm Adam.";

    cout << test1 << " palin 1 gives " << palindromel(test1, 0, test1.length()-1) << endl;
    cout << test2 << " palin 1 gives " << palindromel(test2, 0, test2.length()-1) << endl;
    cout << test3 << " palin 1 gives " << palindromel(test3, 0, test3.length()-1) << endl;

    cout << test1 << " palin 2 gives " << palindrome2(test1, 0, test1.length()-1) << endl;
    cout << test2 << " palin 2 gives " << palindrome2(test2, 0, test2.length()-1) << endl;
    cout << test3 << " palin 2 gives " << palindrome2(test3, 0, test3.length()-1) << endl;

    cout << test1 << " palin 3 gives " << palindrome3(test1, 0, test1.length()-1) << endl;
    cout << test2 << " palin 3 gives " << palindrome3(test2, 0, test2.length()-1) << endl;
    cout << test3 << " palin 3 gives " << palindrome3(test3, 0, test3.length()-1) << endl;

    string abc = "abc";

    cout << abc << " It is a bag of cards " << match_chars(abc, 0, "It is a bag of cards", 0) << endl;
    cout << abc << " It is a bag of books " << match_chars(abc, 0, "It is a bag of books", 0) << endl;
    cout << abc << " It is a classy bag " << match_chars(abc, 0, "It is a classy bag", 0) << endl;

    return 0;
}

