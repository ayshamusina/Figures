#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    representer = new Representer();
    drawer = new Drawer_Deleter();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete representer;
    delete drawer;
}


void MainWindow::paintEvent(QPaintEvent* paint_event)
{
    representer->represent(this, drawer->get());
    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event)
{

    if (mouse_event->button() == Qt::LeftButton)
    {
        drawer->draw(mouse_event->windowPos().x(), mouse_event->windowPos().y());
    }
    else if (mouse_event->button() == Qt::RightButton)
    {
        drawer->delete_it(mouse_event->windowPos().x(), mouse_event->windowPos().y());
    }

    repaint();

    QMainWindow::mousePressEvent(mouse_event);
}
