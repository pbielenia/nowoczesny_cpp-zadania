#pragma once

#include <vector>

#include <iostream>

template<typename T, unsigned R, unsigned C>
class Array2D {
public:
    Array2D()
        : elements(number_of_elements) { }

    Array2D(std::initializer_list<T> elements)
        : elements(elements) {  }

private:
    unsigned number_of_elements{R * C};
    std::vector<T> elements;

};
