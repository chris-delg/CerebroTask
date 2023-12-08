#include "gtest/gtest.h"
#include "../include/UserData.hpp"
#include "../include/UserTxtData.hpp"
#include "../include/UserBinData.hpp"
#include "../include/User.hpp"

#include <unordered_map>

using namespace std;

TEST(TextFileTest, SetUserTest){
    UserTxtData text;
    User u("chris", "1", "password");

    text.setUser(&u);

    EXPECT_EQ(text.getUser()->getUsername(), "chris");
    EXPECT_EQ(text.getUser()->getPassword(), "password");
}

TEST(TextFileTest, GetLoginMapTest){
    UserTxtData text;
    User u("chris", "1", "password");

    text.setUser(&u);

    ASSERT_EQ(text.getLoginMap().count("chris"), 1);
    EXPECT_EQ(text.getLoginMap()["chris"], "password");
}

TEST(TextFileTest, WritingAndReadingTextTest1){
    UserTxtData text;
    User u("chris", "1", "password");

    text.setUser(&u);
    unordered_map<string, string> beforeWriting;
    beforeWriting["chris"] = "password";
    text.writeData("test/testTxtFiles/test.txt");
    text.readData("test/testTxtFiles/test.txt");

    ASSERT_EQ(text.getLoginMap().count("chris"), beforeWriting.count("chris"));
    EXPECT_EQ(text.getLoginMap(), beforeWriting);
}

TEST(TextFileTest, WritingAndReadingTextTest2){
    UserTxtData text;
    User u("chris", "1", "password");

    text.setUser(&u);
    unordered_map<string, string> beforeWriting = text.getLoginMap();
    text.writeData("test/testTxtFiles/test.txt");
    text.readData("test/testTxtFiles/test.txt");

    ASSERT_EQ(text.getLoginMap().count("chris"), beforeWriting.count("chris"));
    EXPECT_EQ(text.getLoginMap(), beforeWriting);
}

TEST(TextFileTest, ReadingMultipleLines){
    UserTxtData text;

    text.readData("test/testTxtFiles/testMultipleLines.txt");
    unordered_map<string, string> testMap = text.getLoginMap();

    EXPECT_EQ(testMap["chris"], "password");
    EXPECT_EQ(testMap["rachel"], "Ilcsmbmh4");
    EXPECT_EQ(testMap["dorian"], "pants123");
    EXPECT_EQ(testMap["mahir"], "glass44");
    EXPECT_EQ(testMap["saif"], "bb2345");
}

TEST(TextFileTest, WritingMultipleLines){
    UserTxtData text;
    UserTxtData text2;

    text.readData("test/testTxtFiles/testMultipleLines.txt");
    text.writeData("test/testTxtFiles/testMultipleLines2.txt");

    text2.readData("test/testTxtFiles/testMultipleLines2.txt");

    EXPECT_EQ(text.getLoginMap()["chris"], text2.getLoginMap()["chris"]);
    EXPECT_EQ(text.getLoginMap()["rachel"], text2.getLoginMap()["rachel"]);
    EXPECT_EQ(text.getLoginMap()["dorian"], text2.getLoginMap()["dorian"]);
    EXPECT_EQ(text.getLoginMap()["mahir"], text2.getLoginMap()["mahir"]);
    EXPECT_EQ(text.getLoginMap()["saif"], text2.getLoginMap()["saif"]);
}

TEST(TextFileTest, WritingMultipleLinesFileClass){
    UserData* text = new UserTxtData();
    UserData* text2 = new UserTxtData();

    text->readData("test/testTxtFiles/testMultipleLines.txt");
    text->writeData("test/testTxtFiles/testMultipleLines2.txt");

    text2->readData("test/testTxtFiles/testMultipleLines2.txt");

    EXPECT_EQ(text->getLoginMap()["chris"], text2->getLoginMap()["chris"]);
    EXPECT_EQ(text->getLoginMap()["rachel"], text2->getLoginMap()["rachel"]);
    EXPECT_EQ(text->getLoginMap()["dorian"], text2->getLoginMap()["dorian"]);
    EXPECT_EQ(text->getLoginMap()["mahir"], text2->getLoginMap()["mahir"]);
    EXPECT_EQ(text->getLoginMap()["saif"], text2->getLoginMap()["saif"]);
}

//Binary file tests
TEST(BinFileTest, ReadingBinData){
    UserData* writerBin = new UserBinData();
    UserData* readerBin = new UserBinData();
    User u("chris", "1", "password");
    string testPrompt[3] = {"first task", "second task", "third task"};

    writerBin->setUser(&u);
    readerBin->setUser(&u);

    writerBin->getUser()->getTasks()[0].setTask(testPrompt[0], 1);
    writerBin->getUser()->getTasks()[1].setTask(testPrompt[1], 2);
    writerBin->getUser()->getTasks()[2].setTask(testPrompt[2], 2);

    writerBin->writeData("test/testBinFiles/binTest.dat");
    readerBin->readData("test/testBinFiles/binTest.dat");

    EXPECT_EQ(writerBin->getUser()->getTasks()[0].getTaskDetails(), readerBin->getUser()->getTasks()[0].getTaskDetails());
    EXPECT_EQ(writerBin->getUser()->getTasks()[1].getTaskDetails(), readerBin->getUser()->getTasks()[1].getTaskDetails());
    EXPECT_EQ(writerBin->getUser()->getTasks()[2].getTaskDetails(), readerBin->getUser()->getTasks()[2].getTaskDetails());
}

TEST(BinFileTest, ReadingBinDataCompareToLiterals){
    UserData* writerBin = new UserBinData();
    UserData* readerBin = new UserBinData();
    User u("chris", "1", "password");
    string testPrompt[3] = {"first task", "second task", "third task"};

    writerBin->setUser(&u);
    readerBin->setUser(&u);

    writerBin->getUser()->getTasks()[0].setTask(testPrompt[0], 1);
    writerBin->getUser()->getTasks()[1].setTask(testPrompt[1], 2);
    writerBin->getUser()->getTasks()[2].setTask(testPrompt[2], 3);

    writerBin->writeData("test/testBinFiles/binTest2.dat");
    readerBin->readData("test/testBinFiles/binTest2.dat");

    EXPECT_EQ(writerBin->getUser()->getTasks()[0].getTaskDetails(), testPrompt[0]);
    EXPECT_EQ(writerBin->getUser()->getTasks()[1].getTaskDetails(), testPrompt[1]);
    EXPECT_EQ(writerBin->getUser()->getTasks()[2].getTaskDetails(), testPrompt[2]);

    EXPECT_EQ(readerBin->getUser()->getTasks()[0].getTaskDetails(), testPrompt[0]);
    EXPECT_EQ(readerBin->getUser()->getTasks()[1].getTaskDetails(), testPrompt[1]);
    EXPECT_EQ(readerBin->getUser()->getTasks()[2].getTaskDetails(), testPrompt[2]);
}
