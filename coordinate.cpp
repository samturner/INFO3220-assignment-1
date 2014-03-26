#include "coordinate.h"

Coordinate::Coordinate(unsigned int xCoordinate,
                       unsigned int yCoordinate,
                       unsigned int frameHeight,
                       unsigned int frameWidth)
{
    m_xCoordinate = xCoordinate;
    m_yCoordinate = yCoordinate;
    m_frameHeight = frameHeight;
    m_frameWidth = frameWidth;
}

int Coordinate::getQtRenderingXCoordinate() {
    return m_frameWidth - m_xCoordinate;
}

int Coordinate::getQtRenderingYCoordinate() {
    return m_frameHeight - m_yCoordinate;
}

void Coordinate::changeInXCoordinate(int change) {
    m_xCoordinate = m_xCoordinate+change;
}

void Coordinate::changeInYCoordinate(int change) {
    m_yCoordinate = m_yCoordinate+change;
}

void Coordinate::setYCoordinateToZero(int offset) {
    m_yCoordinate = offset;
}

void Coordinate::setYCoordinateToHeight(int offset) {
    m_yCoordinate = this->getFrameHeight() - offset;
}

unsigned int Coordinate::getFrameHeight() {
    return m_frameHeight;
}

unsigned int Coordinate::getFrameWidth() {
    return m_frameWidth;
}
