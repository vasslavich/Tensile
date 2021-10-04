#pragma once

#include <utility>
#include <string>
#include <iostream>
#include "Utils.hpp"

namespace Tensile{
namespace Log{

    template<typename Out>
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

    template<typename Out>
    WorkflowReporter<Out> WorkflowReporter<Out>::_Instance;

    template<typename ...ToStrItems>
    void WorkflowLogAppendLine(ToStrItems && ... texts){
        WorkflowReporter<std::ostringstream>::instance().submit_line(concatenate(std::forward<ToStrItems>(texts)...));
    }
}
}
