#include <print>
#include <thread>
#include <string>
#include <map>
void refresh_api(std::map<std::string, int> wf)
{
    unsigned int refresh{5};
    while (refresh--)
    {

        std::println("----------------------------------------------------");
        for (auto &&item : wf)
        {
            item.second++;
            std::println("city : {} , weather : {}", item.first, item.second);
        }
        std::println("----------------------------------------------------");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        if (refresh == 0)
        {
            std::println("api refresher thread is Done!");
        }
    }
}
void print_working()
{
    unsigned int refresh{15};
    while (refresh--)
    {

        std::println("********************************");
        std::println("main worker working!");
        std::println("********************************");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (refresh == 0)
        {
            std::println("Main Worker heading out !");
        }
    }
}
int main()
{
    std::map<std::string, int> WeatherForecast{
        {"New York", 15},
        {"Baghdad", 20},
        {"London", 25},
        {"Tokyo", 30}};

    std::thread mainWorker(print_working);
    std::thread ApiWorker(refresh_api, WeatherForecast);
    ApiWorker.join();

    mainWorker.join();
    std::println("Done!");
    return 0;
}