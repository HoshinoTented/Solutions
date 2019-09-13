use std::io;
use std::cmp::max;

fn is_finish(rule: &i32, win: &i32, lose: &i32) -> bool {
    max(win, lose) >= rule && (win - lose).abs() >= 2
}

pub fn main() {
    let mut wl: Vec<bool> = Vec::new();        // win or lose

    'outer: loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("qaq");

        for c in line.trim().chars() {
            match c {
                'E' => break 'outer,
                'L' => wl.push(false),
                'W' => wl.push(true),
                _ => panic!("我星野，就算是死，从这跳下去。也绝对不会执行到这个语句！")
            };
        }
    }

    let rules = [11, 21];

    for rule in rules.iter() {
        let mut l = 0;
        let mut r = 0;

        for elem in wl.iter() {
            if *elem {
                l += 1;
            } else {
                r += 1;
            }

            if is_finish(rule, &l, &r) {
                println!("{}:{}", l, r);

                l = 0;
                r = 0;
            }
        }

        println!("{}:{}", l, r);
        println!()
    }
}