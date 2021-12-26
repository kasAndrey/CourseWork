#include "pch.h"
#include "CppUnitTest.h"
#include "../Kurs_calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCalc
{
	TEST_CLASS(UnitTestCalc)
	{
	public:
		
		TEST_METHOD(is_correct_Test) // check for the correctness of the expression
		{
			string str;
			Calculator calc;
			str = "2/2*(9-2^3)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "(((";
			calc.set_arithm_exp(str);
			Assert::IsFalse(calc.is_correct());

			str = "sin(e)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "-ln(pi/4)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "-34+11-6*2";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "9-sqrt(81)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "(1^e-cos(90))*(-1)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "tg(45)+arccos(2)+(-1/8)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "log(784)-pi^e";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "df-da";
			calc.set_arithm_exp(str);
			Assert::IsFalse(calc.is_correct());

			str = "()";
			calc.set_arithm_exp(str);
			Assert::IsFalse(calc.is_correct());

			str = "1+2-3/4^(-2)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());

			str = "ctg(pi)/(tg(pi)+6)";
			calc.set_arithm_exp(str);
			Assert::IsTrue(calc.is_correct());
		}

		TEST_METHOD(infix_to_postfix_Test) // compare the expected and received forms by symbol
		{
			string str,str_exp;
			Calculator calc;
			bool flag = true;
			int i;

			str = "2-2";
			str_exp = "2 2 -";
			calc.set_arithm_exp(str);
			calc.infix_to_postfix();
			for (i = 0; i < calc.out_postfix().size() && i < str_exp.size() && flag; i++)
			{
				if (str_exp[i] == calc.out_postfix()[i])
					flag = true;
				else flag = false;
			}
			Assert::IsTrue(flag);

			str = "tg(45)+arccos(2)+(-1/8)";
			str_exp = "tg 45 arccos 2 + 1 - 8 / +";
			calc.set_arithm_exp(str);
			calc.infix_to_postfix();
			for (i = 0; i < calc.out_postfix().size() && i < str_exp.size() && flag; i++)
			{
				if (str_exp[i] == calc.out_postfix()[i])
					flag = true;
				else flag = false;
			}
			Assert::IsTrue(flag);

			str = "log(784)-pi^e";
			str_exp = "log 784 pi e ^ -";
			calc.set_arithm_exp(str);
			calc.infix_to_postfix();
			for (i = 0; i < calc.out_postfix().size() && i < str_exp.size() && flag; i++)
			{
				if (str_exp[i] == calc.out_postfix()[i])
					flag = true;
				else flag = false;
			}
			Assert::IsTrue(flag);

			str = "1+2-3/4^(-2)";
			str_exp = "1 2 + 3 4 / 2 - ^ -";
			calc.set_arithm_exp(str);
			calc.infix_to_postfix();
			for (i = 0; i < calc.out_postfix().size() && i < str_exp.size() && flag; i++)
			{
				if (str_exp[i] == calc.out_postfix()[i])
					flag = true;
				else flag = false;
			}
			Assert::IsTrue(flag);
		}

		TEST_METHOD(result_Test)
		{
			string str;
			Calculator calc;
			str = "1+2-3/4^(-2)";
			calc.set_arithm_exp(str);
			calc.result_arithm();
			Assert::IsTrue(calc.out_result() == 1.22);

			str = "1/2+cos(pi/4)";
			calc.set_arithm_exp(str);
			calc.result_arithm();
			Assert::IsTrue(calc.out_result() == 1.2);

			str = "log(pi)-log(pi)";
			calc.set_arithm_exp(str);
			calc.result_arithm();
			Assert::IsTrue(calc.out_result() == 0);

			str = "(5)/5";
			calc.set_arithm_exp(str);
			calc.result_arithm();
			Assert::IsTrue(calc.out_result() == 1);

			
			str = "2^3";
			calc.set_arithm_exp(str);
			calc.result_arithm();
			Assert::IsTrue(calc.out_result() == 8);
		}

	};
}
