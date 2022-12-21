//
// Created by nabee on 10/25/2022.
//
#include "catch2/catch.hpp"
#include "DSStack.h"
//completing the tests for the StackList Class
TEST_CASE("Check that DSStack works", "[DSStack]")
{
    //testing the push method for the stack list
    SECTION("Testing push...")
    {
        DSStack<int> nums;
        nums.push(5);
        REQUIRE(nums.size() == 1);
        nums.push(6);
        nums.push(7);
        nums.push(9);
        REQUIRE(nums.size()==4);
        nums.push(8);
        REQUIRE(nums.size()==5);
    }
    //making sure that the first element is returned from the stack
    SECTION("Testing top... ")
    {
        DSStack<int> nums;
        nums.push(5);
        REQUIRE(nums.top() == 5);
        nums.push(6);
        REQUIRE(nums.top() == 6);
        nums.push(7);
        REQUIRE(nums.top()==7);

    }
    //removing the first element
    SECTION("Testing pop... ")
    {
        DSStack<int> nums;
        nums.push(5);
        nums.pop();
        REQUIRE(nums.empty());
        nums.push(6);
        nums.push(8);
        nums.pop();
        REQUIRE(nums.size() == 1);
        nums.pop();
        REQUIRE(nums.size()==0);
    }
//seeing if the test is empty
    SECTION("Testing empty... ")
    {
        DSStack<int> nums;
        nums.push(5);
        REQUIRE(!nums.empty());
        nums.pop();
        REQUIRE(nums.empty());
        nums.push(6);
        nums.push(8);
        REQUIRE(!nums.empty());

    }
    // returning the size of the stack
    SECTION("Testing size... ")
    {
        DSStack<int> nums;
        nums.push(5);
        REQUIRE(nums.size() ==1);
        nums.push(6);
        REQUIRE(nums.size() ==2);
        nums.push(8);
        REQUIRE(nums.size() ==3);
    }


}