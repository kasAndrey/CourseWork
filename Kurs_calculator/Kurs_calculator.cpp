#include "Calculator.h";
#define pi 3.14
#define e 2.71
using namespace std;

int main()
{
    bool flag = true;
    size_t i;
    string str;
    Calculator calc;
    str = "cos(pi/4)^2-sin(pi)^2";
    calc.set_arithm_exp(str);
    calc.result_arithm();
    cout<<"----------------------------------------------"<<endl;
    cout<<"Your input: " << str << endl;
    cout<<"----------------------------------------------"<<endl;
    cout << calc << endl;
    
}