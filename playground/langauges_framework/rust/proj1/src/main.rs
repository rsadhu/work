fn add(a:u32, b:u32)->u32
{
    a+b
}
fn swap(a: &mut u32, b: &mut u32)
{
    let tmp = *a;
    *a=*b;
    *b=tmp;
}

fn main() {

    let mut a= 1;
    let mut b= 9;

    println!("{},{} ", a,b);

    swap(&mut a, &mut b);

    println!("{},{} ", a,b);
}
