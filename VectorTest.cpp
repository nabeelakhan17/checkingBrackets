//
// Created by nabee on 10/26/2022.
//

#include "catch2/catch.hpp"
#include "DSStackVector.h"

TEST_CASE("Check that DSVector works", "[DSStackVector]")
{
    //testing if the index is working, this is mainly just for running  my tests
    SECTION("Testing index...")
    {
        StackVector<int> list;
        list.push(5);
        list.push(8);
        list.push(9);
        REQUIRE(list.index(1) == 8);
        REQUIRE(list.index(2) == 5);
        REQUIRE(list.index(0) == 9);


    }
    //testing to make sure that the list is empty
    SECTION("Testing empty...")
    {
        StackVector<int> list;
        REQUIRE(list.empty());
        list.push(5);
        list.pop();
        REQUIRE(list.empty());
        list.push(8);
        list.push(9);
        REQUIRE(!list.empty());

    }
    //testing to see if the stack vector returns the correct size
    SECTION("Testing size")
    {
        StackVector<int> list;
        list.push(5);
        REQUIRE(list.size() == 1);
        list.push(8);
        REQUIRE(list.size() == 2);
        list.push(9);
        REQUIRE(list.size() == 3);
    }
    //making sure that the push method is working correctly
    SECTION("Testing push")
    {
        StackVector<int> list;
        list.push(5);
        list.push(8);
        list.push(9);
        REQUIRE(list.size() == 3);
        REQUIRE(list.index(0) == 9);
        StackVector<int> list2;
        list2.push(2);
        list2.push(7);
        REQUIRE(list2.size() == 2);
        REQUIRE(list2.index(0) == 7);
    }
    //making sure that the pop is working and removing the element
    SECTION("Testing pop")
    {
        StackVector<int> list;
        list.push(5);
        list.push(8);
        list.push(9);
        list.pop();
        REQUIRE(list.size() == 2);
        REQUIRE(list.index(0) == 8);
        list.pop();
        REQUIRE(list.size() == 1);
        REQUIRE(list.index(0) == 5);

    }
    //removing the top and making sure it is correct
    SECTION("Testing top")
    {
        StackVector<int> list;
        list.push(5);
        REQUIRE(list.top() == 5);
        list.push(8);
        REQUIRE(list.top() == 8);
        list.push(9);
        REQUIRE(list.top() == 9);
    }

}

