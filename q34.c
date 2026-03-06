using System;

class Node
{
    public int Data;
    public Node Next;
    public Node(int data)
    {
        Data = data;
        Next = null;
    }
}

class Stack
{
    private Node top;

    public Stack()
    {
        top = null;
    }

    public void Push(int data)
    {
        Node newNode = new Node(data);
        newNode.Next = top;
        top = newNode;
    }

    public int Pop()
    {
        if (top == null)
        {
            throw new InvalidOperationException("Stack Underflow");
        }
        int value = top.Data;
        top = top.Next;
        return value;
    }

    public bool IsEmpty()
    {
        return top == null;
    }

    public int Peek()
    {
        if (top == null) throw new InvalidOperationException("Stack Empty");
        return top.Data;
    }
}

class PostfixEvaluator
{
    public static int Evaluate(string expression)
    {
        Stack stack = new Stack();
        string[] tokens = expression.Split(' ');

        foreach (string token in tokens)
        {
            if (int.TryParse(token, out int num))
            {
                stack.Push(num);
            }
            else
            {
                int val2 = stack.Pop();
                int val1 = stack.Pop();

                switch (token)
                {
                    case "+": stack.Push(val1 + val2); break;
                    case "-": stack.Push(val1 - val2); break;
                    case "*": stack.Push(val1 * val2); break;
                    case "/": stack.Push(val1 / val2); break;
                    default: throw new ArgumentException("Invalid operator");
                }
            }
        }

        return stack.Peek();
    }
}

class Program
{
    static void Main()
    {
        string expr = "2 3 1 * + 9 -";
        Console.WriteLine("Postfix Expression: " + expr);
        int result = PostfixEvaluator.Evaluate(expr);
        Console.WriteLine("Result: " + result);
    }
}
