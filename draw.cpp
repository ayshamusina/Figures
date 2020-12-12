#include <draw.h>
#include <fig.h>

Representer::Representer(){}

Representer::~Representer()
{
    delete painter;
}

void Representer::represent(QWidget* widget, std::vector<Figure*> *figures)
{
    painter = new QPainter(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black));
    for(auto fig : *figures) {
        painter->setBrush(QBrush(QColor(255, 0, 0)));
        fig->drawFigure(this);
    }
    painter->end();
}

void Representer::draw(Circle* circle)
{
    Coordinates center = circle->getDrawPoint();
    painter->drawEllipse(center.first, center.second, circle->getWidth(), circle->getHeight());
}

void  Representer::draw(Rectangle* rectangle)
{
    Coordinates left_top = rectangle->getDrawPoint();
    painter->drawRect(left_top.first, left_top.second, rectangle->getWidth(), rectangle->getHeight());
}


Drawer_Deleter::Drawer_Deleter()
{
    figures = new std::vector<Figure*>();
}

Drawer_Deleter::~Drawer_Deleter()
{
    for (auto ptr : *figures)
    {
        delete ptr;
    }
    delete figures;
}


void Drawer_Deleter::draw(int x, int y) // добавляет новую фигуру в массив
{
    Figure* newFigure = generate(x, y);
    figures->push_back(newFigure);
}

void Drawer_Deleter::delete_it(int x, int y) // удаляет по клику мышки
{
    std::vector<Figure*>::iterator it;
    it = figures->begin();
    while(it != figures->end())
    {
        Figure* i = *it;
        if(i->isPointInFigure(x, y))
        {
            figures->erase(it);
        }else{
            ++it;
        }
    }

}

std::vector<Figure*>* Drawer_Deleter::get() // возвращает массив фигур
{
    return figures;
}

Figure* Drawer_Deleter::generate(int x, int y) // рандомно генерирует фигуру
{
    int type = rand() % 2;
    Figure* newFigure;

    if (type == 0)
    {
            newFigure = new Rectangle(x, y, rand() % 250, rand() % 250);
    }
    else
    {
            newFigure = Circle::createCircle(x, y, rand() % 250);
    }
    return newFigure;
}

