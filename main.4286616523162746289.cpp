//                                                     
#include <iostream>
#include <assert.h>
using namespace std;

//                 
//                                                  
int naive_power(int x,int n){
	//            
	assert(n>=0);
	//             
	//           
	if (n == 0) return 1;
	return x*naive_power(x,n-1);
}

double naive_power(double x,int n){
	//            
	assert(n>=0);
	//             
	//           
	if (n == 0) return 1.0;
	return x*naive_power(x,n-1);
}

//                   
int power(int x,int n){
	//            
	assert(n>=0);
	//             
	//           
	if (n == 0) return 1;
	if (n % 2 == 1)
		return x*power(x*x,n/2);
	else
		return power(x*x,n/2);
}

double power(double x,int n){
	//            
	assert(n>=0);
	//             
	//           
	if (n == 0) return 1.0;
	if (n % 2 == 1)
		return x*power(x*x,n/2);
	else
		return power(x*x,n/2);
}

bool palindrome1 (string text,int i,int j){
	//            
	assert (0<=i and i<static_cast<int>(text.size()));
	assert (0<=j and j<static_cast<int>(text.size()));
	//             
	//                                                             
	if (j<i) return true;
	if (text[i] != text[j]) return false;
	return palindrome1(text,i+1,j-1);
}

bool palindrome2 (string text,int i,int j){
	//            
	assert (0<=i and i<static_cast<int>(text.size()));
	assert (0<=j and j<static_cast<int>(text.size()));
	//             
	//                                                             
	//                          
	if (j<i) return true;
	if (text[i] >= 'A' and text[i] <= 'Z')
		text[i] = text[i]-'A'+'a';
	if (text[j] >= 'A' and text[j] <= 'Z')
		text[j] = text[j]-'A'+'a';
	if (text[i] != text[j]) return false;
	return palindrome2(text,i+1,j-1);
}

bool isSpecialChar(char c){
	//            
	assert(true);
	//             
	//                                          
	if (c == ' ')  return true;
	if (c == '.')  return true;
	if (c == ',')  return true;
	if (c == ':')  return true;
	if (c == ';')  return true;
	if (c == '\'') return true;
	if (c == '!')  return true;
	if (c == '?')  return true;
	if (c == '-')  return true;
	return false;
}

bool palindrome3 (string text,int i,int j){
	//            
	assert (0<=i and i<static_cast<int>(text.size()));
	assert (0<=j and j<static_cast<int>(text.size()));
	//             
	//                                                             
	//                          
	while (isSpecialChar(text[i]) and i<=j)i++;
	while (isSpecialChar(text[j]) and i<=j)j--;
	if (j<i) return true;
	if (text[i] >= 'A' and text[i] <= 'Z')
		text[i] = text[i]-'A'+'a';
	if (text[j] >= 'A' and text[j] <= 'Z')
		text[j] = text[j]-'A'+'a';
	if (text[i] != text[j]) return false;
	return palindrome3(text,i+1,j-1);
}

bool match_chars(string chars, int i,string source, int j){
	//            
	assert(i>=0 and j>=0);
	//             
	//                                                            
	if (i >= static_cast<int>(chars.size())) return true; //                    
	if (j >= static_cast<int>(source.size())) return false; //                        
	if (chars[i] == source[j])
		return match_chars(chars,i+1,source,j+1);
	else
		return match_chars(chars,i,source,j+1);
}

int main(){
	cout << "test cases of naive_power" << endl;
	cout << naive_power(2,16) << endl;
	cout << naive_power(3,5) << endl;
	cout << naive_power(3.3,7) << endl;
	cout << "test cases of power" << endl;
	cout << power(2,16) << endl;
	cout << power(3,5) << endl;
	cout << power(3.3,7) << endl;
	//                                        
	cout << "test cases of palindrome1" << endl;
	cout << palindrome1("otto",0,3) << endl;
	cout << palindrome1("Otto",0,3) << endl;
	cout << palindrome1("Madam, I'm Adam.",0,15) << endl;
	cout << "test cases of palindrome2" << endl;
	cout << palindrome2("otto",0,3) << endl;
	cout << palindrome2("Otto",0,3) << endl;
	cout << palindrome2("Madam, I'm Adam.",0,15) << endl;
	cout << "test cases of palindrome3" << endl;
	cout << palindrome3("otto",0,3) << endl;
	cout << palindrome3("Otto",0,3) << endl;
	cout << palindrome3("Madam, I'm Adam.",0,15) << endl;
	cout << "test cases of match_chars" << endl;
	cout << match_chars("abc",0,"It is a bag of cards",0) << endl;
	cout << match_chars("abc",0,"It is a bag of books",0) << endl;
	cout << match_chars("abc",0,"It is a classy bag",0) << endl;
	return 0;
}
