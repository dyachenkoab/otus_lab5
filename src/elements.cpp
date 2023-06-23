#include "elements.h"

bool Coordinates::operator==(const Coordinates &rp)
{
    return x == rp.x && y == rp.y;
}

GraphicElement::GraphicElement(std::vector<Coordinates> coords, std::string color)
    : m_coordinates(std::move(coords))
    , m_color(std::move(color))
{
}

Line::Line(std::vector<Coordinates> coords, std::string color)
    : GraphicElement(std::move(coords), std::move(color))
{
    std::cout << "Create " << m_color << " Line" << std::endl;
}

Line::~Line()
{
    std::cout << "Destroy " << m_color << " Line" << std::endl;
}

bool Line::isSame(const std::vector<Coordinates> &coordinates)
{
    if (!coordinates.empty()) {
        return m_coordinates.at(0) == coordinates.at(0)
               && m_coordinates.at(1) == coordinates.at(1);
    }
    return false;
}

Square::Square(std::vector<Coordinates> coords, std::string color)
    : GraphicElement(std::move(coords), std::move(color))
{
    std::cout << "Create " << m_color << " Square" << std::endl;
}

Square::~Square()
{
    std::cout << "Destroy " << m_color << " Square" << std::endl;
}

bool Square::isSame(const std::vector<Coordinates> &coordinates)
{
    if (coordinates.size() > 3) {
        return m_coordinates.at(0) == coordinates.at(0)
               && m_coordinates.at(1) == coordinates.at(1)
               && m_coordinates.at(2) == coordinates.at(2)
               && m_coordinates.at(3) == coordinates.at(3);
    }
    return false;
}

Triangle::Triangle(std::vector<Coordinates> coords, std::string color)
    : GraphicElement(std::move(coords), std::move(color))
{
    std::cout << "Create " << m_color << " Triangle" << std::endl;
}

Triangle::~Triangle()
{
    std::cout << "Destroy " << m_color << " Triangle" << std::endl;
}

bool Triangle::isSame(const std::vector<Coordinates> &coordinates)
{
    if (coordinates.size() > 1) {
        return m_coordinates.at(0) == coordinates.at(0)
               && m_coordinates.at(1) == coordinates.at(1)
               && m_coordinates.at(2) == coordinates.at(2);
    }
    return false;
}
