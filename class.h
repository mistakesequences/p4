#pragma once

class DynamicArray{
protected:
    int size;
    int* data;
public:
    DynamicArray(int a);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();
    void print_array();
    void setter(int i, int value);
    void getter(int i);
    
    void push(int value);

    void add(DynamicArray& b);

    void minus(DynamicArray& b);
};