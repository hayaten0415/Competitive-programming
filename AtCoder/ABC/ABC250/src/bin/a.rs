use proconio::input;

fn main() {
  input! {
      x: i32,
      y: i32,
      r: i32,
      c: i32,
  }
  let mut ans = 0;
  let dx = vec![1, 0, -1, 0];
  let dy = vec![0, 1, 0, -1];
  for i in 0..4 {
    if 1 <= r + dx[i] && r + dx[i] <= x && 1 <= c + dy[i] && c + dy[i] <= y {
      ans += 1;
    }
  }

  println!("{}", ans);
}
