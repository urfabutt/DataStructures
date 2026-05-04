#include<iostream>
using namespace std;
#include<cstring>
#include<string>
#include<algorithm>
const int MAX_ITEMS = 100;

class FullStack {};
class EmptyStack {};

class StackType
{
private:
    int top;
    string arr[MAX_ITEMS];
public:
    StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(string);
    void Pop();
    string Top() const;
};

StackType::StackType()
{
    top = -1;
}
bool StackType::IsFull() const
{
    return (top == MAX_ITEMS - 1);
}
bool StackType::IsEmpty() const
{
    return (top == -1);
}
void StackType::Push(string item)
{
    if (IsFull())
        throw FullStack();
    top++;
    arr[top] = item;
}
void StackType::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    top--;
}
string StackType::Top() const
{
    if (IsEmpty())
        throw EmptyStack();
    return arr[top];
}

string ConvPost(string infix)
{
    string postfix = "";
    StackType obj;

    for (char c : infix)
    {
        if (isalpha(c) || isdigit(c))
        {
            prefix = prefix + c;
        }
        else if (c == '(')
        {
            obj.Push(string(1, c));
        }
        else if (c == ')')
        {
            while (!obj.IsEmpty() && obj.Top() != "(")
            {
                postfix = postfix + obj.Top();
                obj.Pop();
            }
            if (!obj.IsEmpty() && obj.Top() == "(")
                obj.Pop();
        }
        else if (!obj.IsEmpty() && obj.Top() == "^" && c == '^')
        {
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && (obj.Top() == "^") && (c == '*' || c == '/' || c == '+' || c == '-'))
        {
            postfix = postfix + obj.Top();
            obj.Pop();
            if (obj.Top() != "(")
            {
                postfix = postfix + obj.Top();
                obj.Pop();
            }
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && ((obj.Top() == "*" || obj.Top() == "/") && (c == '*' || c == '/')))
        {
            postfix = postfix + obj.Top();
            obj.Pop();
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && ((obj.Top() == "*" || obj.Top() == "/") && (c == '+' || c == '-')))
        {
            postfix = postfix + obj.Top();
            obj.Pop();
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && ((obj.Top() == "+" || obj.Top() == "-") && (c == '*' || c == '/')))
        {
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && ((obj.Top() == "+" || obj.Top() == "-") && (c == '+' || c == '-')))
        {
            postfix = postfix + obj.Top();
            obj.Pop();
            obj.Push(string(1, c));
        }
    }

    while (!obj.IsEmpty() && obj.Top() != "(")
    {
        postfix = postfix + obj.Top();
        obj.Pop();
    }

    return postfix;
}

string ConvPre(string pre)
{
    string prefix = "";
    string infix = pre;
    reverse(infix.begin(), infix.end());
    for (char& c : infix)
    {
        if (c == '(')
        {
            c = ')';
        }
        else if (c == ')')
        {
            c = '(';
        }
    }
    StackType obj;
   
    for (char c : infix)
    {
        if (isalpha(c) || isdigit(c)) 
        {
            prefix = prefix + c;
        }
        else if (c == '(' || (!obj.IsEmpty() && c == '^' && obj.Top() != "^"))
        {
            obj.Push(string(1, c));
        }
        else if (c == ')')
        {
            while (!obj.IsEmpty() && obj.Top() != "(")
            {
                prefix = prefix + obj.Top();
                obj.Pop();
            }
            if (!obj.IsEmpty() && obj.Top() == "(")
                obj.Pop();
        }
        else if (!obj.IsEmpty() && obj.Top() == "^" && c == '^')
        {
            prefix = prefix + obj.Top();
            obj.Pop();
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && (obj.Top() == string(1, c)))
        {
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && ((obj.Top() == "+" && c == '-') || (obj.Top() == "-" && c == '+')))
        {
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && ((obj.Top() == "*" && c == '/') || (obj.Top() == "/" && c == '*')))
        {
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && obj.Top() == "^" && (c == '*' || c == '/' || c == '+' || c == '-'))
        {
            prefix = prefix + obj.Top(); 
            obj.Pop();
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && (obj.Top() == "*" || obj.Top() == "/") && (c == '+' || c == '-'))
        {
            prefix = prefix + obj.Top(); 
            obj.Pop();
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && (obj.Top() == "+" || obj.Top() == "-") && (c == '+' || c == '-'))
        {
            prefix = prefix + obj.Top(); 
            obj.Pop();
            obj.Push(string(1, c));
        }
        else if (!obj.IsEmpty() && (obj.Top() == "*" || obj.Top() == "/") && (c == '*' || c == '/'))
        {
            prefix = prefix + obj.Top(); 
            obj.Pop();
            obj.Push(string(1, c));
        }
    }
    while (!obj.IsEmpty() && obj.Top() != "(") 
    {
        prefix = prefix + obj.Top();
        obj.Pop();
    }
    string result = prefix;
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string in;
    do
    {
        string infix;
        cout << "Enter the infix: " << endl;
        getline(cin, infix);
        string postfix = ConvPost(infix);
        cout << "The postfix is " << postfix << endl;
        string prefix = ConvPre(infix);
        cout << "The prefix is " << prefix << endl;
        cout << "Enter 0 if you want to exit: " << endl;
        getline(cin, in);
    } while (in != "0");
    return 0;
}
