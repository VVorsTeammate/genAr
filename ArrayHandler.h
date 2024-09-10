#include <cstdint>
#include <cstring>
#include <iostream>

class ArrayHandler {
private:
    char* _array;
    char* _dop_arr;
    char _max;
    char _min;
    int _dop_count = 0;
    //long long int _dop_count = 0;
    long long int _size;
    long long int _count;
public:
    ArrayHandler(long long int size = 10){
        _size = size;
        _dop_arr = new char[100];
        _array = new char[_size];
        _max = -128;
        _min = 127;
        _count = 0;
        for(int i = 0; i < 100; i++){ //o(C)
            _dop_arr[i] = -1;
            //_dop_count++;
        }
    }
    void Append(char new_element){
        //_dop_count++;
        if (_count == _size) { //o(n)
            //_dop_count++;
            _size = _size * 4; //o(C)
            char* new_arr = new char[_size]; //o(C)
            std::memcpy(new_arr, _array, _count*sizeof(char)); //o(C)
            delete [] _array; //o(C)
            _array = new_arr; //o(C)
        }
        //_dop_count++;
        _array[_count] = new_element; //o(n)
        //_dop_count++;
        if(_dop_count < 99){
            if(_dop_arr[new_element] == -1){ //o(n)
                _dop_arr[new_element] = _count;// o(C)
                _dop_count ++;
            }
        }
        _count++; //o(n)
        //_dop_count++;
        //_dop_count++;
        if(new_element > _max){ //o(k)          //
                _max = new_element;             // //
            }                                   // // // o(n)
        else if(new_element < _min){ //o(n-k)   // //
            _min = new_element;                 //
        }
    }
    int GetMax(){
        return _max; //o(1)
    }
    int GetMin(){
        return _min; //o(1)
    }
    int GetIndexElem(int elem){
        return _dop_arr[elem]; //o(1)
    }
    // long long int GetDopCount(){
    //     return _dop_count; //o(1)
    // }
    ~ArrayHandler() {
        delete [] _array;
        delete [] _dop_arr;
    }
};

