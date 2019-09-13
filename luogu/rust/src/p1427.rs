use std::io;

pub fn main() {
    let mut s = String::new();

    io::stdin().read_line(&mut s).expect("qaq");

    let mut vec: Vec<&str> = s.trim().split(' ').collect();
    let len = vec.len();
    vec.remove(len - 1);
    vec.reverse();

    for item in vec {
        print!("{} ", item);
    }
}