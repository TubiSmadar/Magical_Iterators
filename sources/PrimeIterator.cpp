#include "MagicalContainer.hpp"

namespace ariel{
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    :container(container), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, size_t index)
    : container(container), index(index) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other):
    container(other.container), index(other.index) {}

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
    {
        return PrimeIterator(*this);
    }

     MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
    {
        return PrimeIterator(container, container.size());
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
    {
        if(this != &other)
        {
            container = other.container;
            index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
    {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
    {
        return index != other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
    {
        return index < other.index;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
    {
        return index > other.index;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return index;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
    {
        ++index;
        return *this;
    }
}