using System;
using System.Collections.Generic;

class InfixToPostfix
{
    static int Precedence(char op)
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    static string Convert(string infix)
    {
        Stack<char> stack = new Stack<char>();
        string output = "";

        foreach (char ch in infix)
        {
            if (char.IsLetterOrDigit(ch)) // Operand
            {
                output += ch;
            }
            else if (ch == '(')
            {
                stack.Push(ch);
            }
            else if (ch == ')')
            {
                while (stack.Count > 0 && stack.Peek() != '(')
                {
                    output += stack.Pop();
                }
                stack.Pop(); // Remove '('
            }
            else // Operator
            {
                while (stack.Count > 0 && Precedence(stack.Peek()) >= Precedence(ch))
                {
                    output += stack.Pop();
                }
                stack.Push(ch);
            }
        }

        while (stack.Count > 0)
        {
            output += stack.Pop();
        }

        return output;
    }

    static void Main()
    {
        string infix = Console.ReadLine();
        string postfix = Convert(infix);
        Console.WriteLine(postfix);
    }
}
