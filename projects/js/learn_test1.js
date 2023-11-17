
class  JsCode
{
    constructor()
    {
        console.log("JsCode Constructor")
    }
};

var myArray = [1, 2, 3];
var theSameArray = new Array(1, 2, 3);

myArray[9] = 9;

var obj = {}
obj.firstname = "rakesh";
obj.lastname = "sadhu";
obj.age = 41;
obj.address = "munich 81245";

var my_arr =  [];

my_arr[0] = true;
my_arr[3] = "rakesh";
my_arr[20] = 100;
my_arr[25] = "kashmir";
my_arr[10] = "rajesh";
my_arr[99] = "munich";


function foo()
{
    var a = 10;
    console.log(a);

    function subfoo()
    {
        a = 100;
        console.log(a);
    }

    subfoo();
}

foo();

var fun_add = function(a, b)
{
    console.log(a+b);
};


fun_add(9999999, 1);
