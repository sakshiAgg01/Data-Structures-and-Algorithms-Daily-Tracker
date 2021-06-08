#include <iostream>
using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(){
        
    }
    /* This constructor will restrict the user
    to give values for both numerator and denominator */
    Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    
    //Getters do not make any changes to the properties
    //of current object. So these functions can be marked
    //as constant.
    int getNumerator() const {
        return numerator;
    }
    
    int getDenominator() const {
        return denominator;
    }
    
    //Setters make changes to the properties of current
    //object. Here setNumerator() is changing the values
    //of numerator. So it can't be made constant.
    void setNumerator(int n) {
        numerator=n;
    }
    
    void setDenominator(int d){
        denominator=d;
    }

    //It can be made const because it just prints
    //the contents of an object
    void const print()  {
        cout<< numerator<<" / "<<denominator<<endl;
    }

    //Function to simplify fraction
    void simplify(){
        int gcd = 1;
        int min_num = min(this->numerator, this->denominator);
        for(int i=1; i<= min_num; i++){
            if(this->numerator%i==0 && this->denominator%i==0){
                gcd = i;
            }
        }
        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator/gcd;
    }

    //Adding two fractions f1 and f2 and putting the result back in f1
    void add(Fraction const &f2){
       int lcm = this->denominator * f2.denominator;
       int x = lcm/this->denominator;
       int y = lcm/f2.denominator;

       int num = x*(this->numerator) + y*(f2.numerator);

       //Putting the results back in f1 fraction
       this->numerator = num;
       this->denominator = lcm;

       //Simplifying the fraction calculated above
       simplify();  // this->simplify();
    }

    //Multiplying two fractions f1 and f2 and putting back results in f1
    void multiply(Fraction const &f2){
        this->numerator = this->numerator * f2.numerator;
        this->denominator = this->denominator * f2.denominator;
        simplify();
    }
};

int main() {
	Fraction f1(10,2);
	Fraction f2(15,4);
	
	Fraction const f3;  //constant object
	cout<< f3.getNumerator()<< " "<< f3.getDenominator()<<endl;
	return 0;
}
