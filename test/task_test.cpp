#include <gtest/gtest.h>
#include "../include/Task.hpp"

TEST(TaskTests, Constructor)
{
    std::string taskDetails = "Finish CS Assignment";
    int priority = 2;

    Task task;
    task.setTask(taskDetails, priority);

    EXPECT_EQ(taskDetails, task.getTaskDetails());
    EXPECT_EQ(priority, task.getPriorityOfTask());

}

TEST(TaskTests, Edit)
{
    std::string initialTaskDetails = "Finish CS Assignment";
    int initialPriority = 2;

    Task task;
    task.setTask(initialTaskDetails, initialPriority);

    std::string newTaskDetails = "Study for CS Exam";

    task.editTask(newTaskDetails);

    EXPECT_EQ(newTaskDetails, task.getTaskDetails());
}

TEST(TaskTests, Delete)
{
    std::string taskDetails = "Finish CS Assignment";
    int priority = 2;
    
    Task task;
    task.setTask(taskDetails, priority);
    
    task.deleteTask(1);

    EXPECT_EQ("", task.getTaskDetails());
    EXPECT_EQ(2, task.getPriorityOfTask());
}

TEST(TaskTests, DueDateTests)
{
    std::string taskDetails = "Finish CS Assignment";
    int priority = 2;

    Task task;
    task.setTask(taskDetails, priority);

    std::string dueDate = "12/12/2023";
    task.setDueDate(dueDate);

    EXPECT_EQ(dueDate, task.getDueDate());
}
