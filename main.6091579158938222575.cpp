#include <iostream>
#include <assert.h>

using namespace std;
//                         
//                    

int power (int x, int n)
{
    //             
    assert (n >= 0);

    //                                                        
    if (n == 0)
        return 1;
    if (n > 0)
    {
        x = x * power (x, n-1);
        return x;
    }
}

int efficient_power (int x, int n)
{
    //             
    assert (n >= 0);

    //                                                                                           
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        if (n % 2 == 0)
        {
            x = efficient_power (x,n/2) * efficient_power (x,n/2);
            return x;
        }
        else if (n % 2 != 0)
        {
            x = x * efficient_power (x, n-1);
            return x;
        }
    }
}

bool palindrome1(string text, int i, int j)
{
    assert(i>=0&&j>=0);
    //                                                       
    if(i>=j)
    {
        return true;
    }
    if(text[i]!=text[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        return palindrome1(text, i, j);
    }

}

void case_insensitive(string& text, int& i, int& j)
{
    assert(i>=0&&j>=0);
    //                                                                          
    if(text[i]<97&&text[i]>64)
    {
        text[i]=text[i]+32;
    }
    if(text[j]<97&&text[j]>64)
    {
        text[j]=text[j]+32;
    }
}

bool palindrome2(string text, int i, int j)
{
    assert(i>=0&&j>=0);
    //                                                       
    case_insensitive(text, i, j);
    if(i>=j)
    {
        return true;
    }
    if(text[i]!=text[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        return palindrome2(text, i, j);
    }
}

void ignoring_special_chars(string& text, int& i, int& j)
{
    assert(i>=0&&j>=0);
    //                                             
    while(text[i]<65)
    {
        i++;
    }
    while(text[j]<65)
    {
        j--;
    }
}

bool palindrome3(string text, int i, int j)
{
    assert(i>=0&&j>=0);
    //                                                       
    case_insensitive(text, i, j);
    ignoring_special_chars(text, i, j);
    if(i>=j)
    {
        return true;
    }
    if(text[i]!=text[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        return palindrome3(text, i, j);
    }
}

bool match_chars(string chars, int i, string source, int j)
{
    assert(i>=0&&j>=0);
    //                                                                                               
    case_insensitive(source, j, j);
    case_insensitive(chars, i, i);
    if(i==(chars.length()))
    {
        return true;
    }
    if(j==(source.length()))
    {
        return false;
    }
    if(chars[i]==source[j])
    {
        i++;
        j++;
        return match_chars(chars, i, source, j);
    }
    j++;
    return match_chars(chars, i, source, j);
}

int main()
{
    cout << efficient_power (2,10)<<endl;
    cout << palindrome1("otto", 0, 3);
    cout << palindrome1("ottto", 0, 4);
    cout << palindrome1("Otto", 0, 3)<<endl;
    cout << palindrome2("otto", 0, 3);
    cout << palindrome2("ottto", 0, 4);
    cout << palindrome2("Otto", 0, 3);
    cout << palindrome2("Madam, I'm Adam.", 0, 15) <<endl;
    cout << palindrome3("otto", 0, 3);
    cout << palindrome3("ottto", 0, 4);
    cout << palindrome3("Otto", 0, 3);
    cout << palindrome3("Madam, I'm Adam.", 0, 15) <<endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0);
    cout << match_chars ("abc", 0, "It is a bag of books", 0);
    cout << match_chars ("abc", 0, "It is a classy bag", 0) ;
    return 0;
}

