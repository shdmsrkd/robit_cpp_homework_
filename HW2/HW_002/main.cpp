#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;


stack<char> operator_stack;

struct CharIntConstruct
{
    int type;//0 == number , 1 == operator
    int number;
    char symbol;
};

int operator_priority(char operator_input)
{
    if (operator_input == '*' || operator_input == '/' || operator_input == '%')
    {
        return 3;
    }
    if (operator_input == '+' || operator_input == '-')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

CharIntConstruct input_element_set(char token, int element_type)
{
    // 숫자일 경우
    if (element_type == 0)
    {
        CharIntConstruct input_element;
        input_element.type = 0;
        input_element.number = token - '0';

        return input_element;
    }

    // 문자열일 경우
    else
    {
        CharIntConstruct input_element;
        input_element.type = 1;
        input_element.symbol = operator_stack.top();
        operator_stack.pop();

        return input_element;
    }
}



vector<CharIntConstruct> make_postfix(istream& ins)
{
    vector<CharIntConstruct> postfix;
    string input;

    getline(ins, input);


    for(int i = 0; i < input.size(); i++)
    {
        char token = input[i];

        if (isdigit(token))
        {
            postfix.push_back(input_element_set(token, 0));
        }

        else if (token == '(')
        {
            operator_stack.push(token);
        }

        else if (token == ')')
        {
            while(operator_stack.top() != '(')
            {
                postfix.push_back(input_element_set(token, 1));
            }
        }

        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '+')
        {
            while (operator_priority(operator_stack.top() >= operator_priority(token)))
            {
                postfix.push_back(input_element_set(token, 1));
            }

            operator_stack.push(token);
        }
    while(!operator_stack.empty())
    {
        postfix.push_back(input_element_set(token, 1));
    }

    }
    return postfix;
}

bool evaluate_stack(stack<int>& numbers, const char symbol)
{
    if(numbers.size()<2)
    {
        return false;
    }

    int evaluate_num1 = numbers.top();
    numbers.pop();

    int evaluate_num2 = numbers.top();
    numbers.pop();

    float evaluate_result;

    if (symbol == '*')
    {
        evaluate_result = evaluate_num1 * evaluate_num2;
        numbers.push(evaluate_result);
    }
    else if (symbol == '/')
    {
        if (evaluate_num2 == 0)
        {
            cout << "It cannot be divided by zero." << endl;
            return false;
        }
        evaluate_result = evaluate_num1 / evaluate_num2;
        numbers.push(evaluate_result);
    }
    else if (symbol == '+')
    {
        evaluate_result = evaluate_num1 + evaluate_num2;
        numbers.push(evaluate_result);
    }
    else if (symbol == '-')
    {
        evaluate_result = evaluate_num1 - evaluate_num2;
        numbers.push(evaluate_result);
    }
    else
    {
        cout << "Operator error (operator without calculator)" << endl;
        return false;
    }

    return true;
}

int main()
{
    int result = -1;
    int value;
    int evaluate_num1, evaluate_num2;
    float evaluate_result;
    string input;
    stack<int> stack_store_num;


    string mydelimString;
    getline(cin, mydelimString, 'a');
    cin.ignore();
    cout << mydelimString << endl;
    return 0;

    //        result = evaluate_postfix(make_postfix(cin));
    //        cout << "result : " << result << endl;

}
