#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>        
#include <initializer_list>
#include <stdexcept>      
#include <algorithm>    
#include <iostream>  
#include <limits>

namespace my_std {
template<typename T>
class Vector {
public:
    // Member Types
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using reference_refer = reference&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    // Constructors and Destructor

    Vector(); // ++
    explicit Vector(size_type count); //++
    Vector(size_type count, const_reference value); //++
    Vector(std::initializer_list<value_type> init); //++
    Vector(const Vector& other); //++
    Vector(Vector&& other) noexcept; //++
    ~Vector(); //++

    // Assignment Operators
    Vector& operator=(const Vector& other); //++
    Vector& operator=(Vector&& other) noexcept; //++
    Vector& operator=(std::initializer_list<value_type> list); //++

    // Element Access
    reference at(size_type pos); //++
    const_reference at(size_type pos) const; //++

    reference operator[](size_type pos); //++
    const_reference operator[](size_type pos) const; //++

    reference front(); //++
    const_reference front() const; //++

    reference back(); //++
    const_reference back() const; //++

    pointer data() noexcept; // ++
    const_pointer data() const noexcept; //++

    pointer begin(); //++
    const_pointer begin() const; //++
    const_pointer cbegin() const noexcept; //++


    pointer end() noexcept; //++
    const_pointer end() const noexcept; //++
    const_pointer cend() const noexcept; //++

    // Iterators

    pointer rbegin() noexcept; //++
    const_pointer rbegin() const noexcept; //++
    const_pointer crbegin() const noexcept; //++

    pointer rend() noexcept; //++
    const_pointer rend() const noexcept; //++
    const_pointer crend() const noexcept; //++

    // Capacity
    bool empty() const noexcept; // ++
    size_type size() const noexcept; // ++
    size_type capacity() const noexcept; // ++
    std::size_t max_size()  noexcept; // ++
    void reserve(size_type new_cap); // ++ 
    void shrink_to_fit(); // ++

    // Modifiers
    void clear() noexcept; //++
    void push_back(const_reference value); //++
    void push_back(reference_refer value); //++
    void pop_back(); //++
    void resize(size_type count); //++
    void resize(size_type count, const_reference value); //++
    void swap(Vector& other) noexcept; //++
    void insert(size_type pos, const_reference value); //++
    void insert(size_type pos, reference_refer value); //++
    void insert(size_type pos, size_type count,const_reference value); //++
    void insert(size_type pos, std::initializer_list<value_type> ilist); //++
    void erase(size_type pos); //++
    void erase(size_type first, size_type last); //++
    
    // Equality operators
    bool operator==(const Vector& other) const; // ++
    bool operator!=(const Vector& other) const;  // ++

    // Relational operators
    bool operator<(const Vector& other) const; // ++
    bool operator>(const Vector& other) const; // ++
    bool operator<=(const Vector& other) const; // ++
    bool operator>=(const Vector& other) const; // ++

    // Addition operator (vector concatenation)
    Vector operator+(const Vector& other) const; //++

    // Addition assignment operator
    Vector& operator+=(const Vector& other); //++

    // Operator cast to bool
    explicit operator bool() const noexcept; //++

    // Friend Functions

    friend void swap(Vector& lhs, Vector& rhs) noexcept {
        lhs.swap(rhs);
    } //++

private:
    // Private Member Variables

    pointer m_data;        // Pointer to the dynamic array
    size_type m_size;      // Number of elements
    size_type m_capacity;  // Allocated capacity

    // Private Member Functions

    void reallocate(size_type new_capacity); //++
    // void destroy_elements();
    // void copy_from(const Vector& other);
    // void move_from(Vector&& other) noexcept;
};

} // namespace my_std

#include "vector.tcc"

#endif // VECTOR_H