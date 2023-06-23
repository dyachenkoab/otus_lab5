#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <iostream>
#include <string>
#include <vector>

struct Coordinates
{
    float x = 0;
    float y = 0;

    bool operator==(const Coordinates &rp);
};

class GraphicElement
{
public:
    GraphicElement(std::vector<Coordinates> coords, std::string color);
    virtual ~GraphicElement() = default;

    virtual bool isSame(const std::vector<Coordinates> &coordinates) = 0;

protected:
    std::vector<Coordinates> m_coordinates;
    std::string m_color;
};

class Line : public GraphicElement
{
public:
    Line(std::vector<Coordinates> coords, std::string color);
    ~Line();

    bool isSame(const std::vector<Coordinates> &coordinates) override;
};

class Square : public GraphicElement
{
public:
    Square(std::vector<Coordinates> coords, std::string color);
    ~Square();

    bool isSame(const std::vector<Coordinates> &coordinates) override;
};

class Triangle : public GraphicElement
{
public:
    Triangle(std::vector<Coordinates> coords, std::string color);
    ~Triangle();

    bool isSame(const std::vector<Coordinates> &coordinates) override;
};

#endif // ELEMENTS_H
