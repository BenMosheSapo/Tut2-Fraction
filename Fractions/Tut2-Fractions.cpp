//Ben Moshe Sapo 
// 214527679
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

	void Print(){
		SimplestForm(num, denom);
		cout << num << "/" << denom << endl;
	}

	~Fraction(){

	}
};

int main(){
	Fraction First(1, 2);
	Fraction Result(1,2);
	Result = First.Divide(Result);
	Result.Print();
}
