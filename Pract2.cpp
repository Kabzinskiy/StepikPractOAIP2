#include <iostream>
#include <ctime>
#include <cstdlib>



using std::cout;
using std::cin;
using std::endl;

void generate_arr(int *, int);
void print_arr(int *, int);
void bubble_sort(int *, int);
void shaker_sort(int *, int);
void insert_sort(int *, int);
void comb_sort(int *, int);
void quick_sort(int*, int, int);
void quick_sort_real(int*, int, int);
int min_of_arr(int *, int);
int max_of_arr(int *, int);
bool bin_search(int *, int, int, int);
void big_value(int *, int);
void min_value(int *, int);
void cout_mid(int *, int);
void swap(int *, int, int);
void generate_arr(int *, int);
void menu();



void main(){

	setlocale(LC_ALL, "Russian");
	const int n = 100;
	int ARR[n], change;
	generate_arr(ARR, n);

	for (;;)
	{
		menu();
		cin >> change;
		if (change == 1)
		{
			generate_arr(ARR, n);
		}
		else if (change == 2){
			bubble_sort(ARR, n);
		}
		else if (change == 3){
			shaker_sort(ARR, n);
		}
		else if (change == 4){
			insert_sort(ARR, n);
		}
		else if (change == 5){
			comb_sort(ARR, n);
		}
		else if (change == 6){
			quick_sort(ARR, n-1, 0);
		}
		else if (change == 7){
			min_value(ARR, n);
		}
		else if (change == 8){
			big_value(ARR, n);
		}
		else if (change == 9){
			cout << "Минимальное число массива - " << min_of_arr(ARR, n);
		}
		else if (change == 10){
			cout << "Максимальное число массива - " << max_of_arr(ARR, n);
		}
		else if (change == 11){
			cout << "Введите искомое число." << endl;
			int val;
			cin >> val;
			if (bin_search(ARR, n, 0, val))
			{
				cout << "Введенное число есть в массиве." << endl;
			}
			else
			{
				cout << "Введенного числа нет в массиве." << endl;
			}
		}
		else if (change == 12){
			cout << "Введите индексы меняемых элементов." << endl;
			int val1, val2;
			cin >> val1 >> val2;
			swap(ARR, val1, val2);
		}
		else if (change == 13){
			cout_mid(ARR, n);
		}
		else if (change == 14){
			print_arr(ARR, n);
		}
		else if (change == 15){
			break;
		}
	}

	system("pause");
	
}

void menu(){
	cout << endl << "1 - Сгенерировать массив заново." << endl << "2 - Отсортировать пузырьком." << endl
		<< "3 - Отсортировать шейкером." << endl << "4 - Отсротировать вставками." << endl << "5 - Отсортировать расческой." << endl
		<< "6 - Отсортировать быстрой сортировкой." << endl << "7 - Функция подсчета чисел меньше введеного." << endl
		<< "8 - Функция подсчета чисел больше введеного." << endl << "9 - Минимальное число массива." << endl
		<< "10 - Максимальное число массива." << endl << "11 - Подтверждает наличие числа в массиве. (Бинарный поиск.)" << endl
		<< "12 - Поменять местами элементы." << endl << "13 - Среднее число массива." << endl
		<< "14 - Вывести массив." << endl << "15 - Выход." << endl;
}

void generate_arr(int *arr, int kol){
	srand(time(0));
	for (int i = 0; i < kol; i++){
		arr[i] = rand() % 198 - 99;
	}
	cout << "Массив сгенерирован." << endl;
}

void print_arr(int *arr, int kol){
	for (int i = 0; i < kol; i++){
		cout << i << " = " << arr[i] << endl;
	}
}

void swap(int *arr, int first, int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void bubble_sort(int *arr, int kol){

	unsigned int start_time = clock();
	

	for (int i = 0, z=kol-1; i < kol-2; ++i, --z)
	{
		for (int c = 0; c < z; ++c){
			if (arr[c] > arr[c+1]){
				swap(arr, c, (c + 1));
			}
		}

	}

	unsigned int end_time = clock();
	cout << "Время сортировки пузырьком = " << (end_time - start_time) << endl;
}

void shaker_sort(int *arr, int kol){

	unsigned int start_time = clock();

	for (int i = 0, r = kol-1; i < kol; ++i, --r)
	{
		for (int c = i; c < r; ++c){
			if (arr[c]>arr[c + 1]){
				swap(arr, c, (c + 1));
			}
		}

		for (int c = r; c > i; --c){
			if (arr[c]<arr[c - 1]){
				swap(arr, c, (c - 1));
			}
		}
	}

	unsigned int end_time = clock();
	cout << "Время сортировки шейкером = " << (end_time - start_time) << endl;
}

void insert_sort(int *arr, int kol){

	unsigned int start_time = clock();

	for (int i = 1; i < kol; ++i)
	{
		for (int c = i; c > 0; --c){
			if (arr[c] < arr[c-1]){
				swap(arr, c, (c - 1));
			}
		}
	}

	unsigned int end_time = clock();
	cout << "Время сортировки вставками = " << (end_time - start_time) << endl;
}

void comb_sort(int *arr, int kol){

	unsigned int start_time = clock();

	for (int i = (kol-1); i > 0; --i)
	{
		for (int c = 0; c + i < kol; ++c){
			if (arr[c] > arr[c + i]){
				swap(arr, c, (c + i));
			}
		}
	}

	unsigned int end_time = clock();
	cout << "Время сортировки расческой = " << (end_time - start_time) << endl;
}

void quick_sort(int *arr, int end, int begin){
	unsigned int start_time = clock();
	quick_sort_real(arr, end, begin);
	unsigned int end_time = clock();
	cout << "Время быстрой сортировки = " << (end_time - start_time) << endl;
}

void quick_sort_real(int *arr, int end, int begin){

	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l]> mid) l--;
		if (f <= l)
		{
			swap(arr, f, l);
			f++;
			l--;
		}
	}
	if (begin < l) quick_sort_real(arr, l, begin);
	if (f < end) quick_sort_real(arr, end, f);

}

int min_of_arr(int *arr, int kol){
	int min;
	for (int i = 0; i < kol; i++)
	{
		if (i == 0 || min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

int max_of_arr(int *arr, int kol){
	int max;
	for (int i = 0; i < kol; i++)
	{
		if (i == 0 || max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

void cout_mid(int *arr, int kol){
	int value, min, max;
	int quant = 0;
	min = min_of_arr(arr, kol);
	max = max_of_arr(arr, kol);
	value = (min + max) / 2;
	cout << "Среднее число = " << value << endl;
	for (int i = 0; i < kol; i++)
	{
		if(arr[i] == value){
			cout << "Среднее число под индексом " << i << endl;
			++quant;
		}
		if ( i == kol - 1 ){
			cout << "Количество средних чисел в массиве = " << quant <<  endl;
		}
	}
}

void big_value(int *arr, int kol){
	int quantity=0, value;
	cout << "Введите число, количество чисел больше которого вы хотите найти." << endl;
	cin>>value;
	for (int i = 0; i < kol; i++){
		if (arr[i] > value) ++quantity;
	}
	cout << quantity << " чисел больше введеного." << endl;
}

void min_value(int *arr, int kol){
	int quantity = 0, value;
	cout << "Введите число, количество чисел меньше которого вы хотите найти." << endl;
	cin >> value;
	for (int i = 0; i < kol; i++){
		if (arr[i] < value) ++quantity;
	}
	cout << quantity << " чисел меньше введеного." << endl;
}

bool bin_search(int *arr, int end, int begin, int value){
	int mid = (end + begin) / 2;
	if (arr[mid] == value) return true;
	else if (arr[mid] <= value) {
		if (mid == end){
			return false;
		}
		else{
			return bin_search(arr, end, mid+1, value);
		}
	}
	else if (arr[mid] >= value ){
		if (mid == begin)		{
			return false;
		}
		else{
			return bin_search(arr, mid-1, begin, value);
		}
    }
	
}