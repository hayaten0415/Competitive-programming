use proconio::input;
use std::collections::HashSet;

fn main() {
  input! {
    h: usize,
    w: usize,
    s: [String;h],
  }
  let mut vec:Vec<Vec<char>> = vec![];
  for i in 0..h {
    let tmp:Vec<char> = s[i].chars().collect();
    vec.push(tmp);
  }
  let mut grid:Vec<(i64, i64)> = vec![];
  for i in 0..h {
    for j in 0..w {
      if vec[i][j] == 'o' {
        grid.push((i as i64, j as i64));
      }
    }
  }
  let ans = (grid[0].0 - grid[1].0).abs() + (grid[0].1 - grid[1].1).abs();
  println!("{}", ans);
}
