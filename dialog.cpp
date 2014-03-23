#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <string>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_ball(Ball(Coordinate(100, 100, 500), 20, -9.8,4.5, 10)),      // default values for the ball
    m_counter(0)
{

    // Ball (Coordinate coordinate, unsigned int radius, double gravity, double xVelocity,double yVelocity)
    configuration config = this->readFile();

    if (config.getConfigEntered()) { // if we read the file in correctly
        m_ball = Ball(Coordinate(config.getXCoordinate() + config.getRadius(), config.getYCoordinate() + config.getRadius(), 500), config.getRadius(), config.getGravity(), config.getXVelocity(), config.getYVelocity());
    }

    ui->setupUi(this);
    this->resize(500, 500);
    this->setStyleSheet("background-color: #31B94D;");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}

configuration Dialog::readFile() {
    QStringList options [6];           // Store the string lists

    QFile inputFile("/Users/samturner/Documents/Development/INFO3220/assignment_1/.config");        // The config file location
    configuration config(0,0,0,false);

     if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream configFile(&inputFile);         // Open the file

        config.setConfigEntered(true);
        int i = 0;

        while (!configFile.atEnd()) {               // If we're not at the end of a file
           QStringList tokens = configFile.readLine().split(':');   // Read the line in and split on colon
           options[i] = tokens;
           i++;
        }
        inputFile.close();      // Close the file

        for (int i = 0; i < sizeof(options)/sizeof(options[0]); i++) {
                QStringList opt = options[i];

                if (opt[0] == "Radius") {
                    config.setRadius(opt[1].toInt());
                } else if (opt[0] == "InitialX") {
                    config.setXCoordinate(opt[1].toInt());
                } else if (opt[0] == "InitialY") {
                    config.setYCoordinate(opt[1].toInt());
                } else if (opt[0] == "Gravity") {
                    config.setGravity(opt[1].toDouble());
                } else if (opt[0] == "XVelocity") {
                    config.setXVelocity(opt[1].toDouble());
                } else if (opt[0] == "YVelocity") {
                    config.setYVelocity(opt[1].toDouble());
                }
         }

        return config;
     } else {
         // TODO: Handle this error, file cannot be opened
         return false;
     }
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
