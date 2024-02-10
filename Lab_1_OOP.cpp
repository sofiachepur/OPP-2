#include <iostream>
#include <limits>

double getValidInput() {
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cout << "Invalid input. Please enter a valid positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

class TRectangle {
protected:
    double length;
    double width;

public:
    TRectangle() : length(0.0), width(0.0) {}
    TRectangle(double l, double w) : length(l), width(w) {}

    void input() {
        std::cout << "Enter length (must be greater than 0): ";
        length = getValidInput();

        std::cout << "Enter width (must be greater than 0): ";
        width = getValidInput();
    }

    void display() const {
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }

    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    void compare(const TRectangle& other) const {
        if (compareDimensions(other))
            std::cout << "The rectangles are equal." << std::endl;
        else
            std::cout << "The rectangles are not equal." << std::endl;
    }

    bool compareDimensions(const TRectangle& other) const {
        return (length == other.length) && (width == other.width);
    }

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
    TParallelepiped() : TRectangle(), height(0.0) {}
    TParallelepiped(double l, double w, double h) : TRectangle(l, w), height(h) {}

    using TRectangle::TRectangle;

    void input() {
        TRectangle::input();

        std::cout << "Enter height (must be greater than 0): ";
        height = getValidInput();
    }

    void display() const {
        TRectangle::display();
        std::cout << "Height: " << height << std::endl;
    }

    double calculateVolume() const {
        return calculateArea() * height;
    }

    void compare(const TParallelepiped& other) const {
        if (compareDimensions(other) && height == other.height)
            std::cout << "The parallelepipeds are equal." << std::endl;
        else
            std::cout << "The parallelepipeds are not equal." << std::endl;
    }

    bool compareDimensions(const TParallelepiped& other) const {
        return TRectangle::compareDimensions(other) && (height == other.height);
    }
    TParallelepiped operator+(const TParallelepiped& other) const {
        return TParallelepiped(length + other.length, width + other.width, height + other.height);
    }

    TParallelepiped operator-(const TParallelepiped& other) const {
        return TParallelepiped(length - other.length, width - other.width, height - other.height);
    }

    TParallelepiped operator*(double scalar) const {
        return TParallelepiped(length * scalar, width * scalar, height * scalar);
    }
};

int main() {
    TRectangle rectangle1, rectangle2;

    std::cout << "Enter data for Rectangle 1:" << std::endl;
    rectangle1.input();

    std::cout << "\nEnter data for Rectangle 2:" << std::endl;
    rectangle2.input();

    std::cout << "\nRectangle 1:" << std::endl;
    rectangle1.display();
    std::cout << "Area: " << rectangle1.calculateArea() << ", Perimeter: " << rectangle1.calculatePerimeter() << std::endl;

    std::cout << "\nRectangle 2:" << std::endl;
    rectangle2.display();
    std::cout << "Area: " << rectangle2.calculateArea() << ", Perimeter: " << rectangle2.calculatePerimeter() << std::endl;

    TParallelepiped parallelepiped1, parallelepiped2;

    std::cout << "\nEnter data for Parallelepiped 1:" << std::endl;
    parallelepiped1.input();

    std::cout << "\nEnter data for Parallelepiped 2:" << std::endl;
    parallelepiped2.input();

    std::cout << "\nParallelepiped 1:" << std::endl;
    parallelepiped1.display();
    std::cout << "Volume: " << parallelepiped1.calculateVolume() << std::endl;

    std::cout << "\nParallelepiped 2:" << std::endl;
    parallelepiped2.display();
    std::cout << "Volume: " << parallelepiped2.calculateVolume() << std::endl;

    TRectangle rectangle_sum = rectangle1 + rectangle2;
    std::cout << "\nSum of Rectangles:" << std::endl;
    rectangle_sum.display();

    TRectangle rectangle_diff = rectangle1 - rectangle2;
    std::cout << "\nDifference of Rectangles:" << std::endl;
    rectangle_diff.display();

    TRectangle rectangle_scalar_mult = rectangle1 * 2.0;
    std::cout << "\nRectangle 1 multiplied by scalar:" << std::endl;
    rectangle_scalar_mult.display();


    std::cout << "\nComparison of Rectangles:" << std::endl;
    rectangle1.compare(rectangle2);


    TParallelepiped parallelepiped_sum = parallelepiped1 + parallelepiped2;
    std::cout << "\nSum of Parallelepipeds:" << std::endl;
    parallelepiped_sum.display();

    TParallelepiped parallelepiped_diff = parallelepiped1 - parallelepiped2;
    std::cout << "\nDifference of Parallelepipeds:" << std::endl;
    parallelepiped_diff.display();

    TParallelepiped parallelepiped_scalar_mult = parallelepiped1 * 2.0;
    std::cout << "\nParallelepiped 1 multiplied by scalar:" << std::endl;
    parallelepiped_scalar_mult.display();

    std::cout << "\nComparison of Parallelepipeds:" << std::endl;
    parallelepiped1.compare(parallelepiped2);

    return 0;
}
