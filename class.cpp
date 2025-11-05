#include <iostream>
#include "class.h"

using namespace std;

int max_int = 100;
int min_int = -100;

    DynamicArray::DynamicArray(int a){
        size = a;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    DynamicArray::DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    DynamicArray::~DynamicArray(){
        delete[] data;
    }
    void DynamicArray::print_array(){
        for(int i = 0; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void DynamicArray::setter(int i, int value){
            if(value < min_int or value > max_int or i > size - 1){
                cout << "Invalid value" << endl;
            } else{
                data[i] = value;
            }
    }
    void DynamicArray::getter(int i){
        if(i > size){
            cout << "Invalid index" << endl;
        } else{
            cout << data[i];
        }
    }
    
    void DynamicArray::push(int value) {
        if(value < min_int || value > max_int) {
            cout << "Invalid value" << endl;
        } else{
            int* new_data = new int[size + 1];
            for(int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            new_data[size] = value;
            delete[] data;
            data = new_data;
            size++;
        }
    }

    void DynamicArray::add(DynamicArray& b){
        for(int i = 0; i < min(size, b.size); i++){
            data[i] += b.data[i];
        }
    }

    void DynamicArray::minus(DynamicArray& b){
        for(int i = 0; i < min(size, b.size); i++){
            data[i] -= b.data[i];
        }
    }