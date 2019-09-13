use std::io;

struct UnionFind {
    arr: Vec<usize>
}

impl UnionFind {
    fn new(len: usize) -> UnionFind {
        let mut vec: Vec<usize> = Vec::new();

        for i in 0..len {
            vec.push(i);
        };

        UnionFind {
            arr: vec
        }
    }

    fn ask(&mut self, x: usize) -> usize {
        if self.arr[x] == x {
            x
        } else {
            let p = self.arr[x];
            self.arr[x] = self.ask(p);
            self.arr[x]
        }
    }

    fn cat(&mut self, x: usize, y: usize) {
        let new_x = self.ask(x) as usize;

        self.arr[new_x] = self.ask(y);
    }
}

pub fn main() {
    let mut line = String::new();

    io::stdin().read_line(&mut line).expect("qaq");

    let words: Vec<&str> = line.trim().split(' ').collect();

    let len: usize = words[0].parse().expect("qwq");
    let req_count: usize = words[1].parse().expect("qwq");

    let mut uf = UnionFind::new(len + 1);

    for i in 0..req_count {
        let mut line = String::new();

        io::stdin().read_line(&mut line).expect("qaq");

        let words: Vec<&str> = line.trim().split(' ').collect();
        let req: i32 = words[0].parse().expect("qwq");
        let x: usize = words[1].parse().expect("qwq");
        let y: usize = words[2].parse().expect("qwq");

        if req == 1 {
            uf.cat(x, y);
        } else {
            let result_x = uf.ask(x);
            let result_y = uf.ask(y);

            if result_x == result_y {
                println!("Y")
            } else {
                println!("N")
            }
        }
    }
}