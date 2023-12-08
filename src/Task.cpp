#include "../include/Task.hpp"

#include <iostream>
#include <string>

using namespace std;

Task::Task(){
    size = 0;   
    length = 0; 
    taskId = 0;
    priorityOfTask = 0;

}

void Task::setTask(string &detailsOfTask, int priorityOfTask)
{
    const char *arr = detailsOfTask.c_str();
    this->size = detailsOfTask.size(); 
    this->taskId++;
    this->priorityOfTask = priorityOfTask;
    for (int i = 0; i < this->size; ++i)
    {
        this->task[i] = arr[i];  
    }

    this->task[this->size] = '\0';
}

string Task::getTaskDetails() const
{
    string taskDetails = ""; 
    for (int i = 0; i < this->size; ++i)
    {
        taskDetails += this->task[i];  
    }
    
    return taskDetails; 
}

string Task::getDueDate() const
{
    string dueDate = "";
    for (int i = 0; i < this->length; ++i)
    {
        dueDate += this->dueDate[i];
    }
    return dueDate;
}

void Task::editTask(string &newTaskDetails)
{
    const char *arr = newTaskDetails.c_str();
    this->size = newTaskDetails.size();
    for (int i = 0; i < this->size; ++i)
    {
        this->task[i] = arr[i];
    }
    this->task[this->size] = '\0';
}

string Task::deleteTask(int id)
{
    // Perform deletion logic based on the ID and return some indication of success/failure
    // For example:
    if (this->taskId == id)
    {
        // Clear task details
        this->size = 0;
        this->task[0] = '\0';
        return "Task deleted successfully.";
    }
    else
    {
        return "Task with specified ID not found.";
    }
}

void Task::setDueDate(string &dueDateFromUser)
{
    const char *arr = dueDateFromUser.c_str();
    this->length = dueDateFromUser.size();
    for (int i = 0; i < this->length; ++i)
    {
        this->dueDate[i] = arr[i];
    }

    this->dueDate[this->length] = '\0';
}

int Task::getPriorityOfTask() const
{
    return this->priorityOfTask;
}