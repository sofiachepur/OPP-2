#include <iostream>

class TRectangle {
private:
    double length;
    double width;

public:
    // Конструктори
    TRectangle() : length(0.0), width(0.0) {}
    TRectangle(double l, double w) : length(l), width(w) {}
    TRectangle(const TRectangle& other) : length(other.length), width(other.width) {}

    // Методи введення/виведення даних
    void input() {
        std::cout << "Enter length: ";
        std::cin >> length;
        std::cout << "Enter width: ";
        std::cin >> width;
    }

    void display() const {
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }

    // Методи визначення площі та периметру
    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    // Порівняння з іншим прямокутником
    bool compare(const TRectangle& other) const {
        return (length == other.length) && (width == other.width);
    }

    // Перевантаження операторів
    TRectangle operator+(const TRectangle& other) const {
        return TRectangle(length + other.length, width + other.width);
    }

    TRectangle operator-(const TRectangle& other) const {
        return TRectangle(length - other.length, width - other.width);
    }

    TRectangle operator*(double scalar) const {
        return TRectangle(length * scalar, width * scalar);
    }
};

class TParallelepiped : public TRectangle {
private:
    double height;

public:
    // Конструктори
    TParallelepiped() : TRectangle(), height(0.0) {}
    TParallelepiped(double l, double w, double h) : TRectangle(l, w), height(h) {}
    TParallelepiped(const TParallelepiped& other) : TRectangle(other), height(other.height) {}

    // Метод виведення даних
    void display() const {
        TRectangle::display();
        std::cout << "Height: " << height << std::endl;
    }

    // Метод знаходження об'єму паралелепіпеда
    double calculateVolume() const {
        return calculateArea() * height;
    }

    // Перевизначення методів з батьківського класу
    bool compare(const TParallelepiped& other) const {
        return TRectangle::compare(other) && (height == other.height);
    }
};

int main() {
    // Тестування класів
    TRectangle rectangle1, rectangle2(3.0, 4.0), rectangle3(rectangle2);

    std::cout << "Rectangle 1:" << std::endl;
    rectangle1.input();
    rectangle1.display();
    std::cout << "Area: " << rectangle1.calculateArea() << ", Perimeter: " << rectangle1.calculatePerimeter() << std::endl;

    std::cout << "\nRectangle 2:" << std::endl;
    rectangle2.display();
    std::cout << "Area: " << rectangle2.calculateArea() << ", Perimeter: " << rectangle2.calculatePerimeter() << std::endl;

    std::cout << "\nRectangle 3 (copy of Rectangle 2):" << std::endl;
    rectangle3.display();

    TParallelepiped parallelepiped1, parallelepiped2(3.0, 4.0, 5.0), parallelepiped3(parallelepiped2);

    std::cout << "\nParallelepiped 1:" << std::endl;
    parallelepiped1.input();
    parallelepiped1.display();
    std::cout << "Volume: " << parallelepiped1.calculateVolume() << std::endl;

    std::cout << "\nParallelepiped 2:" << std::endl;
    parallelepiped2.display();
    std::cout << "Volume: " << parallelepiped2.calculateVolume() << std::endl;

    std::cout << "\nParallelepiped 3 (copy of Parallelepiped 2):" << std::endl;
    parallelepiped3.display();

    return 0;
}
