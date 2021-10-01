#pragma once

#include <utility>
#include <string>
#include <iostream>
#include "Utils.hpp"

namespace Tensile::Log{
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

    template<typename ...ToStrItems>
    void WorkflowLogAppendLine(ToStrItems && ... texts){
        WorkflowReporter::instance().submit_line(concatenate(std::forward<ToStrItems>(texts)...));
    }
}
