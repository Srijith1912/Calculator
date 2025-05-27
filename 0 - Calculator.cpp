#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int order(char op){
    if(op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main(){
    
    string expr;
    cout << "Enter expression (eg: 3 + 5 * 2 =): " << endl;
    getline(cin, expr);
    stack<double> numbers;
    stack<char> operators;
    stringstream ss(expr);
    string token;
    
    while (ss >> token){
        if (token == "=") break;
        if (token != "+" && token != "-" && token != "*" && token != "/"){
            numbers.push(stod(token));
        }
        else{
            while(!operators.empty() && order(operators.top()) >= order(token[0])){
                double b = numbers.top();
                numbers.pop();
                double a = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();
            
                if (op == '+') numbers.push(a+b);
                else if (op == '-') numbers.push(a-b);
                else if (op == '*') numbers.push(a*b);
                
                else if (op == '/') {
                    if (b == 0) { 
                        cout << "Error: Division by zero!" << endl; 
                        return 1; 
                    }
                    else numbers.push(a / b);
                    }
                    
                }
            
            operators.push(token[0]);
        }
    }
    
    while(!operators.empty()){
        double b = numbers.top();
        numbers.pop();
        double a = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();
        
        if (op == '+') numbers.push(a+b);
        else if (op == '-') numbers.push(a-b);
        else if (op == '*') numbers.push(a*b);
        
        else if (op == '/') {
            if (b == 0) { 
                cout << "Error: Division by zero!" << endl; 
                return 1; 
            }
            else numbers.push(a / b);
            }

    }
    
    cout << "Result: " << numbers.top() << endl;
    return 0;
    
}
