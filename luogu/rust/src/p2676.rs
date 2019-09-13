use std::io;

pub fn main() {
    let mut tmp = String::new();

    io::stdin().read_line(&mut tmp).expect("qaq");

    let arg: Vec<&str> = tmp.trim().split(' ').collect();

    let n: u32 = arg[0].parse().expect("qaq");
    let mut b: i64 = arg[1].parse().expect("qaq");

    let mut arg: Vec<i64> = Vec::new();

    for _ in 0..n {
        let mut tmp = String::new();

        io::stdin().read_line(&mut tmp).expect("qaq");
        arg.push(tmp.trim().parse().expect("qaq"));
    }

    arg.sort();

    let mut i = 0;

    for c in arg.iter().rev() {
        b -= c;
        i += 1;

        if b <= 0 {
            break;
        }
    }

    println!("{}", i);
}