#pragma once
template <typename RT>
class Rectangle
{
private:
    RT length{};
    RT width{};

public:
    Rectangle(RT l, RT w);
    RT getLength() const { return this->length; } // Getter for length
    RT getWidth() const { return this->width; }   // Getter for width
    ~Rectangle();
};
template <typename RT>
Rectangle<RT>::Rectangle(RT l, RT w) : length{l}, width{w}
{
    // std::println("Rectangle with length:{} and width{} created!", length, width);
}
template <typename RT>
Rectangle<RT>::~Rectangle()
{
    // std::println("Rectangle with length:{} and width{} deleted!", length, width);
}
