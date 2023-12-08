#include "../include/homepage.hpp"
using namespace std;

HomePage::HomePage()
{
    main_text[0] = "HOMEPAGE\n";
    main_text[1] = "---\n";

    main_text[9] = "Input not recognized. Try again:\n";

    options_text[0] = "Homepage Options:\n";
    options_text[1] = "a - ask AI for advice on current task\n";
    options_text[2] = "e - edit current task\n";
    options_text[3] = "c - create new task\n";
    options_text[4] = "s - select different task\n";
    options_text[5] = "l - logout\n";

    options_text[9] = "Logging out...\n";
};

void HomePage::printPageMainText()
{
    for (int i = 0; i < 2; i++)
    {
        cout << main_text[i];
    }
};

void HomePage::printPageOptions()
{
    for (int i = 0; i < 6; i++)
    {
        cout << options_text[i];
    }
};

void HomePage::printPageInputError()
{
    cout << main_text[9];
};

string HomePage::getLine(int line, int text)
{
    switch (text)
    {
    case 0: // main_text
        return main_text[line];
    case 1: // options_text
        return options_text[line];
    }
    return "";
};

void HomePage::changeTask(int new_task)
{
    curr_task = new_task;
}

void HomePage::printEditTask(string &new_details, string &new_date, /* int &new_priority,*/ istream &input)
{
    string temp;
    cout << "Editing Current task...\n---\n";
    cout << "Change task description? Type y to change, any other key to skip.\n";
    getline(input, temp);
    if (temp == "y")
    {
        cout << "Enter new task details...\n";
        getline(input, temp);
        new_details = temp;
    }
    cout << "Change task due date? Type y to change, any other key to skip.\n";
    getline(input, temp);
    if (temp == "y")
    {
        cout << "Enter new task due date...\n";
        getline(input, temp);
        new_date = temp;
    }
    // cout << "Change task priority? Type y to change, any other key to skip.\n";
    // getline(input, temp);
    // if(temp == "y") {
    //     cout << "Enter new task priority...\n";
    //     getline(input, temp);
    //     new_priority = temp;
    // }
    cout << "Finalizing task editing...\n---\n";
}

void HomePage::printCreateTask(string &taskDetails, string &taskDueDate, int &taskPriority, istream &input)
{
    cout << "Creating a new task...\n---\n";

    cout << "Enter task details: ";
    getline(input, taskDetails);

    cout << "Enter task due date: ";
    getline(input, taskDueDate);

    cout << "Enter task priority from 1 to 3 (1 being low and 3 being high): ";
    input >> taskPriority;

    while (taskPriority < 1 || taskPriority > 3)
    {
        cout << "Invalid input. Priority must be between 1 and 3. Please try again: ";
        input >> taskPriority;
    }

    cout << "\nNew Task Created:\n";
    cout << "Task Details: " << taskDetails << endl;
    cout << "Task Due Date: " << taskDueDate << endl;
    cout << "Task Priority: " << taskPriority << endl;
    cout << "Task created succesfully!\n";
}

void HomePage::printAIResponse(string task)
{
    string prompt = "Give step by step instructions on completing this task: ";
    ai.setApiKey();
    prompt += task;
    ai.setPrompt(task);
    cout << ai.getOutput() << endl;
}