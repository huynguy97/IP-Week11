#include <iostream>
#include <cassert>

using namespace std;

double power(double x, int n)
{
    //            
    assert(n >= 0);
    //             
    //                       

    if(n == 0)
        return 1;
    else
        return x * power(x, n-1);
}

double power2(double x, int n)
{
    //            
    assert(n >= 0);
    //             
    //                       

    if(n == 0)
        return 1;
    else
    {
        if((n % 2) == 0 )
        {
            n = n/2;
            return x*power2(x, n-1) * x*power2(x, n-1);
        }
        else
            return x*power2(x, n-1);
    }
}
//                                  

int size(string text)
{
    return static_cast<int>(text.size());
}

bool palindrome1(string text, int i, int j)
{
    //            
    assert(i <= j && j < size(text));
    //             
    //                                                                    
    //               

    if(j == i || j == i+1)          //                                            
        return text[i] == text[j];  //                                              
                                    //               
    else
    {
        return (text[i] == text[j]) && palindrome1(text, ++i, --j);
    }

}

bool palindrome2(string text, int i, int j)
{
    //            
    assert(i <= j && j < size(text));
    //             
    //                                                                    
    //                          

    //                                
    if(text[i] > 64 && text[i] < 91)
        text[i] += 32;
    if(text[j] > 64 && text[j] < 91)
        text[j] += 32;

    if(j == i || j == i+1)
        return text[i] == text[j];
    else
    {
        return (text[i] == text[j]) && palindrome2(text, ++i, --j);
    }

}

bool palindrome3(string text, int i, int j)
{
    //            
    assert(i <= j && j < size(text));
    //             
    //                                                                    
    //                                                          

    //                                                       
    if(text[i] == ' ' || text[i] == '.' || text[i] == ',' ||
       text[i] == ';' || text[i] == ':' || text[i] == '\\' ||
       text[i] == '!' || text[i] == '?' || text[i] == '-')
       return palindrome3(text, ++i, j);
    if(text[j] == ' ' || text[j] == '.' || text[j] == ',' ||
       text[j] == ';' || text[j] == ':' || text[j] == '\\' ||
       text[j] == '!' || text[j] == '?' || text[j] == '-')
       return palindrome3(text, i, --j);

    //                                
    if(text[i] > 64 && text[i] < 91)
        text[i] += 32;
    if(text[j] > 64 && text[j] < 91)
        text[j] += 32;

    if(j == i || j == i+1)
        return text[i] == text[j];
    else
    {
        return (text[i] == text[j]) && palindrome3(text, ++i, --j);
    }

}

bool match_chars(string chars, int i, string source, int j)
{
    //            
    assert(i >= 0 && j >= 0 && i <= size(chars) && j <= size(source));
    //             
    //                                                                      

    if(j == size(source)-1)                             //                            
        return chars[i] == source[j];
    if(i == size(chars)-1 && (chars[i] == source[j]))   //                           
        return true;

    else
        if(chars[i] == source[j])
            return match_chars(chars, ++i, source, ++j);
        else
            return match_chars(chars, i, source, ++j); //                            

}

/*
        
                     
                       
                       

*/
int main()
{
    cout << power2(3,4) << endl;
    if (palindrome1("lepel", 0, 4))
        cout << "Yes 1" << endl;
    if (palindrome2("lepel", 0, 4))
        cout << "Yes 2" << endl;
    if (palindrome3("le.pEl", 0, 5))
        cout << "Yes 3" << endl;
    if(match_chars("abc", 0, "it is a classy bag", 0))
         cout << "Yes" << endl;

    return 0;
}

