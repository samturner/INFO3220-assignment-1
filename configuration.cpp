#include "configuration.h"

configuration::configuration(unsigned int xCoordinate, unsigned int yCoordinate, unsigned int radius, bool configEntered, double gravity, double xVelocity, double yVelocity, QString color) {
    m_xCoordinate = xCoordinate;
    m_yCoordinate = yCoordinate;
    m_radius = radius;
    m_configEntered = configEntered,
    m_gravity = gravity,
    m_xVelocity = xVelocity,
    m_yVelocity = yVelocity;
    m_color = color;
}

void configuration::setConfigEntered(bool configEntered) {
    m_configEntered = configEntered;
}

void configuration::setXCoordinate(unsigned int xCoordinate) {
    m_xCoordinate = xCoordinate;
}

void configuration::setYCoordinate(unsigned int yCoordinate) {
    m_yCoordinate = yCoordinate;
}

void configuration::setRadius(unsigned int radius) {
    m_radius = radius;
}

void configuration::setXVelocity(double xVelocity) {
    m_xVelocity = xVelocity;
}

void configuration::setYVelocity(double yVelocity) {
    m_yVelocity = yVelocity;
}

void configuration::setGravity(double gravity) {
    m_gravity = gravity;
}

void configuration::setColor(QString color) {
    m_color = color;
}

unsigned int configuration::getXCoordinate() {
    return m_xCoordinate;
}

unsigned int configuration::getYCoordinate() {
    return m_yCoordinate;
}

unsigned int configuration::getRadius() {
    return m_radius;
}

double configuration::getGravity() {
    return m_gravity;
}

double configuration::getXVelocity() {
    return m_xVelocity;
}

double configuration::getYVelocity() {
    return m_yVelocity;
}

bool configuration::getConfigEntered() {
    return m_configEntered;
}

QString configuration::getColor() {
    return m_color;
}
