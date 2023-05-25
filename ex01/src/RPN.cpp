#include "RPN.hpp"

// does not handle: multiple ||| / chars in the digit input
// if | but no value: you get nothing

RPN::RPN()
{
    std::cout << "Basic contructor called" << std::endl;
}

RPN::~RPN()
{
    std::cout << "Destructor called " << std::endl;
}

RPN::RPN(const RPN &copy)
{
    std::cout << "Copy constructor called " << std::endl;

    *this = copy;
}

RPN& RPN::operator=(const RPN & other)
{
    std::cout << "Ass operator overload called " << std::endl;

	if (this == &other)
		return *this;
    return *this;
}


void    RPN::executeExpression(char *expression)
{
    std::stack<int>     stack;
    std::string         input;
    int                 digit;
    // char                signs;

    // Using std::istringstream to parse input 
    std::stringstream ss(expression);

    while (ss >> input)
    {
        if (input == "+" || input == "-" || input == "*" || input == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Not enough numbers in the stack " << std::endl;
                exit(1);
            }

            // Store and pop integers used for calculation
            int firstInt = stack.top();
            stack.pop();
            int secondInt = stack.top();
            stack.pop();

            // Perform calculations on the stack
            if (input == "+")
                stack.push(firstInt + secondInt);
            else if (input == "-")
                stack.push(secondInt - firstInt);
            else if (input == "*")
                stack.push(firstInt * secondInt);
            else if (input == "/")
                stack.push(firstInt / secondInt);

        }
        // Handle brackets
        else if (input == "(" || input == ")")
        {
            std::cerr << "Error: Bad input " << std::endl;
            exit(1);
        }
        // Handle digits
        else if (isdigit(input[0]))
        {
            digit = atoi(input.c_str());
            stack.push(digit);
        }
        else
        {
            std::cerr << "Error: Not an int or + " << std::endl;
            exit(1);
        }

        // Skip whitespaces
        ss >> std::ws;
    }

    // Print the top of the stack:
    std::cout << stack.top() << std::endl;
}
