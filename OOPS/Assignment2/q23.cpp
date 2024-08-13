#include <iostream>

class Complex {
private:
    float real;
    float imag;

public:
    void setReal(float r) {
        real = r;
    }

    void setImag(float i) {
        imag = i;
    }

    float getReal() const {
        return real;
    }

    float getImag() const {
        return imag;
    }

    Complex sum(const Complex& other) const {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    void disp() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1, c2, c3;

    c1.setReal(1.1);
    c1.setImag(2.2);

    c2.setReal(3.3);
    c2.setImag(4.4);

    c3 = c1.sum(c2);

    std::cout << "c1: ";
    c1.disp();

    std::cout << "c2: ";
    c2.disp();

    std::cout << "c3 (sum of c1 and c2): ";
    c3.disp();

    return 0;
}
