use proconio::input;
use std::collections::*;
use std::collections::HashSet;

fn main() {
  input! {
    n : usize,
    w: i64,
    s: [i64;n],
  }
  let mut num = HashSet::new();
  for i in 0..n {
    if s[i] <= w{
      num.insert(s[i]);
    }
    for j in i+1..n {
      if s[j] <= w{
        num.insert(s[j]);
      }
      if s[j] + s[i] <= w{
        num.insert(s[j] + s[i]);
      }
      for k in j+1..n {
        if s[k] <= w{
          num.insert(s[k]);
        }
        if s[j] + s[k] <= w{
          num.insert(s[j] + s[k]);
        }
        if s[i] + s[k] <= w{
          num.insert(s[i] + s[k]);
        }
        if s[i] + s[k] + s[j] <= w{
          num.insert(s[i] + s[k] + s[j]);
        }
      }
    }
  }
  println!("{}", num.len());
}
