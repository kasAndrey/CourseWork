#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#define pi 3.14
#define e 2.71
using namespace std;

class Stack_n
{
public:
    Stack_n()
    {
        size = 0;
        head = nullptr;
    }
    ~Stack_n()
    {
        clear();
    }
    void push_back(double data)
    {
        if (!head) head = new Node(data); 
        else
        {
            Node* current = head;
            while (current->next) current = current->next; 
            current->next = new Node(data); 
        }
        size++;
    }
    void push_front(double data)
    {
        if (!head) head = new Node(data); 
        else
        {
            Node* first = new Node(data); 
            first->next = head; 
            head = first; 
        }
        size++;
    }
    void pop_back()
    {
        if (head)
        {
            Node* current = head, * previous = nullptr;
            while (current->next)
            {
                previous = current; 
                current = current->next;
            }
            delete current;
            current = nullptr;
            if (previous) previous->next = current;
            else head = nullptr;
            size--;
        }
    }
    void pop_front()
    {
        if (head)
        {
            Node* current = head->next;
            delete head;
            head = current;
            size--;
        }
    }
    void insert(double data, size_t index)
    {
        if (size >= index + 1)
        {
            Node* current = head;
            if (!index) push_front(data);
            else
            {
                for (size_t i = 1; i < index; i++, current = current->next); 
                Node* new_data = new Node(data); 
                new_data->next = current->next; 
                current->next = new_data;
                size++;
            }
        }
    }
    double get_elem(size_t index)
    {
        if (size >= index + 1)
        {
            Node* current = head;
            for (size_t i = 0; i < index; i++, current = current->next); 
            return current->number; // returns index number
        }
        else
        {
            throw out_of_range("index is entered incorrectly"); // error message
        }
    }
    void remove(size_t index)
    {
        if (size >= index + 1)
        {
            if (index == 0) pop_front(); // delete first element
            else if (index + 1 == size) pop_back(); // delete last element
            else
            {
                Node* current = head, * next;
                for (size_t i = 1; i < index - 1; i++, current = current->next);  // moves the current list to index
                next = current->next;
                current->next = next->next;
                delete next;
                next = nullptr;
                size--;
            }
        }
    }
    size_t get_size()
    {
        return size;
    }

    void clear()
    {
        while (size) pop_front();
    }
    void set(size_t index, double data)
    {
        if (size >= index + 1)
        {
            Node* current = head;
            for (size_t i = 0; i < index; i++, current = current->next); 
            current->number = data;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
    void push_front(Stack_n new_list)
    {
        if (new_list.head)
        {
            Node* current = new_list.head;
            Stack_n main;
            while (current)
            {
                main.push_back(current->number);
                current = current->next;
            }
            current = head;
            while (current)
            {
                main.push_back(current->number);
                current = current->next;
            }
            clear(); 
            head = main.head;
            size = main.size;
            main.size = 0; 
            new_list.size = 0; 
        }
    }
    friend ostream& operator<< (ostream& out, const Stack_n& list)
    {
        Stack_n current;
        current.head = list.head;
        while (current.head)
        {
            out << current.head->number;
            if (current.head->next) out << ',';
            current.head = current.head->next;
        }
        current.size = 0;  
        return out;
    }
private:
    class Node
    {
    public:
        double number;
        class Node* next;
        Node(double data = 0.0, Node* next = nullptr)
        {
            this->next = next;
            this->number = data;
        }
        ~Node() {};
    };
    Node* head;
    size_t size;
};
class Stack_str
{
public:
    Stack_str()
    {
        size = 0;
        head = nullptr;
        last = nullptr;
    }
    ~Stack_str()
    {
        clear();
    }
    void push_back(string new_char)
    {
        if (!head)
        {
            head = new Node(new_char);
            last = head;
        }
        else
        {
            last->next = new Node(new_char);
            last = last->next;
        }
        size++;
    }
    void push_front(string new_char)
    {
        if (!head)
        {
            head = new Node(new_char); 
            last = head;
        }
        else
        {
            Node* first = new Node(new_char);
            first->next = head;
            head = first; 
        }
        size++;
    }
    void pop_back()
    {
        if (head)
        {
            Node* current = head, * previous = nullptr;
            while (current->next)
            {
                previous = current;
                current = current->next; 
            }
            delete current;  
            current = nullptr;
            if (previous)
            {
                previous->next = current;
                last = previous;
            }
            else head = nullptr;
            size--;
        }
    }
    void pop_front()
    {
        if (head)
        {
            Node* current = head->next;
            delete head;
            head = current;
            size--;
        }
    }
    void insert(string new_char, size_t index)
    {
        if (size >= index + 1)
        {
            Node* current = head;
            if (!index) push_front(new_char); 
            else
            {
                for (size_t i = 1; i < index; i++, current = current->next); 
                Node* newelem = new Node(new_char);
                newelem->next = current->next; 
                current->next = newelem;
                size++;
            }
        }
    }
    string get_elem(size_t index)
    {
        if (size > index + 1)
        {
            Node* current = head;
            for (size_t i = 0; i < index; i++, current = current->next); 
            return current->ch; 
        }
        else if (size == index + 1) return last->ch;
        else
        {
            throw out_of_range("index is entered incorrectly"); // error message
        }
    }
    void remove(size_t index)
    {
        if (size >= index + 1)
        {
            if (index == 0) pop_front(); 
            else if (index + 1 == size) pop_back(); 
            else
            {
                Node* current = head, * next;
                for (size_t i = 1; i < index - 1; i++, current = current->next); 
                next = current->next;
                current->next = next->next;
                delete next;
                next = nullptr;
                size--;
            }
        }
    }
    size_t get_size()
    {
        return size;
    }

    void clear()
    {
        while (size) pop_front();
    }

    void set(size_t index, char new_char)
    {
        if (size >= index + 1)
        {
            Node* current = head;
            for (size_t i = 0; i < index; i++, current = current->next); 
            current->ch = new_char;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push_front(Stack_str new_list)
    {
        if (new_list.head)
        {
            Node* current = new_list.head;
            Stack_str main;
            while (current)
            {
                main.push_back(current->ch);
                current = current->next;
            }
            current = head;
            while (current)
            {
                main.push_back(current->ch);
                current = current->next;
            }
            clear();
            head = main.head;
            size = main.size;
            main.size = 0;
            new_list.size = 0; 
        }
    }
    friend ostream& operator<< (ostream& out, const Stack_str& list)
    {
        Stack_str current;
        current.head = list.head;
        while (current.head)
        {
            out << current.head->ch;
            if (current.head->next) out << ' ';
            current.head = current.head->next;
        }
        current.size = 0; 
        return out;
    }
private:
    class Node
    {
    public:
        string ch;
        class Node* next;
        Node(string new_char = nullptr, Node* next = nullptr)
        {
            this->next = next;
            this->ch = new_char;
        }
        ~Node() {};
    };
    Node* head;
    Node* last;
    size_t size;
};


class Calculator
{
public:
    Calculator()
    {
        result = 0;
        math = false;
    }

    Calculator(string arithm)
    {
        result = 0;
        this->arith = arithm;
        math = false;
    }
    bool is_correct()
    {
        int nesting_brackets = 0;
        size_t i = 0;
        bool flag = !arith.empty(); // string validation
        for (i = 0; i < arith.size() && flag; i++) // walks through the line and looks if numbers, functions and signs are entered correctly
        {
            flag = (to_find("cos", i, 3) == i || to_find("sin", i, 3) == i || to_find("ctg", i, 3) == i || to_find("log", i, 3) == i);
            if (flag)
            {
                i += 2;
            }
            else
            {
                flag = (to_find("tg", i, 2) == i || to_find("ln", i, 2) == i || to_find("pi", i, 2) == i);
                if (flag)
                {
                    i++;
                }
                else
                {
                    flag = (to_find("sqrt", i, 4) == i);
                    if (flag)
                    {
                        i += 3;
                    }
                    else
                    {
                        flag = to_find("arccos", i, 6) == i;
                        if (flag)
                        {
                            i += 4;
                        }
                        else
                        {
                            flag = arith[i] != ' ' && (isdigit(arith[i]) || arith[i] == '+' || arith[i] == '-' || arith[i] == '*' || arith[i] == '/' || arith[i] == '^' || arith[i] == ',' || arith[i] == ')' || arith[i] == '(' || arith[i] == 'e');
                        }
                    }
                }
            }
        }
        flag = flag && new_count('(') == new_count(')');
        if (flag)// if there are no extra characters
        {
            for (i = 0; i < arith.size() && flag; i++)
            {
                switch (arith[i])
                {
                case '(':
                    nesting_brackets++;
                    if (i + 1 < arith.size()) flag = (arith[i + 1] != ')');
                    else flag = false;
                    break;
                case ')':
                    nesting_brackets--;
                    if (i > 0) flag = (arith[i - 1] != '(');
                    else flag = false;
                    break;
                }
                flag = flag && !(nesting_brackets < 0);
                if ((arith[i] == 'c' || arith[i] == 's' || arith[i] == 'l') && flag)
                {
                    if (arith[i + 1] == 'n') //ln
                    {
                        if (i + 2 < arith.size()) flag = (arith[i + 2] == '(' || arith[i + 3] == '(');
                        else flag = false;
                        i += 1;
                    }
                    else if (arith[i + 2] == 'n' || arith[i + 2] == 's' || arith[i + 2] == 'g') // if sin cos log
                    {
                        if (i + 3 < arith.size()) flag = (arith[i + 3] == '(');
                        else flag = false;
                        i += 2;
                    }
                    else //sqrt
                    {
                        if (i + 4 < arith.size()) flag = (arith[i + 4] == '(');
                        else flag = false;
                        i += 3;
                    }
                }
                else if ((arith[i] == '+' || arith[i] == '-') && flag)
                {
                    if (i + 1 < arith.size())
                        flag = (isdigit(arith[i + 1]) || arith[i + 1] == '(' || arith[i + 1] == 'c'
                            || arith[i + 1] == 's' || arith[i + 1] == 't' || arith[i + 1] == 'l' || arith[i + 1] == 'a' || arith[i + 1] == 'p'
                            || arith[i + 1] == 'e');
                    else if (i > 0)
                        flag = (isdigit(arith[i - 1]) || arith[i - 1] == ')' || arith[i - 1] == 'i' || arith[i - 1] == 'e'
                            || (arith[i] == '-' && arith[i - 1] == '('));
                    else if (i == 0 && arith[i] == '-') flag = true;
                    else flag = false;
                }
                else if ((arith[i] == '*' || arith[i] == '/' || arith[i] == '^') && flag)
                {
                    if (i > 0)
                    {
                        flag = (arith[i - 1] != '(' && arith[i - 1] != 's' && arith[i - 1] != 'n' && arith[i - 1] != 't'
                            && arith[i - 1] != 'g' && arith[i - 1] != '+' && arith[i - 1] != '-' && arith[i - 1] != '*'
                            && arith[i - 1] != '^' && arith[i - 1] != '/');
                        if (i + 1 < arith.size() && flag)
                        {
                            flag = (arith[i + 1] != ')' && arith[i + 1] != '+' && arith[i + 1] != '-' && arith[i + 1] != '*'
                                && arith[i + 1] != '^' && arith[i + 1] != '/');
                        }
                        else flag = false;
                    }
                    else flag = false;
                }
                else if ((arith[i] == 'a') && flag)
                {
                    if (i + 6 < arith.size()) flag = flag && (arith[i + 6] == '(');
                    else flag = false;
                    i += 5;
                }
                else if ((arith[i] == 't') && flag)
                {
                    if (i + 2 < arith.size()) flag = (arith[i + 2] == '(');
                    else flag = false;
                    i++;
                }
                else if (arith[i] == ',' && flag)
                {
                    if (i > 0)
                    {
                        flag = isdigit(arith[i - 1]);
                        for (int j = i - 1; j > 0 && flag && arith[j] != '(' && arith[j] != '+' && arith[j] != '-' && arith[j] != '*' && arith[j] != '/' && arith[j] != '^'; j--)
                        {
                            flag = flag && arith[j] != ',';
                        }
                    }
                    else flag = false;
                    if (i + 1 < arith.size())
                    {
                        flag = isdigit(arith[i + 1]);
                        for (size_t j = i + 1; j < arith.size() && flag && arith[j] != ')' && arith[j] != '+' && arith[j] != '-' && arith[j] != '*' && arith[j] != '/' && arith[j] != '^'; j++)
                        {
                            flag = arith[j] != ',';
                        }
                    }
                    else flag = false;
                }
                else if ((isdigit(arith[i])) && flag)
                {
                    if (i > 0)
                    {
                        flag = isdigit(arith[i - 1]) || arith[i - 1] == ',' || arith[i - 1] == '+' || arith[i - 1] == '-' || arith[i - 1] == '/' || arith[i - 1] == '^' || arith[i - 1] == '*' || arith[i - 1] == '(';
                    }
                    if (i + 1 < arith.size())
                    {
                        flag = isdigit(arith[i + 1]) || arith[i + 1] == ',' || arith[i + 1] == '+' || arith[i + 1] == '-' || arith[i + 1] == '/' || arith[i + 1] == '^' || arith[i + 1] == '*' || arith[i + 1] == ')';
                    }
                }
                else if ((arith[i] == 'p' || arith[i] == 'e') && flag)
                {
                    if (i + 2 < arith.size() && arith[i] == 'p') flag = (arith[i + 2] == '+' || arith[i + 2] == '-' || arith[i + 2] == '/' || arith[i + 2] == '^' || arith[i + 2] == '*' || arith[i + 2] == ')');
                    if (i > 0)
                        flag = (arith[i - 1] == '+' || arith[i - 1] == '-' || arith[i - 1] == '/' || arith[i - 1] == '^' || arith[i - 1] == '*' || arith[i - 1] == '(');
                    if (i + 1 < arith.size() && arith[i] == 'e')flag = (arith[i + 1] == '+' || arith[i + 1] == '-' || arith[i + 1] == '/' || arith[i + 1] == '^' || arith[i + 1] == '*' || arith[i + 1] == ')');
                }
            }
        }
        if (!flag && arith.empty())
            cout << "the string is empty" << endl;
        else if (!flag)
            cout << "you entered a non-valid arithmetic expression at position (from 0): " << i - 1 << "- <<< " << arith[i - 1] << " >>> !!" << endl;
        math = flag;
        return flag;
    }
    void infix_to_postfix()
    {
        if (!math)
            math = is_correct(); // expression check
        if (math)
        {
            string changestr, str_polish;
            Stack_str list;
            for (size_t i = 0; i < arith.size(); i++)
            {
                if (isdigit(arith[i]) || arith[i] == 'c' || arith[i] == 'p' || arith[i] == 'e'
                    || arith[i] == 's' || arith[i] == 't' || arith[i] == 'l' || arith[i] == 'a')
                {
                    for (; math_sign(i, arith) == -1 && i < arith.size(); i++) // if a function then writes a function
                    {
                        changestr += arith[i];
                        str_polish += arith[i];
                    }
                    changestr += ' ';
                    str_polish += ' ';
                }
                if (math_sign(i, arith) == 1) // if i - '-'
                {
                    if (i > 0)
                    {
                        if (math_sign(i - 1, arith) == 5)
                        {
                            i++;
                            str_polish += '~';
                            for (; math_sign(i, arith) == -1; i++)
                            {
                                changestr += arith[i];
                                str_polish += arith[i];
                            }
                            changestr += ' ';
                            changestr += '-';
                            changestr += ' ';
                            str_polish += ' ';
                        }
                    }
                    else if (i == 0)
                    {
                        i++;
                        str_polish += '~';
                        for (; math_sign(i, arith) == -1; i++)
                        {
                            changestr += arith[i];
                            str_polish += arith[i];
                        }
                        changestr += ' ';
                        changestr += '-';
                        changestr += ' ';
                        str_polish += ' ';
                    }
                }
                switch (math_sign(i, arith))
                {
                case 0://if +
                    while (list.get_size())
                    {
                        if (list.get_elem(0) != "(")
                        {
                            changestr += list.get_elem(0);
                            str_polish += list.get_elem(0);
                            changestr += ' ';
                            str_polish += ' ';
                            list.pop_front();
                        }
                        else break;
                    }
                    list.push_front("+");
                    break;
                case 1://if -
                    while (list.get_size())
                    {
                        if (list.get_elem(0) != "(")
                        {
                            changestr += list.get_elem(0);
                            str_polish += list.get_elem(0);
                            changestr += ' ';
                            str_polish += ' ';
                            list.pop_front();
                        }
                        else break;
                    }
                    list.push_front("-");
                    break;
                case 2://if *
                    while (list.get_size())
                    {
                        if (list.get_elem(0) != "("
                            && list.get_elem(0) != "-" && list.get_elem(0) != "+")
                        {
                            changestr += list.get_elem(0);
                            str_polish += list.get_elem(0);
                            changestr += ' ';
                            str_polish += ' ';
                            list.pop_front();
                        }
                        else break;
                    }
                    list.push_front("*");
                    break;
                case 3://if ^
                    while (list.get_size())
                    {
                        if (list.get_elem(0) != "("
                            && list.get_elem(0) != "-" && list.get_elem(0) != "+")
                        {
                            changestr += list.get_elem(0);
                            str_polish += list.get_elem(0);
                            changestr += ' ';
                            str_polish += ' ';
                            list.pop_front();
                        }
                        else break;
                    }
                    list.push_front("^");
                    break;
                case 4://if /
                    while (list.get_size())
                    {
                        if (list.get_elem(0) != "("
                            && list.get_elem(0) != "-" && list.get_elem(0) != "+")
                        {
                            changestr += list.get_elem(0);
                            str_polish += list.get_elem(0);
                            changestr += ' ';
                            str_polish += ' ';
                            list.pop_front();
                        }
                        else break;
                    }
                    list.push_front("/");
                    break;
                case 5:// if (
                    list.push_front("(");
                    break;
                case 6://if )
                    while (list.get_elem(0) != "(")
                    {
                        changestr += list.get_elem(0);
                        str_polish += list.get_elem(0);
                        changestr += ' ';
                        str_polish += ' ';
                        list.pop_front();
                    }
                    list.pop_front();

                    break;
                }
            }
            while (list.get_size())
            {
                changestr += list.get_elem(0);
                str_polish += list.get_elem(0);
                changestr += ' ';
                str_polish += ' ';
                list.pop_front();
            }
            postfix = changestr;
            new_polish = str_polish;
        }
        else throw logic_error("expression entered incorrectly!"); // error
    }

    double result_arithm()
    {
        math = is_correct();
        if (math)
            infix_to_postfix();
        if (math)
        {
            string str, save, chanarith = arith;
            Stack_str liststring;
            size_t i, j;
            for (i = 0, j = 0; i < new_polish.size() && j < chanarith.size(); i++)
            {
                if (new_polish[i] == ' ')
                    continue;
                if (math_sign(j, arith) != -1 && math_sign(j, arith) != 6 && j + 1 != arith.size())
                    j++;
                if (new_polish[i] != ' ' && math_sign(i, new_polish) == -1)
                {
                    for (; i < new_polish.size() && new_polish[i] != ' '; i++)// writes a function or number to a stack
                    {
                        str += new_polish[i];
                        if (new_polish[i] == arith[j] && j + 1 != arith.size())j++;
                        if (new_polish[i + 1] == ' ')
                        {
                            save = str;
                            liststring.push_front(save);
                            str = "";
                        }
                    }
                    if (arith[j] == ')' && liststring.get_size() > 1)
                    {
                        switch (liststring.get_elem(1)[0])
                        {
                        case 't': //if tg
                            result = tan(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                            break;
                        case 'c'://if cos or ctg
                            if (liststring.get_elem(1)[1] == 'o')
                            {
                                result = cos(string_to_double(liststring.get_elem(0)));
                                liststring.pop_front();
                                liststring.pop_front();
                                liststring.push_front(double_to_string(result));
                            }
                            else
                            {
                                result = cos(string_to_double(liststring.get_elem(0))) / sin(string_to_double(liststring.get_elem(0)));
                                liststring.pop_front();
                                liststring.pop_front();
                                liststring.push_front(double_to_string(result));
                            }
                            break;
                        case 's'://if sin or sqrt
                            if (liststring.get_elem(1)[1] == 'i')
                            {
                                result = sin(string_to_double(liststring.get_elem(0)));
                                liststring.pop_front();
                                liststring.pop_front();
                                liststring.push_front(double_to_string(result));
                            }
                            else
                            {
                                result = sqrt(string_to_double(liststring.get_elem(0)));
                                liststring.pop_front();
                                liststring.pop_front();
                                liststring.push_front(double_to_string(result));
                            }
                            break;
                        case 'l': // if ln or log
                            if (liststring.get_elem(1)[1] == 'n')
                            {
                                result = log(string_to_double(liststring.get_elem(0)));
                                liststring.pop_front();
                                liststring.pop_front();
                                liststring.push_front(double_to_string(result));
                            }
                            else
                            {
                                result = log10(string_to_double(liststring.get_elem(0)));
                                liststring.pop_front();
                                liststring.pop_front();
                                liststring.push_front(double_to_string(result));
                            }
                            break;
                        case 'a':// if arccos
                            result = acos(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                            break;
                        default:
                            j--;
                        }
                        if (j + 1 != arith.size()) j++;
                    }
                    continue;
                }
                switch (math_sign(i, new_polish))
                {
                case 0:// if +
                    result = string_to_double(liststring.get_elem(1)) + string_to_double(liststring.get_elem(0));
                    liststring.pop_front();
                    liststring.pop_front();
                    liststring.push_front(double_to_string(result));
                    break;
                case 1:// if -
                    result = string_to_double(liststring.get_elem(1)) - string_to_double(liststring.get_elem(0));
                    liststring.pop_front();
                    liststring.pop_front();
                    liststring.push_front(double_to_string(result));
                    break;
                case 2:// if *
                    result = string_to_double(liststring.get_elem(1)) * string_to_double(liststring.get_elem(0));
                    liststring.pop_front();
                    liststring.pop_front();
                    liststring.push_front(double_to_string(result));
                    break;
                case 3:// if ^
                    result = pow(string_to_double(liststring.get_elem(1)), string_to_double(liststring.get_elem(0)));
                    liststring.pop_front();
                    liststring.pop_front();
                    liststring.push_front(double_to_string(result));
                    break;
                case 4:// if /
                    result = string_to_double(liststring.get_elem(1)) / string_to_double(liststring.get_elem(0));
                    liststring.pop_front();
                    liststring.pop_front();
                    liststring.push_front(double_to_string(result));
                    break;
                }
                if (arith[j] == ')' && liststring.get_size() > 1)
                {
                    switch (liststring.get_elem(1)[0])
                    {
                    case 't':
                        result = tan(string_to_double(liststring.get_elem(0)));
                        liststring.pop_front();
                        liststring.pop_front();
                        liststring.push_front(double_to_string(result));
                        break;
                    case 'c':
                        if (liststring.get_elem(1)[1] == 'o')
                        {
                            result = cos(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                        }
                        else
                        {
                            result = cos(string_to_double(liststring.get_elem(0))) / sin(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                        }
                        break;
                    case 's':
                        if (liststring.get_elem(1)[1] == 'i')
                        {
                            result = sin(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                        }
                        else
                        {
                            result = sqrt(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                        }
                        break;
                    case 'l':
                        if (liststring.get_elem(1)[1] == 'n')
                        {
                            result = log10(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                        }
                        else
                        {
                            result = log(string_to_double(liststring.get_elem(0)));
                            liststring.pop_front();
                            liststring.pop_front();
                            liststring.push_front(double_to_string(result));
                        }
                        break;
                    case 'asin':
                        result = asin(string_to_double(liststring.get_elem(0)));
                        liststring.pop_front();
                        liststring.pop_front();
                        liststring.push_front(double_to_string(result));
                        break;
                    }
                    if (j + 1 != arith.size()) j++;
                }

            }
            result = string_to_double(liststring.get_elem(0));
        }
        return result;
    }
    string out_postfix()
    {
        return postfix;//out postfix
    }
    double out_result()
    {
        return result;// outputs the result
    }
    void set_arithm_exp(string exp)
    {
        arith = exp; // overwrites arithmetic expression
    }
    friend ostream& operator<< (ostream& out, const Calculator& calc)
    {
        if (calc.math)
        {
            out << "Postfix: " << calc.postfix << endl;
            out << "Result: " << calc.result << endl;
        }
        else out << "Wrong value!" << endl;
        return out;
    }
private:
    int new_count(const char ch)
    {
        int count = 0;
        for (size_t i = 0; i < arith.size(); i++)
        {
            if (arith[i] == ch)count++;
        }
        return count;
    }

    int math_sign(size_t index, string str)
    {
        switch (str[index])
        {
        case '+':
            return 0;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '^':
            return 3;
            break;
        case '/':
            return 4;
            break;
        case '(':
            return 5;
            break;
        case ')':
            return 6;
            break;
        default:
            return -1;
            break;
        }
    }
    int to_find(const char* ch, size_t index, int len)
    {
        int current = 0;
        size_t i;
        bool flag = false;
        for (i = index; i < arith.size() && !flag; i++)
        {
            if (arith[i] == ch[0])
            {
                for (int j = 0; j < len && !flag; j++)
                {
                    flag = true;
                    if (arith[i + j] != ch[j])  flag = false;
                }
                if (flag) i = i - 1;
            }
        }
        if (flag) return i;
        else return -1;
    }
    int to_find(const string ch, size_t index, int len)
    {
        int current = 0;
        size_t i;
        bool flag = false;
        for (i = index; i < arith.size() && !flag; i++)
        {
            if (arith[i] == ch[0])
            {
                for (int j = 0; j < len && flag; j++)
                {
                    flag = true;
                    if (arith[i + j] != ch[j]) flag = false;
                }
                if (flag) i = i - len + 2;
            }
        }
        if (flag) return i;
        else return -1;
    }
    double string_to_double(string str)
    {
        double numdouble = 0;
        int degree = 1, minus = 0;
        size_t i;
        if (str[0] == 'p')
            numdouble = (double)pi;
        else if (str[0] == 'e')
            numdouble = (double)e;
        else
        {
            for (i = 0; i < str.size() && str[i] != ','; i++)
            {
                if (str[i] == '~' || str[i] == '-')
                {
                    minus = 1;
                    continue;
                }
                numdouble = numdouble * pow(10, i - minus) + (double)str[i] - 48;
            }
            if (i < str.size()) if (str[i] == ',')
            {
                for (++i; i < str.size(); i++, degree++)
                {
                    numdouble = numdouble + ((double)str[i] - 48) * pow(10, -degree);
                }
            }
            if (minus) numdouble *= -1;
        }
        return numdouble;
    }
    string double_to_string(double number)
    {
        int num;
        double new_num = number;
        string str;
        if (number < 0)
        {
            str += '-';
            new_num *= -1;
        }
        num = new_num;
        new_num -= num;
        if (num == 0) str += '0';
        while (num > 0)
        {
            str += (char)(num % 10 + 48);
            num /= 10;
        }
        if (new_num > 0)
        {
            str += ',';
            for (int i = 0; i < 2; i++)
            {
                num = new_num * 10;
                str += (char)(num + 48);
                new_num *= 10;
                new_num -= num;
            }
        }
        return str;
    }

    string arith, postfix, new_polish;
    double result;
    bool math;
};