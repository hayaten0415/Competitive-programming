use proconio::input;
use itertools::Itertools;

fn main() {
  input! {
    n: usize,
    q: usize,
    mut x: [usize; q]
  }
  let mut ind = (0..n).collect_vec();
  let mut now = (0..n).collect_vec();

  for mut v in x {
    v -= 1;
    let p0 = ind[v];
    let p1 = if p0 + 1 < n { p0 + 1} else { p0 -1};
    let v0 = now[p0];
    let v1 = now[p1];
    now.swap(p0, p1);
    ind.swap(v0, v1);
  }
  for &v in now.iter() {
    println!("{}", v + 1);
  }

}