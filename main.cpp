#include <iostream>
#include "class.h"
#include <random>

using namespace std;

int max_val = 100;
int min_val = -100;

class NewDynamicArray: public DynamicArray{
    public:
        NewDynamicArray(int size): DynamicArray(size){}
        double avg_value(){
            int sum = 0;
            for (int i = 0; i < size; i++){
                sum += data[i];
            }
            return sum / size;
        }
        NewDynamicArray* sort(){
            NewDynamicArray* sorted_array = new NewDynamicArray(size);
            for (int i = 0; i < size; i++){
                sorted_array->data[i] = data[i];
            }
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size - 1; j++){
                    if (sorted_array->data[j] > sorted_array->data[j + 1]){
                        swap(sorted_array->data[j], sorted_array->data[j + 1]);
                    }
                }
            }
            return sorted_array;
        }
        double median_value(){
            NewDynamicArray* sorted_array = sort();
            double result;
            if (size % 2 == 0){
                result = (sorted_array->data[size / 2] + sorted_array->data[size / 2 + 1]) / 2;
            } else {
                result = sorted_array->data[size / 2 + 1];
            }
            delete sorted_array;
            return result;
        }
        int min_value(){
            int min = data[0];
            for (int i = 1; i < size; i++){
                if (data[i] < min){
                    min = data[i];
                }
            }
            return min;
        }
        int max_value(){
            int max = data[0];
            for (int i = 1; i < size; i++){
                if (data[i] > max){
                    max = data[i];
                }
            }
            return max;
        }
};

int main(){
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    NewDynamicArray arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min_val, max_val);
    for (int i = 0; i < size; i++){
        arr.setter(i, dis(gen));
    }
    arr.print_array();
    cout << "Average value: " << arr.avg_value() << endl;
    cout << "Median value: " << arr.median_value() << endl;
    cout << "Min value: " << arr.min_value() << endl;
    cout << "Max value: " << arr.max_value() << endl;
    return 0;
}
