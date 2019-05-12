#include <iostream>
#include <cassert>

using namespace std;

/*
                         
                    
*/

void upper(string& text, int x)
{
    //              
    assert (true);
    /*
                   
                                                            
    */
    if (text[x]<91)
    {
        text[x] += 32;
    }
}

void special(string text, int& x, int p)
{
    //              
    assert(true);
    /*
                   
                                       
    */
   while (!((text[x]>= 65 && text[x]<91) || (text[x]>= 97 && text[x]<123)))
    {
        x = x+1*p;
    }
}

//        
int power1 (double x, int n)
{
//              
assert( n >= 0);
/*
               
                         
                                         
*/

if (n==0)
{
    return 1;
}
else
{
    return x*power1(x,n-1);
}
}

//       
int power2 (double x, int n)
{
//              
assert( n >= 0);
/*
               
                                                        
                         
                                         
*/
if (n%2 == 0 && n!=0)
{
    int temp = power2(x,n/2);
    return temp*temp;
}

else if (n==0)
{
    return 1;
}
else
{
    return x*power2(x,n-1);
}
}
//                             

bool palindrome1 (string text, int i, int j)
{
    //             
    assert(j< text.length() && i >= 0);
    /*
                   
                                                                                                                         
    */
    if (i>=j)
    {
        return true;
    }
    else
    {
        if (text[i]==text[j])
        {
            return palindrome1(text, i+1, j-1);
        }
        else
        {
            return false;
        }
    }
}

bool palindrome2 (string text, int i, int j)
{
    //             
    assert(j< text.length() && i >= 0);
    /*
                   
                                                                                                                         
                                        
    */
    upper(text, i);
    upper(text, j);

    if (i>=j)
    {
        return true;
    }
    else
    {
        if (text[i]==text[j])
        {
            return palindrome2(text, i+1, j-1);
        }
        else
        {
            return false;
        }
    }
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert(j< text.length() && i >= 0);
    /*
                   
                                                                                                                         
                                        
                                        
    */
    special(text,i,1);
    special(text,j,-1);
    upper(text, i);
    upper(text, j);
    if (i>=j)
    {
        return true;
    }
    else
    {

        if (text[i]==text[j])
        {
            return palindrome3(text, i+1, j-1);
        }
        else
        {
            return false;
        }
    }
}

bool match_chars (string chars, int i, string source, int j)
{
    //              
    assert(true);
    /*
                   
                                                                               
    */
    if (i == chars.length())
    {
        return true;
    }
    else if(j == source.length())
    {
       return false;
    }
    else if (chars[i] == source [j])
    {
        return match_chars(chars, i+1, source, j+1);
    }
    else
    {
        return match_chars(chars, i, source, j+1);
    }

}
int main()
{
   //     
   cout << "slow methode: 2 power 6 = "<<power1 (2,6)<< endl;
   cout << "fast methode: 2 power 6 = "<<power2 (2,6)<< endl;
   cout << "otto via methode 1: " << palindrome1("otto", 0, 3) << endl;
    cout << "Otto via methode 1: " << palindrome1("Otto", 0, 3) << endl;
    cout << "Otto via methode 2: " << palindrome2("Otto", 0, 3) << endl;
   cout << "Madam, I'm Adam. via methode 1 : " << palindrome1("Madam, I'm Adam.", 0, 15) << endl;
    cout << "Madam, I'm Adam. via methode 2 : " << palindrome2("Madam, I'm Adam.", 0, 15) << endl;
    cout << "Madam, I'm Adam. via methode 1 : " << palindrome3("Madam, I'm Adam.", 0, 15) << endl;
    cout <<"abc for It is a bag of cards: " << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    cout <<"abc for It is a bag of books: " << match_chars ("abc", 0, "It is a bag of books", 0) << endl;
    cout <<"abc for It is a classy bag: " << match_chars ("abc", 0, "It is a classy bag", 0) << endl;

}

