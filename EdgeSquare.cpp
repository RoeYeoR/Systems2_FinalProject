#include "EdgeSquare.hpp"


EdgeSquare::EdgeSquare(std::string name,EdgeSquareType esType) :Square(name), type(esType) {}


 EdgeSquareType EdgeSquare::getType()
 {
    return type;
 }

 void EdgeSquare::display(std::ostream& os) const 
 {
    os << "EdgeSquare: " << type << std::endl;

 }

  std::string EdgeSquare::display() const 
 {
    std::ostringstream os;
    os << "EdgeSquare: " << type << std::endl;
    return os.str();
 }