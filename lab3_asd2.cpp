#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "my_stack.h"

bool IsOperator(char& c)
{
	return (c == '+' ||
		c == '-' ||
		c == '*' ||
		c == '^');
}

int Operation(char operation, int o1, int o2)
{
	if (operation == '+')
		return o1 + o2;

	else if (operation == '-')
		return o1 - o2;

	else if (operation == '*')
		return o1 * o2;

	else if (operation == '^')
		return (int)pow(o1, o2);

	else {
		std::cerr << "Can't be calculated!"; exit(1);
	}
}

int count_expression(std::string expression) {

	Stack my_stack;

	for (int i = 0, j = expression.size() - 1; i < expression.size(); i++, j--)
	{
		if (expression[j] == ' ')
			continue;
		if (IsOperator(expression[j])) {
			int leftOperand = my_stack.pop();
			int rightOperand = my_stack.pop();
			int result = Operation(expression[j], leftOperand , rightOperand);
			my_stack.push(result);
		}
		else if (isdigit(expression[j])) {
			int operand = 0;
			int p = 1;
			while (i >= 0 && isdigit(expression[j])) {
				operand += (int(expression[j]) - 48) * p;
				p *= 10;
				++i;
				--j;
			}
			--i;
			++j;
			my_stack.push(operand);
		}
		else {
			std::cout << "Incorrect input" << std::endl;
			exit(1);
		}
	}
	return my_stack.pop();
}

int main()
{
    std::ifstream fin;
    fin.open("prefix.txt");
    if (fin.is_open()) {
		std::string expression;
		while (std::getline(fin, expression)) {

			int result = count_expression(expression);
				std::cout << "Expression : " << expression << "\nResult : " << result << std::endl;
		}

    }
    return 0;
}