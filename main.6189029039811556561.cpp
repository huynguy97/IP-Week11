#include <iostream>
#include <cassert>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <string>

using namespace std;

//                                                        

//      
double naive_power (double x, double n)
{
    //            
    assert(n>=0);
    //             
    //                     
    if (n == 0)
    {
        return 1;
    }
    else
    {
        x = x * naive_power(x,n-1);
        return x;
    }
}

void part1_naive ()
{
    double number;
    double power;
    cout << "What number do you want to power:" << endl;
    cin >> number ;
    cout << "To what do you want to power " << number << ":" << endl ;
    cin >> power ;
    cout << naive_power(number, power);
}

double efficient_power (double x, int n)
{
    //                                            
    //            
    assert(n>=0);
    //             
    //                     
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
        return efficient_power(x, n/2) * efficient_power(x, n/2);

    return x * efficient_power(x, n/2) * efficient_power(x, n/2);
}

void part1_efficient ()
{
    double number;
    int power;
    cout << "What number do you want to power:" << endl;
    cin >> number ;
    cout << "To what do you want to power " << number << ":" << endl ;
    cin >> power ;
    cout << efficient_power(number, power);
}

//      
bool palindrome1 (string text, int i, int j)
{
    //            
    assert (true);
    //             
    //                                                        
    if (j <= i)
    {
        return true;
    }
    else
    {
      if (text[i] == text[j-1])
      {
          palindrome1(text, i+1, j-1);
      }
      else
      {
          return false;
      }
    }
}

void part2_palindrome1 ()
{
    int x;
    string word ;
    cout << "Fill in a sentence or a word to check if it is a palindrome: " << endl;
    getline(cin, word) ;
    x = word.length();
    palindrome1 (word, 0, x);
    if (palindrome1 (word, 0, x) == true)
    {
        cout << "Thank you Kanye, very cool";
    }
    else
    {
        cout << "Not cool Kanye";
    }
}

bool palindrome2 (string text, int i, int j)
{
    //            
    assert (true);
    //             
    //                                                        

    if (j <= i)
    {
        return true;
    }
    if (text[i] < 91 )
    {
        text[i] =  text[i] + 32;
    }
    if (text[j] < 91)
    {
        text[j] = text[j] + 32;
    }

      if (text[i] == text[j])
      {
          return palindrome2(text, i+1, j-1);
      }
      else
      {
          return false;
      }

}

void part2_palindrome2 ()
{
    int x;
    string word ;
    cout << "Fill in a sentence or a word to check if it is a palindrome: " << endl;
    getline(cin, word) ;
    x = word.length() -1 ;
    palindrome2 (word, 0, x);
    if (palindrome2 (word, 0, x) == true)
    {
        cout << "Thank you Kanye, very cool";
    }
    else
    {
        cout << "Not cool Kanye";
    }
}

bool palindrome3 (string text, int i, int j)
{
    //            
    assert (true);
    //             
    //                                                                                                                      
    if (j <= i)
    {
        return true;
    }
    while (text[i] < 91 )
    {
        while (text[i] < 65)
        {
            i++;
        }
        if (64 < text[i] < 91){
        text[i] =  text[i] + 32;
        }
    }
    while (text[j] < 91 )
    {
        while (text[j] < 65)
        {
            j--;
        }
        if (64 < text[j] < 91){
        text[j] = text[j] + 32;
        }
    }

      if (text[i] == text[j])
      {
          return palindrome3(text, i+1, j-1);
      }
      else
      {
          return false;
      }

}

void part2_palindrome3 ()
{
    int x;
    string word ;
    cout << "Fill in a sentence or a word to check if it is a palindrome: " << endl;
    getline(cin, word) ;
    x = word.length() -1 ;
    palindrome3 (word, 0, x);
    if (palindrome3 (word, 0, x) == true)
    {
        cout << "Thank you Kanye, very cool";
    }
    else
    {
        cout << "Not cool Kanye";
    }
}

//      
bool match_chars (string chars, int i, string source, int j)
{
    //            
    assert(!false && chars.length() <= source.length());
    //             
    //                                            
    if (i == chars.length())
    {
        cout << "Sorry it matches";
        return true;
    }
    if (j == source.length())
    {
        cout << "It has  no matches";
        return false;
    }
    if (chars[i] == source[j])
    {
        return match_chars(chars, i+1, source, j+1);
    }
    else
    {
        return match_chars(chars, i, source, j+1);
    }
}

void part3_match()
{
    int i = 0;
    int j = 0;
    string chars;
    string source;
    cout << "Choose the chars you want to search: " << endl;
    cin >> chars;
    cout << "What source do you want to check: " << endl;
    getline(cin, source) ;
    match_chars(chars, i, source, j);
}

int main ()
{
    part1_naive();
    part1_efficient();
    part2_palindrome1();
    part2_palindrome2();
    part2_palindrome3();
    part3_match();
    return 0;
}

