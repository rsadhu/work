mymod = require("./module.js")

class Test
{
    constructor(data=10)
    {
        this.val = data;
    }

    print()
    {
        console.log("value is ",this.val);
    }
}

class Der extends Test
{
    constructor ()
    {
        super(100)
        this.val_d =  this.val;
    }

    printMe()
    {
        console.log("der print is ", this.val_d);
    }
}



t = new Test();
u = new Test(100);

t.print();
u.print();

d = new Der();
d.printMe();


console.log(mymod.add(1,9));
console.log(mymod.add(19,9));