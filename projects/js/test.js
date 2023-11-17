var args = process.argv.slice(2);


console.log("hello entry code")


class Test
{
constructor( num_of_hours, rate)
{
    this.num_of_hours = num_of_hours
    this.rate = rate
}
};

Test.prototype.salary = function(){
    return this.num_of_hours*this.rate*30
  }

t = new Test(8, 40)
console.log("\n")
console.log(t.salary())


t1 = new Test(args[0], args[1])
console.log("\n")
console.log(t1.salary())