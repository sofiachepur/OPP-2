#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
//----------------------------------------функцій для першого завдання
void replaceGreaterThanAverageWithZero(vector<double>& x) {
    double sum = 0.0;
    for (double val : x) {
        sum += val;                                            //замінюємо на нуль все що більше за сер.арифм.
    }
    double average = sum / x.size();

    for (double& val : x) {
        if (val > average) {
            val = 0.0;
        }
    }
}

vector<double> generateRandomVector(int size, double min, double max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(min, max);       //для випадкового набору чисел в заданому діапазоні

    vector<double> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = dis(gen);
    }
    return result;
}
//--------------------------------функції для другого завдання
void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << name << ": ";
    for (int elem : vec) {
        std::cout << elem << " ";         //показати вектор
    }
    std::cout << std::endl;
}

int scalarProduct(const std::vector<int>& a, const std::vector<int>& b) {
    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {          //скалярний добуток
        result += a[i] * b[i];
    }
    return result;
}

std::vector<int> multiplyVectorByScalar(const std::vector<int>& vec, int scalar) {
    std::vector<int> result;
    for (int elem : vec) {
        result.push_back(elem * scalar);               //множимо вектор на число
    }
    return result;
}

std::vector<int> addVectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    for (size_t i = 0; i < a.size(); ++i) {       //додаємо вектори
        result.push_back(a[i] + b[i]);
    }
    return result;
}
//----------------------------------------------функція для третього завдання
void compressArray(vector<int>& arr, int a, int b) {
    int n = arr.size();
    int idx = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < a || arr[i] > b) {
            arr[idx++] = arr[i];
        }                               //стискуємо масив на ті числа що є в діапазоні
    }                                    //кінець заповнюємо нулями
    while (idx < n) {
        arr[idx++] = 0;
    }
}

vector<int> generateArray(int size3, char choice3) {
    vector<int> result(size3);

    if (choice3 == 'm') {
        cout << "Enter " << size3 << " elements manually: ";             //самостійно заповнюємо
        for (int i = 0; i < size3; ++i) {
            cin >> result[i];
        }
    } else {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 100);             //випадковими значеннями

        cout << "Initial array: ";  //початковий масив
        for (int i = 0; i < size3; ++i) {
            result[i] = dis(gen);
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return result;
}
//------------------------------------------функції для четвертого завдання
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {      //виводимо матрицю
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}
void cyclicShift(vector<vector<int>>& matrix, int k) {          //для зсування матриці
    int numRows = matrix.size();
    for (int i = 0; i < numRows; ++i) {
        if (i % 2 != 0) {
            int shift = k % matrix[i].size();
            if (shift < 0) shift += matrix[i].size();
            vector<int> temp(matrix[i].begin(), matrix[i].end() - shift);
            matrix[i].erase(matrix[i].begin(), matrix[i].begin() + temp.size());
            matrix[i].insert(matrix[i].end(), temp.begin(), temp.end());
        }
    }
}
//-------------------------------------------------------------------------------завдання 5-------------
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {             //вивід матриці
            cout << element << "\t";
        }
        cout << endl;
    }
}
void triangularizeMatrix(vector<vector<double>>& matrix) {      //перетворюємо матрицю до трикутного вигляду
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] == 0) {
            // Якщо головний елемент нуль, шукаємо ненульовий елемент в тому ж стовпці для обміну рядків
            int swapRow = -1;
            for (int j = i + 1; j < n; ++j) {
                if (matrix[j][i] != 0) {
                    swapRow = j;
                    break;
                }
            }
            if (swapRow == -1) {
                // Якщо всі елементи у стовпці нульові, переходимо до наступного стовпця
                continue;
            }
            // Обмін рядків
            swap(matrix[i], matrix[swapRow]);
        }
        double norm = matrix[i][i];
        for (int j = i; j < n; ++j) {
            matrix[i][j] /= norm;
        }
        // Занулення елементів у стовпцях нижче головного елемента
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i];
            for (int j = i; j < n; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}
int main() {
    int choice;
    int size, size3;
    char choiceF;
    int a, b;

        cout << "Choose a task: \n";
        cout << "-> 1. One-dimensional array. Task 1 \n";
        cout << "-> 2. One-dimensional array. Task 2 \n";
        cout << "-> 3. One-dimensional array. Task 3 \n";
        cout << "-> 4. Two-dimensional array. Task 1 \n";
        cout << "-> 5. Two-dimensional array. Task 2 \n";
        cout << "-> 6. Two-dimensional array. Task 3 \n";
        cin >> choice;

     if (choice==1) {
         cout << "1. One-dimensional array. Task 1 \n";
         cout << "Enter the size of the vector: ";
         cin >> size;

         vector<double> x(size);
         cout << "Do you want to input elements manually (y/n)? ";
         cin >> choiceF;

         if (choiceF == 'y' || choiceF == 'Y') {
             cout << "Enter " << size << " elements: ";
             for (int i = 0; i < size; ++i) {
                 cin >> x[i];
             }
         } else {
             double min, max;
             cout << "Enter the range for random number generation (min max): ";
             cin >> min >> max;
             x = generateRandomVector(size, min, max);
         }
         cout << "Initial vector: ";
         for (double val: x) {
             cout << val << " ";
         }
         cout << endl;

         replaceGreaterThanAverageWithZero(x);

         cout << "Modified vector: ";
         for (double val: x) {
             cout << val << " ";
         }
         cout << endl;
         return 0;
     }
     if(choice==2){
         cout << "-> 2. One-dimensional array. Task 2 \n";
         std::vector<int> a, b, c;

         // Можна реалізувати введення векторів користувачем або генерацію випадкових значень.
         // Нижче наведено варіант введення векторів користувачем.

         // Введення вектора a
         std::cout << "Enter vector a:" << std::endl;
         for (size_t i = 0; i < 3; ++i) {
             int value;
             std::cin >> value;
             a.push_back(value);
         }

         // Введення вектора b
         std::cout << "Enter vector b:" << std::endl;
         for (size_t i = 0; i < 3; ++i) {
             int value;
             std::cin >> value;
             b.push_back(value);
         }

         // Введення вектора c
         std::cout << "Enter vector c:" << std::endl;
         for (size_t i = 0; i < 3; ++i) {
             int value;
             std::cin >> value;
             c.push_back(value);
         }
         printVector(a, "Vector a");
         printVector(b, "Vector b");
         printVector(c, "Vector c");

         // Обчислення скалярного добутку векторів a та b
         int scalar_product = scalarProduct(a, b);
         std::cout << "Scalar product of a and b: " << scalar_product << std::endl;

         // Помноження скалярного добутку на 2
         int result_scalar = scalar_product * 2;

         // Множення результату на вектор c
         std::vector<int> result_vector = multiplyVectorByScalar(c, result_scalar);

         // Знаходження вектора, рівного 3*b
         std::vector<int> vector_3b = multiplyVectorByScalar(b, 3);

         // Додавання двох векторів
         std::vector<int> final_result = addVectors(result_vector, vector_3b);

         // Виведення результату
         std::cout << "Final result after addition: ";
         for (int elem : final_result) {
             std::cout << elem << " ";
         }
         std::cout << std::endl;

         return 0;
     }
     if(choice==3){
         char choice3;
         cout << "3. One-dimensional array. Task 3 \n";
         cout << "Enter the size of the array. (it must be an integer and a positive number):\n ";
         cin >> size3;

         cout << "Enter a range of numbers(a,b) within which compression will be performed:\n";
         cin >> a >> b;

         cout << "How do you want the given array to be?\n ";
         cout << "If you want to enter the value yourself - select m\n";
         cout << "If you want the array to be filled with random values - select r\n";
         cin >> choice3;

         vector<int> arr = generateArray(size3, choice3);

         compressArray(arr, a, b);

         cout << "Compressed array: ";
         for (int num : arr) {
             cout << num << " ";
         }
         cout << endl;

         return 0;
     }
     if(choice==4){
         cout << " 4. Two-dimensional array. Task 1 \n";
         int n;
         cout << "Enter the matrix size: "; //вести розмір матриці
         cin >> n;
         if (n<=0){
             cout <<"Error.";
             return 0;
         }

         vector<vector<int>> matrix(n, vector<int>(n));

         char choice4;
         cout << "How do you want the given array to be?\n ";
         cout << "If you want to enter the value yourself - select m\n";
         cout << " If you want the array to be filled with random values - select r\n";
         cin >> choice4;

         //спосіб заповнення матриці
         if (choice4 == 'r') {
             srand(time(0));
             for (int i = 0; i < n; ++i) {
                 for (int j = 0; j < n; ++j) {       //випадково в діапазоні від 0 до 99
                     matrix[i][j] = rand() % 100;
                 }
             }
         } else if (choice4 == 'm') {
             cout << "Enter the elements of the matrix:" << endl;
             for (int i = 0; i < n; ++i) {                  //вручну
                 for (int j = 0; j < n; ++j) {
                     cin >> matrix[i][j];
                 }
             }
         } else {
             cout << "Incorrect input. Should be 'r' or 's'." << endl;
             return 1;
         }

         int k;
         cout << "Enter the number of positions to shift (the value must be positive and integer):";
         cin >> k;                    //значення на яке зсувається матриця
         if( k<=0 ){
             cout<<"ERROR.";
             return 0;
         }
         else
         cout << "Initial matrix:" << endl;    //початкова матриця
         printMatrix(matrix);

         cyclicShift(matrix, k);     // Матриця зсувається

         cout << "Matrix after cyclic shift:" << endl;   //  зсунута матрицю
         printMatrix(matrix);

         return 0;
     }
     if(choice==5){
         cout << "Two-dimensional array. Task 2 \n";
         int n5;
         cout << "Enter the size of the square matrix: ";
         cin >> n5;
         if(n5<=0){               //розмір квадратної матриці
             cout <<" ERROR";
             return 0;
         }

         vector<vector<double>> matrix(n5, vector<double>(n5)); //створюється матриця

         cout << "Enter the coefficients of the matrix:" << endl;
         for (int i = 0; i < n5; ++i) {
             for (int j = 0; j < n5; ++j) {             //водимо коефіцієнти
                 cin >> matrix[i][j];
             }
         }

         cout << "Entered matrix:" << endl;   //поч.матриця
         printMatrix(matrix);

         triangularizeMatrix(matrix);   // матриця до трикутного

         cout << "The matrix after reduction to triangular form:" << endl;
         printMatrix(matrix);           //кінець

         return 0;


     }
     if(choice==6){
         cout << "Two-dimensional array. Task 3 \n";
         int rows, cols;
         double threshold;

         cout << "Enter the number of rows of the matrix: ";
         cin >> rows;
         if (rows<=0){                                    //к-ть рядків
             cout <<"Error.Input right value";
             return 0;
         }
         cout << "Enter the number of matrix columns: ";
         cin >> cols;                  //к-ть стовпців
         if (cols<=0){
             cout <<"Error.Input right value";
             return 0;
         }

         cout << "Enter the value with which we will compare:";    //величина з якою порівнюємо
         cin >> threshold;

         vector<vector<double>> matrix(rows, vector<double>(cols));
         cout << "Enter the coefficients of the matrix:\n";
         for (int i = 0; i < rows; ++i) {
             for (int j = 0; j < cols; ++j) {        //заповнюємо матрицю
                 cin >> matrix[i][j];
             }
         }
         cout << "Matrix:\n";
         for (int i = 0; i < rows; ++i) {
             for (int j = 0; j < cols; ++j) {
                 cout << matrix[i][j] << " ";
             }
             cout << endl;
         }

         int count = 0;
         double sum;
         for (int i = 0; i < rows; ++i) {
             sum = 0;                                  //шукаємо суму по рядку
             for (int j = 0; j < cols; ++j) {
                 sum += matrix[i][j];
             }
             double average = sum / cols;          //ділимо на к-ть стовпців, звідки шукаємо сер.арифм.
             if (average < threshold) {                //Порівнюємо з сер.арифм. з веденою величиною
                 count++;                               //якщо менше, то додаємо
             }
         }
         cout << "The number of rows with an arithmetic mean is less " << threshold << " : " << count << endl;

         return 0;
     }
     else
         cout <<"ERROR.Select the desired option";
    return 0;
}
















