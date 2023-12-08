# CerebroTask
Authors: [Mahir Patel](https://github.com/mpate132), [Christopher Delgado](https://github.com/chris-delg), [Saif Deras](https://github.com/saifderas) ,[Dorian Martin](https://github.com/dmart218)

## Project Description
  * Why is it important or interesting to you?
     * A task manager is important/interesting to us because time management is the main concern for us students and we want to make it cooler rather than using NotionAi, Google Task Scheduler, which is compatible with students.
     * The idea of being told how we can actually complete said tasks is an interesting feature we would like to implement in our project.
  * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
     * We plan to use C++, Qt, OpenAI API, GitHub, Googletest, Git, Cmake, gdb, and Valgrind.
  * What will be the input/output of your project?
     * The input of the project would be mainly through a GUI, specifically through a text box located on the GUI. The output would then be displayed directly onto the GUI for the user to see.
  * What are the features that the project provides?
     * The ability for users to input what tasks they need done.
     * Saving/loading the user’s schedule.
     * Giving the user the ability to mark tasks as completed while also giving them the option to revert that task.
     * Having an option to ask from help on specific tasks using the openAI API.

 
## User Interface Specification
### Navigation Diagram
![navigation diagram](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/interface%20diagram.png)

A diagram of how the GUI is navigated in CerebroTask. After logging-in, there are three pages the user can use: the home tab, the history tab, and the settings tab. Not shown in the navigation diagram is that the user can ask for AI advice on a selected task in the home or history tab. Additionally there will be an edit-mode for the home tab's daily schedule.

### Screen Layouts

![login](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/login%20light.png)

The login page to Cerebrotask. Here, the user can enter their name and password to access their saved scheduled tasks. When entering their password, it should be hidden with asterisks instead of the letters being typed.

![dark mode](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/login%20dark.png)

What a dark mode of the log-in page could look like. The rest of the program would have a similar inverse color pallette. This option is in the settings page.

![home](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/home%20light.png)

The home page, where the user can view and edit their schedule. The tabs on the left allow the user to switch to one of the other pages, and the following pages will be the same. When a task is hovered over with the cursor, the option to ask the AI advice on how to complete the task is presented by the orange question mark.

![history](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/history%20light.png)

The history page allows the user to view old saved schedules. The buttons on the side scroll through which schedule is being previewed. The user can ask the AI for advice on old tasks as well.

![settings](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/settings%20light.png)

The settings tab will allow the user to change the UI and enable other features for accessibility purposes. The options will have a variety of ways to interface, such as buttons for switching the clock type or a slider for the text size.

## Outdated Class Diagram

![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/Project.drawio.png)

 * Our UI class will serve as our driver class while the rest of our classes serve as support. Our "Storage" class will hold info for the logged in user while our "User" class will hold an instance of our "Task" class which will hold current and previous tasks. Finally, our "OpenAI" class will give our users the ability to ask for help with their tasks through the use of OpenAI's API.

## New Class Diagram

![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/uml.png)

### UI Class + Page Class and its derived classes
### How did you apply it? i.e. describe the change.

1. **Single Responsibility Principle (SRP) and Open-Close Principle (OCP)**:
 - In the overhaul to the UI design, major changes were made to transition from a GUI to a CLI.
 - Page was formalized into an abstract class with two derived classes -- LoginPage and HomePage. This follows the Open-Closed Principle.
 - Page and its derivatives have a single responsiblity: print the text of a given page. The derived classes have their own specific methods to print other, specific lines of text that aren't already inherited from Page (such as printPageMainText, printPageOptions, and printPageInputError).
 - UI's single responsibility is to update what page the UI is on.
### How did this change help you write better code?
1. **Maintainability**:
   - By adhering to SRP and OCP, the UI became more maintainable. Changes to a specific page type won't alter code to other page types.
2. **Readability and Understandability**:
   - The code became more clear by explicitly segregating responsibilities of the different page types and having Page as an abstract base class. Developers can easily identify which page is being accessed when, without concerning themself of the interfaces/implementation of other page types.
3. **Scalability**:
   - OCP allows for easy scaling. Instead of returing to Page to extend new functionality that a given page might or might not use, a developer instead needs only to change that specific page or make a new page type.
4. **Testing**:
   - Following SRP and OCP allows for testing to be more simple and have greater coverage as the UI and its pages are more direct and specific in what has to be tested.
  

### Storage Class
### How did you apply it? i.e. describe the change.

1. **Single Responsibility Principle (SRP)**:
   - Initially, the "Storage" class violated SRP by handling both text and binary file functionalities.
   - To adhere to SRP, a new "UserData" class was introduced to handle user data, segregating the responsibilities.
   - The "UserData" class was then inherited by specialized classes: "UserTxtData" and "UserBinData," each handling specific file types (text and binary).

### How did this change help you write better code?

1. **Maintainability**:
   - By adhering to SRP, the code became more maintainable. Changes to text file operations won't affect binary file operations and vice versa.
2. **Readability and Understandability**:
   - The code became more readable and understandable by explicitly segregating responsibilities. Developers can easily identify and work with classes focused on specific tasks.
3. **Scalability**:
   - This change facilitates easier scalability. If more file types need to be supported in the future, new classes can be added without disturbing existing functionalities.
4. **Testing**:
   - Testing becomes more targeted and specific, as each class handles a distinct responsibility. This simplifies the testing process and improves test coverage.

By applying the Single Responsibility Principle through the creation of specialized classes, the code becomes more modular, maintainable, and easier to comprehend, which ultimately aids in writing better quality code.
 
 ## Screenshots
 #### The logn menu :
 ![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/login.png)

 #### The hompage :
 ![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/homepage.png)

 #### Editing a task :
 ![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/edit_task.png)

 #### Asking the ai for help :
 ![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/ai_help.png)

 #### Logging out and quitting the program :
 ![image](https://github.com/cs100/final-project-cdelg036-dmart218-sdera006-mpate132/blob/master/img/logout_and_quit.png)

 ## Installation/Usage
 First check if you have these requirements :

 + C++11/C++14/C++17/C++20 compatible compiler
 + [libcurl](https://curl.se/libcurl/) (check [Install curl](https://everything.curl.dev/get) to make sure you have the development package)

 Next make sure that the GoogleTest submodule is correctly connected to the project by running this command :
 ```bash
 git submodule add -f https://github.com/google/googletest.git test/googletest
 ```
 Next add the location of where your data will be stored by running these commands :
 ```bash
 mkdir data && cd data
 mkdir dat_files
 ```
  
  Finally to build and compile run the following : 
  ```bash
  cmake . && make
  ./bin/cerebroTask
  ```

 ## Testing
We utilized the Google Test framework to thoroughly validate and test our program, adopting a meticulous approach to ensure comprehensive testing. To enhance organizational clarity, we established a dedicated test folder. This improves the readability of our code. Here we structured our tests into distinct files, including fileTest.cpp, openaiTest.cpp, ui_test.cpp, task_test.cpp, and user_test.cpp. Our testing regimen was comprehensive, encompassing a combination of EXPECTs and ASSERTs to extensively evaluate the robustness and reliability of our code. By selecting Google Test as our framework and structuring our tests meticulously, we are not only safeguarding the reliability of our current code, however we are also laying a solid foundation for future development and enhancements.

 
