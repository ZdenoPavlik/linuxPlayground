#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <list>

class Cleaner;
class EngineCrew;

// std::list<Cleaner> cleaningQueue;
// std::list<EngineCrew> engineCrewQueue;

enum Commands
{
    cleaning = 1,
    fullSpeed = 2,
    stop = 3,
    exitProgram = 100
};

class Cleaner
{
public:
    void operator()()
    {
        std::cout << "[Cleaner] I am cleaning " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    ~Cleaner()
    {
        std::cout << "[Cleaner] I am done " << std::this_thread::get_id() << std::endl;
    }
};

class EngineCrew
{
public:
    void operator()()
    {
        std::cout << "[Engine] Full speed ahead " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    ~EngineCrew()
    {
        std::cout << "[Engine] We are done " << std::this_thread::get_id() << std::endl;
    }
};

void exercise2_ship()
{
    std::cout << "------------------------------- Exercise ship -------------------------------" << std::endl;

    int command = 0;
    bool run = true;
    while(run)
    {
        std::cout << "enter your choice" << std::endl;
        std::cin >> command;
        switch(command)
        {
            case Commands::cleaning:
            {
                std::thread cleanerThread{Cleaner()};
                cleanerThread.detach();

                break;
            }
            case Commands::fullSpeed:
            {
                std::thread engineCrewThread{EngineCrew()};
                engineCrewThread.join();
                break;
            }
            case Commands::stop:
            {

                break;
            }

            case Commands::exitProgram:
            {
                run = false;
                std::cout << "End of program" << std::endl;
                break;
            }

            default:
            {
                std::cout << "Invalid choice, repeat yourself" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                break;
            }
        }
    }
}