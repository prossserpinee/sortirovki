#include <iostream>
#include <random>
#include <ctime>


void swap(int* first, int* second) { //funcion menyaet mestami elementy massiva
	int temp = *first; 
	*first = *second;
	*second = temp;
}

int* fillArray(int* array, int i) { //funcion zapolnyaet massiv chislami ot 1 do 20
	for (int j = 0; j < i; j++) {
		array[j] = 1 + rand() % 20;
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

int partition(int arr[], int low, int high) { //function dlya razdelenia massiva
	int pivot_index = low + rand() % (high - low + 1); 
	int pivot = arr[pivot_index];
	swap(&arr[pivot_index], &arr[high]);

	int x = (low - 1);

	for (int y = low; y <= high - 1; y++) {

		if (arr[y] < pivot) {
			x++;
			swap(&arr[x], &arr[y]);
		}
	}
	swap(&arr[x + 1], &arr[high]);
	return (x + 1);
}

void quickSort(int arr[], int low, int high) { //function dlya sortirovki 
	if (low < high) {
		int array_partition = partition(arr, low, high); 

		quickSort(arr, low, array_partition - 1);
		quickSort(arr, array_partition + 1, high);
	}
}

void printArray(int arr[], int size) //function vivoda massiva
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));
	for (int n = 1000000; n < 2000000; n = n + 10000) {
		std::clock_t start = std::clock();

		int* array{ new int[n] }; //создание динамического массива
		array = memory(n);

		fillArray(array, n); //заполнение массива

		int size = sizeof(array);

		quickSort(array, 0, size - 1); //применение функции

		std::clock_t end = std::clock();

		double search_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		std::cout << n << " " << search_time << std::endl;

		dlt(array);
	}


	return 0;
}

*/