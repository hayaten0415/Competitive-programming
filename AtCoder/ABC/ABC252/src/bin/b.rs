use proconio::input;
use std::collections::HashSet;

fn main() {
  input! {
    n : usize,
    m: usize,
    a: [i64;n],
    b: [usize;m],
  }
  let mut num = HashSet::new();
  let mut mx = 0;
  for i in 0..n {
    if mx > a[i] {continue;}
    if mx == a[i] {
      num.insert(i+1);
    } else {
      num.clear();
      mx = a[i];
      num.insert(i+1);
    }
  }
  let mut ok = false;
  for i in 0..m {
    if num.contains(&b[i]) {ok = true;}
  }
  if ok {println!("Yes")} else {println!("No")};
}
