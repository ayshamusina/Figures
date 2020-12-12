#include <QPainter>
#include <vector>
#include <QtWidgets/QWidget>
#include <circle_rectangular.h>
#include <cstdlib>
#include <iostream>

#ifndef REPRESENTER_H
#define REPRESENTER_H

using Coordinates = std::pair<int, int>;

class Representer
{
public:
    Representer();
    ~Representer();
    void represent(QWidget* widget, std::vector<Figure*> *figures);
    void draw(Circle* circle);
    void draw(Rectangle* rectangle);
private:
    QPainter* painter;
};

#endif // REPRESENTER_H


#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H

class Drawer_Deleter
{
public:
    Drawer_Deleter();
    ~Drawer_Deleter();
    void draw(int x, int y);
    void delete_it(int x, int y);
    std::vector<Figure*>* get();
    std::vector<Figure*> *figures;
    Figure* generate(int x, int y);
};

#endif // CLICKHANDLER_H
