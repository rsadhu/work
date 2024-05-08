use std::time::Instant;

fn main() {
    let mut cnt = 0;
    let start_time = Instant::now();

    while cnt < 1000000000 {
        cnt += 1;
    }
    let end_time = Instant::now();

    let time_difference = end_time.duration_since(start_time).as_millis();

    println!("Time taken: {} milliseconds", time_difference);
}
