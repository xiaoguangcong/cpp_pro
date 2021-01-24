#include "singleton_eager.cpp"
#include "singleton_lazy.cpp"

// 单例 Singleton 是设计模式的一种，其特点是只提供唯一一个类的实例，具有全局变量的特点，在任何位置都可以通过接口获取到那个唯一实例;

int main()
{
    /* --------- Test the singleton in eager pattern -------- */
    std::cout << std::endl;
    std::cout << "--------- Test the singleton in eager pattern --------" << std::endl;
    singleton::SingletonEager* ptr1 = singleton::SingletonEager::get_instance();
    singleton::SingletonEager* ptr2 = singleton::SingletonEager::get_instance();
    std::cout << "ptr1: " << ptr1 << std::endl;
    std::cout << "ptr2: " << ptr2 << std::endl;
    if (ptr1 == ptr2) { std::cout << "Test the singleton in eager pattern success!" << std::endl; }
    std::cout << std::endl;

    /* --------- Test the singleton in lazy pattern -------- */
    std::cout << std::endl;
    std::cout << "--------- Test the singleton in lazy pattern --------" << std::endl;
    singleton::LazySingleton& ptr3 = singleton::LazySingleton::get_instance();
    singleton::LazySingleton& ptr4 = singleton::LazySingleton::get_instance();
    std::cout << "ptr3: " << &ptr3 << std::endl;
    std::cout << "ptr4: " << &ptr4 << std::endl;
    if (&ptr3 == &ptr4) { std::cout << "Test the singleton in lazy pattern success!" << std::endl; }
    std::cout << std::endl;

    return 0;
}