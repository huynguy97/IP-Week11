#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;
double power(double base,int exponent){
    //             
    assert(exponent>=0);
    //                                                                          
    if(exponent==0){return 1;}
    else{
        return(base*power(base,exponent-1));
    }
}
double power2(double base,int exponent){
    //             
    assert(exponent>=0);
    //                                                                          
    //                                                         
    if(exponent==0){return 1;}
    else if(exponent%2==0){
        const double t=power(base,exponent/2);
        return(t*t);
    }
    else{
        const double t=power(base,exponent/2);
        return(base*t*t);
    }
}
int size(string s){
    return(static_cast<int>(s.length()));
}

bool palindrome1(string text, int i, int j){
    //             
    assert(i>-1 && j>=1 && i<size(text)&& j<size(text) &&i<=j);
    //                                                                                       
    if(i==j){return true;}
    if(j-1==i){
        //                                                                            
        return(text[j]==text[i]);
    }
    return(text[j]==text[i] && palindrome1(text,i+1,j-1));
}
bool no_case_equal(char a, char b){
    //             
    assert(true);
    //                                                                                
    if(a==b){
        return true;
    }
    else if('a'<=a&&a<='z' && b-a=='A'-'a'){
        //                                           
        return true;
    }
    else if('A'<=a&&a<='Z' && b-a=='a'-'A'){
        //                                          
        return true;
    }
    else{
        return false;
    }
}

bool palindrome2(string text, int i, int j){
    //             
    assert(i>-1 && j>=1 && i<size(text)&& j<size(text) &&i<=j);
    //                                                                                                      
    if(no_case_equal(i,j)){return true;}
    if(j==i+1){
        //                                                                            
        return(no_case_equal(text[j],text[i]));
    }
    return(no_case_equal(text[j],text[i]) && palindrome2(text,i+1,j-1));
}

bool is_space_punctuation(char c){
    //             
    assert(true);
    //                                                                                            
    return(c==' '||c=='.'||c==','||c==':'||c==';'||c=='\''||c=='!'||c=='?'||c=='-');
}

bool palindrome3(string text, int i, int j){
    //             
    assert(i>-1 && j>=1 && i<size(text)&& j<size(text) &&i<=j);
    //                                                                                       
    //                                    
    while(is_space_punctuation(text[i])){
        i++;
    }
    while(is_space_punctuation(text[j])){
        j--;
    }
    if(no_case_equal(i,j)){return true;}
    if(j==i+1){
        //                                                                            
        return(no_case_equal(text[j],text[i]));
    }
    return(no_case_equal(text[j],text[i]) && palindrome3(text,i+1,j-1));
}

bool match_chars(string chars, int i, string source, int j){
    //             
    assert(i>=0 && j>=0 && i<=size(chars) && j<=size(source));
    //                                                                  
    //                                                                 
    if(size(chars)==i){
        //                                       
        return true;
    }
    if(size(source)==j){
        //                                                                               
        //                                             
        return false;
    }
    if(chars[i]==source[j]){
        //                                                                          
        return(match_chars(chars,i+1,source,j+1));
    }else{
        //                                                                                       
        return(match_chars(chars,i,source,j+1));
    }
}
main(){
    //                                                                                                         
    //                                  
    cout<<"Both power algorithms, first 1.1, then 1.2:"<<endl;
    cout<<"4^5\t"<<power(4,5)<<",\t"<<power2(4,5)<<endl;
    cout<<"1^5\t"<<power(1,5)<<",\t"<<power2(1,5)<<endl;
    cout<<"2.5^3\t"<<power(2.5,5)<<",\t"<<power2(2.5,5)<<endl;
    cout<<"-3.1^9\t"<<power(-3.1,9)<<",\t"<<power2(-3.1,9)<<endl;
    cout<<"The three test cases from Part 2, for each function:"<<endl;
    cout<<palindrome1("otto",0,3)<<",\t"<<palindrome1("Otto",0,3)<<",\t"<<palindrome1("Madam, I'm Adam.",0,15)<<endl;
    cout<<palindrome2("otto",0,3)<<",\t"<<palindrome2("Otto",0,3)<<",\t"<<palindrome2("Madam, I'm Adam.",0,15)<<endl;
    cout<<palindrome3("otto",0,3)<<",\t"<<palindrome3("Otto",0,3)<<",\t"<<palindrome3("Madam, I'm Adam.",0,15)<<endl;
    cout<<"The three test cases from part 3: "<<endl;
    cout<<match_chars("abc",0,"It is a bag of cards",0)<<",\t";
    cout<<match_chars("abc",0,"It is a bag of books",0)<<",\t";
    cout<<match_chars("abc",0,"It is a classy bag",0)<<endl;
    return 0;
}

