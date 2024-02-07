#include <iostream>
#include <memory>

using namespace std;

class House {
public:
    shared_ptr<House> neighbor;
  
    House() {
        cout << "Дом построен" << endl;
    }
  
    ~House() {
        cout << "Дом разрушен" << endl;
    }
};

int main() {
    shared_ptr<House> house1 = make_shared<House>();
    shared_ptr<House> house2 = make_shared<House>();
  
    house1->neighbor = house2;
    house2->neighbor = house1;
  
    weak_ptr<House> weakPtr = house1;
    cout << "Количество сильных ссылок для house1: " << house1.use_count() << endl;
  
    if (!weakPtr.expired()) {
        shared_ptr<House> sharedPtr = weakPtr.lock();
        cout << "Количество сильных ссылок для house1 после lock(): " << house1.use_count() << endl;
    }
  
    house1.reset(); 
  
    if (!weakPtr.expired()) {
        shared_ptr<House> sharedPtr = weakPtr.lock();
        cout << "Доступ к house1 после удаления сильной ссылки" << endl;
    } else {
        cout << "Доступ к house1 потерян" << endl;
    }
  
    return 0;
}
