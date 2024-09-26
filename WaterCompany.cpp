#include "WaterCompany.hpp"

WaterCompany::WaterCompany() :Square("Default waterSquare"), price(150) {}
WaterCompany::WaterCompany(std::string name) : Square(name) ,  price(150) {}


float WaterCompany::getPrice()
{
    return price;
}


void WaterCompany::display(std::ostream& os) const
{
    os << name << std::endl;
}