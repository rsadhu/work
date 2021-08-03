#ifndef PREG_H
#define PREG_H

enum class h11_registersConfigurationType {
    H11_REGISTERS_SPARSE = 0,
    H11_REGISTERS_SPARSE_REG,
    H11_REGISTERS_SPARSE_PROBE,
    H11_REGISTERS_DENSE,
    H11_REGISTERS_DENSE_REG
};

struct h11_preg_register {
    unsigned int address;
    unsigned int value;

    template <typename archive>
    void serialize(archive& ar)
    {
        ar(address, value);
    }
};

struct h11_preg_entry {

    h11_registersConfigurationType type;
    unsigned int numOfRegisters;
    h11_preg_register registers;

    template <typename archive>
    void serialize(archive& ar)
    {
        ar(type, numOfRegisters, registers);
    }
};

struct preg {
    unsigned int version;
    uint8_t numEntries;

    h11_preg_entry entry;

    template <typename archive>
    void serialize(archive& ar)
    {
        ar(version, numEntries, entry);
    }

    void display()
    {
        std::cout << "\n version " << version;
        std::cout << "\n umEntries " << numEntries;
        //std::cout <<"\n entry.type "<< entry.type;
        std::cout << "\numOfRegisters " << entry.numOfRegisters;
        std::cout << "\registers " << entry.registers.address;
        std::cout << "\registers " << entry.registers.value;
    }
};

#endif