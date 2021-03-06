//Ben Moshe Sapo 
// 214527679
#include <iostream>
#include <math.h>

using namespace std;

class Fraction{
private:
	int denom;
	int num;

	//Finds the Highest Common Factor
	int HCF(int num1, int denom1){
		if (denom1 != 0){
			return HCF(denom1, num1%denom1);
		}
		else{
			return num1;
		}
	}

	
		
	
public:
	// Finds the simplest form of a fraction by dividing the numerator and denominator by the highest common factor
	void SimplestForm(int &rnum, int &rdenom, int &rWhole) {
		int hcf = HCF(rnum, rdenom);
		rnum = rnum / hcf;
		rdenom = rdenom / hcf;
		rWhole = rnum / rdenom;
		rnum = rnum - rdenom*rWhole;
	}
	Fraction(int numerator = 1, int denominator = 1){
		denom = denominator;
		num = numerator;
	}

	void SetNumDenom(int numerator, int denominator){
		num = numerator;
		denom = denominator;
	}
	
	void GetNumDenom(int &rnum, int &rdenom){
		rnum = num;
		rdenom = denom;
	}

	
	//adds two fractions by cross multiplication
	Fraction add(Fraction num2){
		int Denom2,Num2;
		num2.GetNumDenom(Num2,Denom2);
		num = num * Denom2;
		Num2 = Num2*denom;
		Fraction Result(num + Num2 , denom * Denom2);
		return Result;
	}

	// Adds the negative of fraction entered
	Fraction sub(Fraction num2){
		int Denom2,Num2;
		num2.GetNumDenom(Num2, Denom2);
		num2.SetNumDenom(-Num2, Denom2);
		return add(num2);
	}

	//multiply numerators and denominators
	Fraction Multiply(Fraction num2){
		int Num2, Denom2;
		num2.GetNumDenom(Num2, Denom2);
		Fraction Result(num * Num2, denom * Denom2);
		return Result;
	}
	// mulitplies fraction by reciprical of entered fraction
	Fraction Divide(Fraction num2){
		int Num2, Denom2;
		num2.GetNumDenom(Num2, Denom2);
		num2.SetNumDenom(Denom2, Num2);
		return Multiply(num2);
	}
//Prints out the fraction as a mixed number
	void Print(){
		int whole;
		int Num = num;
		int Denom = denom;
		SimplestForm(Num, Denom,whole);
		if (whole != 0 && Num!=0){
			cout << whole << " " << Num << "/" << abs(Denom) << endl;
		}
		else if (whole != 0){
			cout << whole << endl;
		}
		else if (Num!=0){
			cout << Num << "/" << abs(Denom) << endl;
		}
		else{
			cout << "0" << endl;
		}
	}

	~Fraction(){

	}
};
Fraction operator+(Fraction num1, Fraction num2){
	return num1.add(num2);
}
Fraction operator-(Fraction num1, Fraction num2){
	return num1.sub(num2);
}
Fraction operator/(Fraction num1, Fraction num2){
	return num1.Divide(num2);
}
Fraction operator*(Fraction num1, Fraction num2){
	return num1.Multiply(num2);
}

ostream &operator<<(ostream &stream, Fraction fract) {
	int num, denom,whole;
	fract.GetNumDenom(num, denom);
	fract.SimplestForm(num,denom,whole);
	if (whole != 0 && num != 0) {
		stream << whole << " " << num << "/" << abs(denom) << endl;
	}
	else if (whole != 0) {
		stream << whole << endl;
	}
	else if (num != 0) {
		stream << num << "/" << abs(denom) << endl;
	}
	else {
		stream << "0" << endl;
	}
	return stream;
}

istream &operator>>(istream &stream, Fraction &fract) {
	int num, denom;
	stream >> num;
	stream.ignore(1,'/' );
	stream >> denom;
	fract.SetNumDenom(num, denom);
	return stream;
}

int main(){
	Fraction First(5, 4);
	cin >> First;
	cout << First << endl;
}
