const  list = [ "mummy", "jotika", "ashwani", "mona", "rakesh", "valya", "aryan", "lavi"];
var  ages = [67, 47, 44, 42, 41, 37, 16, 10]

function display()
{
    for (let index in list)
        console.log(list[index]);

    console.log(ages)
    ages.sort();
    console.log(ages)

    list.sort();

    console.log(list);

}

function json_to_object(json_str)
{
    obj_arr = JSON.parse(json_str)
   // console.log(obj_arr["members"])
}


var json_str = {
    "members":[
    {
        "name" : "rakesh",
        "age" : 40,
        "home" :  "Kashmir",
        "address" :  "Munich, Germany"},

    {
        "name" : "valya",
        "age" : 37,
        "home" :  "Ukraine",
        "address" :  "Munich, Germany"
    }]
};

display()


json_to_object(json_str)

import("os");
import("fs")

fs.read();