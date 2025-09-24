#include "RPN.hpp"

int all_digits_or_operators(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ' '))
            return std::cerr << ERR_CHAR << std::endl, 0;
        i++;
    }
    return 1;
}

int check_space(char *str)
{
    int i = 0;
    if (str[strlen(str) - 1] == ' ')
        return std::cerr << ERR_SPACE << std::endl, 0;
    while (str[i])
    {
        if (i % 2 == 0 && str[i] == ' ')
                return std::cerr << ERR_SPACE << std::endl, 0;
        if (i % 2 == 1 && str[i] != ' ')
        {
                if (str[i] >= '0' && str[i] <= '9')
                        std::cerr << ERR_NUM << std::endl;
                else
                        std::cerr << ERR_POLISH << std::endl;
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
                return std::cerr << ERR_POLISH << std::endl, 0;
        while (str[i])
        {
                if (str[i] >= '0' && str[i] <= '9')
                        num++;
                if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
                        ope++;
                i++;
        }
        if (ope != num - 1)
                return std::cerr << ERR_POLISH << std::endl, 0;
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
int ope(std::stack<int>& stack, char str, int result)
{
        int num1;
        int num2;
        int num3;

        num2 = stack.top();
        stack.pop();
        if (stack.empty())
                throw std::runtime_error(ERR_POLISH);
        num1 = stack.top();
        stack.pop();
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
                        if (num2 == 0)
                        {
                                throw std::runtime_error("Division par zero");
                        }        
                        num3 = num1 / num2;
                break;
                default:
                std::cerr << ERR_CHAR << std::endl;
                break;
        }
        stack.push(num3);
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
                ope(stack, str[0], result);
                str++;
        }
        result = stack.top();
        stack.pop();
        return result;
}