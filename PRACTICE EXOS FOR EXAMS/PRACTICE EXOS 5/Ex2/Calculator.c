#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum choice { T1, T2 };
typedef enum operator{add, sub, mult, divi, EXIT, init};


struct Complex myCMPLX(float real, float imag)
{
	struct Complex c;
	c.a = real;
	c.b = imag;

	return c;
}

float myCreal(struct Complex c) 
{
	return c.a;
}
float myCimag(struct Complex c)
{
	return c.b;
}

void printCimag(struct Complex c)
{
	if (myCimag(c) == 1)
		printf("+ i");
	else if (myCimag(c) == -1)
		printf("- i");
	else if (myCimag(c) > 1)
		printf("+ %.2fi", myCimag(c));
	else if(myCimag(c)< -1)
		printf("- %.2fi", absoluteValueOf(myCimag(c)));

}
void printComplex(struct Complex c)
{
	if (myCreal(c) != 0)
	{
		printf("%.2f ", myCreal(c));
		printCimag(c);
	}
	else
		printf("%.2fi", myCimag(c));

}

float absoluteValueOf(float num)
{
	if (num >= 0)
		return num;
	else
		return -1 * num;
}
struct Complex cConjugate(struct Complex c)
{
	return myCMPLX(myCreal(c), myCimag(c) * -1);
}

double addRR(double r1, double r2)
{
	return r1 + r2;
}
struct Complex addRC(double r, struct Complex c)
{
	return myCMPLX(myCreal(c) + (float)r, myCimag(c));
}
struct Complex addCR(struct Complex c, double r)
{
	return myCMPLX(myCreal(c) + (float)r, myCimag(c));
}
struct Complex addCC(struct Complex c1, struct Complex c2)
{
	return myCMPLX(myCreal(c1) + myCreal(c2), myCimag(c1) + myCimag(c2));
}

double substractRR(double r1, double r2)
{
	return r1 - r2;
}
struct Complex substractRC(double r, struct Complex c)
{
	return myCMPLX((float)r - myCreal(c), myCimag(c)*-1);
}
struct Complex substractCR(struct Complex c, double r)
{
	return myCMPLX(myCreal(c) - (float)r, myCimag(c));

}
struct Complex substractCC(struct Complex c1, struct Complex c2)
{
	return myCMPLX(myCreal(c1) - myCreal(c2), myCimag(c1) - myCimag(c2));
}

double multiplyRR(double r1, double r2)
{
	return r1 * r2;
}
struct Complex multiplyRC(double r, struct Complex c)
{
	return myCMPLX((float)r * myCreal(c), (float)r * myCimag(c));
}
struct Complex multiplyCR(struct Complex c, double r)
{
	return myCMPLX((float)r * myCreal(c), (float)r * myCimag(c));
}
struct Complex multiplyCC(struct Complex c1, struct Complex c2)
{
	struct Complex res1 = myCMPLX(myCreal(c1) * myCreal(c2), myCreal(c1) * myCimag(c2));
	struct Complex res2 = myCMPLX(myCimag(c1) * myCimag(c2) * -1 , myCimag(c1) * myCreal(c2));

	return addCC(res1, res2);

}

double divideRR(double r1, double r2)
{
	return r1 / r2;
}
struct Complex divideRC(double r, struct Complex c)
{
	if (myCreal(c) == 0)
		return myCMPLX(0, (float)r * -1 / myCimag(c));
	else
	{
		struct Complex conjugate = cConjugate(c);
		struct Complex numerator = multiplyRC(r, conjugate);
		double denominator = pow(myCreal(c), 2) + pow(myCimag(c), 2);

		return divideCR(numerator, denominator);
	}

}
struct Complex divideCR(struct Complex c, double r)
{
	return myCMPLX(myCreal(c) / (float)r, myCimag(c) / (float)r);

}
struct Complex divideCC(struct Complex c1, struct Complex c2)
{
	if (myCreal(c2) == 0)
	{
		float resImag = myCreal(c1) * -1 / myCimag(c2); //ex: 6/4i == -6i/4
		float resReal = myCimag(c1) / myCimag(c2);

		return myCMPLX(resReal, resImag);
	}
	else
	{
		struct Complex conjugate = cConjugate(c2);
		struct Complex numerator = multiplyCC(c1, conjugate);
		float denominator = pow(myCreal(c2), 2) + pow(myCimag(c2),2);

		return divideCR(numerator, denominator);		
	}
}


const char* getType()
{
	char t[8];
	printf("type:     ");
	scanf("%s", t);

	return t;
}
double getReal(enum choice* ch)
{
	*ch = T1;
	double r;
	printf("num:      ");
	scanf("%lf", &r);

	return r;
}
struct Complex getComplex(enum choice* ch)
{
	float a, b;
	char o;
	struct Complex C;
	*ch = T2;
	printf("num:      ");
	scanf("%f%c%fi", &a, &o, &b);
	C = myCMPLX(a, b);

	return C;
}
const char getOperator(enum operator* OP)
{
	char op = '&';
	printf("operator: ");
	scanf(" %c", &op);

	if (op == '+')
		*OP = add;
	else if (op == '-')
		*OP = sub;
	else if (op == '*')
		*OP = mult;
	else if (op == '/')
		*OP = divi;
	else
		*OP = EXIT;

	return op;
}
void printPrompt()
{
	printf("possible commands:\t+\t-\t*\t/\tX to exit\n\n");
	printf("print complex numbers in following format:\ta+bi\n");
	printf("if b is negative, write is as :           \ta+-bi\n");
	printf("if a or b is zero, write is as :          \t0+bi or a+0i\n");
	printf("if b is one, write is as :                \ta+1i\n\n\n");
}

void CALCULATOR()
{
	const char* type1;
	const char* type2;
	char op = '&';
	double Rx = 0, Ry = 0, Rres = 0;
	struct Complex Cx = myCMPLX(0, 0), Cy = myCMPLX(0, 0), Cres = myCMPLX(0, 0);
	enum choice t1 = T1, t2 = T2;
	enum operator COMMAND = init;

	printPrompt();

	type1 = getType();

	if (strcmp(type1, "real") == 0)
		Rx = getReal(&t1);
	else if (strcmp(type1, "complex") == 0)
		Cx = getComplex(&t1);

	op = getOperator(&COMMAND);

	while (COMMAND != EXIT)
	{
		type2 = getType();

		if (strcmp(type2, "real") == 0)
			Ry = getReal(&t2);

		else if (strcmp(type2, "complex") == 0)
			Cy = getComplex(&t2);


		switch (t1) {
		case 0:
			switch (t2) {
			case 0:
				if (op == '+')
					Rres = addRR(Rx, Ry);
				else if (op == '-')
					Rres = substractRR(Rx, Ry);
				else if (op == '*')
					Rres = multiplyRR(Rx, Ry);
				else if (op == '/')
					Rres = divideRR(Rx, Ry);
				else
					;
				printf("\t= %f\n", Rres);
				break;
			case 1:
				if (op == '+')
					Cres = addRC(Rx, Cy);
				else if (op == '-')
					Cres = substractRC(Rx, Cy);
				else if (op == '*')
					Cres = multiplyRC(Rx, Cy);
				else if (op == '/')
					Cres = divideRC(Rx, Cy);
				else
					;
				printf("\t= ");
				printComplex(Cres);
				printf("\n");
				break;
			}
			break;
		case 1:
			switch (t2) {
			case 0:
				if (op == '+')
					Cres = addCR(Cx, Ry);
				else if (op == '-')
					Cres = substractCR(Cx, Ry);
				else if (op == '*')
					Cres = multiplyCR(Cx, Ry);
				else if (op == '/')
					Cres = divideCR(Cx, Ry);
				else
					;
				printf("\t= ");
				printComplex(Cres);
				printf("\n");
				break;
			case 1:
				if (op == '+')
					Cres = addCC(Cx, Cy);
				else if (op == '-')
					Cres = substractCC(Cx, Cy);
				else if (op == '*')
					Cres = multiplyCC(Cx, Cy);
				else if (op == '/')
					Cres = divideCC(Cx, Cy);
				else
					;
				printf("\t= ");
				printComplex(Cres);
				printf("\n");
				break;
			}
			break;
		}

		if (t1 == T1 && t2 == T1)
		{
			t1 = T1;
			Rx = Rres;
		}
		else
		{
			t1 = T2;
			Cx = Cres;
		}

		op = getOperator(&COMMAND);
	}
}





