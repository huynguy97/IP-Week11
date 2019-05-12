#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                          
//                            
//                          

double power (double x, int n)
{
	//               
	assert (n >= 0);
	//                
	//                                                                      

	if (n == 0) return 1;
	return x * power (x, n - 1);
}

//                                                
double power1 (double x, int n)
{
	//               
	assert (n >= 0);
	//                
	//                                                                                                           

	if (n == 0) return 1;
	else if (n % 2 == 0)
	{
		double p = power1(x, n / 2);
		return p * p;
	}
	else
	{
		return x * power1(x, n - 1);
	}
}

bool palindrome1 (string text, int i, int j)
{
	//               
	assert (i >= 0 && j >= i && j < text.length());
	//                
	//                                                                           

	if (j - i <= 1) return true;
	else if (palindrome1(text, i + 1, j - 1) && text[i] == text[j]) return true;
	return false;
}

bool palindrome2 (string text, int i, int j)
{
	//               
	assert (i >= 0 && j >= i && j < text.length());
	//                
	//                                                                                                     

	if (j - i <= 1) return true;
	else if (palindrome2(text, i + 1, j - 1) && tolower(text[i]) == tolower(text[j])) return true;
	return false;
}

bool palindrome3 (string text, int i, int j)
{
	//               
	assert (i >= 0 && j >= i && j < text.length());
	//                
	//                                                                                                                     

	if (j - i <= 1) return true;
	else if (ispunct(text[i]) || text[i] == ' ') return palindrome3(text, i + 1, j);
	else if (ispunct(text[j]) || text[j] == ' ') return palindrome3(text, i, j - 1);
	else if (palindrome3(text, i + 1, j - 1) && tolower(text[i]) == tolower(text[j])) return true;
	return false;
}

bool match_chars (string chars, int i, string source, int j)
{
	//               
	assert (i >= 0 && j >= 0 && i <= chars.length() && j <= source.length());
	//                
	//                                                                                                                   

	if (chars.length() - i > 0 && source.length() - j == 0) return false;
	else if (chars.length() - i == 0) return true;
	else if (chars[i] == source[j]) return match_chars (chars, i + 1, source, j + 1);
	return match_chars (chars, i, source, j + 1);
}

int main()
{
	cout << "Power 0:" << endl;
	cout << power(4, 8) << endl;
	cout << "Power 1:" << endl;
	cout << power1(4, 8) << endl;
	cout << "Palindrome 1:" << endl;
	cout << palindrome1("lepel", 0, 4) << endl;
	cout << "Palindrome 2:" << endl;
	cout << palindrome2("LepEl", 0, 4) << endl;
	cout << "Palindrome 3:" << endl;
	cout << palindrome3("L.e'P   eL", 0, 9) << endl;
	cout << "Match chars:" << endl;
	cout << match_chars("abc", 0, "It is a bag of cards", 0) << endl;

	return 0;
}

