#include <iostream>
#include <cassert>

using namespace std;

//                        

double power1 (double x, double n)
{
//             
    assert (n >= 0);
//              
//                            
//                                           

//                                        
//             
//                                       
//             
    if (n == 0) {return 1;}
    else if (n > 0) {return x * power1(x,n-1);}
}

//                                                   
// 
//                           
//                                             
// 

double power2 (double x, int n)
{
//             
    assert (n >= 0);
//              
//                             
//                                                
    if (n == 0)
        return 1;
    else if (n%2 == 0)
    {
        return power2(x, n/2)*power2(x, n/2);
        cout << power2(x, n/2) << endl;
    }
    else
    {
//                                                  
        return power2(x, n-1);
    }
}
//                                                        
// 
//                           
//                                                                     
// 

bool palindrome1 (string text, int fiLttr, int liLttr) //                                                                                          
{
//                                         
//                           

//             
    assert (fiLttr >= 0 && liLttr >= 0 && fiLttr < liLttr )
//              
//                                                                   
//                                              
//                                                                                           
//                                                                  
//                                              
    if (text[fiLttr] == text[liLttr])
    {
        if (fiLttr == liLttr || fiLttr == liLttr-1)
        {
          return true;
        }
        else {return palindrome1 (text, fiLttr+1, liLttr-1);}
    }
    else {return false;}
}

bool palindrome2 (string text, int fiLttr, int liLttr)
//             
    assert (fiLttr >= 0 && liLttr >= 0 && fiLttr < liLttr )
//              
//                                                                   
//                                                                                                  
//                                                                                           
//                                                                                                                      
//                                                                                                   
{

    if (text[fiLttr] == text[liLttr] || text[fiLttr] == text[liLttr] + 32 || text[fiLttr] + 32 == text[liLttr])
    {
        if (fiLttr == liLttr || fiLttr == liLttr-1)
        {
          return true;
        }
        else {return palindrome2 (text, fiLttr+1, liLttr-1);}
    }
    else {return false;}
}

//                                                 
// 
//                                                 
//     
//                                                                                                                   
//         
//                                                       
//             
//                            
//             
//                                                                 
//         
//                        
//     
//                                
//     
//                                                   
//     
//                                
//     
//                                                    
//     
// 

palindrome3 (string text, int fiLttr, int liLttr)
{
//             
    assert (fiLttr >= 0 && liLttr >= 0 && fiLttr < liLttr )
//              
//                                                                   
//                                                                                                                                   
//                                                                                                                                        
//                                                                                                                                                      
//                                                                                                 
{
    if (fiLttr == liLttr)
    {
        return true;
    }
    if (text [fiLttr] < 65)
    {
        return palindrome3(text, fiLttr+1, liLttr);
    }
    else if (text [liLttr] < 65)
    {
        return palindrome3 (text, fiLttr, liLttr-1);
    }

    if (text[fiLttr] >= 65 && text[liLttr] >= 65)
    {
        if (text[fiLttr] == text[liLttr] || text[fiLttr] == text[liLttr] + 32 || text[fiLttr] + 32 == text[liLttr])
        {
            if (fiLttr == liLttr-1) {return true;} else {return palindrome3 (text, fiLttr+1, liLttr-1);}
        }
    else {return false;}
    }
}

int main()
{
//           
//                      

//           
//                      

//                                                         
//                     
//                                                
//                       

//                     
if (palindrome2("LePpel", 0, 5)) {cout << "true";}
else {cout << "false";}

//                
if (palindrome3 ("lep.pel", 0, 6)){cout << "true";} else {cout << "false";}
    return 0;
}

