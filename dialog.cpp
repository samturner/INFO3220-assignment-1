#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_ball(Ball(Coordinate(0, 0, 0, 0), 0, 0, 0, 0,"#FFFFFF")),      // if there is no config files
    m_counter(0)
{
    configuration config;
    if (config.readConfigFile()) { // if we read the file in correctly, use the options from the file
        m_ball = Ball(Coordinate(config.getXCoordinate() + config.getRadius(), config.getYCoordinate() + config.getRadius(), config.getWindowHeight(), config.getWindowWidth()), config.getRadius(), config.getGravity(), config.getXVelocity(), config.getYVelocity(), config.getColor());
    }

    ui->setupUi(this);

//    qDebug() << "WIDTH: " << config.getWindowWidth() << ", HEIGHT: " << config.getWindowHeight();

    this->resize(config.getWindowWidth(), config.getWindowHeight());
    this->setStyleSheet("background-color: #31B94D;");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}

//configuration Dialog::readFile() {

//    QFile inputFile("config.txt");        // The config file location
//    configuration config;                       // A new configuration object

//     if (inputFile.open(QIODevice::ReadOnly)) {
//        qDebug() << "FILE OPENED!";
//        QTextStream configFile(&inputFile);         // Open the file

//        config.setConfigEntered(true);              // Tell the configuration that we've opened a file

//        while (!configFile.atEnd()) {               // If we're not at the end of a file
//           QStringList opt = configFile.readLine().split(':');   // Read the line in and split on colon

//           if (opt[0] == "Radius") {
//               config.setRadius(opt[1].toInt());
//           } else if (opt[0] == "InitialX") {
//               config.setXCoordinate(opt[1].toInt());
//           } else if (opt[0] == "InitialY") {
//               config.setYCoordinate(opt[1].toInt());
//           } else if (opt[0] == "Gravity") {
//               config.setGravity(opt[1].toDouble());
//           } else if (opt[0] == "XVelocity") {
//               config.setXVelocity(opt[1].toDouble());
//           } else if (opt[0] == "YVelocity") {
//               config.setYVelocity(opt[1].toDouble());
//           } else if (opt[0] == "Color") {
//               config.setColor(opt[1]);
//           } else if (opt[0] == "WindowHeight") {
//               config.setWindowHeight(opt[1].toInt());
//           } else if (opt[0] == "WindowWidth") {
//               config.setWindowWidth(opt[1].toInt());
//           }
//        }

//        inputFile.close();      // Close the file
//     } else {
//         config.setConfigEntered(false);
//         qDebug() << "COULD NOT OPEN FILE!";
//     }

//     return config;
//}

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
