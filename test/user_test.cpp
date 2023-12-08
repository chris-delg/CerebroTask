#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../include/User.hpp"
#include "../include/Task.hpp"

#include <string>

/**
 * This test fall under the UserTest suite and testname is DefaultConstructorTest
 * Checks whether my default constructor is empty or not.
 */
TEST(UserTest, DefaultConstructorTest)
{
    User user;
    ASSERT_EQ("", user.getUsername());
    ASSERT_EQ("", user.getId());
    ASSERT_EQ("", user.getPassword());
}

/**
 * This test fall under the UserTest suite and testname is ParameterizedConstructorTest
 * Checks whether my constructor is initializing the attributes correctly or not.
 */
TEST(UserTest, ParameterizedConstructorTest)
{
    User user("MahirPatel3130", "862338784", "password1234");
    ASSERT_EQ("MahirPatel3130", user.getUsername());
    ASSERT_EQ("862338784", user.getId());
    ASSERT_EQ("password1234", user.getPassword());
}

/**
 * This test fall under the UserTest suite and testname is SettersAndGetters
 * Checks whether my getters and setters are working properly or not.
 */
TEST(UserTest, SettersAndGetters)
{
    User user;
    string name = "Alice";
    string id = "UserID456";
    string password = "newPassword";
    user.setUsername(name);
    ASSERT_EQ("Alice", user.getUsername());

    user.setId(id);
    ASSERT_EQ("UserID456", user.getId());

    user.setPassword(password);
    ASSERT_EQ("newPassword", user.getPassword());
}

TEST(UserTest, getTaskTest){
    User user;
    string testPrompt = "This is a test";

    user.getTasks()[0].setTask(testPrompt, 1);

    EXPECT_EQ(user.getTasks()[0].getTaskDetails(), "This is a test");
}

TEST(UserTest, getMultipleTaskTest){
    User user;
    string testPrompt[3] = {"first task", "second task", "third task"};

    user.getTasks()[0].setTask(testPrompt[0], 1);
    user.getTasks()[1].setTask(testPrompt[1], 1);
    user.getTasks()[2].setTask(testPrompt[2], 1);

    EXPECT_EQ(user.getTasks()[0].getTaskDetails(), testPrompt[0]);
    EXPECT_EQ(user.getTasks()[1].getTaskDetails(), testPrompt[1]);
    EXPECT_EQ(user.getTasks()[2].getTaskDetails(), testPrompt[2]);
}
