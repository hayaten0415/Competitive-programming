use proconio::input;

fn main() {
  input! {
    n : usize,
    mut s: [(String, i64);n],
  }
  let mut f:Vec<(String, i64, usize)> = vec![];
  for i in 0..n {
    f.push((s[i].0.clone(), s[i].1, i));
  }
  f.sort_by(|l, r| {
    match l.0.cmp(&r.0) {
        std::cmp::Ordering::Equal => {
          match r.1.cmp(&l.1) {
              other => other
          }
        },
        other => other
    }
  });
  for i in 0..n {
    println!("{}",f[i].2 + 1);
  }
}
