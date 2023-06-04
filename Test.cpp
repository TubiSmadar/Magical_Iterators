#include "doctest.h"
#include <iostream>
#include <vector>
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test Case 1 - Testing MagicalContainer and its methods")
{
    MagicalContainer mc;
    CHECK(mc.size() == 0);

    // Test addElement()
    mc.addElement(5);
    mc.addElement(3);
    mc.addElement(7);

    CHECK(mc.size() == 3);
    CHECK_NOTHROW(mc.addElement(1));

    // Test removeElement()
    mc.removeElement(5);

    CHECK(mc.size() == 2);
    CHECK_NOTHROW(mc.removeElement(5));
    // Attempt to delete an element that doesn't exist
    CHECK_NOTHROW(mc.removeElement(0));
}


TEST_CASE("Test Case 2 - Testing AscendingIterator - (==, !=, =) operators")
{
    MagicalContainer mc;
    mc.addElement(2);
    mc.addElement(4);
    mc.addElement(6);

    MagicalContainer::AscendingIterator ascIter1(mc);
    MagicalContainer::AscendingIterator ascIter2(mc);

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter2 = ascIter1);
    CHECK(ascIter2 == ascIter1);
    ++ascIter1;
    CHECK(ascIter1 != ascIter2);

    // Test comparison with different containers
    MagicalContainer mc2;
    mc2.addElement(1);
    mc2.addElement(3);
    mc2.addElement(5);

    MagicalContainer::AscendingIterator ascIter3(mc2);

    // AscendingIterator should not be equal to an iterator from a different container
    CHECK(ascIter1 != ascIter3);

    // Assigning an iterator from a different container should throw an exception
    CHECK_THROWS_AS(ascIter2 = ascIter3, std::exception);
}


TEST_CASE("Test Case 3 - Testing AscendingIterator - >, < operators")
{
    MagicalContainer mc1;
    mc1.addElement(1);
    mc1.addElement(3);
    mc1.addElement(5);

    MagicalContainer mc2;
    mc2.addElement(2);
    mc2.addElement(4);
    mc2.addElement(6);

    MagicalContainer::AscendingIterator ascIter1(mc1);
    MagicalContainer::AscendingIterator ascIter2(mc2);

    CHECK_NOTHROW(ascIter1 > ascIter2);
    CHECK_NOTHROW(ascIter1 < ascIter2);

    // AscendingIterator from mc1 should be less than AscendingIterator from mc2
    CHECK(ascIter1 < ascIter2 == true);
    ++ascIter1;

    // After incrementing ascIter1, it should no longer be less than ascIter2
    CHECK(ascIter1 < ascIter2 == false);

    // Test comparison with same container
    MagicalContainer::AscendingIterator ascIter3(mc1);

    // AscendingIterator pointing to the same element should not be greater or less than each other
    CHECK_FALSE(ascIter1 > ascIter3);
    CHECK_FALSE(ascIter1 < ascIter3);

    // AscendingIterator pointing to different elements in the same container can have > or < relationship
    CHECK(ascIter2 > ascIter3);
    CHECK(ascIter3 < ascIter2);
}


TEST_CASE("Test Case 4 - Testing AscendingIterator - * operator")
{
    MagicalContainer mc1;
    mc1.addElement(1);
    mc1.addElement(2);
    mc1.addElement(3);

    MagicalContainer mc2;
    mc2.addElement(4);
    mc2.addElement(5);
    mc2.addElement(6);

    MagicalContainer::AscendingIterator ascIter1(mc1);
    MagicalContainer::AscendingIterator ascIter2(mc2);

    CHECK(*ascIter1 == 1);
    ++ascIter1;
    CHECK(*ascIter1 == 2);

    // Test dereferencing iterator from different containers
    CHECK(*ascIter2 == 4);
    ++ascIter2;
    CHECK(*ascIter2 == 5);
}


TEST_CASE("Test Case 5 - Testing AscendingIterator - begin and end")
{
    // Initialize MagicalContainer and add elements
    MagicalContainer mc1;
    mc1.addElement(1);

    // Create AscendingIterator and check begin() and end()
    MagicalContainer::AscendingIterator ascIter1(mc1);
    CHECK_NOTHROW(ascIter1.begin());
    CHECK_NOTHROW(ascIter1.end());
}

TEST_CASE("Test Case 6 - Testing SideCrossIterator - ==, != , = operators")
{
    // Initialize MagicalContainer and create SideCrossIterators
    MagicalContainer mc;
    MagicalContainer::SideCrossIterator crossIter1(mc);
    MagicalContainer::SideCrossIterator crossIter2(mc);

    // Test equality and inequality operators
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator crossIter2 = crossIter1);
    CHECK(crossIter2 == crossIter1);
    ++crossIter1;
    CHECK(crossIter1 != crossIter2);
}

TEST_CASE("Test Case 7 - Testing SideCrossIterator - > , < operators")
{
    // Initialize MagicalContainers and create SideCrossIterators
    MagicalContainer mc1;
    MagicalContainer mc2;
    mc1.addElement(1);
    mc1.addElement(2);
    mc2.addElement(3);
    MagicalContainer::SideCrossIterator crossIter1(mc1);
    MagicalContainer::SideCrossIterator crossIter2(mc2);

    // Test greater than and less than operators
    CHECK_NOTHROW(crossIter1 > crossIter2);
    CHECK_NOTHROW(crossIter1 < crossIter2);
}

TEST_CASE("Test Case 8 - Testing SideCrossIterator - operator *")
{
    // Initialize MagicalContainer and create SideCrossIterator
    MagicalContainer mc1;
    mc1.addElement(1);
    MagicalContainer::SideCrossIterator crossIter1(mc1);

    // Test dereferencing operator
    CHECK(*crossIter1 == 1);
    ++crossIter1;
    CHECK(*crossIter1 == 2);
}

TEST_CASE("Test Case 9 - Testing SideCrossIterator - begin and end")
{
    // Initialize MagicalContainer and create SideCrossIterator
    MagicalContainer mc1;
    mc1.addElement(1);
    MagicalContainer::SideCrossIterator crossIter1(mc1);

    // Check begin() and end()
    CHECK_NOTHROW(crossIter1.begin());
    CHECK_NOTHROW(crossIter1.end());
}

TEST_CASE("Test Case 10 - Testing PrimeIterator - ==, != , = operators")
{
    // Initialize MagicalContainer and create PrimeIterators
    MagicalContainer mc;
    MagicalContainer::PrimeIterator primeIter1(mc);
    MagicalContainer::PrimeIterator primeIter2(mc);

    // Test equality and inequality operators
    CHECK_NOTHROW(MagicalContainer::PrimeIterator primeIter2 = primeIter1);
    CHECK(primeIter2 == primeIter1);
    ++primeIter1;
    CHECK(primeIter1 != primeIter2);
}

TEST_CASE("Test Case 11 - Testing PrimeIterator - > , < operators")
{
    // Initialize MagicalContainers and create PrimeIterators
    MagicalContainer mc1;
    MagicalContainer mc2;
    mc1.addElement(1);
    mc1.addElement(2);
    mc2.addElement(3);
    MagicalContainer::PrimeIterator primeIter1(mc1);
    MagicalContainer::PrimeIterator primeIter2(mc2);

    // Test greater than and less than operators
    CHECK_NOTHROW(primeIter1 > primeIter2);
    CHECK_NOTHROW(primeIter1 < primeIter2);
}

TEST_CASE("Test Case 12 - Testing PrimeIterator - operator *")
{
    // Initialize MagicalContainer and create PrimeIterator
    MagicalContainer mc1;
    mc1.addElement(1);
    MagicalContainer::PrimeIterator primeIter1(mc1);

    // Test dereferencing operator
    CHECK(*primeIter1 == 1);
    ++primeIter1;
    CHECK(*primeIter1 == 2);
}

TEST_CASE("Test Case 13 - Testing PrimeIterator - begin and end")
{
    // Initialize MagicalContainer and create PrimeIterator
    MagicalContainer mc1;
    mc1.addElement(1);
    MagicalContainer::PrimeIterator primeIter1(mc1);

    // Check begin() and end()
    CHECK_NOTHROW(primeIter1.begin());
    CHECK_NOTHROW(primeIter1.end());
}