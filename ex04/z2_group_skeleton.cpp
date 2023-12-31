/* Programming Techniques for Scientific Simulations, HS 2022
 * Exercise 4.1
 */

#include <complex>
#include <iostream>

enum Z2 { Plus, Minus };

template<class T>
T identity_element() { return T(1); }

// to be implemented: specialize the previous function for Z2
//template specializatuon for Z2
template<>
Z2 identity_element(){return Plus;}


Z2 operator*(const Z2 a, const Z2 b)
{
  // to be implemented (+*+=-*-=+; +*-=-*+=-)
  return (a==b ? Plus : Minus);
}

std::ostream& operator<<(std::ostream& os, const Z2 a)
{
  // to be implemented
  os << (a==Plus ? "Plus" : "Minus");
  return os;
}

template<class T>
T operator*(const T a, const Z2 b)
{
  // to be implemented
  return (b==Plus ? a : -a);
}

template<class T>
T operator*(const Z2 b, const T a)
{
  // to be implemented
  return (a * b);

}

template<class T>
T mypow(T a, unsigned int n)
{
  // to be implemented
  T result(identity_element<T>());
  while(n > 0){
    if(n%2 != 0){
      result = result * a;
      }
      n /= 2;
      a = a * a;
  } return result;
}

int main()
{
  // Some testing: feel free to add your own!
  std::cout << "Plus*Minus = " << Plus*Minus << std::endl;
  std::cout << "Plus*-1*Minus = " << Plus*-1*Minus << std::endl;
  std::cout << "(1.+3.)*mypow(Minus,4) = " << (1.+3.)*mypow(Minus,4)
            << std::endl;

  for (unsigned i=0; i<7; ++i)
    std::cout << "Plus^" << i << " = " << mypow(Plus,i) << std::endl;
  for (unsigned i=0; i<7; ++i)
    std::cout << "Minus^" << i << " = " << mypow(Minus,i) << std::endl;
  for (unsigned i=0; i<7; ++i)
    std::cout << "2^" << i << " = " << mypow(2.0,i) << std::endl;

  // For complex numbers
  std::cout << "Plus*-std::complex<double>(1., 2.)*Minus = "
            <<  Plus*-std::complex<double>(1., 2.)*Minus
            << std::endl;
  std::cout << "std::complex<double>(1., 1.)*mypow(Minus,4) = "
            <<  std::complex<double>(1., 1.)*mypow(Minus,4)
            << std::endl;
  for (unsigned i=0; i<7; ++i)
    std::cout << "std::complex<double>(1., 1.)^" << i << " = "
              << mypow(std::complex<double>(1., 1.),i)
              << std::endl;

  return 0;
}
