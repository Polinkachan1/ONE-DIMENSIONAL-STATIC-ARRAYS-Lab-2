#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

static void from_small_to_big_2(short arr[],int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			};
		};
	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ ВНУТРИ ФУНКЦИИ"<< endl;
	for (int a = 0; a < N; a++) {
		cout << arr[a] << ' ';
	};
	cout << endl;
};

static void max_min_elems_of_arr_3(short arr[], short not_sort[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	// несортированный массив
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1 - j; i++) {
			if (not_sort[i] > not_sort[i + 1]) {
				swap(not_sort[i], not_sort[i + 1]);
			};
		};
	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ С НЕСОРТИРОВАННЫМ МАССИВОМ" << endl;
	cout << "Максимальный и минимальный элементы для неотсортированного массива" << not_sort[0] << ' ' << not_sort[N - 1] << endl;
	// для отсортированного массива
	int max;
	int min;
	start = steady_clock::now();
	min = arr[0];
    max = arr[N - 1];
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "Нахождение заданных элементов заняло: "<< result.count() << " наносекунд" << endl;
	cout << "Максимальный и минимальный элементы для отсортированного массива" << min << ' ' << max << endl;

};

static void median_of_arr_4(short arr[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	int srednee_znachenie = (arr[0] + arr[N - 1]) / 2;
	cout << "среднее от min и max " << srednee_znachenie << endl;
	int counter = 0;
	cout << "Под каким номером есть такое же число как среднее: ";
	start = steady_clock::now();
	for (int i = 0; i < N; i++) {
		if (arr[i] == srednee_znachenie) {
			cout << i << endl;
			counter += 1;
		}

	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "Нахождение заданных элементов заняло: " << result.count() << " наносекунд" << endl;
	if (counter == 0) {
		cout << "ничего не найдено";
	}
	else {
		cout << "Всего найдено чисел: " << counter << endl;
	};
}


static void smaller_num_counter_5(short arr[], int N) {
	int num;
	int count = 0;
	cout << "ВВЕДИТЕ ЧИСЛО: ";
	cin >> num;
	cout << "ЧИСЛА МЕНЬШЕ ЧЕМ " << num << ": ";
	for (int a = 0; a < N; a++) {
		if (num > arr[a]) {
			cout << arr[a] << ' ';
			count += 1;
		}
	};
	if (count == 0) {
		cout << "НЕ НАЙДЕНО";
	};
	cout << endl;
	cout << "КОЛИЧЕСТВО ЧИСЕЛ МЕНЬШЕ ЧЕМ " << num << " РАВНО " << count << endl;
};

static void bigger_num_counter_6(short arr[], int N) {
	int num2;
	int count_2 = 0;
	cout << "ВВЕДИТЕ ЧИСЛО: ";
	cin >> num2;
	cout << "ЧИСЛА БОЛЬШЕ ЧЕМ " << num2 << ": ";
	for (int a = 0; a < N; a++) {
		if (num2 < arr[a]) {
			cout << arr[a] << ' ';
			count_2 += 1;
		}
	};
	if (count_2 == 0) {
		cout << "НЕ НАЙДЕНО";
	};
	cout << endl;
	cout << "КОЛИЧЕСТВО ЧИСЕЛ БОЛЬШЕ ЧЕМ " << num2 << " РАВНО " << count_2<< endl;
};

int binarySearch(short arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}

		return binarySearch(arr, value, mid + 1, end);
	}

	return -1;
};
static void find_number_in_arr_7(short arr[], int N) {
	int num3;
	int count_3 = 0;
	cout << "ВВЕДИТЕ ЧИСЛО ДЛЯ ЗАДАНИЯ 7: ";
	cin >> num3;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	cout << endl;
	// полный перебор
	for (int a = 0; a < N; a++) {
		if (num3 == arr[a]) {
			end = steady_clock::now();
			cout << "ВВЕДЕННОЕ ЧИСЛО ЕСТЬ В МАССИВЕ!" << endl;
			break;
		};
	};
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << "наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ ОБЫЧНЫМ ПЕРЕБОРОМ";
	cout << endl;
	start = steady_clock::now();
	// бинарный поиск
	int binary_res = binarySearch(arr, num3, 0, N-1);
	end = steady_clock::now();
	cout << binary_res;
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << "наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ БИНАРНЫМ ПОИСКОМ";
	
};

static void change_elems_of_arr_8(short arr[], int N) {
	int elem_index_1;
	int elem_index_2;
	cout << "Введи индексы, которые хочешь поменять в массиве:";
	cin >> elem_index_1;
	cout << endl;
	cin >> elem_index_2;
	swap(arr[elem_index_1], arr[elem_index_2]);
	cout << "НУ ВОТ И ПОМЕНЯЛИСЬ" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	};
};


int main()
{
	setlocale(0, "");
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	// 1)Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.
	const int N = 100;
	unsigned identificator;
	short Array[N];
	short not_sorted_array[N];
	unsigned int start_val = -99;
	int end_val = 99;
	srand(time(0));
	cout << "Сгенерированный массив: " << endl;
	for (int i = 0; i < N; i++) {
		Array[i] = rand() % (end_val - start_val + 1) + start_val;
		not_sorted_array[i] = Array[i];
		cout << Array[i] << ' ';
	};
	cout << endl;
	cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ( для завершения нажмите 9, чтобы перегенирировать массив нажмите 1) ";
	cin >> identificator;
	switch (identificator)
	{
	    case 1:
			cout << "Новый массив" << endl;
			for (int i = 0; i < N; i++) {
				Array[i] = rand() % (end_val - start_val + 1) + start_val;
				not_sorted_array[i] = Array[i];
				cout << Array[i] << ' ';
			};
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;

		case 2:
			cout << "Сортировка от меньшего к большему" << endl;
			from_small_to_big_2(Array, N);
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 3:
			max_min_elems_of_arr_3(Array, not_sorted_array, N);
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 4:
			median_of_arr_4(Array, N);
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 5:
			smaller_num_counter_5(Array, N);
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 6:
			bigger_num_counter_6(Array, N);
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 7:
			find_number_in_arr_7(Array, N);
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 8:
			change_elems_of_arr_8(Array, N);
			cout << endl;
			cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ ";
			cin >> identificator;
		case 9:
			return 0;
	}
}
