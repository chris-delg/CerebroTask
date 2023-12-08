#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "../include/OpenaiAPI.hpp"

using namespace std;

TEST(OpenaiTests, GetOutputNoApiKey){
    OpenaiAPI ai;

    EXPECT_EQ(ai.getOutput(), "");
}

TEST(OpenaiTests, GetOutputNoPrompt){
    OpenaiAPI ai;
    string key = "";

    ai.setApiKey();

    EXPECT_EQ(ai.getOutput(), "");
}

TEST(OpenaiTests, GetOutputTestPrompt){
    OpenaiAPI ai;
    string key = "";
    string task = "";

    ai.setApiKey();

    task = "Say this is a test";
    ai.setPrompt(task);

    string ans = ai.getOutput();
    
    EXPECT_EQ(ans, "This is a test.");
}
