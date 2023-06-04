#pragma once
#include <vector>

using namespace std;


namespace ariel
{
    class MagicalContainer
    {
        private:
        vector<int> elements;

        public:
        void addElement(int element);
        void removeElement(int element);
        size_t size() const;


        class AscendingIterator{
            MagicalContainer& container;
            size_t index;

            public:
            AscendingIterator(MagicalContainer& container);
            AscendingIterator(MagicalContainer& container, size_t index);
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator() = default;

            AscendingIterator begin() const;
            AscendingIterator end() const;

            AscendingIterator& operator=(const AscendingIterator& other);
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            int operator*();
            AscendingIterator& operator++();
        };

        class PrimeIterator{
            MagicalContainer& container;
            size_t index;

            public:
            PrimeIterator(MagicalContainer& container);
            PrimeIterator(MagicalContainer& container, size_t index);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator() = default;

            PrimeIterator begin() const;
            PrimeIterator end() const;

            PrimeIterator& operator=(const PrimeIterator& other);
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            int operator*();
            PrimeIterator& operator++();
        };

        class SideCrossIterator{
            MagicalContainer& container;
            size_t index;

            public:
            SideCrossIterator(MagicalContainer& container);
            SideCrossIterator(MagicalContainer& container, size_t index);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator() = default;

            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator<(const  SideCrossIterator& other) const;
            bool operator>(const  SideCrossIterator& other) const;
            int operator*();
            SideCrossIterator& operator++();
        };
    };
}