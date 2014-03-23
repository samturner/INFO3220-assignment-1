#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class configuration
{
public:
    configuration(unsigned int m_xCoordinate = 0,
                  unsigned int m_yCoordinate = 0,
                  unsigned int m_radius = 0,
                  bool m_configEntered = false,
                  double m_gravity = 0.0,
                  double m_xVelocity = 0.0,
                  double m_yVelocity = 0.0);

    void setXCoordinate(unsigned int xCoordinate);
    void setYCoordinate(unsigned int yCoordinate);
    void setConfigEntered(bool configEntered);
    void setRadius(unsigned int radius);
    void setGravity(double gravity);
    void setXVelocity(double xVelocity);
    void setYVelocity(double yVelocity);

    unsigned int getXCoordinate();
    unsigned int getYCoordinate();
    double getXVelocity();
    double getYVelocity();
    unsigned int getRadius();
    double getGravity();
    bool getConfigEntered();

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_radius;

    unsigned int m_xVelocity;
    unsigned int m_yVelocity;

    double m_gravity;

    bool m_configEntered;
};

#endif // CONFIGURATION_H
