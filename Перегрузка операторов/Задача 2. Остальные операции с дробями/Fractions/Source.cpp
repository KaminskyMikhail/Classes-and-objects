#include <iostream>
#include <algorithm> 
#include<numeric>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    void reduce()
    {
        if (denominator_ == 0) return;

        int gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;

        if (denominator_ < 0)
        {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator)
    {
        reduce();
    }

    bool operator==(const Fraction& other) const
    {
        return numerator_ * other.denominator_ == other.numerator_ * denominator_;
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const
    {
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    bool operator>(const Fraction& other) const
    {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const
    {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const
    {
        return !(*this < other);
    }

  
    Fraction operator+(const Fraction& other) const
    {
        int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const
    {
        int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction operator-() const
    {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++()
    {
        numerator_ += denominator_; 
        reduce();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        numerator_ += denominator_;
        reduce();
        return temp;
    }

    Fraction& operator--()
    {
        numerator_ -= denominator_; 
        reduce();
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        numerator_ -= denominator_;
        reduce();
        return temp;
    }

    int getNumerator() const { return numerator_; }
    int getDenominator() const { return denominator_; }
};

int main()
{
    int num1, den1, num2, den2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    std::cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = "
        << (f1 + f2).getNumerator() << "/" << (f1 + f2).getDenominator() << '\n';

    std::cout << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = "
        << (f1 - f2).getNumerator() << "/" << (f1 - f2).getDenominator() << '\n';

    std::cout << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = "
        << (f1 * f2).getNumerator() << "/" << (f1 * f2).getDenominator() << '\n';

    std::cout << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = "
        << (f1 / f2).getNumerator() << "/" << (f1 / f2).getDenominator() << '\n';

    Fraction temp = f1;
    Fraction result = ++temp * f2;
    std::cout << "++" << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = "
        << result.getNumerator() << "/" << result.getDenominator() << '\n';
    std::cout << "Значение дроби 1 = " << temp.getNumerator() << "/" << temp.getDenominator() << '\n';

    temp = f1;
    result = temp-- * f2;
    std::cout << temp.getNumerator() << "/" << temp.getDenominator() << "-- * " << num2 << "/" << den2 << " = "
        << result.getNumerator() << "/" << result.getDenominator() << '\n';
    std::cout << "Значени дроби 1 = " << temp.getNumerator() << "/" << temp.getDenominator() << '\n';

    return 0;
}