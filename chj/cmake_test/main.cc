#include <iostream>

#include "shape.h"

int main(){
    Rectangle *rec = new Rectangle(10,10);

    std::cout << "Get size :  " << rec->GetSize() << std::endl;

    return 0;
}