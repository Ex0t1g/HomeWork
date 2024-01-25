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
    virtual int shoot() = 0;
};

class Blaster : public Weapon {
public:
    Blaster() : Weapon(10, -1, -1) {}
    int shoot() {
        return damage;
    }
};

class Pistol : public Weapon {
public:
    Pistol() : Weapon(20, 6, 6) {}
    int shoot() {
        if (shootCount > 0) {
            shootCount--;
            return damage;
        }
        return 0;
    }
};

class MachineGun : public Weapon {
public:
    MachineGun() : Weapon(5, 100, 100) {}
    int shoot() {
        if (shootCount > 0) {
            shootCount--;
            return damage;
        }
        return 0;
    }
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

    while (weapons.size() > 1) {
        Weapon* currentWeapon = weapons.front();
        cout << "Damage: " << currentWeapon->shoot() << endl;

        if (currentWeapon->shootCount == 0) {
            delete currentWeapon;
            weapons.pop_front();
        }

        weapons.push_back(currentWeapon);
        weapons.pop_front();
    }

    for (Weapon* weapon : weapons) {
        delete weapon;
    }

    return 0;
}
