#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"

// add includes


TEST_CASE("Check that DSList works", "[DSList]")
{

    // add test cases (create lists and specify what the expected output is)
    SECTION("Testing find...")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        REQUIRE(list.find(1) == 2);
        DSList<int> list2;
        list2.push_front(3);
        list2.push_front(4);
        list2.push_front(5);
        REQUIRE(list2.find(4) == 1);
        DSList<int> list3;
        list3.push_front(6);
        REQUIRE(list3.find(6) == 0);
    }

    SECTION("Testing size...")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        REQUIRE(list.size() == 3);
        list.push_front(4);
        REQUIRE(list.size() == 4);
        list.pop_front();
        REQUIRE(list.size() == 3);
    }

    SECTION("Testing empty...")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        REQUIRE(list.empty() == false);
        DSList<int> list2;
        REQUIRE(list2.empty() == true);
        list2.push_front(1);
        REQUIRE(list2.empty() == false);


    }

    SECTION("Testing clear...")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        REQUIRE(list.size() == 3);
        list.clear();
        REQUIRE(list.size() == 0);
        DSList<int> list2;
        list.push_front(3);
        list.push_front(4);
        list.clear();
        REQUIRE(list.size() == 0);
        REQUIRE(list.empty());
    }

    SECTION("Testing copy constructor...")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        DSList<int> newList = DSList(list);

        REQUIRE(newList[2] == list[2]);
         REQUIRE(newList[1] == list[1]);
         REQUIRE(newList[0] == list[0]);


    }

    SECTION("Testing push_front....")
    {
        DSList<int> list;
        list.push_front(3);
        REQUIRE(list[0] == 3);
        list.push_front(1);
        REQUIRE(list[0] == 1);
        list.push_front(2);
        REQUIRE(list[0] == 2);

    }
    SECTION("Testing pop_front....")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(3);
        list.pop_front();
        REQUIRE(list.size() == 1);
        REQUIRE(list[0] == 1);
        list.pop_front();
        REQUIRE(list.empty());
    }
    SECTION("Testing remove....")
    {
        DSList<int> list;
        list.push_front(1);
        list.remove(0);
        REQUIRE(list.empty());
        list.push_front(5);
        list.push_front(6);
        list.remove(1);

        REQUIRE(list[0] == 6);
    }
    SECTION("Testing find_remove...")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.find_remove(2);
        REQUIRE(list.size() == 2);
        REQUIRE(list[1] == 1);
        list.find_remove(3);
        REQUIRE(list[0] == 1);

    }

    SECTION("Testing insert....")
    {
        DSList<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.insert(4, 2);
        REQUIRE(list[2] ==4);
        list.insert(5, 3);
        REQUIRE(list[3] ==5);
        list.insert(6, 4);
        REQUIRE(list[4] ==6);

    }

}

// you can run the test using Run CTest in the task bar or by running the tests executable.