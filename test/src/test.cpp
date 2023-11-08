// #include <iostream>

// class Integer {

// public:

//     Integer(int const n);
//     ~Integer(void);

//     int getValue(void) const;

//     Integer& operator=(Integer const& rhs);
//     Integer operator+(Integer const& rhs) const;

// private:

//     int _n;
// };

// std::ostream& operator<<(std::ostream& o, Integer const& rhs);

// Integer::Integer(int const n) : _n(n) {
    
//     std::cout << "Constructor called with value " << n << std::endl;
//     return ;
// }

// Integer::~Integer(void) {

//     std::cout << "Destructor called with value " << this->_n << std::endl;
//     return ;
// }

// int Integer::getValue(void) const {

//     return this->_n;
// }

// Integer& Integer::operator=(Integer const& rhs) {
//     std::cout << "Assignation operator called from " << this->_n;
//     std::cout << " to " << rhs.getValue() << std::endl;

//     this->_n = rhs.getValue();

//     return *this;
// }

// Integer Integer::operator+(Integer const& rhs) const {

//     std::cout << "Addition operator called with " << this->_n;
//     std::cout << " and " << rhs.getValue() << std::endl;

//     return Integer(this->_n + rhs.getValue());
// }

// std::ostream& operator<<(std::ostream& o, Integer const& rhs) {

//     o << rhs.getValue();
//     return o;
// }

// int main(void) {

//     Integer x(30);
//     Integer y(10);
//     Integer z(0);

//     std::cout << "Value of x: " << x << std::endl;
//     std::cout << "Value of y: " << y << std::endl;
//     y = Integer(12);
//     std::cout << "Value of y: " << y << std::endl;

//     std::cout << "Value of z: " << z << std::endl;
//     z = x + y;
//     std::cout << "Value of z: " << z << std::endl;

//     return (0);
// }

/* ----------------------------- FORME CANONIQUE ---------------------------- */

// class Sample {

// public:
    
//     Sample(void);
//     Sample(int const n);
//     Sample(Sample const& src);
//     ~Sample(void);

//     Sample& operator=(Sample const& rhs);

//     int getFoo(void) const;

// private:
    
//     int _foo;
// };

// std::ostream& operator<<(std::ostream& o, Sample const& i);

/* -------------------------------------------------------------------------- */

// #include <iostream>
// #include <iomanip>
// #include <cstdint>

// int main() {
//     // Define a fixed-point type with 24 integer bits and 8 fractional bits
//     typedef std::int32_t FixedPoint; // 32 bits in total, 24 integer bits and 8 fractional bits

//     FixedPoint fixedValue = 1; // Example fixed-point value

//     // Display the fixed-point value as a floating-point value with 8 fractional digits
//     double floatingValue = static_cast<double>(fixedValue) / (1 << 8); // Right shift by 8 bits due to 8 fractional bits

//     // Set the output format to display 8 decimal places
//     std::cout << std::fixed << std::setprecision(8);

//     // Display the fixed-point value as a floating-point value
//     std::cout << "Fixed-point value: " << fixedValue << std::endl;
//     std::cout << "Floating-point value: " << floatingValue << std::endl;

//     return 0;
// }

/* -------------------------------------------------------------------------- */

//  https://www.youtube.com/watch?v=ZMsrZvBmQnU

/* -------------------------- Fixed Points Numbers -------------------------- */

// #include <iostream>

// template<size_t dp>
// constexpr int32_t doubleToFixed(double d) {
//     return int32_t(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
// }

// template<size_t dp>
// constexpr double fixedToDouble(int32_t d) {
//     return double(d) / double(1 << dp);
// }


// int main() {
//     constexpr int32_t a = doubleToFixed<16>(5.6);
//     constexpr int32_t b = doubleToFixed<16>(2.7);

//     constexpr int32_t c = a + b;
//     constexpr int32_t d = a - b;
    
//     constexpr double z = fixedToDouble<16>(c);
//     return (0);
// }


/* -------------------------------------------------------------------------- */

/* -------------------------------- TESTEX01 -------------------------------- */

// #include <iostream>
// #include <cmath>

// class Fixed {
// private:
//     int value;
//     static const int fractionalBits = 8;

// public:
//     Fixed() : value(0) {
//         std::cout << "Default constructor called" << std::endl;
//     }

//     Fixed(const int intValue) {
//         std::cout << "Int constructor called" << std::endl;
//         value = intValue << fractionalBits;
//     }

//     Fixed(const float floatValue) {
//         std::cout << "Float constructor called" << std::endl;
//         value = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
//     }

//     Fixed(const Fixed& other) : value(other.value) {
//         std::cout << "Copy constructor called" << std::endl;
//     }

//     Fixed& operator=(const Fixed& other) {
//         std::cout << "Copy assignment operator called" << std::endl;
//         if (this != &other) {
//             this->value = other.value;
//         }
//         return *this;
//     }

//     ~Fixed() {
//         std::cout << "Destructor called" << std::endl;
//     }

//     int getRawBits() const {
//         std::cout << "getRawBits member function called" << std::endl;
//         return value;
//     }

//     void setRawBits(int const raw) {
//         value = raw;
//     }

//     float toFloat() const {
//         return static_cast<float>(value) / (1 << fractionalBits);
//     }

//     int toInt() const {
//         return value >> fractionalBits;
//     }
// };

// std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
//     out << fixed.toFloat();
//     return out;
// }

// int main() {
//     Fixed a;
//     Fixed const b(10);
//     Fixed const c(42.42f);
//     Fixed const d(b);
//     a = Fixed(1234.4321f);

//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;

//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;

//     return 0;
// }

/* -------------------------------------------------------------------------- */

/* -------------------------------- TESTEX02 -------------------------------- */

// #include <iostream>
// #include <cmath>

// class Fixed {
// private:
//     int value;
//     static const int fractionalBits = 8;

// public:
//     Fixed() : value(0) {}

//     Fixed(const int intValue) {
//         value = intValue << fractionalBits;
//     }

//     Fixed(const float floatValue) {
//         value = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
//     }

//     Fixed(const Fixed& other) : value(other.value) {}

//     Fixed& operator=(const Fixed& other) {
//         if (this != &other) {
//             this->value = other.value;
//         }
//         return *this;
//     }

//     ~Fixed() {}

//     int getRawBits() const {
//         return value;
//     }

//     void setRawBits(int const raw) {
//         value = raw;
//     }

//     float toFloat() const {
//         return static_cast<float>(value) / (1 << fractionalBits);
//     }

//     int toInt() const {
//         return value >> fractionalBits;
//     }

//     // Comparison operators
//     bool operator>(const Fixed& other) const {
//         return value > other.value;
//     }

//     bool operator<(const Fixed& other) const {
//         return value < other.value;
//     }

//     bool operator>=(const Fixed& other) const {
//         return value >= other.value;
//     }

//     bool operator<=(const Fixed& other) const {
//         return value <= other.value;
//     }

//     bool operator==(const Fixed& other) const {
//         return value == other.value;
//     }

//     bool operator!=(const Fixed& other) const {
//         return value != other.value;
//     }

//     // Arithmetic operators
//     Fixed operator+(const Fixed& other) const {
//         return Fixed(this->toFloat() + other.toFloat());
//     }

//     Fixed operator-(const Fixed& other) const {
//         return Fixed(this->toFloat() - other.toFloat());
//     }

//     Fixed operator*(const Fixed& other) const {
//         return Fixed(this->toFloat() * other.toFloat());
//     }

//     Fixed operator/(const Fixed& other) const {
//         return Fixed(this->toFloat() / other.toFloat());
//     }

//     // Increment/Decrement operators
//     Fixed &operator++() {
//         value += 1;
//         return *this;
//     }

//     Fixed operator++(int) {
//         Fixed temp(*this);
//         ++(*this);
//         return temp;
//     }

//     Fixed &operator--() {
//         value -= 1;
//         return *this;
//     }

//     Fixed operator--(int) {
//         Fixed temp(*this);
//         --(*this);
//         return temp;
//     }

//     static Fixed& min(Fixed& a, Fixed& b) {
//         return (a < b) ? a : b;
//     }

//     static const Fixed& min(const Fixed& a, const Fixed& b) {
//         return (a < b) ? a : b;
//     }

//     static Fixed& max(Fixed& a, Fixed& b) {
//         return (a > b) ? a : b;
//     }

//     static const Fixed& max(const Fixed& a, const Fixed& b) {
//         return (a > b) ? a : b;
//     }
// };

// std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
//     out << fixed.toFloat();
//     return out;
// }

// int main() {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;

//     return 0;
// }

/* -------------------------------------------------------------------------- */

// #ifndef FIXED_HPP
// #define FIXED_HPP

// #include <iostream>
// #include <cmath>

// class Fixed {
// private:
//     int value;
//     static const int fractionalBits = 8;

// public:
//     Fixed();
//     Fixed(const int intValue);
//     Fixed(const float floatValue);
//     Fixed(const Fixed& other);
//     Fixed& operator=(const Fixed& other);
//     ~Fixed();

//     int getRawBits() const;
//     void setRawBits(int const raw);
//     float toFloat() const;
//     int toInt() const;

//     bool operator>(const Fixed& other) const;
//     bool operator<(const Fixed& other) const;
//     bool operator>=(const Fixed& other) const;
//     bool operator<=(const Fixed& other) const;
//     bool operator==(const Fixed& other) const;
//     bool operator!=(const Fixed& other) const;

//     Fixed operator+(const Fixed& other) const;
//     Fixed operator-(const Fixed& other) const;
//     Fixed operator*(const Fixed& other) const;
//     Fixed operator/(const Fixed& other) const;

//     Fixed& operator++();
//     Fixed operator++(int);
//     Fixed& operator--();
//     Fixed operator--(int);

//     static Fixed& min(Fixed& a, Fixed& b);
//     static const Fixed& min(const Fixed& a, const Fixed& b);
//     static Fixed& max(Fixed& a, Fixed& b);
//     static const Fixed& max(const Fixed& a, const Fixed& b);
// };

// std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

// #endif // FIXED_HPP

// Fixed::Fixed() : value(0) {}

// Fixed::Fixed(const int intValue) {
//     value = intValue << fractionalBits;
// }

// Fixed::Fixed(const float floatValue) {
//     value = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
// }

// Fixed::Fixed(const Fixed& other) : value(other.value) {}

// Fixed& Fixed::operator=(const Fixed& other) {
//     if (this != &other) {
//         this->value = other.value;
//     }
//     return *this;
// }

// Fixed::~Fixed() {}

// int Fixed::getRawBits() const {
//     return value;
// }

// void Fixed::setRawBits(int const raw) {
//     value = raw;
// }

// float Fixed::toFloat() const {
//     return static_cast<float>(value) / (1 << fractionalBits);
// }

// int Fixed::toInt() const {
//     return value >> fractionalBits;
// }

// bool Fixed::operator>(const Fixed& other) const {
//     return value > other.value;
// }

// bool Fixed::operator<(const Fixed& other) const {
//     return value < other.value;
// }

// bool Fixed::operator>=(const Fixed& other) const {
//     return value >= other.value;
// }

// bool Fixed::operator<=(const Fixed& other) const {
//     return value <= other.value;
// }

// bool Fixed::operator==(const Fixed& other) const {
//     return value == other.value;
// }

// bool Fixed::operator!=(const Fixed& other) const {
//     return value != other.value;
// }

// Fixed Fixed::operator+(const Fixed& other) const {
//     return Fixed(this->toFloat() + other.toFloat());
// }

// Fixed Fixed::operator-(const Fixed& other) const {
//     return Fixed(this->toFloat() - other.toFloat());
// }

// Fixed Fixed::operator*(const Fixed& other) const {
//     return Fixed(this->toFloat() * other.toFloat());
// }

// Fixed Fixed::operator/(const Fixed& other) const {
//     return Fixed(this->toFloat() / other.toFloat());
// }

// Fixed& Fixed::operator++() {
//     value += 1;
//     return *this;
// }

// Fixed Fixed::operator++(int) {
//     Fixed temp(*this);
//     ++(*this);
//     return temp;
// }

// Fixed& Fixed::operator--() {
//     value -= 1;
//     return *this;
// }

// Fixed Fixed::operator--(int) {
//     Fixed temp(*this);
//     --(*this);
//     return temp;
// }

// Fixed& Fixed::min(Fixed& a, Fixed& b) {
//     return (a < b) ? a : b;
// }

// const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
//     return (a < b) ? a : b;
// }

// Fixed& Fixed::max(Fixed& a, Fixed& b) {
//     return (a > b) ? a : b;
// }

// const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
//     return (a > b) ? a : b;
// }

// std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
//     out << fixed.toFloat();
//     return out;
// }

// #include <iostream>

// int main() {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;

//     return 0;
// }
