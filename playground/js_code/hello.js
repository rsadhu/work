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



display()