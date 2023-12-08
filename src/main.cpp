#include "../include/ui.hpp"
#include <iostream>

using namespace std;

int main()
{
    bool running = 1;
    bool first_boot = 0;
    bool homepage_action = 0;

    char option_input = 'z';
    string username;
    string password;

    int curr_task = -1;
    int total_task = 0;

    Task *task;
    User user;

    UI ui;

    ui.getLoginPage()->printPageMainText();

    ui.getLoginPage()->printPageOptions();

    UserData *data = new UserTxtData(); // handles user login save/load

    while (running)
    {
        cin >> option_input;
        cin.ignore();

        switch (ui.getPageNum())
        {       // transitions
        case 0: // login
            if (option_input == 'l')
            {
                ui.getLoginPage()->login(username, password, cin);

                data->readData("src/../data/users.txt");
                if (data->getLoginMap().count(username)) // username exists, confirm pass
                {
                    cout << "Welcome returning user!\n";
                    if (password == data->getLoginMap()[username]) // password matches
                    {
                        user.setUsername(username);
                        user.setId("1");
                        user.setPassword(password);

                        ui.getData()->setUser(&user);

                        // load user data from .dat file.
                        string save_file = "src/../data/dat_files/" + ui.getData()->getUser()->getUsername() + ".dat";
                        ui.getData()->readData(save_file);
                    }
                    else // password doesn't match
                    {
                        cout << "Password doesn't match... Aborting...\n";
                        break;
                    }
                }
                else
                { // username does not exist, make new user
                    cout << "Welcome new user!\n";

                    user.setUsername(username);
                    user.setId("1");
                    user.setPassword(password);

                    ui.getData()->setUser(&user);
                }
                first_boot = 1;
                ui.changePage(1);
            }
            else if (option_input == 'q')
            {
                cout << ui.getLoginPage()->getLine(9, 1);
                running = 0;
            }
            else
            {
                ui.getLoginPage()->printPageInputError();
            }
            break;
        case 1: // home
            if (option_input == 'l')
            {
                cout << ui.getHomePage()->getLine(9, 1);

                if (curr_task != -1)
                {
                    string save_file = "src/../data/dat_files/" + ui.getData()->getUser()->getUsername() + ".dat";
                    cout << "Saving " << ui.getData()->getUser()->getUsername() << "'s task information...\n";
                    ui.getData()->writeData(save_file); // saves task data
                }

                data->readData("src/../data/users.txt");
                if (!data->getLoginMap().count(ui.getData()->getUser()->getUsername()))
                {
                    data->setUser(ui.getData()->getUser());
                    cout << "Saving " << ui.getData()->getUser()->getUsername() << "'s new login information...\n";
                    data->writeData("src/../data/users.txt"); // saves login
                }

                first_boot = 1;
                curr_task = -1;
                total_task = 0;
                ui.changePage(0);
            }
            else if ((option_input == 'a') || (option_input == 'e') || (option_input == 'c') || (option_input == 's'))
            {
                homepage_action = 1;
            }
            else
            {
                ui.getHomePage()->printPageInputError();
            }
            break;
        };

        switch (ui.getPageNum())
        {       // actions
        case 0: // login
            if (first_boot)
            {
                ui.getLoginPage()->printPageMainText();
                first_boot = 0;
            }
            if (option_input != 'q')
            {
                ui.getLoginPage()->printPageOptions();
            }
            break;
        case 1: // home
            // update count of user tasks
            total_task = 0;
            while (ui.getData()->getUser()->getTasks()[total_task].getTaskDetails() != "")
            {
                total_task++;
            }
            // update curr_task to 0 if a task exists
            if ((curr_task == -1) && (total_task > 0))
            {
                curr_task = 0;
            }

            if (first_boot)
            {
                first_boot = 0;
                ui.getHomePage()->printPageMainText();
                cout << "Welcome " << ui.getData()->getUser()->getUsername() << endl;
            }

            if (homepage_action)
            {
                if (option_input == 'a')
                {
                    if (curr_task == -1)
                    {
                        cout << "Error... no tasks to ask for advice on!\n";
                    }
                    else
                    {
                        string taskDetails = ui.getData()->getUser()->getTasks()[curr_task].getTaskDetails();
                        ui.getHomePage()->printAIResponse(taskDetails);
                        //cout << "[Debug]: ADD OPENAI IMPLEMENTATION\n";
                    }
                }
                else if (option_input == 'e')
                {
                    if (curr_task == -1)
                    {
                        cout << "Error... no tasks to edit!\n";
                    }
                    else
                    {
                        string details = ui.getData()->getUser()->getTasks()[curr_task].getTaskDetails();
                        string date = ui.getData()->getUser()->getTasks()[curr_task].getDueDate();
                        // int priority;

                        ui.getHomePage()->printEditTask(details, date, cin);

                        ui.getData()->getUser()->getTasks()[curr_task].editTask(details);
                        ui.getData()->getUser()->getTasks()[curr_task].setDueDate(date);
                    }
                }
                else if (option_input == 'c')
                {
                    string details;
                    string date;
                    int priority;
                    ui.getHomePage()->printCreateTask(details, date, priority, cin);
                    ui.getData()->getUser()->getTasks()[total_task].setTask(details, priority);
                    ui.getData()->getUser()->getTasks()[total_task].setDueDate(date);
                    total_task++;
                    if (curr_task == -1)
                    {
                        curr_task = 0;
                    }
                }
                else if (option_input == 's')
                {
                    cout << "On position: " << curr_task + 1 << endl;
                    cout << "Enter new task position out of " << total_task << ": ";

                    // FIXME: ADD INPUT VERIFICATION?
                    int selection;
                    cin >> selection;
                    cin.ignore();

                    curr_task = selection - 1;
                }
                homepage_action = 0;
            }

            cout << "---\nCurrent Task View\n\nOn Task " << curr_task + 1 << " out of " << total_task << endl;
            if (curr_task == -1)
            {
                cout << "Task Due Date: n/a\nTask Priority: n/a" << endl;
            }
            else
            {
                cout << "Task details: " << ui.getData()->getUser()->getTasks()[curr_task].getTaskDetails() << endl;
                cout << "Task Due Date: " << ui.getData()->getUser()->getTasks()[curr_task].getDueDate() << endl;
                cout << "Task Priority: " << ui.getData()->getUser()->getTasks()[curr_task].getPriorityOfTask() << endl;
            }
            cout << "---\n";
            ui.getHomePage()->printPageOptions();
            break;
        };
    };

    delete data;

    return 0;
}