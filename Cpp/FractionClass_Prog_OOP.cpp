// 101224. => Fraction_OOP

/*
    * Program to Implement a Fraction class as :
        -> Properties : Numerator & Denomenator.
        -> Functions : 
            - Parameterised Constructor - to set the properties' value.
            - add - to add two fractions & store the result in the first one.
            - multiply - to mul two fractions & store the result in the first one.
            - simplify - to reduce to fraction to its simplest form. (using inbuilt __gcd())
            - print - to print the fraction as "Nr/Dr".

    * Follows OOP design.

    * INPUT : 
        1st line : Initial Nr & Dr
        2nd line : Number of operations to perform. => 'n'
        Next 'n' lines : Query(int), Q_Nr(int), Q_Dr(int)
            Query = 1:Addition & 2:Multiplication.
            Q_Nr, Q_Dr = Nr & Dr of the Operand Fraction.

    * OUTPUT :
        Print the value of fraction after every Query, in seperate line.
*/

// #include <bits/stdc++.h> 
#include<iostream>

#include<algorithm>

using namespace std;

class Fraction {
    private:
        int nr, dr;

    public:    
        Fraction(int nr, int dr);
        
        int getNr(); int getDr();
        void setNr(int nr); void setDr(int dr);

        void add(Fraction& f2);
        void multiply(Fraction& f2);
        void simplify();
        void print();
};

Fraction :: Fraction(int nr, int dr){
    this->nr = nr;
    this->dr = dr;
}

// Getters.
int Fraction :: getNr(){return this->nr;}
int Fraction :: getDr(){return this->dr;}

// Setters.
void Fraction :: setNr(int nr){ this->nr = nr;  }
void Fraction :: setDr(int dr){ this->dr = dr;  }


void Fraction :: add(Fraction& f2){
    int lcm = this->getDr() * f2.getDr();
    int new_nr = this->getNr()*f2.getDr() + f2.getNr()*this->getDr();

    this->setNr(new_nr);
    this->setDr(lcm);
}

void Fraction ::multiply(Fraction &f2) {
    int new_nr = this->getNr() * f2.getNr();
    int new_dr = this->getDr() * f2.getDr();
    this->setNr(new_nr);
    this->setDr(new_dr);
}

void Fraction ::simplify() {
    int gcd = __gcd(this->getNr(), this->getDr());
    this->setNr(this->getNr() / gcd);
    this->setDr(this->getDr() / gcd);
}

void Fraction :: print(){
    cout << this->getNr() << "/" << this->getDr() << endl;
}

int main() {

    int Nr, Dr;
    cin >> Nr >> Dr;
    Fraction fObj = Fraction(Nr, Dr);

    int test;
    cin >> test;

    int query, qNr, qDr;
    while(test--){
        
        cin >> query >> qNr >> qDr;
        Fraction queryFrac = Fraction(qNr, qDr);

        switch(query){
            case 1:
                fObj.add(queryFrac);
                break;

            case 2:
                fObj.multiply(queryFrac);
                break;
        }
        fObj.simplify();
        fObj.print();
        // delete queryFrac;
    }

    return 0;
}