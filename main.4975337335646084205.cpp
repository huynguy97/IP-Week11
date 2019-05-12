//                                     
//                                 
//                                 

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

long power(int x, int n) {
	//             
	assert(n >= 0);

	//              
	//                               
	//                   
	//                                     

	if (n == 0) {
		return 1;
	}
	else {
		return power(x, n - 1)*x;
	}
}

//                                                         
long power2(long s, int n) {
	//             
	assert(n >= 0);

	//              
	//                               
	//                   
	//                                                                                                            

	// 	           
	int p = 2;
	while (n%p == 0) {
		cout << "p == " << p << '\n';
		s = power(s, p);
		n /= p;
	}

	p += 1;

	//                                                  
	//                                            
	while (n > 1) {
		while (n%p == 0) {
			cout << "p == " << p << '\n';
			s = power(s, p);
			n /= p;
		}
		if (p % 6 == 1)
			p += 4;
		else
			p += 2;
	}

	return s;
}

bool is_punctuation(char c) {
	//             
	assert(true);

	//              
	//                                                                  
	//                        
	if (c == ' ' ||
		c == '.' ||
		c == ',' ||
		c == ':' ||
		c == ';' ||
		c == '\\' ||
		c == '!' ||
		c == '?' ||
		c == '-')
		return true;
	return false;
}

bool palindrome1(string text, int i, int j) {
	//             
	assert(true);

	//              
	//                                   
	//                                        
	//                                                    

	if (i == j - 1 || i == j)
		return true;
	else if (text[i] != text[j])
		return false;

	palindrome1(text, i + 1, j - 1);
}

bool palindrome2(string text, int i, int j) {
	//             
	assert(true);

	//              
	//                                                        
	//                                     

	for (int k = 0; k <= j; k++) {
		if (int(text[k]) >= 65 && int(text[k]) <= 90)
			text[k] = char(int(text[k]) + 32);
	}
	return palindrome1(text, i, j);
}

bool palindrome3(string text, int i, int j) {
	//             
	assert(true);

	//              
	//                                                     
	//                                                       
	//          

	if (i == j - 1 || i == j)
		return true;
	if (is_punctuation(text[i]))
		i++;
	else if (is_punctuation(text[j]))
		j--;
	else {
		if (int(text[i]) >= 65 && int(text[i]) <= 90)
			text[i] = char(int(text[i]) + 32);
		if (int(text[j]) >= 65 && int(text[j]) <= 90)
			text[j] = char(int(text[j]) + 32);

		if (text[i] == text[j])
			palindrome3(text, i + 1, j - 1);
		else
			return false;
	}
}

struct potential_character {
	char character;
	int pos;
};

void add_if_not_in(potential_character pc, vector<potential_character>& founds) {
	//             
	assert(true);
	//               
	//                                                                             
	bool found = false;
	for (int i = 0; i < founds.size(); i++) {
		if (pc.character == founds[i].character) {
			found = true;
		}
	}
	if (!found) founds.push_back(pc);
}

bool match_chars(string chars, int i, string source, int j) {
	//            
	assert(true);
	//              
	//                                                                          

	vector<potential_character> foundornot;
	int tempj = j;
	int tempi = i;

	for (int counter = i; counter < chars.length(); counter++) {
		while (tempj < source.length() && chars[counter] != source[tempi]) {
			tempj++;
			tempi++;
		}
		//                                                                
		if (tempj == source.length()) return false;
		else {
			potential_character pc = { chars[counter],tempj };
			add_if_not_in(pc, foundornot);
		}
	}

	//                                                  
	for (int counter = 0; counter < foundornot.size() - 1; counter++) {
		if (foundornot.size() >= 2) {
			if (foundornot[counter].pos > foundornot[counter + 1].pos) {
				return false;
			}
		}
	}
	//                                        
	if (i == chars.length() - 1) return true;
	else {
		return match_chars(chars, i+1, source, j);
	}

}

int main() {

	

	return 0;
}

