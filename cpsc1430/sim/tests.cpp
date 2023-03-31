#include <gtest/gtest.h>
#include "Location.h"
#include "Person.h"

using namespace std;

TEST(LocationTests, testAddPersonWhenNotFull)
{
    string placeholder = "test";
    Location test(placeholder, 1);
    Person jim;

    EXPECT_TRUE(test.addPerson(jim));
}

TEST(LocationTests, testAddPersonWhenFull)
{
    string placeholder = "test";
    Location test(placeholder, 1);
    Person jim;
    test.addPerson(jim);
    Person stacy;

    EXPECT_FALSE(test.addPerson(stacy));
}

TEST(LocationTests, testRemovePersonWhenPersonExists)
{
    string placeholder = "test";
    Location test(placeholder, 1);
    Person igor;
    test.addPerson(igor);
    EXPECT_TRUE(test.removePerson(0));
}

TEST(LocationTests, testGetName)
{
    string seattle = "seattle";
    Location test(seattle, 0);

    EXPECT_EQ(test.getName(), seattle);
}


TEST(LocationTests, testContainsPersonWhenPersonExists)
{
    string placeholder = "test";
    Location test(placeholder, 1);
    Person jim;
    test.addPerson(jim);

    EXPECT_TRUE(test.containsPerson(0));
}

TEST(LocationTests, testContainsPersonWhenDesiredPersonDNE)
{
    string placeholder = "test";
    Location test(placeholder, 1);

    EXPECT_FALSE(test.containsPerson(0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
