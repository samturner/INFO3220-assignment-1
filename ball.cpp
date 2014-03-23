#include "ball.h"

Ball::Ball(Coordinate coordinate) : m_coordinate(0,0,0) {
    m_coordinate = coordinate;
}

Ball::Ball(Coordinate coordinate, unsigned int radius) : m_coordinate(0,0,0) {
    m_coordinate = coordinate;
    m_radius = radius;
}

Ball::Ball(Coordinate coordinate, unsigned int radius, double gravity, double xVelocity, double yVelocity) : m_coordinate(0,0,0) {
    m_coordinate = coordinate;
    m_radius = radius;
    m_gravity = gravity;
    m_xVelocity = xVelocity;
    m_yVelocity = yVelocity;
}

unsigned int Ball::getRadius() {
    return m_radius;
}

bool Ball::isBottomCollision() {
    // checks if the ball has fallen off the screen, if so, return true, else return false
    return m_coordinate.getQtRenderingYCoordinate() > (signed int) (m_coordinate.getFrameHeight() - (signed int) m_radius);
}

bool Ball::isLeftCollision() {
    return m_coordinate.getQtRenderingXCoordinate() - (signed int) m_radius <= 0;   // If x is less than or equal to zero
}

bool Ball::isRightCollision() {
    return m_coordinate.getQtRenderingXCoordinate() > (signed int) m_coordinate.getFrameHeight() - m_radius;
}

bool Ball::isTopCollision() {
    return m_coordinate.getQtRenderingYCoordinate() < 0 + (signed int) m_radius;
}

void Ball::render(QPainter &painter, unsigned int time)
{
    if (isLeftCollision()) {
        m_xVelocity *= -1;
    } else if (isRightCollision()) {
        m_xVelocity *= -1;
    } else if (isTopCollision()) {
        //m_coordinate.setYCoordinateToZero(this->getRadius());
        m_coordinate.setYCoordinateToHeight(this->getRadius());
        // velocity decreases after hitting the ground
        m_yVelocity *= -1;
    } else if (isBottomCollision()) {
        m_coordinate.setYCoordinateToZero(this->getRadius());
        m_yVelocity *= -1;
    }

    //std::cout << "Y Velocity: " << m_yVelocity << " X Velocity: " << m_xVelocity << std::endl;

    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( Qt::yellow ) );
    painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
        m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
        m_radius * 2,
        m_radius * 2);
   //m_yVelocity += m_gravity / 32.0;
    m_coordinate.changeInXCoordinate(m_xVelocity);
    m_coordinate.changeInYCoordinate(m_yVelocity);
}

