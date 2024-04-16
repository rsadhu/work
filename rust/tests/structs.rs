struct Stud{
    id: i32,
    name: String,
    address: String,
    age: u32
}


impl Stud
{
    fn new(i:i32, n:String, a:String, ag:u32) -> Self
    {
        Self
        {
            id:i,
            name:n,
            address:a,
            age:ag
        }
    }

    fn display(&self){
        println!("{} {} {}{}", self.id, self.name, self.address,self.age);
    }
}



fn main()
{
    let s =  Stud{id:1, name:"rakesh sadhu".to_string(), address:"munich de".to_string(), age:42};
    s.display();
}