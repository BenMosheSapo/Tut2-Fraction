#include <iostream>

using namespace std;

class Fraction{
private:
	int denom;
	int num;

	int LCM(int num1, int num2, int count=1){
		if (count % num1 == 0 && count % num2 == 0){
			return count;
		}
		else{
			LCM(num1, num2, count+1);
		}
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
	//Finds lowest common multiple of denominators, converts numerators to match denominator and finally adds the numerators
	Fraction add(int Num2, int Denom2){
		int lcm = LCM(denom, Denom2);
		Num2 *= lcm/Denom2;
		num *= lcm/denom;
		Fraction Result(num + Num2 , lcm);
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
		cout << num << "/" << denom << endl;
	}

	~Fraction(){

	}
};

int main(){
	Fraction First(1, 2);
	Fraction Result;
	Result = First.Multiply(3, 4);
	Result.Print();
}
