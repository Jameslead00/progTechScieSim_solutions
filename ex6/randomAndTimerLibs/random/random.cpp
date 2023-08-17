#include "random.hpp"

#include<limits>
#include <cassert>
#include <type_traits>

Generator::Generator(result_t x_0) : x_(x_0){}

Generator::result_t Generator::generate(){
    x_ = (a_ * x_ + c_) % m_;
    return static_cast<result_t>(x_);
}

Generator::result_t Generator::max() const{
    return static_cast<result_t>(m_);
}