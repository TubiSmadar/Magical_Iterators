#include "MagicalContainer.hpp"

namespace ariel{
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    :container(container), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index)
    : container(container), index(index) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other):
    container(other.container), index(other.index) {}

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
    {
        return AscendingIterator(*this);
    }

     MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
    {
        return AscendingIterator(container, container.size());
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
    {
        if(this != &other)
        {
            container = other.container;
            index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
    {
        return index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
    {
        return index != other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
    {
        return index < other.index;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
    {
        return index > other.index;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return index;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
    {
        ++index;
        return *this;
    }
}