#include "MagicalContainer.hpp"

namespace ariel{
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    :container(container), index(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t index)
    : container(container), index(index) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other):
    container(other.container), index(other.index) {}

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        return SideCrossIterator(*this);
    }

     MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
    {
        return SideCrossIterator(container, container.size());
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        if(this != &other)
        {
            container = other.container;
            index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
    {
        return index == other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
    {
        return index != other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
    {
        return index < other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
    {
        return index > other.index;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return index;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
    {
        ++index;
        return *this;
    }
}