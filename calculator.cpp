/*
 * Author: Percy George Brown
 * The program serves as a terminal based calculator
 * Created on 05 April 2020, 09:03
 */

#include <iostream>            //including necessary header files
#include <queue>
#include <string>
#include <sstream>
using namespace std;             //using functions from std, hence no need to explicitly to call the namespace to access them.

/*
*This method takes three parameters; operator choice chosen, initial and current number.
*Computes the operation based on the number selected by the user in the main method.
*Returns the result as an integer
*/

int assignoperators(int choice, int number1, int number2){
    int ans;
    switch(choice){                    //1 = +, 2 = -, 3 = *, 4 = /.
    case 1:
    ans = number1+number2;
    break;
    case 2:
    ans = number1-number2;
    break;
    case 3:
    ans = number1*number2;
    break;
    case 4:
    ans = number1/number2;
    break;
    }
    return ans;

}

/*
*This method assigns the operation numbers to their respective operations (1 = +, 2 = -, 3 = *, 4 = /.)
*The operation signs would enable us to print the total expression after putting all inputs in a queue.
*Returns each sign as a string
*/

string assign(int token){
    string sign;
    switch(token){         //1 = +, 2 = -, 3 = *, 4 = /.
        case 1:
        sign = "+";
        break;
        case 2:
        sign = "-";
        break;
        case 3:
        sign = "*";
        break;
        case 4:
        sign = "/";
        break;
    }
    return sign;
}

/*
*This method performs the operations between the numbers.
* Once the user has entered two or more numbers, they have the option to compute results or to continue entering another operation.
*Stores all inputs into a queue. It however stores the signs of the operation choices(from sign(int token)) instead of the numbers.
*If the result option is selected, the calculator prints the total expression from a queue together with the final result.
*/

void calculator(){
    queue<string> expression;          //a queue of strings, empty now.
    int result = 0;                     //result is 0 initally
    int operation = 0;                 //operation choice is 0 initially
    int first_number = 0;             //first number 0 initially
    int latest_number = 0;           //recent number 0 initially
    string message = "Select Operation - 1. Addition, 2. Subtraction, 3. Multiplication, 4. Division";           //mesage to choose operation from
    cout << "Enter number: " << endl;           //asks for first number
    cin >> first_number;
    stringstream fnumber;
    fnumber << first_number;
    expression.push(fnumber.str());             //number converted to string and pushed into the queue
    result = first_number;                      // first number is set as current result
    cout << message << ": " << endl;            //asks for operation choice
    cin >> operation;
    expression.push(assign(operation));         //pushes the corresponding symbol form into the queue
    cout << "Enter number: " << endl;           //asks for second number
    cin >> latest_number;
    stringstream lnumber;
    lnumber << latest_number;
    expression.push(lnumber.str());            //converts to string and pushes to queue
    result = assignoperators(operation, result, latest_number);     //current result is computered using the first and recent number
    cout << message << ", 5. Result" << endl;     //now, the user has the option to choose results, end number inputs and see final reult.
    cin >> operation;
    while(operation !=5){                    //while the operation choice is not 5(Results):
        expression.push(assign(operation));    //push the corresponding symbol into queue
        cout << "Enter number: " << endl;     //asks for next number
        cin >> latest_number;
        stringstream lnumber;
        lnumber << latest_number;
        expression.push(lnumber.str());       //current number pushed into queue
        result = assignoperators(operation, result, latest_number);       //current result obtained from past result and current number
        cout << message << ", 5. Result" << endl;         //displays operation choices again, until user chooses 5.
        cin >> operation;
    }
    string inputs = "";                   //if user selects the results option
    while(!expression.empty()){          //while queue is not empty

        inputs += expression.front();    //print the first item pushed
        expression.pop();               //remove that item to make the first item as the next.
    }
    cout << inputs << "=" << result;       //displays whole expression with result.

}

/*
*Main method
*Calls the calculator function to execute
*Returns 0 to traditionally signify program success
*/

int main(){
    calculator();
    return 0;
}


