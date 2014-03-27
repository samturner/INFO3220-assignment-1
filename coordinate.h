#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
    Coordinate(unsigned int xCoordinate,
               unsigned int yCoordinate,
               unsigned int frameHeight,
               unsigned int frameWidth);

    ~Coordinate();

    int getQtRenderingXCoordinate() const;

    int getQtRenderingYCoordinate() const;

    void changeInXCoordinate(int change);
    void changeInYCoordinate(int change);

    void setYCoordinateToZero(int offset);
    void setYCoordinateToHeight(int offset);

    unsigned int getFrameHeight() const;
    unsigned int getFrameWidth() const;

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;

    unsigned int m_frameHeight;
    unsigned int m_frameWidth;

};

#endif // COORDINATE_H
