#include <iostream>
#include <cassert>

using namespace std;

//                          
//                      

//                      
double power_naive (double x, int n);
double power_efficient (double base, int power);
double power_efficient_1 (double base, int power);

//                     

void print_all_power_functions (double& x, int& n)
{

    cout << "Naive implementation: " << endl;
    power_naive(x,n);
    cout << "Efficient implementation: " << endl;
    power_efficient(x, n);
    cout << "Efficient_1 implementation: " << endl;
    power_efficient_1(x, n);
}
void ask_user (double x, int n)
{
    cout << "Enter the base: " << endl;
    cin >> x;
    cout << "Enter the power: " << endl;
    cin >> n;
    print_all_power_functions(x, n);
    return;
}

//       

//                                                                                         
double power_naive (double base, int power)
{
    //              
    assert(power >= 0);
    //                                           
    //                
    if ( power == 0)
    {
        cout << base << " to the power of " << power << " is: " << 1 << endl;
        return 1;
    }
    else
    {
        double result = base*power_naive(base, power-1);
        cout << base << " to the power of " << power << " is: " << result << endl;
        return result;
    }

}

//                                                    
double power_efficient (double base, int power)
{
     //              
    assert(power >= 0);
    //                                           
    //                
    if ( power == 0)
    {
        cout << base << " to the power of 1 " << power << " is: " << 1 << endl;
        return 1;
    }
    if (power % 2 ==  0)
    {
        if (power == 2)
        {
            double result = base * base;
            cout << base << " to the power of 2 " << power << " is: " << result << endl;
            return result;
        }
        else
        {
            double result = power_efficient(power_efficient(base, power/2), 2) ;
            cout << base << " to the power of 3 " << power << " is: " << result << endl;
            return result;
        }

    }
    else
    {
        double result = base*power_efficient(base, power-1);
        cout << base << " to the power of 4 " << power << " is: " << result << endl;
        return result;
    }

}
//                                                    
double power_efficient_1 (double base, int power)
{
    //              
    assert(power >= 0);
    //                                           
    //                
    if ( power == 0)
    if ( power == 0)
    {
        cout << base << " to the power of " << power << " is: " << 1 << endl;
        return 1;
    }
    if (power % 2 ==  0)
    {
        double a = power_efficient_1( base, power/2);
        double result = a * a;
        cout << base << " to the power of " << power << " is: " << result << endl;
        return result;
    }
    else
    {
        double result = base*power_efficient_1(base, power-1);
        cout << base << " to the power of " << power << " is: " << result << endl;
        return result;
    }

}

//        

bool palindrome1_test (string text, int i, int j)
{
       //              
       assert ( i >= 0 );
       //               
       //                                                                                      
       //                

       if ( i >= j)
       {
           cout << "True0" << endl;
           return true;
       }

       if ( text[i] != text [j])
       {
           cout << "False" << endl;
           return false;
       }
       else
       {
            cout << "Recursion" << endl;
            return palindrome1_test(text, i+1, j-1);
       }

}

bool palindrome1_case_sensitive (string& text, int i, int j)
{
       //              
       assert ( i >= 0 );
       //               
       //                                                                                      
       //                

       char a = text[i];
       char b = text[j];
       int diff = 32;

       if ( i >= j)
       {
           cout << "True0" << endl;
           return true;
       }

       if ( a !=  b && (a + diff) != b && a != (b + diff))
       {
           cout << "False" << endl;
           return false;
       }

       else
       {
            cout << "Recursion" << endl;
            return palindrome1_case_sensitive(text, i+1, j-1);
       }

}
bool palindrome1_case_sensitive_1 (string& text, int i, int j)
{
       //              
       assert ( i >= 0 );
       //               
       //                                                                                      
       //                

       char a = text[i];
       char b = text[j];
       int diff = 32;

       if ( i >= j)
       {
           cout << "True0" << endl;
           return true;
       }

       if ( (a > 122 || a < 65 ))
       {
           cout << "This is i: " << i << endl;
           cout << "Recursion 1" << endl;
           return palindrome1_case_sensitive_1(text, i+1, j);
       }
       else if ( (b > 122 || b < 65 ))
       {
           cout << "This is j: " << j << endl;
           cout << "Recursion 2" << endl;
           return palindrome1_case_sensitive_1(text, i, j-1);
       }

       else if ( a !=  b && (a + diff) != b && a != (b + diff))
       {
           cout << "False" << endl;
           return false;
       }
       else
       {
            cout << "Recursion 3" << endl;
            return palindrome1_case_sensitive_1(text, i+1, j-1);
       }

}

bool match_chars (string chars, int i, string source, int j)
{
        //              
        assert(i >=0 && j >= 0 && chars.length() >= 0 && source.length() >= 0 );
        //               
        //                                                                                                                                  
        //                
        char a = chars[i];
        char a1 = chars [chars.length()-1];
        char b = source[j];
        char b1 = source [source.length()-1];

        if ( i >= chars.length())
        {
            cout << "True" << endl;
            return true;
        }
        else if ( j >= source.length())
        {
            cout << "True" << endl;
            return false;
        }
        else if (a == b )
        {
            cout << "This is 2" << endl;
            return match_chars(chars, i+1, source, j+1);
        }

        else
        {
            cout << "This is 1" << endl;
            return match_chars(chars, i, source, j+1);
        }

}

int main()
{
    string sourc = "It is a bag of cards";
    string chars = "abcz";
    int i ;
    int j ;
    //                                
    //                                         
    ask_user(i, j);

    return 0;
}

