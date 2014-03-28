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
    QWidget * wdg = new QWidget(this);
    wdg->resize(150,46);
    wdg->setStyleSheet("background-color: #FFFFFF;");
    m_pauseButton = new QPushButton(wdg);
    m_pauseButton->setText(tr("Pause"));
    connect(m_pauseButton, SIGNAL(released()), this, SLOT(handlePause()));

    // create the ball, getting the values from the configuration class
    m_ball = Ball(Coordinate(m_config.getXCoordinate() + m_config.getRadius(), m_config.getYCoordinate() + m_config.getRadius(), m_config.getWindowHeight(), m_config.getWindowWidth()), m_config.getRadius(), m_config.getXVelocity(), m_config.getYVelocity(), m_config.getBallColor());

    ui->setupUi(this);

    // set the size of the window from the configuration class
    this->resize(m_config.getWindowWidth(), m_config.getWindowHeight());
    this->setStyleSheet("background-color: " + m_config.getBackgroundColor() + ";");

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));   // connect the timer
    m_timer->start(32);
}

Dialog::~Dialog()
{
    delete ui;
    delete m_timer;
    delete m_pauseButton;
}

void Dialog::handlePause() {
    if (m_timer->isActive()) {      // If the timer is active, stop it
        m_timer->stop();
        m_pauseButton->setText(tr("Resume"));
    } else {                        // Otherwise start it again
        m_timer->start(32);
        m_pauseButton->setText(tr("Pause"));
    }
}

void Dialog::nextFrame() {
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    if (m_timer->isActive()) {
        QPainter painter(this);
        m_ball.render(painter, m_counter);
        m_counter++;
    }
}
