#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>

int getValidInput() {
    double size;
    while (true) {
        std::cin >> size;
        if (std::cin.fail() || size <= 0 || size != static_cast<int>(size)) {
            std::cout << "Invalid input. Please enter a valid positive integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return static_cast<int>(size);
}

class TArray {
protected:
    int size;
     double *elements;
public:
    TArray() : size(0), elements(nullptr) {}
    explicit TArray(int s) : size(s) {
        if (s <= 0) {
            std::cerr << "The size of the array must be a positive number." << std::endl;
            exit(1);
        }
        elements = new double[size];
    }
    TArray(const TArray &arr) : size(arr.size) {
        elements = new double[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = arr.elements[i];
        }
    }
    void inputArray() {
        std::cout << "Enter elements:" << std::endl;
        for (int i = 0; i < size; ++i) {                     //введення та виведення
            std::cout << "Element " << i + 1 << ": ";
            std::cin >> elements[i];
        }
    }
    void randomizeArray() {
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            elements[i] = rand() % 100; // випадково в діапазоні від 0 до 99
        }
    }
    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }                         //друкуємо масив
        std::cout << std::endl;
    }

    void quickSortHelper(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);                 //сортування
            quickSortHelper(low, pi);
            quickSortHelper(pi + 1, high);
        }
    }

    int partition(int low, int high) {
        double pivot = elements[low];
        int i = low - 1;
        int j = high + 1;
        while (true) {
            do {
                i++;
            } while (elements[i] < pivot);

            do {
                j--;
            } while (elements[j] > pivot);

            if (i >= j)
                return j;

            std::swap(elements[i], elements[j]);
        }
    }

    void quickSort() {
        quickSortHelper(0, size - 1);
    }

    double findMax() const {
        double max = elements[0];
        for (int i = 1; i < size; ++i) {      //найбільший елемент
            if (elements[i] > max) {
                max = elements[i];
            }
        }
        return max;
    }

    double findMin() const {
        double min = elements[0];
        for (int i = 1; i < size; ++i) {   //найменший елемент
            if (elements[i] < min) {
                min = elements[i];
            }
        }
        return min;
    }

    double sum() const {
        double sum = 0;                  //сума
        for (int i = 0; i < size; ++i) {
            sum += elements[i];
        }
        return sum;
    }

    // перевантаження операторів
    TArray operator+(const TArray &arr) const {
        TArray result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] + arr.elements[i];
        }
        return result;
    }

    TArray operator-(const TArray &arr) const {
        TArray result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] - arr.elements[i];
        }
        return result;
    }

    TArray operator*(int scalar) const {
        TArray result(size);
        for (int i = 0; i < size; ++i) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }
    ~TArray() {
        delete[] elements;
    }
};
class TOderedArray : public TArray {
public:
    TOderedArray() : TArray() {}
    explicit TOderedArray(int s) : TArray(s) {}
    TOderedArray(const TOderedArray &arr) : TArray(arr) {}


    void insertElement(double element) {                //вставляємо елемент
        elements[size] = element;
        size++;
        std::sort(elements, elements + size); // Сортуємо елементи після вставки
    }

    void removeElement(double element) {
        int i = 0;
        while (i < size && elements[i] != element) {     //видаляємо елемент
            i++;
        }
        if (i == size) {
            std::cout << "Element not found in the array." << std::endl;
            return;
        }
        for (int j = i; j < size - 1; j++) {
            elements[j] = elements[j + 1];
        }
        size--;
    }

    // Перевизначення оператора додавання для додавання елемента
    TOderedArray operator+(double element) const {
        TOderedArray result(*this);
        result.insertElement(element);
        return result;
    }

    // Перевизначення оператора віднімання для вилучення елемента
    TOderedArray operator-(double element) const {
        TOderedArray result(*this);
        result.removeElement(element);
        return result;
    }
};
int main() {
    int size;
    std::cout << "Enter the size for both arrays (a positive integer): ";
    size = getValidInput();

    TArray arr(size);
    TArray arr2(size);

    char choice;
    std::cout << "Select the method of setting the arrays. \n";
    std::cout << "-> If you want to fill both arrays yourself, press 1. \n";
    std::cout << "-> If you want to fill the first array yourself, and the second randomly, press 2. \n";
    std::cout << "-> If you want to fill the first array randomly, and the second one yourself, then press 3. \n";
    std::cin >> choice;

    switch (choice) {
        case '1':
            arr.inputArray();
            arr2.inputArray();
            break;
        case '2':
            arr.inputArray();
            arr2.randomizeArray();
            break;
        case '3':
            arr.randomizeArray();
            arr2.inputArray();
            break;
        default:
            std::cerr << "Error! Choose the option that suits you." << std::endl;
            return 1;
    }

    std::cout << "First array: ";
    arr.printArray();
    std::cout << "Second array: ";
    arr2.printArray();

    std::cout << "The largest element in the first array: " << arr.findMax() << std::endl;
    std::cout << "The smallest element in the first array: " << arr.findMin() << std::endl;

    std::cout << "Sum of elements in the first array: " << arr.sum() << std::endl;

    TArray arr_sum = arr + arr2;
    std::cout << "Sum of two arrays: ";
    arr_sum.printArray();

    TArray arr_diff = arr - arr2;
    std::cout << "Difference of two arrays: ";
    arr_diff.printArray();

    arr.quickSort();
    std::cout << "Sorted first array: ";
    arr.printArray();

    int scalar;
    std::cout << "Enter the number by which you want to multiply the first array: ";
    std::cin >> scalar;

    TArray arr_mul = arr * scalar;
    std::cout << "Multiplication result of the first array: ";
    arr_mul.printArray();
//-----------------------------------------------------------------------
    std::cout << "Enter the size for the array (a positive integer): ";
    std::cin >> size;

    TOderedArray arr3(size);

    std::cout << "Enter elements for the array:" << std::endl;
    arr3.inputArray();

    std::cout << "Array before modifications: ";
    arr3.printArray();

    double insertElement;
    std::cout << "Enter an element to insert into the array: ";
    std::cin >> insertElement;
    arr3.insertElement(insertElement);
    std::cout << "Array after insertion: ";
    arr3.printArray();

    double removeElement;
    std::cout << "Enter an element to remove from the array: ";
    std::cin >> removeElement;
    arr3.removeElement(removeElement); 
    std::cout << "Array after removal: ";
    arr3.printArray();
    return 0;
}
