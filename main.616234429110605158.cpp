#include <iostream>
#include<assert.h>

using namespace std;

int counter;

//                    
int naive_power(int x, int n)
{//            
    assert(n >= 0);
    counter++;

    if(n == 0)
        return 1;
    else
        return x * naive_power(x, n - 1);
}

//                                    
int power(int x, int n)
{//            
    assert(n >= 0);

    counter++;
    //          
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;

    //            
    if(n % 2 == 1)
        return (x * power(x, n - 1));

    //                                         
    int temp = power(x, n / 2);
    return temp * temp;
}

//                                            
bool palindrom1(string text, int i, int j)
{//            
    assert(i <= j);

    //           
    if(i == j) //                
        return true;

    if(text[i] == text[j])
    {
        if(j - i > 1)
            return palindrom1(text, i + 1, j - 1);
        else
            return true;
    }

    return false;
}

char lowercase(char c)
{//            
    assert(true);

    //                                                                                             
    if(c >= 65 && c <= 90)
        return static_cast<char>(c + 32);

    return c;
}

bool similar_letters(char a, char b)
{//            
    assert(true);

    return lowercase(a) == lowercase(b);
}

bool palindrom2(string text, int i, int j)
{//            
    assert(i <= j);

    //           
    if(i == j) //                
        return true;

    if(similar_letters(text[i], text[j]))
    {
        if(j - i > 1)
            return palindrom2(text, i + 1, j - 1);
        else
            return true;
    }

    return false;
}

char SPECIALS [] = {'.', ',', ':', ';', '\'', '!', '?', '-', ' ' };
char SPECIALS_COUNT = 9;

bool special_char(char c)
{
    for(int i = 0; i < SPECIALS_COUNT; i++)
        if(c == SPECIALS[i])
            return true;

    return false;
}

bool palindrom3(string text, int i, int j)
{//            
    assert(i <= j);

    //                                                                           

    //           
    if(i == j) //                   
        return true;

    if(special_char(text[i]) && i + 1 <= j)
        return palindrom3(text, i + 1, j);

    else if(special_char(text[j]) && j - 1 >= i)
        return palindrom3(text, i, j - 1);

    if(similar_letters(text[i], text[j]))
    {
        if(j - i > 1)
            return palindrom3(text, i + 1, j - 1);
        else
            return true;
    }

    return false;
}

bool match_chars(string chars, int i, string source, int j)
{//            
    assert(i >= 0 && i < chars.length() && j >= 0 && j < source.length());

    if(chars[i] == source[j])
    {
        if(i + 1 >= static_cast<int>(chars.length()))
            return true;

        return match_chars(chars, i + 1, source, j + 1);
    }

    if(j + 1 >= static_cast<int>(source.length()))
        return false;

    return match_chars(chars, i, source, j + 1);
}

//        
void returns_value(bool value)
{
    if(value)
        cout << " returns true" << endl;
    else
        cout << " returns false" << endl;
}

//        
void test_palindroms()
{
    string text [] = { "otto", "Otto", "Madam, I'm Adam." };
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "palindrom" << i + 1 << "(\"" << text[j] << "\", 0, " << text[j].length() - 1 << ")";
            switch(i)
            {
                case 0:
                    returns_value(palindrom1(text[j], 0, text[j].length()- 1));
                    break;
                case 1 :
                    returns_value(palindrom2(text[j], 0, text[j].length()- 1));
                    break;
                case 2:
                    returns_value(palindrom3(text[j], 0, text[j].length()- 1));
                    break;
            }
            cout << endl;
        }
    }
}

//        
void test_powers()
{
    int base = 2;
    int to_power = 25;

    counter = 0;
    cout << base << "^" << to_power << " = " << naive_power(base, to_power);
    cout << " calculated in " << counter << " (naive) recursions." << endl;
    cout << endl;

    counter = 0;
    cout << base << "^" << to_power << " = " << power(base, to_power);
    cout << " calculated in " << counter << " (efficient) recursions." << endl;
    cout << endl;

}

//        
void test_match()
{
    string chars = "abc";
    string source [] = { "It is a bag of cards", "It is a bag of books", "It is a classy bag" };

    for(int i = 0; i < 3; i++)
    {
        cout << "match_chars(\"abc\", 0, \"" << source[i] << "\", 0) ";
        returns_value(match_chars(chars, 0, source[i], 0));
        cout << endl;
    }
}

//                                                    
//                                                    

int main()
{

    //          
    test_powers();

    test_palindroms();

    test_match();

    return 0;
}

/*
                                                           

                
                 	                                            
                	     
              		     
                         
                   	     
            		                                            
                         
                                                              
                                                              
                                                                
        		         

*/

