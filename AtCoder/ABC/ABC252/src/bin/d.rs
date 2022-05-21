use proconio::input;
use std::collections::HashSet;

fn main() {
  input! {
    n : usize,
    a: [usize;n],
  }
  let mut cn:Vec<i64> = vec![0; 200001];
  for i in 0..n {
    cn[a[i]] += 1;
  }
  let mut sum = n as i64;
  let mut ans = n as i64 * (n-1) as i64 * (n-2) as i64 / 6;
  for i in 1..200001 {
    ans -= cn[i] * (cn[i] -1) / 2 * (n as i64 - cn[i]);
    ans -= (cn[i] -1) * cn[i] * (cn[i] -2) / 6;
  }
  println!("{}", ans);
}
