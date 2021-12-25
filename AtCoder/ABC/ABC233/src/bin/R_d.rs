use proconio::input;
use std::collections::HashMap;

fn main() {
    input! {
        n : usize,
        k: i64,
        a: [i64; n]
    }
    let d = a.len() + 1;
    let mut vec = vec![0; d];
    for i in 0..n {
        vec[i+1] += vec[i] + a[i];
    }
    let mut map: HashMap<i64, u64> = HashMap::new();
    let mut ans = 0;
    for i in 0..d {
        if let Some(x) =  map.get(&(vec[i]-k)) {
            ans += x;
        }
        *map.entry(vec[i]).or_insert(0) += 1;
    }
    println!("{}", ans);
}
