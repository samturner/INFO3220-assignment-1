#ifndef BALL_H
#define BALL_H

#include "coordinate.h"
#include <QPainter>

class Ball
{
public:
    Ball();

    Ball(Coordinate coordinate);

    Ball(Coordinate coordinate,
         unsigned int radius);

    Ball(Coordinate coordinate,
         unsigned int radius,
         double xVelocity,
         double yVelocity,
         QString color);

    ~Ball();

    void render(QPainter &painter, unsigned int time);

    bool isBottomCollision() const;
    bool isLeftCollision() const;
    bool isTopCollision() const;
    bool isRightCollision() const;

    unsigned int getRadius() const;

private:
    Coordinate m_coordinate;
    unsigned int m_radius;
    double m_xVelocity;
    double m_yVelocity;

    QString m_color;
};

#endif // BALL_H
