/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;

int main()
{
    double n1, n2, res;
    char operation;
    bool flag = true;
    
    
    std::cout << "Welcome to Srijith's Calculator!\n" << endl;
    
    do{
        
        cout << "Enter your first number for the calculation" << endl;
        while (!(cin >> n1)){
            cout << "Please enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Enter your second number for the calculation" << endl;
        while (!(cin >> n2)){
            cout << "Please enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Enter the operation you'd like between the numbers (+/-) or q to Quit" << endl;
        cin >> operation;
        
        switch(operation){
            
            case '+':{
                res = n1+n2;
                cout << "The result of your operation between the two numbers is: " << res << endl << endl;
                break;
            }
            
            case '-':{
                res = n1-n2;
                cout << "The result of your operation between the two numbers is: " << res << endl << endl;
                break;
            }
            
            case 'q':{
                flag = false;
                cout << "\nYou have quit Srijith's calculator." << endl;
                break;
            }
            
            case 'Q':{
                flag = false;
                cout << "\nYou have quit Srijith's calculator." << endl;
                break;
            }
            
            default:
                cout << "Please select a valid operation" << endl;
                continue;
            
            
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while(flag);

    return 0;
}