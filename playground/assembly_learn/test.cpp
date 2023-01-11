struct stud
{
    int d;
    friend stud operator+(stud &, stud &);
};

stud operator+(stud &op1, stud &op2)
{
    stud res{op1.d + op2.d};
    return res;
}

int main(void)
{
    stud s{10}, t{20};
    stud u = s + t;
    return 0;
}