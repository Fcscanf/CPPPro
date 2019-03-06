cmake_minimum_required(VERSION 3.13)
project(Pro1)

set(CMAKE_CXX_STANDARD 14)

# module8_abstract/acctabc.cpp module8_abstract/acctabc.h

add_executable(Pro1 main.cpp module1/Mouh.cpp module1/Mouh.h
        module2/Stock.cpp module2/Stock.h
        module3/FcTime.cpp module3/FcTime.h
        module4/vector.cpp module4/vector.h
        module5/Customer.cpp module5/Customer.h
        module5/queue.cpp module5/queue.h
        module6_extends/tabtenn.cpp module6_extends/tabtenn.h
        module7_polymorphism/brass.cpp module7_polymorphism/brass.h
        module9_dynamic_memory_allocation_friend_inheritance/dma.cpp module9_dynamic_memory_allocation_friend_inheritance/dma.h module10_code_reuse/workermi.cpp module10_code_reuse/workermi.h module11_class_template/stacktp.cpp module11_class_template/stacktp.h module11_class_template/pointer_stack/stcktp.cpp module11_class_template/pointer_stack/stcktp.h module11_class_template/arrry/arraytp.cpp module11_class_template/arrry/arraytp.h)