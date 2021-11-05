#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

struct task{
    std::string name;
    int beginTime;
    int endTime;
    bool done = false;
};

void taskBegin(task& someTask){
    std::time_t t = std::time(nullptr);
    std::cout << "Input name of task" << std::endl;
    std::cin >> someTask.name;
    someTask.beginTime = t;
}

void taskEnd(task& someTask){
    std::time_t t = std::time(nullptr);
    someTask.endTime = t;
    someTask.done = true;
}


int main() {
    std::vector<task> tasks;
    std::string request;
    std::cout << "Input 'begin' for begin new task or 'exit' for exit!" << std::endl;
    std::cin >> request;
    while (request != "exit"){
        if(request == "begin"){
            task someTask;
            taskBegin(someTask);
            tasks.push_back(someTask);
            if((tasks.size()>1)&&(!tasks[tasks.size()-2].done)){
                taskEnd(tasks[tasks.size()-2]);
            }
        } else if(request == "end"){
            if(!tasks[tasks.size()-1].done)
            taskEnd(tasks[tasks.size()-1]);
        } else if(request == "status"){
            for(int i = 0; i < tasks.size() ;i++){
                std::cout << tasks[i].name<<" ";
                if(!tasks[i].done){
                    std::cout <<"task in process!"<<std::endl;
                } else {
                    std::cout <<"task done! Duration:"<<" ";
                    int dt = tasks[i].endTime - tasks[i].beginTime;
                    int hours = dt/3600;
                    dt %= 3600;
                    int min = dt/60 ;
                    dt %= 60;
                    int sec = dt;

                    std::cout << hours << ":" << min << ":" << sec <<std::endl;
                }
            }
        }
        std::cout << "Input 'begin' for begin new task, 'end' for finish the task, status for "
                     "for showing the status, or 'exit' for exit!" << std::endl;
        std::cin >> request;
    }

    return 0;
}
