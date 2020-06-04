cmake_minimum_required(VERSION 3.14)
project(Traveller_s_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(Traveller_s_app main.cpp User.cpp User.h commands/RegistrationCommand.h commands/LoginCommand.h commands/ICommand.cpp commands/ICommand.h System.cpp System.h CallingCommandLine.cpp CallingCommandLine.h commands/HelpCommand.h commands/FriendCommand.h commands/ExitAccountCommand.h Holiday.cpp Holiday.h Date.cpp Date.h commands/ShowFriend.h)