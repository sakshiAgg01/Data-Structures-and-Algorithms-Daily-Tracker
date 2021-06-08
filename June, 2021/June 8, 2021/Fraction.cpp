#include <iostream>
using namespace std;


class Fraction{
    public:
    int numerator;
    int denominator;
    
    //constructor
    Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    
    //To simplify the fraction to lowest multiples
    void simplify(){
        int gcd = 1;
        int j = min(numerator, denominator);
        for(int i=1; i<=j; i++){
            if(numerator%i == 0 && denominator%i == 0){
                gcd = i;
            }
        }
        
        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }
    
    //To add two fractions
    void add(Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        
        int num = numerator*x + f2.numerator*y;
        
        numerator = num;
        denominator = lcm;
        simplify();
    }
    
    //To multiply two fractions
    void multiply(Fraction const &f2){
        numerator = numerator*f2.numerator;
        denominator = denominator*f2.denominator;
    }
    
    //To display the final fraction after simplification
    void display(){
        cout<<numerator<<" "<<denominator<<endl;
    }
};

int main() {
	Fraction f1(2, 3);
	Fraction f2(5, 9);
	
	f1.add(f2);
	f1.display();
	f1.multiply(f2);
	f1.display();
	return 0;
}








