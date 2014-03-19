#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    // Ball (Coordinate coordinate, unsigned int radius, double gravity, double xVelocity,double yVelocity)
    m_ball(Ball(Coordinate(100, 100, 500), 20, -9.8,4.5, 10)),
    m_counter(0)
{
    ui->setupUi(this);
    this->resize(500, 500);
    this->setStyleSheet("background-color: #31B94D;");
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::nextFrame() {
    //std::cout << "RENDERING" << std::endl;
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{

    bool animation = true;

    if (animation) {
        // code for this exercise goes here
        QPainter painter(this);
        m_ball.render(painter, m_counter);
        m_counter++;
    } else {
        QPainter painter(this);
        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::black);

        QBrush brush(Qt::yellow);

        painter.setPen(pen);
        painter.setBrush(brush);

        // Add before the painter draws the ellipse
        painter.drawEllipse(50, 30, 100, 100);

        brush.setColor("#C36241");
        painter.setBrush(brush);
        pen.setWidth(1);

        QPolygon roof;
        roof.putPoints(0, 3, 250, 260, 290, 220, 330, 260);
        painter.drawPolygon(roof);

        brush.setColor("#835C3B");
        painter.setBrush(brush);

        QPolygon house;
        house.putPoints(0, 4, 260, 260, 260, 299, 320, 299, 320, 260);
        painter.drawPolygon(house);
    }
}
