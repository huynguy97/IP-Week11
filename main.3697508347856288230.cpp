#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*                                                                   
                 
                                 
                              
                                                                   */

double power(double x, int n) {
  assert(n >= 0);
  //                                
  if (n == 0) {
    return 1;
  } else {
    return x * power(x, n - 1);
  }
}

//                                                           
double efficientPower(double x, int n) {
  assert(n >= 0);
  //                                   
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return x;
  }
  double y = efficientPower(x, n / 2);
  if (n % 2 == 1) {
    return y * y * x;
  } else {
    return y * y;
  }
}

bool palindrome1(string str, int i, int j) {
  assert(i <= j);
  //                                                   
  if (abs(i - j) <= 1) {
    return true;
  } else {
    return palindrome1(str, i + 1, j - 1) && str[i] == str[j];
  }
}

bool palindrome2(string str, int i, int j) {
  assert(i <= j);
  //                                                   
  //                                                             
  if (abs(i - j) <= 1) {
    return true;
  } else {
    char c1 = str[i];
    char c2 = str[j];
    //                                                                    
    //          
    c1 = (c1 > 64 && c1 < 91) ? c1 + 32 : c1;
    c2 = (c2 > 64 && c2 < 91) ? c2 + 32 : c2;
    return palindrome2(str, i + 1, j - 1) && c1 == c2;
  }
}

bool palindrome3(string str, int i, int j) {
  assert(i <= j);
  //                                                   
  //                                                             
  //                                     
  if (abs(i - j) <= 1) {
    return true;
  } else {
    char c1 = str[i];
    char c2 = str[j];
    //                                 
    if (!((c1 > 64 && c1 < 91) || (c1 > 96 && c1 < 123))) {
      return palindrome3(str, i + 1, j);
    }
    //                                 
    if (!((c2 > 64 && c2 < 91) || (c2 > 96 && c2 < 123))) {
      return palindrome3(str, i, j - 1);
    }
    //                                                                    
    //          
    c1 = (c1 > 64 && c1 < 91) ? c1 + 32 : c1;
    c2 = (c2 > 64 && c2 < 91) ? c2 + 32 : c2;
    return palindrome3(str, i + 1, j - 1) && c1 == c2;
  }
}

bool match_chars(string chars, int i, string source, int j){
  assert(i>= 0 && j>= 0 && i <= chars.length());
  //                                                                                                                                        
  if(i == chars.length()){
    return chars[i-1] == source[j-1];
  } else {
    char c1 = chars[i];
    char c2 = source[j];

  if(c1 == c2){
    return match_chars(chars, i+1, source, j+1);
  } else {
    return match_chars(chars, i, source, j+1);
  }

  }
}

int main(int argc, char const *argv[]) {
  cout << "power(2,8)=" << power(2, 8) << endl;
  cout << "power(17.5,9)=" << power(17.5, 9) << endl;
  cout << "efficientPower(17.5,9)=" << efficientPower(17.5, 9) << endl;
  cout << "palindrome1(otto,0,3)="
       << (palindrome1("otto", 0, 3) ? "true" : "false") << endl;
  cout << "palindrome1(Otto,0,3)="
       << (palindrome1("Otto", 0, 3) ? "true" : "false") << endl;
  cout << "palindrome2(otto,0,3)="
       << (palindrome2("otto", 0, 3) ? "true" : "false") << endl;
  cout << "palindrome2(Otto,0,3)="
       << (palindrome2("Otto", 0, 3) ? "true" : "false") << endl;
  cout << "palindrome3(Madam, I'm Adam.,0,15)="
       << (palindrome3("Madam, I'm Adam.", 0, 15) ? "true" : "false") << endl;
  cout << "match_chars(\"abc\", 0,\"It is a bag of cards\", 0)="
       << (match_chars("abc", 0,"It is a bag of cards", 0) ? "true" : "false") << endl;
  cout << "match_chars(\"abc\", 0,\"It is a bag of books\", 0)="
       << (match_chars("abc", 0,"It is a bag of books", 0) ? "true" : "false") << endl;
  while (true) {
    string test;
    cin >> test;
  }
  return 0;
}

