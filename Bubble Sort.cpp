#include <iostream>
#include <random>



int* fillArray(int* array, int i) {//funcion zapolnyaet massiv chislami ot 1 do 50
	for (int j = 0; j < i; j++) {
		array[j] = 1 + rand() % 50;
	}
	return array;
}

void dlt(int* array) { //osvobozhdenie pamyati posle iteratsii massiva
	delete[] array;
	array = nullptr;
}

int* memory(int n) { //videlenie payati pod massiv
	return new int[n];
}

void printArray(int arr[], int size){ //function vivoda massiva
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void swap(int* first, int* second){//funcion menyaet mestami elementy massiva
	int temp = *first;
	*first = *second;
	*second = temp;
}

void BubbleSort(int* arr, int n){ //function dlya sortirovki
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}


int main() {
	srand(time(NULL));
	for (int n = 1000; n < 20000; n = n + 100) {
		std::clock_t start = std::clock();

		int* array{ new int[n] };
		array = memory(n);

		fillArray(array, n);
		
		BubbleSort(array, n);

		std::clock_t end = std::clock();

		double search_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		std::cout << n << " " << search_time << std::endl;

		dlt(array);

		
	}
	return 0;
}

