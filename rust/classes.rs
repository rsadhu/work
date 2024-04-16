//use std::io;

struct Test {
    id: u32,
    age: u32,
    roll: u32,
}

impl Test {
    fn id(&self) -> u32 {
        self.id
    }

    fn age(&self) -> u32 {
        self.age
    }

    fn roll(&self) -> u32 {
        self.roll
    }
}

fn fact(n: i32) -> i32 {
    if n == 0 {
        1
    } else {
        n * fact(n - 1)
    }
}

fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    println!("Hello, world!");
    println!("{}", fact(5));

    let t = Test {
        id: 1212121,
        age: 42,
        roll: 1,
    };

    println!("{} {} {}", t.age(), t.id(), t.roll());
    println!("{} + {} = {}", 10, 90, add(10, 90));
}
