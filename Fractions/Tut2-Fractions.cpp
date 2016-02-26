#include <iostream>

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
	// Finds the simplest form of a fraction by dividing the numerator and denominator by the highest common factor
	void SimplestForm(int &rnum, int &rdenom){
		int hcf = HCF(rnum, rdenom);
		rnum = rnum / hcf;
		rdenom = rdenom / hcf;
	}
		
	
public:
	Fraction(int numerator = 1, int denominator = 1){
		denom = denominator;
		num = numerator;
	}

	void SetValues(int numerator, int denominator){
		num = numerator;
		denom = denominator;
	}
	
	void GetValues(int &rnum, int &rdenom){
		rnum = num;
		rdenom = denom;
	}

	int GetNum(){
		return num;
	}

	int GetDenom(){
		return denom;
	}
	//adds two fractions by cross multiplication
	Fraction add(int Num2, int Denom2){
		num = num * Denom2;
		Num2 = Num2*denom;
		Fraction Result(num + Num2 , denom * Denom2);
		return Result;
	}

	// Adds the negative of fraction entered
	Fraction sub(int Num2, int Denom2){
		return add(-Num2, Denom2);
	}

	//multiply numerators and denominators
	Fraction Multiply(int Num2, int Denom2){
		Fraction Result(num * Num2, denom * Denom2);
		return Result;
	}
	// mulitplies fraction by reciprical of entered fraction
	Fraction Divide(int Num2, int Denom2){
		return Multiply(Denom2, Num2);
	}

	void Print(){
		SimplestForm(num, denom);
		cout << num << "/" << denom << endl;
	}

	~Fraction(){

	}
};

int main(){
	Fraction First(1, 2);
	Fraction Result;
	Result = First.add(3, 4);
	Result.Print();
}
