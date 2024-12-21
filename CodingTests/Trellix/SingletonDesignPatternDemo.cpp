#include <iostream>
#include <thread>
#include <mutex>

class SingletonDemo {
private:
    static SingletonDemo* data;
    static std::mutex mtx;

    SingletonDemo() {
        std::cout << "Private Constructor to restrict object construction from outside\n";
    }

    // Private copy constructor and assignment operator to prevent copy semantics
    SingletonDemo(const SingletonDemo&) = delete;
    SingletonDemo& operator=(const SingletonDemo&) = delete;

public:
    // public static method to access the Singleton instance
    static SingletonDemo* getData() {
        if(data == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            data = new SingletonDemo();
        }

        return data;
    }

    void showMessage() {
        std::cout << "Hello from Singleton in thread " << std::this_thread::get_id() << '\n';
    }

    ~SingletonDemo();
};

SingletonDemo* SingletonDemo::data = nullptr;
std::mutex SingletonDemo::mtx;

void threadFunc(int threadNum) {
    std::cout << "Thread " << threadNum << " trying to get Singleton instance\n";

    SingletonDemo* singleton = SingletonDemo::getData();
    singleton->showMessage();
}

int main()
{
    SingletonDemo* s1 = SingletonDemo::getData();
    s1->showMessage();

    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();

    return 0;
}