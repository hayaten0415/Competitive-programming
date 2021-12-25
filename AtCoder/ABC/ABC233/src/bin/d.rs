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
        if map.contains_key(&(vec[i]-k)) {
            ans += map[&(vec[i]- k)];
        }
        if map.contains_key(&vec[i]) {
            *map.get_mut(&vec[i]).unwrap() += 1;
        } else{
            map.insert(vec[i], 1);
        }
    }
    println!("{}", ans);
}
