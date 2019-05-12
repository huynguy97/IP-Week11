#include <iostream>
#include <string>
#include <cassert>

using namespace std;
//                             
int power(int x, int n)
{
//             
assert(n>=0);
//               
//                            
if(n==0)
	return 1;
else
	return x*power(x,n-1);
}

int power2(int x, int n)
{
//             
assert(n>=0);
//               
//                            
    if(n==0)
        return 1;
    else if(n%2==0)
    {
        int m=power2(x,n/2);
        return m*m;
    }
    else return power2(x,n-1)*x;
}
//                                                                                                                                                                                       
bool palindrome1 (string text, int i, int j)
{
//               
assert(i>=0&&j<text.length());
//                
//                                   
assert(i>=0 && j<=text.length());
	if(i>=j)
		return true;
	else
		return text[i]==text[j]&&palindrome1(text, i+1, j-1);
}

bool ignore_capital(char a, char b)
{
//               
assert(true);
//                
//                     
	if((a==b+32) && (b>=65&&b<=90))
        return true;
    else if ((b==a+32) && (b>=97&&b<=122))
        return true;
    else return false;
}

bool palindrome2 (string text, int i, int j)
{
 //               
assert(i>=0&&j<text.length());
//                
//                                                                                             
	if(i>=j)
		return true;
	else
	{
		return (text[i]==text[j]||ignore_capital(text[i],text[j]))&&palindrome2(text, i+1, j-1);
	}
}

bool palindrome3 (string text, int i, int j)
{
//               
assert(i>=0&&j<text.length());
//                
//                                                                                                                            

    while(text[i]==' '||text[i]=='.'||text[i]== ','||text[i]== ':'||text[i]== ';'||text[i]== '\''||text[i]== '!'||text[i]== '?'||text[i]== '-')
        i++;
    while(text[j]==' '||text[j]=='.'||text[j]== ','||text[j]== ':'||text[j]== ';'||text[j]== '\''||text[j]== '!'||text[j]== '?'||text[j]== '-')
        j--;
    if(i>=j)
        return true;
    else
    {
        if(text[i]==text[j]||ignore_capital(text[i],text[j]))
            return palindrome3(text, i+1, j-1);
        else return false;
    }
}

bool match_chars (string chars, int i, string source, int j)
{
//               
assert(i>=0&&j>=0);
//                
//                                                                                                  
    if(i>=chars.length())
        return true;
    if(j>=source.length())
        return false;
    else if(chars[i]==source[j])
        return match_chars(chars, i+1,source, j+1);
    else
        return match_chars(chars, i,source, j+1);
}

int main()
{
 /*                                         
                                          
                                          
                                          
                                          
                                          
                                                       
                                                       
                                                       
    */
cout<<match_chars ("abcz", 0, "It is a bag of cards", 0)<<endl;
//                                                                                    
cout<<match_chars ("abc", 0, "It is a bag of books", 0)<<endl;
//                                                                           
cout<<match_chars ("abc", 0, "It is a classy bag", 0)<<endl;
//                                                             

    return 0;
}

