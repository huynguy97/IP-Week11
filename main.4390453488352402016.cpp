/*                           
                    
*/
#include <iostream>
using namespace std;
#include <cstring>
#include <cassert>

int power(int x, int n)
{   //            
    assert(x >= 0 && n >= 0);
    //                        
    if(n == 0) {
      return 1;
    } else {
      x = x * power(x, n - 1);
      return x;
    }
}

//                                                
//                          
int power1(int x, int n)
{ //            
  assert(x >= 0 && n >= 0);
  //                        
  if(n == 0) {
    return 1;
  } else if(n == 1) {
    return x;
  } else {
    x = x * power1(x, n - 2);
    return 2*x;
  }
}

char charToLow(char in)
{ //            
  assert(true);
  //             
  //                                               
  if ( in >= 65 && in <= 90)
    return in + 32;
  return in;
}

string lowercase ( string input )
{ //            
  assert(true);
  //            
  //                                           
  for(int i = 0 ; i < input.length(); i++)
    input[i] = charToLow(input[i]);
  return input;
}

string stripstring ( string input )
{ //            
  assert(true);
  //             
  //                                                                   
  input = lowercase(input);
  string output = "";
  for(int i = 0 ; i < input.length(); i++)
    if(int(input[i]) > 96 && int(input[i]) < 123) //                  
      output += input[i];
  return output;
}

bool palindrome1 (string text, int i, int j)
{ //            
  assert(true);
  //            
  //                                         
  if(text[i] == text[j])
    if(j > i)
      return palindrome1(text, i + 1, j - 1);
    else
      return true;
  return false;
}
/*                                                     
                                                               
                                                                
              
*/
bool palindrome2 (string text, int i, int j)
{//            
  assert(true);
  //            
  //                                         
  text = lowercase(text);
  return palindrome1(text, 0, text.length() - 1);
}

bool palindrome3 (string text, int i, int j)
{//            
  assert(true);
  //            
  //                                         
  text = stripstring(text);
  return palindrome1(text, 0, text.length() - 1);
}

bool match_chars (string chars, int i, string source, int j)
{ //            
  assert(true);
  //            
  //                                          
  for (int p = j; p < source.length() - 1; p++) {
    if(chars[i] == source[p]) {
      if(i >= chars.length() - 1)
        return true;
      return match_chars(chars, i + 1, source, p);
    }
  }
  return false;
}

void printbool(bool i){
  if(i)
    cout << "TRUE" << endl<<endl;
  else
    cout << "FALSE" << endl<<endl;
}

int main()
{

  cout << ">> palindrome1 (\"otto\", 0, 3): " << endl;
  printbool(palindrome1 ("otto", 0, 3));

  cout << ">> palindrome1 (\"Otto\", 0, 3)" << endl;
  printbool(palindrome1 ("Otto", 0, 3));

  cout << ">> palindrome1 (\"Madam, I'm Adam.\", 0, 15) " << endl;
  printbool(palindrome1 ("Madam, I'm Adam.", 0, 15));

  cout << ">> palindrome2 (\"otto\", 0, 3): " << endl;
  printbool(palindrome2 ("otto", 0, 3));

  cout << ">> palindrome2 (\"Otto\", 0, 3)" << endl;
  printbool(palindrome2 ("Otto", 0, 3));

  cout << ">> palindrome2 (\"Madam, I'm Adam.\", 0, 15) " << endl;
  printbool(palindrome2 ("Madam, I'm Adam.", 0, 15));

  cout << ">> palindrome3 (\"otto\", 0, 3): " << endl;
  printbool(palindrome3 ("otto", 0, 3));

  cout << ">> palindrome3 (\"Otto\", 0, 3)" << endl;
  printbool(palindrome3 ("Otto", 0, 3));

  cout << ">> palindrome3 (\"Madam, I'm Adam.\", 0, 15) " << endl;
  printbool(palindrome3 ("Madam, I'm Adam.", 0, 15));

  cout << " >> match_chars (\"abc\", 0, \"It is a bag of cards\", 0) " << endl;
  printbool( match_chars ("abc", 0, "It is a bag of cards", 0) );

  cout << " >> match_chars (\"abc\", 0, \"It is a bag of books\", 0)" << endl;
  printbool( match_chars ("abc", 0, "It is a bag of books", 0) );

  cout << " >> match_chars (\"abc\", 0, \"It is a classy bag\", 0)" << endl;
  printbool( match_chars ("abc", 0, "It is a classy bag", 0) );

  return 1;
}

