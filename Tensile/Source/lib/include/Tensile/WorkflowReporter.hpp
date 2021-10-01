#pragma once

#include <string>
#include <iostream>

namespace Tensile::Client{
    class WorkflowReporter{
    private:
        static WorkflowReporter _Instance;

    public:
        static WorkflowReporter& instance(){
            return _Instance;
        }

        void submit_line(std::string text){
            std::cout << text << std::endl;
        }
    };

    WorkflowReporter WorkflowReporter::_Instance;

    void WorkflowLogAppendLine(std::string text){
        WorkflowReporter::instance().submit_line(std::move(text));
    }
}
