#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

using Coordinates = std::pair<int, int>;
class Representer;

class Figure // определяем класс фигуры и ее методы (наследуется кругом и прямоугольником)
{
public:
    Figure() {}
    ~Figure() {}
    virtual Coordinates getDrawPoint()=0;
    virtual void drawFigure(Representer* representer)=0;
    virtual bool isPointInFigure(int x, int y)=0;
    int getHeight()
    {
        return height;
    }

    int getWidth()
    {
         return width;
    }
    int x;
    int y;
    int width;
    int height;
};
#endif // FIGURE_H


#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Figure // определяем класс круга
{
public:
    Circle(int x, int y, int height, int width);
    static Circle* createCircle(int x, int y, int radius);
    Coordinates getDrawPoint();
    void drawFigure(Representer *representer);
    bool isPointInFigure(int x, int y);
};

#endif // CIRCLE_H


#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Figure // определяем класс прямоугольника
{
public:
    Rectangle(int x, int y, int width, int height);
    Coordinates getDrawPoint();
    void drawFigure(Representer* representer);
    bool isPointInFigure(int x, int y);
};

#endif // RECTANGLE_H
