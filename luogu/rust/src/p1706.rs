use std::io;

fn permutation(vec: Vec<usize>) -> Vec<Vec<usize>> {
    if vec.is_empty() {
        let mut result = Vec::new();
        result.push(Vec::new());

        result
    } else {
        let mut result: Vec<Vec<usize>> = Vec::new();

        for i in 0..vec.len() {
            let mut new_vec = vec.clone();
            new_vec.remove(i);

            let mut inner_result = permutation(new_vec);

            for v in inner_result.iter_mut() {
                v.push(vec[i]);

                result.push(v.clone());
            }
        }

        result
    }
}

pub fn main() {
//    let mut line = String::new();
//
//    io::stdin().read_line(&mut line).expect("qaq");
//
//    let n: usize = line.trim().parse().expect("qwq");
//
//    let mut vis = Vec::new();
//
//    for i in 0..n + 1 {
//        vis.push(false);
//    }

    println!("{:?}", permutation(vec![1, 2, 3]));
}