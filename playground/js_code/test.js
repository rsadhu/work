function add(arg)
{
    if (arg == 0)
        return 0;
    return arg + add(arg-1);
}



console.log(add(10))