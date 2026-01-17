#include "Poly.h"

Poly::Poly()
{
    head = nullptr;
}
Poly::Poly(const Poly& other)
{
    head = nullptr;
    copyList(other);
}

istream& operator>>(istream& is, Poly& p)
{
    p.Reset();

    char next;
    string s_coeff;
    string s_exp;
    int i_coeff;
    int i_exp;

    is>>next; //eat <
    if(next != '<')
    {
        cout<<"ERROR IN INPUT FORMAT"<<endl;
        return is;
    }
    is>>next; //prime coeff
    while(next != '>')
    {
        s_coeff = "";
        s_exp = "";
        while(next != 'x')
        {
            s_coeff += next;
            is>>next;
        }
        i_coeff = stoi(s_coeff);

        is>>next; //eat ^
        is>>next; //prime exp
        while(next != '+' && next != '>')
        {
            s_exp += next;
            is>>next;
        }
        i_exp = stoi(s_exp);

        //cout<<i_coeff<<":"<<i_exp<<endl;
        p.Insert(i_coeff, i_exp);

        if(next != '>')
        {
            is>>next; //prime next coeff;
        }
    }
    return is;
}
ostream& operator<<(ostream& os, const Poly& p)
{
    Term* current;
    current = p.head;
    os << "<";
    while(current != nullptr)
    {
        cout<<current->coeff;
        if(current->exp != 0)
        {
            cout<< "x^" << current->exp;
        }
        if(current->next != nullptr)
        {
            cout<<" + ";
        }
        current = current->next;
    }
    os << ">" <<endl;
    return os;
}

void Poly::Reset()
{
    Term* current;
    Term* temp;
    current = head;
    while(current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int Poly::Evaluate(int x)
{
    int val = 0;
    Term* current = head;
    while(current != nullptr)
    {
        val = val + ((pow(x, current->exp))*current->coeff);
        current = current->next;
    }
    return val;
}

Poly Poly::operator+(const Poly& rhs)const
{
    Term* left;
    Term* right;

    Poly sum;

    left = head;
    right = rhs.head;

    while(left != nullptr && right != nullptr)
    {
        if(left->exp == right->exp)
        {
            sum.Insert(left->coeff + right->coeff, left->exp);
            left = left->next;
            right = right->next;
        }
        else if(left->exp > right->exp)
        {
            sum.Insert(left->coeff, left->exp);
            left = left->next;
        }
        else if(left->exp < right->exp)
        {
            sum.Insert(right->coeff, right->exp);
            right = right->next;
        }
    }
    if(left == nullptr && right != nullptr)
    {
        while(right != nullptr)
        {
            sum.Insert(right->coeff, right->exp);
            right = right->next;
        }
    }
    else if(right == nullptr && left != nullptr)
    {
        while(left != nullptr)
        {
            sum.Insert(left->coeff, left->exp);
            left = left->next;
        }
    }
    return sum;
}

Poly Poly::operator-(const Poly& rhs)const
{
    Term* left;
    Term* right;

    Poly diff;

    left = head;
    right = rhs.head;

    while(left != nullptr && right != nullptr)
    {
        if(left->exp == right->exp)
        {
            int x;
            x = left->coeff + (-1*right->coeff);
            if(x != 0)
            {
                diff.Insert(x, left->exp);
            }
            left = left->next;
            right = right->next;
        }
        else if(left->exp > right->exp)
        {
            diff.Insert(left->coeff, left->exp);
            left = left->next;
        }
        else if(left->exp < right->exp)
        {
            diff.Insert((-1*right->coeff), right->exp);
            right = right->next;
        }
    }
    if(left == nullptr && right != nullptr)
    {
        while(right != nullptr)
        {
            diff.Insert((-1*right->coeff), right->exp);
            right = right->next;
        }
    }
    else if(right == nullptr && left != nullptr)
    {
        while(left != nullptr)
        {
            diff.Insert(left->coeff, left->exp);
            left = left->next;
        }
    }
    return diff;
}

void Poly::Derivative()
{
    Term* current;
    Term* previous;
    current = head;

    if(current!=nullptr)
    {
        if(current->exp == 0)
        {
            delete current;
            head = nullptr;
        }
        else if(current->next == nullptr)
        {
            current->coeff = current->coeff * current->exp;
            current->exp = current->exp - 1;
        }
        else{
            current->coeff = current->coeff * current->exp;
            current->exp = current->exp - 1;
            previous = current;
            current = current->next;
            while(current != nullptr)
            {
                if(current->exp == 0)
                {
                    previous->next = nullptr;
                    delete current;
                    current = nullptr;
                }
                else
                {
                    current->coeff = current->coeff * current->exp;
                    current->exp = current->exp - 1;
                    previous = current;
                    current = current->next;
                }
            }
        }
    }

}

void Poly::Insert(int c, int e)
{
    Term* newT = new Term;
    newT->coeff = c;
    newT->exp = e;
    newT->next = nullptr;

    Term* current;
    Term* previous;

    if(head == nullptr)
    {
        head = newT;
    }
    else if(head->exp < e)
    {
        newT->next = head;
        head = newT;
    }
    else
    {
        current = head;

        while(current != nullptr && current->exp > e)
        {
            previous = current;
            current = current->next;
        }

        if(current == nullptr)
        {
            previous->next = newT;
        }
        else
        {
            previous->next = newT;
            newT->next = current;
        }
    }
}

Term* Poly::Search(int targetExp)
{
    Term* srch;
    srch = head;

    while(srch != nullptr)
    {
        if(srch->exp == targetExp)
        {
            return srch;
        }
        srch = srch->next;
    }
    return nullptr;
}

void Poly::PrintReverse()
{
    Term* current;
    current = head;
    cout<<"<";
    recPrintRev(current);
    cout<<">"<<endl;
}
void Poly::recPrintRev(Term* c)
{
    if(c->next != nullptr)
    {
        recPrintRev(c->next);
    }
    cout << c->coeff << "x^" << c->exp << " + ";
}

Poly& Poly::operator=(const Poly& other)
{
    if (this != &other) //avoid self-copy
    {
        copyList(other);
    }//end else

    return *this;
}

Poly::~Poly()
{
    Reset();
}

void Poly::copyList(const Poly& otherList)
{
    Term* newT;
    Term* current;
    Term* last;

    if(head!=nullptr)
    {
        Reset();
    }

    if(otherList.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        current = otherList.head;
        head = new Term;
        head->coeff = otherList.head->coeff;
        head->exp = otherList.head->exp;
        head->next = nullptr;

        last = head;
        current = current->next;

        while(current != nullptr)
        {
            newT = new Term;
            newT->coeff = current->coeff;
            newT->exp = current->exp;
            newT->next = nullptr;

            last->next = newT;

            last = last->next;
            current = current->next;
        }
    }
}
