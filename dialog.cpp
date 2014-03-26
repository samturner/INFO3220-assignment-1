#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_ball(Ball(Coordinate(0, 0, 0, 0), 0, 0, 0,"#FFFFFF")),
    m_config(),
    m_counter(0)
{
    // create the ball, getting the values from the configuration class
    m_ball = Ball(Coordinate(m_config.getXCoordinate() + m_config.getRadius(), m_config.getYCoordinate() + m_config.getRadius(), m_config.getWindowHeight(), m_config.getWindowWidth()), m_config.getRadius(), m_config.getXVelocity(), m_config.getYVelocity(), m_config.getColor());

    ui->setupUi(this);

    // set the size of the window from the configuration class
    this->resize(m_config.getWindowWidth(), m_config.getWindowHeight());
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
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{

    bool animation = true;

    if (animation) {
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
