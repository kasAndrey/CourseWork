#include "Calculator.h";
#define pi 3.14
#define e 2.71
using namespace std;

int main()
{
    cout << "Kasatkin Andrey gr.0309" << endl;
    bool flag = true;
    size_t i;
    string str;
    Calculator calc;
    str = "cos(pi/2)+(2*4^2)";
    calc.set_arithm_exp(str);
    calc.result_arithm();
    cout<<endl;
    cout<<"input: " << str << endl;
    cout<<endl;
    cout << calc << endl;
   
}