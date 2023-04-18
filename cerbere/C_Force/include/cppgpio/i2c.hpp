#ifndef i2c_hpp_IASZJGFISOLJDFPOSIDUHGZAUHIJDALSFASVYESF
#define i2c_hpp_IASZJGFISOLJDFPOSIDUHGZAUHIJDALSFASVYESF

#include <string>

namespace GPIO {

class I2C {
public:
    I2C(const std::string& interface, unsigned int device_id)
    {
        open(interface, device_id);
    }
    I2C() {}
    ~I2C()
    {
        close();
    }

    void open(const std::string& interface, unsigned int device_id);
    void close();

    int read() const;
    int regread8(int reg) const;
    int regread16(int reg) const;

    void write(int data) const;
    void regwrite8(int reg, int value) const;
    void regwrite16(int reg, int value) const;

private:
    int m_fd = -1;
};

}

#endif /* i2c_hpp */
