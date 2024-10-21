/**
 * @file DynamicArray.h
 * @brief Declaration of the DynamicArray and DynamicArrayVector classes for dynamic arrays management.
 */
#pragma once

#include <iostream>
#include <vector>

/**
 * @namespace oop
 * @brief oop namespace that contains all the classes and functions related to Object Oriented Programming (OOP).
 */
namespace oop{

    /**
     * @class DynamicArrayVector
     * @brief A class that represents a dynamic array implemented using std::vector instead of raw pointers for memory management.
     */
    class DynamicArrayVector{
    private:
        
        int* ptr; // ptr to the memory allocated to the array
        int arrSize; // size of the array

        std::vector<int> array;

    public:
    
        /**
         * @brief Constructor that takes int and initializes array with that size
         * @param size Size of the array to be initialized
         */
        DynamicArrayVector(int size) : array(size, 0){}

        /**
         * @brief Constructor that takes size and values to initialize
         * @param size Size of the array
         */
        DynamicArrayVector(int size, int value) : array(size, value){}

        /**
         * @brief size method returns the size of the dynamic array.
         * @return The size of the array.
         */
        int size() const {
            return array.size();
        }

        /**
         * @brief Overloading [] operator to access elements at index or modify elements in the array.
         * @param index Index of the element to be accessed.
         * @return Reference to the element at the given index.
         */
        int& operator[](int index) {

            return array[index]; // returns reference to the element at index
        }

        /**
         * @brief Addition operator to concatenate two arrays
         * @param other The second DynamicArrayVector to be concatenated.
         * @return A new DynamicArrayVector containing elements from both arrays.
         */
        DynamicArrayVector operator+(const DynamicArrayVector& other) const{
            DynamicArrayVector result(0); // initialize new result array size 0

            // Insert the current array's elements into result
            result.array.insert(result.array.begin(), array.begin(), array.end());

            // Insert the other array's elements into result
            result.array.insert(result.array.end(), other.array.begin(), other.array.end());

            return result;
        }

        /**
         * @brief Operator overloading on ostream, implementing operator as a free function to access private variables
         * @param os Output stream object.
         * @param other DynamicArrayVector to be printed.
         * @return Output stream object.
         */
        friend std::ostream& operator<<(std::ostream& os, const DynamicArrayVector& other) {
            os << "[";
            for(int i=0; i<other.array.size();i++){
                os << other.array[i];
                if (i!=other.array.size()-1){
                    os << ", ";
                } 
            }
            os << "]";
            return os;

        }

    };


    /**
     * @class DynamicArray
     * @brief A class that represents a dynamic array implemented using raw pointers for memory management.
     */

    class DynamicArray{
    private:
        int* ptr; /**< ptr to the memory allocated to the array. */
        int arrSize; /**< size of the array. */

    public:
        /**
         * @brief Constructor that takes int and initializes array with that size
         * @param size Size of the array to be initialized
         */
        // Constructor that takes int and initializes array with that size
        DynamicArray(int size) : arrSize(size){
            ptr = new int[arrSize](); // allocates heap memory for an array of int filles with 0 with ()
        }

        /**
         * @brief Constructor that takes size and values to initialize
         * @param size Size of the array
         * @param value Value to initialize all elements in te array
         * 
         */
        // Constructor that takes size and values to initialize
        DynamicArray(int size, int value) : arrSize(size){
            ptr = new int[arrSize];
            for(int i=0; i < arrSize; i++){
                ptr[i] = value;
            }
        }

        /**
         * @brief Destructor to deallocate memory occupied by int array
         */
        // Destructor to deallocate memory occupied by int array
        ~DynamicArray(){
            delete[] ptr;
        }

        /**
         * @brief Copy Constructor: makes object from copy of other object (DynamicArray obj2(obj1);)
         * @param other Dynamic array to be copied
         */
        // Copy Constructor: makes object from copy of other object (DynamicArray obj2(obj1);)
        DynamicArray(const DynamicArray& other) : arrSize(other.arrSize) {
            ptr = new int[arrSize];
            for(int i=0; i<arrSize; i++){
                ptr[i] = other.ptr[i];
            }
        }

        /**
         * @brief Copy Assignment Operator: makes object from copy of other object using = (DynamicArray obj2 = obj1)
         * @param other Dynamic array to be copied
         * @return returns reference to modified array 
         */
        // Copy Assignment Operator: makes object from copy of other object using = (DynamicArray obj2 = obj1)
        DynamicArray& operator=(const DynamicArray& other){
            if (this != &other){
                arrSize = other.arrSize;
                ptr = new int[arrSize];
                for(int i=0; i<arrSize; i++){
                    ptr[i] = other.ptr[i];
                }          
            } 
            return *this;
        }

        /**
         * @brief Move Constructor steals the data from the other object
         * @param other Dynamic array to be moved
         */
        // Move Constructor steals the data from the other object
        DynamicArray(DynamicArray&& other) : ptr(other.ptr), arrSize(other.arrSize){
            other.ptr = nullptr;
            other.arrSize = 0;
        }
        /**
         * @brief Move Assignment Operator
         * @param other dynamic array to be moved
         * @return reference to the modified Dynamic array
         */
        // Move Assignment Operator
        DynamicArray& operator=(DynamicArray&& other) noexcept{
            if (this!= &other) {
                ptr = other.ptr;
                arrSize = other.arrSize;
                other.ptr = nullptr;
                other.arrSize = 0;
            }
            return *this;
        }

        /**
         * @brief Returns the size of the dynamic array.
         * @return The size of the array.
         */
        // Method returns array size
        int size() const {
            return arrSize;
        }

        /**
         * @brief Overloading [] operator to access elements at index or modify elements in the array.
         * @param index Index of the element to be accessed.
         * @return Reference to the element at the given index.
         */
        // Overloading [] operator to access elements at index
        int& operator[](int index) {
            return ptr[index]; // returns reference to the element at index
        }

        /**
         * @brief Addition operator to concatenate two arrays
         * @param other The second DynamicArray to be concatenated.
         * @return A new DynamicArray containing elements from both arrays.
         */
        // Addition operator to concatenate two arrays
        DynamicArray operator+(const DynamicArray& other) const{
            DynamicArray result(arrSize + other.arrSize); // creates new result array with size of the sum of both

            // Copying elements from input arrays to result array in corresponding index
            for(int i=0; i<arrSize; i++){
                result.ptr[i] = ptr[i];
            }

            for(int i=0; i<other.arrSize; i++){
                result.ptr[arrSize + i] = other.ptr[i];
            }

            return result;
        }

        /**
         * @brief Operator overloading on ostream, implementing operator as a free function to access private variables
         * @param os Output stream object.
         * @param other DynamicArray to be printed.
         * @return Output stream object.
         */
        // Operator overloading on ostream, implementing operator as a free function to access private variables
        friend std::ostream& operator<<(std::ostream& os, const DynamicArray& other) {
            os << "[";
            for(int i=0; i<other.arrSize;i++){
                os << other.ptr[i];
                if (i!=other.arrSize - 1){
                    os << ", ";
                } 
            }
            os << "]";
            return os;

        }

    };


}