#include <iostream>
using namespace std;

class ComplexNumber{
    private:
    double real;
    double imag;

    public :

    // this is parameterized constructor
    ComplexNumber(double real1, double imag1){
        real = real1;
        imag = imag1;
    }

    // this is default constructor

    ComplexNumber(){
        real = 0.0;
        imag = 0.0;
    }

   /* overloading addition operation */

   ComplexNumber operator +(ComplexNumber other){

    return ComplexNumber(real + other.real , imag + other.imag);

   } 

   /* overloading subtraction operation */

   ComplexNumber operator -(ComplexNumber other){

    return ComplexNumber(real - other.real , imag - other.imag);

   } 

    /* overloading multiplication operation */

    ComplexNumber operator*( ComplexNumber other){
        double resultreal = (real * other.real) - (imag * other.imag);
        double resultimag = (real * other.imag) + (imag * other.real);
        return ComplexNumber(resultreal, resultimag);
    }


    // Type casting operator to convert to double (returns the real part)
    operator double(){
        return real;
    }

    // Static method to cast double to ComplexNumber with imaginary part as 0
    static ComplexNumber fromDouble(double value) {
        return ComplexNumber(value, 0);
    }


    // Display the complex number
     void display(){
        cout << real << " + " << imag<< "i" << std::endl;
    }

};

int main(){
    // Creating ComplexNumber objects using parameterized and default constructors
    ComplexNumber comp1(3, 2);
    ComplexNumber comp2(1, -1);
    ComplexNumber comp3;  // Default constructor creates (0, 0)

    // Testing addition, subtraction, and multiplication
    ComplexNumber resultAddition = comp1 + comp2;
    ComplexNumber resultSubtraction = comp1 - comp2;
    ComplexNumber resultMultiplication = comp1 * comp2;

    cout << "Addition: ";
    resultAddition.display();
    cout << "Subtraction: ";
    resultSubtraction.display();
    cout << "Multiplication: ";
    resultMultiplication.display();

    // Type casting operations
    double castedToDouble = static_cast<double>(comp1);
    ComplexNumber castedToComplex = ComplexNumber::fromDouble(5.0);

    cout << "Type Casting (Complex to Double): " << castedToDouble << std::endl;
    cout << "Type Casting (Double to Complex): ";
    castedToComplex.display();





    return 0;
}