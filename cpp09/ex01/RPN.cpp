#include "RPN.hpp"


int all_digits_or_operators(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ' '))
            return std::cout << "err char" << std::endl, 0;
        i++;
    }
    return 1;
}

int check_space(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (i % 2 == 0 && str[i] == ' ')
                return std::cout << "error space", 0;
        if (i % 2 == 1 && str[i] != ' ')
        {
                if (str[i] >= '0' && str[i] <= '9')
                        std::cout << "error num" << std::endl;
                else
                        std::cout << "error polish" << std::endl;
                return 0;
        }           
        i++;
    }
    return 1;
}

int check_polish(char* str)
{
        int i = 0;
        int num = 0;
        int ope = 0;
        if (!(str[0] >= '0' && str[0] <= '9') || !(str[2] >= '0' && str[2] <= '9'))
                std::cout << "error polish start" << std::endl;
        while (str[i])
        {
                if (str[i] >= '0' && str[i] <= '9')
                        num++;
                if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
                        ope++;
                i++;
        }
        if (ope != num - 1)
                return std::cout << "ratio ope/num" << std::endl, 0;
        return 1;
}

int check_expression(char* expr)
{
        if (all_digits_or_operators(expr) == 0)
                return 0;
        if (check_space(expr) == 0)
                return 0;
        if (check_polish(expr) == 0)
                return 0;
        return 1;
}

void afficher(std::stack<int>& pile) {
    std::cout << "[";
    bool premier = true;
    while (!pile.empty()) {
        if (!premier) std::cout << ", ";
        std::cout << pile.top();
        pile.pop(); // détruit le sommet
        premier = false;
    }
    std::cout << "]" << std::endl;
}

int ope(std::stack<int>& stack, char str, int result)
{
        int num1;
        int num2;
        int num3;
        bool choice = 0;

        num2 = stack.top();
        stack.pop();
        if (stack.empty())
        {
                num1 = num2;
                num2 = result;
                result = 0;
        }
        else
        {
                num1 = stack.top();
                stack.pop();
                choice = 1;
        }
        switch (str)
        {
                case '+':
                        num3 = num1 + num2;
                break;
                case '-':
                        num3 = num1 - num2;
                break;
                case '*':
                        num3 = num1 * num2;
                break;
                case '/':
                        num3 = num1 / num2;
                break;
                default:
                std::cout << "error" << std::endl;
                break;
        }
        if (choice == 1)
                stack.push(num3);
        else
                result = result + num3;
        std::cout << num1 << str << num2 << " = " << result << std::endl;
        return result;        
}

char* fill_stack(char* str, std::stack<int>& stack)
{
        while (*str && ((*str >= '0' && *str <= '9') || *str == ' '))
        {
                if (*str >= '0' && *str <= '9')
                        stack.push(*str - 48);
                str++;
        }
        
        return str;
}

int calculated(char* str)
{
        std::stack<int> stack;
        int result = 0;
        while (*str != 0)
        {
                str = fill_stack(str, stack);
                //afficher(stack);
                ope(stack, str[0], result);
                str++;
        }
        result = stack.top();
        stack.pop();
        return result;
}
