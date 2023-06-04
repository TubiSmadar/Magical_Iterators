#include "MagicalContainer.hpp"

namespace ariel{

    void MagicalContainer::addElement(int element){
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element){

    }

    size_t MagicalContainer::size() const{
        return elements.size();
    }
}