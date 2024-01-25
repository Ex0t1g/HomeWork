

#include <iostream>
#include <list>
using namespace std;

class Weapon
{
protected:
    int damage;
    int shootCount;
    int maxAmmo;
public:

    Weapon(int damage, int shootCount, int maxAmmo) : damage(damage), shootCount(shootCount), maxAmmo(maxAmmo) {}
    virtual int shoot()
    {
        if (shootCount > 0) {
            shootCount--;
            return damage;
        }
        return 0;
    }
};

class Blaster : public Weapon {
public:
    Blaster() : Weapon(10, INT_MAX ,INT_MAX) {} // Бесконечные патроны
    int shoot() override
    {
        return damage;
    }
};

class Pistol : public Weapon {
public:
    Pistol() : Weapon(20, 6, 6) {}
};

class MachineGun : public Weapon {
public:
    MachineGun() : Weapon(5, 100, 100) {}
};

int main()
{
    list<Weapon*> weapons;
    Blaster* blaster = new Blaster();
    Pistol* pistol = new Pistol();
    MachineGun* machineGun = new MachineGun();

    weapons.push_back(blaster);
    weapons.push_back(pistol);
    weapons.push_back(machineGun);

    int currentEnemyHP = 1000;
    while (true) {
        for (Weapon* weapon : weapons) {
            int damage = weapon->shoot();
            currentEnemyHP -= damage;
            cout << "Damage: " << damage << " Current Enemy HP: " << currentEnemyHP << endl;
            if (currentEnemyHP <= 0) {
                cout << "Enemy killed!" << endl;
                break;
            }
        }

        if (currentEnemyHP <= 0) {
            break;
        }
    }

    for (Weapon* weapon : weapons) {
        delete weapon;
    }

    return 0;
}
