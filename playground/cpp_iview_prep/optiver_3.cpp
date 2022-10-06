#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#define PI 3.1427571
class Shape
{
public:
    virtual int GetArea() const { return 1; };
};

class Rectangle : public Shape
{
    int height_, width_;

public:
    Rectangle(int height, int width) : height_(height), width_(width) {}
    int GetArea() const
    {
        return (height_ * width_);
    }
};

class Triangle : public Shape
{
    int height_, width_;

public:
    Triangle(int height, int width) : height_(height), width_(width) {}
    int GetArea() const
    {
        return (height_ * width_) / 2;
    }
};

class Circle : public Shape
{
    int radius_;

public:
    Circle(int radius) : radius_(radius) {}
    int GetArea() const
    {
        return (radius_ * radius_ * 22) / 7;
    }
};

int main()
{
    int rectangleHeight = 4, rectangleWidth = 3;
    int triangleHeight = 5, triangleWidth = 2;
    int circleRadius = 5;

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Rectangle>(rectangleHeight, rectangleWidth));
    shapes.emplace_back(std::make_unique<Triangle>(triangleHeight, triangleWidth));
    shapes.emplace_back(std::make_unique<Circle>(circleRadius));

    // std::cout << shapes[0]->GetArea() << "  " << shapes[1]->GetArea() << "  " << shapes[2]->GetArea() << "\n";

    const int totalArea = std::accumulate(shapes.begin(), shapes.end(), 0, [](int total, const auto &shape)
                                          { return total + shape->GetArea(); });
    std::cout << totalArea << "\n";

    return 0;
}