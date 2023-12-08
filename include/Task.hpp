#ifndef TASK_HPP
#define TASK_HPP

#include <string>

using namespace std;

class Task
{
private:
    char task[200];
    char dueDate[50];
    int size;   // for tracking the task details
    int length; // for tracking the dueDate
    int taskId;
    int priorityOfTask;

public:
    Task();
    void setTask(string &, int);
    void editTask(string &);
    string deleteTask(int);
    void setDueDate(string &);
    string getTaskDetails() const;
    string getDueDate() const;
    int getPriorityOfTask() const;
};

#endif