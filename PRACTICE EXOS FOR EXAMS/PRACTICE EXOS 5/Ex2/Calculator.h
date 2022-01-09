#pragma once

struct Complex {
	float a,b;
};

struct Complex myCMPLX(float real, float imag); //creat complex number
float myCreal(struct Complex c); //returns a of a+bi complex number
float myCimag(struct Complex c); //returns b of a+bi complex number
void printCimag(struct Complex C);
void printComplex(struct Complex c);

float absoluteValueOf(float num);
struct Complex cConjugate(struct Complex c);

double addRR(double r1, double r2);
struct Complex addRC(double r, struct Complex c);
struct Complex addCR(struct Complex c, double r);
struct Complex addCC(struct Complex c1, struct Complex c2);

double substractRR(double r1, double r2);
struct Complex substractRC(double r, struct Complex c);
struct Complex substractCR(struct Complex c, double r);
struct Complex substractCC(struct Complex c1, struct Complex c2);

double multiplyRR(double r1, double r2);
struct Complex multiplyRC(double r, struct Complex c);
struct Complex multiplyCR(struct Complex c, double r);
struct Complex multiplyCC(struct Complex c1, struct Complex c2);

double divideRR(double r1, double r2);
struct Complex divideRC(double r, struct Complex c);
struct Complex divideCR(struct Complex c, double r);
struct Complex divideCC(struct Complex c1, struct Complex c2);

const char* getType();
double getReal(enum choice* ch);
struct Complex getComplex(enum choice* ch);
const char getOperator(enum operator* OP);
void printPrompt();

void CALCULATOR();


