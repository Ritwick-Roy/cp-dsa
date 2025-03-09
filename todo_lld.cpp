#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Task {
private:
    std::string taskName;
    std::string notes;
    bool completed;
    time_t timestamp;  // new attribute for timestamp

public:
    // Constructors
    Task(const std::string& name, const std::string& notes) : taskName(name), notes(notes), completed(false) {
        timestamp = std::time(0);  // set the current time as the creation timestamp
    }

    // Getter methods
    std::string getTaskName() const { return taskName; }
    std::string getNotes() const { return notes; }
    bool isCompleted() const { return completed; }
    time_t getTimestamp() const { return timestamp; }
    std::string getFormattedTimestamp() const {
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%d-%m %H:%M:%S", localtime(&timestamp));
        return std::string(buffer);
    }

    // Setter methods
    void setCompleted(bool status) { completed = status; }
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    // Method to add a new task to the list
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    // Method to mark a task as completed
    void markTaskAsCompleted(const std::string& taskName) {
        for (auto& task : tasks) {
            if (task.getTaskName() == taskName) {
                task.setCompleted(true);
                std::cout << "Task '" << taskName << "' marked as completed at " << task.getFormattedTimestamp() << ".\n";
                return;
            }
        }
        std::cout << "Task '" << taskName << "' not found.\n";
    }

    // Method to display all tasks
    void displayTasks() const {
        std::cout << "Tasks:\n";
        for (const auto& task : tasks) {
            std::cout << "- " << task.getTaskName() << " ("
                      << (task.isCompleted() ? "Completed" : "Pending") << ") created at "
                      << task.getFormattedTimestamp() << "\n";
        }
    }
};

int main() {
    // Example usage
    Task task1("Complete Assignment", "Finish the project by the deadline");
    Task task2("Buy Groceries", "Milk, eggs, bread");

    TodoList todoList;
    todoList.addTask(task1);
    todoList.addTask(task2);

    todoList.displayTasks();

    todoList.markTaskAsCompleted("Complete Assignment");

    todoList.displayTasks();

    return 0;
}
