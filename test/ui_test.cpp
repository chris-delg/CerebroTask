#include <gtest/gtest.h>
#include <fstream>
#include "../include/ui.hpp"
using namespace std;

// UI Tests
TEST(UIPageChange, ChangesCurrentPage)
{
    UI ui;
    int newPage = 1;
    ui.changePage(newPage);
    ASSERT_EQ(ui.getPageNum(), newPage);
}

TEST(UIPageChange, OutOfBoundsPage)
{
    UI ui;
    int pageInvalid = 5;
    ui.changePage(pageInvalid);
    ASSERT_EQ(ui.getPageNum(), 0);
}

TEST(UIInitialization, CorrectInitialization)
{
    UI ui;
    EXPECT_EQ(ui.size(), 2);
    EXPECT_TRUE(ui.getLoginPage() != nullptr);
    EXPECT_TRUE(ui.getHomePage()  != nullptr);
    EXPECT_EQ(ui.getPageNum(), 0);
}

// Login page Tests

TEST(LoginPageTests, Constructor) 
{
    LoginPage loginpage;

    EXPECT_EQ("Welcome to CerebroTask : The AI Assisted Task Scheduler\n", loginpage.getLine(0,0));
    EXPECT_EQ("---\n", loginpage.getLine(1,0));

    EXPECT_EQ("Login Options:\n", loginpage.getLine(0,1));
    EXPECT_EQ("l - login\n", loginpage.getLine(1,1));
    EXPECT_EQ("q - quit\n", loginpage.getLine(2,1));
}

TEST(LoginPageTests, Login) 
{
    string input_string = "testuser1\ncleverpassword\ntest user\ntestuser2\nclevererpassword\n";
    stringstream test_input(input_string);
    string test_user = "user1";
    string test_pass = "pass1";
    LoginPage loginpage;

    loginpage.login(test_user, test_pass, test_input);

    EXPECT_EQ(test_user, "testuser1");
    EXPECT_EQ(test_pass, "cleverpassword");

    loginpage.login(test_user, test_pass, test_input);

    EXPECT_EQ(test_user, "testuser2");
    EXPECT_EQ(test_pass, "clevererpassword");
}

// Home page tests

TEST(HomePageTests, Constructor) 
{
    HomePage homepage;

    EXPECT_EQ("HOMEPAGE\n", homepage.getLine(0,0));
    EXPECT_EQ("---\n", homepage.getLine(1,0));

    EXPECT_EQ("Homepage Options:\n", homepage.getLine(0,1));
    EXPECT_EQ("a - ask AI for advice on current task\n", homepage.getLine(1,1));
    EXPECT_EQ("e - edit current task\n", homepage.getLine(2,1));
    EXPECT_EQ("c - create new task\n", homepage.getLine(3,1));
    EXPECT_EQ("s - select different task\n", homepage.getLine(4,1));
    EXPECT_EQ("l - logout\n", homepage.getLine(5,1));
}

TEST(HomePageTests, TaskChange) 
{
    HomePage homepage;

    EXPECT_EQ(0, homepage.getCurrTask());    
    homepage.changeTask(1);
    EXPECT_EQ(1, homepage.getCurrTask()); 
    homepage.changeTask(2);
    EXPECT_EQ(2, homepage.getCurrTask()); 
}