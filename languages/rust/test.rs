
fn foo(a: &str)
{
    println!("{}", a);
}

fn add(a:i32, b:i32) -> i32
{
    return a+b;
}

fn concat(a:&str, b:&str) -> str
{
    return a+b;
}

fn main() {
    println!("Hello World!");
    foo("rakesh");
    let s = add(10, 90);
    println!("{}", s);
    println!("{}", concat("rak", "esh"));
}