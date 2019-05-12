#include <iostream>
#include <cassert>

using namespace std;

/*
                            
                       
*/

int naive_power(double x, int n)
{
    //              
    assert(n>=0);
    //                                  
    if (n==0) //         
        return 1;
    else
        return x*naive_power(x,n-1);
}

int power(double x, int n)
{
    //              
    assert(n>=0);
    //                                  
    //                          
    if (n==0) //         
        return 1;
    else
    {
		const double TMP = power(x,n/2);
		if (n%2)
			return x*TMP*TMP;
		else
			return TMP*TMP;
	}
}

bool palindrome1 (string text, int i, int j)
{
    //              
    assert(i<=j+1);
    //                                                          
	//                                                               
	//                    
	if (i==j||i==j+1) //         
		return true;
	else if (text[i]!=text[j])
		return false;
	else
		return palindrome1(text, i+1, j-1);
}

bool equals (char a, char b)
{
	//              
    assert(true);
    //                                                        
	if(a==b)
		return true;
	if(a>64&&a<91&&a+32)
		return true;
	if(b>64&&b<91&&b+32)
		return true;
	return false;
}

bool is_punct (char a)
{
	//              
    assert(true);
    //                                                          
	string punct = " .,:;\'!?-";
	for (int i = 0; i < punct.length(); i++)
        if (a == punct[i])
            return true;
    return false;
}

bool palindrome2 (string text, int i, int j)
{
	//              
    assert(i<=j+1);
    //                                                          
	//                                           
	//                                                      
	if (i==j||i==j+1) //         
		return true;
	else if (!equals(text[i], text[j]))
		return false;
	else
		return palindrome2(text, i+1, j-1);
}

bool palindrome3 (string text, int i, int j)
{
    //              
    assert(i<=j+1);
    //                                                          
	//                                                                  
	//                                                      
	if (i==j||i==j+1) //         
		return true;
    else if (is_punct(text[i]))
        return palindrome3(text, i+1, j);
    else if (is_punct(text[j]))
        return palindrome3(text, i, j-1);
	else if (!equals(text[i], text[j]))
		return false;
	else
		return palindrome3(text, i+1, j-1);
}

bool match_chars (string chars, int i, string source, int j)
{
    //              
    assert(i<=j+1 && chars.length() <= source.length());
    //               
    //                                                       
    //                                                     
    if (i == chars.length()) //         
        return true;
    else if (j == source.length())
        return false;
    else if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j+1);
    else
        return match_chars(chars, i, source, j+1);
}

int main()
{
    //                     
    cout << power(3,5) << endl;
    cout << palindrome1 ("otto", 0, 3) << endl;
    cout << palindrome2 ("Otto", 0, 3) << endl;
    cout << palindrome3 ("Madam, I'm Adam.", 0, 15) << endl;
    cout << match_chars ("abc", 0, "It is a bag of cards", 0) << endl;
    return 0;
}

