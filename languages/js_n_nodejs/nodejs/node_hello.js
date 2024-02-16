//const fs = require('fs')
const yarg =  require('yargs')

// console.log("hello learning node js");

// fs.writeFileSync("test.txt", "This is merely a test file to learn node.js")

// const add_fun = function(a, b)
// {
//     return a+b;
// }

// console.log(add_fun(10, 90));

// // console.log(process.argv)

// console.log(yarg.argv)

yarg.version('1.1.0');

try
{
    yarg.command({
    command: 'test',
    describe : 'Testing yarg',
    handler : function()
    {
        console.log("testing yarg module")
    }


}).help().argv
console.log("done");

}
catch(e)
{
    console.log("exception thrown")
}

