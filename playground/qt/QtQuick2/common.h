#ifndef COMMON_H
#define COMMON_H

#include<QDebug>

enum class TestEnum
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

QDebug operator<<(QDebug stream, const TestEnum &day) {

    switch (day)
    {
    case TestEnum::SUNDAY:
        stream << "Pazar";
        break;
    case TestEnum::MONDAY:
        stream << "Pazartesi";
        break;
    case TestEnum::TUESDAY:
        stream << "Sali";
        break;
    case TestEnum::WEDNESDAY:
        stream << "Carsembe";
        break;
    case TestEnum::THURSDAY:
        stream << "Parsembe";
        break;
    case TestEnum::FRIDAY:
        stream << "Cummah";
        break;
    case TestEnum::SATURDAY:
        stream << "Cummahtersi";
        break;
    }
    return stream;
}
#endif // COMMON_H
