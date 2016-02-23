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

	void SetNum(int numerator){
		num = numerator;
	}

	void SetDenom(int denominator){
		denom = denominator;
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

	// Adds the negative of fraction inputed
	Fraction sub(int Num2, int Denom2){
		return add(-Num2, Denom2);
	}

	Fraction Multiply(int Num2, int Denom2){

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
	Result = First.sub(3, 4);
	Result.Print();
}
