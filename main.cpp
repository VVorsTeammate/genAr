#include "ArrayHandler.h"
#include <chrono>
#include <random>

int main(){
    srand(time(NULL));

    ArrayHandler arrayHandler = ArrayHandler(5);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    // Реализовать заполнения массива на 1000000000
    for (long long int i = 0; i < 1000000000; i++) {
        arrayHandler.Append(rand() % 100);
    }
    // Продемонстрировать поиск элемента 
    std::cout << arrayHandler.GetIndexElem(18) << std::endl;
    // Продемонстрировать максимальный элемент 
    std::cout << arrayHandler.GetMax() << std::endl;
    // Продемонстрировать минимальный элемент
    std::cout << arrayHandler.GetMin() << std::endl;

    //std::cout << arrayHandler.GetDopCount() << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[mks]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    return 0;
}

