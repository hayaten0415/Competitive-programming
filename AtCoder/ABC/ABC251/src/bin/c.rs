use proconio::input;
use std::collections::HashSet;

fn main() {
  input! {
    n : usize,
    s: [(String, i64);n],
  }
  let mut origin:HashSet<String> = HashSet::new();
  let mut ans = -1;
  let mut ans_index = 0;
  let mut i = -1;
  for (st, score) in s.iter() {
    i += 1;
    if origin.contains(st){
      continue;
    }
    origin.insert(st.to_string());
    if chmax(&mut ans, *score) {
      ans_index = i;
    }
  }
  println!("{}", ans_index+1);
}


fn chmax<T: std::cmp::PartialOrd>(a1 : &mut T, a2 : T) -> bool {
  if *a1 < a2 {*a1 = a2; true} else {false}
}
