#include <iostream>
#include <ctime>


int* fill(int* array, int i) {  //funcion zapolnyaet massiv chislami ot 1 do 20
    for (int j = 0; j < i; j++) {
        array[j] = 1 + rand() % 20; 
    }
    return array;
}

void dlt(int* array) { //osvobozhdenie pamyati pod massiv
    delete[] array;
    array = nullptr;
}

int* memory(int n) { //videlenie payati pod massiv
    return new int[n];
}


void insertionSort(int arr[], int n) //function dlya sortirovki
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int arr[], int n){ //function vivoda massiva
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main(){ 
    for (int n = 10000; n < 200000; n = n + 10000) {
        std::clock_t start = std::clock();

        int* array{ new int[n] };
        array = memory(n);


        fill(array, n);

        insertionSort(array, n);

        std::clock_t end = std::clock();

        double search_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        std::cout << n << " " << search_time << std::endl;

        dlt(array);
    }

    return 0;

}

